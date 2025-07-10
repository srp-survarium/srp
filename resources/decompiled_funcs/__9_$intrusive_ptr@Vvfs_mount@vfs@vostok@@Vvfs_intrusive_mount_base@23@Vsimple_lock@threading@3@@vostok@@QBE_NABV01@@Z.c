BOOL __usercall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator!=@<eax>(
        const stlp_std::reverse_iterator<unsigned int *> *__x@<eax>,
        const stlp_std::reverse_iterator<unsigned int *> *__y@<edx>)
{
  return __x->current != __y->current;
}
