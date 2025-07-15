void __thiscall vostok::resources::positional_unmanaged_resource::positional_unmanaged_resource(
        vostok::resources::positional_unmanaged_resource *this,
        unsigned int quality_levels_count)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(
    this,
    resource_flag_is_positional_unmanaged,
    quality_levels_count);
  this->matrix[1] = 0;
  this->matrix[0] = 0;
  this->__vftable = (vostok::resources::positional_unmanaged_resource_vtbl *)&vostok::resources::positional_unmanaged_resource::`vftable';
}
