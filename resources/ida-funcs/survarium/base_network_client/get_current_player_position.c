vostok::math::float3 *__thiscall survarium::base_network_client::get_current_player_position(
        survarium::base_network_client *this,
        vostok::math::float3 *result)
{
  survarium::player *m_object; // eax
  vostok::math::float3 *v3; // eax
  vostok::math::float3 *v4; // esi
  vostok::math::float3 *v5; // eax
  _DWORD v6[3]; // [esp+0h] [ebp-Ch] BYREF

  m_object = this->m_current_player.m_object;
  if ( m_object )
  {
    v3 = (vostok::math::float3 *)&m_object->transform(&m_object->survarium::collision_user)->lines[3];
  }
  else
  {
    memset(v6, 0, sizeof(v6));
    v3 = (vostok::math::float3 *)v6;
  }
  v4 = v3;
  v5 = result;
  *result = *v4;
  return v5;
}
