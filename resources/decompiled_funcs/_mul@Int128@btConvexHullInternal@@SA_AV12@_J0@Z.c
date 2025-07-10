btConvexHullInternal::Int128 *__cdecl btConvexHullInternal::Int128::mul(
        btConvexHullInternal::Int128 *result,
        __int64 a,
        __int64 b)
{
  unsigned __int64 v3; // rdi
  unsigned int v4; // ecx
  int v5; // eax
  bool v6; // bl
  btConvexHullInternal::Int128 *p_resulta; // eax
  btConvexHullInternal::Int128 resulta; // [esp+10h] [ebp-20h] BYREF
  _QWORD v10[2]; // [esp+20h] [ebp-10h] BYREF

  v3 = a;
  if ( a < 0 )
  {
    v6 = 1;
    v3 = -a;
  }
  else
  {
    v6 = 0;
  }
  v4 = HIDWORD(b);
  v5 = b;
  if ( b < 0 )
  {
    v6 = !v6;
    v5 = -(int)b;
    v4 = (unsigned __int64)-b >> 32;
  }
  btConvexHullInternal::DMul<unsigned __int64,unsigned int>::mul(v3, __PAIR64__(v4, v5), &resulta.low, &resulta.high);
  if ( v6 )
  {
    v10[0] = -resulta.low;
    v10[1] = (resulta.low == 0) + ~resulta.high;
    p_resulta = (btConvexHullInternal::Int128 *)v10;
  }
  else
  {
    p_resulta = &resulta;
  }
  *result = *p_resulta;
  return result;
}
