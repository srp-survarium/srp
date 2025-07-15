void __thiscall survarium::game_state_history_item::clear_buffers(
        survarium::game_state_history_item *this,
        vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *a2)
{
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v2; // ebx
  survarium::player_serialized_state *v3; // ecx
  survarium::player_serialized_state *v4; // ecx
  vostok::command_line::key *v5; // ecx
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v6; // eax
  survarium::statistics_history_item *v7; // ecx
  survarium::game_objects_history_item *v8; // ecx
  survarium::game_rules_history_item *v9; // ecx
  int v10; // [esp+10h] [ebp-4h]

  v2 = a2;
  a2 += 522;
  v10 = 20;
  do
  {
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      a2 + 522,
      0);
    survarium::player_serialized_state::clear(v3, (vostok::network_core::mutable_buffer *)&a2[-522]);
    survarium::player_serialized_state::clear(v4, (vostok::network_core::mutable_buffer *)a2);
    a2 += 9237;
    --v10;
  }
  while ( v10 );
  while ( *(vostok::animation::mixing::n_ary_tree_intrusive_base **)((char *)&v2->m_object + (_DWORD)&loc_B9949 + 3) )
  {
    v6 = (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front((vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)((char *)v2 + (_DWORD)&loc_B993F + 5));
    if ( v6 )
    {
      a2 = v6;
      if ( vostok::memory::g_mt_allocator.m_use_memory_monitor )
        vostok::memory::monitor::on_free((void **)&a2, v5);
      pt3free((int)v5, (char *)a2);
    }
  }
  survarium::bullet_manager_history_item::clear(
    (survarium::bullet_manager_history_item *)v5,
    (vostok::network_core::mutable_buffer *)((char *)v2 + (_DWORD)&loc_B468F + 1));
  survarium::statistics_history_item::clear(
    v7,
    (vostok::network_core::mutable_buffer *)((char *)&loc_B6AB8 + (_DWORD)v2));
  survarium::game_objects_history_item::clear(
    v8,
    (vostok::network_core::mutable_buffer *)((char *)&loc_B7908 + (_DWORD)v2));
  survarium::game_rules_history_item::clear(
    v9,
    (vostok::network_core::mutable_buffer *)((char *)v2 + (_DWORD)&loc_B76DC + 4));
  *((_BYTE *)&v2->m_object + (_DWORD)&loc_B993F + 2) = 0;
}
