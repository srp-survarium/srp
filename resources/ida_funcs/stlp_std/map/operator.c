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


stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *__usercall stlp_std::map<unsigned int,survarium::base_point_stats,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::base_point_stats>>>::operator[]<unsigned int>@<eax>(
        stlp_std::map<unsigned int,survarium::base_point_stats,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::base_point_stats> > > *this@<ecx>,
        stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *a2@<eax>)
{
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *M_node; // ecx
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *v4; // edx
  stlp_std::priv::_Rb_tree_node_base *v5; // esi
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,survarium::base_point_stats> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> >,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::base_point_stats> > > v7; // [esp-8h] [ebp-2Ch] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > result; // [esp+10h] [ebp-14h] BYREF
  __int64 v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+1Ch] [ebp-8h]

  *(_DWORD *)&v7._M_key_compare.gap0 = 0;
  M_node = (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *)a2[1]._M_node;
  v4 = a2;
  while ( M_node )
  {
    if ( M_node[4]._M_node < (stlp_std::priv::_Rb_tree_node_base *)*(_DWORD *)&this->_M_t._M_header._M_data._M_color )
    {
      M_node = (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *)M_node[3]._M_node;
    }
    else
    {
      v4 = M_node;
      M_node = (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *)M_node[2]._M_node;
    }
  }
  if ( v4 != a2
    && (stlp_std::priv::_Rb_tree_node_base *)*(_DWORD *)&this->_M_t._M_header._M_data._M_color >= v4[4]._M_node )
  {
    return v4 + 5;
  }
  v5 = *(stlp_std::priv::_Rb_tree_node_base **)&this->_M_t._M_header._M_data._M_color;
  v10 = 0;
  result._M_node = v5;
  v9 = 0;
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,survarium::base_point_stats>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,survarium::base_point_stats>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,survarium::base_point_stats>>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::base_point_stats>>>::insert_unique(
    &v7,
    v4,
    (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > >)&result,
    (const stlp_std::pair<unsigned int const ,survarium::base_point_stats> *)v7._M_header._M_data._M_left);
  return (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *)(*(_DWORD *)&v7._M_key_compare.gap0 + 20);
}


stlp_std::priv::_Rb_tree_node_base **__thiscall stlp_std::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::dictionary_item>>>::operator[]<unsigned int>(
        stlp_std::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::dictionary_item> > > *this,
        const unsigned int *__k)
{
  stlp_std::priv::_Rb_tree_node_base *v2; // ecx
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::dictionary_item>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::dictionary_item> > > v4; // [esp-8h] [ebp-2B0h] BYREF
  const stlp_std::pair<unsigned int const ,survarium::dictionary_item> *p_val; // [esp-4h] [ebp-2ACh]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::dictionary_item>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::dictionary_item> > > *p_result; // [esp+8h] [ebp-2A0h]
  BOOL v7; // [esp+Ch] [ebp-29Ch]
  bool v8; // [esp+13h] [ebp-295h]
  stlp_std::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::dictionary_item> > > *thisa; // [esp+14h] [ebp-294h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v10[7]; // [esp+1Ch] [ebp-28Ch] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v11[2]; // [esp+38h] [ebp-270h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v12; // [esp+40h] [ebp-268h]
  int v13; // [esp+44h] [ebp-264h]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::dictionary_item>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::dictionary_item> > > result; // [esp+48h] [ebp-260h] BYREF
  survarium::dictionary_item __that; // [esp+50h] [ebp-258h] BYREF
  stlp_std::pair<unsigned int const ,survarium::dictionary_item> __val; // [esp+170h] [ebp-138h] BYREF
  stlp_std::less<unsigned int> v17; // [esp+297h] [ebp-11h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v18; // [esp+298h] [ebp-10h] BYREF
  bool v19; // [esp+2A3h] [ebp-5h]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::dictionary_item>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::dictionary_item> > > __i; // [esp+2A4h] [ebp-4h] BYREF

  thisa = this;
  v13 = 0;
  v12 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,survarium::dictionary_item>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,survarium::dictionary_item>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,survarium::dictionary_item>>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::dictionary_item>>>::_M_lower_bound<unsigned int>(
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
        v10[6] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)&__i._M_node[1],
        v17.gap0 = thisa->_M_t._M_key_compare.gap0,
        stlp_std::less<unsigned int>::operator()(&v17, __k, (const unsigned int *)&__i._M_node[1]));
  v19 = v7;
  if ( (v13 & 1) != 0 )
  {
    v13 &= ~1u;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v17);
  }
  if ( v19 )
  {
    vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&__that.item_cfg);
    vostok::fixed_string<260>::fixed_string<260>(&__that.item_cfg_name);
    __val.first = *__k;
    survarium::dictionary_item::dictionary_item(&__val.second, &__that);
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
    stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,survarium::dictionary_item>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,survarium::dictionary_item>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,survarium::dictionary_item>>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::dictionary_item>>>::insert_unique(
      &thisa->_M_t,
      &result,
      v4,
      p_val);
    p_result = &result;
    __i._M_node = result._M_node;
    survarium::dictionary_item::~dictionary_item(&__val.second);
    survarium::dictionary_item::~dictionary_item(&__that);
  }
  return &__i._M_node[1]._M_parent;
}


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
