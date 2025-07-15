// local variable allocation has failed, the output may be wrong!
void __userpurge btConvexHullInternal::findEdgeForCoplanarFaces(
        btConvexHullInternal::Vertex *c0@<eax>,
        btConvexHullInternal::Vertex *c1@<edx>,
        btConvexHullInternal *this,
        btConvexHullInternal::Edge **e0,
        btConvexHullInternal::Edge **e1,
        btConvexHullInternal::Vertex *stop0,
        btConvexHullInternal::Vertex *stop1)
{
  btConvexHullInternal::Edge *v8; // ebx
  btConvexHullInternal::Edge *v9; // eax
  btConvexHullInternal::Point32 *p_point; // ecx
  btConvexHullInternal::Point32 *v11; // ecx
  __int64 v12; // xmm0_8
  int v13; // ecx
  btConvexHullInternal::Vertex *target; // eax
  int v15; // edx
  btConvexHullInternal::Vertex *prev; // edx
  int v17; // eax
  int v18; // edx
  unsigned int v19; // ebp
  btConvexHullInternal::Vertex *v20; // esi
  __int64 v21; // kr50_8
  __int64 v22; // xmm0_8
  bool v23; // zf
  __int64 v24; // xmm0_8
  btConvexHullInternal::Vertex *v25; // esi
  __int64 v26; // kr78_8
  __int64 v27; // xmm0_8
  __int64 v28; // kr80_8
  bool v29; // cc
  btConvexHullInternal::Edge *v30; // eax
  btConvexHullInternal::Vertex *v31; // esi
  int v32; // eax
  __int64 v33; // rax
  unsigned int v34; // ebp
  int v35; // ecx
  __int64 v36; // rax
  btConvexHullInternal::Edge *v37; // eax
  btConvexHullInternal::Edge **p_next; // ecx
  btConvexHullInternal::Vertex *v39; // ebx
  int v40; // esi
  int v41; // edi
  unsigned int v42; // ebp
  int v43; // eax
  int v44; // edi
  int v45; // eax
  int v46; // esi
  __int64 v47; // rax
  unsigned int v48; // esi
  __int64 v49; // rax
  signed __int64 v50; // kr90_8
  const btConvexHullInternal::Rational64 *v51; // eax
  const btConvexHullInternal::Rational64 *v52; // esi
  btConvexHullInternal::Rational64 *v53; // eax
  btConvexHullInternal::Point32 *v54; // eax
  const btConvexHullInternal::Rational64 *v55; // eax
  const btConvexHullInternal::Rational64 *v56; // esi
  btConvexHullInternal::Rational64 *v57; // eax
  __int64 v58; // xmm0_8
  unsigned int v59; // edx
  btConvexHullInternal::Edge *v60; // eax
  btConvexHullInternal::Vertex *v61; // esi
  int v62; // eax
  __int64 v63; // rax
  unsigned int v64; // ebp
  int v65; // ecx
  __int64 v66; // rax
  btConvexHullInternal::Edge *v67; // eax
  btConvexHullInternal::Edge *v68; // eax
  btConvexHullInternal::Vertex *v69; // ebx
  int v70; // esi
  int v71; // edi
  int v72; // eax
  int v73; // edi
  int v74; // eax
  int v75; // esi
  int v76; // ebp
  const btConvexHullInternal::Rational64 *v77; // eax
  const btConvexHullInternal::Rational64 *v78; // esi
  btConvexHullInternal::Rational64 *v79; // eax
  btConvexHullInternal::Point32 *v80; // eax
  const btConvexHullInternal::Rational64 *v81; // eax
  const btConvexHullInternal::Rational64 *v82; // esi
  btConvexHullInternal::Rational64 *v83; // eax
  __int64 v84; // rcx
  __int64 v85; // xmm0_8
  __int64 v86; // [esp-10h] [ebp-168h]
  btConvexHullInternal::Edge *f1; // [esp+14h] [ebp-144h]
  btConvexHullInternal::Edge *f1a; // [esp+14h] [ebp-144h]
  btConvexHullInternal::Edge *f1b; // [esp+14h] [ebp-144h]
  btConvexHullInternal::Edge *f1c; // [esp+14h] [ebp-144h]
  btConvexHullInternal::Edge *f1d; // [esp+14h] [ebp-144h]
  __int64 maxDot1; // [esp+18h] [ebp-140h]
  __int64 maxDot1a; // [esp+18h] [ebp-140h]
  btConvexHullInternal::Point64 perp; // [esp+20h] [ebp-138h] BYREF
  __int64 dy0; // [esp+38h] [ebp-120h]
  btConvexHullInternal::Point32 et1; // [esp+40h] [ebp-118h]
  btConvexHullInternal::Point32 et0; // [esp+50h] [ebp-108h]
  __int64 dy1; // [esp+60h] [ebp-F8h]
  __int64 v99; // [esp+68h] [ebp-F0h]
  __int64 numerator; // [esp+70h] [ebp-E8h]
  btConvexHullInternal::Point32 s; // [esp+78h] [ebp-E0h] BYREF
  __int64 dy; // [esp+88h] [ebp-D0h]
  __int64 dxn; // [esp+90h] [ebp-C8h]
  __int64 dist; // [esp+98h] [ebp-C0h]
  btConvexHullInternal::Point64 normal; // [esp+A0h] [ebp-B8h] BYREF
  int v106; // [esp+BCh] [ebp-9Ch]
  __int64 dx0; // [esp+C0h] [ebp-98h]
  btConvexHullInternal::Edge *f0; // [esp+CCh] [ebp-8Ch]
  __int64 start1; // [esp+D0h] [ebp-88h] OVERLAPPED
  int v110; // [esp+DCh] [ebp-7Ch]
  __int64 x; // [esp+E0h] [ebp-78h]
  __int64 dx1; // [esp+E8h] [ebp-70h]
  btConvexHullInternal::Point32 v113; // [esp+F0h] [ebp-68h] BYREF
  btConvexHullInternal::Point32 d1; // [esp+100h] [ebp-58h]
  _BYTE v115[24]; // [esp+110h] [ebp-48h] BYREF
  btConvexHullInternal::Point32 d0; // [esp+128h] [ebp-30h] BYREF
  _BYTE v117[24]; // [esp+140h] [ebp-18h] BYREF

  v8 = *e0;
  v9 = *e1;
  f0 = v8;
  LODWORD(start1) = v9;
  if ( v8 )
    p_point = &v8->target->point;
  else
    p_point = &c0->point;
  et0 = *p_point;
  if ( v9 )
    v11 = &v9->target->point;
  else
    v11 = &c1->point;
  *(_QWORD *)&et1.x = *(_QWORD *)&v11->x;
  v12 = *(_QWORD *)&v11->z;
  v13 = c1->point.x - c0->point.x;
  *(_QWORD *)&et1.z = v12;
  s.x = v13;
  s.y = c1->point.y - c0->point.y;
  s.z = c1->point.z - c0->point.z;
  s.index = -1;
  if ( v8 )
    v9 = v8;
  target = v9->target;
  v15 = target->point.x - c0->point.x;
  target = (btConvexHullInternal::Vertex *)((char *)target + 88);
  v113.x = v15;
  prev = target->prev;
  v17 = (int)target->edges - c0->point.z;
  v18 = (int)prev - c0->point.y;
  v113.index = -1;
  v113.z = v17;
  v113.y = v18;
  btConvexHullInternal::Point32::cross(&s, &normal, &v113);
  v19 = (unsigned __int64)(c0->point.x * normal.x + c0->point.z * normal.z + c0->point.y * normal.y) >> 32;
  LODWORD(dist) = c0->point.x * LODWORD(normal.x) + c0->point.z * LODWORD(normal.z) + c0->point.y * LODWORD(normal.y);
  btConvexHullInternal::Point32::cross(&normal, (int)&perp, &s);
  dy0 = et0.z * perp.z + et0.y * perp.y + et0.x * perp.x;
  if ( v8 && v8->target )
  {
    do
    {
      v20 = (*e0)->reverse->prev->target;
      f1 = (*e0)->reverse->prev;
      if ( v20->point.x * normal.x + v20->point.z * normal.z + v20->point.y * normal.y < __SPAIR64__(v19, dist) )
        break;
      if ( f1->copy == this->mergeStamp )
        break;
      v21 = v20->point.x * perp.x + v20->point.z * perp.z + v20->point.y * perp.y;
      if ( v21 <= dy0 )
        break;
      v22 = *(_QWORD *)&v20->point.x;
      *e0 = f1;
      v23 = f1->target == 0;
      *(_QWORD *)&et0.x = v22;
      v24 = *(_QWORD *)&v20->point.z;
      dy0 = v21;
      *(_QWORD *)&et0.z = v24;
    }
    while ( !v23 );
  }
  maxDot1 = et1.z * perp.z + et1.y * perp.y + et1.x * perp.x;
  if ( *e1 && (*e1)->target )
  {
    do
    {
      v25 = (*e1)->reverse->next->target;
      f1a = (*e1)->reverse->next;
      if ( v25->point.x * normal.x + v25->point.z * normal.z + v25->point.y * normal.y < __SPAIR64__(v19, dist) )
        break;
      if ( f1a->copy == this->mergeStamp )
        break;
      v26 = v25->point.x * perp.x + v25->point.z * perp.z + v25->point.y * perp.y;
      if ( v26 <= maxDot1 )
        break;
      v27 = *(_QWORD *)&v25->point.x;
      *e1 = f1a;
      v23 = f1a->target == 0;
      *(_QWORD *)&et1.x = v27;
      maxDot1 = v26;
      *(_QWORD *)&et1.z = *(_QWORD *)&v25->point.z;
    }
    while ( !v23 );
  }
  v28 = maxDot1 - dy0;
  v29 = maxDot1 < dy0 || (unsigned __int64)(maxDot1 - dy0) >> 32 == 0;
  maxDot1a = maxDot1 - dy0;
  if ( maxDot1a >= 0 && (!v29 || (_DWORD)v28) )
  {
    while ( 1 )
    {
      dy = s.y * (et1.y - et0.y) + s.z * (et1.z - et0.z) + s.x * (et1.x - et0.x);
      v30 = *e0;
      if ( !*e0 )
        goto LABEL_29;
      if ( !v30->target )
        goto LABEL_29;
      f1b = v30->next->reverse;
      if ( f1b->copy <= this->mergeStamp )
        goto LABEL_29;
      v31 = f1b->target;
      v32 = v31->point.x - et0.x;
      v113.y = v31->point.y - et0.y;
      v113.z = v31->point.z - et0.z;
      v33 = v32 * perp.x;
      v110 = (unsigned __int64)(v113.y * perp.y + v33) >> 32;
      v34 = v113.z * LODWORD(perp.z) + v113.y * LODWORD(perp.y) + v33;
      v35 = v31->point.y - et0.y;
      HIDWORD(dx0) = (unsigned __int64)(v113.z * perp.z + v113.y * perp.y + v33) >> 32;
      v36 = s.y * v35 + s.z * (v31->point.z - et0.z) + s.x * (v31->point.x - et0.x);
      dy0 = v36;
      if ( __PAIR64__(HIDWORD(dx0), v34) )
      {
        if ( dx0 < 0 )
        {
          btConvexHullInternal::Rational64::Rational64(
            (btConvexHullInternal::Rational64 *)(HIDWORD(dx0) | v34),
            (int)&d0,
            dy,
            v28);
          v52 = v51;
          btConvexHullInternal::Rational64::Rational64(
            (btConvexHullInternal::Rational64 *)HIDWORD(dx0),
            (int)v115,
            dy0,
            __SPAIR64__(HIDWORD(dx0), v34));
          if ( btConvexHullInternal::Rational64::compare(v53, v52) >= 0 )
            goto LABEL_41;
        }
LABEL_29:
        v37 = *e1;
        if ( !*e1 )
          return;
        if ( !v37->target )
          return;
        p_next = &v37->reverse->next;
        f1c = *p_next;
        if ( (*p_next)->copy <= this->mergeStamp )
          return;
        v39 = f1c->target;
        v40 = v39->point.y - et1.y;
        v41 = v39->point.z - et1.z;
        d1.x = v39->point.x - et1.x;
        numerator = v40;
        start1 = v41;
        x = d1.x;
        v106 = (unsigned __int64)(normal.z * v41 + d1.x * normal.x) >> 32;
        if ( normal.y * v40 + normal.z * v41 + d1.x * normal.x )
          return;
        HIDWORD(dist) = (unsigned __int64)(perp.z * start1 + x * perp.x) >> 32;
        v42 = LODWORD(perp.y) * numerator + LODWORD(perp.z) * start1 + x * LODWORD(perp.x);
        HIDWORD(dx1) = (unsigned __int64)(perp.y * numerator + perp.z * start1 + x * perp.x) >> 32;
        v43 = s.z * v41 + s.x * d1.x;
        v44 = v39->point.z - et0.z;
        v45 = s.y * v40 + v43;
        v46 = v39->point.y - et0.y;
        dy1 = v45;
        v99 = (v39->point.x - et0.x) * perp.x;
        v47 = v46 * perp.y;
        v48 = v47 + v99;
        HIDWORD(v99) = (unsigned __int64)(v47 + v99) >> 32;
        v49 = v44 * perp.z;
        v50 = v49 + __PAIR64__(HIDWORD(v99), v48);
        dxn = v49 + __PAIR64__(HIDWORD(v99), v48);
        if ( (((v49 + __PAIR64__(HIDWORD(v99), v48)) >> 32) & 0x80000000) != 0LL
          || (v50 < 0)
           ^ (__OFADD__(__CFADD__((_DWORD)v49, v48), HIDWORD(v99))
            | __OFADD__(HIDWORD(v49), __CFADD__((_DWORD)v49, v48) + HIDWORD(v99)))
           | (HIDWORD(v50) == 0)
          && !(_DWORD)v50 )
        {
          return;
        }
        if ( HIDWORD(dx1) | v42 )
        {
          if ( dx1 >= 0 )
            return;
          btConvexHullInternal::Rational64::Rational64(
            (btConvexHullInternal::Rational64 *)HIDWORD(dy),
            (int)v115,
            dy,
            maxDot1a);
          v56 = v55;
          btConvexHullInternal::Rational64::Rational64(
            (btConvexHullInternal::Rational64 *)HIDWORD(dy1),
            (int)&d0,
            dy1,
            __SPAIR64__(HIDWORD(dx1), v42));
          if ( btConvexHullInternal::Rational64::compare(v57, v56) <= 0 )
            return;
        }
        else if ( dy1 >= 0 )
        {
          return;
        }
        v58 = *(_QWORD *)&v39->point.x;
        v59 = dxn;
        *e1 = f1c;
        *(_QWORD *)&et1.x = v58;
        *(_QWORD *)&et1.z = *(_QWORD *)&v39->point.z;
        maxDot1a = __PAIR64__(HIDWORD(dxn), v59);
        v28 = __PAIR64__(HIDWORD(dxn), v59);
      }
      else
      {
        if ( v36 >= 0 )
          goto LABEL_29;
LABEL_41:
        v54 = &f1b->target->point;
        et0 = *v54;
        maxDot1a = (et1.z - et0.z) * perp.z + (et1.y - et0.y) * perp.y + (et1.x - et0.x) * perp.x;
        *e0 = *e0 != f0 ? f1b : 0;
        v28 = maxDot1a;
      }
    }
  }
  if ( v28 < 0 )
  {
    while ( 1 )
    {
      numerator = s.y * (et1.y - et0.y) + s.z * (et1.z - et0.z) + s.x * (et1.x - et0.x);
      v60 = *e1;
      if ( !*e1 )
        goto LABEL_52;
      if ( !v60->target )
        goto LABEL_52;
      f1d = v60->prev->reverse;
      if ( f1d->copy <= this->mergeStamp )
        goto LABEL_52;
      v61 = f1d->target;
      v62 = v61->point.x - et1.x;
      d1.y = v61->point.y - et1.y;
      d1.z = v61->point.z - et1.z;
      v63 = v62 * perp.x;
      HIDWORD(dist) = (unsigned __int64)(d1.y * perp.y + v63) >> 32;
      v64 = d1.z * LODWORD(perp.z) + d1.y * LODWORD(perp.y) + v63;
      v65 = v61->point.y - et1.y;
      HIDWORD(x) = (unsigned __int64)(d1.z * perp.z + d1.y * perp.y + v63) >> 32;
      v66 = s.y * v65 + s.z * (v61->point.z - et1.z) + s.x * (v61->point.x - et1.x);
      dy1 = v66;
      if ( __PAIR64__(HIDWORD(x), v64) )
      {
        if ( x < 0 )
        {
          btConvexHullInternal::Rational64::Rational64(
            (btConvexHullInternal::Rational64 *)(HIDWORD(x) | v64),
            (int)v115,
            numerator,
            v28);
          v78 = v77;
          btConvexHullInternal::Rational64::Rational64(
            (btConvexHullInternal::Rational64 *)HIDWORD(x),
            (int)v117,
            dy1,
            __SPAIR64__(HIDWORD(x), v64));
          if ( btConvexHullInternal::Rational64::compare(v79, v78) <= 0 )
            goto LABEL_62;
        }
LABEL_52:
        v67 = *e0;
        if ( !*e0 )
          return;
        if ( !v67->target )
          return;
        v68 = v67->reverse->prev;
        v29 = v68->copy <= this->mergeStamp;
        f0 = v68;
        if ( v29 )
          return;
        v69 = v68->target;
        v70 = v69->point.y - et0.y;
        v71 = v69->point.z - et0.z;
        d0.x = v69->point.x - et0.x;
        v99 = v70;
        dy = v71;
        dx0 = d0.x;
        v106 = (unsigned __int64)(v71 * normal.z + d0.x * normal.x) >> 32;
        if ( v70 * normal.y + v71 * normal.z + d0.x * normal.x )
          return;
        v110 = (unsigned __int64)(dy * perp.z + dx0 * perp.x) >> 32;
        v72 = s.z * v71 + s.x * d0.x;
        v73 = et1.z - v69->point.z;
        v74 = s.y * v70 + v72;
        v75 = et1.y - v69->point.y;
        dxn = v74;
        v86 = et1.x - v69->point.x;
        dy0 = v99 * perp.y + dy * perp.z + dx0 * perp.x;
        v113.x = v86 * LODWORD(perp.x);
        v76 = (unsigned __int64)(v73 * perp.z + v75 * perp.y + v86 * perp.x) >> 32;
        LODWORD(dx1) = v73 * LODWORD(perp.z) + v75 * LODWORD(perp.y) + v86 * LODWORD(perp.x);
        if ( v76 >= 0 )
          return;
        if ( dy0 )
        {
          if ( dy0 >= 0 )
            return;
          btConvexHullInternal::Rational64::Rational64(
            (btConvexHullInternal::Rational64 *)maxDot1a,
            (int)v117,
            numerator,
            maxDot1a);
          v82 = v81;
          btConvexHullInternal::Rational64::Rational64((btConvexHullInternal::Rational64 *)dxn, (int)v115, dxn, dy0);
          if ( btConvexHullInternal::Rational64::compare(v83, v82) >= 0 )
            return;
        }
        else if ( dxn <= 0 )
        {
          return;
        }
        LODWORD(v84) = dx1;
        *(_QWORD *)&et0.x = *(_QWORD *)&v69->point.x;
        v85 = *(_QWORD *)&v69->point.z;
        *e0 = f0;
        *(_QWORD *)&et0.z = v85;
        maxDot1a = __PAIR64__(v76, v84);
        HIDWORD(v84) = v76;
        v28 = v84;
      }
      else
      {
        if ( v66 < 0 || !(_DWORD)v66 )
          goto LABEL_52;
LABEL_62:
        v80 = &f1d->target->point;
        et1 = *v80;
        maxDot1a = (et1.z - et0.z) * perp.z + (et1.y - et0.y) * perp.y + (et1.x - et0.x) * perp.x;
        *e1 = *e1 != (btConvexHullInternal::Edge *)start1 ? f1d : 0;
        v28 = maxDot1a;
      }
    }
  }
}
