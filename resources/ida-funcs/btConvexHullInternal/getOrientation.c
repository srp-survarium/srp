int __usercall btConvexHullInternal::getOrientation@<eax>(
        const btConvexHullInternal::Edge *prev@<edi>,
        const btConvexHullInternal::Edge *next@<ecx>,
        const btConvexHullInternal::Point32 *s@<eax>,
        btConvexHullInternal::Point32 *t)
{
  btConvexHullInternal::Point32 *p_point; // ebx
  const btConvexHullInternal::Point32 *v7; // [esp+0h] [ebp-5Ch]
  const btConvexHullInternal::Point32 *v8; // [esp+0h] [ebp-5Ch]
  btConvexHullInternal::Point64 b; // [esp+8h] [ebp-54h] BYREF
  btConvexHullInternal::Point64 v10; // [esp+20h] [ebp-3Ch] BYREF
  btConvexHullInternal::Point32 v11; // [esp+38h] [ebp-24h] BYREF
  btConvexHullInternal::Point32 v12; // [esp+48h] [ebp-14h] BYREF

  if ( prev->next != next )
    return prev->prev == next;
  if ( prev->prev == next )
  {
    btConvexHullInternal::Point32::cross(s, &v10, t);
    p_point = &next->reverse->target->point;
    btConvexHullInternal::Point32::operator-(p_point, &v11, &next->target->point, v7);
    btConvexHullInternal::Point32::operator-(p_point, &v12, &prev->target->point, v8);
    btConvexHullInternal::Point32::cross(&v11, &b, &v12);
    if ( btConvexHullInternal::Point64::dot(&b, &v10) <= 0 )
      return 1;
  }
  return 2;
}
