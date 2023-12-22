package C322.homework4.parta;

import java.util.ArrayList;

public class DiscussionForum {

    private ArrayList<String> discussionthread = new ArrayList<>();
    private ArrayList<Subscriber> subscribers = new ArrayList<>();

    public ArrayList<String> getDiscussionthread(){
        return this.discussionthread;
    }


    void update(){
        for(Subscriber subscriber: this.subscribers){
            subscriber.update(this.getDiscussionthread());
        }
    }
    void addSub(Subscriber subscriber){
        this.subscribers.add(subscriber);
    }

    void removeSub(Subscriber subscriber){
        this.subscribers.remove(subscriber);
    }
}
