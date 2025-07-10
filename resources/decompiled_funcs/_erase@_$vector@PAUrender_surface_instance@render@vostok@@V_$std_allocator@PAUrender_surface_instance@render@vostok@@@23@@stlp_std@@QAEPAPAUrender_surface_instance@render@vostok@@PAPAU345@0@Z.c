void **__userpurge stlp_std::vector<vostok::render::render_surface_instance *,vostok::render::std_allocator<vostok::render::render_surface_instance *>>::erase@<eax>(
        void **__first@<edi>,
        void **__last@<eax>,
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *this)
{
  void **v3; // esi

  if ( __first != __last )
  {
    v3 = stlp_std::priv::__copy_ptrs<void * *,void * *>(__last, this->_M_finish, __first);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>(v3, this->_M_finish);
    this->_M_finish = v3;
  }
  return __first;
}
