void __thiscall survarium::body_part_parameters::update_affects(
        survarium::body_part_parameters *this,
        unsigned int current_time_in_ms)
{
  const vostok::variant<32> **v2; // eax
  survarium::hit_affects_type_enum first; // [esp-8h] [ebp-48h]
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *end; // [esp+28h] [ebp-18h] BYREF
  char v6; // [esp+2Fh] [ebp-11h]
  survarium::game_camera *m_begin; // [esp+30h] [ebp-10h]
  vostok::fixed_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int>,8> *p_m_affects; // [esp+34h] [ebp-Ch]
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *it_affect; // [esp+38h] [ebp-8h] BYREF
  int i; // [esp+3Ch] [ebp-4h]

  p_m_affects = &this->m_affects;
  for ( i = this->m_affects.m_end - this->m_affects.m_begin - 1; i >= 0; --i )
  {
    m_begin = (survarium::game_camera *)this->m_affects.m_begin;
    it_affect = (stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *)m_begin;
    v6 = 0;
    survarium::weapon_user_dead_state::finalize(m_begin);
    if ( this->m_affects.m_begin[i].second <= current_time_in_ms )
    {
      it_affect += i;
      first = it_affect->first;
      v2 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
             (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)it_affect,
             (int)&this->m_name);
      survarium::damage_model::notify_on_affect_event(this->m_damage_model, (const char *)v2, first, affect_recalling);
      end = it_affect + 1;
      vostok::buffer_vector<stlp_std::pair<vostok::ai::game_object const *,enum vostok::ai::ignorance_types_enum>>::erase(
        &this->m_affects,
        &it_affect,
        &end);
    }
  }
}
