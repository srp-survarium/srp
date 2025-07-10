void __thiscall vostok::ai::planning::predicate::add_to_effects_as_predicate(
        vostok::ai::planning::predicate *this,
        vostok::ai::planning::generalized_action *action)
{
  vostok::buffer_vector<vostok::resources::request> *property; // eax
  vostok::buffer_vector<vostok::resources::request> *v3; // ecx
  vostok::ai::planning::pddl_world_state_property_impl result; // [esp+48h] [ebp-20h] BYREF

  property = vostok::ai::planning::create_property(
               (vostok::buffer_vector<vostok::resources::request> *)&result,
               this->m_predicate_id,
               action,
               this->m_value,
               (survarium::game_camera *)&this->m_parameters);
  vostok::ai::planning::generalized_action::add_effect(
    action,
    (const vostok::ai::planning::pddl_world_state_property_impl *)property);
  vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v3, &result);
}
