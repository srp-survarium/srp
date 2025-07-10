float __thiscall vostok::sound::world_user::get_time_scale_factor(vostok::sound::world_user *this)
{
  return vostok::sound::sound_world::get_time_scale_factor(this->m_owner_world);
}
