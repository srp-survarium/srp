void __thiscall vostok::render::effect_cook::translate_query(
        vostok::render::effect_cook *this,
        vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *in_out_query)
{
  void *obj_ptr; // esi
  vostok::render::effect_compile_data *v3; // ebx
  bool has_passed_filters; // al
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  vostok::render::res_effect *v9; // ecx
  vostok::render::res_effect *v10; // eax
  vostok::memory::doug_lea_allocator *v11; // esi
  char *v12; // eax
  vostok::memory::doug_lea_allocator *v13; // ecx
  char *v14; // ecx
  _DWORD *v15; // eax
  int stage_index; // eax
  vostok::render::effect_descriptor_vtbl *v17; // esi
  vostok::configs::binary_config_value *v18; // ecx
  vostok::configs::binary_config_value *v19; // eax
  vostok::configs::binary_config_value *v20; // eax
  const vostok::configs::binary_config_value *v21; // eax
  vostok::render::effect_compiler *v22; // ecx
  unsigned int v23; // esi
  _DWORD *v24; // eax
  void *v25; // esp
  void *v26; // esp
  void *v27; // esp
  void *v28; // esp
  unsigned int v29; // eax
  int v30; // ecx
  const char *v31; // edx
  int v32; // eax
  vostok::fixed_string<260> *v33; // edi
  int *v34; // ebx
  int v35; // eax
  const char *v36; // ecx
  bool v37; // zf
  const char *v38; // eax
  vostok::fixed_string<260> *shader_name; // eax
  vostok::memory::doug_lea_allocator *v40; // esi
  char *v41; // eax
  vostok::memory::doug_lea_allocator *v42; // ecx
  vostok::strings::shared::profile *v43; // ecx
  char *v44; // eax
  vostok::fixed_string<260> *v45; // eax
  char *v46; // eax
  char *m_begin; // ecx
  vostok::fixed_string<260> *v48; // eax
  vostok::memory::doug_lea_allocator *v49; // esi
  char *v50; // eax
  vostok::memory::doug_lea_allocator *v51; // ecx
  vostok::strings::shared::profile *v52; // ecx
  char *v53; // eax
  vostok::fixed_string<260> *v54; // eax
  char *v55; // eax
  char *v56; // ecx
  vostok::fixed_string<260> *v57; // eax
  vostok::memory::doug_lea_allocator *v58; // esi
  char *v59; // eax
  vostok::memory::doug_lea_allocator *v60; // ecx
  vostok::strings::shared::profile *v61; // ecx
  char *v62; // eax
  vostok::fixed_string<260> *v63; // eax
  char *v64; // eax
  char *v65; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v66; // ecx
  vostok::render::effect_compiler *v67; // ecx
  char *v68; // esi
  vostok::memory::doug_lea_allocator *v69; // edi
  vostok::memory::doug_lea_allocator *v70; // ecx
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> v71; // [esp-8h] [ebp-6F98h] BYREF
  vostok::render::enum_shader_type v72; // [esp-4h] [ebp-6F94h]
  const char *v73; // [esp+0h] [ebp-6F90h] BYREF
  const char *v74; // [esp+4h] [ebp-6F8Ch]
  unsigned int v75; // [esp+8h] [ebp-6F88h]
  char *v76; // [esp+Ch] [ebp-6F84h] BYREF
  char *v77; // [esp+10h] [ebp-6F80h]
  _BYTE v78[272]; // [esp+6E18h] [ebp-178h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v79; // [esp+6F28h] [ebp-68h] BYREF
  _DWORD v80[5]; // [esp+6F48h] [ebp-48h] BYREF
  const vostok::variant<32> *const *v81; // [esp+6F5Ch] [ebp-34h]
  vostok::render::effect_cook *v82; // [esp+6F60h] [ebp-30h]
  unsigned int v83; // [esp+6F64h] [ebp-2Ch]
  vostok::render::effect_compile_data *v84; // [esp+6F68h] [ebp-28h] BYREF
  char *v85; // [esp+6F6Ch] [ebp-24h]
  vostok::render::res_effect *v86; // [esp+6F70h] [ebp-20h]
  char *v87; // [esp+6F74h] [ebp-1Ch]
  bool v88; // [esp+6F7Ah] [ebp-16h]
  bool v89; // [esp+6F7Bh] [ebp-15h]
  int v90; // [esp+6F7Ch] [ebp-14h]
  vostok::fixed_string<260> *v91; // [esp+6F80h] [ebp-10h]
  const char **v92; // [esp+6F88h] [ebp-8h]
  vostok::fixed_string<260> *src; // [esp+6F8Ch] [ebp-4h] BYREF

  obj_ptr = in_out_query[5].m_on_out_of_memory.functor.bound_memfunc_ptr.obj_ptr;
  v82 = this;
  v90 = 0;
  v84 = 0;
  if ( !obj_ptr
    || (vostok::variant<32>::try_get<vostok::render::effect_compile_data *>(
          (vostok::variant<32> *)this,
          (int)obj_ptr,
          &v84),
        (v3 = v84) == 0) )
  {
    v72 = enum_shader_types_count|0x8;
    v71.m_object = 0;
LABEL_4:
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      in_out_query,
      result_success,
      (const assert_on_fail_bool)v71.m_object,
      (vostok::resources::cook_base::result_enum)v72);
    return;
  }
  if ( !v84->descriptor )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                 (const char *)2),
          this = (vostok::render::effect_cook *)v72,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v79);
      v90 = 1;
      vostok::logging::append(
        &v79,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\effect_cook.cpp",
        0x140u,
        "void __thiscall vostok::render::effect_cook::translate_query(class vostok::resources::query_result_for_cook &)",
        (char *)&initiator_raw.initiator_tree,
        error,
        "No effect descriptor!");
    }
    if ( (v90 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        (int *)&v79);
    v72 = enum_shader_types_count|0x8;
    v71.m_object = (vostok::strings::shared::profile *)1;
    goto LABEL_4;
  }
  v5 = vostok::render::g_allocator;
  v6 = type_info::raw_name(&vostok::render::res_effect `RTTI Type Descriptor');
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(v7, (int)v5, 0x56B8u, v6, v73, v74, v75);
  if ( v8 )
  {
    vostok::render::res_effect::res_effect(v9, (int)v8);
    v86 = v10;
  }
  else
  {
    v86 = 0;
  }
  v11 = vostok::render::g_allocator;
  v12 = type_info::raw_name(&vostok::render::effect_compiler `RTTI Type Descriptor');
  v14 = vostok::memory::doug_lea_allocator::malloc_impl(v13, (int)v11, (unsigned int)dword_61F50, v12, v73, v74, v75);
  if ( v14 )
  {
    vostok::render::effect_compiler::effect_compiler(
      (vostok::render::effect_compiler *)v14,
      0,
      v86,
      (vostok::resources::query_result_for_cook *)in_out_query,
      1,
      1);
    v90 = (int)v15;
  }
  else
  {
    v90 = 0;
  }
  stage_index = v3->stage_index;
  if ( stage_index == 29 )
  {
    v3->descriptor->compile(
      v3->descriptor,
      (vostok::render::effect_compiler *)v90,
      vostok::quasi_singleton<vostok::render::resource_manager>::pinst->shader_name_to_mask_config.m_object->m_root,
      &v3->parameters);
  }
  else
  {
    v17 = v3->descriptor->__vftable;
    v85 = (char *)vostok::render::stage_type_to_string(stage_index);
    v19 = vostok::configs::binary_config_value::operator[](v18, "material");
    v20 = vostok::configs::binary_config_value::operator[](v19, v85);
    v21 = vostok::configs::binary_config_value::operator[](v20, "effect");
    v17->compile(v3->descriptor, (vostok::render::effect_compiler *)v90, v21, &v3->parameters);
  }
  vostok::render::effect_compiler::get_cached_shaders_info(v22, v90, &v76);
  v23 = 3 * ((v77 - v76) / 880);
  v83 = v23;
  if ( v76 != v77 )
  {
    v24 = v76 + 556;
    do
    {
      if ( *(v24 - 69) == *(v24 - 70) )
        --v23;
      if ( *(v24 - 138) == *(v24 - 139) )
        --v23;
      if ( *v24 == *(v24 - 1) )
        --v23;
      v24 += 220;
    }
    while ( v24 - 139 != (_DWORD *)v77 );
    v83 = v23;
  }
  max_requests -= max_requests < v23 ? max_requests - v23 : 0;
  v25 = alloca(8 * v23);
  v85 = (char *)&v73;
  v26 = alloca(48 * v23);
  v92 = &v73;
  v27 = alloca(4 * v23);
  v81 = (const vostok::variant<32> *const *)&v73;
  v28 = alloca(276 * v23);
  src = (vostok::fixed_string<260> *)&v73;
  v91 = (vostok::fixed_string<260> *)&v73;
  v29 = 0;
  if ( v23 )
  {
    v30 = (int)v92;
    do
    {
      if ( v30 )
      {
        *(_DWORD *)(v30 + 40) = 0;
        *(_DWORD *)(v30 + 44) = 0;
        v31 = (const char *)v30;
      }
      else
      {
        v31 = 0;
      }
      (&v73)[v29++] = v31;
      v30 += 48;
    }
    while ( v29 < v23 );
    do
    {
      v32 = (int)v91;
      v91 = (vostok::fixed_string<260> *)((char *)v91 + 276);
      if ( v32 )
        vostok::fs_new::virtual_path_string::virtual_path_string((vostok::fs_new::virtual_path_string *)v30, v32);
      --v23;
    }
    while ( v23 );
  }
  s_efc_size += 1024;
  ++effects_count;
  if ( v76 != v77 )
  {
    v33 = src;
    v87 = v85;
    v91 = src;
    v34 = (int *)(v76 + 280);
    do
    {
      v35 = *v34;
      v36 = (const char *)*(v34 - 69);
      v88 = v34[69] != v34[68];
      v37 = v35 == *(v34 - 1);
      v38 = (const char *)*(v34 - 70);
      v89 = !v37;
      if ( v36 != v38 )
      {
        shader_name = vostok::render::make_shader_name(
                        (vostok::buffer_string *)v34 + 46,
                        (int)v78,
                        v38,
                        enum_shader_type_vertex);
        vostok::fixed_string<260>::operator=(shader_name, v33);
        v40 = vostok::render::g_allocator;
        v41 = type_info::raw_name(&vostok::render::binary_shader_cook_data `RTTI Type Descriptor');
        src = (vostok::fixed_string<260> *)vostok::memory::doug_lea_allocator::malloc_impl(
                                             v42,
                                             (int)v40,
                                             0x20u,
                                             v41,
                                             v73,
                                             v74,
                                             v75);
        if ( src )
        {
          v44 = (char *)*(v34 - 70);
          v72 = enum_shader_type_vertex;
          v71.m_object = v43;
          vostok::shared_string::shared_string((vostok::shared_string *)v43, &v71, v44);
          vostok::render::binary_shader_cook_data::binary_shader_cook_data(
            v86,
            (vostok::render::binary_shader_cook_data *)src,
            *(vostok::render::shader_configuration *)(v34 + 138),
            (vostok::shared_string)v71.m_object,
            v72,
            (bool)v73);
          v33 = v91;
          src = v45;
        }
        else
        {
          src = 0;
        }
        vostok::variant<32>::set<vostok::render::binary_shader_cook_data *>(
          (vostok::variant<32> *)v43,
          (int)v92,
          (vostok::render::binary_shader_cook_data **)&src);
        v46 = v87;
        m_begin = v33->m_begin;
        v92 += 12;
        *(_DWORD *)v87 = m_begin;
        *((_DWORD *)v46 + 1) = 12;
        v33 = (vostok::fixed_string<260> *)((char *)v33 + 276);
        v87 = v46 + 8;
        v91 = v33;
      }
      if ( v88 )
      {
        v48 = vostok::render::make_shader_name(
                (vostok::buffer_string *)(v34 + 146),
                (int)v78,
                (const char *)v34[68],
                enum_shader_type_geometry);
        vostok::fixed_string<260>::operator=(v48, v33);
        v49 = vostok::render::g_allocator;
        v50 = type_info::raw_name(&vostok::render::binary_shader_cook_data `RTTI Type Descriptor');
        src = (vostok::fixed_string<260> *)vostok::memory::doug_lea_allocator::malloc_impl(
                                             v51,
                                             (int)v49,
                                             0x20u,
                                             v50,
                                             v73,
                                             v74,
                                             v75);
        if ( src )
        {
          v53 = (char *)v34[68];
          v72 = enum_shader_type_geometry;
          v71.m_object = v52;
          vostok::shared_string::shared_string((vostok::shared_string *)v52, &v71, v53);
          vostok::render::binary_shader_cook_data::binary_shader_cook_data(
            v86,
            (vostok::render::binary_shader_cook_data *)src,
            *(vostok::render::shader_configuration *)(v34 + 146),
            (vostok::shared_string)v71.m_object,
            v72,
            (bool)v73);
          v33 = v91;
          src = v54;
        }
        else
        {
          src = 0;
        }
        vostok::variant<32>::set<vostok::render::binary_shader_cook_data *>(
          (vostok::variant<32> *)v52,
          (int)v92,
          (vostok::render::binary_shader_cook_data **)&src);
        v55 = v87;
        v56 = v33->m_begin;
        v92 += 12;
        *(_DWORD *)v87 = v56;
        *((_DWORD *)v55 + 1) = 12;
        v33 = (vostok::fixed_string<260> *)((char *)v33 + 276);
        v87 = v55 + 8;
        v91 = v33;
      }
      if ( v89 )
      {
        v57 = vostok::render::make_shader_name(
                (vostok::buffer_string *)(v34 + 142),
                (int)v78,
                (const char *)*(v34 - 1),
                enum_shader_type_pixel);
        vostok::fixed_string<260>::operator=(v57, v33);
        v58 = vostok::render::g_allocator;
        v59 = type_info::raw_name(&vostok::render::binary_shader_cook_data `RTTI Type Descriptor');
        src = (vostok::fixed_string<260> *)vostok::memory::doug_lea_allocator::malloc_impl(
                                             v60,
                                             (int)v58,
                                             0x20u,
                                             v59,
                                             v73,
                                             v74,
                                             v75);
        if ( src )
        {
          v62 = (char *)*(v34 - 1);
          v72 = enum_shader_type_pixel;
          v71.m_object = v61;
          vostok::shared_string::shared_string((vostok::shared_string *)v61, &v71, v62);
          vostok::render::binary_shader_cook_data::binary_shader_cook_data(
            v86,
            (vostok::render::binary_shader_cook_data *)src,
            *(vostok::render::shader_configuration *)(v34 + 142),
            (vostok::shared_string)v71.m_object,
            v72,
            (bool)v73);
          v33 = v91;
          src = v63;
        }
        else
        {
          src = 0;
        }
        vostok::variant<32>::set<vostok::render::binary_shader_cook_data *>(
          (vostok::variant<32> *)v61,
          (int)v92,
          (vostok::render::binary_shader_cook_data **)&src);
        v64 = v87;
        v65 = v33->m_begin;
        v92 += 12;
        *(_DWORD *)v87 = v65;
        *((_DWORD *)v64 + 1) = 12;
        v33 = (vostok::fixed_string<260> *)((char *)v33 + 276);
        v87 = v64 + 8;
        v91 = v33;
      }
      v34 += 220;
    }
    while ( v34 - 70 != (int *)v77 );
    v3 = v84;
  }
  v79.functor.vostok_pointer_size_alignment[1] = vostok::render::effect_cook::on_binary_shaders;
  *((_QWORD *)&v79.functor.data + 1) = __PAIR64__((unsigned int)in_out_query, (unsigned int)v82);
  *((_QWORD *)&v79.functor.data + 2) = __PAIR64__((unsigned int)v3, (unsigned int)v86);
  v72 = (vostok::render::enum_shader_type)v80;
  qmemcpy(v80, (char *)&v79.functor.bound_memfunc_ptr.memfunc_ptr + 4, sizeof(v80));
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v79.vtable = 0;
  }
  else
  {
    qmemcpy((void *)&v79.functor, v80, 0x14u);
    v79.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::effect_cook,vostok::resources::query_result_for_cook *,vostok::render::res_effect *,vostok::render::effect_compile_data *,vostok::resources::queries_result &>,boost::_bi::list5<boost::_bi::value<vostok::render::effect_cook *>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::render::res_effect *>,boost::_bi::value<vostok::render::effect_compile_data *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  vostok::resources::query_resources(
    (const vostok::resources::request *)v85,
    v83,
    (vostok::memory::base_allocator *)(&in_out_query[7].m_on_out_of_memory.vtable)[1],
    v81,
    (const vostok::variant<32> **)in_out_query,
    assert_on_fail_false);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v66,
    (int *)&v79);
  v68 = (char *)v90;
  v69 = vostok::render::g_allocator;
  if ( v90 )
  {
    vostok::render::effect_compiler::~effect_compiler(v67, (_DWORD *)v90);
    vostok::memory::doug_lea_allocator::free_impl(v70, (int)v69, v68, v73, v74, v75);
  }
}
