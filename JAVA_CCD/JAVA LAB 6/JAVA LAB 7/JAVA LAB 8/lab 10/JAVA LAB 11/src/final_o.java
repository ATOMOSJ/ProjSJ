 class final_o {
     public static void main(String[] args) {
         try {
             try{
                 System.out.println("lets see...");
                 int b =45/5;
             }catch(ArithmeticException e){
                 System.out.println("its handled but there is no exception here"+e.getMessage());
             }finally {
                 System.out.println("1). final block is executed even the exception is not there");
             }
             try {
                 System.out.println("lets see...");
                 int b =45/0;
             }catch(ArithmeticException e){
                 System.out.println("its handled but there is no exception here"+e.getMessage());
             }finally {
                 System.out.println("2). final block is executed even the exception is there");
             }
         }catch (Exception e){
             System.out.println("here are the details"+ e.getMessage());
         }finally {
             System.out.println("3). chal bhai ye last final hai");
         }
     }
}
