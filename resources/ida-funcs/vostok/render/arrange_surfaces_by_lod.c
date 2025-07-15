void __cdecl vostok::render::arrange_surfaces_by_lod(
        vostok::render::cook_intermediate_data *cook_data,
        vostok::render::model_lods_descriptor **lods_descriptor)
{
  vostok::configs::binary_config *m_object; // eax
  vostok::render::model_lods_descriptor *v3; // eax
  unsigned __int8 **m_lod_surfaces; // ecx
  int v5; // edx
  const char *v6; // esi
  vostok::resources::query_result_for_cook *v7; // eax
  char *v8; // ecx
  const char *v9; // eax
  void (__cdecl *v10)(vostok::platform_pointer_selector<char const ,1>::helper *, vostok::platform_pointer_selector<char const ,1>::helper *, int); // eax
  unsigned __int64 *m_root; // eax
  unsigned __int64 v12; // xmm0_8
  const char *v13; // esi
  vostok::configs::binary_config_value *v14; // eax
  vostok::configs::binary_config_value *v15; // eax
  const vostok::configs::binary_config_value *pointer; // edi
  int v17; // ecx
  int v18; // ebx
  _DWORD *v19; // eax
  unsigned __int8 *v20; // ebp
  int v21; // eax
  unsigned __int8 *j; // ecx
  const char *v23; // eax
  int surface_index; // eax
  void (__cdecl *v25)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  vostok::resources::query_result_for_cook *parent_query; // eax
  char *m_requery_path; // ecx
  const char *m_request_path; // eax
  void (__cdecl *v29)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::memory::doug_lea_allocator *v30; // eax
  vostok::render::model_lods_descriptor *v31; // eax
  vostok::configs::binary_config_value *v32; // eax
  vostok::configs::binary_config_value *v33; // eax
  bool v34; // al
  vostok::configs::binary_config_value *v35; // eax
  const vostok::configs::binary_config_value *v36; // eax
  float v37; // xmm0_4
  vostok::configs::binary_config_value *v38; // eax
  const vostok::configs::binary_config_value *v39; // eax
  float v40; // xmm0_4
  vostok::configs::binary_config_value *v41; // eax
  vostok::configs::binary_config_value *v42; // eax
  const vostok::configs::binary_config_value *v43; // eax
  float v44; // xmm0_4
  float v45; // xmm0_4
  int v46; // ebx
  int v47; // edi
  int v48; // eax
  unsigned __int8 v49; // cl
  unsigned __int8 *v50; // esi
  unsigned __int8 *v51; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned __int8 *v53; // [esp-Ch] [ebp-C8h]
  unsigned __int8 i; // [esp+13h] [ebp-A9h]
  unsigned __int8 result_lod_surfaces_count[4]; // [esp+14h] [ebp-A8h] BYREF
  int v56; // [esp+18h] [ebp-A4h]
  int v57; // [esp+1Ch] [ebp-A0h]
  const vostok::configs::binary_config_value *it; // [esp+20h] [ebp-9Ch]
  unsigned int v59; // [esp+24h] [ebp-98h]
  unsigned __int8 *v60; // [esp+28h] [ebp-94h]
  const vostok::configs::binary_config_value *it_e; // [esp+2Ch] [ebp-90h]
  vostok::configs::binary_config_value t_root; // [esp+30h] [ebp-8Ch] BYREF
  vostok::configs::binary_config_value t_surfaces; // [esp+48h] [ebp-74h] BYREF
  unsigned __int8 *result_lod_surfaces[3]; // [esp+68h] [ebp-54h] BYREF
  const char *lods[3]; // [esp+74h] [ebp-48h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+80h] [ebp-3Ch] BYREF
  vostok::configs::binary_config_value t_lods; // [esp+A0h] [ebp-1Ch] BYREF

  memset(result_lod_surfaces_count, 0, 3);
  m_object = cook_data->model_settings_config.m_object;
  v56 = 0;
  memset(result_lod_surfaces, 0, sizeof(result_lod_surfaces));
  if ( m_object )
  {
    m_root = (unsigned __int64 *)m_object->m_root;
    t_root.data.max_storage = *m_root;
    t_root.id.max_storage = m_root[1];
    v12 = m_root[2];
    lods[0] = "LOD0";
    lods[1] = "LOD1";
    lods[2] = "LOD2";
    *(_QWORD *)&t_root.id_crc = v12;
    if ( vostok::configs::binary_config_value::value_exists(&t_root, "lod_hierrarchy") )
    {
      t_lods = *vostok::configs::binary_config_value::operator[](&t_root, "lod_hierrarchy");
      v60 = result_lod_surfaces_count;
      v59 = 0;
      v57 = 3;
      do
      {
        v13 = lods[v59 / 4];
        if ( vostok::configs::binary_config_value::value_exists(&t_lods, v13) )
        {
          v14 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&t_lods, v13);
          if ( vostok::configs::binary_config_value::value_exists(v14, "surfaces") )
          {
            v15 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&t_lods, v13);
            t_surfaces = *vostok::configs::binary_config_value::operator[](v15, "surfaces");
            pointer = (const vostok::configs::binary_config_value *)t_surfaces.data.pointer;
            v17 = 24 * HIWORD(*(_DWORD *)&t_surfaces.type);
            it_e = (const vostok::configs::binary_config_value *)((char *)t_surfaces.data.pointer + v17);
            v18 = v17 / 24;
            it = (const vostok::configs::binary_config_value *)t_surfaces.data.pointer;
            i = 0;
            v19 = vostok::memory::doug_lea_allocator::malloc_impl(
                    (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                    (unsigned __int8)((char)(24 * LOBYTE(t_surfaces.count)) / 24) + 8);
            *v19++ = (unsigned __int8)v18;
            v20 = (unsigned __int8 *)(v19 + 1);
            *v19 = 1;
            v21 = (int)v19 + (unsigned __int8)v18 + 4;
            for ( j = v20; j != (unsigned __int8 *)v21; ++j )
            {
              if ( j )
                *j = 0;
            }
            result_lod_surfaces[v59 / 4] = v20;
            if ( pointer != it_e )
            {
              do
              {
                if ( t_surfaces.type == 4 )
                  v23 = (const char *)it->data.pointer;
                else
                  v23 = (const char *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&it->id);
                surface_index = vostok::render::cook_intermediate_data::find_surface_index(cook_data, v23);
                if ( surface_index == -1 )
                {
                  LOBYTE(v18) = v18 - 1;
                  if ( !vostok::core::g_log_filter_tree
                    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", error) )
                  {
                    v25 = vostok::core::g_log_callback;
                    log_callback.vtable = 0;
                    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
                      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
                        &log_callback.functor,
                        &log_callback.functor,
                        destroy_functor_tag);
                    if ( v25 )
                    {
                      log_callback.functor.obj_ptr = v25;
                      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                                   + 1);
                    }
                    else
                    {
                      log_callback.vtable = 0;
                    }
                    parent_query = cook_data->parent_query;
                    m_requery_path = parent_query->m_requery_path;
                    v56 |= 2u;
                    if ( m_requery_path )
                      m_request_path = m_requery_path;
                    else
                      m_request_path = parent_query->m_request_path;
                    vostok::logging::append(
                      &log_callback,
                      (void *const)vostok::core::g_log_flags,
                      &vostok::core::g_log_format,
                      ".\\render_model_cooker.cpp",
                      0x2D2u,
                      "void __cdecl vostok::render::arrange_surfaces_by_lod(struct vostok::render::cook_intermediate_data"
                      " *,struct vostok::render::model_lods_descriptor *&)",
                      "render_pc_dx11:",
                      error,
                      "Incorrect model LOD settings for %s",
                      m_request_path);
                  }
                  if ( (v56 & 2) != 0 )
                  {
                    v56 &= ~2u;
                    if ( log_callback.vtable )
                    {
                      if ( ((int)log_callback.vtable & 1) == 0 )
                      {
                        v29 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
                        if ( v29 )
                          v29(&log_callback.functor, &log_callback.functor, 2);
                      }
                    }
                  }
                }
                else
                {
                  v20[i++] = surface_index;
                }
                ++it;
              }
              while ( it != it_e );
            }
            if ( (_BYTE)v18 )
              *v60 = v18;
          }
        }
        v59 += 4;
        ++v60;
        --v57;
      }
      while ( v57 );
      v30 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)vostok::render::g_allocator.m_object);
      v31 = (vostok::render::model_lods_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                       v30,
                                                       result_lod_surfaces_count[1]
                                                     + result_lod_surfaces_count[2]
                                                     + result_lod_surfaces_count[0]
                                                     + 36);
      *lods_descriptor = v31;
      if ( v31 )
      {
        v31->m_lod_calc_type = 0;
        v31->m_lod_params_default = 1;
      }
      if ( vostok::configs::binary_config_value::value_exists(&t_root, "lod_switching") )
      {
        vostok::configs::binary_config_value::operator[](&t_root, "lod_switching");
        v32 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        &t_root,
                                                        "lod_switching");
        (*lods_descriptor)->m_lod_calc_type = (unsigned __int8)vostok::configs::binary_config_value::operator[](
                                                                 v32,
                                                                 "type")->data.pointer;
        v33 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        &t_root,
                                                        "lod_switching");
        v34 = vostok::configs::binary_config_value::operator[](v33, "default_params")->data.pointer != 0;
        (*lods_descriptor)->m_lod_params_default = v34;
        if ( !v34 )
        {
          v35 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          &t_root,
                                                          "lod_switching");
          v36 = vostok::configs::binary_config_value::operator[](v35, "param0");
          if ( v36->type == 2 )
            v37 = *(float *)&v36->data.pointer;
          else
            v37 = (float)(int)v36->data.pointer;
          (*lods_descriptor)->m_lod_custom_params[0] = v37;
          v38 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          &t_root,
                                                          "lod_switching");
          v39 = vostok::configs::binary_config_value::operator[](v38, "param1");
          if ( v39->type == 2 )
            v40 = *(float *)&v39->data.pointer;
          else
            v40 = (float)(int)v39->data.pointer;
          (*lods_descriptor)->m_lod_custom_params[1] = v40;
          v41 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          &t_root,
                                                          "lod_switching");
          if ( vostok::configs::binary_config_value::value_exists(v41, "param2") )
          {
            v42 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            &t_root,
                                                            "lod_switching");
            v43 = vostok::configs::binary_config_value::operator[](v42, "param2");
            if ( v43->type == 2 )
              v44 = *(float *)&v43->data.pointer;
            else
              v44 = (float)(int)v43->data.pointer;
            (*lods_descriptor)->m_lod_custom_params[2] = v44;
          }
          else
          {
            if ( (*lods_descriptor)->m_lod_calc_type )
              v45 = epsilon_3_11;
            else
              v45 = 240.0;
            (*lods_descriptor)->m_lod_custom_params[2] = v45;
          }
        }
      }
      v46 = 0;
      v47 = 0;
      v57 = 3;
      do
      {
        v48 = (int)*lods_descriptor;
        v49 = result_lod_surfaces_count[v47];
        v50 = result_lod_surfaces[v47];
        *(_BYTE *)(v48 + v47) = v49;
        *(_DWORD *)(v48 + 4 * v47 + 4) = v48 + v46 + 36;
        v53 = (unsigned __int8 *)(v48 + v46 + 36);
        v46 += v49;
        memcpy(v53, v50, v49);
        if ( v50 )
        {
          v51 = v50;
          m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v51 - 8);
        }
        ++v47;
        --v57;
      }
      while ( v57 );
    }
  }
  else
  {
    v3 = (vostok::render::model_lods_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                    (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                    0x24u);
    if ( v3 )
    {
      v3->m_lod_calc_type = 0;
      v3->m_lod_params_default = 1;
    }
    else
    {
      v3 = 0;
    }
    *lods_descriptor = v3;
    m_lod_surfaces = v3->m_lod_surfaces;
    v5 = 3;
    do
    {
      v3->m_lod_surfaces_count[0] = 0;
      *m_lod_surfaces = 0;
      v3 = (vostok::render::model_lods_descriptor *)((char *)v3 + 1);
      ++m_lod_surfaces;
      --v5;
    }
    while ( v5 );
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", error) )
    {
      v6 = (const char *)vostok::core::g_log_callback;
      t_surfaces.data.pointer = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          (const boost::detail::function::function_buffer *)&t_surfaces.id,
          (boost::detail::function::function_buffer *)&t_surfaces.id,
          destroy_functor_tag);
      if ( v6 )
      {
        t_surfaces.id.pointer = v6;
        t_surfaces.data.pointer = (char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                + 1;
      }
      else
      {
        t_surfaces.data.pointer = 0;
      }
      v7 = cook_data->parent_query;
      v8 = v7->m_requery_path;
      v56 = 1;
      if ( v8 )
        v9 = v8;
      else
        v9 = v7->m_request_path;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&t_surfaces,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\render_model_cooker.cpp",
        0x2ACu,
        "void __cdecl vostok::render::arrange_surfaces_by_lod(struct vostok::render::cook_intermediate_data *,struct vost"
        "ok::render::model_lods_descriptor *&)",
        "render_pc_dx11:",
        error,
        "Incorrect model settings for %s",
        v9);
    }
    if ( (v56 & 1) != 0 && t_surfaces.data.pointer && ((int)t_surfaces.data.pointer & 1) == 0 )
    {
      v10 = *(void (__cdecl **)(vostok::platform_pointer_selector<char const ,1>::helper *, vostok::platform_pointer_selector<char const ,1>::helper *, int))((int)t_surfaces.data.pointer & 0xFFFFFFFE);
      if ( v10 )
        v10(&t_surfaces.id, &t_surfaces.id, 2);
    }
  }
}
