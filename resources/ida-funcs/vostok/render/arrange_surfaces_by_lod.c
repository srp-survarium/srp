void __cdecl vostok::render::arrange_surfaces_by_lod(
        vostok::render::cook_intermediate_data *cook_data,
        vostok::render::model_lods_descriptor **lods_descriptor)
{
  vostok::configs::binary_config *m_object; // eax
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  vostok::render::model_lods_descriptor *v6; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // ecx
  unsigned __int8 **m_lod_surfaces; // eax
  int v9; // edx
  bool v10; // al
  vostok::resources::query_result_for_cook *v11; // ecx
  const char *v12; // eax
  const vostok::configs::binary_config_value *v13; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v14; // ecx
  char *v15; // edi
  const vostok::configs::binary_config_value *v16; // eax
  vostok::configs::binary_config_value *v17; // ecx
  vostok::configs::binary_config_value *v18; // eax
  char **obj_ptr; // ebx
  signed int v20; // eax
  unsigned __int8 *v21; // edi
  char *v22; // eax
  unsigned int m_num_render_models; // ebx
  vostok::fs_new::virtual_path_string *p_m_surface_name; // esi
  int v25; // eax
  bool has_passed_filters; // al
  vostok::resources::query_result_for_cook *parent_query; // ecx
  const char *requested_path; // eax
  vostok::render::model_lods_descriptor *v29; // eax
  vostok::configs::binary_config_value *v30; // ecx
  vostok::configs::binary_config_value *v31; // eax
  vostok::configs::binary_config_value *v32; // eax
  bool v33; // al
  vostok::configs::binary_config_value *v34; // eax
  const vostok::configs::binary_config_value *v35; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v37; // eax
  const vostok::configs::binary_config_value *v38; // eax
  float v39; // xmm0_4
  const vostok::configs::binary_config_value *v40; // eax
  vostok::configs::binary_config_value *v41; // ecx
  vostok::configs::binary_config_value *v42; // eax
  const vostok::configs::binary_config_value *v43; // eax
  float v44; // xmm0_4
  int v45; // eax
  int v46; // edi
  int v47; // eax
  unsigned __int8 v48; // cl
  int v49; // esi
  unsigned int v50; // edx
  unsigned __int8 **v51; // ecx
  unsigned __int8 **v52; // esi
  vostok::memory::doug_lea_allocator *v53; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v54; // [esp-4h] [ebp-C4h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v55; // [esp-4h] [ebp-C4h]
  const char *v56; // [esp+0h] [ebp-C0h]
  const char *v57; // [esp+0h] [ebp-C0h]
  const char *v58; // [esp+4h] [ebp-BCh]
  const char *v59; // [esp+4h] [ebp-BCh]
  unsigned int v60; // [esp+8h] [ebp-B8h]
  unsigned int v61; // [esp+8h] [ebp-B8h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v62; // [esp+10h] [ebp-B0h] BYREF
  vostok::configs::binary_config_value v63; // [esp+30h] [ebp-90h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v64; // [esp+48h] [ebp-78h] BYREF
  _DWORD v65[3]; // [esp+68h] [ebp-58h] BYREF
  _DWORD v66[3]; // [esp+74h] [ebp-4Ch]
  vostok::configs::binary_config_value v67; // [esp+80h] [ebp-40h] BYREF
  char **v68; // [esp+98h] [ebp-28h]
  char *right; // [esp+9Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v70; // [esp+A0h] [ebp-20h]
  unsigned int v71; // [esp+A4h] [ebp-1Ch]
  unsigned int v72; // [esp+A8h] [ebp-18h]
  int v73; // [esp+ACh] [ebp-14h]
  char **v74; // [esp+B0h] [ebp-10h]
  int v75; // [esp+B4h] [ebp-Ch]
  __int16 v76; // [esp+B8h] [ebp-8h] BYREF
  unsigned __int8 v77; // [esp+BAh] [ebp-6h]
  unsigned __int8 v78; // [esp+BEh] [ebp-2h]
  unsigned __int8 v79; // [esp+BFh] [ebp-1h]
  int v80; // [esp+C8h] [ebp+8h]

  v75 = 0;
  memset(v65, 0, sizeof(v65));
  v76 = 0;
  v77 = 0;
  m_object = cook_data->model_settings_config.m_object;
  if ( m_object )
  {
    qmemcpy((void *)&v67, m_object->m_root, sizeof(v67));
    v66[0] = "LOD0";
    v66[1] = "LOD1";
    v66[2] = "LOD2";
    if ( vostok::configs::binary_config_value::value_exists(0, (int)&v67, (unsigned int)"lod_hierrarchy") )
    {
      v13 = vostok::configs::binary_config_value::operator[](&v67, "lod_hierrarchy");
      v72 = 0;
      qmemcpy((void *)&v63, v13, sizeof(v63));
      v14 = 0;
      v70 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v76;
      v73 = 3;
      do
      {
        v15 = (char *)v66[v72 / 4];
        if ( vostok::configs::binary_config_value::value_exists(
               (vostok::configs::binary_config_value *)v14,
               (int)&v63,
               (unsigned int)v15) )
        {
          v16 = vostok::configs::binary_config_value::operator[](&v63, v15);
          if ( vostok::configs::binary_config_value::value_exists(v17, (int)v16, (unsigned int)"surfaces") )
          {
            v18 = vostok::configs::binary_config_value::operator[](&v63, v15);
            qmemcpy(
              (void *)&v64.functor,
              vostok::configs::binary_config_value::operator[](v18, "surfaces"),
              sizeof(v64.functor));
            obj_ptr = (char **)v64.functor.obj_ptr;
            v20 = 24 * ((unsigned int)v64.functor.vostok_pointer_size_alignment[5] >> 16);
            v68 = (char **)((char *)v64.functor.obj_ptr + v20);
            v74 = (char **)v64.functor.obj_ptr;
            v78 = 0;
            v79 = v20 / 24;
            v21 = vostok::memory::new_array_helper<unsigned char>::call<vostok::memory::doug_lea_allocator>(
                    vostok::render::g_allocator,
                    v79,
                    v56,
                    v58,
                    v60);
            v65[v72 / 4] = v21;
            if ( obj_ptr != v68 )
            {
              do
              {
                if ( *((_WORD *)&v64.functor.data + 10) == 4 )
                  v22 = *v74;
                else
                  v22 = v74[2];
                v71 = 0;
                right = v22;
                m_num_render_models = cook_data->m_num_render_models;
                if ( cook_data->m_num_render_models )
                {
                  p_m_surface_name = &cook_data->assets->m_surface_name;
                  while ( vostok::strings::compare(p_m_surface_name->m_string.m_begin, right) )
                  {
                    ++v71;
                    p_m_surface_name = (vostok::fs_new::virtual_path_string *)((char *)p_m_surface_name + 288);
                    if ( v71 >= m_num_render_models )
                      goto LABEL_24;
                  }
                  v25 = v71;
                }
                else
                {
LABEL_24:
                  v25 = -1;
                }
                if ( v25 == -1 )
                {
                  --v79;
                  if ( !vostok::core::g_log_filter_tree
                    || (has_passed_filters = vostok::logging::has_passed_filters(
                                               (vostok::logging::filter_tree *)"render_pc_dx11",
                                               (const char *)2),
                        v14 = v55,
                        has_passed_filters) )
                  {
                    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
                      v14,
                      &v62);
                    parent_query = cook_data->parent_query;
                    v75 |= 2u;
                    requested_path = vostok::resources::query_result_for_user::get_requested_path(parent_query);
                    vostok::logging::append(
                      &v62,
                      (void *const)vostok::core::g_log_flags,
                      &vostok::core::g_log_format,
                      ".\\render_model_cooker.cpp",
                      0x2D4u,
                      "void __cdecl vostok::render::arrange_surfaces_by_lod(struct vostok::render::cook_intermediate_data"
                      " *,struct vostok::render::model_lods_descriptor *&)",
                      "render_pc_dx11",
                      error,
                      "Incorrect model LOD settings for %s",
                      requested_path);
                  }
                  if ( (v75 & 2) != 0 )
                  {
                    v75 &= ~2u;
                    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
                      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v14,
                      (int *)&v62);
                  }
                }
                else
                {
                  v14 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v78++;
                  v21[(_DWORD)v14] = v25;
                }
                v74 += 6;
              }
              while ( v74 != v68 );
            }
            if ( v79 )
            {
              v14 = v70;
              LOBYTE(v70->vtable) = v79;
            }
          }
        }
        v72 += 4;
        v70 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)((char *)v70 + 1);
        --v73;
      }
      while ( v73 );
      v29 = (vostok::render::model_lods_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                       (vostok::memory::doug_lea_allocator *)(unsigned __int8)v76,
                                                       (int)vostok::render::g_allocator,
                                                       HIBYTE(v76) + v77 + (unsigned __int8)v76 + 36,
                                                       "model_lods_descriptor",
                                                       v56,
                                                       v58,
                                                       v60);
      *lods_descriptor = v29;
      if ( v29 )
      {
        v29->m_lod_calc_type = 0;
        v29->m_lod_params_default = 1;
      }
      if ( vostok::configs::binary_config_value::value_exists(v30, (int)&v67, (unsigned int)"lod_switching") )
      {
        vostok::configs::binary_config_value::operator[](&v67, "lod_switching");
        v31 = vostok::configs::binary_config_value::operator[](&v67, "lod_switching");
        (*lods_descriptor)->m_lod_calc_type = (unsigned __int8)vostok::configs::binary_config_value::operator[](
                                                                 v31,
                                                                 "type")->data.pointer;
        v32 = vostok::configs::binary_config_value::operator[](&v67, "lod_switching");
        v33 = vostok::configs::binary_config_value::operator[](v32, "default_params")->data.pointer != 0;
        (*lods_descriptor)->m_lod_params_default = v33;
        if ( !v33 )
        {
          v34 = vostok::configs::binary_config_value::operator[](&v67, "lod_switching");
          v35 = vostok::configs::binary_config_value::operator[](v34, "param0");
          if ( v35->type == 2 )
            pointer = *(float *)&v35->data.pointer;
          else
            pointer = (float)(int)v35->data.pointer;
          (*lods_descriptor)->m_lod_custom_params[0] = pointer;
          v37 = vostok::configs::binary_config_value::operator[](&v67, "lod_switching");
          v38 = vostok::configs::binary_config_value::operator[](v37, "param1");
          if ( v38->type == 2 )
            v39 = *(float *)&v38->data.pointer;
          else
            v39 = (float)(int)v38->data.pointer;
          (*lods_descriptor)->m_lod_custom_params[1] = v39;
          v40 = vostok::configs::binary_config_value::operator[](&v67, "lod_switching");
          if ( vostok::configs::binary_config_value::value_exists(v41, (int)v40, (unsigned int)"param2") )
          {
            v42 = vostok::configs::binary_config_value::operator[](&v67, "lod_switching");
            v43 = vostok::configs::binary_config_value::operator[](v42, "param2");
            if ( v43->type == 2 )
              v44 = *(float *)&v43->data.pointer;
            else
              v44 = (float)(int)v43->data.pointer;
            v45 = (int)*lods_descriptor;
          }
          else
          {
            v45 = (int)*lods_descriptor;
            if ( (*lods_descriptor)->m_lod_calc_type )
              v44 = epsilon_3_4;
            else
              v44 = FLOAT_240_0;
          }
          *(float *)(v45 + 28) = v44;
        }
      }
      v46 = 0;
      v80 = 0;
      v73 = 3;
      do
      {
        v47 = (int)*lods_descriptor;
        v48 = *((_BYTE *)&v76 + v46);
        v49 = v80;
        *(_BYTE *)(v47 + v46) = v48;
        v50 = v48;
        v80 += v48;
        v51 = (unsigned __int8 **)(v47 + 4 * v46 + 4);
        *v51 = (unsigned __int8 *)(v47 + v49 + 36);
        v52 = (unsigned __int8 **)&v65[v46];
        memcpy(*v51, *v52, v50);
        if ( *v52 )
          vostok::memory::doug_lea_allocator::free_impl(
            v53,
            (int)vostok::render::g_allocator,
            (char *)*v52 - 8,
            v57,
            v59,
            v61);
        ++v46;
        --v73;
      }
      while ( v73 );
    }
  }
  else
  {
    v3 = vostok::render::g_allocator;
    v4 = type_info::raw_name(&vostok::render::model_lods_descriptor `RTTI Type Descriptor');
    v6 = (vostok::render::model_lods_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                    v5,
                                                    (int)v3,
                                                    0x24u,
                                                    v4,
                                                    v56,
                                                    v58,
                                                    v60);
    if ( v6 )
    {
      v6->m_lod_calc_type = 0;
      v6->m_lod_params_default = 1;
    }
    else
    {
      v6 = 0;
    }
    *lods_descriptor = v6;
    v7 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v6;
    m_lod_surfaces = v6->m_lod_surfaces;
    v9 = 3;
    do
    {
      LOBYTE(v7->vtable) = 0;
      *m_lod_surfaces = 0;
      v7 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)((char *)v7 + 1);
      ++m_lod_surfaces;
      --v9;
    }
    while ( v9 );
    if ( !vostok::core::g_log_filter_tree
      || (v10 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"render_pc_dx11", (const char *)2),
          v7 = v54,
          v10) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v7,
        &v64);
      v11 = cook_data->parent_query;
      v75 = 1;
      v12 = vostok::resources::query_result_for_user::get_requested_path(v11);
      vostok::logging::append(
        &v64,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\render_model_cooker.cpp",
        0x2AFu,
        "void __cdecl vostok::render::arrange_surfaces_by_lod(struct vostok::render::cook_intermediate_data *,struct vost"
        "ok::render::model_lods_descriptor *&)",
        "render_pc_dx11",
        error,
        "Incorrect model settings for %s",
        v12);
    }
    if ( (v75 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v7,
        (int *)&v64);
  }
}
