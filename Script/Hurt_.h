//===================================�L�Įɶ�================================
//Hurt  TWMS151.2
long GodTime ;
bool HurtMode = 1;
bool AutoLoseHpSw = 0;
long AutoLoseHpIcsRet;
long CostHpCount = 01;
void __declspec(naked) GodMode(){
VMProtectBegin("GodMode");
asm{
cmp [esp],0x095AB2D  // �U��ICS�I����^��m [1/2] e8 ? ? ? ? 85 c0 0f 85 ? ? ? ? 8b 83 ? ? 00 00 83 e0 fe 83 f8 12
je HurtTimeBlockControl
Normal:
push 0x096C5B4
ret

HurtTimeBlockControl:
cmp [HurtMode],00
je  Normal
mov eax,[0x0E92390] // �ɶ�
mov eax,[eax+0x1C]
cmp eax,[GodTime]
jl God
add eax,30000
mov [GodTime],eax
mov eax,[GodTime]
jmp Normal

God:
mov [esp],0x095D082 // �L��
jmp Normal
}
VMProtectEnd();
}



//150.2 �۰ʱ���
long CostHpCall = 0x00921C61;
void __declspec(naked) AutoLoseHp(){
VMProtectBegin("AutoLoseHp");
asm{
cmp [esp],0x088EF6F
jne Back
cmp [HurtMode],00
je Back
cmp [AutoLoseHpSw],00
je Back
pushad
mov ecx,[0x0E1847C]
push 01
push 01
push 00
push 00
push 00
push 00
push 00
push 00
push 00
push [CostHpCount] // �榸����q
call dword ptr [CostHpCall]
popad
Back:
push [AutoLoseHpIcsRet]
ret
}
VMProtectEnd();
}
