void __thiscall vostok::sound::sound_collection_cook::translate_query(
        vostok::sound::sound_collection_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::configs::binary_config *v2; // ecx
  const char *requested_path; // eax
  vostok::memory::base_allocator *v4; // eax
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> v5; // [esp-Ch] [ebp-1C4h] BYREF
  const vostok::configs::binary_config_value *val; // [esp-8h] [ebp-1C0h]
  char *v7; // [esp-4h] [ebp-1BCh]
  vostok::sound::sound_collection_cook *thisa; // [esp+0h] [ebp-1B8h]
  char *request_path; // [esp+Ch] [ebp-1ACh]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v10; // [esp+10h] [ebp-1A8h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *v11; // [esp+40h] [ebp-178h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *p_cfg_ptr; // [esp+4Ch] [ebp-16Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+50h] [ebp-168h] BYREF
  void (__thiscall *f)(vostok::sound::sound_collection_cook *, vostok::resources::queries_result *); // [esp+60h] [ebp-158h]
  int f_4; // [esp+64h] [ebp-154h]
  boost::function1<void,vostok::resources::queries_result &> v16; // [esp+68h] [ebp-150h] BYREF
  vostok::fs_new::virtual_path_string config_path; // [esp+90h] [ebp-128h] BYREF
  vostok::sound::sound_collection_cook_user_data data; // [esp+1ACh] [ebp-Ch] BYREF
  vostok::variant<32> *ud; // [esp+1B4h] [ebp-4h]

  thisa = this;
  ud = parent->m_user_data;
  if ( ud )
  {
    p_cfg_ptr = &data.cfg_ptr;
    data.cfg_ptr.m_object = 0;
    vostok::variant<32>::try_get<vostok::sound::sound_collection_cook_user_data>(ud, &data);
    vostok::resources::query_result_for_cook::clear_user_data(parent);
    v7 = (char *)parent;
    val = data.val;
    v5.m_object = v2;
    v11 = &v5;
    boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      &v5,
      &data.cfg_ptr);
    vostok::sound::sound_collection_cook::request_items(
      thisa,
      v5,
      val,
      (vostok::resources::query_result_for_cook *const)v7);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&data.cfg_ptr);
  }
  else
  {
    vostok::fixed_string<260>::fixed_string<260>(&config_path.m_string);
    config_path.m_separator = 47;
    v7 = (char *)vostok::sound::collection_extention;
    requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
    vostok::fs_new::path_string_impl::assignf(
      &config_path,
      "%s%s%s",
      "resources/sounds/collections/",
      requested_path,
      v7);
    f = vostok::sound::sound_collection_cook::collection_config_loaded;
    f_4 = 0;
    v7 = (char *)(unsigned __int8)1_8;
    v10 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
             (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
             (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::sound::sound_collection_cook::collection_config_loaded,
             (survarium::weapon_core_animation_end_aware_state *)thisa);
    v16.vtable = 0;
    boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_collection_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_collection_cook *>,boost::arg<1>>>>(
      &v16,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_collection_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_collection_cook *>,boost::arg<1> > >)v10);
    request_path = config_path.m_string.m_begin;
    v4 = vostok::resources::unmanaged_allocator();
    vostok::resources::query_resource(
      request_path,
      binary_config_class_impl,
      (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&v16,
      v4,
      0,
      parent,
      assert_on_fail_true);
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v16);
  }
}
