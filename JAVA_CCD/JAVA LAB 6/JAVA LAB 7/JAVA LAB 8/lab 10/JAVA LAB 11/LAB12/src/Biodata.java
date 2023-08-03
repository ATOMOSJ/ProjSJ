import java.io.*;

public class Biodata {
    public static void main(String[] args) {
        String name = "JPS SAAHIL";
        int age = 20;
        String address = "BBSR";
        String phone = "7751956464";
        String email = "jpssaahil203@gmail.com";
        String bio = "I am a software engineer with experience in Java programming.";

        // Write biodata to a file in byte form using FileOutputStream
        try {
            FileOutputStream fos = new FileOutputStream("biodata.txt");
            fos.write(name.getBytes());
            fos.write(age);
            fos.write(address.getBytes());
            fos.write(phone.getBytes());
            fos.write(email.getBytes());
            fos.write(bio.getBytes());
            fos.close();
            System.out.println("Biodata written to file.");
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Read biodata from file in byte form using FileInputStream
        try {
            FileInputStream fis = new FileInputStream("biodata.bin");
            byte[] buffer = new byte[1024];
            int length = fis.read(buffer);
            String data = new String(buffer, 0, length);
            System.out.println("Biodata read from file in byte form:");
            System.out.println(data);
            fis.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Write biodata to a file in character form using FileWriter
        try {
            FileWriter fw = new FileWriter("biodata.txt");
            fw.write(name + "\n");
            fw.write(Integer.toString(age) + "\n");
            fw.write(address + "\n");
            fw.write(phone + "\n");
            fw.write(email + "\n");
            fw.write(bio + "\n");
            fw.close();
            System.out.println("Biodata written to file.");
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Read biodata from file in character form using FileReader
        try {
            FileReader fr = new FileReader("biodata.txt");
            BufferedReader br = new BufferedReader(fr);
            System.out.println("Biodata read from file in character form:");
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
            fr.close();
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
