package lu.pata.crypto;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.NativeLong;
import com.sun.jna.Platform;
import com.sun.jna.*;
import org.apache.commons.codec.binary.Hex;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Hash {
    public void test(){
        simpleDLL sdll = simpleDLL.INSTANCE;
        sdll.test();
    }

    public void calculateHash(byte[] data) throws NoSuchAlgorithmException {
        simpleDLL sdll = simpleDLL.INSTANCE;
        byte[] digest=new byte[16];
        sdll.calc_digest(data,data.length,digest);
        System.out.println("MD5 C: "+ Hex.encodeHexString(digest));

        MessageDigest md = MessageDigest.getInstance("MD5");
        md.update(data);
        byte[] digest2 = md.digest();
        System.out.println("MD5 J: "+ Hex.encodeHexString(digest2));
    }

    public interface simpleDLL extends Library {
        simpleDLL INSTANCE = Native.load(
                (Platform.isWindows() ? "hash" : "hash"), simpleDLL.class);
        // it's possible to check the platform on which program runs,
        // for example purposes we assume that there's a linux port of the library (it's not attached to the downloadable project)
        //byte giveVoidPtrGetChar(Pointer param); // char giveVoidPtrGetChar(void* param);
        //int giveVoidPtrGetInt(Pointer param);   //int giveVoidPtrGetInt(void* param);
        //int giveIntGetInt(int a);               // int giveIntGetInt(int a);
        //void simpleCall();                      // void simpleCall();
        void test();
        void calc_digest(byte[] data,int length,byte[] digest); //void calc_digest(uint8_t* data, size_t length, uint8_t* digest)
    }
}
