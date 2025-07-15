void __thiscall vostok::render::render_model_cook::on_model_settings_loaded(
        vostok::render::render_model_cook *this,
        vostok::resources::queries_result *data,
        vostok::render::cook_intermediate_data *cook_data)
{
  volatile int m_result; // edx
  bool v4; // zf
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::configs::binary_config_value *v6; // ecx
  int v7; // ecx
  vostok::configs::binary_config_value *v8; // eax
  int m_num_render_models; // esi
  unsigned int v10; // edi
  int v11; // esi
  bool has_passed_filters; // al
  vostok::resources::request *v13; // eax
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v14; // ecx
  char *v15; // edi
  vostok::configs::binary_config_value *v16; // eax
  const char *pointer; // esi
  int v18; // eax
  int v19; // edi
  int v20; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v21; // ecx
  vostok::memory::doug_lea_allocator *v22; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::render_model_cook,vostok::resources::queries_result &,vostok::render::cook_intermediate_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::render_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::cook_intermediate_data *> > > v23; // [esp-10h] [ebp-A8h]
  int v24; // [esp-4h] [ebp-9Ch]
  char *m_begin; // [esp-4h] [ebp-9Ch]
  unsigned int v26; // [esp-4h] [ebp-9Ch]
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v27; // [esp-4h] [ebp-9Ch]
  const char *v28; // [esp+0h] [ebp-98h]
  const char *v29; // [esp+4h] [ebp-94h]
  unsigned int v30; // [esp+8h] [ebp-90h]
  bool v31; // [esp+Fh] [ebp-89h]
  bool v32; // [esp+Fh] [ebp-89h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v33; // [esp+10h] [ebp-88h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v34; // [esp+14h] [ebp-84h] BYREF
  int v35; // [esp+18h] [ebp-80h]
  unsigned int count; // [esp+1Ch] [ebp-7Ch]
  vostok::render::render_model_cook *v37; // [esp+20h] [ebp-78h]
  int __formal; // [esp+24h] [ebp-74h] BYREF
  vostok::configs::binary_config_value v39; // [esp+28h] [ebp-70h] BYREF
  vostok::configs::binary_config_value v40; // [esp+40h] [ebp-58h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v41; // [esp+58h] [ebp-40h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::render_model_cook,vostok::resources::queries_result &,vostok::render::cook_intermediate_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::render_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::cook_intermediate_data *> > > f; // [esp+78h] [ebp-20h] BYREF

  m_result = data->m_result;
  v35 = 0;
  v37 = this;
  if ( m_result == 1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v34,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v34.m_object;
    v33.m_object = 0;
    if ( v34.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v33);
      v33.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v33,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&cook_data->model_settings_config);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v33);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v34);
    qmemcpy((void *)&v40, cook_data->model_settings_config.m_object->m_root, sizeof(v40));
    v31 = vostok::configs::binary_config_value::value_exists(0, (int)&v40, (unsigned int)"material_settings");
    vostok::configs::binary_config_value::binary_config_value(v6, (int)&v39);
    if ( !v31 )
      goto LABEL_31;
    v8 = vostok::configs::binary_config_value::operator[](&v40, "material_settings");
    vostok::configs::binary_config_value::operator=(v8, &v39);
    v7 = 24;
    m_num_render_models = cook_data->m_num_render_models;
    count = 24 * v39.count / 24;
    v32 = m_num_render_models == count && v31;
    if ( !v32 )
      goto LABEL_31;
    v10 = 0;
    if ( m_num_render_models )
    {
      v11 = 0;
      while ( vostok::configs::binary_config_value::value_exists(
                (vostok::configs::binary_config_value *)v7,
                (int)&v39,
                (unsigned int)cook_data->assets[v11].m_surface_name.m_string.m_begin) )
      {
        ++v10;
        ++v11;
        if ( v10 >= cook_data->m_num_render_models )
          goto LABEL_14;
      }
      v32 = 0;
    }
