void __usercall survarium::base_player::jump(
        survarium::base_player *this@<ecx>,
        survarium::jump_type_enum jump_type@<eax>)
{
  void (__stdcall ****v3)(survarium::hit_receiver *, int, _DWORD); // ebx
  void (__stdcall ****i)(survarium::hit_receiver *, int, _DWORD); // edi
  int v5; // esi
  vostok::physics::bullet_character_controller *v6; // esi

  this->m_jump_type = jump_type;
  survarium::base_player::stand_up(this, (int)this);
  v3 = *(void (__stdcall *****)(survarium::hit_receiver *, int, _DWORD))((char *)&dword_10EAC + (_DWORD)this);
  for ( i = *(void (__stdcall *****)(survarium::hit_receiver *, int, _DWORD))((char *)&dword_10EA8 + (_DWORD)this);
        i != v3;
        ++i )
  {
    (***i)(&this->survarium::hit_receiver, 2, 0.0);
  }
  v5 = *(int *)((char *)&dword_10E74 + (_DWORD)this);
  if ( s_cc_use_old_controller_value )
  {
    *(_BYTE *)(*(_DWORD *)(v5 + 4) + 572) = 1;
  }
  else
  {
    v6 = *(vostok::physics::bullet_character_controller **)v5;
    if ( vostok::physics::bullet_character_controller::can_jump(v6) )
      v6->m_jumping = 1;
  }
}
