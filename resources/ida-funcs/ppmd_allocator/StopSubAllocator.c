void __usercall ppmd_allocator::StopSubAllocator(_DWORD *a1@<esi>)
{
  int v1; // eax

  if ( a1[120] )
  {
    a1[120] = 0;
    v1 = a1[121];
    if ( v1 )
    {
      (*(void (__thiscall **)(_DWORD, int, const char *, const char *, int))(*(_DWORD *)*a1 + 24))(
        *a1,
        v1,
        "ppmd_allocator::StopSubAllocator",
        "c:\\survarium.deploy\\sources\\vostok\\core\\sources\\compressor_ppmd_allocator.h",
        149);
      a1[121] = 0;
    }
  }
}
