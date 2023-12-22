package C322.homework6.parta;

import java.util.*;

public class Facebook implements SocialNetwork {
    public Profile[] getProfiles() {

        return profiles;
    }

    public int getSize() {

        return size;
    }

    private Profile[] profiles;
    private int size;

    // Constructor
    public Facebook() {
        this.profiles = new Profile[50];
        this.size = 0;
    }

    // Add a profile to the social network
    // expand if at capacity
    public void addProfile(Profile profile) {
        if (size == profiles.length) {
            profiles = Arrays.copyOf(profiles, size*2);
        }
        profiles[size] = profile;
        size++;
    }
    public Profile getProfileWithEmail(String email) {
        for (int i = 0; i <size; i++) {
            Profile profile = profiles[i];
            if (profile.getEmail().equals(email)){
                return profile;
            }
        }
        return null;
    }
    @Override
    //company doesn't really matter in this case
    public FacebookIterator createFriendIterator(String company) {
        return new FacebookIterator(this, "friends", company);
    }
    @Override
    public FacebookIterator createCoworkersIterator(String company) {
        return new FacebookIterator(this, "coworkers", company);
    }
}