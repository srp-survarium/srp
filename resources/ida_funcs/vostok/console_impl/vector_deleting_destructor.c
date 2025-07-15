vostok::console_impl *__thiscall vostok::console_impl::`vector deleting destructor'(
        vostok::console_impl *this,
        char a2)
{
  vostok::console_impl::~console_impl(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
