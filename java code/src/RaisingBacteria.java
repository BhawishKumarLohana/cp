import java.util.Scanner;

public class RaisingBacteria {
    public static int check_kth_bit(int x, int k){
        return (x >> k) & 1;
    }

    public static void main(String[] args) {
        // initially t
        // end of day 1 : 2t
        // x at some time
        // minimum for x
        // box property : t --> 2t --> 4t --> 8t
        //                4 --> 8 --> 16 --->32
        //                0100-->1000--> 10000
        // LEFT SHIFT
        Scanner scanner = new Scanner(System.in);
        int x  =  scanner.nextInt();
        int sum  = 0 ;

        for(int  k  = 0; k < 32 ; k++) {
            if (check_kth_bit(x, k) == 1) {
                sum+=1;
            }
        }
        System.out.println(sum);


    }



}
