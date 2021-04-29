#include "NRF24L01.h"                        //����NRF����ģ��
#define uint unsigned int
#define uchar unsigned char
sbit mover=P2^1 ;                            //��ˢ���
sbit boat=P2^6;                              //���
uchar num=0;
void init()                                  // ��ʱ����ʼ���������ж� 
{
 TMOD=0x02;                   
 TH0=0x9C;      //��ֵΪ156������100�κ�����жϣ�ÿ���ж���ʱ100us
                              //��Ϊ12/12=1.0us(��һ����������ʱ��)������100����ʱ100*1.0=100us
 TL0=0x9C;
 TR0=1;                
 EA=1;
 ET0=1;
}
void mover_init(uint tim,uint i)             //��Ƭ�����PWM��������ˢ����� ������tim,�ߵ�ƽʱ����i��
{
 num=0;
 while(num<=tim)
 {
  if(num<i){mover=1;}
  else{mover=0;} 
 }
}
void mover_on()                              //��ˢ�������������У׼
{
 uint k;
 for(k=0;k<100;k++)
 {
  mover_init(200,20);
 }
 for(k=0;k<50;k++)
 {
  mover_init(200,10);
 }
}
void boat_init(uint tim,uint i)              //��Ƭ�����PWM�����������
{
 num=0;
 while(num<=tim)
 {
  if(num<i){boat=1;}
  else{boat=0;} 
 }
 } 
void mb_init(uint tim,uint i,uint j)         //ͬʱ������ˢ����Ͷ����iΪ����ߵ�ƽʱ�䣬jΪ����ߵ�ƽʱ��
{
 num=0;
 while(num<=tim)
 {
  if(num<i){mover=1;}
  else{mover=0;}
  if(num<j){boat=1;}
  else{boat=0;} 
 }
}
void delayxs(uint xms)                       //��ʱ����
{
 uint k,j;
 for(k=xms;k>0;k--)
  for(j=110;j>0;j--);       
}

void main()                                  //���غ���
{
 uint speed=10,i=10,flag=1,dire=16,k,tim=200;//�����ٶ�speed,����dire,����tim,��ˢ�����ʼ��״̬flag                         
 uchar Rx_Buf[32];  	                     //���յ��������ݴ��������32�ֽ�����  
 init_NRF24L01();	
 init();
 for(k=0;k<100;k++)                          //�����ʼ��ת���м�λ�ã�dire=16
 {
  boat_init(tim,dire);
 }     
 while(1)
 {
	  RX_Mode();		                     //����ģʽ  
	  while(nRF24L01_RxPacket(Rx_Buf)) 	     //�ȴ���������,����1����յ�����,�ڵȴ����������ڼ�,������ʱ��ɷ���ģʽ  
	  {
		switch(Rx_Buf[0])
		{
			case 1:		                                                                     //�жϽ��յ���һ���ֽ��Ƿ�Ϊ1,Ϊ1��ʾ���٣��ͽ�speed+1
        
                    Rx_Buf[0]=0;				
                    speed=speed+1;
                    if(speed>20){speed=20;}
					break;
           
			case 2:                                                                          //�жϽ��յ���һ���ֽ��Ƿ�Ϊ,Ϊ1��ʾ���٣��ͽ�speed-1     
			        Rx_Buf[0]=0;	
                    speed=speed-1;
                    if(speed<10){speed=10;}
					break;
       
			case 3:                                                                          //�жϽ��յ���һ���ֽ��Ƿ�Ϊ3,Ϊ1��ʾ��ת���ͽ�dire+3       
		            Rx_Buf[0]=0;	
                    dire=dire+3;       
                    if(dire>22){dire=22;} 
					break;
                      
            case 4:                                                                          //�жϽ��յ���һ���ֽ��Ƿ�Ϊ4,Ϊ1��ʾ��ת���ͽ�dire-3
		            Rx_Buf[0]=0;	
                    dire=dire-3;
                    if(dire<10){dire=10;}    
					break;
	   
    
			case 5:		                                                                     //�жϽ��յ���һ���ֽ��Ƿ�Ϊ5,Ϊ1��ʾ�ٶ���Ϊ1�� 
          
                    Rx_Buf[0]=0;				
                    speed=12;
                    break;
       
        
			case 6:                                                                         //�жϽ��յ���һ���ֽ��Ƿ�Ϊ6,Ϊ1��ʾ�ٶ���Ϊ2�� 
        			Rx_Buf[0]=0;	
                    speed=14;
			        break;
          
       
		    case 7:                                                                     	//�жϽ��յ���һ���ֽ��Ƿ�Ϊ7,Ϊ1��ʾ�ٶ���Ϊ3�� 
         
                    Rx_Buf[0]=0;				
                    speed=16;
			        break;
          
       
       
			case 8:                                                                          //�жϽ��յ���һ���ֽ��Ƿ�Ϊ8,Ϊ1��ʾ�ٶ���Ϊ4�� 
      
			Rx_Buf[0]=0;	
            speed=20;
			break;
			
 
			case 9:                                                                          //�жϽ��յ���һ���ֽ��Ƿ�Ϊ9,Ϊ1��ʾ������Ϊ��2��
				    Rx_Buf[0]=0;	
                    dire=13;
			        break;
		

			case 10: 			                                                             //�жϽ��յ���һ���ֽ��Ƿ�Ϊ10,Ϊ1��ʾ������Ϊ��1�� 
                    Rx_Buf[0]=0;				
                    dire=10;
			        break;
           
  
       
			case 11:                                                                       	 //�жϽ��յ���һ���ֽ��Ƿ�Ϊ11,Ϊ1��ʾ������Ϊ��1�� 
			        Rx_Buf[0]=0;				
                    dire=19;
			        break;
        
			case 12:                                                                         //�жϽ��յ���һ���ֽ��Ƿ�Ϊ12,Ϊ1��ʾ������Ϊ��2�� 
           			Rx_Buf[0]=0;	
                    dire=22;
			        break;
       
			
			case 13:		                                                                 //�жϽ��յ���һ���ֽ��Ƿ�Ϊ13,Ϊ1��ʾֹͣ 
                   Rx_Buf[0]=0;				
                   speed=10;
                   break;


			case 14:			                                                             //�жϽ��յ���һ���ֽ�D2�Ƿ�Ϊ1,Ϊ1��ʾ������� 
          
        
			Rx_Buf[0]=0;	
            dire=16;
            break;
		}
			
	  }
	    if(flag){mover_on();}                //����տ�ʼ������
        flag=0;
        while(i!=speed)                      //i�Ƕ����һ���ٶ�״ֵ̬��������Ҫ���ٶ�speed��Ƚ�
         {
   for(k=0;k<5;k++)    
   {
    mover_init(tim,i);
   }
   if(i<speed){i++;}         //iС��speed��ʾ��ǰ�ٶ�״ֵ̬������Ҫ���ٶȣ���Ҫ���ߵ�ƽʱ����ߣ���iҪ���ӣ�
   else{i--;}
  }
  
           mb_init(tim,i,dire);
  
         }
}
void T0_time() interrupt 1                   //��ʱ���жϺ���  
{
 num++;
}