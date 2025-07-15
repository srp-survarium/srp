void __usercall vostok::render::res_input_layout::res_input_layout(
        vostok::render::res_input_layout *this@<esi>,
        const vostok::render::res_declaration *decl@<eax>,
        const vostok::render::res_signature *signature@<ecx>)
{
  vostok::render::device *v4; // eax
  const vostok::render::res_declaration *m_declaration; // ecx
  ID3D10Blob *m_signature; // ebx
  D3D11_INPUT_ELEMENT_DESC *m_end; // eax
  void (__stdcall **v8)(_DWORD *, unsigned int, int, int); // edi
  int v9; // eax
  int v10; // eax
  unsigned int m_reference_count; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+10h] [ebp-8h]
  _DWORD *v13; // [esp+14h] [ebp-4h]

  this->m_reference_count = 0;
  this->m_declaration = decl;
  this->m_signature.m_object = 0;
  if ( signature )
  {
    vostok::intrusive_ptr<vostok::render::res_signature const,vostok::render::res_signature const,vostok::threading::single_threading_policy>::dec(&this->m_signature);
    this->m_signature.m_object = signature;
    ++signature->m_reference_count;
  }
  this->m_hw_input_layout = 0;
  v4 = vostok::quasi_singleton<vostok::render::device>::pinst;
  m_declaration = this->m_declaration;
  this->m_is_registered = 0;
  m_signature = signature->m_signature;
  v13 = &v4->m_device->lpVtbl;
  m_end = m_declaration->dcl_code.m_end;
  m_declaration = (const vostok::render::res_declaration *)((char *)m_declaration + 1040);
  v12 = (int)((int)m_end - m_declaration->m_reference_count) / 28;
  m_reference_count = m_declaration->m_reference_count;
  v8 = (void (__stdcall **)(_DWORD *, unsigned int, int, int))(*v13 + 44);
  v9 = ((int (__stdcall *)(ID3D10Blob *, ID3D11InputLayout **))m_signature->GetBufferSize)(
         m_signature,
         &this->m_hw_input_layout);
  v10 = ((int (__stdcall *)(ID3D10Blob *, int))m_signature->GetBufferPointer)(m_signature, v9);
  (*v8)(v13, m_reference_count, v12, v10);
}
