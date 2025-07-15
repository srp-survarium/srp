vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::set_alpha_blend@<eax>(
        vostok::render::effect_compiler *this@<ecx>,
        int a2@<esi>,
        int blend_enable,
        D3D11_BLEND src_blend,
        D3D11_BLEND dest_blend,
        D3D11_BLEND_OP blend_op,
        D3D11_BLEND src_alpha_blend,
        D3D11_BLEND dest_alpha_blend,
        D3D11_BLEND_OP blend_alpha_op)
{
  _DWORD *v9; // eax
  int v10; // ecx

  if ( !byte_61F4C[a2]
    && !vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_no_effect_result) )
  {
    v9 = (_DWORD *)((char *)&loc_503A4 + a2);
    v10 = 8;
    do
    {
      *(v9 - 1) = blend_enable;
      *v9 = src_blend;
      v9[1] = dest_blend;
      v9[2] = blend_op;
      v9[3] = src_alpha_blend;
      v9[4] = dest_alpha_blend;
      v9[5] = 1;
      v9 += 8;
      --v10;
    }
    while ( v10 );
  }
  return (vostok::render::effect_compiler *)a2;
}
