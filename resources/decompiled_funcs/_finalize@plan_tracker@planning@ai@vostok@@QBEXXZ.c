void __thiscall vostok::ai::planning::plan_tracker::finalize(vostok::ai::planning::plan_tracker *this)
{
  if ( !this->m_first_time )
    vostok::ai::planning::action_instance::finalize(
      (vostok::ai::planning::action_instance *)this->m_current_operator.action,
      &this->m_current_operator.parameters);
}
