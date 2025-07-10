vostok::math::float3 *__thiscall survarium::base_network_client::get_current_player_position(
        survarium::base_network_client *this,
        vostok::math::float3 *result)
{
  survarium::player *m_object; // eax
  float *p_x; // ecx
  __int64 v4; // xmm0_8
  vostok::math::float3 *v5; // eax
  float v6; // ecx
  _DWORD v7[3]; // [esp+0h] [ebp-Ch] BYREF

  m_object = this->m_current_player.m_object;
  if ( m_object )
  {
    p_x = &m_object->m_current.transform.c.x;
  }
  else
  {
    memset(v7, 0, sizeof(v7));
    p_x = (float *)v7;
  }
  v4 = *(_QWORD *)p_x;
  v5 = result;
  v6 = p_x[2];
  *(_QWORD *)&result->x = v4;
  result->z = v6;
  return v5;
}
