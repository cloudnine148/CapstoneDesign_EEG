#include "SerialComm.h"

CSerialComm::CSerialComm() {

}
CSerialComm::~CSerialComm()
{

}

int CSerialComm::connect(char* _portNum)
{
	//��Ʈ�����ϰ� ��������ϸ� fail��ȯ
	if (!serial.OpenPort(_portNum))
		return RETURN_FAIL;

	serial.ConfigurePort(CBR_9600, 8, FALSE, NOPARITY, ONESTOPBIT);//��Ʈ �⺻�� ����
	serial.SetCommunicationTimeouts(0, 0, 0, 0, 0);//Timeout�� ����

	return RETURN_SUCCESS;
}

//������ �����Լ�
int CSerialComm::sendCommand(char pos)
{
	//WriteByte()�� ���� ������ ���ۿ� �����ϸ� SUCCESS, �����ϸ� FAIL�� ��ȯ
	if (serial.WriteByte(pos))
		return RETURN_SUCCESS;
	else
		return RETURN_FAIL;
}

//��Ʈ ���
void CSerialComm::disconnect()
{
	serial.ClosePort();
}
