void __thiscall vostok::ai::sound_item::sound_item(
        vostok::ai::sound_item *this,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *new_emitter,
        const char *filename)
{
  boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
    &this->sound,
    new_emitter);
  vostok::fs_new::path_string_impl::path_string_impl(&this->name, 47, &filename);
}
