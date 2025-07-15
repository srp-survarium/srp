void __thiscall vostok::render::shader_binary_source_cook::translate_query(
        vostok::render::shader_binary_source_cook *this,
        const vostok::variant<32> **in_out_query)
{
  const vostok::variant<32> *v2; // esi
  vostok::render::binary_shader_cook_data *v3; // ebx
  vostok::shared_string *v4; // ecx
  vostok::strings::shared::profile *v5; // eax
  vostok::buffer_string *v6; // ecx
  vostok::memory::doug_lea_allocator *v7; // esi
  char *v8; // eax
  vostok::memory::doug_lea_allocator *v9; // ecx
  char *v10; // eax
  vostok::render::binary_shader_source *v11; // ecx
  unsigned int *v12; // eax
  vostok::configs::binary_config_value *m_root; // esi
  vostok::strings::shared::profile *v14; // eax
  vostok::configs::binary_config_value *v15; // ecx
  vostok::buffer_string *v16; // ecx
  char *v17; // eax
  const vostok::configs::binary_config_value *v18; // eax
  vostok::configs::binary_config_value *v19; // ecx
  char *v20; // eax
  vostok::configs::binary_config_value *v21; // eax
  const vostok::configs::binary_config_value *v22; // ecx
  vostok::fixed_string<256> *p_definition; // edi
  vostok::render::binary_shader_cook_data *pointer; // eax
  vostok::render::binary_shader_cook_data *v25; // esi
  vostok::buffer_string *v26; // ecx
  vostok::render::shader_macro *v27; // edi
  vostok::memory::doug_lea_allocator *v28; // esi
  char *v29; // eax
  vostok::memory::doug_lea_allocator *v30; // ecx
  char *v31; // eax
  vostok::particle::particle_action *v32; // ecx
  char *v33; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v34; // ecx
  vostok::resources::resources_manager *v35; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v36; // ecx
  _BYTE v37[12]; // [esp-10h] [ebp-11200h] BYREF
  char *m_begin; // [esp-4h] [ebp-111F4h]
  const bool *v39; // [esp+0h] [ebp-111F0h]
  const char *v40; // [esp+4h] [ebp-111ECh]
  const char *v41; // [esp+8h] [ebp-111E8h]
  vostok::render::binary_shader_cook_data *out_value; // [esp+Ch] [ebp-111E4h] BYREF
  vostok::render::shader_macro *m_end; // [esp+10h] [ebp-111E0h]
  unsigned int *v44; // [esp+14h] [ebp-111DCh]
  const vostok::configs::binary_config_value *v45; // [esp+18h] [ebp-111D8h]
  vostok::render::shader_binary_source_cook *v46; // [esp+1Ch] [ebp-111D4h]
  vostok::resources::request v47; // [esp+20h] [ebp-111D0h] BYREF
  void (__thiscall *v48)(vostok::render::shader_binary_source_cook *, vostok::render::conveted_shader_loaded_data *, vostok::resources::queries_result *); // [esp+28h] [ebp-111C8h]
  vostok::render::shader_binary_source_cook *v49; // [esp+2Ch] [ebp-111C4h]
  char *v50; // [esp+30h] [ebp-111C0h]
  __int64 v51; // [esp+34h] [ebp-111BCh] BYREF
  char *v52; // [esp+3Ch] [ebp-111B4h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v53; // [esp+40h] [ebp-111B0h] BYREF
  vostok::fixed_string<260> v54; // [esp+60h] [ebp-11190h] BYREF
  char v55; // [esp+170h] [ebp-11080h] BYREF
  vostok::resources::query_resource_params params; // [esp+178h] [ebp-11078h] BYREF
  vostok::fixed_vector<vostok::render::shader_macro,128> macros; // [esp+1E0h] [ebp-11010h] BYREF

  v2 = in_out_query[66];
  v46 = this;
  out_value = 0;
  if ( v2
    && (vostok::variant<32>::try_get<vostok::render::binary_shader_cook_data *>(
          (vostok::variant<32> *)this,
          (int)v2,
          &out_value),
        (v3 = out_value) != 0)
    && (this = (vostok::render::shader_binary_source_cook *)&out_value->shader_name,
        out_value->shader_name.m_pointer.m_object->m_length) )
  {
    v54.m_begin = v54.m_buffer;
    v54.m_end = v54.m_buffer;
    v54.m_max_end = &v55;
    v54.m_buffer[0] = 0;
    v55 = 47;
    m_begin = (char *)vostok::render::shader_type_to_ext(out_value->shader_type);
    v5 = vostok::shared_string::c_str(v4);
    vostok::fs_new::path_string_impl::assignf(
      &v54,
      v6,
      (vostok::buffer_string *)"%s/%s.%s/",
      "resources/shaders/sm_4_0",
      v5,
      m_begin);
    v7 = vostok::render::g_allocator;
    v8 = type_info::raw_name(&vostok::render::binary_shader_source `RTTI Type Descriptor');
    v10 = vostok::memory::doug_lea_allocator::malloc_impl(
            v9,
            (int)v7,
            0x138u,
            v8,
            (const char *const)v39,
            v40,
            (const unsigned int)v41);
    if ( v10 )
    {
      vostok::render::binary_shader_source::binary_shader_source(v11, (int)v10);
      v44 = v12;
    }
    else
    {
      v44 = 0;
    }
    macros.m_begin = (vostok::render::shader_macro *)macros.m_buffer;
    macros.m_end = (vostok::render::shader_macro *)macros.m_buffer;
    macros.m_max_end = (vostok::render::shader_macro *)&v37[(_DWORD)&loc_111FB + 1];
    vostok::render::shader_macros::fill_shader_macro_list(
      (vostok::render::shader_macros *)v11,
      &macros,
      v3->configuration);
    m_root = vostok::quasi_singleton<vostok::render::resource_manager>::pinst->shader_name_to_mask_config.m_object->m_root;
    v14 = vostok::shared_string::c_str(&v3->shader_name);
    if ( vostok::configs::binary_config_value::value_exists(v15, (int)m_root, (unsigned int)v14)
      && (m_begin = (char *)vostok::render::shader_type_to_ext(v3->shader_type),
          v17 = (char *)vostok::shared_string::c_str(&v3->shader_name),
          v18 = vostok::configs::binary_config_value::operator[](m_root, v17),
          vostok::configs::binary_config_value::value_exists(v19, (int)v18, (unsigned int)m_begin)) )
    {
      out_value = (vostok::render::binary_shader_cook_data *)vostok::render::shader_type_to_ext(v3->shader_type);
      v20 = (char *)vostok::shared_string::c_str(&v3->shader_name);
      v21 = vostok::configs::binary_config_value::operator[](m_root, v20);
      v22 = vostok::configs::binary_config_value::operator[](v21, (char *)out_value);
      v45 = v22;
      m_end = macros.m_end;
      if ( macros.m_begin != macros.m_end )
      {
        p_definition = &macros.m_begin->definition;
        while ( 1 )
        {
          pointer = (vostok::render::binary_shader_cook_data *)v22->data.pointer;
          v25 = (vostok::render::binary_shader_cook_data *)((char *)v22->data.pointer + 24 * v22->count);
          v26 = (vostok::buffer_string *)(p_definition->m_end - p_definition->m_begin);
          out_value = pointer;
          if ( v26 )
          {
            if ( pointer == v25 )
            {
LABEL_14:
              m_begin = "_";
            }
            else
            {
              while ( vostok::strings::compare(
                        *(const char **)&p_definition[-2].m_buffer[248],
                        *(const char **)&pointer->configuration.0) )
              {
                out_value = (vostok::render::binary_shader_cook_data *)((char *)out_value + 24);
                if ( out_value == v25 )
                  goto LABEL_14;
                pointer = out_value;
              }
              m_begin = p_definition->m_begin;
            }
            vostok::buffer_string::append(v26, (int)&v54, m_begin);
          }
          p_definition = (vostok::fixed_string<256> *)((char *)p_definition + 544);
          if ( &p_definition[-2].m_buffer[248] == (char *)m_end )
            break;
          v22 = v45;
        }
      }
    }
    else
    {
      v27 = macros.m_begin;
      for ( m_end = macros.m_end; v27 != m_end; ++v27 )
        vostok::buffer_string::append(v16, (int)&v54, "_");
    }
    v28 = vostok::render::g_allocator;
    v47.path = v54.m_begin;
    v47.id = raw_data_class;
    v29 = type_info::raw_name(&vostok::render::conveted_shader_loaded_data `RTTI Type Descriptor');
    v31 = vostok::memory::doug_lea_allocator::malloc_impl(
            v30,
            (int)v28,
            0x128u,
            v29,
            (const char *const)v39,
            v40,
            (const unsigned int)v41);
    v33 = v31;
    if ( v31 )
    {
      *((_DWORD *)v31 + 1) = in_out_query;
      *((_DWORD *)v31 + 3) = v44;
      *((_DWORD *)v31 + 2) = v3;
      vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)(v31 + 16), &v54);
      v33[288] = 47;
    }
    else
    {
      v33 = 0;
    }
    v50 = v33;
    v49 = v46;
    v48 = vostok::render::shader_binary_source_cook::converted_shader_loaded;
    LODWORD(v51) = vostok::render::shader_binary_source_cook::converted_shader_loaded;
    HIDWORD(v51) = v46;
    m_begin = (char *)&v51;
    v52 = v33;
    if ( Scaleform::Render::RenderEvent::GetListenerStatus(v32) )
    {
      v53.vtable = 0;
    }
    else
    {
      *(_QWORD *)&v53.functor.obj_ptr = v51;
      v53.functor.vostok_pointer_size_alignment[2] = v52;
      v53.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::shader_binary_source_cook,vostok::render::conveted_shader_loaded_data *,vostok::resources::queries_result &>,boost::_bi::list3<boost::_bi::value<vostok::render::shader_binary_source_cook *>,boost::_bi::value<vostok::render::conveted_shader_loaded_data *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                          + 1);
    }
    vostok::resources::query_resource_params::query_resource_params(
      &params,
      &v47,
      &v53,
      0,
      1u,
      (vostok::memory::base_allocator *)in_out_query[85],
      0,
      0,
      in_out_query,
      0,
      v39,
      (const unsigned int *)v40,
      v41,
      (unsigned int)out_value,
      (vostok::resources::query_type_enum)m_end,
      v44,
      (vostok::resources::autoselect_quality_bool *)v45,
      (assert_on_fail_bool)v46);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v34,
      (int *)&v53);
    params.assert_on_fail = assert_on_fail_false;
    vostok::resources::resources_manager::query_resources_impl(v35, &params);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v36,
      (int *)&params.callback);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)in_out_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
