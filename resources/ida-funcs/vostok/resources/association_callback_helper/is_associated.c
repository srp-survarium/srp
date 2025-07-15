void __thiscall vostok::resources::association_callback_helper::is_associated(
        vostok::resources::association_callback_helper *this,
        vostok::resources::resource_base **association)
{
  vostok::resources::resource_base *resource; // eax

  resource = this->resource;
  if ( resource )
    this->associated = *association == resource;
  else
    this->associated = 0;
}
