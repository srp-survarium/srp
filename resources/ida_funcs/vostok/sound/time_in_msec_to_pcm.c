unsigned int __cdecl vostok::sound::time_in_msec_to_pcm(
        const vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *encoded_sound,
        unsigned int time)
{
  return encoded_sound->m_object->m_samples_per_sec * time / 0x3E8;
}
