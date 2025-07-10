char __thiscall vostok::ui::functor_edit_action::execute(
        vostok::ui::functor_edit_action *this,
        vostok::input::enum_keyboard_action action)
{
  this->m_functor.m_Closure.m_pFunction(this->m_functor.m_Closure.m_pthis);
  return 1;
}
