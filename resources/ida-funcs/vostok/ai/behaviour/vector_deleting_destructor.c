vostok::ai::behaviour *__thiscall vostok::ai::behaviour::`vector deleting destructor'(
        vostok::ai::behaviour *this,
        char a2)
{
  vostok::ai::behaviour::~behaviour(this);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
