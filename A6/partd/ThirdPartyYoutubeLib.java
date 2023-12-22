package C322.homework6.partd;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;


class ThirdPartyYouTubeClass implements ThirdPartyYouTubeLib {
    private HashMap<String, String> videoList = new HashMap<String, String>();
    public ThirdPartyYouTubeClass() {
        videoList.put("videoId1", "fat kid falls off bike");
        videoList.put("videoId2", "scarlet takes a tumble");
        videoList.put("videoId3", "keyboard cat");
    }

    public List<String> listVideos() {
        return new ArrayList<String>(videoList.keySet());
    }

    public String getVideoInfo(String id) {
        return videoList.get(id);
    }

    public void downloadVideo(String id) {
        System.out.println("Downloading video with ID: " + id);
    }
}