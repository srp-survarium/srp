void __thiscall survarium::weapon_user_animations_container_cook::on_config_loaded(
        survarium::weapon_user_animations_container_cook *this,
        vostok::resources::queries_result *data)
{
  survarium::game_camera *v2; // ecx
  vostok::resources::queries_result *v3; // ecx
  vostok::resources::query_result_for_cook *v4; // eax
  void *v5; // esp
  vostok::buffer_vector<vostok::resources::request> *v6; // eax
  vostok::resources::query_result *v7; // eax
  vostok::resources::query_result_for_user *v8; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v10; // ecx
  const vostok::variant<32> **v11; // eax
  vostok::configs::binary_config *v12; // ecx
  vostok::configs::binary_config_value *v13; // eax
  vostok::configs::binary_config_value *v14; // eax
  vostok::configs::binary_config_value *v15; // eax
  vostok::configs::binary_config_value *v16; // eax
  vostok::configs::binary_config_value *v17; // eax
  vostok::configs::binary_config_value *v18; // eax
  vostok::configs::binary_config_value *v19; // eax
  vostok::configs::binary_config_value *v20; // eax
  vostok::configs::binary_config_value *v21; // eax
  vostok::configs::binary_config_value *v22; // eax
  vostok::configs::binary_config_value *v23; // eax
  vostok::configs::binary_config_value *v24; // eax
  vostok::configs::binary_config_value *v25; // eax
  vostok::configs::binary_config_value *v26; // eax
  vostok::configs::binary_config_value *v27; // eax
  vostok::configs::binary_config_value *v28; // eax
  vostok::configs::binary_config_value *v29; // eax
  vostok::configs::binary_config_value *v30; // eax
  vostok::configs::binary_config_value *v31; // eax
  vostok::configs::binary_config_value *v32; // eax
  survarium::game_camera *v33; // ecx
  vostok::resources::queries_result *v34; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v35; // ecx
  const vostok::variant<32> **v36; // eax
  vostok::buffer_vector<vostok::resources::request> *v37; // ecx
  unsigned int v38; // [esp-EB8h] [ebp-1030h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v39; // [esp-EB4h] [ebp-102Ch]
  vostok::memory::base_allocator *v40; // [esp-EB0h] [ebp-1028h]
  vostok::resources::query_result_for_cook *parent_query; // [esp-EA8h] [ebp-1020h]
  unsigned int v42[938]; // [esp-EA0h] [ebp-1018h] BYREF
  survarium::weapon_user_animations_container_cook *thisa; // [esp+8h] [ebp-170h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+120h] [ebp-58h] BYREF
  void (__thiscall *f)(survarium::weapon_user_animations_container_cook *, vostok::resources::queries_result *); // [esp+130h] [ebp-48h]
  int f_4; // [esp+134h] [ebp-44h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+138h] [ebp-40h] BYREF
  char v48; // [esp+15Fh] [ebp-19h]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v49; // [esp+160h] [ebp-18h] BYREF
  char v50; // [esp+167h] [ebp-11h]
  const vostok::configs::binary_config_value *root; // [esp+168h] [ebp-10h]
  vostok::buffer_vector<vostok::resources::request> requests; // [esp+16Ch] [ebp-Ch] BYREF
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config; // [esp+174h] [ebp-4h] BYREF

  thisa = this;
  if ( vostok::resources::queries_result::is_successful(data) )
  {
    v5 = alloca(3744);
    v42[937] = (unsigned int)v42;
    survarium::weapon_user_dead_state::finalize(v2);
    vostok::buffer_vector<vostok::resources::request>::buffer_vector<vostok::resources::request>(
      v6,
      (vostok::buffer_vector<vostok::resources::request> **)&requests,
      0,
      v42[0],
      v42[1]);
    v7 = vostok::resources::queries_result::operator[](data, 0);
    unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                           v8,
                           (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v7,
                           (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v49);
    vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)unmanaged_resource,
      &config);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v49);
    v11 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v10, (int)&config);
    root = vostok::configs::binary_config::get_root(v12, (int)v11);
    v13 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "stand_hud");
    survarium::create_requests_for_animations(v13, 0x1Bu, &requests);
    v14 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "stand");
    survarium::create_requests_for_animations(v14, 0x1Bu, &requests);
    v15 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "stand_hands_only_hud");
    survarium::create_requests_for_animations(v15, 6u, &requests);
    v16 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "stand_hands_only");
    survarium::create_requests_for_animations(v16, 6u, &requests);
    v17 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "aimed_stand_hud");
    survarium::create_requests_for_animations(v17, 0x1Bu, &requests);
    v18 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "aimed_stand");
    survarium::create_requests_for_animations(v18, 0x1Bu, &requests);
    v19 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "aimed_stand_hands_only_hud");
    survarium::create_requests_for_animations(v19, 6u, &requests);
    v20 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "aimed_stand_hands_only");
    survarium::create_requests_for_animations(v20, 6u, &requests);
    v21 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "crouch_hud");
    survarium::create_requests_for_animations(v21, 0x1Bu, &requests);
    v22 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "crouch");
    survarium::create_requests_for_animations(v22, 0x1Bu, &requests);
    v23 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "crouch_hands_only_hud");
    survarium::create_requests_for_animations(v23, 6u, &requests);
    v24 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "crouch_hands_only");
    survarium::create_requests_for_animations(v24, 6u, &requests);
    v25 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "aimed_crouch_hud");
    survarium::create_requests_for_animations(v25, 0x1Bu, &requests);
    v26 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "aimed_crouch");
    survarium::create_requests_for_animations(v26, 0x1Bu, &requests);
    v27 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "aimed_crouch_hands_only_hud");
    survarium::create_requests_for_animations(v27, 6u, &requests);
    v28 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "aimed_crouch_hands_only");
    survarium::create_requests_for_animations(v28, 6u, &requests);
    v29 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "sprint_hud");
    survarium::create_requests_for_animations(v29, 2u, &requests);
    v30 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "sprint");
    survarium::create_requests_for_animations(v30, 2u, &requests);
    v31 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "jump_hud");
    survarium::create_requests_for_animations(v31, 0x64u, &requests);
    v32 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)root,
                                                    "jump");
    survarium::create_requests_for_animations(v32, 0x64u, &requests);
    v48 = 0;
    survarium::weapon_user_dead_state::finalize(v33);
    f = survarium::weapon_user_animations_container_cook::on_animations_loaded;
    f_4 = 0;
    v39 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
             (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
             (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_user_animations_container_cook::on_animations_loaded,
             (survarium::weapon_core_animation_end_aware_state *)thisa);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      &callback,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_user_animations_container_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_user_animations_container_cook *>,boost::arg<1> > >)v39,
      0);
    parent_query = vostok::resources::queries_result::get_parent_query(v34, (int)data);
    v40 = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
    v38 = vostok::vectora<vostok::resources::request>::size((survarium::vector<vostok::resources::request> *)&requests);
    v36 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v35, (int)&requests);
    vostok::resources::query_resources(
      (const vostok::resources::request *)v36,
      v38,
      (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
      v40,
      0,
      parent_query,
      assert_on_fail_true);
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&config);
    vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v37, &requests);
  }
  else
  {
    v50 = 0;
    survarium::weapon_user_dead_state::finalize(v2);
    v4 = vostok::resources::queries_result::get_parent_query(v3, (int)data);
    vostok::resources::query_result_for_cook::finish_query(v4, result_error, assert_on_fail_true);
  }
}
