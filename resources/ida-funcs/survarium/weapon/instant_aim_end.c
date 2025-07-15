void __thiscall survarium::weapon::instant_aim_end(survarium::weapon *this)
{
  survarium::base_player *m_user; // eax
  int v3; // ecx
  const vostok::math::float4x4 *v4; // xmm0_4

  survarium::weapon_core::instant_aim_end(this);
  if ( this->m_game_ui )
  {
    m_user = this->m_user;
    v3 = *(int *)((char *)&dword_10F0C + (_DWORD)m_user);
    m_user[244].m_character_head_transform.k.y = m_user[244].m_character_head_transform.k.z;
    *(float *)((char *)&dword_10F24 + (_DWORD)m_user) = s_aim_transition_time;
    v4 = clear_value;
    *(int *)((char *)&dword_10F28 + (_DWORD)m_user) = v3;
    *(int *)((char *)&dword_10F18 + (_DWORD)m_user) = (int)v4;
    *(_DWORD *)(*(int *)((char *)&dword_10EF4 + (unsigned int)this->m_user) + 416) = 1;
  }
}
