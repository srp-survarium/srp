void __usercall survarium::weapon_user_animations_selector::tick(
        survarium::weapon_user_animations_selector *this@<ecx>,
        int a2@<eax>)
{
  int v3; // edi
  survarium::weapon_user_animations_selector *v4; // ecx
  bool v5; // bl
  _BYTE *v6; // eax

  vostok::ai::fsm::tick(&this->m_logic, a2);
  v3 = *(_DWORD *)(*(_DWORD *)(a2 + 60) + 320);
  v5 = survarium::weapon_user_animations_selector::is_going_to_aim(v4, a2)
    && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 88))(v3);
  v6 = (_BYTE *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 96))(v3);
  if ( v6 )
  {
    if ( v6[1108] )
    {
      if ( !v5 )
        (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)v6 + 148))(v6);
    }
    else if ( v5 )
    {
      (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)v6 + 144))(v6);
    }
  }
}
