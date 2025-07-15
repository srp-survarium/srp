void __thiscall vostok::resources::association_callback_helper::get_managed(
        vostok::resources::association_callback_helper *this,
        vostok::resources::managed_resource **association)
{
  vostok::resources::managed_resource *v2; // edi

  v2 = *association;
  if ( *association )
  {
    if ( v2->type == 1 )
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        &this->managed,
        v2);
  }
}
