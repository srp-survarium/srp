int __cdecl sort32a(_DWORD **a1, _DWORD **a2)
{
  return (__PAIR64__(**a2 < **a1, **a1) - (unsigned int)**a2) >> 32;
}
