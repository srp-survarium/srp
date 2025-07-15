char __thiscall vostok::ai::planning::weapon_filter::contains_object_id(
        vostok::ai::planning::weapon_filter *this,
        unsigned int id)
{
  vostok::ai::planning::weapon_filter *iter; // [esp+14h] [ebp-4h]

  for ( iter = (vostok::ai::planning::weapon_filter *)this->m_filtered_ids._M_impl._M_node._M_data._M_next;
        iter != (vostok::ai::planning::weapon_filter *)&this->m_filtered_ids;
        iter = (vostok::ai::planning::weapon_filter *)iter->__vftable )
  {
    if ( iter->m_subfilters.m_size == id )
      return 1;
  }
  return 0;
}
