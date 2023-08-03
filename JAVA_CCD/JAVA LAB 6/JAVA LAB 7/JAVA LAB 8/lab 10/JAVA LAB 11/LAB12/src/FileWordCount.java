import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class FileWordCount {
    public static void main(String[] args) {
        String filename = "ZX.txt";
        int wordCount = 0;
        int characterCount = 0;
        int sentenceCount = 0;

        try {
            BufferedReader reader = new BufferedReader(new FileReader(filename));
            String line;

            while ((line = reader.readLine()) != null) {
                // Count characters
                characterCount += line.length();

                // Count words
                String[] words = line.split("\\s+");
                wordCount += words.length;

                // Count sentences
                String[] sentences = line.split("[!?.:]+");
                sentenceCount += sentences.length;
            }

            reader.close();

            // Display the counts
            System.out.println("Number of words: " + wordCount);
            System.out.println("Number of characters: " + characterCount);
            System.out.println("Number of sentences: " + sentenceCount);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
