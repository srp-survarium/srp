void __thiscall vostok::sound::encoded_sound_interface::encoded_sound_interface(
        vostok::sound::encoded_sound_interface *this)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  this->__vftable = (vostok::sound::encoded_sound_interface_vtbl *)&vostok::sound::encoded_sound_interface::`vftable';
  this->m_length_in_pcm = 0;
  this->m_length_in_msec = 0;
  this->m_samples_per_sec = 0;
  this->m_bytes_per_sample = 0;
  this->m_channels_num = 1;
}
