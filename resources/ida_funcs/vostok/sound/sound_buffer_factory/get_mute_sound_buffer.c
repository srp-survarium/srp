vostok::sound::sound_buffer *__thiscall vostok::sound::sound_buffer_factory::get_mute_sound_buffer(
        vostok::sound::sound_buffer_factory *this,
        const vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *encoded_sound)
{
  vostok::sound::sound_buffer::fill_mute_buffer(this->m_mute_buffer, encoded_sound);
  return this->m_mute_buffer;
}
