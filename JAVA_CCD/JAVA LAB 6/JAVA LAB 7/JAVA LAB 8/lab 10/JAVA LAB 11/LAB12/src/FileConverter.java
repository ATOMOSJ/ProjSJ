import java.io.*;

public class FileConverter {
    public static void main(String[] args) {
        String filename = "lorem.txt";

        try {
            BufferedReader reader = new BufferedReader(new FileReader(filename));
            StringBuilder sb = new StringBuilder();
            String line;

            while ((line = reader.readLine()) != null) {
                // Convert case
                String convertedLine = line.chars()
                        .map(c -> Character.isLowerCase(c) ? Character.toUpperCase(c) : Character.toLowerCase(c))
                        .mapToObj(c -> String.valueOf((char) c))
                        .reduce("", (s1, s2) -> s1 + s2);

                // Convert vowels to '@'
                convertedLine = convertedLine.replaceAll("[aeiouAEIOU]", "@");

                sb.append(convertedLine).append("\n");
            }

            reader.close();

            // Write to file
            BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
            writer.write(sb.toString());
            writer.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

