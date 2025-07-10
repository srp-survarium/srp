void __userpurge stlp_std::priv::_Impl_vector<vostok::render::branch_vertex,vostok::render::std_allocator<vostok::render::branch_vertex>>::resize(
        unsigned int __new_size@<eax>,
        stlp_std::priv::_Impl_vector<vostok::render::frond_vertex,vostok::render::std_allocator<vostok::render::frond_vertex> > *this,
        const vostok::render::frond_vertex *__x)
{
  vostok::render::frond_vertex *M_finish; // esi
  int v4; // ecx
  vostok::render::frond_vertex *v5; // eax

  M_finish = this->_M_finish;
  v4 = (char *)M_finish - (char *)this->_M_start;
  if ( __new_size >= v4 / 56 )
  {
    stlp_std::priv::_Impl_vector<vostok::render::branch_vertex,vostok::render::std_allocator<vostok::render::branch_vertex>>::_M_fill_insert(
      this,
      M_finish,
      __new_size - v4 / 56,
      __x);
  }
  else
  {
    v5 = &this->_M_start[__new_size];
    if ( v5 != M_finish )
      this->_M_finish = v5;
  }
}
