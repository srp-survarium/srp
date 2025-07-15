int __usercall btDbvt::`scalar deleting destructor'@<eax>(btDbvt *this@<ecx>, int a2@<eax>)
{
  void *v3; // eax

  btDbvt::clear(this);
  v3 = *(void **)(a2 + 32);
  if ( v3 )
  {
    if ( *(_BYTE *)(a2 + 36) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v3);
    }
    *(_DWORD *)(a2 + 32) = 0;
  }
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_BYTE *)(a2 + 36) = 1;
  return a2;
}
