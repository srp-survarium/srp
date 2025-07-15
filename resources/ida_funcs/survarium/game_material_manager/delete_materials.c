void __thiscall survarium::game_material_manager::delete_materials(survarium::game_material_manager *this)
{
  boost::_bi::list1<vostok::network_core::packet_reader &> *v2[2]; // [esp+14h] [ebp-18h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *M_left; // [esp+1Ch] [ebp-10h]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned short const ,survarium::game_material const *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const ,survarium::game_material const *> > > end; // [esp+24h] [ebp-8h] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned short const ,survarium::game_material const *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const ,survarium::game_material const *> > > it; // [esp+28h] [ebp-4h] BYREF

  M_left = (boost::_bi::list1<vostok::network_core::packet_reader &> *)this->m_materials._M_t._M_header._M_data._M_left;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    M_left,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&it);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)&this->m_materials,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&end);
  while ( 1 )
  {
    v2[1] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)v2;
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      (boost::_bi::list1<vostok::network_core::packet_reader &> *)end._M_node,
      v2);
    if ( (boost::_bi::list1<vostok::network_core::packet_reader &> *)it._M_node == v2[0] )
      break;
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::game_material,vostok::memory::detail::call_destructor_predicate>(
      (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
      (survarium::game_camera **)&it._M_node[1]._M_parent);
    it._M_node = stlp_std::priv::_Rb_global<bool>::_M_increment(it._M_node);
  }
  stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const,survarium::material_pair const *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const,survarium::material_pair const *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const,survarium::material_pair const *>>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::material_pair const *>>>::clear(&this->m_materials._M_t);
}
