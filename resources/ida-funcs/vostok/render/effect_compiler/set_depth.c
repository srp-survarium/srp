vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::set_depth@<eax>(
        vostok::render::effect_compiler *this@<ecx>,
        int a2@<esi>,
        bool enable,
        bool write_enable,
        D3D11_COMPARISON_FUNC cmp_func)
{
  char *v5; // eax

  if ( !byte_61F4C[a2]
    && !vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_no_effect_result) )
  {
    v5 = (char *)&loc_5033B + a2 + 1;
    *((_DWORD *)v5 + 10) = enable;
    *((_DWORD *)v5 + 12) = 4;
    v5[361] = 1;
    *((_DWORD *)v5 + 11) = write_enable;
  }
  return (vostok::render::effect_compiler *)a2;
}
