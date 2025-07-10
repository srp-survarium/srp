void __thiscall vostok::ai::planning::base_lexeme::add_to_target_world_state_as_or(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::specified_problem *problem,
        unsigned int *offset)
{
  vostok::variant<32> *value; // [esp+8h] [ebp-10h] BYREF
  vostok::ai::planning::base_lexeme *m_lexeme; // [esp+14h] [ebp-4h]

  m_lexeme = (vostok::ai::planning::base_lexeme *)this->m_left.m_lexeme;
  vostok::ai::planning::base_lexeme::add_to_target_world_state(m_lexeme, problem, offset);
  value = (vostok::variant<32> *)*offset;
  vostok::buffer_vector<unsigned int>::push_back(
    (vostok::buffer_vector<vostok::variant<32> const *> *)&problem->m_target_offsets,
    (const vostok::variant<32> **)&value);
  vostok::ai::planning::base_lexeme::add_to_target_world_state(
    (vostok::ai::planning::base_lexeme *)this->m_right.m_lexeme,
    problem,
    offset);
}
