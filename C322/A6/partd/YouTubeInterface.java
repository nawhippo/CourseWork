package C322.homework6.partd;

import java.util.List;

interface ThirdPartyYouTubeLib {
        public List<String> listVideos();
        public String getVideoInfo(String id);
        public void downloadVideo(String id);
    }

