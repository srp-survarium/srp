int __cdecl apsort(float **a1, _DWORD **a2)
{
  return (__PAIR64__(*(float *)*a2 > **a1, **a2) - *(unsigned int *)*a1) >> 32;
}
