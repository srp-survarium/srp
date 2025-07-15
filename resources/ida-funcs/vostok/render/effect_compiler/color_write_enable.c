vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::color_write_enable@<eax>(
        vostok::render::effect_compiler *this@<ecx>,
        int a2@<esi>,
        unsigned int rt_index,
        D3D11_COLOR_WRITE_ENABLE mode)
{
  _BYTE *v4; // eax

  if ( !byte_61F4C[a2]
    && !vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_no_effect_result) )
  {
    v4 = (char *)&loc_5033B + 32 * rt_index + a2 + 129;
    *((_BYTE *)&loc_504A3 + a2 + 3) |= (unsigned __int8)*v4 != mode;
    *v4 = mode;
  }
  return (vostok::render::effect_compiler *)a2;
}


vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::color_write_enable@<eax>(
        vostok::render::effect_compiler *this@<ecx>,
        int a2@<esi>,
        D3D11_COLOR_WRITE_ENABLE mode)
{
  _BYTE *v3; // eax
  int v4; // ecx

  if ( !byte_61F4C[a2]
    && !vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_no_effect_result) )
  {
    v3 = (char *)&loc_503BB + a2 + 1;
    *((_BYTE *)&loc_504A3 + a2 + 3) |= *((unsigned __int8 *)&loc_503BB + a2 + 1) != mode;
    v4 = 8;
    do
    {
      *v3 = mode;
      v3 += 32;
      --v4;
    }
    while ( v4 );
  }
  return (vostok::render::effect_compiler *)a2;
}
