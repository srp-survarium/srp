vostok::render::effect_compiler *__thiscall vostok::render::effect_compiler::end_pass(
        vostok::render::effect_compiler *this,
        int a2)
{
  vostok::render::resource_manager *v2; // ecx
  vostok::render::res_state *state; // eax
  vostok::render::resource_manager *v4; // ecx
  vostok::render::res_xs<vostok::render::vs_data> *vs; // eax
  vostok::render::resource_manager *v6; // ecx
  vostok::render::res_xs<vostok::render::gs_data> *gs; // eax
  vostok::render::resource_manager *v8; // ecx
  vostok::render::res_xs<vostok::render::ps_data> *ps; // eax
  vostok::render::effect_manager *v10; // edi
  const vostok::render::res_pass *v11; // eax
  vostok::render::effect_manager *v12; // ecx
  vostok::render::res_pass *pass; // eax
  vostok::render::res_pass *v14; // ecx
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *v15; // ecx
  vostok::render::state_descriptor *v16; // ecx
  _DWORD *v17; // esi
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *i; // edi
  vostok::render::effect_manager *v19; // ecx
  vostok::render::res_pass *m_object; // eax
  bool v21; // zf
  vostok::render::res_xs<vostok::render::ps_data> *v22; // eax
  vostok::render::res_xs<vostok::render::gs_data> *v23; // eax
  vostok::render::res_xs<vostok::render::vs_data> *v24; // eax
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> value; // [esp+10h] [ebp-30h] BYREF
  vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v27; // [esp+14h] [ebp-2Ch] BYREF
  vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v28; // [esp+18h] [ebp-28h] BYREF
  vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v29; // [esp+1Ch] [ebp-24h] BYREF
  vostok::intrusive_ptr<vostok::render::res_state,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v30; // [esp+20h] [ebp-20h] BYREF
  vostok::render::res_pass v31; // [esp+24h] [ebp-1Ch] BYREF

  if ( !byte_61F4C[a2]
    && !vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_no_effect_result) )
  {
    vostok::render::shader_constant_table::apply_bindings(
      (const vostok::render::shader_constant_bindings *)((char *)&dword_61C1C + a2),
      (vostok::render::shader_constant_table *)((char *)&loc_504EE + a2 + 2));
    vostok::render::shader_constant_table::apply_bindings(
      (const vostok::render::shader_constant_bindings *)((char *)&dword_61C1C + a2),
      (vostok::render::shader_constant_table *)((char *)&loc_56203 + a2 + 1));
    vostok::render::shader_constant_table::apply_bindings(
      (const vostok::render::shader_constant_bindings *)((char *)&dword_61C1C + a2),
      (vostok::render::shader_constant_table *)((char *)&loc_5BF12 + a2 + 2));
    state = vostok::render::resource_manager::create_state(
              v2,
              (vostok::render::state_descriptor *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              (const D3D11_RASTERIZER_DESC *)((char *)&loc_5033B + a2 + 1));
    v30.m_object = 0;
    if ( state )
    {
      ++state->m_reference_count;
      v30.m_object = state;
    }
    vs = (vostok::render::res_xs<vostok::render::vs_data> *)vostok::render::resource_manager::create_vs(
                                                              v4,
                                                              (const vostok::render::xs_descriptor<vostok::render::vs_data> *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                                              (vostok::render::xs_descriptor<vostok::render::vs_data> *)((char *)&loc_504E3 + a2 + 1));
    v29.m_object = 0;
    if ( vs )
    {
      ++vs->m_reference_count;
      v29.m_object = vs;
    }
    gs = (vostok::render::res_xs<vostok::render::gs_data> *)vostok::render::resource_manager::create_gs(
                                                              v6,
                                                              (const vostok::render::xs_descriptor<vostok::render::gs_data> *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                                              (vostok::render::xs_descriptor<vostok::render::gs_data> *)((char *)&loc_561F6 + a2 + 2));
    v28.m_object = 0;
    if ( gs )
    {
      ++gs->m_reference_count;
      v28.m_object = gs;
    }
    ps = (vostok::render::res_xs<vostok::render::ps_data> *)vostok::render::resource_manager::create_ps(
                                                              v8,
                                                              (const vostok::render::xs_descriptor<vostok::render::ps_data> *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                                              (vostok::render::xs_descriptor<vostok::render::ps_data> *)((char *)&loc_5BF08 + a2));
    v27.m_object = 0;
    if ( ps )
    {
      ++ps->m_reference_count;
      v27.m_object = ps;
    }
    v10 = vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
    vostok::render::res_pass::res_pass(&v30, &v31, &v29, &v28, &v27);
    pass = (vostok::render::res_pass *)vostok::render::effect_manager::create_pass(v12, (int)v10, v11);
    value.m_object = 0;
    if ( pass )
    {
      ++pass->m_reference_count;
      value.m_object = pass;
    }
    vostok::render::res_pass::~res_pass(v14, (int)&v31);
    vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::push_back(
      v15,
      (int)dword_61EB0 + a2,
      &value);
    vostok::render::state_descriptor::reset(v16, (char *)&loc_5033B + a2 + 1);
    v17 = (int *)((char *)&dword_61C1C + a2);
    for ( i = *(vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> **)((char *)&dword_61C1C + a2);
          i != (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)v17[1];
          i += 5 )
    {
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(i + 2);
    }
    v17[1] = *v17;
    vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&loc_50338 + a2),
      0);
    vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&loc_50332 + a2 + 2),
      0);
    vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&loc_5032F + a2 + 1),
      0);
    m_object = value.m_object;
    ++*(int *)((char *)&dword_61F48 + a2);
    if ( m_object )
    {
      v21 = m_object->m_reference_count-- == 1;
      if ( v21 )
        vostok::render::effect_manager::delete_pass(
          v19,
          (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
          m_object);
    }
    v22 = v27.m_object;
    if ( v27.m_object )
    {
      v21 = v27.m_object->m_reference_count-- == 1;
      if ( v21 )
        vostok::render::resource_manager::release(
          vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::res_pass *)v22);
    }
    v23 = v28.m_object;
    if ( v28.m_object )
    {
      v21 = v28.m_object->m_reference_count-- == 1;
      if ( v21 )
        vostok::render::resource_manager::release(
          vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::res_pass *)v23);
    }
    v24 = v29.m_object;
    if ( v29.m_object )
    {
      v21 = v29.m_object->m_reference_count-- == 1;
      if ( v21 )
        vostok::render::resource_manager::release(
          vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::res_pass *)v24);
    }
    if ( v30.m_object )
      --v30.m_object->m_reference_count;
  }
  return (vostok::render::effect_compiler *)a2;
}
