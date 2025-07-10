void __thiscall vostok::buffer_vector<stlp_std::pair<vostok::ai::npc const *,float>>::erase(
        vostok::buffer_vector<stlp_std::pair<vostok::ai::npc const *,float> > *this,
        stlp_std::pair<vostok::ai::npc const *,float> **begin,
        stlp_std::pair<vostok::ai::npc const *,float> **end)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  stlp_std::pair<vostok::ai::npc const *,float> *k; // [esp+8h] [ebp-24h]
  float *v9; // [esp+Ch] [ebp-20h]
  stlp_std::pair<vostok::ai::npc const *,float> *j; // [esp+18h] [ebp-14h]
  stlp_std::pair<vostok::ai::npc const *,float> *i; // [esp+1Ch] [ebp-10h]
  survarium::game_camera *size; // [esp+20h] [ebp-Ch]
  unsigned int new_size; // [esp+24h] [ebp-8h]
  unsigned int count; // [esp+28h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_user_dead_state::finalize(v4);
  survarium::weapon_user_dead_state::finalize(v5);
  survarium::weapon_user_dead_state::finalize(v6);
  if ( *begin != *end )
  {
    i = *begin;
    for ( j = *end; j != this->m_end; ++j )
    {
      v9 = (float *)operator new(8u, i);
      if ( v9 )
      {
        *v9 = *(float *)&j->first;
        v9[1] = j->second;
      }
      ++i;
    }
    count = *end - *begin;
    size = (survarium::game_camera *)(this->m_end - this->m_begin);
    survarium::weapon_user_dead_state::finalize(size);
    new_size = (unsigned int)size - count;
    for ( k = &this->m_begin[(unsigned int)size - count]; k != this->m_end; ++k )
      ;
    this->m_end = &this->m_begin[new_size];
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)new_size);
  }
}
