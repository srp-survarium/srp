btConvexHullInternal::Edge *__thiscall btConvexHullInternal::findMaxAngle(
        btConvexHullInternal *this,
        btConvexHullInternal *ccw,
        const btConvexHullInternal::Vertex *start,
        const btConvexHullInternal::Vertex *s,
        const btConvexHullInternal::Point32 *rxs,
        btConvexHullInternal::Edge *sxrxs,
        btConvexHullInternal::Edge *minCot,
        btConvexHullInternal::Rational64 *minCota)
{
  const btConvexHullInternal::Point32 *v8; // edx
  btConvexHullInternal::Edge *result; // eax
  btConvexHullInternal::Vertex *target; // eax
  int v13; // ecx
  int v14; // esi
  int v15; // eax
  int v16; // edi
  __int64 v17; // kr00_8
  btConvexHullInternal::Vertex *v18; // eax
  btConvexHullInternal::Edge *reverse; // ecx
  int v20; // eax
  __int64 v21; // [esp+18h] [ebp-40h]
  btConvexHullInternal::Point32 t; // [esp+30h] [ebp-28h] BYREF
  btConvexHullInternal::Rational64 cot; // [esp+40h] [ebp-18h] BYREF
  btConvexHullInternal::Edge *minEdge; // [esp+6Ch] [ebp+14h]
  btConvexHullInternal::Edge *e; // [esp+70h] [ebp+18h]

  v8 = (const btConvexHullInternal::Point32 *)s;
  result = 0;
  minEdge = 0;
  e = s->edges;
  if ( e )
  {
    while ( 1 )
    {
      if ( e->copy <= ccw->mergeStamp )
        goto LABEL_12;
      target = e->target;
      v13 = target->point.x - v8[5].z;
      v14 = target->point.y - v8[5].index;
      v15 = target->point.z - v8[6].x;
      t.y = v14;
      t.z = v15;
      v17 = v15;
      v16 = v15;
      v21 = v13;
      v18 = sxrxs->target;
      t.x = v13;
      reverse = sxrxs->reverse;
      t.index = -1;
      btConvexHullInternal::Rational64::Rational64(
        (btConvexHullInternal::Rational64 *)minCot->prev,
        (int)&cot,
        *(_QWORD *)&minCot->next * v21
      + *(_QWORD *)&minCot->face * __PAIR64__(HIDWORD(v17), v16)
      + *(_QWORD *)&minCot->reverse * v14,
        *(_QWORD *)&sxrxs->next * v21
      + *(_QWORD *)&sxrxs->face * __PAIR64__(HIDWORD(v17), v16)
      + __PAIR64__((unsigned int)v18, (unsigned int)reverse) * v14);
      if ( !cot.sign && !cot.denominator )
        goto LABEL_12;
      if ( !minEdge )
        break;
      v20 = btConvexHullInternal::Rational64::compare(&cot, minCota);
      if ( v20 >= 0 )
      {
        if ( v20 || (unsigned __int8)start != (btConvexHullInternal::getOrientation(e, &t, minEdge, rxs) == 2) )
          goto LABEL_12;
        goto LABEL_11;
      }
      *minCota = cot;
      minEdge = e;
LABEL_12:
      v8 = (const btConvexHullInternal::Point32 *)s;
      e = e->next;
      if ( e == s->edges )
        return minEdge;
    }
    *minCota = cot;
LABEL_11:
    minEdge = e;
    goto LABEL_12;
  }
  return result;
}
