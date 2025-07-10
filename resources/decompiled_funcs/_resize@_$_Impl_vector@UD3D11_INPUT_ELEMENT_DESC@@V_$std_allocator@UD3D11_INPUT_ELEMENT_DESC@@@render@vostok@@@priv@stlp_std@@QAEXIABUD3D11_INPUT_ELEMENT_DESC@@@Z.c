void __userpurge stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC>>::resize(
        unsigned int __new_size@<eax>,
        stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC> > *this,
        const D3D11_INPUT_ELEMENT_DESC *__x)
{
  D3D11_INPUT_ELEMENT_DESC *M_finish; // esi
  int v4; // ecx
  D3D11_INPUT_ELEMENT_DESC *v5; // eax

  M_finish = this->_M_finish;
  v4 = (char *)M_finish - (char *)this->_M_start;
  if ( __new_size >= v4 / 28 )
  {
    stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC>>::_M_fill_insert(
      this,
      M_finish,
      __new_size - v4 / 28,
      __x);
  }
  else
  {
    v5 = &this->_M_start[__new_size];
    if ( v5 != M_finish )
      this->_M_finish = v5;
  }
}
