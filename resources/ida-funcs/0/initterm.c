void __usercall initterm(void (__cdecl **pfbegin)()@<eax>, void (__cdecl **pfend)())
{
  while ( pfbegin < pfend )
  {
    if ( *pfbegin )
      (*pfbegin)();
    ++pfbegin;
  }
}
