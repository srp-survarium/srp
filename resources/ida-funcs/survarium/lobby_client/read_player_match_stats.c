char __thiscall survarium::lobby_client::read_player_match_stats(
        survarium::lobby_client *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *a3)
{
  survarium::lobby_menu *v3; // ecx
  vostok::network_core::buffer_reader v5; // [esp+4h] [ebp-24h] BYREF
  __int16 v6; // [esp+10h] [ebp-18h]
  __int16 v7; // [esp+12h] [ebp-16h]
  __int16 v8; // [esp+14h] [ebp-14h]
  __int16 v9; // [esp+16h] [ebp-12h]
  __int16 v10; // [esp+18h] [ebp-10h]
  __int16 v11; // [esp+1Ah] [ebp-Eh]
  int v12; // [esp+1Ch] [ebp-Ch]
  char v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+21h] [ebp-7h]

  v12 = 0;
  v13 = 0;
  v14 = 0;
  memset(&v5, 0, sizeof(v5));
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  survarium::match_player_stats::deserialize(0, &v5, a3);
  survarium::lobby_menu::fill_player_statistic(
    v3,
    *((const survarium::match_player_stats **)reader[5].m_pointer + 3460),
    (unsigned __int16 *)&v5);
  return 1;
}
