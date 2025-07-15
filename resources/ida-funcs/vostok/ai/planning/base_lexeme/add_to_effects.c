void __thiscall vostok::ai::planning::base_lexeme::add_to_effects(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::generalized_action *action)
{
  this->m_function_pointers->m_effects_filler(this, action);
}
