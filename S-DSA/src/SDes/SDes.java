package SDes;

public class SDes {
    private static final String[][] s1 = {{"101","010","001","110","011","100","111","000"},
                                    {"001","100","110","010","000","111","101","011"}};

    private static final String[][] s2 = {{"100","000","110","101","111","001","011","010"},
                                    {"101","011","000","111","110","010","001","100"}};
    public static String cypher(String input, String key){
        String out = input;
        String k2 = key.substring(1,9);

        out = round(out,k2);
        String k3 = key.substring(2,9) + key.charAt(0);
        out = round(out,k3);
        String k4 = key.substring(3,9) + key.substring(0,2);
        out = round(out,k4);

        return out;
    }

    private static String round(String input, String key){
        String l0 = input.substring(0,6);
        String r0 = input.substring(6,12);

        //Expand r0
        String temp = r0.substring(0,2) + r0.charAt(3) + r0.charAt(2) + r0.charAt(3) + r0.charAt(2) + r0.substring(4);

        //xorWithKey
        temp = stringXor(temp,key);

        //sBoxes
        String fromS1 = s1[Integer.parseInt(temp.substring(0,1),2)][Integer.parseInt(temp.substring(1,4),2)];
        String fromS2 = s2[Integer.parseInt(temp.substring(4,5),2)][Integer.parseInt(temp.substring(5,8),2)];
        temp = fromS1 + fromS2;

        temp = r0 + stringXor(temp,l0);

        return temp;


    }

    private static String stringXor(String a, String b){
        assert(a.length() == b.length());
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < a.length(); i++) {
            if(a.charAt(i) == b.charAt(i)){
                result.append('0');
            } else {
                result.append('1');
            }
        }

        return result.toString();
    }
}
