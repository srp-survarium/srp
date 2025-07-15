int __cdecl _initterm_e(int (__cdecl **pfbegin)(), int (__cdecl **pfend)())
{
  int result; // eax

  result = 0;
  while ( pfbegin < pfend && !result )
  {
    if ( *pfbegin )
      result = (*pfbegin)();
    ++pfbegin;
  }
  return result;
}
