package C322.homework6.partd;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class CachedYouTubeClass implements ThirdPartyYouTubeLib {
    private ThirdPartyYouTubeClass youtube;
    private Map<String, String> videoCache;
    public CachedYouTubeClass() {
        this.youtube = new ThirdPartyYouTubeClass();
        this.videoCache = new HashMap<>();
    }

    public List<String> listVideos() {
        // Delegate to the third-party class
        return youtube.listVideos();
    }
    public String getVideoInfo(String id) {
        // Return cached result if available
        if (videoCache.containsKey(id)) {
            System.out.println("Using cached version of video " + id);
            return videoCache.get(id);
        }
        // Delegate to the 3rdparty class and cache the result
        String videoInfo = youtube.getVideoInfo(id);
        videoCache.put(id, videoInfo);
        return videoInfo;
    }
    public void downloadVideo(String id) {
        if (videoCache.containsKey(id)) {
            System.out.println("Using cached version of video" + id);
            return;
        }
        youtube.downloadVideo(id);
        videoCache.put(id, id);
    }
}