void __userpurge stlp_std::priv::_Impl_vector<vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex>>::resize(
        stlp_std::priv::_Impl_vector<vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex> > *this@<esi>,
        unsigned int __new_size@<edx>,
        const vostok::render::leafmesh_vertex *__x)
{
  vostok::render::leafmesh_vertex *M_finish; // ecx
  unsigned int v4; // eax
  vostok::render::leafmesh_vertex *v5; // eax
  unsigned int v6; // eax
  bool v7; // [esp+0h] [ebp-8h]

  M_finish = this->_M_finish;
  v4 = M_finish - this->_M_start;
  if ( __new_size >= v4 )
  {
    v6 = __new_size - v4;
    if ( v6 )
    {
      if ( this->_M_end_of_storage._M_data - M_finish < v6 )
        stlp_std::priv::_Impl_vector<vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex>>::_M_insert_overflow(
          this,
          M_finish,
          __x,
          0,
          v6,
          v7);
      else
        stlp_std::priv::_Impl_vector<vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex>>::_M_fill_insert_aux(
          this,
          M_finish,
          v6,
          __x,
          (const stlp_std::__false_type *)&__x);
    }
  }
  else
  {
    v5 = &this->_M_start[__new_size];
    if ( v5 != M_finish )
      this->_M_finish = v5;
  }
}
