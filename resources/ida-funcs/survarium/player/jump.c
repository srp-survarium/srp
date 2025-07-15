void __thiscall survarium::player::jump(survarium::player *this)
{
  vostok::physics::bullet_character_controller *v2; // ecx
  void (__stdcall ****v3)(survarium::hit_receiver *, int, _DWORD); // edi
  void (__stdcall ****i)(survarium::hit_receiver *, int, _DWORD); // esi

  this->stand_up(this);
  v3 = *(void (__stdcall *****)(survarium::hit_receiver *, int, _DWORD))((char *)&dword_10E14 + (_DWORD)this);
  for ( i = *(void (__stdcall *****)(survarium::hit_receiver *, int, _DWORD))((char *)&dword_10E10 + (_DWORD)this);
        i != v3;
        ++i )
  {
    (***i)(&this->survarium::hit_receiver, 2, 0.0);
  }
  vostok::physics::bullet_character_controller::jump(v2, **(_DWORD **)((char *)&dword_10DC8 + (_DWORD)this));
  if ( byte_10F36[(_DWORD)this] )
    vostok::physics::bullet_character_controller::jump(
      (vostok::physics::bullet_character_controller *)this->m_current.physics_controller,
      (int)this->m_current.physics_controller->m_bt_controller);
}
