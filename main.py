
import shlex
from collections import defaultdict
import sys

class UserDayStat:
    def __init__(self):
        self.agents = set()
        self.ips = set()
        self.pdf_count = 0
        self.sessions = set()
        self.pdf_nums = []

stats = defaultdict(UserDayStat)

def get_pdf_number(request):
    try:
        path = request.split(' ')[1] 
        if path.endswith('.pdf'):
            num = path.split('/')[-1].replace('.pdf', '')
            if num.isdigit():
                return int(num)
    except Exception:
        pass
    return None

def get_day(date):
    s = date.find('[')
    e = date.find(':', s)
    if s != -1 and e != -1:
        return date[s+1:e]
    return date

def main():
    violation = input().strip()
    agent = ip = pdf = session = crawl = ""
    # rules
    for part in violation.split(','):
        part = part.strip()
        key, value = part.split('=')
        key, value = key.strip(), value.strip()
        if key == 'agent': agent = int(value)
        elif key == 'ip': ip = int(value)
        elif key == 'pdf': pdf = int(value)
        elif key == 'session': session = int(value)
        elif key == 'crawl': crawl = int(value)
    
    #format of addresses
    header = input().strip() 
    fields = []
    for f in header.split(','):
        f = f.strip()
        fields.append(f)
    # field_name -> column index
    field_index = {name: i for i, name in enumerate(fields)}

    
    lines = sys.stdin.read().splitlines()

    for line in lines:
        #print(line)
        line = line.strip()
        if not line:
            continue 

        parts = shlex.split(line)
        client_ip = parts[field_index['Client IP']]
        id_ = parts[field_index['Id']]
        date = parts[field_index['Date']]
        request = parts[field_index['Request']]
        http_status = parts[field_index['HTTP Status']]
        user_agent = parts[field_index['User Agent']]
        session_cookie = parts[field_index['Session Cookie']]
        
        if http_status != '200': # Ignore non-200s
            continue

        day = get_day(date)
        key = (id_,day)
        record = stats[key]
        record.agents.add(user_agent)
        record.ips.add(client_ip)
        record.sessions.add(session_cookie)
        
        pdf_num = get_pdf_number(request)
        if pdf_num is not None:
            record.pdf_count += 1
            record.pdf_nums.append(pdf_num)

        #print('Client IP:', client_ip)
        #print('Id:', id_)
        #print('Date:', date)
        #print('Request:', request)
        #print('HTTP Status:', http_status)
        #print('User Agent:', user_agent)
        #print('Session Cookie:', session_cookie)
    
    #After all the inputs we can now check the violations
    for (id_, day), record in stats.items():
        if not id_ or id_ == "-":
            continue  
        violations = []
        if len(record.agents) >= agent:
            violations.append(f'agent={agent}')
        if len(record.ips) >= ip:
            violations.append(f'ip={ip}')
        if record.pdf_count >= pdf:
            violations.append(f'pdf={pdf}')
        if len(record.sessions) >= session:
            violations.append(f'session={session}')
        # Crawl: max streak of sequential PDF numbers
        nums = sorted(set(record.pdf_nums))
        max_streak = 0
        if nums:
            streak = 1
            for i in range(1, len(nums)):
                if nums[i] == nums[i-1] + 1:
                    streak += 1
                else:
                    max_streak = max(max_streak, streak)
                    streak = 1
            max_streak = max(max_streak, streak)
            if max_streak >= crawl:
                violations.append(f'crawl={crawl}')
        for v in violations:
            print(f'{id_} {v}')
        



    

    
    #print('agent:', agent)
    #print('ip:', ip)
    #print('pdf:', pdf)
    #print('session:', session)
    #print('crawl:', crawl)

main()


