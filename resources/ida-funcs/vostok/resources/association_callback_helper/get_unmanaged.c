void __thiscall vostok::resources::association_callback_helper::get_unmanaged(
        vostok::resources::association_callback_helper *this,
        vostok::particle::particle_system_instance_impl **association)
{
  vostok::particle::particle_system_instance_impl *v2; // edi

  v2 = *association;
  if ( *association )
  {
    if ( v2->type == 4 )
      vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
        &this->unmanaged,
        v2);
  }
}
