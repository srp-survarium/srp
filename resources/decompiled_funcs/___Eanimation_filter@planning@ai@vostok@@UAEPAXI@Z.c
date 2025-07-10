vostok::ai::planning::animation_filter *__thiscall vostok::ai::planning::animation_filter::`vector deleting destructor'(
        vostok::ai::planning::animation_filter *this,
        char a2)
{
  vostok::ai::planning::animation_filter::~animation_filter(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
