void __thiscall vostok::sound::sound_instance_proxy_order::execute(vostok::sound::sound_instance_proxy_order *this)
{
  vostok::sound::sound_world::try_process_order(this->m_world_user_base->m_owner_world, this);
}
