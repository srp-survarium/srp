void __userpurge vostok::render::signature_layout_pair::signature_layout_pair(
        vostok::render::signature_layout_pair *this@<esi>,
        const vostok::render::res_signature *signature@<eax>,
        const vostok::render::res_declaration *decl)
{
  D3D11_INPUT_ELEMENT_DESC *input_layout; // eax
  vostok::render::res_input_layout *v4; // ecx
  vostok::render::res_input_layout *m_object; // eax

  this->input_layout.m_object = 0;
  this->signature.m_object = 0;
  if ( signature )
  {
    this->signature.m_object = signature;
    ++signature->m_reference_count;
  }
  input_layout = vostok::render::resource_manager::create_input_layout(
                   (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                   (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                   decl,
                   (vostok::render::res_input_layout *)signature);
  v4 = 0;
  if ( input_layout )
  {
    ++input_layout->SemanticName;
    v4 = (vostok::render::res_input_layout *)input_layout;
  }
  m_object = this->input_layout.m_object;
  this->input_layout.m_object = v4;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
}
