void __usercall btStackAlloc::destroy(btStackAlloc *this@<ecx>, int a2@<esi>)
{
  if ( !*(_DWORD *)(a2 + 8) )
  {
    if ( !*(_BYTE *)(a2 + 16) )
    {
      if ( *(_DWORD *)a2 )
        btAlignedFreeInternal(*(void **)a2);
    }
    *(_DWORD *)a2 = 0;
    *(_DWORD *)(a2 + 8) = 0;
  }
}
