vostok::ai::planning::action_instance *__thiscall vostok::ai::planning::pddl_problem::pop_action_instance(
        vostok::ai::planning::pddl_problem *this)
{
  vostok::ai::planning::action_parameter **end; // [esp+28h] [ebp-10h] BYREF
  vostok::ai::planning::action_instance **m_begin; // [esp+2Ch] [ebp-Ch]
  vostok::ai::planning::action_instance *result; // [esp+30h] [ebp-8h]
  vostok::ai::planning::action_instance **it_begin; // [esp+34h] [ebp-4h] BYREF

  if ( this->m_action_instances.m_begin == this->m_action_instances.m_end )
    return 0;
  m_begin = this->m_action_instances.m_begin;
  it_begin = m_begin;
  result = *m_begin;
  end = (vostok::ai::planning::action_parameter **)(m_begin + 1);
  vostok::buffer_vector<vostok::ai::planning::action_parameter *>::erase(
    (vostok::buffer_vector<vostok::ai::planning::action_parameter *> *)this,
    (vostok::ai::planning::action_parameter ***)&it_begin,
    &end);
  return result;
}
