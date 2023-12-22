package C322.homework7.parta;

public class PartATestDrive {
    public static void main(String[] args){
        Off initialState = new Off();

        //starts OFF
        TV tv = new TV(initialState);

            //First time press
            //tv should be turned on
            tv.pressButton();
            System.out.println(tv.getState());

    //Second time press
            //tv should be turned off
            tv.pressButton();
            System.out.println(tv.getState());

        }
}
