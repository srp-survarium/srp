vostok::ai::planning::position_filter *__thiscall vostok::ai::planning::position_filter::`scalar deleting destructor'(
        vostok::ai::planning::position_filter *this,
        char a2)
{
  vostok::ai::planning::position_filter::~position_filter(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
