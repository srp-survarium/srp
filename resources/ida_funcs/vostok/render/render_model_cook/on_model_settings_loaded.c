void __thiscall vostok::render::render_model_cook::on_model_settings_loaded(
        vostok::render::render_model_cook *this,
        vostok::resources::queries_result *data,
        vostok::render::cook_intermediate_data *cook_data)
{
  volatile int m_result; // edx
  bool v4; // zf
  vostok::resources::unmanaged_resource *v5; // edi
  vostok::configs::binary_config *m_object; // eax
  vostok::resources::unmanaged_intrusive_base *v7; // ecx
  bool v8; // bl
  int m_num_render_models; // eax
  unsigned int v10; // edi
  int v11; // ebx
  unsigned int v12; // ecx
  unsigned int *v13; // eax
  const vostok::resources::request *v14; // edi
  survarium::game_camera *v15; // ecx
  unsigned int v16; // ebx
  const char *v17; // edx
  char *M_finish; // eax
  vostok::render::render_model_cook *v19; // ecx
  void (__cdecl *v20)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  char v21; // bl
  void (__cdecl *v22)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::configs::binary_config_value *v23; // eax
  bool v24; // al
  int v25; // ecx
  const char *v26; // eax
  void (__cdecl *v27)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  const stlp_std::__true_type *v29; // [esp+0h] [ebp-A0h]
  unsigned int v30; // [esp+4h] [ebp-9Ch]
  bool v31; // [esp+8h] [ebp-98h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v32; // [esp+Ch] [ebp-94h] BYREF
  const char *sname; // [esp+10h] [ebp-90h] BYREF
  unsigned int num_render_models; // [esp+14h] [ebp-8Ch] BYREF
  const vostok::resources::request *v35; // [esp+18h] [ebp-88h]
  vostok::render::cook_intermediate_data *v36; // [esp+1Ch] [ebp-84h]
  vostok::configs::binary_config_value msettings; // [esp+20h] [ebp-80h] BYREF
  unsigned __int64 max_storage; // [esp+3Ch] [ebp-64h]
  vostok::render::cook_intermediate_data *v39; // [esp+44h] [ebp-5Ch]
  vostok::configs::binary_config_value root; // [esp+48h] [ebp-58h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+60h] [ebp-40h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+80h] [ebp-20h] BYREF

  m_result = data->m_result;
  v36 = (vostok::render::cook_intermediate_data *)this;
  v35 = 0;
  if ( m_result != 1 )
  {
    v4 = !cook_data->render_model_data_ready;
    cook_data->material_data_ready = 1;
    if ( !v4 )
      vostok::render::render_model_cook::query_materail_effects(
        this,
        (vostok::render::cook_intermediate_data *)this,
        cook_data);
    return;
  }
  num_render_models = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&num_render_models,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  v5 = (vostok::resources::unmanaged_resource *)num_render_models;
  v32.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v32,
    (vostok::configs::binary_config *)num_render_models);
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
    &cook_data->model_settings_config,
    (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&v32);
  m_object = v32.m_object;
  if ( v32.m_object )
  {
    v7 = &v32.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v32.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v7, m_object);
  }
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  root = *cook_data->model_settings_config.m_object->m_root;
  v8 = vostok::configs::binary_config_value::value_exists(&root, "material_settings");
  msettings.data.max_storage = 0;
  vostok::platform_pointer_selector<char const,1>::helper::helper(&msettings.id, 0);
  msettings.id_crc = 0;
  msettings.type = 0;
  msettings.count = 0;
  if ( v8 )
  {
    msettings = *vostok::configs::binary_config_value::operator[](&root, "material_settings");
    m_num_render_models = cook_data->m_num_render_models;
    v10 = 24 * msettings.count / 24;
    num_render_models = v10;
    if ( m_num_render_models == v10 && v8 )
    {
      v11 = 0;
      if ( !m_num_render_models )
      {
LABEL_16:
        cook_data->material_settings_valid = 1;
        v13 = (unsigned int *)vostok::memory::doug_lea_allocator::malloc_impl(
                                (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                8 * v10 + 8);
        *v13++ = v10;
        v14 = (const vostok::resources::request *)(v13 + 1);
        *v13 = 8;
        v35 = (const vostok::resources::request *)(v13 + 1);
        survarium::weapon_user_dead_state::finalize(v15);
        v16 = 0;
        if ( cook_data->m_num_render_models )
        {
          v32.m_object = 0;
          do
          {
            v17 = *(char **)((char *)&cook_data->assets->m_surface_name.m_string.m_begin + (unsigned int)v32.m_object);
            M_finish = (char *)cook_data->m_surface_materials._M_impl._M_finish;
            sname = v17;
            if ( M_finish == (char *)cook_data->m_surface_materials._M_impl._M_end_of_storage._M_data )
            {
              stlp_std::priv::_Impl_vector<unsigned int,vostok::render::std_allocator<unsigned int>>::_M_insert_overflow(
                (stlp_std::priv::_Impl_vector<unsigned int,vostok::render::std_allocator<unsigned int> > *)&cook_data->m_surface_materials,
                M_finish,
                (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)&cook_data->m_surface_materials,
                (const unsigned int *)&sname,
                v29,
                v30,
                v31);
              v14 = v35;
              v17 = sname;
            }
            else
            {
              *(_DWORD *)M_finish = v17;
              ++cook_data->m_surface_materials._M_impl._M_finish;
            }
            v23 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            &msettings,
                                                            v17);
            sname = (const char *)vostok::configs::binary_config_value::operator[](v23, "material_name")->data.pointer;
            v24 = &sname[strlen(sname) + 1] != sname + 1;
            v25 = v24 ? 0x21 : 0;
            v4 = !v24;
            v26 = sname;
            v14[v16].id = v25;
            if ( v4 )
              v26 = "a";
            v32.m_object = (vostok::configs::binary_config *)((char *)v32.m_object + 288);
            v14[v16++].path = v26;
          }
          while ( v16 < cook_data->m_num_render_models );
        }
        HIDWORD(root.data.max_storage) = v36;
        root.data.pointer = vostok::render::render_model_cook::on_materials_loaded;
        max_storage = root.data.max_storage;
        v39 = cook_data;
        if ( survarium::generate_shaders_world::is_loading() )
        {
          callback.vtable = 0;
        }
        else
        {
          *(_QWORD *)&callback.functor.obj_ptr = max_storage;
          callback.functor.vostok_pointer_size_alignment[2] = v39;
          callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::render_model_cook,vostok::resources::queries_result &,vostok::render::cook_intermediate_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::render_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::cook_intermediate_data *>>>>'::`2'::stored_vtable
                                                                   + 1);
        }
        vostok::resources::query_resources(
          v14,
          num_render_models,
          &callback,
          (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
          0,
          cook_data->parent_query,
          assert_on_fail_true);
        if ( callback.vtable )
        {
          if ( ((int)callback.vtable & 1) == 0 )
          {
            v27 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
            if ( v27 )
              v27(&callback.functor, &callback.functor, 2);
          }
        }
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (void *)&v14[-1]);
        return;
      }
      v32.m_object = 0;
      while ( vostok::configs::binary_config_value::value_exists(
                &msettings,
                *(const char **)((char *)&cook_data->assets->m_surface_name.m_string.m_begin + (unsigned int)v32.m_object)) )
      {
        v12 = cook_data->m_num_render_models;
        v32.m_object = (vostok::configs::binary_config *)((char *)v32.m_object + 288);
        if ( ++v11 >= v12 )
          goto LABEL_16;
      }
    }
  }
  if ( vostok::core::g_log_filter_tree
    && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", error) )
  {
    v21 = (char)v35;
  }
  else
  {
    v20 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v20 )
    {
      log_callback.functor.obj_ptr = v20;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v21 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\render_model_cooker.cpp",
      0x1A9u,
      "void __thiscall vostok::render::render_model_cook::on_model_settings_loaded(class vostok::resources::queries_resul"
      "t &,struct vostok::render::cook_intermediate_data *)",
      "render_pc_dx11:",
      error,
      "Incompatible model settings for %s",
      cook_data->root_model_path.m_string.m_begin);
  }
  if ( (v21 & 1) != 0 )
  {
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v22 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v22 )
          v22(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
  v4 = !cook_data->render_model_data_ready;
  cook_data->material_settings_valid = 0;
  cook_data->material_data_ready = 1;
  if ( !v4 )
    vostok::render::render_model_cook::query_materail_effects(v19, v36, cook_data);
}
