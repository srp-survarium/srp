void __thiscall survarium::body_part_parameters::apply_affects(
        survarium::body_part_parameters *this,
        const survarium::affects_threshold *threshold_reached,
        unsigned int current_time_in_ms)
{
  const vostok::variant<32> **v3; // eax
  survarium::hit_affects_type_enum v4; // [esp-8h] [ebp-40h]
  unsigned int v6; // [esp+10h] [ebp-28h]
  stlp_std::pair<char *,unsigned int> value; // [esp+24h] [ebp-14h] BYREF
  const survarium::hit_affects_type_enum *it; // [esp+2Ch] [ebp-Ch]
  const survarium::hit_affects_type_enum *it_begin; // [esp+30h] [ebp-8h]
  const survarium::hit_affects_type_enum *it_end; // [esp+34h] [ebp-4h]

  it_begin = (const survarium::hit_affects_type_enum *)&threshold_reached[1];
  it_end = (const survarium::hit_affects_type_enum *)(&threshold_reached[1].next + threshold_reached->m_affects_count);
  for ( it = (const survarium::hit_affects_type_enum *)&threshold_reached[1]; it != it_end; ++it )
  {
    if ( !survarium::body_part_parameters::is_affect_applied(this, *it)
      && !survarium::body_part_parameters::has_affect_protector(this, *it) )
    {
      v4 = *it;
      v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(0, (int)&this->m_name);
      survarium::damage_model::notify_on_affect_event(this->m_damage_model, (const char *)v3, v4, affect_applying);
      v6 = current_time_in_ms + 1000 * affects_durations_16[*it];
      value.first = (char *)*it;
      value.second = v6;
      vostok::buffer_vector<stlp_std::pair<vostok::ai::weapon const *,unsigned int>>::push_back(
        (vostok::buffer_vector<stlp_std::pair<char *,unsigned int> > *)&this->m_affects,
        &value);
    }
  }
}
