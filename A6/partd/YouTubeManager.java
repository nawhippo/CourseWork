package C322.homework6.partd;

import java.util.List;

public class YouTubeManager {
    private ThirdPartyYouTubeLib service;
    public YouTubeManager(ThirdPartyYouTubeLib service) {
        this.service = service;
    }

    public List<String> getVideoList() {
        return service.listVideos();
    }

    public String getVideoInfo(String id) {
        return service.getVideoInfo(id);
    }

    public void downloadVideo(String id) {
        service.downloadVideo(id);
    }
}