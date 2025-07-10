void __thiscall survarium::items_dictionary_cook::on_items_dictionary_config_loaded(
        survarium::items_dictionary_cook *this,
        vostok::resources::queries_result *data)
{
  survarium::game_camera *v2; // ecx
  vostok::memory::doug_lea_allocator *v3; // eax
  survarium::items_dictionary *v4; // eax
  vostok::resources::query_result *v5; // eax
  vostok::resources::query_result_for_user *v6; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *v8; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v9; // ecx
  const vostok::variant<32> **v10; // eax
  vostok::configs::binary_config *v11; // ecx
  vostok::vectora<vostok::resources::request> *v12; // ecx
  vostok::configs::binary_config_value *v13; // eax
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v14; // eax
  vostok::configs::binary_config_value *v15; // eax
  survarium::game_camera *v16; // ecx
  _BYTE *v17; // eax
  vostok::strings::detail::tuples *v18; // ecx
  void *v19; // esp
  vostok::strings::detail::tuples *v20; // ecx
  survarium::game_camera *v21; // ecx
  char *v22; // eax
  vostok::resources::request *v23; // eax
  vostok::resources::request *v24; // edx
  const vostok::configs::binary_config_value *v25; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v26; // ecx
  const vostok::configs::binary_config_value *v27; // eax
  vostok::configs::binary_config_value *v28; // ecx
  vostok::configs::binary_config_value *v29; // eax
  vostok::configs::binary_config_value *v30; // eax
  const vostok::configs::binary_config_value *v31; // eax
  stlp_std::priv::_Rb_tree_node_base **v32; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v33; // ecx
  const vostok::variant<32> **v34; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::items_dictionary_cook,vostok::resources::queries_result &,survarium::items_dictionary *,unsigned int *>,boost::_bi::list4<boost::_bi::value<survarium::items_dictionary_cook *>,boost::arg<1>,boost::_bi::value<survarium::items_dictionary *>,boost::_bi::value<unsigned int *> > > v35; // [esp-1Ch] [ebp-29Ch]
  unsigned int v36; // [esp-18h] [ebp-298h]
  vostok::memory::base_allocator *v37; // [esp-10h] [ebp-290h]
  vostok::resources::query_result_for_cook *v38; // [esp-8h] [ebp-288h]
  const vostok::resources::request *v39[3]; // [esp+0h] [ebp-280h] BYREF
  survarium::items_dictionary *v40; // [esp+Ch] [ebp-274h]
  survarium::items_dictionary_cook *thisa; // [esp+10h] [ebp-270h]
  vostok::configs::binary_config_value v42; // [esp+44h] [ebp-23Ch]
  vostok::memory::doug_lea_allocator *allocator; // [esp+74h] [ebp-20Ch]
  void *_Where; // [esp+88h] [ebp-1F8h]
  vostok::memory::doug_lea_allocator *v45; // [esp+8Ch] [ebp-1F4h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::items_dictionary_cook,vostok::resources::queries_result &,survarium::items_dictionary *,unsigned int *>,boost::_bi::list4<boost::_bi::value<survarium::items_dictionary_cook *>,boost::arg<1>,boost::_bi::value<survarium::items_dictionary *>,boost::_bi::value<unsigned int *> > > result; // [esp+90h] [ebp-1F0h] BYREF
  void (__userpurge *f)(survarium::items_dictionary_cook *@<ecx>, float@<xmm0>, vostok::resources::queries_result *, vostok::configs::binary_config *, unsigned int *); // [esp+A8h] [ebp-1D8h]
  int f_4; // [esp+ACh] [ebp-1D4h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+B0h] [ebp-1D0h] BYREF
  stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *> > v50; // [esp+D4h] [ebp-1ACh] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v51; // [esp+E4h] [ebp-19Ch] BYREF
  survarium::items_dictionary *v52; // [esp+E8h] [ebp-198h]
  vostok::strings::detail::tuples STR_JOINA_tuples_unique_identifier; // [esp+ECh] [ebp-194h] BYREF
  survarium::dictionary_item item_dict; // [esp+120h] [ebp-160h] BYREF
  bool is_stack; // [esp+242h] [ebp-3Eh]
  bool is_premium; // [esp+243h] [ebp-3Dh]
  char *item_cfg_path; // [esp+244h] [ebp-3Ch]
  unsigned int item_dict_id; // [esp+248h] [ebp-38h]
  unsigned __int8 item_category_id; // [esp+24Fh] [ebp-31h]
  unsigned int i; // [esp+250h] [ebp-30h]
  unsigned int requests_count; // [esp+254h] [ebp-2Ch]
  vostok::resources::query_result_for_cook *parent; // [esp+258h] [ebp-28h]
  const vostok::configs::binary_config_value *items_it_e; // [esp+25Ch] [ebp-24h]
  unsigned int *item_dict_ids; // [esp+260h] [ebp-20h]
  survarium::items_dictionary *cooked_resource; // [esp+264h] [ebp-1Ch]
  vostok::vectora<vostok::resources::request> requests; // [esp+268h] [ebp-18h] BYREF
  const vostok::configs::binary_config_value *dict_cfg; // [esp+278h] [ebp-8h]
  const vostok::configs::binary_config_value *items_it; // [esp+27Ch] [ebp-4h]

  thisa = this;
  parent = vostok::resources::queries_result::get_parent_query((vostok::resources::queries_result *)this, (int)data);
  survarium::weapon_user_dead_state::finalize(v2);
  v45 = v3;
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v3, 0x128u);
  v52 = (survarium::items_dictionary *)operator new(0x128u, _Where);
  if ( v52 )
  {
    survarium::items_dictionary::items_dictionary(v52);
    v40 = v4;
  }
  else
  {
    v40 = 0;
  }
  cooked_resource = v40;
  v5 = vostok::resources::queries_result::operator[](data, 0);
  unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                         v6,
                         (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v5,
                         (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v51);
  v8 = vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
         (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)unmanaged_resource,
         (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v50._M_impl._M_end_of_storage._M_data);
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
    &cooked_resource->dict_config,
    v8);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&v50._M_impl._M_end_of_storage._M_data);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v51);
  v10 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
          v9,
          (int)&cooked_resource->dict_config);
  dict_cfg = vostok::configs::binary_config::get_root(v11, (int)v10);
  vostok::vectora<vostok::resources::request>::vectora<vostok::resources::request>(v12, &requests);
  v13 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  (vostok::configs::binary_config_value *)dict_cfg,
                                                  "items_dict");
  requests_count = vostok::configs::binary_config_value::size(v13);
  allocator = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  item_dict_ids = vostok::memory::new_array_helper<unsigned int>::call<vostok::memory::doug_lea_allocator>(
                    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                    requests_count);
  v14 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)dict_cfg, "items_dict");
  items_it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v14);
  v15 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  (vostok::configs::binary_config_value *)dict_cfg,
                                                  "items_dict");
  items_it_e = vostok::configs::binary_config_value::end(v15);
  i = 0;
  while ( items_it != items_it_e )
  {
    item_cfg_path = 0;
    HIBYTE(v50._M_impl._M_end_of_storage.m_allocator) = 1;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)items_it);
    if ( *v17 )
    {
      v42 = *vostok::configs::binary_config_value::operator[](
               (vostok::configs::binary_config_value *)items_it,
               "cfg_name");
      `vector constructor iterator'(
        (char *)&STR_JOINA_tuples_unique_identifier,
        8u,
        6,
        (void *(__thiscall *)(void *))vostok::render::lod_render_info::lod_render_info);
      STR_JOINA_tuples_unique_identifier.m_count = 2;
      vostok::strings::detail::tuples::helper<0>::add_string<char const *>(
        &STR_JOINA_tuples_unique_identifier,
        "resources/");
      vostok::strings::detail::tuples::helper<1>::add_string<vostok::configs::binary_config_value>(
        &STR_JOINA_tuples_unique_identifier,
        v42);
      v19 = alloca(vostok::strings::detail::tuples::size(v18, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
      v39[2] = (const vostok::resources::request *)v39;
      vostok::strings::detail::tuples::size(v20, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
      survarium::weapon_user_dead_state::finalize(v21);
      item_cfg_path = v22;
      vostok::strings::detail::tuples::concat(v22, &STR_JOINA_tuples_unique_identifier);
    }
    survarium::weapon_user_dead_state::finalize(v16);
    v50._M_impl._M_start = v23;
    v50._M_impl._M_finish = v24;
    stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *>>::push_back(&v50, v39[0]);
    v25 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)items_it, "dict_id");
    item_dict_id = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                   v26,
                                   (int)v25);
    v27 = vostok::configs::binary_config_value::operator[](
            (vostok::configs::binary_config_value *)items_it,
            "item_category");
    item_category_id = vostok::configs::binary_config_value::operator unsigned char(v28, (int)v27);
    v29 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)items_it,
                                                    "is_premium");
    is_premium = vostok::configs::binary_config_value::operator bool(v29);
    v30 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)items_it,
                                                    "is_stack");
    is_stack = vostok::configs::binary_config_value::operator bool(v30);
    item_dict_ids[i] = item_dict_id;
    vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&item_dict.item_cfg);
    vostok::fixed_string<260>::fixed_string<260>(&item_dict.item_cfg_name);
    item_dict.item_id = item_dict_id;
    item_dict.item_category = item_category_id;
    v31 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)items_it, "cfg_name");
    vostok::fixed_string<260>::operator=<vostok::configs::binary_config_value>(&item_dict.item_cfg_name, v31);
    item_dict.is_premium = is_premium;
    item_dict.is_stack = is_stack;
    v32 = stlp_std::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::dictionary_item>>>::operator[]<unsigned int>(
            &cooked_resource->m_items_dict,
            &item_dict.item_id);
    survarium::dictionary_item::operator=((survarium::dictionary_item *)v32, &item_dict);
    survarium::dictionary_item::~dictionary_item(&item_dict);
    ++items_it;
    ++i;
  }
  f = survarium::items_dictionary_cook::on_subresources_loaded;
  f_4 = 0;
  v35 = *boost::bind<void,survarium::items_dictionary_cook,vostok::resources::queries_result &,survarium::items_dictionary *,unsigned int *,survarium::items_dictionary_cook *,boost::arg<1>,survarium::items_dictionary *,unsigned int *>(
           &result,
           (void (__thiscall *__ptr64)(survarium::items_dictionary_cook *, vostok::resources::queries_result *, survarium::items_dictionary *, unsigned int *))(unsigned int)survarium::items_dictionary_cook::on_subresources_loaded,
           thisa,
           1_163,
           cooked_resource,
           item_dict_ids);
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    &callback,
    v35,
    0);
  v38 = parent;
  v37 = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  v36 = vostok::vectora<vostok::resources::request>::size((survarium::vector<vostok::resources::request> *)&requests);
  v34 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v33, (int)&requests);
  vostok::resources::query_resources(
    (const vostok::resources::request *)v34,
    v36,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    v37,
    0,
    v38,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::~_Impl_vector<void const *,vostok::vectora_allocator<void const *>>(&requests);
}
