void __thiscall survarium::messaging_client::process_incoming_important_text_message(
        survarium::messaging_client *this,
        vostok::network_core::buffer_reader *reader,
        int a3)
{
  unsigned __int8 *v4; // esi
  vostok::network_core::buffer_reader *v5; // ecx
  _BYTE *v6; // esi
  vostok::network_core::buffer_reader *v7; // ecx
  int *v8; // esi
  _DWORD *v9; // eax
  vostok::network_core::buffer_reader *v10; // esi
  vostok::messaging::send_message_params *m_buffer; // edi
  survarium::lobby_menu *v12; // ecx
  survarium::messaging_client *v13; // ecx
  int v14; // eax
  survarium::lobby_client *v15; // ecx
  stlp_std::priv::_Impl_vector<vostok::messaging::send_message_params,survarium::std_allocator<vostok::messaging::send_message_params> > *v16; // [esp-4h] [ebp-1ACh]
  unsigned int v17; // [esp+0h] [ebp-1A8h]
  bool v18; // [esp+4h] [ebp-1A4h]
  unsigned __int8 v19[256]; // [esp+10h] [ebp-198h] BYREF
  stlp_std::__true_type __formal[152]; // [esp+110h] [ebp-98h] BYREF
  int v21; // [esp+1B4h] [ebp+Ch]
  int v22; // [esp+1B4h] [ebp+Ch]

  *(_DWORD *)&__formal[148] = v19;
  v4 = *(unsigned __int8 **)(a3 + 4);
  v5 = (vostok::network_core::buffer_reader *)*v4;
  *(_DWORD *)(a3 + 4) = ++v4;
  *(_DWORD *)&__formal[136] = v5;
  v21 = *(_DWORD *)v4;
  *(_DWORD *)(a3 + 4) = v4 + 4;
  *(_DWORD *)&__formal[68] = v21;
  vostok::network_core::buffer_reader::r_string(v5, (char *)a3, (unsigned __int8 *)&__formal[72]);
  v6 = *(_BYTE **)(a3 + 4);
  HIBYTE(v21) = *v6;
  *(_DWORD *)(a3 + 4) = v6 + 1;
  *(_DWORD *)&__formal[140] = HIBYTE(v21);
  vostok::network_core::buffer_reader::r_string(v7, (char *)a3, v19);
  v8 = *(int **)(a3 + 4);
  v9 = v8 + 1;
  v22 = *v8;
  v10 = reader;
  *(_DWORD *)(a3 + 4) = v9;
  *(_DWORD *)&__formal[144] = v22;
  if ( stlp_std::priv::__find<vostok::messaging::send_message_params const *,unsigned int>(
         (const vostok::messaging::send_message_params *)reader[33].m_buffer_size,
         (const unsigned int *)&__formal[144],
         (const vostok::messaging::send_message_params *)reader[34].m_buffer) == (const vostok::messaging::send_message_params *)reader[34].m_buffer )
  {
    m_buffer = (vostok::messaging::send_message_params *)reader[34].m_buffer;
    if ( m_buffer == (vostok::messaging::send_message_params *)reader[34].m_pointer )
    {
      stlp_std::priv::_Impl_vector<vostok::messaging::send_message_params,survarium::std_allocator<vostok::messaging::send_message_params>>::_M_insert_overflow(
        v16,
        (unsigned int)&reader[33].m_buffer_size,
        m_buffer,
        __formal,
        v17,
        v18);
    }
    else
    {
      qmemcpy(m_buffer, __formal, sizeof(vostok::messaging::send_message_params));
      v12 = 0;
      reader[34].m_buffer += 152;
      v10 = reader;
    }
    survarium::lobby_menu::important_message_arrived(
      v12,
      *((_DWORD *)v10->m_buffer + 3460),
      *(unsigned int *)&__formal[144],
      *(const char **)&__formal[140],
      (char *)v19,
      (char *)&__formal[72]);
    if ( *(_DWORD *)&__formal[140] == 1 || *(_DWORD *)&__formal[140] == 4 )
    {
      survarium::messaging_client::read_important_message(v13, (int)v10, *(unsigned int *)&__formal[144], answer_accept);
    }
    else if ( *(_DWORD *)&__formal[140] == 3 )
    {
      survarium::messaging_client::read_important_message(v13, (int)v10, *(unsigned int *)&__formal[144], answer_accept);
      v14 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)v10->m_buffer + 3478) + 60))(*((_DWORD *)v10->m_buffer + 3478));
      survarium::lobby_client::add_squad_member(v15, v14, (const char (*)[64])&__formal[72]);
    }
  }
}
