vostok::ai::planning::cover_filter *__thiscall vostok::ai::planning::cover_filter::`vector deleting destructor'(
        vostok::ai::planning::cover_filter *this,
        char a2)
{
  vostok::ai::planning::cover_filter::~cover_filter(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
