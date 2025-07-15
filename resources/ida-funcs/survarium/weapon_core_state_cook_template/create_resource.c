void __thiscall survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state>::create_resource(
        survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state> *this,
        vostok::resources::query_result_for_cook *parent,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::variant<32> *m_user_data; // esi
  vostok::resources::query_result_for_cook *v5; // ecx
  int i; // esi
  char *pointer; // edx
  vostok::resources::request *m_end; // eax
  vostok::resources::query_result_for_cook *v9; // ecx
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::effect_cook,vostok::resources::query_result_for_cook *,vostok::render::res_effect *,vostok::render::effect_compile_data *,vostok::resources::queries_result &>,boost::_bi::list5<boost::_bi::value<vostok::render::effect_cook *>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::render::res_effect *>,boost::_bi::value<vostok::render::effect_compile_data *>,boost::arg<1> > > v11; // [esp-10h] [ebp-C0h]
  const survarium::weapon_state_creation_params *params; // [esp+10h] [ebp-A0h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+18h] [ebp-98h] BYREF
  vostok::configs::binary_config_value cfg; // [esp+38h] [ebp-78h] BYREF
  void (__thiscall *v16)(survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state> *, vostok::resources::queries_result *, vostok::mutable_buffer, const survarium::weapon_state_creation_params *); // [esp+54h] [ebp-5Ch]
  __int128 v17; // [esp+58h] [ebp-58h]
  vostok::fixed_vector<vostok::resources::request,8> requests; // [esp+68h] [ebp-48h] BYREF

  params = (const survarium::weapon_state_creation_params *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&raw_file_data);
  cfg.data.max_storage = 0;
  vostok::platform_pointer_selector<char const,1>::helper::helper(&cfg.id, 0);
  m_user_data = parent->m_user_data;
  cfg.id_crc = 0;
  cfg.type = 0;
  cfg.count = 0;
  if ( vostok::variant<32>::try_get<vostok::configs::binary_config_value>(m_user_data, &cfg, 0) )
  {
    requests.m_begin = (vostok::resources::request *)requests.m_buffer;
    requests.m_end = (vostok::resources::request *)requests.m_buffer;
    for ( i = 0; i != 192; i += 24 )
    {
      pointer = (char *)vostok::configs::binary_config_value::operator[](&cfg, "animations")->data.pointer;
      m_end = requests.m_end;
      if ( requests.m_end )
      {
        requests.m_end->path = *(const char **)&pointer[i];
        m_end->id = animation_class;
      }
      ++requests.m_end;
    }
    vostok::configs::binary_config_value::value_exists(&cfg, "user_animations");
    (&callback.vtable)[1] = (boost::detail::function::vtable_base *)in_out_unmanaged_resource_buffer.m_data;
    *(_QWORD *)&v17 = __PAIR64__((unsigned int)in_out_unmanaged_resource_buffer.m_data, (unsigned int)this);
    *(_QWORD *)&callback.functor.obj_ptr = __PAIR64__((unsigned int)params, in_out_unmanaged_resource_buffer.m_size);
    *((_QWORD *)&v17 + 1) = __PAIR64__((unsigned int)params, in_out_unmanaged_resource_buffer.m_size);
    v16 = survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state>::on_subresources_ready;
    v11.f_.f_ = (void (__thiscall *)(vostok::render::effect_cook *, vostok::resources::query_result_for_cook *, vostok::render::res_effect *, vostok::render::effect_compile_data *, vostok::resources::queries_result *))this;
    v11.l_.boost::_bi::storage2<boost::_bi::value<vostok::render::effect_cook *>,boost::_bi::value<vostok::resources::query_result_for_cook *> > = *(boost::_bi::storage2<boost::_bi::value<vostok::render::effect_cook *>,boost::_bi::value<vostok::resources::query_result_for_cook *> > *)((char *)&v17 + 4);
    callback.vtable = 0;
    v11.l_.a3_.t_ = (vostok::render::res_effect *)params;
    if ( boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_aimed_idle_state>,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_aimed_idle_state> *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *>>>>(
           (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state>::on_subresources_ready,
           v11,
           &callback.functor) )
    {
      callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state>,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state> *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *>>>>'::`2'::stored_vtable
                                                               + 1);
    }
    else
    {
      callback.vtable = 0;
    }
    vostok::resources::query_resources(
      requests.m_begin,
      requests.m_end - requests.m_begin,
      &callback,
      (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
      0,
      parent,
      assert_on_fail_true);
    if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
    {
      v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v10 )
        v10(&callback.functor, &callback.functor, 2);
    }
    vostok::resources::query_result_for_cook::finish_query_impl(
      v9,
      result_postponed,
      assert_on_fail_true,
      error_type_unset);
  }
  else
  {
    __debugbreak();
    vostok::resources::query_result_for_cook::finish_query_impl(
      v5,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
  }
}


void __thiscall survarium::weapon_core_state_cook_template<survarium::weapon_core_aimed_state>::create_resource(
        survarium::weapon_core_state_cook_template<survarium::weapon_core_aimed_state> *this,
        vostok::resources::query_result_for_cook *parent,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::variant<32> *m_user_data; // esi
  vostok::resources::query_result_for_cook *v5; // ecx
  int i; // esi
  char *pointer; // edx
  vostok::resources::request *m_end; // eax
  vostok::resources::query_result_for_cook *v9; // ecx
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::effect_cook,vostok::resources::query_result_for_cook *,vostok::render::res_effect *,vostok::render::effect_compile_data *,vostok::resources::queries_result &>,boost::_bi::list5<boost::_bi::value<vostok::render::effect_cook *>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::render::res_effect *>,boost::_bi::value<vostok::render::effect_compile_data *>,boost::arg<1> > > v11; // [esp-10h] [ebp-A0h]
  const survarium::weapon_state_creation_params *params; // [esp+14h] [ebp-7Ch]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+18h] [ebp-78h] BYREF
  void (__thiscall *v15)(survarium::weapon_core_state_cook_template<survarium::weapon_core_aimed_state> *, vostok::resources::queries_result *, vostok::mutable_buffer, const survarium::weapon_state_creation_params *); // [esp+3Ch] [ebp-54h]
  __int128 v16; // [esp+40h] [ebp-50h]
  vostok::configs::binary_config_value cfg; // [esp+50h] [ebp-40h] BYREF
  vostok::fixed_vector<vostok::resources::request,4> requests; // [esp+68h] [ebp-28h] BYREF

  params = (const survarium::weapon_state_creation_params *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&raw_file_data);
  cfg.data.max_storage = 0;
  vostok::platform_pointer_selector<char const,1>::helper::helper(&cfg.id, 0);
  m_user_data = parent->m_user_data;
  cfg.id_crc = 0;
  cfg.type = 0;
  cfg.count = 0;
  if ( vostok::variant<32>::try_get<vostok::configs::binary_config_value>(m_user_data, &cfg, 0) )
  {
    requests.m_begin = (vostok::resources::request *)requests.m_buffer;
    requests.m_end = (vostok::resources::request *)requests.m_buffer;
    for ( i = 0; i != 96; i += 24 )
    {
      pointer = (char *)vostok::configs::binary_config_value::operator[](&cfg, "animations")->data.pointer;
      m_end = requests.m_end;
      if ( requests.m_end )
      {
        requests.m_end->path = *(const char **)&pointer[i];
        m_end->id = animation_class;
      }
      ++requests.m_end;
    }
    vostok::configs::binary_config_value::value_exists(&cfg, "user_animations");
    (&callback.vtable)[1] = (boost::detail::function::vtable_base *)in_out_unmanaged_resource_buffer.m_data;
    *(_QWORD *)&v16 = __PAIR64__((unsigned int)in_out_unmanaged_resource_buffer.m_data, (unsigned int)this);
    *(_QWORD *)&callback.functor.obj_ptr = __PAIR64__((unsigned int)params, in_out_unmanaged_resource_buffer.m_size);
    *((_QWORD *)&v16 + 1) = __PAIR64__((unsigned int)params, in_out_unmanaged_resource_buffer.m_size);
    v15 = survarium::weapon_core_state_cook_template<survarium::weapon_core_aimed_state>::on_subresources_ready;
    v11.f_.f_ = (void (__thiscall *)(vostok::render::effect_cook *, vostok::resources::query_result_for_cook *, vostok::render::res_effect *, vostok::render::effect_compile_data *, vostok::resources::queries_result *))this;
    v11.l_.boost::_bi::storage2<boost::_bi::value<vostok::render::effect_cook *>,boost::_bi::value<vostok::resources::query_result_for_cook *> > = *(boost::_bi::storage2<boost::_bi::value<vostok::render::effect_cook *>,boost::_bi::value<vostok::resources::query_result_for_cook *> > *)((char *)&v16 + 4);
    callback.vtable = 0;
    v11.l_.a3_.t_ = (vostok::render::res_effect *)params;
    if ( boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_aimed_idle_state>,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_aimed_idle_state> *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *>>>>(
           (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)survarium::weapon_core_state_cook_template<survarium::weapon_core_aimed_state>::on_subresources_ready,
           v11,
           &callback.functor) )
    {
      callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_state_cook_template<survarium::weapon_core_aimed_state>,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_state_cook_template<survarium::weapon_core_aimed_state> *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *>>>>'::`2'::stored_vtable
                                                               + 1);
    }
    else
    {
      callback.vtable = 0;
    }
    vostok::resources::query_resources(
      requests.m_begin,
      requests.m_end - requests.m_begin,
      &callback,
      (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
      0,
      parent,
      assert_on_fail_true);
    if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
    {
      v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v10 )
        v10(&callback.functor, &callback.functor, 2);
    }
    vostok::resources::query_result_for_cook::finish_query_impl(
      v9,
      result_postponed,
      assert_on_fail_true,
      error_type_unset);
  }
  else
  {
    __debugbreak();
    vostok::resources::query_result_for_cook::finish_query_impl(
      v5,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
  }
}


void __thiscall survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state>::create_resource(
        survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state> *this,
        vostok::resources::query_result_for_cook *parent,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::variant<32> *m_user_data; // esi
  vostok::resources::query_result_for_cook *v5; // ecx
  int i; // esi
  char *pointer; // edx
  vostok::resources::request *m_end; // eax
  vostok::resources::query_result_for_cook *v9; // ecx
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::effect_cook,vostok::resources::query_result_for_cook *,vostok::render::res_effect *,vostok::render::effect_compile_data *,vostok::resources::queries_result &>,boost::_bi::list5<boost::_bi::value<vostok::render::effect_cook *>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::render::res_effect *>,boost::_bi::value<vostok::render::effect_compile_data *>,boost::arg<1> > > v11; // [esp-10h] [ebp-A0h]
  const survarium::weapon_state_creation_params *params; // [esp+14h] [ebp-7Ch]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+18h] [ebp-78h] BYREF
  void (__thiscall *v15)(survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state> *, vostok::resources::queries_result *, vostok::mutable_buffer, const survarium::weapon_state_creation_params *); // [esp+3Ch] [ebp-54h]
  __int128 v16; // [esp+40h] [ebp-50h]
  vostok::configs::binary_config_value cfg; // [esp+50h] [ebp-40h] BYREF
  vostok::fixed_vector<vostok::resources::request,4> requests; // [esp+68h] [ebp-28h] BYREF

  params = (const survarium::weapon_state_creation_params *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&raw_file_data);
  cfg.data.max_storage = 0;
  vostok::platform_pointer_selector<char const,1>::helper::helper(&cfg.id, 0);
  m_user_data = parent->m_user_data;
  cfg.id_crc = 0;
  cfg.type = 0;
  cfg.count = 0;
  if ( vostok::variant<32>::try_get<vostok::configs::binary_config_value>(m_user_data, &cfg, 0) )
  {
    requests.m_begin = (vostok::resources::request *)requests.m_buffer;
    requests.m_end = (vostok::resources::request *)requests.m_buffer;
    for ( i = 0; i != 96; i += 24 )
    {
      pointer = (char *)vostok::configs::binary_config_value::operator[](&cfg, "animations")->data.pointer;
      m_end = requests.m_end;
      if ( requests.m_end )
      {
        requests.m_end->path = *(const char **)&pointer[i];
        m_end->id = animation_class;
      }
      ++requests.m_end;
    }
    vostok::configs::binary_config_value::value_exists(&cfg, "user_animations");
    (&callback.vtable)[1] = (boost::detail::function::vtable_base *)in_out_unmanaged_resource_buffer.m_data;
    *(_QWORD *)&v16 = __PAIR64__((unsigned int)in_out_unmanaged_resource_buffer.m_data, (unsigned int)this);
    *(_QWORD *)&callback.functor.obj_ptr = __PAIR64__((unsigned int)params, in_out_unmanaged_resource_buffer.m_size);
    *((_QWORD *)&v16 + 1) = __PAIR64__((unsigned int)params, in_out_unmanaged_resource_buffer.m_size);
    v15 = survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state>::on_subresources_ready;
    v11.f_.f_ = (void (__thiscall *)(vostok::render::effect_cook *, vostok::resources::query_result_for_cook *, vostok::render::res_effect *, vostok::render::effect_compile_data *, vostok::resources::queries_result *))this;
    v11.l_.boost::_bi::storage2<boost::_bi::value<vostok::render::effect_cook *>,boost::_bi::value<vostok::resources::query_result_for_cook *> > = *(boost::_bi::storage2<boost::_bi::value<vostok::render::effect_cook *>,boost::_bi::value<vostok::resources::query_result_for_cook *> > *)((char *)&v16 + 4);
    callback.vtable = 0;
    v11.l_.a3_.t_ = (vostok::render::res_effect *)params;
    if ( boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_aimed_idle_state>,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_aimed_idle_state> *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *>>>>(
           (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state>::on_subresources_ready,
           v11,
           &callback.functor) )
    {
      callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state>,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state> *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *>>>>'::`2'::stored_vtable
                                                               + 1);
    }
    else
    {
      callback.vtable = 0;
    }
    vostok::resources::query_resources(
      requests.m_begin,
      requests.m_end - requests.m_begin,
      &callback,
      (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
      0,
      parent,
      assert_on_fail_true);
    if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
    {
      v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v10 )
        v10(&callback.functor, &callback.functor, 2);
    }
    vostok::resources::query_result_for_cook::finish_query_impl(
      v9,
      result_postponed,
      assert_on_fail_true,
      error_type_unset);
  }
  else
  {
    __debugbreak();
    vostok::resources::query_result_for_cook::finish_query_impl(
      v5,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
  }
}
