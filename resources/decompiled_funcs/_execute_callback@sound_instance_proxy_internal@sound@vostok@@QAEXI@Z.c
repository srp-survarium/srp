void __thiscall vostok::sound::sound_instance_proxy_internal::execute_callback(
        vostok::sound::sound_instance_proxy_internal *this,
        unsigned int playback_id)
{
  _InterlockedExchange(&this->m_callback_pending, 0);
  if ( (this->m_callback.vtable != 0
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0
    && this->m_is_playing
    && this->m_playback_id == playback_id )
  {
    boost::function0<void>::operator()(&this->m_callback);
  }
  this->m_is_playing = 0;
}
