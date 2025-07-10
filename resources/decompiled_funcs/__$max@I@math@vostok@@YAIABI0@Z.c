unsigned int __cdecl vostok::math::max<unsigned int>(const unsigned int *left, const unsigned int *right)
{
  if ( *left <= *right )
    return *right;
  else
    return *left;
}
