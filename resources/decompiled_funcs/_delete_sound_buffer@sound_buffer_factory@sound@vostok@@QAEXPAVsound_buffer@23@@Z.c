void __thiscall vostok::sound::sound_buffer_factory::delete_sound_buffer(
        vostok::sound::sound_buffer_factory *this,
        vostok::sound::sound_buffer *buffer)
{
  --buffer->m_reference_count;
}
