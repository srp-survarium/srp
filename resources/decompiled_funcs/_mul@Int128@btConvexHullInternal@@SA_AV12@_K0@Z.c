btConvexHullInternal::Int128 *__usercall btConvexHullInternal::Int128::mul@<eax>(
        unsigned __int64 *a1@<esi>,
        btConvexHullInternal::Int128 *result,
        unsigned __int64 a,
        unsigned __int64 b)
{
  btConvexHullInternal::DMul<unsigned __int64,unsigned int>::mul(
    __PAIR64__(a, (unsigned int)result),
    __PAIR64__(b, HIDWORD(a)),
    a1,
    a1 + 1);
  return (btConvexHullInternal::Int128 *)a1;
}
