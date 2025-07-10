void __thiscall survarium::player::end_jump(survarium::player *this)
{
  *(_BYTE *)(**(_DWORD **)((char *)&dword_10DC8 + (_DWORD)this) + 257) = 0;
  if ( byte_10F36[(_DWORD)this] )
    this->m_current.physics_controller->m_bt_controller->m_jumping = 0;
}
