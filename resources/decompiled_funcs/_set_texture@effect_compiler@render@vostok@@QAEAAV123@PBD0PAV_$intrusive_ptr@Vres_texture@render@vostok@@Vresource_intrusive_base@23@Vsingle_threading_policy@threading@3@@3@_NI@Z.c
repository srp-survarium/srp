vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::set_texture@<eax>(
        unsigned int num_last_mips_used@<eax>,
        vostok::render::effect_compiler *this,
        const char *name,
        char *physical_name,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *out_texture,
        bool streamed)
{
  int v7; // eax
  int v8; // eax
  const char *v9; // ecx
  char *m_buffer; // eax
  vostok::render::xs_descriptor<vostok::render::vs_data> *v11; // ecx
  const char *v12; // esi
  char v13; // bl
  survarium::game_action_id *M_start; // ecx
  vostok::render::res_texture *texture; // edi
  stlp_std::priv::_Impl_vector<vostok::render::effect_compiler::texture_query_desc,vostok::render::std_allocator<vostok::render::effect_compiler::texture_query_desc> > *m_begin; // ecx
  char *p_m_max_end; // eax
  vostok::render::effect_compiler::texture_query_desc *M_finish; // esi
  unsigned int v20; // [esp+0h] [ebp-45Ch]
  unsigned int v21; // [esp+4h] [ebp-458h]
  char res; // [esp+13h] [ebp-449h]
  vostok::render::texture_named_instance instance; // [esp+18h] [ebp-444h] BYREF
  unsigned int v24; // [esp+12Ch] [ebp-330h] BYREF
  vostok::fixed_string<512> s; // [esp+130h] [ebp-32Ch] BYREF
  char v26; // [esp+33Ch] [ebp-120h] BYREF
  vostok::fs_new::virtual_path_string physical_name_lower_case; // [esp+340h] [ebp-11Ch] BYREF

  if ( physical_name
    && strcmp(physical_name, (const char *)&buf)
    && (!vostok::command_line::key::is_set(&s_one_texture_result)
     || (strstr((unsigned __int8 *)physical_name, "$user$"), v7)
     || (strstr((unsigned __int8 *)physical_name, "ui/"), v8)) )
  {
    v9 = physical_name;
  }
  else
  {
    v9 = "editor/default";
    physical_name = "editor/default";
  }
  m_buffer = s.m_buffer;
  s.m_begin = s.m_buffer;
  s.m_end = s.m_buffer;
  s.m_max_end = &v26;
  s.m_buffer[0] = 0;
  if ( v9 )
  {
    for ( ; *v9; ++s.m_end )
    {
      if ( m_buffer >= s.m_max_end )
        break;
      *m_buffer = *v9;
      m_buffer = s.m_end + 1;
      ++v9;
    }
    *m_buffer = 0;
  }
  if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 302) )
    num_last_mips_used = -1;
  vostok::fs_new::virtual_path_string::virtual_path_string(&physical_name_lower_case, (const char **)&physical_name);
  vostok::fs_new::path_string_impl::make_lowercase(&physical_name_lower_case);
  if ( this->m_shaders_cache_mode )
    goto LABEL_36;
  if ( s_no_effect_result.m_type == type_unset )
  {
    s_no_effect_result.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( s_no_effect_result.m_type != type_recursive )
  {
LABEL_36:
    instance.path.m_end = &instance.path.m_buffer[256];
    m_begin = (stlp_std::priv::_Impl_vector<vostok::render::effect_compiler::texture_query_desc,vostok::render::std_allocator<vostok::render::effect_compiler::texture_query_desc> > *)physical_name_lower_case.m_string.m_begin;
    p_m_max_end = (char *)&instance.path.m_max_end;
    instance.texture = (vostok::render::res_texture *)&instance.path.m_max_end;
    instance.path.m_begin = (char *)&instance.path.m_max_end;
    LOBYTE(instance.path.m_max_end) = 0;
    if ( &instance.path.m_max_end != (char **)physical_name_lower_case.m_string.m_begin )
    {
      instance.path.m_begin = (char *)&instance.path.m_max_end;
      LOBYTE(instance.path.m_max_end) = 0;
      if ( physical_name_lower_case.m_string.m_begin )
      {
        if ( *physical_name_lower_case.m_string.m_begin )
        {
          do
          {
            if ( p_m_max_end >= instance.path.m_end )
              break;
            *p_m_max_end = (char)m_begin->_M_start;
            p_m_max_end = instance.path.m_begin + 1;
            m_begin = (stlp_std::priv::_Impl_vector<vostok::render::effect_compiler::texture_query_desc,vostok::render::std_allocator<vostok::render::effect_compiler::texture_query_desc> > *)((char *)m_begin + 1);
            ++instance.path.m_begin;
          }
          while ( LOBYTE(m_begin->_M_start) );
        }
        *p_m_max_end = 0;
      }
    }
    M_finish = this->m_textures_for_query._M_impl._M_finish;
    *(_DWORD *)&instance.path.m_buffer[256] = 0;
    v24 = num_last_mips_used;
    if ( M_finish == this->m_textures_for_query._M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::render::effect_compiler::texture_query_desc,vostok::render::std_allocator<vostok::render::effect_compiler::texture_query_desc>>::_M_insert_overflow_aux(
        m_begin,
        (vostok::render::effect_compiler::texture_query_desc *)&this->m_textures_for_query,
        M_finish,
        (const vostok::render::effect_compiler::texture_query_desc *)&instance,
        v20,
        v21);
      return this;
    }
    else
    {
      if ( M_finish )
        vostok::render::effect_compiler::texture_query_desc::texture_query_desc(
          M_finish,
          (const vostok::render::effect_compiler::texture_query_desc *)&instance);
      ++this->m_textures_for_query._M_impl._M_finish;
      return this;
    }
  }
  else
  {
    res = 0;
    if ( this->m_vs_hw.m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v12 = name;
      res = vostok::render::xs_descriptor<vostok::render::gs_data>::use_texture(v11, (int)&this->m_vs_descriptor, name);
    }
    else
    {
      v12 = name;
    }
    if ( this->m_gs_hw.m_object )
    {
      v11 = (vostok::render::xs_descriptor<vostok::render::vs_data> *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        res |= vostok::render::xs_descriptor<vostok::render::gs_data>::use_texture(
                 (vostok::render::xs_descriptor<vostok::render::vs_data> *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
                 (int)&this->m_gs_descriptor,
                 v12);
    }
    v13 = 0;
    if ( this->m_ps_hw.m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v13 = vostok::render::xs_descriptor<vostok::render::gs_data>::use_texture(v11, (int)&this->m_ps_descriptor, v12);
      res |= v13;
    }
    if ( res )
    {
      texture = (vostok::render::res_texture *)vostok::render::resource_manager::create_texture(
                                                 (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                                                 physical_name_lower_case.m_string.m_begin,
                                                 0,
                                                 0,
                                                 0,
                                                 1,
                                                 1,
                                                 num_last_mips_used);
      if ( v13 && (_BYTE)out_texture )
      {
        M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
        if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
             + 302) )
        {
          instance.path.m_max_end = (char *)&v24;
          instance.path.m_begin = instance.path.m_buffer;
          instance.path.m_end = instance.path.m_buffer;
          instance.path.m_buffer[0] = 0;
          instance.texture = texture;
          vostok::fixed_string<16>::operator=((vostok::fixed_string<16> *)physical_name, &instance.path);
          stlp_std::vector<vostok::render::texture_named_instance,vostok::render::std_allocator<vostok::render::texture_named_instance>>::push_back(
            &this->m_ps_used_textures,
            &instance);
          v12 = name;
        }
      }
      return vostok::render::effect_compiler::set_texture(
               this,
               texture,
               (vostok::render::xs_descriptor<vostok::render::vs_data> *)M_start,
               v12,
               v20,
               v21);
    }
    else
    {
      return this;
    }
  }
}
