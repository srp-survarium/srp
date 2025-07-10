int __cdecl sort32a(_DWORD **a, _DWORD **b)
{
  return (__PAIR64__(**b < **a, **a) - (unsigned int)**b) >> 32;
}
