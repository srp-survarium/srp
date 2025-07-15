void __userpurge btConvexHullInternal::merge(
        btConvexHullInternal *h0@<ecx>,
        btVector3 *h1@<eax>,
        btConvexHullInternal *this)
{
  char v3; // al
  btConvexHullInternal::Vertex *v4; // ebp
  btConvexHullInternal::Vertex *v5; // ebx
  int v6; // ecx
  int v7; // edx
  btConvexHullInternal::Vertex *target; // edi
  int v9; // ecx
  int v10; // eax
  unsigned __int64 v11; // rax
  int v12; // eax
  int v13; // ecx
  btConvexHullInternal::Vertex *v14; // edi
  int v15; // ecx
  int v16; // eax
  unsigned __int64 v17; // rax
  int v18; // eax
  int v19; // ecx
  __int64 v20; // xmm0_8
  __int64 v21; // xmm0_8
  int v22; // eax
  int v23; // ecx
  int v24; // edx
  int v25; // eax
  int v26; // ecx
  btConvexHullInternal::Edge *MaxAngle; // esi
  btConvexHullInternal::Edge *v28; // eax
  BOOL v29; // ecx
  char v30; // al
  btConvexHullInternal::Edge *v31; // eax
  btConvexHullInternal::Edge *v32; // ecx
  btConvexHullInternal::Edge *v33; // eax
  btConvexHullInternal::Edge *next; // eax
  btConvexHullInternal::Edge *v35; // edi
  btConvexHullInternal::Edge *v36; // esi
  btConvexHullInternal::Edge *v37; // eax
  btConvexHullInternal::Edge *v38; // ecx
  btConvexHullInternal::Edge *v39; // eax
  btConvexHullInternal::Edge *prev; // edx
  __int64 v41; // xmm0_8
  btConvexHullInternal::Edge *v42; // eax
  btConvexHullInternal::Edge *v43; // eax
  btConvexHullInternal::Edge *v44; // edi
  btConvexHullInternal::Edge *v45; // esi
  btConvexHullInternal::Edge *v46; // eax
  btConvexHullInternal::Edge *v47; // ecx
  btConvexHullInternal::Edge *v48; // eax
  btConvexHullInternal::Edge *v49; // edx
  __int64 v50; // xmm0_8
  btConvexHullInternal::Edge *v51; // eax
  btConvexHullInternal::Edge *v52; // eax
  btConvexHullInternal::Edge *reverse; // eax
  btConvexHullInternal::Edge *v54; // eax
  btConvexHullInternal::Edge *v55; // ecx
  btConvexHullInternal::Edge *v56; // eax
  btConvexHullInternal::Edge *v57; // ebp
  btConvexHullInternal::Edge *v58; // eax
  btConvexHullInternal::Edge *v59; // ecx
  btConvexHullInternal::Edge *v60; // edx
  btConvexHullInternal::Edge *v61; // ecx
  btConvexHullInternal::Edge *v62; // ecx
  btConvexHullInternal::Edge *v63; // eax
  btConvexHullInternal::Edge *v64; // ecx
  btConvexHullInternal::Edge *v65; // eax
  btConvexHullInternal::Edge *v66; // ebp
  btConvexHullInternal::Edge *v67; // ebx
  btConvexHullInternal::Edge *v68; // eax
  btConvexHullInternal::Edge *v69; // edx
  btConvexHullInternal::Vertex *v70; // [esp+0h] [ebp-F0h]
  btConvexHullInternal::Vertex *v71; // [esp+4h] [ebp-ECh]
  btConvexHullInternal::Edge *min1; // [esp+14h] [ebp-DCh]
  btConvexHullInternal::Edge *min1a; // [esp+14h] [ebp-DCh]
  btConvexHullInternal::Edge *min1b; // [esp+14h] [ebp-DCh]
  btConvexHullInternal::Edge *min0; // [esp+18h] [ebp-D8h] BYREF
  int cmp; // [esp+1Ch] [ebp-D4h] BYREF
  bool firstRun; // [esp+23h] [ebp-CDh]
  btConvexHullInternal::Edge *pendingTail0; // [esp+24h] [ebp-CCh]
  btConvexHullInternal::Edge *toPrev0; // [esp+28h] [ebp-C8h]
  btConvexHullInternal::Edge *toPrev1; // [esp+2Ch] [ebp-C4h]
  btConvexHullInternal::Edge *pendingHead0; // [esp+30h] [ebp-C0h]
  btConvexHullInternal::Edge *pendingTail1; // [esp+34h] [ebp-BCh]
  btConvexHullInternal::Edge *pendingHead1; // [esp+38h] [ebp-B8h]
  btConvexHullInternal::Edge *firstNew0; // [esp+3Ch] [ebp-B4h]
  btConvexHullInternal::Point32 s; // [esp+40h] [ebp-B0h] BYREF
  btConvexHullInternal::Point32 t; // [esp+50h] [ebp-A0h] BYREF
  btConvexHullInternal::Vertex *first1; // [esp+60h] [ebp-90h]
  int v88; // [esp+64h] [ebp-8Ch]
  btConvexHullInternal::Edge *e1; // [esp+68h] [ebp-88h] BYREF
  btConvexHullInternal::Edge *firstNew1; // [esp+6Ch] [ebp-84h]
  btConvexHullInternal::Rational64 minCot1; // [esp+70h] [ebp-80h] BYREF
  btConvexHullInternal::Edge *e0; // [esp+8Ch] [ebp-64h] BYREF
  btConvexHullInternal::Point32 r; // [esp+90h] [ebp-60h] BYREF
  btConvexHullInternal::Rational64 minCot0; // [esp+A0h] [ebp-50h] BYREF
  btConvexHullInternal::Vertex *first0; // [esp+BCh] [ebp-34h]
  btConvexHullInternal::Point64 rxs; // [esp+C0h] [ebp-30h] BYREF
  btConvexHullInternal::Point64 sxrxs; // [esp+D8h] [ebp-18h] BYREF

  if ( !h1->mVec128.m128_i32[1] )
    return;
  if ( !h0->scaling.mVec128.m128_i32[1] )
  {
    h0->scaling = (btVector3)h1->mVec128;
    return;
  }
  --this->mergeStamp;
  min0 = 0;
  toPrev0 = 0;
  firstNew0 = 0;
  pendingHead0 = 0;
  pendingTail0 = 0;
  cmp = 0;
  toPrev1 = 0;
  firstNew1 = 0;
  pendingHead1 = 0;
  pendingTail1 = 0;
  v3 = btConvexHullInternal::mergeProjection(
         h0,
         (btConvexHullInternal::IntermediateHull *)h0,
         (btConvexHullInternal::IntermediateHull *)h1,
         (btConvexHullInternal::Vertex **)&min0,
         (btConvexHullInternal::Vertex **)&cmp);
  v4 = (btConvexHullInternal::Vertex *)min0;
  v5 = (btConvexHullInternal::Vertex *)cmp;
  if ( v3 )
  {
    v6 = *(_DWORD *)(cmp + 92) - min0[3].copy;
    v7 = *(_DWORD *)(cmp + 96) - (unsigned int)min0[4].next;
    s.x = *(_DWORD *)(cmp + 88) - (unsigned int)min0[3].face;
    s.y = v6;
    s.z = v7;
    s.index = -1;
    t.x = 0;
    t.y = 0;
    t.z = -1;
    t.index = -1;
    btConvexHullInternal::Point32::cross(&s, &minCot1, &t);
    btConvexHullInternal::Point32::cross((const btConvexHullInternal::Point64 *)&minCot1, (int)&rxs, &s);
    min1 = v4->edges;
    min0 = 0;
    if ( min1 )
    {
      do
      {
        target = min1->target;
        v9 = target->point.z - v4->point.z;
        LODWORD(minCot0.numerator) = target->point.x - v4->point.x;
        v10 = target->point.y - v4->point.y;
        LODWORD(minCot0.denominator) = v9;
        v11 = v10 * minCot1.denominator;
        v88 = (v9 * *(_QWORD *)&minCot1.sign + v11) >> 32;
        if ( !(SLODWORD(minCot0.numerator) * minCot1.numerator + v9 * *(_QWORD *)&minCot1.sign + v11) )
        {
          v12 = target->point.y - v4->point.y;
          v13 = target->point.z - v4->point.z;
          t.x = target->point.x - v4->point.x;
          t.y = v12;
          t.z = v13;
          t.index = -1;
          if ( btConvexHullInternal::Point32::dot(&t, &rxs) > 0 )
          {
            if ( !min0
              || (r.x = 0, r.y = 0,
                           r.z = -1,
                           r.index = -1,
                           btConvexHullInternal::getOrientation(min1, &r, min0, &s) == 1) )
            {
              min0 = min1;
            }
          }
        }
        min1 = min1->next;
      }
      while ( min1 != v4->edges );
    }
    min1a = v5->edges;
    cmp = 0;
    if ( min1a )
    {
      do
      {
        v14 = min1a->target;
        v15 = v14->point.z - v5->point.z;
        LODWORD(minCot0.numerator) = v14->point.x - v5->point.x;
        v16 = v14->point.y - v5->point.y;
        LODWORD(minCot0.denominator) = v15;
        v17 = v16 * minCot1.denominator;
        v88 = (v15 * *(_QWORD *)&minCot1.sign + v17) >> 32;
        if ( !(SLODWORD(minCot0.numerator) * minCot1.numerator + v15 * *(_QWORD *)&minCot1.sign + v17) )
        {
          v18 = v14->point.y - v5->point.y;
          v19 = v14->point.z - v5->point.z;
          r.x = v14->point.x - v5->point.x;
          r.y = v18;
          r.z = v19;
          r.index = -1;
          if ( btConvexHullInternal::Point32::dot(&r, &rxs) > 0 )
          {
            if ( !cmp
              || (t.x = 0,
                  t.y = 0,
                  t.z = -1,
                  t.index = -1,
                  btConvexHullInternal::getOrientation(min1a, &t, (const btConvexHullInternal::Edge *)cmp, &s) == 2) )
            {
              cmp = (int)min1a;
            }
          }
        }
        min1a = min1a->next;
      }
      while ( min1a != v5->edges );
    }
    if ( min0 || cmp )
    {
      btConvexHullInternal::findEdgeForCoplanarFaces(v4, v5, this, &min0, (btConvexHullInternal::Edge **)&cmp, v70, v71);
      if ( min0 )
        v4 = min0->target;
      if ( cmp )
        v5 = *(btConvexHullInternal::Vertex **)(cmp + 12);
    }
    *(_QWORD *)&s.x = *(_QWORD *)&v5->point.x;
    v20 = *(_QWORD *)&v5->point.z;
    s.index = v5->point.index;
    s.z = v20 + 1;
  }
  else
  {
    *(_QWORD *)&s.x = *(_QWORD *)(cmp + 88);
    v21 = *(_QWORD *)(cmp + 96);
    ++s.x;
    *(_QWORD *)&s.z = v21;
  }
  first0 = v4;
  first1 = v5;
  firstRun = 1;
  t.index = -1;
  r.index = -1;
  while ( 1 )
  {
    v22 = v5->point.y - v4->point.y;
    v23 = v5->point.z - v4->point.z;
    t.x = v5->point.x - v4->point.x;
    v24 = s.x - v4->point.x;
    t.y = v22;
    v25 = s.y - v4->point.y;
    t.z = v23;
    v26 = s.z - v4->point.z;
    r.x = v24;
    r.y = v25;
    r.z = v26;
    btConvexHullInternal::Point32::cross(&t, &rxs, &r);
    btConvexHullInternal::Point32::cross(&rxs, (int)&sxrxs, &t);
    memset(&minCot0, 0, 20);
    MaxAngle = btConvexHullInternal::findMaxAngle(
                 (btConvexHullInternal *)&t,
                 this,
                 0,
                 v4,
                 &t,
                 (btConvexHullInternal::Edge *)&rxs,
                 (btConvexHullInternal::Edge *)&sxrxs,
                 &minCot0);
    min0 = MaxAngle;
    memset(&minCot1, 0, 20);
    v28 = btConvexHullInternal::findMaxAngle(
            this,
            this,
            (const btConvexHullInternal::Vertex *)1,
            v5,
            &t,
            (btConvexHullInternal::Edge *)&rxs,
            (btConvexHullInternal::Edge *)&sxrxs,
            &minCot1);
    min1b = v28;
    if ( MaxAngle )
    {
      if ( v28 )
        cmp = btConvexHullInternal::Rational64::compare(&minCot0, &minCot1);
      else
        cmp = -1;
    }
    else
    {
      if ( !v28 )
      {
        v52 = btConvexHullInternal::newEdgePair((btConvexHullInternal *)v29, this, v4, v5);
        v52->next = v52;
        v52->prev = v52;
        v4->edges = v52;
        reverse = v52->reverse;
        reverse->next = reverse;
        reverse->prev = reverse;
        v5->edges = reverse;
        return;
      }
      cmp = 1;
    }
    if ( !firstRun )
    {
      if ( cmp < 0 )
      {
        if ( minCot0.sign < 0 && !minCot0.denominator )
        {
          v30 = 1;
          goto LABEL_43;
        }
      }
      else if ( minCot1.sign < 0 && !minCot1.denominator )
      {
        v30 = 1;
        goto LABEL_43;
      }
      v30 = 0;
LABEL_43:
      v29 = v30 == 0;
      if ( v30 )
        goto LABEL_51;
    }
    v31 = btConvexHullInternal::newEdgePair((btConvexHullInternal *)v29, this, v4, v5);
    if ( pendingTail0 )
      pendingTail0->prev = v31;
    else
      pendingHead0 = v31;
    v31->next = pendingTail0;
    v32 = pendingTail1;
    pendingTail0 = v31;
    v33 = v31->reverse;
    if ( pendingTail1 )
      pendingTail1->next = v33;
    else
      pendingHead1 = v33;
    v33->prev = v32;
    pendingTail1 = v33;
LABEL_51:
    e1 = min1b;
    e0 = min0;
    if ( cmp )
    {
      if ( cmp < 0 )
        goto LABEL_66;
    }
    else
    {
      btConvexHullInternal::findEdgeForCoplanarFaces(v4, v5, this, &e0, &e1, v70, v71);
    }
    if ( e1 )
    {
      if ( toPrev1 )
      {
        next = toPrev1->next;
        if ( toPrev1->next != min1b )
        {
          do
          {
            v35 = next->next;
            btConvexHullInternal::removeEdgePair(this, next);
            next = v35;
          }
          while ( v35 != min1b );
        }
      }
      v36 = pendingTail1;
      if ( pendingTail1 )
      {
        v37 = toPrev1;
        v38 = pendingHead1;
        if ( toPrev1 )
        {
          toPrev1->next = pendingHead1;
          v38->prev = v37;
          v39 = min1b;
          v36->next = min1b;
        }
        else
        {
          v39 = min1b;
          prev = min1b->prev;
          prev->next = pendingHead1;
          v38->prev = prev;
          v36->next = min1b;
          firstNew1 = v38;
        }
        v39->prev = v36;
        pendingHead1 = 0;
        pendingTail1 = 0;
      }
      else if ( !toPrev1 )
      {
        firstNew1 = min1b;
      }
      *(_QWORD *)&s.x = *(_QWORD *)&v5->point.x;
      v41 = *(_QWORD *)&v5->point.z;
      v5 = e1->target;
      v42 = e1->reverse;
      *(_QWORD *)&s.z = v41;
      toPrev1 = v42;
    }
LABEL_66:
    if ( cmp <= 0 && e0 )
    {
      if ( toPrev0 )
      {
        v43 = toPrev0->prev;
        if ( v43 != min0 )
        {
          do
          {
            v44 = v43->prev;
            btConvexHullInternal::removeEdgePair(this, v43);
            v43 = v44;
          }
          while ( v44 != min0 );
        }
      }
      v45 = pendingTail0;
      if ( pendingTail0 )
      {
        v46 = toPrev0;
        v47 = pendingHead0;
        if ( toPrev0 )
        {
          pendingHead0->next = toPrev0;
          v46->prev = v47;
          v48 = min0;
          min0->next = v45;
        }
        else
        {
          v48 = min0;
          v49 = min0->next;
          pendingHead0->next = min0->next;
          v49->prev = v47;
          v48->next = v45;
          firstNew0 = v47;
        }
        v45->prev = v48;
        pendingHead0 = 0;
        pendingTail0 = 0;
      }
      else if ( !toPrev0 )
      {
        firstNew0 = min0;
      }
      *(_QWORD *)&s.x = *(_QWORD *)&v4->point.x;
      v50 = *(_QWORD *)&v4->point.z;
      v4 = e0->target;
      v51 = e0->reverse;
      *(_QWORD *)&s.z = v50;
      toPrev0 = v51;
    }
    if ( v4 == first0 && v5 == first1 )
      break;
    firstRun = 0;
  }
  if ( toPrev0 )
  {
    v56 = toPrev0->prev;
    if ( v56 != firstNew0 )
    {
      do
      {
        v57 = v56->prev;
        btConvexHullInternal::removeEdgePair(this, v56);
        v56 = v57;
      }
      while ( v57 != firstNew0 );
    }
    v58 = pendingTail0;
    if ( pendingTail0 )
    {
      v59 = toPrev0;
      v60 = pendingHead0;
      pendingHead0->next = toPrev0;
      v59->prev = v60;
      v61 = firstNew0;
      firstNew0->next = v58;
      v58->prev = v61;
    }
  }
  else
  {
    v54 = pendingTail0;
    v55 = pendingHead0;
    pendingHead0->next = pendingTail0;
    v54->prev = v55;
    v4->edges = v54;
  }
  v62 = toPrev1;
  if ( toPrev1 )
  {
    v65 = toPrev1->next;
    v66 = firstNew1;
    if ( toPrev1->next != firstNew1 )
    {
      do
      {
        v67 = v65->next;
        btConvexHullInternal::removeEdgePair(this, v65);
        v65 = v67;
      }
      while ( v67 != v66 );
      v62 = toPrev1;
    }
    v68 = pendingTail1;
    if ( pendingTail1 )
    {
      v69 = pendingHead1;
      v62->next = pendingHead1;
      v69->prev = v62;
      v68->next = v66;
      v66->prev = v68;
    }
  }
  else
  {
    v63 = pendingTail1;
    v64 = pendingHead1;
    pendingTail1->next = pendingHead1;
    v64->prev = v63;
    v5->edges = v63;
  }
}
