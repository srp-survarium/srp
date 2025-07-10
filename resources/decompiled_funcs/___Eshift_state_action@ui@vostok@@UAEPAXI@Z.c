vostok::ui::functor_edit_action *__thiscall vostok::ui::shift_state_action::`vector deleting destructor'(
        vostok::ui::functor_edit_action *this,
        char a2)
{
  this->__vftable = (vostok::ui::functor_edit_action_vtbl *)&vostok::ui::base_edit_action::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
