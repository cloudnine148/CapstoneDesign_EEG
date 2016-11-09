#include "SerialComm.h"

CSerialComm::CSerialComm() {

}
CSerialComm::~CSerialComm()
{

}

int CSerialComm::connect(char* _portNum)
{
	//포트개방하고 개방실패하면 fail반환
	if (!serial.OpenPort(_portNum))
		return RETURN_FAIL;

	serial.ConfigurePort(CBR_9600, 8, FALSE, NOPARITY, ONESTOPBIT);//포트 기본값 설정
	serial.SetCommunicationTimeouts(0, 0, 0, 0, 0);//Timeout값 설정

	return RETURN_SUCCESS;
}

//데이터 전송함수
int CSerialComm::sendCommand(char pos)
{
	//WriteByte()를 통해 데이터 전송에 성공하면 SUCCESS, 실패하면 FAIL을 반환
	if (serial.WriteByte(pos))
		return RETURN_SUCCESS;
	else
		return RETURN_FAIL;
}

//포트 폐쇄
void CSerialComm::disconnect()
{
	serial.ClosePort();
}
