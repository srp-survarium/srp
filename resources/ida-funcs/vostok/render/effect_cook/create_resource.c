void __thiscall vostok::render::effect_cook::create_resource(
        vostok::render::effect_cook *this,
        vostok::resources::query_result_for_cook *in_out_query,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::variant<32> *m_user_data; // esi
  vostok::render::effect_compile_data *v5; // ebx
  vostok::render::grass_render_model *m_object; // ecx
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v8; // ecx
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  char v10; // bl
  bool v11; // zf
  void (__cdecl *v12)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  vostok::render::res_effect *v13; // eax
  vostok::render::effect_compiler *v14; // ecx
  int v15; // edi
  int *v16; // eax
  int *v17; // esi
  int *v18; // ecx
  int M_start; // ecx
  vostok::render::effect_compile_data *v20; // esi
  vostok::render::shader_configuration *p_configuration; // ebx
  vostok::fs_new::virtual_path_string *v22; // edi
  unsigned __int8 *m_begin; // edx
  char *m_end; // ecx
  vostok::render::custom_config *v25; // eax
  vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *v26; // edx
  vostok::fs_new::virtual_path_string *v27; // edi
  vostok::render::effect_compile_data *v28; // esi
  unsigned __int8 *v29; // edx
  char *v30; // ecx
  vostok::render::custom_config *v31; // eax
  vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *v32; // edx
  vostok::fs_new::virtual_path_string *v33; // edi
  vostok::render::effect_compile_data *v34; // esi
  unsigned __int8 *v35; // eax
  char *v36; // ecx
  vostok::render::custom_config *v37; // eax
  vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *v38; // edx
  vostok::render::effect_compile_data *v39; // esi
  void (__cdecl *v40)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::grass_render_model *v41; // ecx
  char *v42; // eax
  malloc_state *v43; // esi
  char *v44; // eax
  malloc_state *v45; // esi
  _BYTE v46[284]; // [esp-118h] [ebp-9238h] BYREF
  vostok::render::binary_shader_cook_data *v47; // [esp+Ch] [ebp-9114h]
  vostok::render::res_effect *effect; // [esp+10h] [ebp-9110h]
  vostok::render::effect_compile_data *v49; // [esp+14h] [ebp-910Ch]
  vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *p_config; // [esp+18h] [ebp-9108h]
  unsigned __int8 *src; // [esp+1Ch] [ebp-9104h]
  vostok::render::effect_compile_data *out_value[2]; // [esp+20h] [ebp-9100h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+28h] [ebp-90F8h] BYREF
  vostok::render::effect_cook *v54; // [esp+4Ch] [ebp-90D4h]
  stlp_std::priv::_Vector_base<vostok::render::effect_compiler::shader_cache_info,vostok::vectora_allocator<vostok::render::effect_compiler::shader_cache_info> > v55; // [esp+50h] [ebp-90D0h] BYREF
  unsigned int request_count[2]; // [esp+60h] [ebp-90C0h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+68h] [ebp-90B8h] BYREF
  vostok::render::effect_compiler v58; // [esp+88h] [ebp-9098h] BYREF

  m_user_data = in_out_query->m_user_data;
  v54 = this;
  effect = 0;
  out_value[0] = 0;
  if ( !m_user_data
    || (vostok::variant<32>::try_get<vostok::render::effect_compile_data *>(
          (vostok::variant<32> *)this,
          (int)m_user_data,
          out_value),
        (v5 = out_value[0]) == 0) )
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      (int)in_out_query,
      result_error,
      assert_on_fail_false,
      (vostok::resources::query_result_for_cook *)0xB);
    m_object = vostok::render::g_allocator.m_object;
    if ( in_out_unmanaged_resource_buffer.m_data )
    {
      m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, in_out_unmanaged_resource_buffer.m_data);
      m_object = vostok::render::g_allocator.m_object;
    }
