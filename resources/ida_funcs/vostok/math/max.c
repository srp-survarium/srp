int __cdecl vostok::math::max(int left, int right)
{
  return left - (left < right ? left - right : 0);
}


unsigned int __cdecl vostok::math::max(unsigned int left, unsigned int right)
{
  return left - (left < right ? left - right : 0);
}


void __cdecl vostok::math::max()
{
  ;
}


unsigned __int64 __cdecl vostok::math::max(unsigned __int64 left, unsigned __int64 right)
{
  return left - (left < right ? left - right : 0);
}


unsigned int __cdecl vostok::math::max<unsigned int>(const unsigned int *left, const unsigned int *right)
{
  if ( *left <= *right )
    return *right;
  else
    return *left;
}
