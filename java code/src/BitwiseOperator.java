public class BitwiseOperator {
    public static void main(String[] args) {
        int input_a  = 0b0010 & 0b1; // 2
        int input_b =  0b0011 & 0b1; //3

        if(input_a == 1){
            System.out.println("a in odd");
        }else{
            System.out.println("a in even");
        }

        if(input_b == 1){
            System.out.println("a in odd");
        }else{
            System.out.println("a in even");
        }


    }
}
