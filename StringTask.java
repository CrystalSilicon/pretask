package pretask;
import java.util.Scanner;

public class StringTask {
	
	public int getIndex(String str) {
		char ch;
		int firstIndex,lastIndex,result = -1;	
		for(int i=0;i<str.length();i++) {
			ch = str.charAt(i);
			firstIndex = str.indexOf(ch);
			lastIndex = str.lastIndexOf(ch);
			if(firstIndex == lastIndex) {
				result = i;
				break;
			}
		}
		return result;
	}

	public static void main(String[] args) {
		StringTask st = new StringTask();
		System.out.print("Input a string: ");
		Scanner in = new Scanner(System.in);
		String str = in.nextLine();
		int result = st.getIndex(str);
		System.out.println("The index of the first char that isn't repeated is "+result);
	}

}
