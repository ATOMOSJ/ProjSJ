public class objectcounter {
    static int count;
    private int gol;
    objectcounter(int gol) {
    this.gol = gol;
    count++;
    }
    public static void main(String[] args) {
        objectcounter kol =new objectcounter(90);
        objectcounter kol1 =new objectcounter(90);
        System.out.println("the created object:"+count);
    }
}

