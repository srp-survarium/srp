vostok::ai::planning::oracle *__thiscall vostok::ai::planning::oracle::`scalar deleting destructor'(
        vostok::ai::planning::oracle *this,
        char a2)
{
  vostok::ai::planning::oracle::~oracle(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
