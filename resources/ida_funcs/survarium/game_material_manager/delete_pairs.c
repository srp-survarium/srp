void __thiscall survarium::game_material_manager::delete_pairs(survarium::game_material_manager *this)
{
  boost::_bi::list1<vostok::network_core::packet_reader &> *v2[4]; // [esp+14h] [ebp-38h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *M_right; // [esp+24h] [ebp-28h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v4[2]; // [esp+28h] [ebp-24h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *M_left; // [esp+30h] [ebp-1Ch]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned short const ,survarium::material_pair const *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const ,survarium::material_pair const *> > > internail_it; // [esp+3Ch] [ebp-10h] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned short const ,survarium::material_pair const *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const ,survarium::material_pair const *> > > internail_end; // [esp+40h] [ebp-Ch] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned short const ,survarium::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const ,survarium::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short> > > > > end; // [esp+44h] [ebp-8h] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned short const ,survarium::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const ,survarium::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short> > > > > it; // [esp+48h] [ebp-4h] BYREF

  M_left = (boost::_bi::list1<vostok::network_core::packet_reader &> *)this->m_pairs._M_t._M_header._M_data._M_left;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    M_left,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&it);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)&this->m_pairs,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&end);
  while ( 1 )
  {
    v4[1] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)v4;
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      (boost::_bi::list1<vostok::network_core::packet_reader &> *)end._M_node,
      v4);
    if ( (boost::_bi::list1<vostok::network_core::packet_reader &> *)it._M_node == v4[0] )
      break;
    v2[3] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)&it._M_node[1]._M_parent;
    M_right = (boost::_bi::list1<vostok::network_core::packet_reader &> *)it._M_node[1]._M_right;
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      M_right,
      (boost::_bi::list1<vostok::network_core::packet_reader &> **)&internail_it);
    v2[2] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)&it._M_node[1]._M_parent;
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      (boost::_bi::list1<vostok::network_core::packet_reader &> *)&it._M_node[1]._M_parent,
      (boost::_bi::list1<vostok::network_core::packet_reader &> **)&internail_end);
    while ( 1 )
    {
      v2[1] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)v2;
      stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
        (boost::_bi::list1<vostok::network_core::packet_reader &> *)internail_end._M_node,
        v2);
      if ( (boost::_bi::list1<vostok::network_core::packet_reader &> *)internail_it._M_node == v2[0] )
        break;
      vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::material_pair,vostok::memory::detail::call_destructor_predicate>(
        (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
        (survarium::material_pair **)&internail_it._M_node[1]._M_parent);
      internail_it._M_node = stlp_std::priv::_Rb_global<bool>::_M_increment(internail_it._M_node);
    }
    it._M_node = stlp_std::priv::_Rb_global<bool>::_M_increment(it._M_node);
  }
  stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const,survarium::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short>>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const,survarium::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short>>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const,survarium::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short>>>>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short>>>>>::clear(&this->m_pairs._M_t);
}
