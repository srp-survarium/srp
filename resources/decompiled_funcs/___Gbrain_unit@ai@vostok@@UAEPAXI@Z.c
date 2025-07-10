vostok::ai::brain_unit *__thiscall vostok::ai::brain_unit::`scalar deleting destructor'(
        vostok::ai::brain_unit *this,
        char a2)
{
  vostok::ai::brain_unit::~brain_unit(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
