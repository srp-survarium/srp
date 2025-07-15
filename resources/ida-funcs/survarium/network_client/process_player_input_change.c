void __thiscall survarium::network_client::process_player_input_change(
        survarium::network_client *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *readera)
{
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v5; // esi
  survarium::game_world_core *v6; // ecx
  unsigned __int8 is_server_aware_of[4]; // [esp+0h] [ebp-14h] BYREF
  survarium::player_input v8; // [esp+4h] [ebp-10h] BYREF
  vostok::network_core::buffer_reader *v9; // [esp+10h] [ebp-4h]
  vostok::network_core::buffer_reader *readerb; // [esp+20h] [ebp+Ch]
  unsigned __int8 reader_3; // [esp+23h] [ebp+Fh]

  v8.actions_mask = 0;
  m_pointer = readera->m_pointer;
  reader_3 = *m_pointer;
  readera->m_pointer = m_pointer + 1;
  is_server_aware_of[0] = reader_3;
  v8.rotation_delta = 0;
  survarium::player_input::deserialize(&v8, readera);
  v5 = readera->m_pointer;
  readerb = *(vostok::network_core::buffer_reader **)v5;
  readera->m_pointer = v5 + 4;
  v9 = readerb;
  survarium::game_world_core::change_input(
    v6,
    *(survarium::game_world_core **)(reader[1724].m_buffer_size + 312),
    is_server_aware_of,
    1);
}
