void __thiscall vostok::ai::planning::world_state_property::world_state_property(
        vostok::ai::planning::world_state_property *this,
        unsigned int *id,
        bool *value)
{
  vostok::math::random32 rnd; // [esp+4h] [ebp-4h] BYREF

  this->m_id = *id;
  this->m_value = *value;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)(*id + 1),
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&rnd);
  this->m_hash = vostok::math::random32::random(&rnd, 0xFFFFFFFF);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)(this->m_hash + *value),
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&rnd);
  this->m_hash ^= vostok::math::random32::random(&rnd, 0xFFFFFFFF);
}
