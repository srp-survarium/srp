vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::set_depth@<eax>(
        vostok::render::effect_compiler *this@<ecx>,
        int a2@<esi>,
        bool enable,
        bool write_enable,
        D3D11_COMPARISON_FUNC cmp_func)
{
  if ( !*(_BYTE *)(a2 + 37008) )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      *(_DWORD *)(a2 + 100) = enable;
      *(_DWORD *)(a2 + 108) = cmp_func;
      *(_BYTE *)(a2 + 421) = 1;
      *(_DWORD *)(a2 + 104) = write_enable;
    }
  }
  return (vostok::render::effect_compiler *)a2;
}
