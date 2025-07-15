int __usercall ppmd_allocator::StartSubAllocator@<eax>(_DWORD *a1@<esi>, ppmd_allocator *this)
{
  char *v2; // eax
  int v3; // ecx
  int result; // eax

  v2 = (char *)a1[120];
  if ( v2 == (char *)&loc_FFFFF + 1 )
    return 1;
  if ( v2 )
  {
    v3 = *a1;
    a1[120] = 0;
    if ( a1[121] )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 24))(v3, a1[121]);
      a1[121] = 0;
    }
  }
  result = (*(int (__thiscall **)(_DWORD, char *))(*(_DWORD *)*a1 + 16))(*a1, (char *)&loc_FFFFF + 1);
  a1[121] = result;
  if ( result )
  {
    a1[120] = (char *)&loc_FFFFF + 1;
    return 1;
  }
  return result;
}
