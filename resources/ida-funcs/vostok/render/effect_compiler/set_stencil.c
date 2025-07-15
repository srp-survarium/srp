vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::set_stencil@<eax>(
        vostok::render::effect_compiler *this@<ecx>,
        int a2@<edi>,
        int enable,
        unsigned int ref,
        unsigned __int8 read_mask,
        unsigned __int8 write_mask,
        D3D11_COMPARISON_FUNC func,
        D3D11_STENCIL_OP fail,
        D3D11_STENCIL_OP pass,
        D3D11_STENCIL_OP zfail)
{
  vostok::command_line::key *v10; // ecx
  vostok::render::state_descriptor *v11; // ecx
  char *v12; // esi

  if ( !byte_61F4C[a2]
    && !vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_no_effect_result) )
  {
    v12 = (char *)&loc_5033B + a2 + 1;
    if ( vostok::command_line::key::is_set(v10, (int)&s_no_stencil) )
      vostok::render::state_descriptor::set_stencil(v11, (int)v12, 0, ref, read_mask, write_mask);
    else
      vostok::render::state_descriptor::set_stencil(v11, (int)v12, enable, ref, read_mask, write_mask);
    *((_DWORD *)v12 + 15) = 1;
    *((_DWORD *)v12 + 16) = pass;
    *((_DWORD *)v12 + 17) = fail;
    *((_DWORD *)v12 + 18) = func;
    *((_DWORD *)v12 + 19) = 1;
    *((_DWORD *)v12 + 20) = pass;
    *((_DWORD *)v12 + 21) = fail;
    *((_DWORD *)v12 + 22) = func;
    v12[361] = 1;
  }
  return (vostok::render::effect_compiler *)a2;
}
