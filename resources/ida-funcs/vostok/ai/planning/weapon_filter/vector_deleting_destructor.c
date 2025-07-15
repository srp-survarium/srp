vostok::ai::planning::weapon_filter *__thiscall vostok::ai::planning::weapon_filter::`vector deleting destructor'(
        vostok::ai::planning::weapon_filter *this,
        char a2)
{
  vostok::ai::planning::weapon_filter::~weapon_filter(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
