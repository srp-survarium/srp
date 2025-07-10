BOOL __thiscall vostok::sound::sound_voice::can_be_deleted(vostok::sound::sound_voice *this)
{
  return this->m_buffers_queued == 0;
}
