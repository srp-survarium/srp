vostok::render::effect_compiler *__thiscall vostok::render::effect_compiler::begin_pass(
        vostok::render::effect_compiler *this,
        int vs_name,
        char *gs_name,
        char *ps_name,
        vostok::render::shader_configuration in_shader_config,
        vostok::render::shader_include_getter *include_getter)
{
  vostok::render::effect_compiler::shader_cache_info *v6; // ecx
  vostok::render::resource_manager *v7; // ecx
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *v8; // edi
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> **v9; // esi
  stlp_std::priv::_Rb_tree_node_base *v10; // eax
  vostok::render::resource_manager *v11; // ecx
  stlp_std::priv::_Rb_tree_node_base *v12; // eax
  vostok::render::resource_manager *v13; // ecx
  stlp_std::priv::_Rb_tree_node_base *v14; // eax
  vostok::render::res_xs_hw<vostok::render::vs_data> *v15; // eax
  vostok::render::res_xs_hw<vostok::render::gs_data> *v16; // eax
  vostok::render::res_xs_hw<vostok::render::ps_data> *v17; // eax
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::buffer_vector<vostok::render::effect_compiler::shader_cache_info> *v20; // ecx
  vostok::render::shader_configuration v22; // [esp-18h] [ebp-3C8h]
  vostok::render::shader_configuration v23; // [esp-18h] [ebp-3C8h]
  vostok::render::shader_configuration v24; // [esp-18h] [ebp-3C8h]
  D3D11_COMPARISON_FUNC v25; // [esp+0h] [ebp-3B0h]
  D3D11_BLEND_OP v26; // [esp+0h] [ebp-3B0h]
  vostok::render::shader_configuration v27; // [esp+10h] [ebp-3A0h] BYREF
  vostok::render::shader_configuration v28; // [esp+20h] [ebp-390h] BYREF
  vostok::render::shader_configuration v29; // [esp+30h] [ebp-380h] BYREF
  vostok::render::effect_compiler::shader_cache_info value; // [esp+40h] [ebp-370h] BYREF

  v29.configuration[0] = *(unsigned __int64 *)((char *)in_shader_config.configuration + 4);
  v29.configuration[1] = __PAIR64__((unsigned int)include_getter, HIDWORD(in_shader_config.configuration[1]));
  v27.configuration[0] = *(unsigned __int64 *)((char *)in_shader_config.configuration + 4);
  v27.configuration[1] = __PAIR64__((unsigned int)include_getter, HIDWORD(in_shader_config.configuration[1]));
  v28.configuration[0] = *(unsigned __int64 *)((char *)in_shader_config.configuration + 4);
  v28.configuration[1] = __PAIR64__((unsigned int)include_getter, HIDWORD(in_shader_config.configuration[1]));
  vostok::render::modify_shader_configuration(&v29, *(char **)&in_shader_config.0, "ps");
  vostok::render::modify_shader_configuration(&v27, gs_name, "vs");
  vostok::render::modify_shader_configuration(&v28, ps_name, "gs");
  if ( byte_61F4C[vs_name]
    || vostok::command_line::key::is_set((vostok::command_line::key *)v6, (int)&s_no_effect_result) )
  {
    vostok::render::effect_compiler::shader_cache_info::shader_cache_info(v6, (int)&value);
    if ( value.vertex_shader_name.m_string.m_begin != gs_name )
    {
      value.vertex_shader_name.m_string.m_end = value.vertex_shader_name.m_string.m_begin;
      *value.vertex_shader_name.m_string.m_begin = 0;
      vostok::buffer_string::operator+=(&value.vertex_shader_name.m_string, gs_name);
    }
    if ( value.geometry_shader_name.m_string.m_begin != ps_name )
    {
      value.geometry_shader_name.m_string.m_end = value.geometry_shader_name.m_string.m_begin;
      *value.geometry_shader_name.m_string.m_begin = 0;
      vostok::buffer_string::operator+=(&value.geometry_shader_name.m_string, ps_name);
    }
    if ( value.pixel_shader_name.m_string.m_begin != *(char **)&in_shader_config.0 )
    {
      value.pixel_shader_name.m_string.m_end = value.pixel_shader_name.m_string.m_begin;
      *value.pixel_shader_name.m_string.m_begin = 0;
      vostok::buffer_string::operator+=(&value.pixel_shader_name.m_string, *(char **)&in_shader_config.0);
    }
    value.ps_configuration = v29;
    value.vs_configuration = v27;
    value.gs_configuration = v28;
    vostok::buffer_vector<vostok::render::effect_compiler::shader_cache_info>::push_back(v20, vs_name + 12, &value);
  }
  else
  {
    vostok::render::state_descriptor::reset((vostok::render::state_descriptor *)v6, (char *)&loc_5033B + vs_name + 1);
    v8 = *(vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> **)((char *)&dword_61C1C + vs_name);
    v9 = (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> **)((char *)&dword_61C20 + vs_name);
    while ( v8 != *v9 )
    {
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(v8 + 2);
      v8 += 5;
    }
    *v9 = *(vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> **)((char *)&dword_61C1C + vs_name);
    v22.configuration[1] = v27.configuration[0];
    HIDWORD(v22.configuration[0]) = *(_DWORD *)vs_name;
    *(_DWORD *)&v22.0 = gs_name;
    v10 = vostok::render::resource_manager::create_xs_hw_impl<vostok::render::vs_data>(
            v7,
            (const char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            v22,
            v27.configuration[1]);
    vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&loc_50338 + vs_name),
      (vostok::render::res_xs_hw<vostok::render::vs_data> *)v10);
    v23.configuration[1] = v28.configuration[0];
    HIDWORD(v23.configuration[0]) = *(_DWORD *)vs_name;
    *(_DWORD *)&v23.0 = ps_name;
    v12 = vostok::render::resource_manager::create_xs_hw_impl<vostok::render::gs_data>(
            v11,
            (const char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            v23,
            v28.configuration[1]);
    vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&loc_50332 + vs_name + 2),
      (vostok::render::res_xs_hw<vostok::render::gs_data> *)v12);
    v24.configuration[1] = v29.configuration[0];
    HIDWORD(v24.configuration[0]) = *(_DWORD *)vs_name;
    *(_DWORD *)&v24.0 = in_shader_config.0;
    v14 = vostok::render::resource_manager::create_xs_hw_impl<vostok::render::ps_data>(
            v13,
            (const char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            v24,
            v29.configuration[1]);
    vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&loc_5032F + vs_name + 1),
      (vostok::render::res_xs_hw<vostok::render::ps_data> *)v14);
    v15 = *(vostok::render::res_xs_hw<vostok::render::vs_data> **)((char *)&loc_50338 + vs_name);
    if ( !v15
      || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v15 = 0;
    }
    vostok::render::xs_descriptor<vostok::render::vs_data>::reset(
      (vostok::render::xs_descriptor<vostok::render::vs_data> *)((char *)&loc_504E3 + vs_name + 1),
      v15);
    v16 = *(vostok::render::res_xs_hw<vostok::render::gs_data> **)((char *)&loc_50332 + vs_name + 2);
    if ( !v16
      || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v16 = 0;
    }
    vostok::render::xs_descriptor<vostok::render::gs_data>::reset(
      (vostok::render::xs_descriptor<vostok::render::gs_data> *)((char *)&loc_561F6 + vs_name + 2),
      v16);
    if ( *(_DWORD *)((char *)&loc_5032F + vs_name + 1)
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v17 = *(vostok::render::res_xs_hw<vostok::render::ps_data> **)((char *)&loc_5032F + vs_name + 1);
    }
    else
    {
      v17 = 0;
    }
    vostok::render::xs_descriptor<vostok::render::ps_data>::reset(
      (vostok::render::xs_descriptor<vostok::render::ps_data> *)((char *)&loc_5BF08 + vs_name),
      v17);
    vostok::render::effect_compiler::set_depth(v18, vs_name, 1, 1, v25);
    vostok::render::effect_compiler::set_alpha_blend(
      v19,
      vs_name,
      0,
      D3D11_BLEND_ONE,
      D3D11_BLEND_ZERO,
      D3D11_BLEND_OP_ADD,
      D3D11_BLEND_ONE,
      D3D11_BLEND_ZERO,
      v26);
  }
  return (vostok::render::effect_compiler *)vs_name;
}
