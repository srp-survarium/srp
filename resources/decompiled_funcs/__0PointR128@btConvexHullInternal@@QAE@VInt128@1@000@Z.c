void __userpurge btConvexHullInternal::PointR128::PointR128(
        btConvexHullInternal::PointR128 *this@<ecx>,
        btConvexHullInternal::Int128 *a2@<eax>,
        btConvexHullInternal::Int128 x,
        btConvexHullInternal::Int128 y,
        btConvexHullInternal::Int128 z,
        btConvexHullInternal::Int128 denominator)
{
  *a2 = x;
  a2[1] = y;
  a2[2] = z;
  a2[3] = denominator;
}
