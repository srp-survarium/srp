vostok::render::effect_compiler *__thiscall vostok::render::effect_compiler::set_texture(
        vostok::render::effect_compiler *this,
        int name,
        char *physical_name,
        char *streamed,
        char num_last_mips_used,
        unsigned int streaming_priority,
        unsigned int tiling,
        float a8)
{
  int v9; // eax
  int v10; // eax
  vostok::fixed_string<260> *v11; // ecx
  vostok::command_line::key *v12; // ecx
  vostok::buffer_string *v13; // ecx
  char v15; // al
  vostok::render::effect_compiler::texture_query_desc *v16; // edi
  int v17; // eax
  vostok::render::res_texture *texture; // esi
  unsigned int v19; // eax
  float max_tiling; // xmm0_4
  vostok::render::effect_compiler *v21; // ecx
  bool v22; // zf
  bool v23; // al
  vostok::render::effect_compiler *v24; // [esp-4h] [ebp-570h]
  vostok::render::effect_compiler *v25; // [esp-4h] [ebp-570h]
  vostok::command_line::key *v26; // [esp-4h] [ebp-570h]
  vostok::buffer_vector<vostok::render::effect_compiler::texture_query_desc> *v27; // [esp-4h] [ebp-570h]
  bool v28; // [esp+0h] [ebp-56Ch]
  unsigned int v29; // [esp+4h] [ebp-568h]
  unsigned int v30; // [esp+8h] [ebp-564h]
  float v31; // [esp+Ch] [ebp-560h]
  vostok::buffer_string v32[44]; // [esp+10h] [ebp-55Ch] BYREF
  vostok::buffer_string string; // [esp+220h] [ebp-34Ch] BYREF
  char v34; // [esp+330h] [ebp-23Ch]
  vostok::render::effect_compiler::texture_query_desc __pred; // [esp+338h] [ebp-234h] BYREF
  unsigned int v36; // [esp+560h] [ebp-Ch]
  char v37; // [esp+567h] [ebp-5h]
  char v38; // [esp+577h] [ebp+Bh]

  if ( !streamed
    || !vostok::strings::compare(streamed, uri)
    || vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_one_texture_result)
    && (strstr((unsigned __int8 *)streamed, "$user$"), this = v24, !v9)
    && (strstr((unsigned __int8 *)streamed, "ui/"), this = v25, !v10) )
  {
    streamed = "editor/default";
  }
  vostok::fixed_string<512>::fixed_string<512>((vostok::fixed_string<512> *)this, v32, streamed);
  v36 = streaming_priority;
  if ( !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_use_texture_streaming )
    streaming_priority = -1;
  vostok::fixed_string<260>::fixed_string<260>(v11, &string, streamed);
  v34 = 47;
  if ( string.m_end != string.m_begin )
  {
    _strlwr_s(string.m_begin, string.m_end - string.m_begin + 1);
    v12 = v26;
  }
  if ( vostok::command_line::key::is_set(v12, (int)&s_no_effect_result) )
    return (vostok::render::effect_compiler *)name;
  v38 = 0;
  if ( *(_DWORD *)((char *)&loc_50338 + name)
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v38 = vostok::render::xs_descriptor<vostok::render::gs_data>::use_texture(
            (vostok::render::xs_descriptor<vostok::render::vs_data> *)((char *)&loc_504E3 + name + 1),
            physical_name);
  }
  if ( *(_DWORD *)((char *)&loc_50332 + name + 2)
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v38 |= vostok::render::xs_descriptor<vostok::render::gs_data>::use_texture(
             (vostok::render::xs_descriptor<vostok::render::vs_data> *)((char *)&loc_561F6 + name + 2),
             physical_name);
  }
  v37 = 0;
  if ( *(_DWORD *)((char *)&loc_5032F + name + 1)
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v15 = vostok::render::xs_descriptor<vostok::render::gs_data>::use_texture(
            (vostok::render::xs_descriptor<vostok::render::vs_data> *)((char *)&loc_5BF08 + name),
            physical_name);
    v38 |= v15;
    v37 = v15;
  }
  if ( !v38 )
    return (vostok::render::effect_compiler *)name;
  if ( v37
    && (!num_last_mips_used || !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_use_texture_streaming) )
  {
    streaming_priority = -1;
  }
  if ( !byte_61F4C[name] )
  {
    __pred.m_query_physicaly_path.m_begin = __pred.m_query_physicaly_path.m_buffer;
    __pred.m_query_physicaly_path.m_end = __pred.m_query_physicaly_path.m_buffer;
    __pred.m_query_physicaly_path.m_max_end = (char *)&__pred.m_query_short_path;
    __pred.m_query_short_path.m_begin = __pred.m_query_short_path.m_buffer;
    __pred.m_query_short_path.m_end = __pred.m_query_short_path.m_buffer;
    __pred.m_query_short_path.m_max_end = (char *)&__pred.m_mip_level_cut;
    __pred.m_query_physicaly_path.m_buffer[0] = 0;
    __pred.m_query_short_path.m_buffer[0] = 0;
    if ( __pred.m_query_short_path.m_buffer != string.m_begin )
    {
      __pred.m_query_short_path.m_end = __pred.m_query_short_path.m_buffer;
      __pred.m_query_short_path.m_buffer[0] = 0;
      vostok::buffer_string::operator+=(&__pred.m_query_short_path, string.m_begin);
    }
    vostok::fs_new::path_string_impl::assignf(&__pred, v13, (vostok::buffer_string *)&stru_80B1B4, string.m_begin);
    __pred.m_mip_level_cut = 0;
    v16 = *(vostok::render::effect_compiler::texture_query_desc **)((char *)&loc_4BE28 + name);
    __pred.m_num_last_mips_used = streaming_priority;
    if ( stlp_std::priv::__find_if<vostok::render::effect_compiler::texture_query_desc *,vostok::render::find_texture_predicate>(
           *(vostok::render::effect_compiler::texture_query_desc **)((char *)&loc_4BE23 + name + 1),
           v16,
           __pred.m_query_physicaly_path.m_begin) == v16 )
    {
      strstr((unsigned __int8 *)streamed, "$user$");
      v13 = (vostok::buffer_string *)v27;
      if ( !v17 )
        vostok::buffer_vector<vostok::render::effect_compiler::texture_query_desc>::push_back(
          v27,
          (int)&loc_4BE23 + name + 1,
          &__pred);
    }
  }
  texture = vostok::render::resource_manager::create_texture(
              (vostok::render::resource_manager *)v13,
              vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              (vostok::resources::query_result_for_cook *)string.m_begin,
              0,
              0,
              0,
              1,
              1,
              streaming_priority,
              *(_BYTE *)(name + 4),
              0,
              0);
  v19 = texture->streaming_priority;
  max_tiling = texture->max_tiling;
  v21 = (vostok::render::effect_compiler *)((v19 - tiling) & ((v19 - (unsigned __int64)tiling) >> 32));
  texture->streaming_priority = v19 - (_DWORD)v21;
  if ( max_tiling <= a8 )
    max_tiling = a8;
  v22 = !texture->m_streamed;
  texture->max_tiling = max_tiling;
  v23 = (!v22 || num_last_mips_used)
     && vostok::quasi_singleton<vostok::render::options>::pinst->current.m_use_texture_streaming;
  v22 = v36 == 0;
  texture->m_streamed = v23;
  if ( v22 )
    texture->m_always_closer = 1;
  if ( v37 )
  {
    __pred.m_query_short_path.m_end = &__pred.m_query_short_path.m_buffer[4];
    __pred.m_query_short_path.m_max_end = &__pred.m_query_short_path.m_buffer[4];
    *(_DWORD *)__pred.m_query_short_path.m_buffer = &__pred.m_num_last_mips_used;
    __pred.m_query_short_path.m_buffer[4] = 0;
    __pred.m_query_short_path.m_begin = (char *)texture;
    if ( &__pred.m_query_short_path.m_buffer[4] != streamed )
    {
      __pred.m_query_short_path.m_max_end = &__pred.m_query_short_path.m_buffer[4];
      __pred.m_query_short_path.m_buffer[4] = 0;
      vostok::buffer_string::operator+=((vostok::buffer_string *)&__pred.m_query_short_path.m_end, streamed);
    }
    vostok::buffer_vector<vostok::render::texture_named_instance>::push_back(
      (vostok::buffer_vector<vostok::render::texture_named_instance> *)(name + 28184),
      (const vostok::render::texture_named_instance *)&__pred.m_query_short_path);
  }
  return vostok::render::effect_compiler::set_texture_impl(v21, name, physical_name, texture, v28, v29, v30, v31);
}
