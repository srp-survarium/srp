void __userpurge btConvexHullInternal::Rational64::Rational64(
        btConvexHullInternal::Rational64 *this@<ecx>,
        int a2@<eax>,
        __int64 numerator,
        __int64 denominator)
{
  if ( numerator < 0 )
  {
LABEL_5:
    *(_DWORD *)(a2 + 16) = -1;
    *(_QWORD *)a2 = -numerator;
    goto LABEL_7;
  }
  if ( numerator <= 0 )
  {
    if ( numerator >= 0 )
    {
      *(_DWORD *)(a2 + 16) = 0;
      *(_DWORD *)a2 = 0;
      *(_DWORD *)(a2 + 4) = 0;
      goto LABEL_7;
    }
    goto LABEL_5;
  }
  *(_DWORD *)(a2 + 16) = 1;
  *(_QWORD *)a2 = numerator;
LABEL_7:
  if ( denominator < 0 )
    goto LABEL_11;
  if ( denominator > 0 )
  {
    *(_QWORD *)(a2 + 8) = denominator;
    return;
  }
  if ( denominator >= 0 )
  {
    *(_DWORD *)(a2 + 8) = 0;
    *(_DWORD *)(a2 + 12) = 0;
  }
  else
  {
LABEL_11:
    *(_DWORD *)(a2 + 16) = -*(_DWORD *)(a2 + 16);
    *(_QWORD *)(a2 + 8) = -denominator;
  }
}
