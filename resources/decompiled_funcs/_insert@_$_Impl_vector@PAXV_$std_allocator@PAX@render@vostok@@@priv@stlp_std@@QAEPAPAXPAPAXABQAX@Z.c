void **__userpurge stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::insert@<eax>(
        void **__pos@<eax>,
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *__x@<ecx>,
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *this)
{
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v3; // edi
  int v4; // esi
  bool v6; // [esp+0h] [ebp-8h]

  v3 = this;
  v4 = __pos - this->_M_start;
  if ( this->_M_end_of_storage._M_data - this->_M_finish )
    stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *>>::_M_fill_insert_aux(
      (stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *> > *)this,
      __pos,
      1u,
      (void **)&__x->_M_start,
      (const stlp_std::__false_type *)&this);
  else
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
      __x,
      (int)this,
      __pos,
      (void *const *)&__x->_M_start,
      (const stlp_std::__true_type *)1,
      0,
      v6);
  return &v3->_M_start[v4];
}
