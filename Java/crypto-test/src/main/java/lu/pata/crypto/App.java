package lu.pata.crypto;

import java.security.NoSuchAlgorithmException;
import java.util.Random;

public class App {
    public static void main(String[] args) throws NoSuchAlgorithmException {
        Random rnd=new Random();

        Hash hash=new Hash();
        byte[] data=new byte[40];
        rnd.nextBytes(data);
        hash.calculateHash(data);
    }
}
