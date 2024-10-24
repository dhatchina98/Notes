import java.util.LinkedHashMap;
import java.util.Map;

public class hheegwh_to_h3e2g1w1 {

    static String compress_string(String input) {

        if (input == null) {
            return "";
        }

        if (input.isEmpty()) {
            return "";
        }

        Map<Character, Integer> map = new LinkedHashMap<>();
        StringBuilder compressed = new StringBuilder();

        for (Character ch : input.toCharArray()) {
            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }

        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            compressed.append(entry.getKey());
            compressed.append(entry.getValue());
        }

        return compressed.toString();
    }

    public static void main(String[] args) {

        String input = "hheegwh";
        String output = compress_string(input);
        System.out.println("output : " + output);

    }

}
