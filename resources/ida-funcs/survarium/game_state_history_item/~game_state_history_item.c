void __thiscall survarium::game_state_history_item::~game_state_history_item(
        survarium::game_state_history_item *this,
        char *a2)
{
  char *v2; // ebx
  char *v3; // eax
  vostok::network_core::mutable_buffer *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::mutable_buffer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::mutable_buffer *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::mutable_buffer *v10; // ecx

  v2 = a2;
  while ( *(_DWORD *)&v2[(_DWORD)&loc_B9949 + 3] )
  {
    v3 = (char *)vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front((vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&v2[(_DWORD)&loc_B993F + 5]);
    if ( v3 )
    {
      a2 = v3;
      if ( vostok::memory::g_mt_allocator.m_use_memory_monitor )
        vostok::memory::monitor::on_free((void **)&a2, (vostok::command_line::key *)this);
      pt3free((int)this, a2);
    }
  }
  vostok::network_core::buffer_writer::~buffer_writer(
    (vostok::network_core::buffer_writer *)this,
    (vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)((char *)&loc_B9918 + (_DWORD)v2));
  vostok::network_core::mutable_buffer::~mutable_buffer(v4, &v2[(_DWORD)&loc_B9905 + 3]);
  vostok::network_core::buffer_writer::~buffer_writer(
    v5,
    (vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&v2[(_DWORD)&loc_B78EE + 2]);
  vostok::network_core::mutable_buffer::~mutable_buffer(v6, &v2[(_DWORD)&loc_B78DF + 1]);
  vostok::network_core::buffer_writer::~buffer_writer(
    v7,
    (vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&v2[(_DWORD)&loc_B76C4 + 4]);
  vostok::network_core::mutable_buffer::~mutable_buffer(v8, &v2[(_DWORD)&loc_B76B6 + 2]);
  vostok::network_core::buffer_writer::~buffer_writer(
    v9,
    (vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)((char *)&loc_B6AA0 + (_DWORD)v2));
  vostok::network_core::mutable_buffer::~mutable_buffer(v10, &v2[(_DWORD)&loc_B6A8C + 4]);
  `vector destructor iterator'(
    v2,
    0x9054u,
    20,
    (void (__thiscall *)(void *))survarium::player_history_item::~player_history_item);
}
