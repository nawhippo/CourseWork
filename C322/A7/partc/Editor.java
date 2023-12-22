package C322.homework7.partc;

public class Editor {
    public Editor(String file) {
        this.file = file;
    }
    String file;
    Editor(){
        String file = "";
    }
    void openFile(String filename){
        System.out.println("Opened file " + filename);
        //new file is opened
        this.file = filename;
    }

    void saveFile(String filename){
        System.out.println("Saved file " + filename);
    }
}
