void __thiscall survarium::player_history_item::deserialize(
        survarium::player_history_item *this,
        vostok::network_core::mutable_buffer *reader,
        vostok::network_core::buffer_reader *a3)
{
  vostok::network_core::buffer_reader *v3; // ebx
  vostok::network_core::mutable_buffer *v4; // esi
  unsigned int v5; // edi
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v7; // esi
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v8; // eax
  vostok::network_core::buffer_reader readera; // [esp+10h] [ebp-8h]

  v3 = a3;
  v4 = reader;
  survarium::player_serialized_state::clear(&this->player_state, reader);
  v5 = vostok::network_core::buffer_reader::r<unsigned short>(v3);
  vostok::network_core::buffer_writer::w(v6, &v4[129].m_allocator, (unsigned __int8 *)v3->m_pointer, v5);
  v3->m_pointer += v5;
  v7 = (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&v4[261];
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v7,
    0);
  if ( vostok::network_core::buffer_reader::r<bool>(v3) )
  {
    readera.m_buffer = (const unsigned __int8 *)&reader[261].m_buffer;
    readera.m_pointer = (const unsigned __int8 *)0x8000;
    v8 = vostok::animation::animation_player::deserialize_compressed_state((vostok::mutable_buffer *)v3);
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      v8,
      v7);
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&reader);
  }
}
