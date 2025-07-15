vostok::ai::planning::action_parameter *__thiscall vostok::ai::planning::action_instance::pop_parameter(
        vostok::ai::planning::action_instance *this)
{
  vostok::ai::planning::action_parameter **end; // [esp+28h] [ebp-10h] BYREF
  vostok::ai::planning::action_parameter **m_begin; // [esp+2Ch] [ebp-Ch]
  vostok::ai::planning::action_parameter *result; // [esp+30h] [ebp-8h]
  vostok::ai::planning::action_parameter **it_begin; // [esp+34h] [ebp-4h] BYREF

  if ( this->m_parameters.m_begin == this->m_parameters.m_end )
    return 0;
  m_begin = this->m_parameters.m_begin;
  it_begin = m_begin;
  result = *m_begin;
  end = m_begin + 1;
  vostok::buffer_vector<vostok::ai::planning::action_parameter *>::erase(&this->m_parameters, &it_begin, &end);
  return result;
}
