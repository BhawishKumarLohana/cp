public class BasicsBitwiseOperators {

    public static int check_kth_bit(int x, int k){
        return (x >> k) & 1;
    }
    // print positions of all 1's in the x
    public static void print_on_bits(int x ){
        for(int  k  = 0; k < 32 ; k++) {
            if (check_kth_bit(x, k) == 1) {
                System.out.print(k + " ");
            }
        }
    }

    //checking even or odd
    // false for odd
    public static boolean is_even(int x){
        if((x & 1) == 1){
            return false;
        }else{
            return true;
        }
    }






    public static void main(String[] args) {
        int x  = 4 ;
        int k = 4;
        int ans  = check_kth_bit(x,k);
        System.out.println(ans);
        print_on_bits(9);
        System.out.println();
        System.out.println(is_even(5));
    }




}
