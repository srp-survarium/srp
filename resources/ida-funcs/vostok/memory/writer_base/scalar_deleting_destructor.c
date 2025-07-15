vostok::memory::writer_base *__thiscall vostok::memory::writer_base::`scalar deleting destructor'(
        vostok::memory::writer_base *this,
        char a2)
{
  vostok::memory::writer_base::~writer_base(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
