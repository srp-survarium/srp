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
