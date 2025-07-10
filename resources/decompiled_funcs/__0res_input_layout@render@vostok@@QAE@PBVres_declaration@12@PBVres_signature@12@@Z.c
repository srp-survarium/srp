void __usercall vostok::render::res_input_layout::res_input_layout(
        vostok::render::res_input_layout *this@<esi>,
        const vostok::render::res_declaration *decl@<edx>,
        const vostok::render::res_signature *signature@<eax>,
        int a4)
{
  const vostok::render::res_declaration *m_declaration; // ebp
  ID3D10Blob *m_signature; // edi
  int v6; // ebx
  void (__stdcall **v7)(void *, int, int, int); // ebp
  int v8; // eax
  int v9; // eax
  void *retaddr; // [esp+14h] [ebp+0h]

  this->m_reference_count = 0;
  this->m_declaration = decl;
  this->m_signature.m_object = 0;
  if ( signature )
  {
    this->m_signature.m_object = signature;
    ++signature->m_reference_count;
  }
  m_declaration = this->m_declaration;
  this->m_is_registered = 0;
  this->m_hw_input_layout = 0;
  m_signature = signature->m_signature;
  v6 = m_declaration->dcl_code._M_impl._M_finish - m_declaration->dcl_code._M_impl._M_start;
  v7 = (void (__stdcall **)(void *, int, int, int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                  + 44);
  v8 = ((int (__stdcall *)(ID3D10Blob *, ID3D11InputLayout **))m_signature->GetBufferSize)(
         m_signature,
         &this->m_hw_input_layout);
  v9 = ((int (__stdcall *)(ID3D10Blob *, int))m_signature->GetBufferPointer)(m_signature, v8);
  (*v7)(retaddr, a4, v6, v9);
}
