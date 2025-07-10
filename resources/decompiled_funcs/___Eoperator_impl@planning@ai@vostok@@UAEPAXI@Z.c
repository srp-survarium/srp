vostok::ai::planning::operator_base *__thiscall vostok::ai::planning::operator_impl::`vector deleting destructor'(
        vostok::ai::planning::operator_base *this,
        char a2)
{
  vostok::ai::planning::operator_base::~operator_base(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
