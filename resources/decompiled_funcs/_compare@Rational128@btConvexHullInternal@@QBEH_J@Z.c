int __userpurge btConvexHullInternal::Rational128::compare@<eax>(
        btConvexHullInternal::Rational128 *this@<ecx>,
        int a2@<eax>,
        __int64 b)
{
  __int64 v4; // rax
  btConvexHullInternal::Int128 *v6; // ecx
  int v7; // eax
  btConvexHullInternal::Int128 *v8; // eax
  btConvexHullInternal::Int128 result; // [esp+8h] [ebp-14h] BYREF

  if ( *(_BYTE *)(a2 + 36) )
  {
    v4 = *(int *)(a2 + 32) * *(_QWORD *)a2;
    if ( SHIDWORD(v4) >= SHIDWORD(b) )
    {
      if ( SHIDWORD(v4) <= SHIDWORD(b) && (unsigned int)v4 <= (unsigned int)b )
      {
        if ( v4 >= b )
          return 0;
        return -1;
      }
      return 1;
    }
    return -1;
  }
  v6 = (btConvexHullInternal::Int128 *)HIDWORD(b);
  v7 = b;
  if ( b < 0 )
    goto LABEL_12;
  if ( b > 0 )
  {
    if ( *(int *)(a2 + 32) <= 0 )
      return -1;
    goto LABEL_15;
  }
  if ( b < 0 )
  {
LABEL_12:
    if ( *(int *)(a2 + 32) >= 0 )
      return 1;
    v7 = -(int)b;
    v6 = (btConvexHullInternal::Int128 *)((unsigned __int64)-b >> 32);
LABEL_15:
    v8 = btConvexHullInternal::Int128::operator*(
           v6,
           (btConvexHullInternal::Int128 *)(a2 + 16),
           &result,
           __SPAIR64__((unsigned int)v6, v7));
    return *(_DWORD *)(a2 + 32) * btConvexHullInternal::Int128::ucmp((btConvexHullInternal::Int128 *)a2, v8);
  }
  return *(_DWORD *)(a2 + 32);
}
