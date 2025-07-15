void __thiscall vostok::render::effect_cook::on_binary_shaders(
        vostok::render::effect_cook *this,
        vostok::resources::query_result_for_cook *in_out_query,
        vostok::render::res_effect *effect_resource,
        vostok::render::effect_compile_data *compile_data,
        vostok::resources::queries_result *data)
{
  vostok::resources::queries_result *v5; // ebx
  vostok::variant<32> *p_result; // ecx
  char *m_queries; // edi
  int v8; // esi
  vostok::resources::query_result_for_user *v9; // ecx
  char *m_object; // esi
  vostok::memory::doug_lea_allocator *v11; // ecx
  vostok::particle::particle_system_instance_impl *v12; // esi
  vostok::particle::particle_system_instance_impl *v13; // ebx
  char *v14; // eax
  vostok::render::binary_shader_key_type *v15; // ecx
  vostok::render::binary_shader_key_type *v16; // ecx
  vostok::render::binary_shader_key_type *v17; // ecx
  stlp_std::priv::_Rb_tree<vostok::render::binary_shader_key_type,stlp_std::less<vostok::render::binary_shader_key_type>,stlp_std::pair<vostok::render::binary_shader_key_type const ,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> >,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::binary_shader_key_type const ,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::binary_shader_key_type const ,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> > >,vostok::render::std_allocator<stlp_std::pair<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> > > > *v18; // ecx
  vostok::memory::doug_lea_allocator *v19; // ecx
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *p_m_unmanaged_resource; // edi
  vostok::particle::particle_system_instance_impl *v21; // esi
  vostok::render::res_effect *v22; // edi
  vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> *m_end; // esi
  vostok::memory::doug_lea_allocator *v24; // esi
  char *v25; // eax
  vostok::memory::doug_lea_allocator *v26; // ecx
  char *v27; // edi
  vostok::render::effect_compiler *v28; // ebx
  vostok::render::effect_compiler *v29; // eax
  unsigned int stage_index; // eax
  vostok::configs::binary_config_value *v31; // edx
  vostok::configs::binary_config_value *v32; // eax
  vostok::configs::binary_config_value *v33; // eax
  const vostok::configs::binary_config_value *v34; // eax
  vostok::render::res_effect *v35; // ecx
  vostok::render::texture_named_instance *m_begin; // edi
  vostok::render::effect_compiler::texture_query_desc *v37; // esi
  vostok::render::effect_compiler::texture_query_desc *v38; // eax
  vostok::resources::queries_result *v39; // esi
  int v40; // eax
  void *v41; // esp
  const char **v42; // eax
  vostok::memory::doug_lea_allocator *v43; // esi
  char *v44; // eax
  vostok::memory::doug_lea_allocator *v45; // ecx
  char *v46; // eax
  char *v47; // esi
  vostok::resources::queries_result *v48; // ecx
  vostok::render::effect_compiler::texture_query_desc *v49; // eax
  vostok::render::effect_compiler::texture_query_desc *i; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v51; // ecx
  vostok::render::effect_compiler *v52; // ecx
  vostok::resources::query_result_for_cook *v53; // ecx
  vostok::resources::query_result_for_cook *v54; // ecx
  vostok::memory::doug_lea_allocator *v55; // edi
  vostok::memory::doug_lea_allocator *v56; // ecx
  vostok::render::shader_configuration v57; // [esp-14h] [ebp-418h] BYREF
  unsigned int m_first; // [esp-4h] [ebp-408h]
  const char *v59; // [esp+0h] [ebp-404h] BYREF
  const char *v60; // [esp+4h] [ebp-400h]
  unsigned int v61; // [esp+8h] [ebp-3FCh]
  char v62[296]; // [esp+Ch] [ebp-3F8h] BYREF
  vostok::render::binary_shader_key_type v63; // [esp+134h] [ebp-2D0h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v64; // [esp+25Ch] [ebp-1A8h] BYREF
  vostok::render::binary_shader_key_type __that; // [esp+264h] [ebp-1A0h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v66; // [esp+38Ch] [ebp-78h] BYREF
  int v67; // [esp+394h] [ebp-70h] BYREF
  _DWORD v68[6]; // [esp+39Ch] [ebp-68h] BYREF
  vostok::render::effect_cook *v69; // [esp+3B4h] [ebp-50h]
  _DWORD v70[6]; // [esp+3B8h] [ebp-4Ch] BYREF
  stlp_std::priv::_Rb_tree<vostok::render::binary_shader_key_type,stlp_std::less<vostok::render::binary_shader_key_type>,stlp_std::pair<vostok::render::binary_shader_key_type const ,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> >,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::binary_shader_key_type const ,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::binary_shader_key_type const ,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> > >,vostok::render::std_allocator<stlp_std::pair<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> > > > result; // [esp+3D0h] [ebp-34h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v72; // [esp+3E8h] [ebp-1Ch] BYREF
  unsigned int v73; // [esp+3ECh] [ebp-18h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> other; // [esp+3F0h] [ebp-14h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v75; // [esp+3F4h] [ebp-10h] BYREF
  vostok::resources::queries_result *p_compile; // [esp+3F8h] [ebp-Ch]
  char v77; // [esp+3FFh] [ebp-5h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v78; // [esp+400h] [ebp-4h] BYREF

  memset(&v70[2], 0, 16);
  v5 = data;
  s_efc_size -= 1024;
  *(_DWORD *)&result._M_header._M_data._M_color = 0;
  v69 = this;
  p_result = (vostok::variant<32> *)&result;
  result._M_header._M_data._M_left = (stlp_std::priv::_Rb_tree_node_base *)&result;
  result._M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)&result;
  LOBYTE(p_result) = HIBYTE(effect_resource);
  result._M_header._M_data._M_parent = 0;
  result._M_node_count = 0;
  result._M_key_compare.gap0 = HIBYTE(effect_resource);
  v77 = 0;
  v73 = 0;
  if ( !data->m_size )
    goto LABEL_11;
  m_queries = (char *)data->m_queries;
  v75.m_object = (survarium::pure_game_effect_emitter_base *)data->m_queries;
  do
  {
    v8 = *((_DWORD *)m_queries + 66);
    v78.m_object = 0;
    vostok::variant<32>::try_get<vostok::render::binary_shader_cook_data *>(
      p_result,
      v8,
      (vostok::render::binary_shader_cook_data **)&v78);
    m_object = (char *)v78.m_object;
    p_compile = (vostok::resources::queries_result *)vostok::render::g_allocator;
    if ( v78.m_object )
    {
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(
        (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&v78.m_object->m_reconstruction_info_actuality_tick
      + 1);
      vostok::memory::doug_lea_allocator::free_impl(v11, (int)p_compile, m_object, v59, v60, v61);
    }
    if ( vostok::resources::query_result_for_user::is_successful(v9, (int)m_queries) )
    {
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v72,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)m_queries
      + 55);
      v12 = (vostok::particle::particle_system_instance_impl *)v72.m_object;
      v13 = 0;
      v78.m_object = 0;
      if ( v72.m_object )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v78);
        v13 = v12;
        v78.m_object = v12;
        _InterlockedExchangeAdd(&v12->m_reference_count, 1u);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v72);
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &other,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v78);
      *(_DWORD *)&v57.0 = *(_DWORD *)&v13->m_lods[1].m_emitter_instance_list.gap4;
      *(unsigned __int64 *)((char *)v57.configuration + 4) = *(_QWORD *)&v13->m_lods[0].m_template.m_object;
      HIDWORD(v57.configuration[1]) = *(_DWORD *)&v13->m_lods[0].m_emitter_instance_list.gap4;
      m_first = (unsigned int)v13->m_lods[0].m_emitter_instance_list.m_first;
      v14 = (char *)vostok::shared_string::c_str((vostok::shared_string *)&v13->m_lods[1]);
      vostok::render::binary_shader_key_type::binary_shader_key_type(v15, v62, v14, v57, m_first);
      vostok::render::binary_shader_key_type::binary_shader_key_type(v16, &__that, (int)v62);
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v66,
        &other);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&other);
      vostok::render::binary_shader_key_type::binary_shader_key_type(v17, &v63, (int)&__that);
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v64,
        &v66);
      stlp_std::priv::_Rb_tree<vostok::render::binary_shader_key_type,stlp_std::less<vostok::render::binary_shader_key_type>,stlp_std::pair<vostok::render::binary_shader_key_type const,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::binary_shader_key_type const,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::binary_shader_key_type const,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>>>,vostok::render::std_allocator<stlp_std::pair<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>>>>::insert_unique(
        v18,
        &result._M_header._M_data,
        (const stlp_std::pair<vostok::render::binary_shader_key_type const ,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> > *)&v70[4],
        &v63);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v64);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v66);
      v77 = 1;
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v78);
      m_queries = (char *)v75.m_object;
      v5 = data;
    }
    ++v73;
    m_queries += 736;
    v75.m_object = (survarium::pure_game_effect_emitter_base *)m_queries;
  }
  while ( v73 < v5->m_size );
  if ( v77 )
  {
    v73 = 0;
    if ( v5->m_size )
    {
      p_m_unmanaged_resource = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v5->m_queries[0].m_unmanaged_resource;
      other.m_object = (survarium::pure_game_effect_emitter_base *)&v5->m_queries[0].m_unmanaged_resource;
      do
      {
        if ( vostok::resources::query_result_for_user::is_successful(
               (vostok::resources::query_result_for_user *)p_result,
               (int)&p_m_unmanaged_resource[-55]) )
        {
          vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            &v75,
            p_m_unmanaged_resource);
          v21 = (vostok::particle::particle_system_instance_impl *)v75.m_object;
          v78.m_object = 0;
          if ( v75.m_object )
          {
            vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v78);
            v78.m_object = v21;
            _InterlockedExchangeAdd(&v21->m_reference_count, 1u);
          }
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v75);
          v22 = effect_resource;
          if ( effect_resource->cached_binary_shaders.m_end >= effect_resource->cached_binary_shaders.m_max_end
            && !`vostok::buffer_vector<vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>>::push_back'::`11'::debug_macro_helper_ignore_always )
          {
            HIBYTE(data) = 0;
            vostok::debug::on_error(
              (bool *)&data + 3,
              process_error_true,
              0,
              "assertion_failed",
              "fatal error",
              "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
              "vostok::buffer_vector<class vostok::resources::resource_ptr<struct vostok::render::binary_shader_source,cl"
              "ass vostok::resources::unmanaged_intrusive_base> >::push_back",
              (const char *)0x12E,
              "buffer overflow",
              v59);
            if ( vostok::debug::is_debugger_present() || HIBYTE(data) )
              __debugbreak();
          }
          m_end = effect_resource->cached_binary_shaders.m_end;
          if ( m_end )
          {
            vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
              (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)m_end,
              (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v78);
            v22 = effect_resource;
          }
          ++v22->cached_binary_shaders.m_end;
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v78);
        }
        ++v73;
        p_m_unmanaged_resource = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&other.m_object[2].vostok::resources::unmanaged_intrusive_base;
        other.m_object = (survarium::pure_game_effect_emitter_base *)((char *)other.m_object + 736);
      }
      while ( v73 < v5->m_size );
    }
    ++effect_compiler_cnt;
    v24 = vostok::render::g_allocator;
    v25 = type_info::raw_name(&vostok::render::effect_compiler `RTTI Type Descriptor');
    v27 = vostok::memory::doug_lea_allocator::malloc_impl(v26, (int)v24, (unsigned int)dword_61F50, v25, v59, v60, v61);
    v28 = 0;
    if ( v27 )
    {
      vostok::render::effect_compiler::effect_compiler(
        (vostok::render::effect_compiler *)v27,
        (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)&result,
        effect_resource,
        in_out_query,
        0,
        0);
      v28 = v29;
    }
    stage_index = compile_data->stage_index;
    if ( stage_index == 29 )
    {
      compile_data->descriptor->compile(
        compile_data->descriptor,
        v28,
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst->shader_name_to_mask_config.m_object->m_root,
        &compile_data->parameters);
    }
    else
    {
      p_compile = (vostok::resources::queries_result *)&compile_data->descriptor->compile;
      data = (vostok::resources::queries_result *)vostok::render::stage_type_to_string(stage_index);
      v32 = vostok::configs::binary_config_value::operator[](v31, "material");
      v33 = vostok::configs::binary_config_value::operator[](v32, (char *)data);
      v34 = vostok::configs::binary_config_value::operator[](v33, "effect");
      ((void (__thiscall *)(vostok::render::effect_descriptor *, vostok::render::effect_compiler *, const vostok::configs::binary_config_value *, vostok::render::surface_effect_parameters *))p_compile->m_callback.vtable)(
        compile_data->descriptor,
        v28,
        v34,
        &compile_data->parameters);
    }
    m_begin = v28->m_used_textures.m_begin;
    for ( data = (vostok::resources::queries_result *)v28->m_used_textures.m_end;
          m_begin != (vostok::render::texture_named_instance *)data;
          ++m_begin )
    {
      vostok::render::res_effect::push_texture_unique(
        v35,
        (vostok::buffer_vector<vostok::render::texture_named_instance> *)effect_resource,
        m_begin->texture,
        m_begin->path.m_begin);
    }
    if ( compile_data->add_to_array )
      vostok::render::effect_manager::add_effect(
        (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&compile_data->config,
        vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
        compile_data->descriptor,
        &compile_data->parameters,
        effect_resource,
        compile_data->stage_index);
    m_first = (unsigned int)effect_resource;
    v37 = *(vostok::render::effect_compiler::texture_query_desc **)((char *)&loc_4BE28 + (_DWORD)v28);
    v38 = stlp_std::priv::__find_if<vostok::render::effect_compiler::texture_query_desc *,vostok::render::remove_texture_predicate>(
            v28->m_textures_for_query.m_begin,
            v37);
    if ( v38 != v37 )
    {
      m_first = (unsigned int)effect_resource;
      v38 = stlp_std::remove_copy_if<vostok::render::effect_compiler::texture_query_desc *,vostok::render::effect_compiler::texture_query_desc *,vostok::render::remove_texture_predicate>(
              v38 + 1,
              v38,
              v37);
    }
    v78.m_object = (vostok::particle::particle_system_instance_impl *)v38;
    if ( v38 != v37 )
    {
      data = (vostok::resources::queries_result *)v37;
      if ( v37 != *(vostok::render::effect_compiler::texture_query_desc **)((char *)&loc_4BE28 + (_DWORD)v28) )
      {
        p_compile = (vostok::resources::queries_result *)((char *)v38 - (char *)v37);
        do
        {
          vostok::buffer_vector<vostok::render::effect_compiler::texture_query_desc>::construct(
            (vostok::render::effect_compiler::texture_query_desc *)((char *)data + (_DWORD)p_compile),
            (const vostok::render::effect_compiler::texture_query_desc *)data);
          data = (vostok::resources::queries_result *)((char *)data + 552);
        }
        while ( data != *(vostok::resources::queries_result **)((char *)&loc_4BE28 + (_DWORD)v28) );
      }
      *(_DWORD *)((char *)&loc_4BE28 + (_DWORD)v28) = &v28->m_textures_for_query.m_begin[(signed int)(*(_DWORD *)((char *)&loc_4BE28 + (_DWORD)v28) - (unsigned int)v28->m_textures_for_query.m_begin)
                                                                                       / 552
                                                                                       - ((char *)v37
                                                                                        - (char *)v78.m_object)
                                                                                       / 552];
    }
    v39 = (vostok::resources::queries_result *)v28->m_textures_for_query.m_begin;
    data = *(vostok::resources::queries_result **)((char *)&loc_4BE28 + (_DWORD)v28);
    v40 = ((char *)data - (char *)v39) / 552;
    v75.m_object = (survarium::pure_game_effect_emitter_base *)v40;
    if ( v40 )
    {
      v41 = alloca(8 * v40);
      v42 = &v59;
      other.m_object = (survarium::pure_game_effect_emitter_base *)&v59;
      while ( v39 != data )
      {
        v42[1] = (const char *)7;
        *v42 = (const char *)v39->m_callback.vtable;
        v42 += 2;
        v39 = (vostok::resources::queries_result *)((char *)v39 + 552);
      }
      v43 = vostok::render::g_allocator;
      v44 = type_info::raw_name(&vostok::fixed_vector<vostok::render::effect_compiler::texture_query_desc,32> `RTTI Type Descriptor');
      v46 = vostok::memory::doug_lea_allocator::malloc_impl(v45, (int)v43, 0x450Cu, v44, v59, v60, v61);
      if ( v46 )
      {
        *(_DWORD *)v46 = v46 + 12;
        *((_DWORD *)v46 + 1) = v46 + 12;
        *((_DWORD *)v46 + 2) = v46 + 17676;
        v47 = v46;
      }
      else
      {
        v47 = 0;
      }
      v48 = *(vostok::resources::queries_result **)((char *)&loc_4BE28 + (_DWORD)v28);
      data = (vostok::resources::queries_result *)v28->m_textures_for_query.m_begin;
      p_compile = v48;
      v49 = *(vostok::render::effect_compiler::texture_query_desc **)v47;
      *((_DWORD *)v47 + 1) = *(_DWORD *)v47 + 552 * (((char *)v48 - (char *)data) / 552);
      for ( i = v49; data != p_compile; ++i )
      {
        vostok::buffer_vector<vostok::render::effect_compiler::texture_query_desc>::construct(
          i,
          (const vostok::render::effect_compiler::texture_query_desc *)data);
        data = (vostok::resources::queries_result *)((char *)data + 552);
      }
      v70[1] = v69;
      v70[3] = in_out_query;
      v70[4] = effect_resource;
      v70[2] = v47;
      v70[5] = compile_data;
      v68[0] = vostok::render::effect_cook::on_textures_ready;
      qmemcpy(&v68[1], &v70[1], 0x14u);
      m_first = (unsigned int)v70;
      qmemcpy(v70, v68, sizeof(v70));
      if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
      {
        v67 = 0;
      }
      else
      {
        qmemcpy(v68, v70, sizeof(v68));
        v67 = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf5<void,vostok::render::effect_cook,void *,vostok::resources::query_result_for_cook *,vostok::render::res_effect *,vostok::render::effect_compile_data *,vostok::resources::queries_result &>,boost::_bi::list6<boost::_bi::value<vostok::render::effect_cook *>,boost::_bi::value<vostok::fixed_vector<vostok::render::effect_compiler::texture_query_desc,32> *>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::render::res_effect *>,boost::_bi::value<vostok::render::effect_compile_data *>,boost::arg<1>>>>'::`2'::stored_vtable
            + 1;
      }
      vostok::resources::query_resources(
        (const vostok::resources::request *)other.m_object,
        (unsigned int)v75.m_object,
        in_out_query->m_user_allocator,
        0,
        (const vostok::variant<32> **)in_out_query,
        assert_on_fail_false);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v51, &v67);
    }
    else
    {
      m_first = 22200;
      HIDWORD(v57.configuration[1]) = &vostok::resources::nocache_memory;
      LODWORD(v57.configuration[1]) = 552;
      vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v57.configuration[1],
        (survarium::pure_game_effect_emitter_base *)effect_resource);
      vostok::resources::query_result_for_cook::set_unmanaged_resource(
        v53,
        (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)in_out_query,
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v57.configuration[1],
        (const vostok::resources::memory_type *)HIDWORD(v57.configuration[1]),
        m_first);
      vostok::resources::query_result_for_cook::finish_query_impl(
        v54,
        (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)in_out_query,
        result_out_of_memory,
        assert_on_fail_true,
        result_fail);
    }
    v55 = vostok::render::g_allocator;
    vostok::render::effect_compiler::~effect_compiler(v52, v28);
    vostok::memory::doug_lea_allocator::free_impl(v56, (int)v55, (char *)v28, v59, v60, v61);
  }
  else
  {
LABEL_11:
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)p_result,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)in_out_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
    ((void (__thiscall *)(vostok::render::res_effect *, _DWORD))effect_resource->~vostok::render::res_effect)(
      effect_resource,
      0);
    vostok::memory::doug_lea_allocator::free_impl(
      v19,
      (int)vostok::render::g_allocator,
      (char *)effect_resource,
      v59,
      v60,
      v61);
    --s_num_ec;
  }
  if ( result._M_node_count )
    stlp_std::priv::_Rb_tree<vostok::render::binary_shader_key_type,stlp_std::less<vostok::render::binary_shader_key_type>,stlp_std::pair<vostok::render::binary_shader_key_type const,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::binary_shader_key_type const,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::binary_shader_key_type const,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>>>,vostok::render::std_allocator<stlp_std::pair<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>>>>::_M_erase(
      &result,
      result._M_header._M_data._M_parent);
}
