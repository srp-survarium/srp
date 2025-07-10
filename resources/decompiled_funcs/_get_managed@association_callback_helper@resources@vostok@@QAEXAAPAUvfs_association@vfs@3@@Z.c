void __thiscall vostok::resources::association_callback_helper::get_managed(
        vostok::resources::association_callback_helper *this,
        vostok::vfs::vfs_association **association)
{
  vostok::resources::managed_resource *v3; // eax
  vostok::resources::managed_resource *v4; // [esp-4h] [ebp-Ch]

  if ( *association )
  {
    if ( (*association)->type == 1 )
    {
      v4 = (vostok::resources::managed_resource *)*association;
      association = 0;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&association,
        v4);
      v3 = (vostok::resources::managed_resource *)association;
      association = (vostok::vfs::vfs_association **)this->managed.m_object;
      this->managed.m_object = v3;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&association);
    }
  }
}
