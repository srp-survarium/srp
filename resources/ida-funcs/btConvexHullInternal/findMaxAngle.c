btConvexHullInternal::Edge *__thiscall btConvexHullInternal::findMaxAngle(
        btConvexHullInternal *this,
        int ccw,
        const btConvexHullInternal::Vertex *start,
        const btConvexHullInternal::Point32 *s,
        const btConvexHullInternal::Point32 *rxs,
        const btConvexHullInternal::Point64 *sxrxs,
        const btConvexHullInternal::Point64 *minCot,
        btConvexHullInternal::Rational64 *b)
{
  const btConvexHullInternal::Point32 *v8; // eax
  const btConvexHullInternal::Edge *z; // ebx
  __int64 v10; // rax
  btConvexHullInternal::Rational64 *v11; // ecx
  int v12; // eax
  __int64 v14; // [esp-8h] [ebp-4Ch]
  const btConvexHullInternal::Point32 *v15; // [esp+0h] [ebp-44h]
  btConvexHullInternal::Rational64 v16; // [esp+10h] [ebp-34h] BYREF
  btConvexHullInternal::Point32 v17; // [esp+2Ch] [ebp-18h] BYREF
  const btConvexHullInternal::Edge *v18; // [esp+3Ch] [ebp-8h]

  v8 = s;
  v18 = 0;
  z = (const btConvexHullInternal::Edge *)s->z;
  if ( z )
  {
    do
    {
      if ( z->copy <= *(_DWORD *)(ccw + 100) )
        goto LABEL_11;
      btConvexHullInternal::Point32::operator-((btConvexHullInternal::Point32 *)&v8[5].z, &v17, &z->target->point, v15);
      v14 = btConvexHullInternal::Point32::dot(sxrxs, &v17);
      v10 = btConvexHullInternal::Point32::dot(minCot, &v17);
      btConvexHullInternal::Rational64::Rational64(v11, (int *)&v16, v10, v14);
      if ( !v16.sign && !v16.denominator )
        goto LABEL_11;
      if ( v18 && (v12 = btConvexHullInternal::Rational64::compare(b, &v16), v12 >= 0) )
      {
        if ( v12 || (unsigned __int8)start != (btConvexHullInternal::getOrientation(v18, z, rxs, &v17) == 2) )
          goto LABEL_11;
      }
      else
      {
        qmemcpy(b, &v16, sizeof(btConvexHullInternal::Rational64));
      }
      v18 = z;
LABEL_11:
      z = z->next;
      v8 = s;
    }
    while ( z != (const btConvexHullInternal::Edge *)s->z );
  }
  return (btConvexHullInternal::Edge *)v18;
}
