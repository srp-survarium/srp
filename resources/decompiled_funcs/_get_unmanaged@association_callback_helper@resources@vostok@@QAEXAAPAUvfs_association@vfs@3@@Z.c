void __thiscall vostok::resources::association_callback_helper::get_unmanaged(
        vostok::resources::association_callback_helper *this,
        vostok::vfs::vfs_association **association)
{
  vostok::configs::binary_config *v2; // eax

  v2 = (vostok::configs::binary_config *)*association;
  if ( *association )
  {
    if ( v2->type == 4 )
      vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
        &this->unmanaged,
        v2);
  }
}
