void __thiscall vostok::buffer_vector<stlp_std::pair<vostok::ai::game_object const *,enum vostok::ai::ignorance_types_enum>>::erase(
        vostok::buffer_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> > *this,
        stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> **begin,
        stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> **end)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *k; // [esp+8h] [ebp-24h]
  survarium::hit_affects_type_enum *v9; // [esp+Ch] [ebp-20h]
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *j; // [esp+18h] [ebp-14h]
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *i; // [esp+1Ch] [ebp-10h]
  unsigned int size; // [esp+20h] [ebp-Ch]
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
      v9 = (survarium::hit_affects_type_enum *)operator new(8u, i);
      if ( v9 )
      {
        *v9 = j->first;
        v9[1] = (survarium::hit_affects_type_enum)j->second;
      }
      ++i;
    }
    count = *end - *begin;
    size = this->m_end - this->m_begin;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    for ( k = &this->m_begin[size - count]; k != this->m_end; ++k )
      ;
    this->m_end = &this->m_begin[size - count];
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  }
}
