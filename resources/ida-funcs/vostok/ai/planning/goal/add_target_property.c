void __thiscall vostok::ai::planning::goal::add_target_property(
        vostok::ai::planning::goal *this,
        const vostok::ai::planning::pddl_predicate *required_predicate,
        bool value,
        survarium::game_camera *object_ids)
{
  vostok::buffer_vector<vostok::resources::request> *v4; // ecx
  vostok::variant<32> *v6; // [esp+18h] [ebp-38h] BYREF
  char v7; // [esp+22h] [ebp-2Eh]
  void *buffer; // [esp+24h] [ebp-2Ch]
  char v9; // [esp+2Bh] [ebp-25h]
  unsigned int i; // [esp+2Ch] [ebp-24h]
  vostok::ai::planning::pddl_world_state_property_impl property_to_be_added; // [esp+30h] [ebp-20h] BYREF

  v9 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  buffer = property_to_be_added.m_indices.m_buffer;
  vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
    &property_to_be_added.m_indices,
    (unsigned int *)property_to_be_added.m_indices.m_buffer,
    4u,
    0);
  property_to_be_added.m_predicate = required_predicate;
  property_to_be_added.m_result = value;
  for ( i = 0;
        i < (signed int)(LODWORD(object_ids->m_inverted_view_matrix.i.x) - (unsigned int)object_ids->__vftable) >> 2;
        ++i )
  {
    v7 = 0;
    survarium::weapon_user_dead_state::finalize(object_ids);
    v6 = (vostok::variant<32> *)*((_DWORD *)&object_ids->get_projection_matrix + i);
    vostok::buffer_vector<unsigned int>::push_back(
      (vostok::buffer_vector<vostok::variant<32> const *> *)&property_to_be_added,
      (const vostok::variant<32> **)&v6);
  }
  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::push_back(
    &this->m_target_state._M_impl,
    &property_to_be_added);
  vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v4, &property_to_be_added);
}