LABEL_5:
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::effect_compile_data,vostok::memory::detail::call_destructor_predicate>(
      (vostok::memory::doug_lea_allocator *)m_object,
      out_value);
    return;
  }
  if ( !out_value[0]->descriptor )
  {
    if ( vostok::core::g_log_filter_tree
      && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
    {
      v10 = (char)effect;
    }
    else
    {
      v9 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v9 )
      {
        log_callback.functor.obj_ptr = v9;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v10 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        &stru_984D24.m_working_macro_list.m_buffer[0].m_store[316],
        0x75u,
        &stru_984D24.m_working_macro_list.m_buffer[0].m_store[148],
        "render:",
        error,
        &stru_984D24.m_working_macro_list.m_buffer[0].m_store[120]);
    }
    v11 = (v10 & 1) == 0;
LABEL_17:
    if ( !v11 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v8,
        (int *)&log_callback);
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)v8,
      (int)in_out_query,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
    m_object = vostok::render::g_allocator.m_object;
    if ( in_out_unmanaged_resource_buffer.m_data )
    {
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(
        (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
        in_out_unmanaged_resource_buffer.m_data);
      m_object = vostok::render::g_allocator.m_object;
    }
    goto LABEL_5;
  }
  if ( !out_value[0]->config.m_object )
  {
    if ( vostok::core::g_log_filter_tree
      && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
    {
      v11 = ((unsigned __int8)effect & 2) == 0;
    }
    else
    {
      v12 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v12 )
      {
        log_callback.functor.obj_ptr = v12;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        &stru_984D24.m_working_macro_list.m_buffer[0].m_store[316],
        0x7Fu,
        &stru_984D24.m_working_macro_list.m_buffer[0].m_store[148],
        "render:",
        error,
        &stru_984D24.m_working_macro_list.m_buffer[0].m_store[336]);
      v11 = 0;
    }
    goto LABEL_17;
  }
  if ( in_out_unmanaged_resource_buffer.m_data )
  {
    vostok::render::res_effect::res_effect(
      (vostok::render::res_effect *)this,
      (int)in_out_unmanaged_resource_buffer.m_data);
    effect = v13;
  }
  else
  {
    effect = 0;
  }
  vostok::render::effect_compiler::effect_compiler(&v58, effect, in_out_query, 1, 0);
  v5->descriptor->compile(v5->descriptor, &v58, &v5->config.m_object->m_root);
  vostok::render::effect_compiler::get_cached_shaders_info(v14, &v55, (int)&v58);
  v15 = 3 * (v55._M_finish - v55._M_start);
  request_count[0] = v15;
  out_value[1] = (vostok::render::effect_compile_data *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                          48 * (v55._M_finish - v55._M_start));
  v16 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          276 * v15);
  request_count[1] = (unsigned int)v16;
  v17 = v16;
  if ( v15 )
  {
    v49 = (vostok::render::effect_compile_data *)v15;
    do
    {
      v18 = v17;
      v17 += 69;
      if ( v18 )
      {
        *v18 = (int)(v18 + 3);
        v18[1] = (int)(v18 + 3);
        v18[2] = (int)(v18 + 68);
        *((_BYTE *)v18 + 12) = 0;
        *((_BYTE *)v18 + 12) = 0;
        *((_BYTE *)v18 + 272) = 47;
      }
      v49 = (vostok::render::effect_compile_data *)((char *)v49 - 1);
    }
    while ( v49 );
  }
  M_start = (int)v55._M_start;
  if ( v55._M_start != v55._M_finish )
  {
    v20 = out_value[1];
    p_configuration = &v55._M_start->configuration;
    v22 = (vostok::fs_new::virtual_path_string *)v16;
    v49 = out_value[1];
    p_config = &out_value[1]->config;
    do
    {
      vostok::fs_new::virtual_path_string::operator=(v22, (vostok::fs_new::virtual_path_string *)&p_configuration[-52]);
      if ( v20 )
      {
        v47 = (vostok::render::binary_shader_cook_data *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                           0x138u);
        if ( v47 )
        {
          m_begin = (unsigned __int8 *)v22->m_string.m_begin;
          m_end = v22->m_string.m_end;
          *(_DWORD *)&v46[276] = 0;
          *(_DWORD *)&v46[8] = &v46[272];
          *(_DWORD *)v46 = &v46[12];
          *(_DWORD *)&v46[4] = &v46[12];
          src = (unsigned __int8 *)(m_end - (char *)m_begin);
          memcpy(&v46[12], m_begin, m_end - (char *)m_begin);
          *(_DWORD *)&v46[4] += src;
          **(_BYTE **)&v46[4] = 0;
          v46[272] = 47;
          vostok::render::binary_shader_cook_data::binary_shader_cook_data(
            v47,
            effect,
            *p_configuration,
            *(vostok::fs_new::virtual_path_string *)v46,
            *(vostok::render::enum_shader_type *)&v46[276],
            v46[280]);
          v20 = v49;
        }
        else
        {
          v25 = 0;
        }
        v20->descriptor = (vostok::render::effect_descriptor *)v22->m_string.m_begin;
        v26 = p_config;
        p_config->m_object = v25;
        v26[1].m_object = (vostok::render::custom_config *)312;
        *(_DWORD *)&v20->add_to_array = 12;
      }
      p_config += 4;
      v27 = v22 + 1;
      v28 = v20 + 1;
      v49 = v28;
      vostok::fs_new::virtual_path_string::operator=(
        v27,
        (vostok::fs_new::virtual_path_string *)&p_configuration[-18].configuration[1]);
      if ( v28 )
      {
        src = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                                   (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                   0x138u);
        if ( src )
        {
          v29 = (unsigned __int8 *)v27->m_string.m_begin;
          v30 = v27->m_string.m_end;
          *(_DWORD *)&v46[276] = 2;
          *(_DWORD *)&v46[8] = &v46[272];
          *(_DWORD *)v46 = &v46[12];
          *(_DWORD *)&v46[4] = &v46[12];
          v47 = (vostok::render::binary_shader_cook_data *)(v30 - (char *)v29);
          memcpy(&v46[12], v29, v30 - (char *)v29);
          *(_DWORD *)&v46[4] += v47;
          **(_BYTE **)&v46[4] = 0;
          v46[272] = 47;
          vostok::render::binary_shader_cook_data::binary_shader_cook_data(
            (vostok::render::binary_shader_cook_data *)src,
            effect,
            *p_configuration,
            *(vostok::fs_new::virtual_path_string *)v46,
            *(vostok::render::enum_shader_type *)&v46[276],
            v46[280]);
          v28 = v49;
        }
        else
        {
          v31 = 0;
        }
        v28->descriptor = (vostok::render::effect_descriptor *)v27->m_string.m_begin;
        v32 = p_config;
        p_config->m_object = v31;
        v32[1].m_object = (vostok::render::custom_config *)312;
        *(_DWORD *)&v28->add_to_array = 12;
      }
      p_config += 4;
      v33 = v27 + 1;
      v34 = v28 + 1;
      v49 = v34;
      vostok::fs_new::virtual_path_string::operator=(
        v33,
        (vostok::fs_new::virtual_path_string *)((char *)p_configuration[-35].configuration + 4));
      if ( v34 )
      {
        src = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                                   (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                   0x138u);
        if ( src )
        {
          v35 = (unsigned __int8 *)v33->m_string.m_begin;
          v36 = v33->m_string.m_end;
          *(_DWORD *)&v46[276] = 1;
          *(_DWORD *)&v46[8] = &v46[272];
          *(_DWORD *)v46 = &v46[12];
          *(_DWORD *)&v46[4] = &v46[12];
          v47 = (vostok::render::binary_shader_cook_data *)(v36 - (char *)v35);
          memcpy(&v46[12], v35, v36 - (char *)v35);
          *(_DWORD *)&v46[4] += v47;
          **(_BYTE **)&v46[4] = 0;
          v46[272] = 47;
          vostok::render::binary_shader_cook_data::binary_shader_cook_data(
            (vostok::render::binary_shader_cook_data *)src,
            effect,
            *p_configuration,
            *(vostok::fs_new::virtual_path_string *)v46,
            *(vostok::render::enum_shader_type *)&v46[276],
            v46[280]);
          v34 = v49;
        }
        else
        {
          v37 = 0;
        }
        v34->descriptor = (vostok::render::effect_descriptor *)v33->m_string.m_begin;
        v38 = p_config;
        M_start = 312;
        p_config->m_object = v37;
        v38[1].m_object = (vostok::render::custom_config *)312;
        *(_DWORD *)&v34->add_to_array = 12;
      }
      p_config += 4;
      p_configuration += 53;
      v20 = v34 + 1;
      v22 = v33 + 1;
      v49 = v20;
    }
    while ( &p_configuration[-52] != (vostok::render::shader_configuration *)v55._M_finish );
    v5 = out_value[0];
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    (vostok::resources::query_result_for_cook *)M_start,
    (int)in_out_query,
    result_postponed,
    assert_on_fail_true,
    0);
  (&callback.vtable)[1] = (boost::detail::function::vtable_base *)in_out_query;
  *(_QWORD *)&(&log_callback.vtable)[1] = __PAIR64__((unsigned int)in_out_query, (unsigned int)v54);
  *(_QWORD *)&callback.functor.obj_ptr = __PAIR64__((unsigned int)v5, (unsigned int)effect);
  *(_QWORD *)((char *)&log_callback.functor.bound_memfunc_ptr.memfunc_ptr + 4) = __PAIR64__(
                                                                                   (unsigned int)v5,
                                                                                   (unsigned int)effect);
  log_callback.vtable = (boost::detail::function::vtable_base *)vostok::render::effect_cook::on_binary_shaders;
  *(_DWORD *)&v46[264] = v54;
  *(_QWORD *)&v46[268] = *(_QWORD *)&log_callback.functor.obj_ptr;
  callback.vtable = 0;
  *(_DWORD *)&v46[276] = v5;
  if ( boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_aimed_idle_state>,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_aimed_idle_state> *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *>>>>(
         &callback.functor,
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)vostok::render::effect_cook::on_binary_shaders,
         *(boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::effect_cook,vostok::resources::query_result_for_cook *,vostok::render::res_effect *,vostok::render::effect_compile_data *,vostok::resources::queries_result &>,boost::_bi::list5<boost::_bi::value<vostok::render::effect_cook *>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::render::res_effect *>,boost::_bi::value<vostok::render::effect_compile_data *>,boost::arg<1> > > *)&v46[264]) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)&stru_984D24.m_working_macro_list.m_buffer[0].m_store[357];
  }
  else
  {
    callback.vtable = 0;
  }
  v39 = out_value[1];
  vostok::resources::query_create_resources(
    (const vostok::resources::creation_request *)out_value[1],
    request_count[0],
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    in_out_query->m_user_allocator,
    0,
    in_out_query,
    assert_on_fail_false);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v40 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v40 )
        v40(&callback.functor, &callback.functor, 2);
    }
  }
  v41 = vostok::render::g_allocator.m_object;
  if ( v39 )
  {
    v42 = (char *)v39;
    v43 = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v43, v42);
    v41 = vostok::render::g_allocator.m_object;
  }
  v44 = (char *)request_count[1];
  if ( request_count[1] )
  {
    v45 = (malloc_state *)HIDWORD(v41->m_reconstruction_info_actuality_tick);
    BYTE2(v41->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v45, v44);
  }
  if ( v55._M_start )
    v55._M_end_of_storage.m_allocator->call_free(v55._M_end_of_storage.m_allocator, v55._M_start);
  vostok::render::effect_compiler::~effect_compiler((vostok::render::effect_compiler *)v41);
}
