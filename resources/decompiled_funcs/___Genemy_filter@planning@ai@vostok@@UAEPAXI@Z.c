vostok::ai::planning::enemy_filter *__thiscall vostok::ai::planning::enemy_filter::`scalar deleting destructor'(
        vostok::ai::planning::enemy_filter *this,
        char a2)
{
  vostok::ai::planning::enemy_filter::~enemy_filter(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
