package C322.homework5.parta;

import java.util.Random;

public class CreateBankAccount {
    private static CreateBankAccount instance = null;
    private int currentAccountNumber;
    private CreateBankAccount(){
        Random random = new Random();
        int currentAccountNumber = (random.nextInt(99999999) + 10000000);
    }
    public static synchronized CreateBankAccount getNewAccount(){
        if(instance == null){
            System.out.println("Bank account number created.");
            instance = new CreateBankAccount();
            return instance;
        }else{
            System.out.println("Bank Account already opened.");
            return instance;
        }
    }
}

