void __thiscall vostok::ai::pre_perceptors_filter::ignore(
        vostok::ai::pre_perceptors_filter *this,
        const stlp_std::pair<vostok::ai::game_object const *,enum vostok::ai::ignorance_types_enum> *begin,
        const stlp_std::pair<vostok::ai::game_object const *,enum vostok::ai::ignorance_types_enum> *end)
{
  stlp_std::pair<vostok::ai::game_object const *,enum vostok::ai::ignorance_types_enum> *i; // [esp+18h] [ebp-18h]
  vostok::ai::planning::base_filter *it_filter; // [esp+1Ch] [ebp-14h]
  char can_be_ignored; // [esp+23h] [ebp-Dh]
  const void *instance; // [esp+24h] [ebp-Ch] BYREF
  const stlp_std::pair<vostok::ai::game_object const *,enum vostok::ai::ignorance_types_enum> *iter_end; // [esp+28h] [ebp-8h]
  const stlp_std::pair<vostok::ai::game_object const *,enum vostok::ai::ignorance_types_enum> *iter; // [esp+2Ch] [ebp-4h]

  for ( i = this->m_ignorable_objects.m_begin; i != this->m_ignorable_objects.m_end; ++i )
    ;
  this->m_ignorable_objects.m_end = this->m_ignorable_objects.m_begin;
  iter = begin;
  iter_end = end;
  while ( iter != iter_end )
  {
    instance = iter->first;
    can_be_ignored = 1;
    for ( it_filter = this->m_aux_filters.m_first; it_filter; it_filter = it_filter->m_next )
      can_be_ignored &= vostok::ai::planning::base_filter::is_object_available(it_filter, &instance);
    if ( can_be_ignored )
      vostok::buffer_vector<stlp_std::pair<vostok::ai::weapon const *,unsigned int>>::push_back(
        (vostok::buffer_vector<stlp_std::pair<char *,unsigned int> > *)this,
        (const stlp_std::pair<char *,unsigned int> *)iter);
    ++iter;
  }
}
