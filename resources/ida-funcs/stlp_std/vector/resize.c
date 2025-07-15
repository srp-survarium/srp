void __userpurge stlp_std::vector<vostok::ui::undo_,vostok::vectora_allocator<void *>>::resize(
        stlp_std::vector<vostok::ui::undo_,vostok::vectora_allocator<void *> > *this@<edi>,
        unsigned int __new_size@<eax>,
        const vostok::ui::undo_ *__x)
{
  unsigned int v3; // ecx
  vostok::ui::undo_ *v4; // eax

  v3 = this->_M_impl._M_finish - this->_M_impl._M_start;
  if ( __new_size >= v3 )
  {
    stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_>>::insert(
      &this->_M_impl,
      this->_M_impl._M_finish,
      __new_size - v3,
      __x);
  }
  else
  {
    v4 = &this->_M_impl._M_start[__new_size];
    if ( v4 != this->_M_impl._M_finish )
      this->_M_impl._M_finish = v4;
  }
}
