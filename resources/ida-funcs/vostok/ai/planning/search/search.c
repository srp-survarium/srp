void __thiscall vostok::ai::planning::search::search(vostok::ai::planning::search *this)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->m_plan._M_impl._M_start = 0;
  this->m_plan._M_impl._M_finish = 0;
  this->m_plan._M_impl._M_end_of_storage._M_data = 0;
  vostok::ai::planning::search_base::search_base(&this->m_search);
  vostok::ai::planning::search_backward::search_backward(&this->m_search_backward, &this->m_search);
  vostok::ai::planning::search_backward::search_backward(
    (vostok::ai::planning::search_backward *)&this->m_search_forward,
    &this->m_search);
  this->m_previous_search = 0;
  this->m_next_search = s_head;
  if ( s_head )
    s_head->m_previous_search = this;
  s_head = this;
}
