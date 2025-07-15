void __thiscall survarium::hit_type_parameters::apply_damage(
        survarium::hit_type_parameters *this,
        float delta,
        unsigned int time_in_ms)
{
  const vostok::variant<32> **v3; // eax
  stlp_std::pair<survarium::body_part_parameters *,float> *it; // [esp+20h] [ebp-Ch]
  stlp_std::pair<survarium::body_part_parameters *,float> *it_end; // [esp+28h] [ebp-4h]

  it_end = (stlp_std::pair<survarium::body_part_parameters *,float> *)((char *)&this[1] + 8 * this->m_bdb_count);
  for ( it = (stlp_std::pair<survarium::body_part_parameters *,float> *)&this[1]; it != it_end; ++it )
  {
    if ( it->second > 0.0 )
    {
      v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
             (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)it,
             (int)&this->m_type);
      survarium::body_part_parameters::hit_by_type(
        it->first,
        (const char *)v3,
        time_in_ms,
        it->second * delta,
        0.0,
        0,
        0);
    }
  }
}
