void __userpurge vostok::vfs::vfs_mount::vfs_mount(
        vostok::vfs::vfs_mount *this@<ecx>,
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *a2@<esi>,
        vostok::vfs::vfs_mount *mount_root,
        vostok::memory::base_allocator *allocator)
{
  a2->m_object = 0;
  a2[1].m_object = 0;
  a2[2].m_object = 0;
  a2[3].m_object = 0;
  a2[4].m_object = 0;
  a2[5].m_object = 0;
  a2[6].m_object = 0;
  a2[7].m_object = 0;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    a2 + 8,
    0);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    a2 + 9,
    0);
  a2[10].m_object = 0;
  a2[11].m_object = 0;
  a2[12].m_object = 0;
  a2[13].m_object = 0;
  a2[14].m_object = mount_root;
  a2[15].m_object = (vostok::vfs::vfs_mount *)1;
}
