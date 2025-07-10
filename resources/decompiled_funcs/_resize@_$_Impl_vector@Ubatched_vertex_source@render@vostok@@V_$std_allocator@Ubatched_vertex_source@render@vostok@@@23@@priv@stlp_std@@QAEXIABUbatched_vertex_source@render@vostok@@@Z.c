void __userpurge stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::resize(
        unsigned int __new_size@<eax>,
        stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source> > *this,
        const vostok::render::batched_vertex_source *__x)
{
  unsigned int v4; // eax
  vostok::render::batched_vertex_source *v5; // eax

  v4 = this->_M_finish - this->_M_start;
  if ( __new_size >= v4 )
  {
    stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::insert(
      this,
      this->_M_finish,
      __new_size - v4,
      __x);
  }
  else
  {
    v5 = &this->_M_start[__new_size];
    if ( v5 != this->_M_finish )
      this->_M_finish = v5;
  }
}
