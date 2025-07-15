char __thiscall vostok::ai::planning::position_filter::contains_item(
        vostok::ai::planning::position_filter *this,
        const vostok::ai::movement_target *item)
{
  stlp_std::priv::_List_node_base *iter; // [esp+18h] [ebp-4h]

  for ( iter = this->m_filtered_items._M_impl._M_node._M_data._M_next;
        iter != (stlp_std::priv::_List_node_base *)&this->m_filtered_items;
        iter = iter->_M_next )
  {
    if ( vostok::ai::planning::are_targets_similar(
           item,
           (const vostok::ai::planning::movement_target_wrapper *)&iter[1]) )
    {
      return 1;
    }
  }
  return 0;
}
