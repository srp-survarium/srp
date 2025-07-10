void __userpurge survarium::items_dictionary_cook::on_subresources_loaded(
        survarium::items_dictionary_cook *this@<ecx>,
        float a2@<xmm0>,
        vostok::resources::queries_result *data,
        vostok::configs::binary_config *cooked_resource,
        unsigned int *item_dict_ids)
{
  survarium::game_camera *v5; // ecx
  unsigned int v6; // eax
  vostok::resources::query_result *v7; // eax
  vostok::resources::query_result_for_user *v8; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  stlp_std::priv::_Rb_tree_node_base **v10; // eax
  survarium::dictionary_item *v11; // ecx
  bool is_ammo; // al
  const vostok::variant<32> **v13; // eax
  vostok::configs::binary_config *v14; // ecx
  vostok::configs::binary_config_value *root; // eax
  vostok::configs::binary_config_value *v16; // eax
  const vostok::configs::binary_config_value *v17; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v18; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v19; // ecx
  const vostok::variant<32> **v20; // eax
  vostok::configs::binary_config *v21; // ecx
  vostok::configs::binary_config_value *v22; // eax
  vostok::configs::binary_config_value *v23; // eax
  vostok::configs::binary_config_value *v24; // ecx
  survarium::dictionary_item *v25; // ecx
  const vostok::variant<32> **v26; // eax
  vostok::configs::binary_config *v27; // ecx
  vostok::configs::binary_config_value *v28; // eax
  vostok::configs::binary_config_value *v29; // eax
  vostok::configs::binary_config_value *v30; // ecx
  const vostok::variant<32> **v31; // eax
  vostok::configs::binary_config *v32; // ecx
  vostok::configs::binary_config_value *v33; // eax
  vostok::configs::binary_config_value *v34; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v35; // ecx
  const vostok::variant<32> **v36; // eax
  vostok::configs::binary_config *v37; // ecx
  vostok::configs::binary_config_value *v38; // eax
  vostok::configs::binary_config_value *v39; // eax
  const vostok::configs::binary_config_value *v40; // eax
  vostok::configs::binary_config_value *v41; // ecx
  vostok::resources::memory_usage_type *v42; // eax
  vostok::resources::unmanaged_resource *v43; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v44[2]; // [esp-4h] [ebp-52Ch] BYREF
  vostok::resources::memory_usage_type *memory_usage; // [esp+4h] [ebp-524h]
  int v46; // [esp+8h] [ebp-520h]
  __int64 v47; // [esp+Ch] [ebp-51Ch]
  survarium::items_dictionary_cook *thisa; // [esp+14h] [ebp-514h]
  vostok::memory::doug_lea_allocator *allocator; // [esp+18h] [ebp-510h]
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+1Ch] [ebp-50Ch] BYREF
  int v51; // [esp+294h] [ebp-294h]
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v52; // [esp+500h] [ebp-28h] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v53; // [esp+508h] [ebp-20h] BYREF
  char v54; // [esp+50Fh] [ebp-19h]
  unsigned int clip_size; // [esp+510h] [ebp-18h]
  float clip_weight; // [esp+514h] [ebp-14h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> item_cfg; // [esp+518h] [ebp-10h] BYREF
  survarium::dictionary_item *current_item; // [esp+51Ch] [ebp-Ch]
  unsigned int i; // [esp+520h] [ebp-8h]
  vostok::resources::query_result_for_cook *parent; // [esp+524h] [ebp-4h]

  thisa = this;
  v51 = 0;
  parent = vostok::resources::queries_result::get_parent_query((vostok::resources::queries_result *)this, (int)data);
  v54 = 0;
  survarium::weapon_user_dead_state::finalize(v5);
  for ( i = 0; ; ++i )
  {
    v6 = vostok::resources::queries_result::size(data);
    if ( i >= v6 )
      break;
    v7 = vostok::resources::queries_result::operator[](data, i);
    unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                           v8,
                           (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v7,
                           (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v53);
    vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)unmanaged_resource,
      &item_cfg);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v53);
    v10 = stlp_std::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::dictionary_item>>>::operator[]<unsigned int>(
            (stlp_std::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::dictionary_item> > > *)(&cooked_resource->m_root + 1),
            &item_dict_ids[i]);
    vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
      (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)v10
    + 1,
      &item_cfg);
    current_item = (survarium::dictionary_item *)stlp_std::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::dictionary_item>>>::operator[]<unsigned int>(
                                                   (stlp_std::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::dictionary_item> > > *)(&cooked_resource->m_root + 1),
                                                   &item_dict_ids[i]);
    is_ammo = survarium::dictionary_item::is_ammo(v11, (int)current_item);
    if ( is_ammo )
    {
      v13 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
              (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)is_ammo,
              (int)&item_cfg);
      root = (vostok::configs::binary_config_value *)vostok::configs::binary_config::get_root(v14, (int)v13);
      v16 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](root, "parameters");
      v17 = vostok::configs::binary_config_value::operator[](v16, "clip_size");
      clip_size = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                  v18,
                                  (int)v17);
      v20 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v19, (int)&item_cfg);
      v22 = (vostok::configs::binary_config_value *)vostok::configs::binary_config::get_root(v21, (int)v20);
      v23 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v22, "parameters");
      vostok::configs::binary_config_value::operator[](v23, "clip_weight");
      vostok::configs::binary_config_value::operator float(v24);
      clip_weight = a2;
      v47 = clip_size;
      current_item->weight = a2 / (double)clip_size;
    }
    else
    {
      v26 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(0, (int)&item_cfg);
      v28 = (vostok::configs::binary_config_value *)vostok::configs::binary_config::get_root(v27, (int)v26);
      v29 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v28, "parameters");
      vostok::configs::binary_config_value::operator[](v29, "weight");
      vostok::configs::binary_config_value::operator float(v30);
      v25 = current_item;
      current_item->weight = a2;
    }
    v31 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
            (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)v25,
            (int)&item_cfg);
    v33 = (vostok::configs::binary_config_value *)vostok::configs::binary_config::get_root(v32, (int)v31);
    v34 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v33, "ui_desc");
    if ( vostok::configs::binary_config_value::value_exists(v34, "combat_log_icon") )
    {
      v36 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v35, (int)&item_cfg);
      v38 = (vostok::configs::binary_config_value *)vostok::configs::binary_config::get_root(v37, (int)v36);
      v39 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v38, "ui_desc");
      v40 = vostok::configs::binary_config_value::operator[](v39, "combat_log_icon");
      v46 = vostok::configs::binary_config_value::operator unsigned char(v41, (int)v40);
    }
    else
    {
      v46 = 0;
    }
    current_item->combat_log_icon = v46;
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&item_cfg);
  }
  vostok::resources::memory_usage_type::memory_usage_type(
    (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)&vostok::resources::nocache_memory,
    &v52,
    (vostok::network_core::packet_reader *)0x128,
    (vostok::network_core::packet_reader *)v44[1].m_object);
  memory_usage = v42;
  v44[0].m_object = v43;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    v44,
    cooked_resource);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(memory_usage, parent, v44[0]);
  vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
  allocator = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  call_destructor_predicate = 0;
  v44[0].m_object = (vostok::resources::unmanaged_resource *)&call_destructor_predicate;
  vostok::memory::detail::delete_array_helper_impl<vostok::memory::doug_lea_allocator,unsigned int,vostok::memory::detail::call_destructor_predicate>(
    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
    (unsigned __int8 **)&item_dict_ids);
}
