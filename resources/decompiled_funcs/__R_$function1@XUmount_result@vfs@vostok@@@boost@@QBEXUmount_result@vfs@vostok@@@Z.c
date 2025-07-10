void __thiscall boost::function1<void,vostok::vfs::mount_result>::operator()(
        boost::function1<void,vostok::vfs::mount_result> *this,
        vostok::vfs::mount_result a0)
{
  const std::exception *v2; // eax
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v3[4]; // [esp-8h] [ebp-150h] BYREF
  const boost::function1<void,vostok::vfs::mount_result> *thisa; // [esp+8h] [ebp-140h]
  unsigned int v5; // [esp+10h] [ebp-138h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v6; // [esp+14h] [ebp-134h]
  boost::bad_function_call v7; // [esp+38h] [ebp-110h] BYREF

  thisa = this;
  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v7);
    boost::throw_exception(v2);
    boost::bad_function_call::~bad_function_call(&v7);
  }
  v6 = v3;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    v3,
    &a0.mount);
  v6[1].m_object = (vostok::vfs::vfs_mount *)a0.result;
  v5 = (int)thisa->vtable & 0xFFFFFFFE;
  (*(void (__cdecl **)(boost::detail::function::function_buffer *))(v5 + 4))(&thisa->functor);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&a0.mount);
}
