const vostok::math::float4x4 *__thiscall survarium::player::get_transform(survarium::player *this)
{
  return (const vostok::math::float4x4 *)&this->m_current.animation_player.m_callbacks_buffer.m_size;
}
