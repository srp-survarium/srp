void __thiscall vostok::sound::sound_instance_proxy::sound_instance_proxy(vostok::sound::sound_instance_proxy *this)
{
  vostok::resources::positional_unmanaged_resource::positional_unmanaged_resource(this, 3u);
  this->__vftable = (vostok::sound::sound_instance_proxy_vtbl *)&vostok::sound::sound_instance_proxy::`vftable';
  this->m_callback.vtable = 0;
  this->m_id = s_sound_instance_proxy_id++;
  this->m_reference_count = 0;
  this->m_callback_pending = 0;
  this->m_is_playing_once = 0;
  this->m_is_playing = 0;
  this->m_is_producing_paused = 0;
  this->m_is_propagating_paused = 0;
}
