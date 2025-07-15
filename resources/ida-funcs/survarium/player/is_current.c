BOOL __usercall survarium::player::is_current@<eax>(survarium::player *this@<ecx>, int a2@<eax>)
{
  return !*((_BYTE *)&loc_1143B + a2)
      && survarium::base_network_client::is_player_current(
           (survarium::base_network_client *)*(unsigned __int8 *)(a2 + 304),
           *(_DWORD *)(*(int *)((char *)&dword_11414 + a2) + 13912),
           *(_BYTE *)(a2 + 304));
}
