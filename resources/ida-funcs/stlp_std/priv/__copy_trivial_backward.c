void __cdecl stlp_std::priv::__copy_trivial_backward(unsigned __int8 *__first, _BYTE *__last, char *__result)
{
  if ( __last - __first > 0 )
    memmove((unsigned __int8 *)&__result[-(__last - __first)], __first, __last - __first);
}
