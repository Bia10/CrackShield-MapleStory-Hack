//151.2
bool Freeze_Switch;

void __declspec(naked) Dingua_Main(){
	VMProtectBeginMutation("Dingua_Main");
	asm{
	cmp [Freeze_Switch],00
	je Back
	inc eax//���殳�����`
	Back:
	ret
	}
	VMProtectEnd();

}

