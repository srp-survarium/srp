void __thiscall vostok::render::texture_gpu_converter_cook::create_resource(
        vostok::render::texture_gpu_converter_cook *this,
        vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *in_out_query,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  float z; // eax
  LARGE_INTEGER QPC; // rax
  vostok::resources::managed_resource *v6; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v7; // ecx
  const char *v8; // esi
  int v9; // eax
  int v10; // eax
  vostok::render::res_texture *v11; // ecx
  bool has_passed_filters; // al
  vostok::render::resource_manager *v13; // ecx
  vostok::render::res_texture *v14; // ecx
  unsigned int v15; // eax
  bool v16; // zf
  unsigned int v17; // ebx
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **v18; // eax
  char *v19; // edi
  dds_header *v20; // eax
  vostok::resources::query_result_for_cook *v21; // esi
  vostok::resources::unmanaged_resource *v22; // ecx
  _DWORD *v23; // esi
  int v24; // eax
  unsigned int m_object; // eax
  vostok::memory::doug_lea_allocator *v26; // esi
  char *v27; // eax
  vostok::memory::doug_lea_allocator *v28; // ecx
  char *v29; // eax
  int v30; // ebx
  int v31; // esi
  char v32; // al
  vostok::memory::doug_lea_allocator *v33; // edi
  char *v34; // eax
  vostok::memory::doug_lea_allocator *v35; // ecx
  unsigned int i; // eax
  _DWORD *v37; // ecx
  vostok::timing::timer *v38; // ecx
  double elapsed_sec; // st7
  float v40; // eax
  vostok::render::texture_gpu_converter_cook *v41; // ecx
  int *v42; // edi
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v43; // eax
  vostok::render::res_geometry *geometry; // eax
  vostok::shared_string *v45; // ecx
  vostok::render::backend *v46; // ecx
  vostok::render::shader_constant_host *v47; // eax
  vostok::render::res_texture *v48; // eax
  bool v49; // [esp-4h] [ebp-98h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v50; // [esp+0h] [ebp-94h] BYREF
  const char *v51; // [esp+4h] [ebp-90h]
  const char *v52; // [esp+8h] [ebp-8Ch]
  unsigned int v53; // [esp+Ch] [ebp-88h]
  DXGI_FORMAT v54; // [esp+14h] [ebp-80h]
  bool is_additional_buffer[4]; // [esp+18h] [ebp-7Ch]
  vostok::render::texture_gpu_converter_cook *v56; // [esp+1Ch] [ebp-78h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> object; // [esp+20h] [ebp-74h] BYREF
  vostok::shared_string name; // [esp+24h] [ebp-70h] BYREF
  int v59; // [esp+28h] [ebp-6Ch]
  int v60; // [esp+2Ch] [ebp-68h]
  DXGI_FORMAT v61; // [esp+30h] [ebp-64h]
  _DWORD data[2]; // [esp+34h] [ebp-60h] BYREF
  __int16 v63; // [esp+3Ch] [ebp-58h]
  __int16 v64; // [esp+3Eh] [ebp-56h]
  char v65; // [esp+40h] [ebp-54h]
  bool v66; // [esp+44h] [ebp-50h]
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_data; // [esp+48h] [ebp-4Ch]
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **p_m_screen_vertex_ib; // [esp+4Ch] [ebp-48h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr; // [esp+50h] [ebp-44h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> decl_size; // [esp+5Ch] [ebp-38h] BYREF
  int v71; // [esp+7Ch] [ebp-18h]
  int v72; // [esp+80h] [ebp-14h]
  int v73; // [esp+84h] [ebp-10h]
  int v74; // [esp+88h] [ebp-Ch]
  int v75; // [esp+8Ch] [ebp-8h]
  int v76; // [esp+90h] [ebp-4h]

  v56 = this;
  v60 = 0;
  if ( !this->m_screen_vertex_geometry.m_object )
  {
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7392) = 0;
    *(_DWORD *)(LODWORD(z) + 7396) = 0;
    *(_DWORD *)(LODWORD(z) + 7408) = 0;
  }
  vostok::timing::timer::timer((vostok::timing::timer *)this, (LARGE_INTEGER *)&decl_size);
  QPC = vostok::timing::get_QPC();
  v50.m_object = v6;
  decl_size.vtable = 0;
  (&decl_size.vtable)[1] = 0;
  *(LARGE_INTEGER *)&decl_size.functor.obj_ptr = QPC;
  m_data = (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)raw_file_data.m_data;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v50,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)raw_file_data.m_data
  + 1);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v7,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&ptr,
    v50);
  v8 = (const char *)*((_DWORD *)raw_file_data.m_data + 141);
  if ( vostok::strings::compare(v8, "DXT1") )
    v54 = vostok::strings::compare(v8, "DXT5") != 0 ? DXGI_FORMAT_BC1_UNORM : DXGI_FORMAT_BC3_UNORM;
  else
    v54 = DXGI_FORMAT_BC1_UNORM;
  v9 = *((_DWORD *)raw_file_data.m_data + 212);
  LOBYTE(v61) = v9 == 3;
  v66 = v9 == 2;
  v10 = vostok::strings::compare(v8, "NORMAL_MAP");
  v65 = v10 == 0;
  if ( !v10 )
    v54 = DXGI_FORMAT_BC3_UNORM;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &object,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)raw_file_data.m_data
  + 2);
  if ( object.m_object )
  {
    name.m_pointer.m_object = (vostok::strings::shared::profile *)vostok::render::res_texture::width(
                                                                    v11,
                                                                    (int)object.m_object);
    v15 = vostok::render::res_texture::height(v14, (int)object.m_object);
    v16 = *((_BYTE *)raw_file_data.m_data + 857) == 0;
    *(_DWORD *)is_additional_buffer = v15;
    if ( v16 )
    {
      v59 = 1;
      v17 = 1;
    }
    else
    {
      p_m_screen_vertex_ib = (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)((v15 >> 2) + ((unsigned int)name.m_pointer.m_object >> 2 < v15 >> 2 ? ((unsigned int)name.m_pointer.m_object >> 2) - (v15 >> 2) : 0));
      v17 = (unsigned __int64)(__FYL2X__((double)(unsigned int)p_m_screen_vertex_ib, 0.6931471805599453094)
                             / __FYL2X__(2.0, 0.6931471805599453094))
          + 1;
      v59 = v17;
    }
    v18 = (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)vostok::render::calc_dds_body_size(v17, *(unsigned int *)is_additional_buffer, v54);
    v19 = (char *)v18 + 129;
    p_m_screen_vertex_ib = v18;
    v20 = (dds_header *)vostok::render::texture_compressor_allocate((unsigned int)v18 + 129, v49);
    v21 = (vostok::resources::query_result_for_cook *)v56->__vftable;
    v60 = (int)v20;
    v22 = *(vostok::resources::unmanaged_resource **)((int (__thiscall *)(vostok::render::texture_gpu_converter_cook *, _DWORD *, vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *, _DWORD, int, _DWORD))v21->m_uid)(
                                                       v56,
                                                       data,
                                                       in_out_query,
                                                       0,
                                                       272,
                                                       0);
    v23 = &v22->__vftable;
    if ( v22 )
    {
      vostok::resources::unmanaged_resource::unmanaged_resource(v22, v22, fs_iterator_class);
      v24 = v60;
      *v23 = &vostok::render::block_compressed_file_data::`vftable';
      v23[66] = v24;
      v23[67] = v19;
      data[0] = v23;
    }
    else
    {
      data[0] = 0;
    }
    m_object = *(_DWORD *)is_additional_buffer;
    if ( !(_BYTE)v61 )
      m_object = (unsigned int)name.m_pointer.m_object;
    vostok::render::fill_dds_header(
      (dds_header *)v60,
      m_object,
      *(unsigned int *)is_additional_buffer,
      (int)(v19 - 128),
      v54,
      v65,
      v61,
      v66,
      v17);
    v26 = vostok::render::g_allocator;
    v27 = type_info::raw_name(&vostok::render::compress_temp_data `RTTI Type Descriptor');
    v29 = vostok::memory::doug_lea_allocator::malloc_impl(v28, (int)v26, 0x30u, v27, v51, v52, v53);
    if ( v29 )
    {
      *((_DWORD *)v29 + 3) = m_data;
      v30 = (int)v29;
    }
    else
    {
      v30 = 0;
    }
    v31 = v59;
    *(_DWORD *)v30 = in_out_query;
    *(_DWORD *)(v30 + 4) = data[0];
    *(_DWORD *)(v30 + 28) = v54;
    *(vostok::shared_string *)(v30 + 32) = name;
    *(_DWORD *)(v30 + 36) = *(_DWORD *)is_additional_buffer;
    *(_DWORD *)(v30 + 24) = p_m_screen_vertex_ib;
    *(_DWORD *)(v30 + 16) = v60;
    v32 = v65;
    *(_DWORD *)(v30 + 20) = v19;
    v33 = vostok::render::g_allocator;
    *(_DWORD *)(v30 + 40) = v31;
    *(_BYTE *)(v30 + 44) = v32;
    v34 = type_info::raw_name(&vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> `RTTI Type Descriptor');
    *(_DWORD *)(v30 + 8) = vostok::memory::doug_lea_allocator::malloc_impl(v35, (int)v33, 4 * v31, v34, v51, v52, v53);
    for ( i = 0; i < *(_DWORD *)(v30 + 40); ++i )
    {
      v37 = (_DWORD *)(*(_DWORD *)(v30 + 8) + 4 * i);
      if ( v37 )
        *v37 = 0;
    }
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      &object,
      *(vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(v30 + 8));
    elapsed_sec = vostok::timing::timer::get_elapsed_sec(v38, (int)&decl_size);
    v40 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    v41 = (vostok::render::texture_gpu_converter_cook *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                                       + 7392);
    *(float *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7392) = elapsed_sec + *(float *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7392);
    ++*(_DWORD *)(LODWORD(v40) + 7408);
    m_data = &v56->m_screen_vertex_geometry;
    if ( !v56->m_screen_vertex_geometry.m_object )
    {
      v72 = 16;
      v74 = 16;
      data[0] = 0x10000;
      data[1] = 196610;
      v63 = 2;
      v64 = 1;
      p_m_screen_vertex_ib = (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&v56->m_screen_vertex_ib;
      decl_size.vtable = (boost::detail::function::vtable_base *)"POSITION";
      (&decl_size.vtable)[1] = 0;
      *(_QWORD *)&decl_size.functor.obj_ptr = 2;
      memset(&decl_size.functor.data + 8, 0, 12);
      decl_size.functor.vostok_pointer_size_alignment[5] = "TEXCOORD";
      v71 = 0;
      v73 = 0;
      v75 = 0;
      v76 = 0;
      vostok::render::resource_manager::create_buffer(
        0xCu,
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (void *)2,
        (vostok::render::enum_buffer_type)data,
        1,
        0,
        0);
      v42 = (int *)p_m_screen_vertex_ib;
      vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        v43,
        p_m_screen_vertex_ib,
        0);
      geometry = vostok::render::resource_manager::create_geometry(
                   *(vostok::render::resource_manager **)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                                        + 44),
                   (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                   (const D3D11_INPUT_ELEMENT_DESC *)&decl_size,
                   2u,
                   (vostok::render::untyped_buffer *)0x18,
                   *(vostok::render::untyped_buffer **)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                                      + 44),
                   *v42);
      vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        m_data,
        geometry);
      vostok::shared_string::shared_string(v45, &name.m_pointer, "base_texture_read_offset_and_scale");
      v47 = vostok::render::backend::register_constant_host(
              v46,
              SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
              &name,
              0);
      v16 = name.m_pointer.m_object == 0;
      v41 = v56;
      v56->m_c_base_texture_read_offset_and_scale = v47;
      if ( !v16 )
      {
        v41 = (vostok::render::texture_gpu_converter_cook *)_InterlockedExchangeAdd(
                                                              &name.m_pointer.m_object->m_reference_count,
                                                              0xFFFFFFFF);
        if ( !v41 )
          vostok::strings::shared::detail::intrusive_base::destroy(
            0,
            (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
      }
    }
    vostok::render::texture_gpu_converter_cook::compress(v41, (vostok::render::compress_temp_data *)v56, v30);
    v48 = object.m_object;
    v16 = object.m_object->m_reference_count-- == 1;
    if ( v16 )
      vostok::render::resource_manager::release(
        v13,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v48);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"render_pc_dx11",
                                 (const char *)2),
          v11 = (vostok::render::res_texture *)v50.m_object,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v11,
        &decl_size);
      v60 = 1;
      vostok::logging::append(
        &decl_size,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\texture_gpu_converter_cook.cpp",
        0x2C0u,
        "void __thiscall vostok::render::texture_gpu_converter_cook::create_resource(class vostok::resources::query_resul"
        "t_for_cook &,class vostok::const_buffer,class vostok::mutable_buffer)",
        "render_pc_dx11",
        error,
        "texture_gpu_converter_cook: base_pixels_texture is null! ");
    }
    if ( (v60 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
        (int *)&decl_size);
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)v11,
      in_out_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>((vostok::resources::pinned_ptr_const<unsigned char> *)v13);
}
