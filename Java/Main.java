import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
 
public class Main {
 
    public static void main(String[] args) {
        try {
            FileWriter writer = new FileWriter("data_mhs.dat", true);
            writer.write("Ardi 2101210 Ilkom FPMIPA");
            writer.write("Andi 2101410 Pilkom FPMIPA");
            writer.write("Aldo 2101310 Ilkom FPMIPA");
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        try {
            FileReader reader = new FileReader("data_mhs.dat");
            int character;
 
            while ((character = reader.read()) != -1) {
                System.out.print((char) character);
            }
            reader.close();
 
        } catch (IOException e) {
            e.printStackTrace();
        }
 
    }
 
}