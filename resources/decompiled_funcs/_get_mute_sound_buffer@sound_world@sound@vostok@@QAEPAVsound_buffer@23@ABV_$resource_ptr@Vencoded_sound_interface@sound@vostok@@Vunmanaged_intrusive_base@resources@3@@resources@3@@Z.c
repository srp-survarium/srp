vostok::sound::sound_buffer *__thiscall vostok::sound::sound_world::get_mute_sound_buffer(
        vostok::sound::sound_world *this,
        const vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *encoded_sound)
{
  return vostok::sound::sound_buffer_factory::get_mute_sound_buffer(this->m_sound_buffer_factory, encoded_sound);
}
