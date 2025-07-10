void __thiscall vostok::ai::planning::world_state::add(
        vostok::ai::planning::world_state *this,
        const vostok::ai::planning::world_state_property **iter,
        const vostok::ai::planning::world_state_property *property)
{
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::insert(
    &this->m_properties._M_impl,
    &this->m_properties._M_impl._M_start[*iter - this->m_properties._M_impl._M_start],
    property);
  this->m_hash ^= property->m_hash;
}
