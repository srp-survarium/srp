void __userpurge btConvexHullInternal::Rational64::Rational64(
        btConvexHullInternal::Rational64 *this@<ecx>,
        int *a2@<eax>,
        __int64 numerator,
        __int64 denominator)
{
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  int v7; // edx

  v4 = HIDWORD(numerator);
  v5 = numerator;
  if ( numerator < 0 )
  {
LABEL_5:
    a2[4] = -1;
    v5 = -(int)numerator;
    v4 = (unsigned __int64)-numerator >> 32;
    goto LABEL_6;
  }
  if ( numerator <= 0 )
  {
    if ( numerator >= 0 )
    {
      a2[4] = 0;
      *a2 = 0;
      a2[1] = 0;
      goto LABEL_8;
    }
    goto LABEL_5;
  }
  a2[4] = 1;
LABEL_6:
  *a2 = v5;
  a2[1] = v4;
LABEL_8:
  v6 = HIDWORD(denominator);
  v7 = denominator;
  if ( denominator < 0 )
    goto LABEL_11;
  if ( denominator > 0 )
  {
LABEL_12:
    a2[2] = v7;
    a2[3] = v6;
    return;
  }
  if ( denominator < 0 )
  {
LABEL_11:
    a2[4] = -a2[4];
    v7 = -(int)denominator;
    v6 = (unsigned __int64)-denominator >> 32;
    goto LABEL_12;
  }
  a2[2] = 0;
  a2[3] = 0;
}
