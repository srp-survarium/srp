stlp_std::priv::_Rb_tree_node_base *__thiscall survarium::game_material_manager::get_material(
        survarium::game_material_manager *this,
        unsigned __int16 id)
{
  boost::_bi::list1<vostok::network_core::packet_reader &> *v5; // [esp+8h] [ebp-20h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v6; // [esp+20h] [ebp-8h] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned short const ,survarium::game_material const *>,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned short const ,survarium::game_material const *> > > it; // [esp+24h] [ebp-4h] BYREF

  v5 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const,survarium::game_material const *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const,survarium::game_material const *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const,survarium::game_material const *>>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::game_material const *>>>::_M_find<unsigned short>(
                                                                     &this->m_materials._M_t,
                                                                     &id);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v5,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&it);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)&this->m_materials,
    &v6);
  if ( (boost::_bi::list1<vostok::network_core::packet_reader &> *)it._M_node == v6 )
    return (stlp_std::priv::_Rb_tree_node_base *)survarium::game_material_manager::get_material(
                                                   this,
                                                   this->m_default_material_id);
  else
    return it._M_node[1]._M_parent;
}
