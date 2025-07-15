void __usercall vostok::physics::bt_character_controller::~bt_character_controller(
        vostok::physics::bt_character_controller *this@<ecx>,
        _DWORD *a2@<esi>)
{
  int v2; // edi
  _BYTE *v3; // ebx

  v2 = *(_DWORD *)(a2[1] + 28);
  if ( *a2 )
  {
    v3 = __RTCastToVoid((void **)*a2);
    (**(void (__thiscall ***)(_DWORD, _DWORD))*a2)(*a2, 0);
    (*(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v2 + 24))(v2, v3);
    *a2 = 0;
  }
}
