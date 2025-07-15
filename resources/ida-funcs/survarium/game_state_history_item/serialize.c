void __userpurge survarium::game_state_history_item::serialize(
        survarium::game_state_history_item *this@<ecx>,
        int a2@<eax>,
        vostok::network_core::buffer_writer *writer,
        unsigned int active_clients_mask)
{
  vostok::network_core::buffer_writer *v4; // ebx
  vostok::network_core::buffer_writer *v6; // eax
  vostok::network_core::buffer_writer::serialization_operation_descriptor *i; // eax
  vostok::network_core::buffer_writer *v8; // ecx
  unsigned int j; // edi
  unsigned __int8 v10; // al
  survarium::player_history_item *v11; // ecx
  vostok::network_core::buffer_writer *v12; // ecx
  vostok::network_core::buffer_writer *v13; // ecx
  vostok::network_core::buffer_writer *v14; // ecx
  vostok::network_core::buffer_writer *v15; // ecx
  vostok::network_core::buffer_writer *v16; // [esp-4h] [ebp-14h]
  vostok::network_core::buffer_writer *v17; // [esp-4h] [ebp-14h]
  vostok::network_core::buffer_writer *v18; // [esp-4h] [ebp-14h]

  v4 = writer;
  writer->player_id = -1;
  if ( vostok::network_core::g_debug_hash_mismatches )
  {
    if ( vostok::network_core::g_debug_hash_mismatches_enabled )
    {
      while ( *(_DWORD *)((char *)&loc_B9949 + a2 + 3) )
      {
        v6 = (vostok::network_core::buffer_writer *)vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front((vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)((char *)&loc_B993F + a2 + 5));
        if ( v6 )
        {
          writer = v6;
          if ( vostok::memory::g_mt_allocator.m_use_memory_monitor )
            vostok::memory::monitor::on_free((void **)&writer, (vostok::command_line::key *)this);
          pt3free((int)this, (char *)writer);
        }
      }
    }
    if ( vostok::network_core::g_debug_hash_mismatches && vostok::network_core::g_debug_hash_mismatches_enabled )
    {
      for ( i = v4->serialization_operations_descriptors.m_first; i; i = i->next )
        ;
    }
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&active_clients_mask,
    (vostok::network_core::buffer_writer *)this,
    v4,
    ".\\game_state_history_item.cpp",
    (const char *)0x60,
    "survarium::game_state_history_item::serialize",
    "active_clients_mask");
  for ( j = active_clients_mask; j; j &= j - 1 )
  {
    v10 = vostok::bit_index(j & ~(j - 1));
    v4->player_id = v10;
    survarium::player_history_item::serialize(v11, a2 + 36948 * v10, v4);
  }
  v4->player_id = -1;
  active_clients_mask = *(unsigned __int16 *)((char *)&loc_B6A9C + a2);
  vostok::network_core::buffer_writer::w<unsigned short>(
    (unsigned __int8 *)&active_clients_mask,
    v8,
    v4,
    "c:\\survarium.deploy\\sources\\vostok/game_core/bullet_manager_history_item_inline.h",
    (const char *)0x1D,
    "survarium::bullet_manager_history_item::serialize",
    "(u16)m_buffer.size()");
  vostok::network_core::buffer_writer::w(
    v12,
    v4,
    *(unsigned __int8 **)((char *)&loc_B6A94 + a2),
    *(_DWORD *)((char *)&loc_B6A9C + a2));
  vostok::network_core::aggregate(
    &v4->serialization_operations_descriptors,
    (vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)((char *)&loc_B6AA0 + a2));
  active_clients_mask = *(unsigned __int16 *)((char *)&loc_B76C4 + a2);
  vostok::network_core::buffer_writer::w<unsigned short>(
    (unsigned __int8 *)&active_clients_mask,
    v16,
    v4,
    "c:\\survarium.deploy\\sources\\vostok/game_core/statistics_history_item_inline.h",
    (const char *)0x1D,
    "survarium::statistics_history_item::serialize",
    "(u16)m_buffer.size()");
  vostok::network_core::buffer_writer::w(
    v13,
    v4,
    *(unsigned __int8 **)((char *)&loc_B76BB + a2 + 1),
    *(_DWORD *)((char *)&loc_B76C4 + a2));
  vostok::network_core::aggregate(
    &v4->serialization_operations_descriptors,
    (vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)((char *)&loc_B76C4 + a2 + 4));
  active_clients_mask = *(unsigned __int16 *)((char *)&loc_B9913 + a2 + 1);
  vostok::network_core::buffer_writer::w<unsigned short>(
    (unsigned __int8 *)&active_clients_mask,
    v17,
    v4,
    "c:\\survarium.deploy\\sources\\vostok/game_core/game_objects_history_item_inline.h",
    (const char *)0x1D,
    "survarium::game_objects_history_item::serialize",
    "(u16)m_buffer.size()");
  vostok::network_core::buffer_writer::w(
    v14,
    v4,
    *(unsigned __int8 **)((char *)&loc_B990B + a2 + 1),
    *(_DWORD *)((char *)&loc_B9913 + a2 + 1));
  vostok::network_core::aggregate(
    &v4->serialization_operations_descriptors,
    (vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)((char *)&loc_B9918 + a2));
  active_clients_mask = *(unsigned __int16 *)((char *)&loc_B78EA + a2 + 2);
  vostok::network_core::buffer_writer::w<unsigned short>(
    (unsigned __int8 *)&active_clients_mask,
    v18,
    v4,
    "c:\\survarium.deploy\\sources\\vostok/game_core/game_rules_history_item_inline.h",
    (const char *)0x1D,
    "survarium::game_rules_history_item::serialize",
    "(u16)m_buffer.size()");
  vostok::network_core::buffer_writer::w(
    v15,
    v4,
    *(unsigned __int8 **)((char *)&loc_B78E3 + a2 + 1),
    *(_DWORD *)((char *)&loc_B78EA + a2 + 2));
  vostok::network_core::aggregate(
    &v4->serialization_operations_descriptors,
    (vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)((char *)&loc_B78EE + a2 + 2));
  vostok::network_core::aggregate(
    (vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)((char *)&loc_B993F + a2 + 5),
    &v4->serialization_operations_descriptors);
}
