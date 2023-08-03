import java.io.*;

public class FileComparator {
    public static void main(String[] args) {
        String filename1 = "file1.txt";
        String filename2 = "file2.txt";

        try {
            BufferedReader reader1 = new BufferedReader(new FileReader(filename1));
            BufferedReader reader2 = new BufferedReader(new FileReader(filename2));
            String line1, line2;
            boolean isEqual = true;

            while ((line1 = reader1.readLine()) != null && (line2 = reader2.readLine()) != null) {
                if (!line1.equals(line2)) {
                    isEqual = false;
                    break;
                }
            }

            if (isEqual && reader1.readLine() == null && reader2.readLine() == null) {
                System.out.println("The contents of the files are equal.");
            } else {
                System.out.println("The contents of the files are not equal.");
            }

            reader1.close();
            reader2.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
