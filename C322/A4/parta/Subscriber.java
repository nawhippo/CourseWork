package C322.homework4.parta;

import java.util.ArrayList;

public interface Subscriber {
    public void update(ArrayList<String> discussionthread);
    public void subscribe(DiscussionForum discussionForum);
    public void unsubscribe(DiscussionForum discussionForum);
}
