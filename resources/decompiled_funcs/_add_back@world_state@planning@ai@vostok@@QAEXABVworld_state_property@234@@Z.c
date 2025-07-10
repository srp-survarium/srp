void __thiscall vostok::ai::planning::world_state::add_back(
        vostok::ai::planning::world_state *this,
        const vostok::ai::planning::world_state_property *property)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::push_back(
    &this->m_properties._M_impl,
    property);
  this->m_hash ^= property->m_hash;
}
