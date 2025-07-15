void __thiscall vostok::render::shader_macros::fill_shader_macro_list(
        vostok::render::shader_macros *this,
        vostok::fixed_vector<vostok::render::shader_macro,128> *macros,
        vostok::render::shader_configuration shader_config)
{
  vostok::fixed_vector<vostok::render::shader_macro,128> *v3; // eax
  vostok::render::shader_macro *v4; // ecx
  vostok::render::render_cc *first_render_command; // ebx
  vostok::render::shader_configuration v6; // [esp-Ch] [ebp-240h]
  vostok::render::shader_macro value; // [esp+10h] [ebp-224h] BYREF

  v3 = macros;
  macros->m_end = macros->m_begin;
  v4 = (vostok::render::shader_macro *)vostok::quasi_singleton<vostok::render::options>::pinst;
  first_render_command = vostok::quasi_singleton<vostok::render::options>::pinst->first_render_command;
  if ( vostok::quasi_singleton<vostok::render::options>::pinst->first_render_command )
  {
    do
    {
      vostok::render::shader_macro::shader_macro(v4, (int)&value);
      if ( first_render_command->fill_macro(first_render_command, &value) )
        vostok::buffer_vector<vostok::render::shader_macro>::push_back(
          (vostok::buffer_vector<vostok::render::shader_macro> *)v4,
          (int)macros,
          &value);
      first_render_command = first_render_command->render_next;
    }
    while ( first_render_command );
    v3 = macros;
  }
  v6.configuration[0] = *(unsigned __int64 *)((char *)shader_config.configuration + 4);
  LODWORD(v6.configuration[1]) = HIDWORD(shader_config.configuration[1]);
  vostok::render::shader_macros::fill_shader_configuration_macros(
    v3,
    v4,
    *(vostok::render::shader_macros **)&shader_config.0,
    v6);
}
