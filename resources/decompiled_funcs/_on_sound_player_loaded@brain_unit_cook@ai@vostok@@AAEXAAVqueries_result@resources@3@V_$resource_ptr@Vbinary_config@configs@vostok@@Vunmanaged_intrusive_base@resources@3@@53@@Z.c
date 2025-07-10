// local variable allocation has failed, the output may be wrong!
void __thiscall vostok::ai::brain_unit_cook::on_sound_player_loaded(
        vostok::ai::brain_unit_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config)
{
  survarium::game_camera *v3; // ecx
  vostok::resources::query_result *v4; // eax
  vostok::resources::query_result_for_user *v5; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  const vostok::variant<32> **v7; // eax
  vostok::configs::binary_config *v8; // ecx
  survarium::vector<vostok::resources::request> *v9; // ecx
  vostok::resources::query_result_for_cook *v10; // ecx
  int v11; // ecx
  survarium::game_camera *v12; // ecx
  survarium::game_camera *v13; // ecx
  _BYTE *v14; // eax
  const vostok::configs::binary_config_value *v15; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v16; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v17; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v18; // eax
  vostok::variant<32> *v19; // ecx
  vostok::resources::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base> v20; // [esp+290h] [ebp-F0h] BYREF
  vostok::ai::navigation_environment *v21; // [esp+294h] [ebp-ECh]
  vostok::ai::ai_world *v22; // [esp+298h] [ebp-E8h]
  vostok::ai::brain_unit_cook *thisa; // [esp+29Ch] [ebp-E4h]
  boost::function1<void,vostok::resources::queries_result &> v24; // [esp+2A8h] [ebp-D8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_material_manager_cook,vostok::resources::queries_result &,survarium::vector<survarium::game_material_manager_cook::query_ext_data> *>,boost::_bi::list3<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>,boost::_bi::value<survarium::vector<survarium::game_material_manager_cook::query_ext_data> *> > > v25; // [esp+2C8h] [ebp-B8h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > result; // [esp+2D8h] [ebp-A8h] BYREF
  void (__thiscall *f)(vostok::ai::brain_unit_cook *, vostok::resources::queries_result *, vostok::ai::brain_unit *const); // [esp+2E8h] [ebp-98h]
  int f_4; // [esp+2ECh] [ebp-94h]
  vostok::variant<32> v29; // [esp+2F0h] [ebp-90h] BYREF
  vostok::ai::behaviour_cook_params v30; // [esp+320h] [ebp-60h] BYREF
  vostok::math::float4x4 *a3; // [esp+324h] [ebp-5Ch]
  vostok::math::float4x4 *v32; // [esp+328h] [ebp-58h]
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v33; // [esp+32Ch] [ebp-54h]
  vostok::resources::unmanaged_intrusive_base *v34; // [esp+330h] [ebp-50h]
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v35; // [esp+334h] [ebp-4Ch]
  vostok::ai::navigation_environment v36; // [esp+33Bh] [ebp-45h] BYREF
  vostok::ai::brain_unit *v37; // [esp+33Ch] [ebp-44h]
  void *_Where; // [esp+340h] [ebp-40h]
  vostok::memory::doug_lea_allocator *v39; // [esp+344h] [ebp-3Ch]
  char *request_path; // [esp+348h] [ebp-38h]
  char v41; // [esp+34Dh] [ebp-33h]
  char v42; // [esp+34Eh] [ebp-32h]
  unsigned __int8 v43; // [esp+34Fh] [ebp-31h]
  vostok::variant<32> *v44; // [esp+350h] [ebp-30h]
  vostok::ai::brain_unit_cook_params out_value; // [esp+354h] [ebp-2Ch] BYREF
  vostok::configs::binary_config_value *brain_unit_options; // [esp+360h] [ebp-20h]
  vostok::resources::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base> v47; // [esp+364h] [ebp-1Ch] BYREF
  vostok::ai::sound_player *object; // [esp+368h] [ebp-18h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // [esp+36Ch] [ebp-14h]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v50; // [esp+370h] [ebp-10h] BYREF
  char v51; // [esp+377h] [ebp-9h]
  vostok::resources::query_result_for_cook *parent_query; // [esp+378h] [ebp-8h]
  vostok::sound::sound_environment_cook *a1; // [esp+37Ch] [ebp-4h]

  a1 = (vostok::sound::sound_environment_cook *)this;
  parent_query = vostok::resources::queries_result::get_parent_query(
                   (vostok::resources::queries_result *)this,
                   (int)data);
  if ( vostok::resources::queries_result::is_successful(data) )
  {
    v4 = vostok::resources::queries_result::operator[](data, 0);
    unmanaged_resource = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::query_result_for_user::get_unmanaged_resource(v5, (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v4, (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v50);
    object = (vostok::ai::sound_player *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(unmanaged_resource);
    vostok::resources::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base>(
      &v47,
      object);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v50);
    v7 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v6, (int)&config);
    brain_unit_options = (vostok::configs::binary_config_value *)vostok::configs::binary_config::get_root(v8, (int)v7);
    stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_Impl_vector<void *,survarium::std_allocator<void *>>(
      v9,
      &out_value);
    v44 = vostok::resources::query_result_for_cook::user_data(v10, (int)parent_query);
    v43 = vostok::variant<32>::try_get<vostok::ai::brain_unit_cook_params>(v44, &out_value, v11);
    v42 = 0;
    survarium::weapon_user_dead_state::finalize(v12);
    if ( *v14 )
    {
      thisa = (vostok::ai::brain_unit_cook *)v43;
      v22 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v43);
    }
    v41 = 0;
    survarium::weapon_user_dead_state::finalize(v13);
    v15 = vostok::configs::binary_config_value::operator[](brain_unit_options, "default_behaviour");
    request_path = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                             v16,
                             (int)v15);
    v39 = vostok::ai::g_allocator;
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(vostok::ai::g_allocator, 0x400u);
    v37 = (vostok::ai::brain_unit *)operator new(0x400u, _Where);
    if ( v37 )
    {
      thisa = (vostok::ai::brain_unit_cook *)brain_unit_options;
      v22 = (vostok::ai::ai_world *)a1[1].__vftable;
      v21 = &v36;
      v35 = (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20;
      v20.m_object = 0;
      if ( v47.m_object )
      {
        vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v35);
        v35->m_object = (survarium::weapon_user_animations_container *)v47.m_object;
        if ( v35->m_object )
        {
          v34 = &v35->m_object->vostok::resources::unmanaged_intrusive_base;
          vostok::threading::interlocked_increment(v34);
        }
      }
      vostok::ai::brain_unit::brain_unit(
        v37,
        out_value.npc,
        v20,
        v21,
        v22,
        (vostok::configs::binary_config_value *)thisa);
      v33 = v18;
      v17 = v18;
      v32 = (vostok::math::float4x4 *)v18;
    }
    else
    {
      v32 = 0;
    }
    a3 = v32;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v17, &v30);
    vostok::variant<32>::variant<32>(&v29);
    vostok::variant<32>::set<vostok::ai::behaviour_cook_params>(v19, (vostok::ai::behaviour_cook_params *)&v29, &v30);
    f = vostok::ai::brain_unit_cook::on_default_behaviour_loaded;
    f_4 = 0;
    v25 = *boost::bind<void,vostok::ai::brain_unit_cook,vostok::resources::queries_result &,vostok::ai::brain_unit *,vostok::ai::brain_unit_cook *,boost::arg<1>,vostok::ai::brain_unit *>(
             (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_material_manager_cook,vostok::resources::queries_result &,survarium::vector<survarium::game_material_manager_cook::query_ext_data> *>,boost::_bi::list3<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>,boost::_bi::value<survarium::vector<survarium::game_material_manager_cook::query_ext_data> *> > > *)&result,
             (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *, vostok::math::float4x4 *))(unsigned int)vostok::ai::brain_unit_cook::on_default_behaviour_loaded,
             (survarium::game_material_manager_cook *)a1,
             1_251,
             a3);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v25.l_.a1_.t_,
      &v24);
    boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::ai::brain_unit_cook,vostok::resources::queries_result &,vostok::ai::brain_unit *>,boost::_bi::list3<boost::_bi::value<vostok::ai::brain_unit_cook *>,boost::arg<1>,boost::_bi::value<vostok::ai::brain_unit *>>>>(
      &v24,
      (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::ai::brain_unit_cook,vostok::resources::queries_result &,vostok::ai::brain_unit *>,boost::_bi::list3<boost::_bi::value<vostok::ai::brain_unit_cook *>,boost::arg<1>,boost::_bi::value<vostok::ai::brain_unit *> > >)v25);
    vostok::resources::query_resource(
      request_path,
      behaviour_class,
      (boost::function4<void,unsigned int,float,float,char const *> *)&v24,
      vostok::ai::g_allocator,
      &v29,
      parent_query,
      assert_on_fail_true);
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v24);
    vostok::variant<32>::~variant<32>(&v29);
    vostok::ai::brain_unit_cook_params::~brain_unit_cook_params((vostok::memory::detail::call_destructor_predicate *)&out_value);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v47);
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&config);
  }
  else
  {
    v51 = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    vostok::resources::query_result_for_cook::finish_query(parent_query, result_error, assert_on_fail_true);
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&config);
  }
}
