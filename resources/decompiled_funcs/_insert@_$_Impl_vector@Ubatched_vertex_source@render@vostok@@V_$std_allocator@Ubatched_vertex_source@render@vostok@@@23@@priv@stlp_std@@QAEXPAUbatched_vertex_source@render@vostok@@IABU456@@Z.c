void __userpurge stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::insert(
        stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source> > *this@<ecx>,
        const stlp_std::__true_type *__n@<esi>,
        const vostok::render::batched_vertex_source *__x@<eax>,
        vostok::render::batched_vertex_source *__pos)
{
  unsigned int v4; // [esp+0h] [ebp-8h]
  bool v5; // [esp+4h] [ebp-4h]

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < (unsigned int)__n )
      stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::_M_insert_overflow(
        this,
        __pos,
        __x,
        __n,
        v4,
        v5);
    else
      stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::_M_fill_insert_aux(
        this,
        __pos,
        (unsigned int)__n,
        __x,
        (const stlp_std::__false_type *)&__pos);
  }
}
