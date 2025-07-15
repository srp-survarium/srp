vostok::ai::selectors::position_target_selector *__thiscall vostok::ai::selectors::position_target_selector::`scalar deleting destructor'(
        vostok::ai::selectors::position_target_selector *this,
        char a2)
{
  vostok::ai::selectors::animation_target_selector::~animation_target_selector(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
