void __userpurge btConvexHullInternal::Rational128::Rational128(
        btConvexHullInternal::Rational128 *this@<ecx>,
        int a2@<eax>,
        __int64 value)
{
  __int64 v3; // [esp+8h] [ebp-14h]
  __int64 v4; // [esp+10h] [ebp-Ch]

  if ( value >= 0 )
  {
    if ( value > 0 )
    {
      *(_DWORD *)(a2 + 32) = 1;
      v3 = value;
LABEL_8:
      v4 = 0;
      goto LABEL_9;
    }
    if ( value >= 0 )
    {
      *(_DWORD *)(a2 + 32) = 0;
      v3 = 0;
      goto LABEL_8;
    }
  }
  *(_DWORD *)(a2 + 32) = -1;
  v3 = -value;
  if ( (((unsigned __int64)-value >> 32) & 0x80000000) == 0LL )
    goto LABEL_8;
  v4 = -1;
LABEL_9:
  *(_QWORD *)a2 = v3;
  *(_QWORD *)(a2 + 8) = v4;
  *(_QWORD *)(a2 + 16) = 1;
  *(_QWORD *)(a2 + 24) = 0;
  *(_BYTE *)(a2 + 36) = 1;
}
