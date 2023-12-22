package C322.homework6.parta;

public class Application {
    Facebook facebook;
    SocialSpammer spammer;

    Application(Facebook facebook, SocialSpammer spammer){
        this.facebook = facebook;
        this.spammer = spammer;
    }
    void sendSpamToFriends(Profile profile){
        FacebookIterator friendsIterator = facebook.createFriendIterator(profile.getId());
        while(friendsIterator.hasNext()){
            Profile friend = (Profile) friendsIterator.next();
            spammer.sendSpam(friend.getEmail());
        }
    }
    void sendSpamToCoworker(Profile profile){
        FacebookIterator coworkersIterator = facebook.createFriendIterator(profile.getId());
        while(coworkersIterator.hasNext()){
            Profile coworker = (Profile) coworkersIterator.next();
            spammer.sendSpam(coworker.getEmail());
        }
    }
}
