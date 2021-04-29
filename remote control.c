#include"NRF24L01.h"//发射 

#define uint unsigned int
#define uchar unsigned char
sbit speed0=P0^5;          //停止按键
sbit speed1=P0^0;          //速度1档按键  
sbit speed2=P0^1;          //速度2档按键
sbit speed3=P0^2;          //速度3档按键
sbit speed4=P0^3;          //速度4档按键
sbit left1=P2^7;           //方向左1档按键
sbit left2=P0^7;           //方向左2档按键
sbit mid=P2^3;             //方向归中按键
sbit right1=P2^6;          //方向右1档按键
sbit right2=P2^5;          //方向右2档按键
sbit acc=P0^4;             //加速按键 
sbit dec=P0^6;             //减速按键
sbit left=P2^4;            //左转按键
sbit right=P2^2;           //右转按键
uchar Tx_Buf1[]={1};			
uchar Tx_Buf2[]={2};	
uchar Tx_Buf3[]={3};	
uchar Tx_Buf4[]={4};
uchar Tx_Buf5[]={5};
uchar Tx_Buf6[]={6};
uchar Tx_Buf7[]={7};
uchar Tx_Buf8[]={8};
uchar Tx_Buf9[]={9};
uchar Tx_Buf10[]={10};
uchar Tx_Buf11[]={11};
uchar Tx_Buf12[]={12};
uchar Tx_Buf13[]={13};
uchar Tx_Buf14[]={14};

uchar Rx_Buf[32];//接收到的数据暂存器，最多32字节数据  
uchar a;			//a为接收到的数据
/*------------------------------------------------
延时函数
------------------------------------------------*/
void delays(uint z)			//延时函数 
{
	uint y;
	while(z--)
		for(y=115;y>0;y--);
}


/*------------------------------------------------
main函数
------------------------------------------------*/
void main()
{
	init_NRF24L01();		//初始化24L01
	TX_Mode();
	 while(1)
	 {	
		if(acc==0)
		{
			delays(10);
			if(acc==0)
			{
				while(!acc);
				nRF24L01_TxPacket(Tx_Buf1);		
				
			}
		}
		if(dec==0)
		{
			delays(10);
			if(dec==0)
			{
				while(!dec);
				nRF24L01_TxPacket(Tx_Buf2);		
				
			}
		}
		if(left==0)
		{
			delays(10);
			if(left==0)
			{
				while(!left);
				nRF24L01_TxPacket(Tx_Buf3);		
				
			}
		}
		if(right==0)
		{
			delays(10);
			if(right==0)
			{
				while(!right);
				nRF24L01_TxPacket(Tx_Buf4);		
				
			}
		}
		if(speed1==0)
		{
			delays(10);
			if(speed1==0)
			{
				while(!speed1);
				nRF24L01_TxPacket(Tx_Buf5);		
				
			}
		}
		if(speed2==0)
		{
			delays(10);
			if(speed2==0)
			{
				while(!speed2);
				nRF24L01_TxPacket(Tx_Buf6);		
				
			}
		}
		if(speed3==0)
		{
			delays(10);
			if(speed3==0)
			{
				while(!speed3);
				nRF24L01_TxPacket(Tx_Buf7);		
				
			}
		}
		if(speed4==0)
		{
			delays(10);
			if(speed4==0)
			{
				while(!speed4);
				nRF24L01_TxPacket(Tx_Buf8);		
				
			}
		}
		if(left1==0)
		{
			delays(10);
			if(left1==0)
			{
				while(!left1);
				nRF24L01_TxPacket(Tx_Buf11);		
				
			}
		}
		if(left2==0)
		{
			delays(10);
			if(left2==0)
			{
				while(!left2);
				nRF24L01_TxPacket(Tx_Buf12);		
				
			}
		}
		if(right1==0)
		{
			delays(10);
			if(right1==0)
			{
				while(!right1);
				nRF24L01_TxPacket(Tx_Buf9);		
				
			}
		}
		if(right2==0)
		{
			delays(10);
			if(right2==0)
			{
				while(!right2);
				nRF24L01_TxPacket(Tx_Buf10);		
				
			}
		}
		if(speed0==0)
		{
			delays(10);
			if(speed0==0)
			{
				while(!speed0);
				nRF24L01_TxPacket(Tx_Buf13);		
				
			}
		}
		
		if(mid==0)
		{
			delays(10);
			if(mid==0)
			{
				while(!mid);
				nRF24L01_TxPacket(Tx_Buf14);		
				
			}
		}
		
		
	 }
}
