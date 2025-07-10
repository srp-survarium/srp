void __thiscall survarium::body_part_parameters::apply_affect_by_force(
        survarium::body_part_parameters *this,
        survarium::hit_affects_type_enum affect,
        survarium::affect_event_type_enum event_type,
        unsigned int current_time_in_ms)
{
  const vostok::variant<32> **v4; // eax
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *v5; // ecx
  const vostok::variant<32> **v6; // eax
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *end; // [esp+28h] [ebp-34h] BYREF
  char v9; // [esp+2Fh] [ebp-2Dh]
  survarium::game_camera *p_m_affects; // [esp+30h] [ebp-2Ch]
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *m_begin; // [esp+34h] [ebp-28h]
  unsigned int v12; // [esp+44h] [ebp-18h]
  survarium::hit_affects_type_enum v13; // [esp+48h] [ebp-14h]
  stlp_std::pair<char *,unsigned int> value; // [esp+4Ch] [ebp-10h] BYREF
  unsigned int i; // [esp+54h] [ebp-8h]
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *it_affect; // [esp+58h] [ebp-4h] BYREF

  if ( event_type || survarium::body_part_parameters::is_affect_applied(this, affect) )
  {
    if ( event_type == affect_recalling )
    {
      m_begin = this->m_affects.m_begin;
      it_affect = m_begin;
      for ( i = 0; ; ++i )
      {
        p_m_affects = (survarium::game_camera *)&this->m_affects;
        if ( i >= this->m_affects.m_end - this->m_affects.m_begin )
          break;
        v9 = 0;
        survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_affects);
        if ( this->m_affects.m_begin[i].first == affect )
        {
          v5 = it_affect;
          it_affect += i;
          v6 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                 (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)v5,
                 (int)&this->m_name);
          survarium::damage_model::notify_on_affect_event(
            this->m_damage_model,
            (const char *)v6,
            affect,
            affect_recalling);
          end = it_affect + 1;
          vostok::buffer_vector<stlp_std::pair<vostok::ai::game_object const *,enum vostok::ai::ignorance_types_enum>>::erase(
            &this->m_affects,
            &it_affect,
            &end);
          return;
        }
      }
    }
  }
  else
  {
    v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(0, (int)&this->m_name);
    survarium::damage_model::notify_on_affect_event(this->m_damage_model, (const char *)v4, affect, affect_applying);
    v12 = current_time_in_ms + 1000 * affects_durations_16[affect];
    v13 = affect;
    value.first = (char *)affect;
    value.second = v12;
    vostok::buffer_vector<stlp_std::pair<vostok::ai::weapon const *,unsigned int>>::push_back(
      (vostok::buffer_vector<stlp_std::pair<char *,unsigned int> > *)&this->m_affects,
      &value);
  }
}
