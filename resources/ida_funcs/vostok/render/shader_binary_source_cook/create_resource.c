void __thiscall vostok::render::shader_binary_source_cook::create_resource(
        vostok::render::shader_binary_source_cook *this,
        vostok::resources::query_result_for_cook *in_out_query,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::resources::query_result_for_cook *v4; // ecx
  vostok::sound::encoded_sound_interface *v5; // ebx
  char *m_data; // eax
  vostok::render::grass_render_model *m_object; // ecx
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *v9; // esi
  unsigned int type; // eax
  const char *v11; // eax
  vostok::render::binary_shader_source *v12; // ecx
  int v13; // eax
  vostok::configs::binary_config_value *v14; // esi
  char *m_begin; // ecx
  unsigned int v16; // eax
  const char *v17; // eax
  vostok::configs::binary_config_value *v18; // eax
  unsigned int v19; // eax
  const char *v20; // eax
  vostok::configs::binary_config_value *v21; // eax
  const vostok::configs::binary_config_value *v22; // eax
  const vostok::configs::binary_config_value *v23; // edx
  vostok::fixed_string<256> *p_definition; // edi
  const char **pointer; // esi
  int v26; // ebx
  vostok::render::shader_macro *v27; // eax
  vostok::render::shader_macro *i; // edx
  char *v29; // esi
  int v30; // edi
  unsigned __int8 *v31; // edi
  unsigned int v32; // edi
  unsigned int v33; // eax
  vostok::memory::base_allocator *m_user_allocator; // esi
  void (__cdecl *v35)(__int64 *, __int64 *, int); // eax
  void (__cdecl *v36)(_QWORD *, _QWORD *, int); // eax
  vostok::render::shader_configuration v37; // [esp-Ch] [ebp-1130Ch]
  unsigned __int8 *v38; // [esp-8h] [ebp-11308h]
  const char *v39; // [esp-4h] [ebp-11304h]
  const char *v40; // [esp-4h] [ebp-11304h]
  vostok::sound::encoded_sound_interface *v41; // [esp+10h] [ebp-112F0h]
  __int64 v42; // [esp+14h] [ebp-112ECh]
  __int64 v43; // [esp+14h] [ebp-112ECh]
  unsigned __int64 m_reconstruction_info_actuality_tick; // [esp+1Ch] [ebp-112E4h]
  int v45; // [esp+24h] [ebp-112DCh]
  vostok::render::shader_macro *m_end; // [esp+28h] [ebp-112D8h]
  char *s; // [esp+30h] [ebp-112D0h] BYREF
  const vostok::configs::binary_config_value *v49; // [esp+34h] [ebp-112CCh]
  char *v50; // [esp+38h] [ebp-112C8h]
  __int64 v51; // [esp+40h] [ebp-112C0h] BYREF
  __int64 v52; // [esp+48h] [ebp-112B8h]
  __int64 v53; // [esp+50h] [ebp-112B0h]
  _DWORD v54[6]; // [esp+58h] [ebp-112A8h] BYREF
  unsigned int v55; // [esp+70h] [ebp-11290h]
  _QWORD v56[3]; // [esp+78h] [ebp-11288h] BYREF
  vostok::memory::base_allocator *v57; // [esp+90h] [ebp-11270h]
  int v58; // [esp+94h] [ebp-1126Ch]
  int v59; // [esp+98h] [ebp-11268h]
  int v60; // [esp+9Ch] [ebp-11264h]
  vostok::resources::query_result_for_cook *v61; // [esp+A0h] [ebp-11260h]
  int v62; // [esp+A4h] [ebp-1125Ch]
  int v63; // [esp+A8h] [ebp-11258h]
  int v64; // [esp+ACh] [ebp-11254h]
  int v65; // [esp+B0h] [ebp-11250h]
  int v66; // [esp+B4h] [ebp-1124Ch]
  int v67; // [esp+B8h] [ebp-11248h]
  int v68; // [esp+BCh] [ebp-11244h]
  int v69; // [esp+C0h] [ebp-11240h]
  vostok::fs_new::path_string_impl v70; // [esp+C8h] [ebp-11238h] BYREF
  unsigned __int8 *src; // [esp+1E0h] [ebp-11120h]
  unsigned __int8 *v72; // [esp+1E4h] [ebp-1111Ch]
  char *v73; // [esp+1E8h] [ebp-11118h]
  unsigned __int8 dst[260]; // [esp+1ECh] [ebp-11114h] BYREF
  char v75; // [esp+2F0h] [ebp-11010h] BYREF
  vostok::fixed_vector<vostok::render::shader_macro,128> out_defines; // [esp+2F8h] [ebp-11008h] BYREF

  v5 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&raw_file_data);
  v41 = v5;
  if ( *(&v5->m_reconstruction_size + 1) == v5->m_reconstruction_size )
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      v4,
      result_error,
      assert_on_fail_false,
      error_type_cook_failed);
    m_data = in_out_unmanaged_resource_buffer.m_data;
    m_object = vostok::render::g_allocator.m_object;
    if ( in_out_unmanaged_resource_buffer.m_data )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, m_data);
      m_object = vostok::render::g_allocator.m_object;
    }
    if ( v5 )
    {
      v9 = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v9, v5);
    }
  }
  else
  {
    v70.m_string.m_max_end = &v70.m_separator;
    v70.m_string.m_begin = v70.m_string.m_buffer;
    v70.m_string.m_end = v70.m_string.m_buffer;
    v70.m_string.m_buffer[0] = 0;
    v70.m_separator = 47;
    type = v5[1].type;
    if ( type )
    {
      if ( type == 1 )
        v11 = "ps";
      else
        v11 = "gs";
    }
    else
    {
      v11 = "vs";
    }
    vostok::fs_new::path_string_impl::assignf(
      &v70,
      (const char *)&stru_984D24,
      "resources/shaders/sm_4_0",
      v5->m_reconstruction_size,
      v11);
    if ( in_out_unmanaged_resource_buffer.m_data )
    {
      vostok::render::binary_shader_source::binary_shader_source(v12, (int)in_out_unmanaged_resource_buffer.m_data);
      v45 = v13;
    }
    else
    {
      v45 = 0;
    }
    out_defines.m_end = (vostok::render::shader_macro *)out_defines.m_buffer;
    out_defines.m_begin = (vostok::render::shader_macro *)out_defines.m_buffer;
    v42 = *(_QWORD *)&v5->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
    m_reconstruction_info_actuality_tick = v5->m_reconstruction_info_actuality_tick;
    out_defines.m_end = (vostok::render::shader_macro *)out_defines.m_buffer;
    vostok::render::options::fill_global_macros((vostok::render::options *)out_defines.m_buffer, &out_defines);
    *(_DWORD *)&v37.0 = HIDWORD(v42);
    *(unsigned __int64 *)((char *)v37.configuration + 4) = m_reconstruction_info_actuality_tick;
    vostok::render::shader_macros::fill_shader_configuration_macros(
      (vostok::render::shader_macros *)v42,
      &out_defines,
      v37);
    v14 = *(vostok::configs::binary_config_value **)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][1].m_type
                                                   + 264);
    if ( vostok::configs::binary_config_value::value_exists(v14, (const char *)v5->m_reconstruction_size)
      && ((v16 = v5[1].type) == 0 ? (v17 = "vs") : v16 == 1 ? (v17 = "ps") : (v17 = "gs"),
          v39 = v17,
          v18 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          v14,
                                                          (const char *)v5->m_reconstruction_size),
          vostok::configs::binary_config_value::value_exists(v18, v39)) )
    {
      v19 = v5[1].type;
      if ( v19 )
      {
        if ( v19 == 1 )
          v20 = "ps";
        else
          v20 = "gs";
      }
      else
      {
        v20 = "vs";
      }
      v40 = v20;
      v21 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      v14,
                                                      (const char *)v5->m_reconstruction_size);
      v22 = vostok::configs::binary_config_value::operator[](v21, v40);
      m_begin = (char *)out_defines.m_begin;
      v23 = v22;
      v49 = v22;
      m_end = out_defines.m_end;
      if ( out_defines.m_begin != out_defines.m_end )
      {
        p_definition = &out_defines.m_begin->definition;
        while ( 1 )
        {
          pointer = (const char **)v23->data.pointer;
          v26 = (int)v23->data.pointer + 24 * v23->count;
          if ( p_definition->m_end != p_definition->m_begin )
          {
            if ( pointer == (const char **)v26 )
            {
LABEL_33:
              *v70.m_string.m_end++ = asc_95ACF4[0];
              *v70.m_string.m_end = 0;
            }
            else
            {
              while ( strcmp(*(const char **)&p_definition[-2].m_buffer[248], *pointer) )
              {
                pointer += 6;
                if ( pointer == (const char **)v26 )
                  goto LABEL_33;
              }
              s = p_definition->m_begin;
              vostok::fs_new::path_string_impl::append<char const *>((vostok::fs_new::virtual_path_string *)&v70, &s);
            }
          }
          p_definition = (vostok::fixed_string<256> *)((char *)p_definition + 544);
          m_begin = &p_definition[-2].m_buffer[248];
          if ( &p_definition[-2].m_buffer[248] == (char *)m_end )
            break;
          v23 = v49;
        }
      }
    }
    else
    {
      v27 = out_defines.m_begin;
      for ( i = out_defines.m_end; v27 != i; *m_begin = 0 )
      {
        *v70.m_string.m_end = asc_95ACF4[0];
        m_begin = v70.m_string.m_end + 1;
        ++v27;
        v70.m_string.m_end = m_begin;
      }
    }
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)m_begin,
      result_postponed,
      assert_on_fail_true,
      error_type_unset);
    v54[0] = v70.m_string.m_begin;
    v54[1] = 3;
    v29 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(
                    (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                    0x128u);
    if ( v29 )
    {
      src = dst;
      v30 = v70.m_string.m_end - v70.m_string.m_begin;
      v72 = dst;
      v73 = &v75;
      memcpy(dst, (unsigned __int8 *)v70.m_string.m_begin, v70.m_string.m_end - v70.m_string.m_begin);
      v72 += v30;
      *v72 = 0;
      v31 = v72;
      *((_DWORD *)v29 + 1) = v41;
      *(_DWORD *)v29 = in_out_query;
      *((_DWORD *)v29 + 2) = v45;
      *((_DWORD *)v29 + 5) = v29 + 284;
      v32 = v31 - src;
      v38 = src;
      v75 = 47;
      *((_DWORD *)v29 + 3) = v29 + 24;
      *((_DWORD *)v29 + 4) = v29 + 24;
      memcpy((unsigned __int8 *)v29 + 24, v38, v32);
      *((_DWORD *)v29 + 4) += v32;
      **((_BYTE **)v29 + 4) = 0;
      v29[284] = 47;
    }
    else
    {
      v29 = 0;
    }
    LODWORD(v43) = vostok::render::shader_binary_source_cook::converted_shader_loaded;
    HIDWORD(v43) = this;
    if ( survarium::generate_shaders_world::is_loading() )
    {
      v33 = 0;
    }
    else
    {
      v51 = v43;
      LODWORD(v52) = v29;
      v33 = (unsigned int)&stru_984D24.m_available_macros.m_buffer[1] + 1;
    }
    m_user_allocator = in_out_query->m_user_allocator;
    v50 = (char *)v33;
    v54[2] = v54;
    v54[3] = 0;
    v54[4] = 1;
    v55 = 0;
    if ( v33 )
    {
      v55 = v33;
      if ( (v33 & 1) != 0 )
      {
        v56[0] = v51;
        v56[1] = v52;
        v56[2] = v53;
      }
      else
      {
        (*(void (__cdecl **)(__int64 *, _QWORD *, _DWORD))(v33 & 0xFFFFFFFE))(&v51, v56, 0);
        v33 = (unsigned int)v50;
      }
    }
    v57 = m_user_allocator;
    v58 = 0;
    v59 = 0;
    v60 = 0;
    v61 = in_out_query;
    v62 = 0;
    v63 = 0;
    v64 = 0;
    v65 = 0;
    v66 = 0;
    v67 = 0;
    v68 = 0;
    v69 = 1;
    if ( v33 )
    {
      if ( ((unsigned __int8)v50 & 1) == 0 )
      {
        v35 = *(void (__cdecl **)(__int64 *, __int64 *, int))(v33 & 0xFFFFFFFE);
        if ( v35 )
          v35(&v51, &v51, 2);
      }
    }
    v69 = 0;
    vostok::resources::resources_manager::query_resources_impl(
      vostok::resources::g_resources_manager.m_variable,
      (const vostok::resources::query_resource_params *)vostok::resources::g_resources_manager.m_variable);
    if ( v55 )
    {
      if ( (v55 & 1) == 0 )
      {
        v36 = *(void (__cdecl **)(_QWORD *, _QWORD *, int))(v55 & 0xFFFFFFFE);
        if ( v36 )
          v36(v56, v56, 2);
      }
    }
  }
}
