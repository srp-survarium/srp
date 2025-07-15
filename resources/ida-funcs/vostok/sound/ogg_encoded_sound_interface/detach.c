void __thiscall vostok::sound::ogg_encoded_sound_interface::detach(vostok::sound::ogg_encoded_sound_interface *this)
{
  if ( !--this->m_active_count )
    ov_clear(&this->m_ovf);
}
