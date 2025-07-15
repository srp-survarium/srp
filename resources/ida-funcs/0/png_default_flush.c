int __usercall png_default_flush@<eax>(int a1@<ebx>, int a2@<edi>, int a3)
{
  int result; // eax

  if ( a3 )
    return fflush(a1, a2, *(_iobuf **)(a3 + 88));
  return result;
}
