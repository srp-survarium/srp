void __thiscall vostok::ai::planning::plan_tracker::on_plan_changed(
        vostok::ai::planning::plan_tracker *this,
        const vostok::fixed_vector<vostok::ai::planning::plan_item,32> *new_plan)
{
  if ( this->m_first_time )
  {
    this->m_first_time = 0;
    vostok::ai::planning::plan_tracker::start_new_operator(this, new_plan);
  }
  else
  {
    survarium::weapon_user_dead_state::finalize(0);
    if ( new_plan->m_begin->action != this->m_current_operator.action
      || !vostok::ai::planning::are_parameters_equal(
            (survarium::game_camera *)&new_plan->m_begin->parameters,
            &this->m_current_operator.parameters) )
    {
      vostok::ai::planning::plan_tracker::start_new_operator(this, new_plan);
    }
  }
}
