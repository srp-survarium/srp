void __usercall survarium::base_player::subscribe_on_player_death(survarium::base_player *this@<ecx>, int a2@<eax>)
{
  int v2; // eax

  this->m_uid = 0;
  v2 = a2 + 448;
  if ( *(_DWORD *)(v2 + 4) )
    *(_DWORD *)(*(_DWORD *)(v2 + 8) + 32) = this;
  else
    *(_DWORD *)(v2 + 4) = this;
  *(_DWORD *)(v2 + 8) = this;
}
