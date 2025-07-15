void __thiscall vostok::sound::sound_voice::on_buffer_end_impl(
        vostok::sound::sound_voice *this,
        vostok::sound::sound_buffer *pcontext)
{
  _InterlockedExchangeAdd(&this->m_buffers_queued, 0xFFFFFFFF);
  if ( pcontext )
  {
    if ( this->m_is_playing && (!this->m_conv_state || this->m_conv_state == 4) )
      vostok::sound::sound_voice::refill_buffers(this);
    vostok::sound::sound_world::free_sound_buffer(this->m_world_user->m_owner_world, pcontext);
  }
}
