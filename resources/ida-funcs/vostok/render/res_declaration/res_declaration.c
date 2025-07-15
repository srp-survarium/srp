void __userpurge vostok::render::res_declaration::res_declaration(
        const D3D11_INPUT_ELEMENT_DESC *decl@<eax>,
        unsigned int count@<ecx>,
        vostok::render::res_declaration *this)
{
  vostok::fixed_vector<D3D11_INPUT_ELEMENT_DESC,128>::allign_helper *m_buffer; // ecx
  int v5; // eax
  const D3D11_INPUT_ELEMENT_DESC *v6; // [esp+Ch] [ebp-4h]
  const D3D11_INPUT_ELEMENT_DESC *v7; // [esp+18h] [ebp+8h]

  this->m_reference_count = 0;
  this->vs_to_layout.m_begin = (vostok::render::signature_layout_pair *)this->vs_to_layout.m_buffer;
  this->vs_to_layout.m_end = (vostok::render::signature_layout_pair *)this->vs_to_layout.m_buffer;
  this->vs_to_layout.m_max_end = (vostok::render::signature_layout_pair *)&this->dcl_code;
  v6 = &decl[count];
  m_buffer = this->dcl_code.m_buffer;
  this->dcl_code.m_max_end = (D3D11_INPUT_ELEMENT_DESC *)&this->m_is_registered;
  this->dcl_code.m_begin = (D3D11_INPUT_ELEMENT_DESC *)this->dcl_code.m_buffer;
  v7 = decl;
  this->dcl_code.m_end = (D3D11_INPUT_ELEMENT_DESC *)&this->dcl_code.m_buffer[v6 - decl];
  if ( decl != v6 )
  {
    v5 = (char *)m_buffer - (char *)decl;
    do
    {
      if ( (const D3D11_INPUT_ELEMENT_DESC *)((char *)v7 + v5) )
        qmemcpy((char *)v7 + v5, v7, sizeof(const D3D11_INPUT_ELEMENT_DESC));
      ++v7;
    }
    while ( v7 != v6 );
  }
  this->m_is_registered = 0;
}
