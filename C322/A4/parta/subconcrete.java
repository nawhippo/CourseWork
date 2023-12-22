package C322.homework4.parta;

import java.util.ArrayList;

public class subconcrete implements Subscriber {
    public subconcrete(DiscussionForum discussionForum){
        discussionForum.addSub(this);
    }

    public void update(ArrayList<String> discussionthread) {

    }

    public void subscribe(DiscussionForum discussionForum) {
        discussionForum.addSub(this);
    }

    public void unsubscribe(DiscussionForum discussionForum) {
        discussionForum.removeSub(this);
    }
}
