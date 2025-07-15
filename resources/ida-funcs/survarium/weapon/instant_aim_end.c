void __thiscall survarium::weapon::instant_aim_end(survarium::weapon *this)
{
  survarium::player *v2; // ecx
  int v3; // edx

  survarium::weapon_core::instant_aim_end(this);
  if ( survarium::player::is_current(v2, (int)this->m_user) )
  {
    if ( *(_BYTE *)(v3 + 764) )
      *(_DWORD *)(*(_DWORD *)((char *)&loc_11403 + v3 + 5) + 872) = 1;
  }
}
