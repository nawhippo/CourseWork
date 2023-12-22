package C322.homework6.parta;

import java.util.List;

public class Profile {
    public String getName() {
        return name;
    }

    public Profile[] getFriends() {
        return friends;
    }

    public String getId() {
        return id;
    }

    public String getEmail() {
        return email;
    }

    public String getCompany(){
        return company;
    }
    private String name;
    private String id;
    private String email;
    private String company;
    private Profile[] friends;
    // Constructor
    public Profile(String name, String email, String id, String company) {
        this.id = id;
        this.email = email;
        this.company = company;
        this.friends = friends;
    }


}
