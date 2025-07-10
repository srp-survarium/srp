void __usercall stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::clear(
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *this@<ecx>,
        void ***a2@<esi>)
{
  void **v2; // eax
  void **v3; // edi

  v2 = a2[1];
  if ( *a2 != v2 )
  {
    v3 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v2, v2, *a2);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>(v3, a2[1]);
    a2[1] = v3;
  }
}
