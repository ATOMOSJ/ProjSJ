import java.applet.*;
import java.awt.*;

public class UserInfoApplet extends Applet {
    // User information variables
    private String rollNo = "12345";
    private String name = "John Doe";
    private String branch = "Computer Science";
    private String section = "A";

    // Initialization method
    public void init() {
        // Set the applet background color
        setBackground(Color.white);
    }

    // Paint method to draw the user information
    public void paint(Graphics g) {
        // Set font and color for the text
        g.setFont(new Font("Arial", Font.BOLD, 18));
        g.setColor(Color.black);

        // Draw the user information on separate lines
        g.drawString("Roll No: " + rollNo, 20, 30);
        g.drawString("Name: " + name, 20, 60);
        g.drawString("Branch: " + branch, 20, 90);
        g.drawString("Section: " + section, 20, 120);
    }
}
