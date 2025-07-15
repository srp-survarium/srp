void __thiscall vostok::sound::destroy_sound_instance_proxy_order::execute(
        vostok::sound::destroy_sound_instance_proxy_order *this)
{
  vostok::sound::sound_world::process_destroy_sound_instance_proxy(this->m_user->m_owner_world, this);
}
