void __thiscall vostok::sound::sound_world::free_sound_buffer(
        vostok::sound::sound_world *this,
        vostok::sound::sound_buffer *buffer)
{
  vostok::sound::sound_buffer_factory::delete_sound_buffer(this->m_sound_buffer_factory, buffer);
}
