void __thiscall boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>::operator()(
        boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result> *this,
        vostok::vfs::async_callbacks_data *p,
        vostok::vfs::mount_result a1)
{
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v3[4]; // [esp-8h] [ebp-24h] BYREF
  const boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result> *thisa; // [esp+8h] [ebp-14h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v5; // [esp+10h] [ebp-Ch]

  thisa = this;
  v5 = v3;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    v3,
    &a1.mount);
  v5[1].m_object = (vostok::vfs::vfs_mount *)a1.result;
  ((void (__thiscall *)(vostok::vfs::async_callbacks_data *, vostok::vfs::vfs_mount *, vostok::vfs::vfs_mount *))thisa->f_)(
    p,
    v3[0].m_object,
    v3[1].m_object);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&a1.mount);
}
