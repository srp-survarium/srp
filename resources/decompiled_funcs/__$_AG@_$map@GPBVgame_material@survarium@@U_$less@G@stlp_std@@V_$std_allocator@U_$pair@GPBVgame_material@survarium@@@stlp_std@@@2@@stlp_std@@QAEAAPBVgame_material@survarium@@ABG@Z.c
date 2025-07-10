stlp_std::priv::_Rb_tree_node_base **__thiscall stlp_std::map<unsigned short,survarium::game_material const *,stlp_std::less<unsigned short>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::game_material const *>>>::operator[]<unsigned short>(
        stlp_std::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::material_pair const *> > > *this,
        const unsigned __int16 *__k)
{
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned short const ,survarium::material_pair const *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const ,survarium::material_pair const *> > > v3; // [esp-8h] [ebp-64h] BYREF
  vostok::network_core::packet_reader *p_a1; // [esp-4h] [ebp-60h]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned short const ,survarium::material_pair const *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const ,survarium::material_pair const *> > > *p_result; // [esp+0h] [ebp-5Ch]
  BOOL v6; // [esp+4h] [ebp-58h]
  bool v7; // [esp+Bh] [ebp-51h]
  stlp_std::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::material_pair const *> > > *thisa; // [esp+Ch] [ebp-50h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v9[5]; // [esp+10h] [ebp-4Ch] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v10[2]; // [esp+24h] [ebp-38h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v11; // [esp+2Ch] [ebp-30h]
  int v12; // [esp+30h] [ebp-2Ch]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned short const ,survarium::material_pair const *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const ,survarium::material_pair const *> > > result; // [esp+34h] [ebp-28h] BYREF
  int v14; // [esp+3Ch] [ebp-20h]
  vostok::network_core::packet_reader a1; // [esp+40h] [ebp-1Ch] BYREF
  char v16; // [esp+4Bh] [ebp-11h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v17; // [esp+4Ch] [ebp-10h] BYREF
  bool v18; // [esp+57h] [ebp-5h]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned short const ,survarium::material_pair const *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const ,survarium::material_pair const *> > > __i; // [esp+58h] [ebp-4h] BYREF

  thisa = this;
  v12 = 0;
  v11 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const,survarium::game_material const *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const,survarium::game_material const *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const,survarium::game_material const *>>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::game_material const *>>>::_M_lower_bound<unsigned short>(
                                                                      (stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const ,survarium::game_material const *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const ,survarium::game_material const *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const ,survarium::game_material const *> >,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::game_material const *> > > *)this,
                                                                      __k);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v11,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&__i);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)thisa,
    &v17);
  v10[1] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)v10;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v17,
    v10);
  v7 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)__i._M_node == v10[0];
  v6 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)__i._M_node == v10[0]
    || (v12 |= 1u,
        v9[4] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)&__i._M_node[1],
        v16 = thisa->_M_t._M_key_compare.gap0,
        *__k < (int)*(unsigned __int16 *)&__i._M_node[1]._M_color);
  v18 = v6;
  if ( (v12 & 1) != 0 )
    v12 &= ~1u;
  if ( v18 )
  {
    v14 = 0;
    LOWORD(a1.m_packet) = *__k;
    a1.m_pointer = 0;
    v9[3] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)v9;
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      (boost::_bi::list1<vostok::network_core::packet_reader &> *)__i._M_node,
      v9);
    p_a1 = &a1;
    v3._M_node = (stlp_std::priv::_Rb_tree_node_base *)&a1;
    v9[1] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)&v3;
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      v9[0],
      (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v3);
    stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const,survarium::game_material const *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const,survarium::game_material const *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const,survarium::game_material const *>>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::game_material const *>>>::insert_unique(
      &thisa->_M_t,
      &result,
      v3,
      (const stlp_std::pair<unsigned short const ,survarium::material_pair const *> *)p_a1);
    p_result = &result;
    __i._M_node = result._M_node;
  }
  return &__i._M_node[1]._M_parent;
}
