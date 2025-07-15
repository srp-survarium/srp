vostok::network_core::buffer_reader *__thiscall survarium::game_state_history_item::deserialize(
        survarium::game_state_history_item *this,
        vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *reader,
        vostok::network_core::buffer_reader *a3)
{
  survarium::bullet_manager_history_item *v4; // ecx
  const unsigned __int8 *m_pointer; // esi
  vostok::network_core::buffer_reader *v6; // esi
  unsigned __int8 v7; // al
  survarium::player_history_item *v8; // ecx
  unsigned int v9; // edi
  vostok::network_core::buffer_writer *v10; // ecx
  char *v12; // edi
  survarium::statistics_history_item *v13; // ecx
  vostok::network_core::buffer_writer *v14; // ecx
  survarium::game_objects_history_item *v15; // ecx
  vostok::network_core::buffer_writer *v16; // ecx
  survarium::game_rules_history_item *v17; // ecx
  vostok::network_core::buffer_writer *v18; // ecx
  vostok::network_core::buffer_reader *result; // eax
  unsigned int v20; // [esp+18h] [ebp+8h]
  unsigned int v21; // [esp+18h] [ebp+8h]
  unsigned int v22; // [esp+18h] [ebp+8h]
  vostok::animation::mixing::n_ary_tree_intrusive_base *v23; // [esp+1Ch] [ebp+Ch]
  vostok::network_core::buffer_reader *v24; // [esp+1Ch] [ebp+Ch]

  survarium::game_state_history_item::clear_buffers(this, reader);
  v4 = (survarium::bullet_manager_history_item *)reader;
  m_pointer = a3->m_pointer;
  v23 = *(vostok::animation::mixing::n_ary_tree_intrusive_base **)m_pointer;
  a3->m_pointer = m_pointer + 4;
  *(vostok::animation::mixing::n_ary_tree_intrusive_base **)((char *)&reader->m_object + (_DWORD)&loc_B9937 + 1) = v23;
  v24 = *(vostok::network_core::buffer_reader **)a3->m_pointer;
  v6 = v24;
  a3->m_pointer += 4;
  if ( v24 )
  {
    do
    {
      v7 = vostok::bit_index((unsigned int)v6 & ~((unsigned int)&v6[-1].m_buffer_size + 3));
      survarium::player_history_item::deserialize(v8, (vostok::network_core::mutable_buffer *)&reader[9237 * v7], a3);
      v6 = (vostok::network_core::buffer_reader *)(((unsigned int)&v6[-1].m_buffer_size + 3) & (unsigned int)v6);
    }
    while ( v6 );
  }
  survarium::bullet_manager_history_item::clear(
    v4,
    (vostok::network_core::mutable_buffer *)((char *)reader + (_DWORD)&loc_B468F + 1));
  v9 = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  vostok::network_core::buffer_writer::w(
    v10,
    (vostok::animation::mixing::n_ary_tree_intrusive_base **)((char *)&reader[2308].m_object + (_DWORD)&loc_B468F + 1),
    (unsigned __int8 *)a3->m_pointer,
    v9);
  a3->m_pointer += v9;
  v12 = (char *)&loc_B6AB8 + (_DWORD)reader;
  survarium::statistics_history_item::clear(
    v13,
    (vostok::network_core::mutable_buffer *)((char *)&loc_B6AB8 + (_DWORD)reader));
  v20 = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  vostok::network_core::buffer_writer::w(v14, (_DWORD *)v12 + 772, (unsigned __int8 *)a3->m_pointer, v20);
  a3->m_pointer += v20;
  survarium::game_objects_history_item::clear(
    v15,
    (vostok::network_core::mutable_buffer *)((char *)&loc_B7908 + (_DWORD)reader));
  v21 = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  vostok::network_core::buffer_writer::w(
    v16,
    (char *)&loc_B7908 + (_DWORD)reader + 8208,
    (unsigned __int8 *)a3->m_pointer,
    v21);
  a3->m_pointer += v21;
  survarium::game_rules_history_item::clear(
    v17,
    (vostok::network_core::mutable_buffer *)((char *)reader + (_DWORD)&loc_B76DC + 4));
  v22 = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  vostok::network_core::buffer_writer::w(
    v18,
    (vostok::animation::mixing::n_ary_tree_intrusive_base **)((char *)&reader[132].m_object + (_DWORD)&loc_B76DC + 4),
    (unsigned __int8 *)a3->m_pointer,
    v22);
  a3->m_pointer += v22;
  result = v24;
  *((_BYTE *)&reader->m_object + (_DWORD)&loc_B993F + 2) = 1;
  return result;
}
