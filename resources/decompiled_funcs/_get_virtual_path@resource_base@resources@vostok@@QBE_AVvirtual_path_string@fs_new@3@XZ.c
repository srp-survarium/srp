vostok::fs_new::virtual_path_string *__usercall vostok::resources::resource_base::get_virtual_path@<eax>(
        vostok::resources::resource_base *this@<ecx>,
        vostok::fs_new::virtual_path_string *a2@<esi>)
{
  vostok::vfs::vfs_iterator::get_virtual_path(&this->m_fat_it, a2);
  return a2;
}
