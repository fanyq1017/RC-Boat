#include"NRF24L01.h"//���� 

#define uint unsigned int
#define uchar unsigned char
sbit speed0=P0^5;          //ֹͣ����
sbit speed1=P0^0;          //�ٶ�1������  
sbit speed2=P0^1;          //�ٶ�2������
sbit speed3=P0^2;          //�ٶ�3������
sbit speed4=P0^3;          //�ٶ�4������
sbit left1=P2^7;           //������1������
sbit left2=P0^7;           //������2������
sbit mid=P2^3;             //������а���
sbit right1=P2^6;          //������1������
sbit right2=P2^5;          //������2������
sbit acc=P0^4;             //���ٰ��� 
sbit dec=P0^6;             //���ٰ���
sbit left=P2^4;            //��ת����
sbit right=P2^2;           //��ת����
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

uchar Rx_Buf[32];//���յ��������ݴ��������32�ֽ�����  
uchar a;			//aΪ���յ�������
/*------------------------------------------------
��ʱ����
------------------------------------------------*/
void delays(uint z)			//��ʱ���� 
{
	uint y;
	while(z--)
		for(y=115;y>0;y--);
}


/*------------------------------------------------
main����
------------------------------------------------*/
void main()
{
	init_NRF24L01();		//��ʼ��24L01
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
