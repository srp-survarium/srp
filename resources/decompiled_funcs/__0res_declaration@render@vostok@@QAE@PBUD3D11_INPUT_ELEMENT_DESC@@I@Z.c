void __usercall vostok::render::res_declaration::res_declaration(
        vostok::render::res_declaration *this@<esi>,
        stlp_std::forward_iterator_tag *decl@<edx>,
        unsigned int count@<ecx>)
{
  this->m_reference_count = 0;
  this->vs_to_layout._M_impl._M_start = 0;
  this->vs_to_layout._M_impl._M_finish = 0;
  this->vs_to_layout._M_impl._M_end_of_storage._M_data = 0;
  this->dcl_code._M_impl._M_start = 0;
  this->dcl_code._M_impl._M_finish = 0;
  this->dcl_code._M_impl._M_end_of_storage._M_data = 0;
  stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC>>::_M_range_initialize<D3D11_INPUT_ELEMENT_DESC const *>(
    (stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC> > *)&decl[28 * count],
    &this->dcl_code._M_impl,
    decl,
    (const D3D11_INPUT_ELEMENT_DESC *)&decl[28 * count]);
  this->m_is_registered = 0;
}
