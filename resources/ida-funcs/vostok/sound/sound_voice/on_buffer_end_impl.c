void __thiscall vostok::sound::sound_voice::on_buffer_end_impl(vostok::sound::sound_voice *this, void *__formal)
{
  if ( this->m_is_playing )
    vostok::sound::sound_voice::refill_buffers(this, (int)this);
}
