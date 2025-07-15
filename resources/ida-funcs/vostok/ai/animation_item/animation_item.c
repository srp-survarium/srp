void __thiscall vostok::ai::animation_item::animation_item(
        vostok::ai::animation_item *this,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *new_item,
        const char *filename)
{
  boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
    &this->animation,
    new_item);
  vostok::fs_new::path_string_impl::path_string_impl(&this->name, 47, &filename);
}
