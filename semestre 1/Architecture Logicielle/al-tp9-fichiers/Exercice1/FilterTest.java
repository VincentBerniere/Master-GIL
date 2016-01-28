import java.io.*;

public class FilterTest {
	public static IFilter test1() {
		return ...
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(
			new InputStreamReader(
				new FileInputStream(args[0])));
		String line;

		// Get the Filter to apply on each line :		
		IFilter f=test1();	// Test 1

		// Process each line :
		while ((line = in.readLine()) != null) {
			System.out.println(f.filter(line)); // <- To be filtered !
		}
		
	}
}
