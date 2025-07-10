void __thiscall vostok::resources::resource_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base> *this,
        const vostok::resources::resource_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base> *other)
{
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    this,
    other);
}
