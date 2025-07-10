vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::color_write_enable@<eax>(
        vostok::render::effect_compiler *this@<ecx>,
        int a2@<esi>,
        D3D11_COLOR_WRITE_ENABLE mode)
{
  if ( !*(_BYTE *)(a2 + 37008) )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
      vostok::render::state_descriptor::color_write_enable((vostok::render::state_descriptor *)(a2 + 60), mode);
  }
  return (vostok::render::effect_compiler *)a2;
}
