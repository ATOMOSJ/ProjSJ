 class Plate {
    private double length;
    private double width;

    public Plate(double length, double width) {
        this.length = length;
        this.width = width;
        System.out.println("Plate constructor called");
    }

    public double getLength() {
        return length;
    }

    public double getWidth() {
        return width;
    }
}

 class Box extends Plate {
    private double height;

    public Box(double length, double width, double height) {
        super(length, width);
        this.height = height;
        System.out.println("Box constructor called");
    }

    public double getHeight() {
        return height;
    }
}

 class WoodBox extends Box {
    private double thickness;

    public WoodBox(double length, double width, double height, double thickness) {
        super(length, width, height);
        this.thickness = thickness;
        System.out.println("WoodBox constructor called");
    }

    public double getThickness() {
        return thickness;
    }

} public class MAIN{
    public static void main(String[] args) {
        WoodBox woodBox = new WoodBox(10, 20, 30, 2);
        System.out.println("WoodBox dimensions: " + woodBox.getLength() + " x " + woodBox.getWidth() + " x " + woodBox.getHeight());
        System.out.println("WoodBox thickness: " + woodBox.getThickness());
    }
}




