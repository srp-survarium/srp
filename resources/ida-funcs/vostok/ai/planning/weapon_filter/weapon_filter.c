void __thiscall vostok::ai::planning::weapon_filter::weapon_filter(
        vostok::ai::planning::weapon_filter *this,
        bool need_to_be_inverted)
{
  vostok::ai::planning::base_filter::base_filter(this, need_to_be_inverted);
  this->__vftable = (vostok::ai::planning::weapon_filter_vtbl *)&vostok::ai::planning::weapon_filter::`vftable';
  this->m_filtered_ids._M_impl._M_node._M_data._M_next = 0;
  this->m_filtered_ids._M_impl._M_node._M_data._M_prev = 0;
  this->m_filtered_ids._M_impl._M_node._M_data._M_next = &this->m_filtered_ids._M_impl._M_node._M_data;
  this->m_filtered_ids._M_impl._M_node._M_data._M_prev = this->m_filtered_ids._M_impl._M_node._M_data._M_next;
}
