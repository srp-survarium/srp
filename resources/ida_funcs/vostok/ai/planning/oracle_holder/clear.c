void __thiscall vostok::ai::planning::oracle_holder::clear(vostok::ai::planning::oracle_holder *this)
{
  unsigned int *oracle_id; // [esp+4h] [ebp-10h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v3[2]; // [esp+Ch] [ebp-8h] BYREF

  while ( this->m_objects._M_t._M_node_count )
  {
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      (boost::_bi::list1<vostok::network_core::packet_reader &> *)this,
      v3);
    v3[1] = v3[0];
    oracle_id = (unsigned int *)&stlp_std::priv::_Rb_global<bool>::_M_decrement((stlp_std::priv::_Rb_tree_node_base *)v3[0])[1];
    vostok::ai::planning::oracle_holder::remove_impl(this, oracle_id, 1);
  }
}
