void auto()
{
	srsetup();
	int temp = ((SensorValue(LeftOrRight)/4095.0)*3);//potentiometer values range from 0 to 4095 with leftmost being 0 and rightmost being 4095
	if(temp==0){

		}else if(temp==1){

		}else{

		}
	sleep(1000);
}
