vostok::vfs::mounter *__thiscall vostok::vfs::mounter::`vector deleting destructor'(
        vostok::vfs::mounter *this,
        char a2)
{
  vostok::vfs::mounter::~mounter(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
