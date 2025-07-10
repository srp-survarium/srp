void __userpurge stlp_std::priv::_Impl_vector<vostok::render::branch_vertex,vostok::render::std_allocator<vostok::render::branch_vertex>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<vostok::render::frond_vertex,vostok::render::std_allocator<vostok::render::frond_vertex> > *this@<ecx>,
        unsigned int __n@<edi>,
        vostok::render::frond_vertex *__pos,
        const vostok::render::frond_vertex *__x)
{
  bool v4; // [esp+0h] [ebp-Ch]

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < __n )
      stlp_std::priv::_Impl_vector<vostok::render::frond_vertex,vostok::render::std_allocator<vostok::render::frond_vertex>>::_M_insert_overflow(
        __n,
        this,
        this,
        __pos,
        __x,
        0,
        v4);
    else
      stlp_std::priv::_Impl_vector<vostok::render::frond_vertex,vostok::render::std_allocator<vostok::render::frond_vertex>>::_M_fill_insert_aux(
        this,
        __pos,
        __n,
        __x,
        (const stlp_std::__false_type *)&__x);
  }
}
