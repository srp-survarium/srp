void __thiscall vostok::sound::sound_world::free_sound_buffer(
        vostok::sound::sound_world *this,
        vostok::sound::sound_buffer *buffer)
{
  --buffer->m_reference_count;
}
