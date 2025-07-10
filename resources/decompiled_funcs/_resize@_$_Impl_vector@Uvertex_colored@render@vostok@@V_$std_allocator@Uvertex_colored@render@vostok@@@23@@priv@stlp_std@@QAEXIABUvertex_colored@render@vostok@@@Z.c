void __thiscall stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored>>::resize(
        stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored> > *this)
{
  vostok::render::vertex_colored *M_finish; // ecx
  vostok::render::vertex_colored *M_start; // edx

  M_finish = this->_M_finish;
  M_start = this->_M_start;
  if ( M_finish - this->_M_start )
  {
    if ( M_start != M_finish )
      this->_M_finish = M_start;
  }
}
