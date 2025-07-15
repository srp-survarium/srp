void __thiscall vostok::render::effect_compiler::end_technique(
        vostok::render::effect_compiler *this,
        vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> value)
{
  vostok::render::res_shader_technique *m_object; // ebx
  vostok::render::effect_manager *v3; // ecx
  vostok::render::res_shader_technique *effect_technique; // eax
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *v5; // ecx
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *v6; // ecx
  vostok::render::res_pass *v7; // eax

  m_object = value.m_object;
  if ( !byte_61F4C[(unsigned int)value.m_object]
    && !vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_no_effect_result) )
  {
    effect_technique = vostok::render::effect_manager::create_effect_technique(
                         v3,
                         (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
                         (vostok::render::res_shader_technique *)((char *)dword_61EA8 + (_DWORD)m_object));
    value.m_object = 0;
    if ( effect_technique )
    {
      ++effect_technique->m_reference_count;
      value.m_object = effect_technique;
    }
    vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::push_back(
      v5,
      *(int *)((char *)&dword_61F40 + (_DWORD)m_object) + 22052,
      &value);
    vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::clear(
      v6,
      (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)((char *)dword_61EB0 + (_DWORD)m_object));
    v7 = (vostok::render::res_pass *)value.m_object;
    ++*(int *)((char *)&dword_61F44 + (_DWORD)m_object);
    *(int *)((char *)&dword_61F48 + (_DWORD)m_object) = 0;
    if ( v7 )
    {
      if ( v7->m_reference_count-- == 1 )
        vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v7);
    }
  }
}
