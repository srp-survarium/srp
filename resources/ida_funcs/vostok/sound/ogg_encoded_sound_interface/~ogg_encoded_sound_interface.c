void __thiscall vostok::sound::ogg_encoded_sound_interface::~ogg_encoded_sound_interface(
        vostok::sound::ogg_encoded_sound_interface *this)
{
  this->__vftable = (vostok::sound::ogg_encoded_sound_interface_vtbl *)&vostok::sound::ogg_encoded_sound_interface::`vftable';
  ov_clear(&this->m_ovf);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_raw_file.resource);
  this->__vftable = (vostok::sound::ogg_encoded_sound_interface_vtbl *)&vostok::sound::encoded_sound_interface::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
