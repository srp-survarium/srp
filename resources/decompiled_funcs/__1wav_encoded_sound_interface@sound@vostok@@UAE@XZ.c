void __thiscall vostok::sound::wav_encoded_sound_interface::~wav_encoded_sound_interface(
        vostok::sound::wav_encoded_sound_interface *this)
{
  this->__vftable = (vostok::sound::wav_encoded_sound_interface_vtbl *)&vostok::sound::wav_encoded_sound_interface::`vftable';
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_wav_file.resource);
  this->__vftable = (vostok::sound::wav_encoded_sound_interface_vtbl *)&vostok::sound::encoded_sound_interface::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
