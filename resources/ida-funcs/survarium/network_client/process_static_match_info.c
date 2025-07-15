void __userpurge survarium::network_client::process_static_match_info(
        survarium::network_client *this@<ecx>,
        int a2@<ebp>,
        _DWORD *a3@<edi>,
        vostok::network_core::buffer_reader *reader)
{
  int v4; // esi
  survarium::match_options *v5; // ecx
  survarium::lobby_menu *v6; // ecx
  int v7; // ebx

  v4 = (*(int (__thiscall **)(_DWORD *))(*a3 + 64))(a3) + 16;
  survarium::match_options::deserialize(v5, (vostok::network_core::buffer_reader *)v4, reader);
  if ( vostok::core::journal_usage() != replay_journal )
    survarium::lobby_menu::switch_to_level_loading(v6, *(_DWORD **)(a3[6] + 13840), *(_BYTE *)(v4 + 29764));
  if ( *(_BYTE *)(v4 + 29772) )
  {
    v7 = *(unsigned __int8 *)(v4 + 29772);
    do
    {
      survarium::player_profile::deserialize_static(
        (survarium::player_profile *)v6,
        (vostok::network_core::buffer_reader *)v4,
        reader);
      v4 += 1488;
      --v7;
    }
    while ( v7 );
  }
  survarium::network_client::query_players((survarium::network_client *)v6, a2, (int)a3, v4, a3);
}
