stlp_std::priv::_Rb_tree_node_base **__thiscall stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int>>>::operator[]<char const *>(
        stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *this,
        const char *const *__k)
{
  stlp_std::priv::_Rb_tree_node_base *v2; // ecx
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<char const * const,unsigned int>,stlp_std::priv::_MapTraitsT<stlp_std::pair<char const * const,unsigned int> > > v4; // [esp-8h] [ebp-64h] BYREF
  const stlp_std::pair<char const * const,unsigned int> *p_val; // [esp-4h] [ebp-60h]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<char const * const,unsigned int>,stlp_std::priv::_MapTraitsT<stlp_std::pair<char const * const,unsigned int> > > *p_result; // [esp+0h] [ebp-5Ch]
  BOOL v7; // [esp+4h] [ebp-58h]
  bool v8; // [esp+Bh] [ebp-51h]
  stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *thisa; // [esp+Ch] [ebp-50h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v10[5]; // [esp+10h] [ebp-4Ch] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v11[2]; // [esp+24h] [ebp-38h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v12; // [esp+2Ch] [ebp-30h]
  int v13; // [esp+30h] [ebp-2Ch]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<char const * const,unsigned int>,stlp_std::priv::_MapTraitsT<stlp_std::pair<char const * const,unsigned int> > > result; // [esp+34h] [ebp-28h] BYREF
  int v15; // [esp+3Ch] [ebp-20h]
  stlp_std::pair<char const * const,unsigned int> __val; // [esp+40h] [ebp-1Ch] BYREF
  char v17; // [esp+4Bh] [ebp-11h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v18; // [esp+4Ch] [ebp-10h] BYREF
  bool v19; // [esp+57h] [ebp-5h]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<char const * const,unsigned int>,stlp_std::priv::_MapTraitsT<stlp_std::pair<char const * const,unsigned int> > > __i; // [esp+58h] [ebp-4h] BYREF

  thisa = this;
  v13 = 0;
  v12 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<char const *,stlp_std::less<char const *>,stlp_std::pair<char const * const,unsigned int>,stlp_std::priv::_Select1st<stlp_std::pair<char const * const,unsigned int>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<char const * const,unsigned int>>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int>>>::_M_lower_bound<char const *>(
                                                                      &this->_M_t,
                                                                      __k);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v12,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&__i);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)thisa,
    &v18);
  v11[1] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)v11;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v18,
    v11);
  v8 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)__i._M_node == v11[0];
  v7 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)__i._M_node == v11[0]
    || (v13 |= 1u,
        v10[4] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)&__i._M_node[1],
        v17 = thisa->_M_t._M_key_compare.gap0,
        *__k < (const char *const)*(_DWORD *)&__i._M_node[1]._M_color);
  v19 = v7;
  if ( (v13 & 1) != 0 )
    v13 &= ~1u;
  if ( v19 )
  {
    v15 = 0;
    __val.first = *__k;
    __val.second = 0;
    v10[3] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)v10;
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      (boost::_bi::list1<vostok::network_core::packet_reader &> *)__i._M_node,
      v10);
    p_val = &__val;
    v4._M_node = v2;
    v10[1] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)&v4;
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      v10[0],
      (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v4);
    stlp_std::priv::_Rb_tree<char const *,stlp_std::less<char const *>,stlp_std::pair<char const * const,unsigned int>,stlp_std::priv::_Select1st<stlp_std::pair<char const * const,unsigned int>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<char const * const,unsigned int>>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int>>>::insert_unique(
      &thisa->_M_t,
      &result,
      v4,
      p_val);
    p_result = &result;
    __i._M_node = result._M_node;
  }
  return &__i._M_node[1]._M_parent;
}
