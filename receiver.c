#include "NRF24L01.h"                        //配置NRF接收模块
#define uint unsigned int
#define uchar unsigned char
sbit mover=P2^1 ;                            //无刷电调
sbit boat=P2^6;                              //舵机
uchar num=0;
void init()                                  // 定时器初始化，开启中断 
{
 TMOD=0x02;                   
 TH0=0x9C;      //初值为156，计数100次后产生中断，每次中断用时100us
                              //因为12/12=1.0us(即一个机器周期时间)，计数100次用时100*1.0=100us
 TL0=0x9C;
 TR0=1;                
 EA=1;
 ET0=1;
}
void mover_init(uint tim,uint i)             //单片机输出PWM波驱动无刷电调块 （周期tim,高电平时间是i）
{
 num=0;
 while(num<=tim)
 {
  if(num<i){mover=1;}
  else{mover=0;} 
 }
}
void mover_on()                              //无刷电调解锁，油门校准
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
void boat_init(uint tim,uint i)              //单片机输出PWM波驱动舵机块
{
 num=0;
 while(num<=tim)
 {
  if(num<i){boat=1;}
  else{boat=0;} 
 }
 } 
void mb_init(uint tim,uint i,uint j)         //同时驱动无刷电调和舵机，i为电调高电平时间，j为舵机高电平时间
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
void delayxs(uint xms)                       //延时函数
{
 uint k,j;
 for(k=xms;k>0;k--)
  for(j=110;j>0;j--);       
}

void main()                                  //主控函数
{
 uint speed=10,i=10,flag=1,dire=16,k,tim=200;//定义速度speed,方向dire,周期tim,无刷电调初始化状态flag                         
 uchar Rx_Buf[32];  	                     //接收到的数据暂存器，最多32字节数据  
 init_NRF24L01();	
 init();
 for(k=0;k<100;k++)                          //舵机初始化转到中间位置，dire=16
 {
  boat_init(tim,dire);
 }     
 while(1)
 {
	  RX_Mode();		                     //接收模式  
	  while(nRF24L01_RxPacket(Rx_Buf)) 	     //等待接收数据,返回1则接收到数据,在等待接收数据期间,可以随时变成发送模式  
	  {
		switch(Rx_Buf[0])
		{
			case 1:		                                                                     //判断接收到的一个字节是否为1,为1表示加速，就将speed+1
        
                    Rx_Buf[0]=0;				
                    speed=speed+1;
                    if(speed>20){speed=20;}
					break;
           
			case 2:                                                                          //判断接收到的一个字节是否为,为1表示加速，就将speed-1     
			        Rx_Buf[0]=0;	
                    speed=speed-1;
                    if(speed<10){speed=10;}
					break;
       
			case 3:                                                                          //判断接收到的一个字节是否为3,为1表示左转，就将dire+3       
		            Rx_Buf[0]=0;	
                    dire=dire+3;       
                    if(dire>22){dire=22;} 
					break;
                      
            case 4:                                                                          //判断接收到的一个字节是否为4,为1表示右转，就将dire-3
		            Rx_Buf[0]=0;	
                    dire=dire-3;
                    if(dire<10){dire=10;}    
					break;
	   
    
			case 5:		                                                                     //判断接收到的一个字节是否为5,为1表示速度置为1档 
          
                    Rx_Buf[0]=0;				
                    speed=12;
                    break;
       
        
			case 6:                                                                         //判断接收到的一个字节是否为6,为1表示速度置为2档 
        			Rx_Buf[0]=0;	
                    speed=14;
			        break;
          
       
		    case 7:                                                                     	//判断接收到的一个字节是否为7,为1表示速度置为3档 
         
                    Rx_Buf[0]=0;				
                    speed=16;
			        break;
          
       
       
			case 8:                                                                          //判断接收到的一个字节是否为8,为1表示速度置为4档 
      
			Rx_Buf[0]=0;	
            speed=20;
			break;
			
 
			case 9:                                                                          //判断接收到的一个字节是否为9,为1表示方向置为左2档
				    Rx_Buf[0]=0;	
                    dire=13;
			        break;
		

			case 10: 			                                                             //判断接收到的一个字节是否为10,为1表示方向置为左1档 
                    Rx_Buf[0]=0;				
                    dire=10;
			        break;
           
  
       
			case 11:                                                                       	 //判断接收到的一个字节是否为11,为1表示方向置为右1档 
			        Rx_Buf[0]=0;				
                    dire=19;
			        break;
        
			case 12:                                                                         //判断接收到的一个字节是否为12,为1表示方向置为右2档 
           			Rx_Buf[0]=0;	
                    dire=22;
			        break;
       
			
			case 13:		                                                                 //判断接收到的一个字节是否为13,为1表示停止 
                   Rx_Buf[0]=0;				
                   speed=10;
                   break;


			case 14:			                                                             //判断接收到的一个字节D2是否为1,为1表示方向归中 
          
        
			Rx_Buf[0]=0;	
            dire=16;
            break;
		}
			
	  }
	    if(flag){mover_on();}                //电调刚开始启动块
        flag=0;
        while(i!=speed)                      //i是定义的一个速度状态值，与你想要的速度speed想比较
         {
   for(k=0;k<5;k++)    
   {
    mover_init(tim,i);
   }
   if(i<speed){i++;}         //i小于speed表示当前速度状态值低于想要的速度，就要将高电平时间调高（即i要增加）
   else{i--;}
  }
  
           mb_init(tim,i,dire);
  
         }
}
void T0_time() interrupt 1                   //定时器中断函数  
{
 num++;
}