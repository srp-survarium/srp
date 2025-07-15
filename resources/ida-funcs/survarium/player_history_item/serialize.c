void __userpurge survarium::player_history_item::serialize(
        survarium::player_history_item *this@<ecx>,
        int a2@<eax>,
        vostok::network_core::buffer_writer *writer)
{
  vostok::network_core::buffer_writer *v3; // ebx
  vostok::network_core::buffer_writer *v5; // ecx
  const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v6; // esi
  vostok::network_core::buffer_writer *v7; // ecx
  unsigned int v8; // edi
  vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v9; // esi
  const char *v10; // eax
  vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v11; // ecx
  const char *v12; // [esp+4h] [ebp-14h]
  const char *v13; // [esp+8h] [ebp-10h]
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  unsigned int m_size; // [esp+14h] [ebp-4h]

  v3 = writer;
  writer = (vostok::network_core::buffer_writer *)*(unsigned __int16 *)(a2 + 2060);
  vostok::network_core::buffer_writer::w<unsigned short>(
    (unsigned __int8 *)&writer,
    (vostok::network_core::buffer_writer *)this,
    v3,
    "c:\\survarium.deploy\\sources\\vostok/game_core/player_serialized_state_inline.h",
    (const char *)0x1D,
    "survarium::player_serialized_state::serialize",
    "(u16)m_buffer.size()");
  vostok::network_core::buffer_writer::w(v5, v3, *(unsigned __int8 **)(a2 + 2052), *(_DWORD *)(a2 + 2060));
  vostok::network_core::aggregate(
    &v3->serialization_operations_descriptors,
    (vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)(a2 + 2064));
  v6 = (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 4176);
  HIBYTE(writer) = v6->m_object != 0;
  vostok::network_core::buffer_writer::w<bool>(
    (const bool *)&writer + 3,
    v7,
    v3,
    ".\\player_history_item.cpp",
    (const char *)0x27,
    "survarium::player_history_item::serialize",
    "animation_tree != 0");
  m_size = v3->m_buffer->m_size;
  if ( v6->m_object )
  {
    vostok::animation::animation_player::serialize_state_and_compress(v6, (vostok::animation::mixing::n_ary_tree *)v3);
    if ( vostok::network_core::g_debug_hash_mismatches && vostok::network_core::g_debug_hash_mismatches_enabled )
    {
      v8 = v3->m_buffer->m_size;
      v9 = (vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)vostok::memory::new_helper<vostok::network_core::buffer_writer::serialization_operation_descriptor>::call<vostok::memory::pthreads3_allocator>(&vostok::memory::g_mt_allocator, v12, v13, v14);
      if ( v9 )
      {
        LOBYTE(writer) = v3->player_id;
        v10 = type_info::name(&void * `RTTI Type Descriptor', &__type_info_root_node);
        v9->m_size = 0;
        *(_DWORD *)&v9->gap4 = v10;
        LOBYTE(v10) = (_BYTE)writer;
        v9->m_first = (vostok::network_core::buffer_writer::serialization_operation_descriptor *)"animation_player";
        v9->m_last = (vostok::network_core::buffer_writer::serialization_operation_descriptor *)"survarium::player_histor"
                                                                                                "y_item::serialize";
        v9[1].m_size = (unsigned int)".\\player_history_item.cpp";
        *(_DWORD *)&v9[1].gap4 = 84;
        v9[1].m_first = (vostok::network_core::buffer_writer::serialization_operation_descriptor *)(v8 - m_size);
        LOBYTE(v9[1].m_last) = (_BYTE)v10;
        v11 = v9;
      }
      else
      {
        v11 = 0;
      }
      vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        v11,
        (int)v3);
    }
  }
}
