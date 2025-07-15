vostok::core::configs::binary_config *__thiscall vostok::core::configs::binary_config::`vector deleting destructor'(
        vostok::core::configs::binary_config *this,
        char a2)
{
  vostok::core::configs::binary_config::~binary_config(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
