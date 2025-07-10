vostok::ai::planning::action_parameter *__thiscall vostok::ai::planning::goal::pop_parameter(
        vostok::ai::planning::goal *this)
{
  vostok::ai::planning::action_parameter **end; // [esp+28h] [ebp-14h] BYREF
  vostok::ai::planning::action_parameter **m_begin; // [esp+2Ch] [ebp-10h]
  vostok::fixed_vector<vostok::ai::planning::action_parameter *,4> *p_m_parameters; // [esp+30h] [ebp-Ch]
  vostok::ai::planning::action_parameter *result; // [esp+34h] [ebp-8h]
  vostok::ai::planning::action_parameter **it_begin; // [esp+38h] [ebp-4h] BYREF

  p_m_parameters = &this->m_parameters;
  if ( this->m_parameters.m_begin == this->m_parameters.m_end )
    return 0;
  m_begin = this->m_parameters.m_begin;
  it_begin = m_begin;
  result = *m_begin;
  end = m_begin + 1;
  vostok::buffer_vector<vostok::ai::planning::action_parameter *>::erase(&this->m_parameters, &it_begin, &end);
  return result;
}
