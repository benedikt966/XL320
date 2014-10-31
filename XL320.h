/*
 Code based on:
 Dynamixel.cpp - Ax-12+ Half Duplex USART Comunication
 Copyright (c) 2011 Savage Electronics.
 And Dynamixel Pro library for OpenCM-9.04 made by ROBOTIS, LTD.

 Modified to work only with Dynamixel XL-320 actuator.

 Modifications made by Luis G III for HelloSpoon robot.
 Webpage: http://hellospoonrobot.com
 Twitter: @HelloSpoon
 Youtube: http://youtube.com/user/hellospoonrobot

 This file can be used and be modified by anyone, 
 don't forget to say thank you to OP!
 
 */

#ifndef XL320_h
#define XL320_h

/*EEPROM Area*/
#define XL_MODEL_NUMBER_L           0
#define XL_MODEL_NUMBER_H           1
#define XL_VERSION                  2
#define XL_ID                       3
#define XL_BAUD_RATE                4
#define XL_RETURN_DELAY_TIME        5
#define XL_CW_ANGLE_LIMIT_L         6
#define XL_CW_ANGLE_LIMIT_H         7
#define XL_CCW_ANGLE_LIMIT_L        8
#define XL_CCW_ANGLE_LIMIT_H        9
#define XL_CONTROL_MODE             11
#define XL_LIMIT_TEMPERATURE        12
#define XL_DOWN_LIMIT_VOLTAGE       13
#define XL_UP_LIMIT_VOLTAGE         14
#define XL_MAX_TORQUE_L             15
#define XL_MAX_TORQUE_H             16
#define XL_RETURN_LEVEL             17
#define XL_ALARM_SHUTDOWN           18
/*RAM Area*/
#define XL_TORQUE_ENABLE            24
#define XL_LED                      25
#define XL_D_GAIN    				27
#define XL_I_GAIN      				28
#define XL_P_GAIN    				29
#define XL_GOAL_POSITION_L          30
#define XL_GOAL_SPEED_L             32
#define XL_GOAL_TORQUE 		        35
#define XL_PRESENT_POSITION         37
#define XL_PRESENT_SPEED            39
#define XL_PRESENT_LOAD             41
#define XL_PRESENT_VOLTAGE          45
#define XL_PRESENT_TEMPERATURE      46
#define XL_REGISTERED_INSTRUCTION   47
#define XL_MOVING                   49
#define XL_HARDWARE_ERROR           50
#define XL_PUNCH                    51

#define Tx_MODE                     1
#define Rx_MODE                     0


#include <inttypes.h>

class DynamixelPro {
private:
	unsigned char Direction_Pin;
	volatile char gbpParamEx[130+10];

public:
	/*
	Initialization of communication with Dynamixel XL-320 using 2.0 protocol
	
	Usage:
	XL320.begin();
	*/
	void begin();
	
	/*
	Set the position of the joint selected between 0-1023.
	
	@params
	ID - Dynamixel XL-320 defined ID
	value - 0-1023
	
	Usage:
	XL320.moveJoint(1, 324);
	*/
	void moveJoint(int ID, int value);
	
	/*
	Set the speed of the joint selected between 0-1023
	
	@params
	ID - Dynamixel XL-320 defined ID
	value - 0-1023
	
	Usage:
	XL320.setJointSpeed(2, 400);
	*/
	void setJointSpeed(int ID, int value);
	
	/*
	Choose color of LED from Dynamixel XL-320
	
	@params
	ID - Dynamixel XL-320 defined ID
	led_color - 0 OFF 1 RED 2 GREEN 3 BLUE 4 YELLOW 5 BLUE-GREEN 6 PINK 7 WHITE
	
	Usage:
	XL320.LED(1, 7);
	*/
	void LED(int ID, int led_color);
	
	/**/
	int getSpoonLoad(int ID);
	
	/*
	Set the maximum torque limit of the selected joint
	
	@params
	ID - Dynamixel XL-320 defined ID
	value - 0-1023
	
	Usage:
	XL320.setJointTorque(1, 512);
	*/
	void setJointTorque(int ID, int value);
	
	/*
	Turn ON Torque of the selected joint.
	
	@params
	ID - Dynamixel XL-320 defined ID
	
	Usage:
	XL320.TorqueON(2);
	*/
	void TorqueON(int ID);
	
	/*
	Turn OFF Torque of the selected joint.
	
	@params
	ID - Dynamixel XL-320 defined ID
	
	Usage:
	XL320.TorqueOFF(4);
	*/
	void TorqueOFF(int ID);
	
	/*
	Turn OFF Torque of the whole robotic trunk.
	
	Usage:
	XL320.deactivateTrunk();
	*/
	void deactivateTrunk();
	
	/*
	Turn ON Torque of the whole robotic trunk.
	
	Usage:
	XL320.activateTrunk();
	*/
	void activateTrunk();
	
	/*
	Test to prove the correct functionality of the robotic trunk.
	
	Usage:
	XL320.quickTest();
	*/
	void quickTest();
	
	/**/
	int writeWord(int ID, int Address, int value);
	/**/
	int readWord(int ID, int Address);
};

extern DynamixelPro hs;

#endif
