void __thiscall boost::_mfi::mf2<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result,unsigned int>::operator()(
        boost::_mfi::mf2<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result,unsigned int> *this,
        vostok::vfs::async_callbacks_data *p,
        vostok::vfs::mount_result a1,
        unsigned int a2)
{
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v4[2]; // [esp-Ch] [ebp-28h] BYREF
  unsigned int v5; // [esp-4h] [ebp-20h]
  const boost::_mfi::mf2<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result,unsigned int> *thisa; // [esp+8h] [ebp-14h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v7; // [esp+10h] [ebp-Ch]

  thisa = this;
  v5 = a2;
  v7 = v4;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    v4,
    &a1.mount);
  v7[1].m_object = (vostok::vfs::vfs_mount *)a1.result;
  ((void (__thiscall *)(vostok::vfs::async_callbacks_data *, vostok::vfs::vfs_mount *, vostok::vfs::vfs_mount *, unsigned int))thisa->f_)(
    p,
    v4[0].m_object,
    v4[1].m_object,
    v5);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&a1.mount);
}
