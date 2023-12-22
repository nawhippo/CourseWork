package C322.homework6.parta;

import java.util.*;

public class FacebookIterator implements Iterator {
    private Facebook socialNetwork;
    private String type;
    private String profileEmail;
    private int currentPosition;
    private Profile[] Cache;

    public FacebookIterator(Facebook socialNetwork, String type, String profileEmail) {
        this.socialNetwork = socialNetwork;
        this.type = type;
        this.profileEmail = profileEmail;
        //starting point
        this.currentPosition = 0;
        this.Cache = new Profile[100];
    }

    // Fetch the next batch of profiles, given an id
    private Profile[] lazyinit() {
        if (Cache == null) {
            //initalize it to a friend iterator,
            if ("friends".equals(type)) {
                Profile profile = socialNetwork.getProfileWithEmail(profileEmail);
                if (profile != null) {
                    Cache = profile.getFriends();
                } else {
                    Cache = new Profile[0];
                }
            } else if ("coworkers".equals(type)) {
                //make an array of coworkers, that ought to have the same company as me
                Profile[] coworkers = new Profile[10];
                int coworkcount = 0;
                Profile currentProfile = socialNetwork.getProfileWithEmail(profileEmail);
                if (currentProfile != null) {
                    for (Profile profToAdd:socialNetwork.getProfiles()) {
                        if (profToAdd.getCompany() != null &&
                                //match profile
                                profToAdd.getCompany().equals(currentProfile.getCompany()) &&
                                //different email
                                !profToAdd.getEmail().equals(currentProfile.getEmail())) {
                            if (coworkcount >= coworkers.length) {
                                coworkers = Arrays.copyOf(coworkers, coworkers.length * 2);
                            }
                            coworkers[coworkcount++] = profToAdd;
                        }
                    }
                }
                Cache = Arrays.copyOf(coworkers, coworkcount);
            } else {
                Cache = new Profile[0];
            }
        }
        return Cache;
    }

    // Check if there are more profiles to iterate over

    public boolean hasNext() {
        //initialize it lazily
        lazyinit();
        return currentPosition < Cache.length;
    }

    // Return the next profile in the iteration
    public Profile next() {
        if (!hasNext()) {
            return null;
        } else {
            currentPosition++;
            return Cache[currentPosition];
        }
    }
}