LABEL_14:
    if ( v32 )
    {
      v26 = count;
      cook_data->material_settings_valid = 1;
      v13 = vostok::memory::new_array_helper<vostok::resources::request>::call<vostok::memory::doug_lea_allocator>(
              vostok::render::g_allocator,
              v26);
      v33.m_object = 0;
      v4 = cook_data->m_num_render_models == 0;
      v14 = v27;
      v35 = (int)v13;
      if ( !v4 )
      {
        v34.m_object = 0;
        do
        {
          __formal = *(_DWORD *)((char *)&v34.m_object->vostok::resources::resource_flags
                               + (unsigned int)cook_data->assets
                               + 12);
          v15 = (char *)__formal;
          vostok::buffer_vector<char const *>::push_back(
            (vostok::buffer_vector<char const *> *)v34.m_object,
            (int)&cook_data->m_surface_materials,
            (const char **)&__formal);
          v16 = vostok::configs::binary_config_value::operator[](&v39, v15);
          pointer = (const char *)vostok::configs::binary_config_value::operator[](v16, "material_name")->data.pointer;
          v4 = &pointer[strlen(pointer) + 1] == pointer + 1;
          v18 = v35;
          v19 = 8 * (int)v33.m_object;
          *(_DWORD *)(8 * (int)v33.m_object + v35 + 4) = !v4 ? 0x1F : 0;
          v14 = (boost::function<void __cdecl(vostok::resources::queries_result &)> *)pointer;
          if ( v4 )
            v14 = (boost::function<void __cdecl(vostok::resources::queries_result &)> *)&stru_809F70;
          ++v33.m_object;
          v34.m_object = (survarium::pure_game_effect_emitter_base *)((char *)v34.m_object + 288);
          *(_DWORD *)(v19 + v18) = v14;
        }
        while ( (unsigned int)v33.m_object < cook_data->m_num_render_models );
      }
      HIDWORD(v39.data.max_storage) = v37;
      v39.data.pointer = vostok::render::render_model_cook::on_materials_loaded;
      v39.id.pointer = (const char *)cook_data;
      v23.l_.a1_.t_ = (vostok::render::render_model_cook *)vostok::render::render_model_cook::on_materials_loaded;
      v23.l_.a3_.t_ = (vostok::render::cook_intermediate_data *)v37;
      v23.f_.f_ = (void (__thiscall *)(vostok::render::render_model_cook *, vostok::resources::queries_result *, vostok::render::cook_intermediate_data *))&f;
      boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
        v14,
        v23,
        (int)cook_data);
      v20 = v35;
      vostok::resources::query_resources(
        (const vostok::resources::request *)v35,
        count,
        vostok::render::g_allocator,
        0,
        (const vostok::variant<32> **)cook_data->parent_query,
        assert_on_fail_true);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v21,
        (int *)&f);
      if ( v20 )
        vostok::memory::doug_lea_allocator::free_impl(
          v22,
          (int)vostok::render::g_allocator,
          (char *)(v20 - 8),
          v28,
          v29,
          v30);
    }
    else
    {
LABEL_31:
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"render_pc_dx11",
                                   (const char *)2),
            v7 = v24,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v7,
          &v41);
        m_begin = cook_data->root_model_path.m_string.m_begin;
        v35 = 1;
        vostok::logging::append(
          &v41,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\render_model_cooker.cpp",
          0x1A8u,
          "void __thiscall vostok::render::render_model_cook::on_model_settings_loaded(class vostok::resources::queries_r"
          "esult &,struct vostok::render::cook_intermediate_data *)",
          "render_pc_dx11",
          error,
          "Incompatible model settings for %s",
          m_begin);
      }
      if ( (v35 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v7,
          (int *)&v41);
      v4 = !cook_data->render_model_data_ready;
      cook_data->material_settings_valid = 0;
      cook_data->material_data_ready = 1;
      if ( !v4 )
        vostok::render::render_model_cook::query_materail_effects(
          (vostok::render::render_model_cook *)v7,
          (vostok::render::cook_intermediate_data *)v37,
          cook_data);
    }
  }
  else
  {
    v4 = !cook_data->render_model_data_ready;
    cook_data->material_data_ready = 1;
    if ( !v4 )
      vostok::render::render_model_cook::query_materail_effects(
        this,
        (vostok::render::cook_intermediate_data *)this,
        cook_data);
  }
}
