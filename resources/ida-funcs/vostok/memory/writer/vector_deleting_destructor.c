vostok::memory::writer *__thiscall vostok::memory::writer::`vector deleting destructor'(
        vostok::memory::writer *this,
        char a2)
{
  vostok::memory::writer::~writer(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
