void __userpurge stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex> > *this@<ecx>,
        const vostok::render::ui::vertex *__x@<eax>,
        vostok::render::ui::vertex *__pos,
        const stlp_std::__true_type *__n)
{
  unsigned int v4; // [esp+0h] [ebp-Ch]
  bool v5; // [esp+4h] [ebp-8h]

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < (unsigned int)__n )
      stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::_M_insert_overflow(
        this,
        __pos,
        __x,
        __n,
        v4,
        v5);
    else
      stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::_M_fill_insert_aux(
        this,
        __pos,
        (unsigned int)__n,
        __x,
        (const stlp_std::__false_type *)&__n);
  }
}
