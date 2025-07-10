void __thiscall vostok::ai::planning::plan_tracker::start_new_operator(
        vostok::ai::planning::plan_tracker *this,
        const vostok::fixed_vector<vostok::ai::planning::plan_item,32> *new_plan)
{
  vostok::physics::base_physics_object **end; // [esp+28h] [ebp-Ch] BYREF
  vostok::ai::planning::plan_item *m_begin; // [esp+2Ch] [ebp-8h]
  char v5; // [esp+33h] [ebp-1h]

  v5 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  m_begin = new_plan->m_begin;
  this->m_current_operator.action = m_begin->action;
  end = (vostok::physics::base_physics_object **)m_begin->parameters.m_end;
  vostok::buffer_vector<vostok::physics::base_physics_object *>::assign<vostok::physics::base_physics_object * *>(
    (vostok::buffer_vector<vostok::physics::base_physics_object *> *)&this->m_current_operator.parameters,
    (vostok::physics::base_physics_object **)m_begin->parameters.m_begin,
    &end);
  vostok::ai::planning::action_instance::initialize(
    (vostok::ai::planning::action_instance *)this->m_current_operator.action,
    &this->m_current_operator.parameters);
}
