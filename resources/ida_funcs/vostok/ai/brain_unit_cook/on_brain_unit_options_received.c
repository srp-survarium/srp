void __thiscall vostok::ai::brain_unit_cook::on_brain_unit_options_received(
        vostok::ai::brain_unit_cook *this,
        vostok::resources::queries_result *data)
{
  survarium::game_camera *v2; // ecx
  vostok::resources::query_result *v3; // eax
  vostok::resources::query_result_for_user *v4; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  vostok::configs::binary_config *v6; // ecx
  const char *requested_path; // eax
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> v8; // [esp-18h] [ebp-74h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::ai::brain_unit_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list3<boost::_bi::value<vostok::ai::brain_unit_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > v9; // [esp-14h] [ebp-70h] BYREF
  assert_on_fail_bool v10; // [esp-4h] [ebp-60h]
  vostok::ai::brain_unit_cook *thisa; // [esp+4h] [ebp-58h]
  void (__thiscall *__ptr64 f)(survarium::booby_trap_core_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>); // [esp+1Ch] [ebp-40h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+2Ch] [ebp-30h] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v14; // [esp+4Ch] [ebp-10h] BYREF
  char v15; // [esp+53h] [ebp-9h]
  vostok::resources::query_result_for_cook *parent; // [esp+54h] [ebp-8h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config; // [esp+58h] [ebp-4h] BYREF

  thisa = this;
  parent = vostok::resources::queries_result::get_parent_query((vostok::resources::queries_result *)this, (int)data);
  if ( vostok::resources::queries_result::is_successful(data) )
  {
    v3 = vostok::resources::queries_result::operator[](data, 0);
    unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                           v4,
                           (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v3,
                           (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v14);
    vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)unmanaged_resource,
      &config);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v14);
    LODWORD(f) = vostok::ai::brain_unit_cook::on_sound_player_loaded;
    HIDWORD(f) = 0;
    v10 = assert_on_fail_false;
    v8.m_object = v6;
    boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      &v8,
      &config);
    boost::bind<void,vostok::ai::brain_unit_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::ai::brain_unit_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      &v9,
      f,
      (survarium::booby_trap_core_cook *)thisa,
      1_251,
      v8);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      &callback,
      v9,
      v10);
    v10 = assert_on_fail_true;
    v9.l_.a3_.t_.m_object = (vostok::configs::binary_config *)parent;
    v9.l_.a1_.t_ = 0;
    HIDWORD(v9.f_.f_) = vostok::ai::g_allocator;
    LODWORD(v9.f_.f_) = &callback;
    v8.m_object = (vostok::configs::binary_config *)91;
    requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
    vostok::resources::query_resource(
      requested_path,
      (vostok::resources::class_id_enum)v8.m_object,
      (boost::function4<void,unsigned int,float,float,char const *> *)v9.f_.f_,
      (vostok::memory::base_allocator *)HIDWORD(v9.f_.f_),
      (const vostok::variant<32> *)v9.l_.a1_.t_,
      (vostok::resources::query_result_for_cook *)v9.l_.a3_.t_.m_object,
      v10);
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&config);
  }
  else
  {
    v15 = 0;
    survarium::weapon_user_dead_state::finalize(v2);
    vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
  }
}
