unsigned int __cdecl strnlen(const char *str, unsigned int maxsize)
{
  unsigned int result; // eax

  for ( result = 0; result < maxsize; ++str )
  {
    if ( !*str )
      break;
    ++result;
  }
  return result;
}
