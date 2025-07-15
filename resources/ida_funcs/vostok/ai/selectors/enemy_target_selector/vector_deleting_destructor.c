vostok::ai::selectors::weapon_target_selector *__thiscall vostok::ai::selectors::enemy_target_selector::`vector deleting destructor'(
        vostok::ai::selectors::weapon_target_selector *this,
        char a2)
{
  vostok::ai::selectors::enemy_target_selector::~enemy_target_selector(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
