class nega extends Exception{
    nega(String s){
        super(s);
    }
}
class test {
    static void checking (int ex)throws nega{
        if(ex<0){
            throw new nega("" +
                    "error occured");

        }else{
            System.out.println("no error occured");
        }
    }

    public static void main(String[] args) {
        try{
            checking(-9);
        }catch (Exception e){
            System.out.println("exception occured" + e.getMessage());
        }
        System.out.println("rest of the code...");
    }
}