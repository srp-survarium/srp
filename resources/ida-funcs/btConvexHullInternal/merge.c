void __userpurge btConvexHullInternal::merge(
        btConvexHullInternal *h0@<ecx>,
        btConvexHullInternal::IntermediateHull *h1@<eax>,
        btConvexHullInternal *this)
{
  btConvexHullInternal::Vertex *v3; // edi
  btConvexHullInternal::Point32 *v4; // ecx
  btConvexHullInternal::Point32 *p_point; // edi
  btConvexHullInternal::Edge *next; // eax
  bool i; // zf
  btConvexHullInternal::Point32 *v8; // edi
  btConvexHullInternal::Vertex *v9; // edi
  btConvexHullInternal::Point32 *v10; // ecx
  btConvexHullInternal *v11; // ecx
  btConvexHullInternal *v12; // ecx
  btConvexHullInternal::Edge *v13; // eax
  BOOL v14; // ecx
  btConvexHullInternal::Edge *v15; // eax
  bool v16; // zf
  char v17; // al
  btConvexHullInternal::Edge *v18; // eax
  btConvexHullInternal::Edge *v19; // ecx
  btConvexHullInternal::Edge *v20; // eax
  bool v21; // sf
  btConvexHullInternal::Edge **v22; // edi
  btConvexHullInternal::Edge *v23; // eax
  const btConvexHullInternal::Edge *v24; // esi
  btConvexHullInternal::Edge *v25; // esi
  const btConvexHullInternal::Edge *v26; // edx
  btConvexHullInternal::Edge *v27; // eax
  btConvexHullInternal::Edge *v28; // ecx
  btConvexHullInternal::Edge *prev; // eax
  btConvexHullInternal::Vertex *v30; // ecx
  btConvexHullInternal::Edge *v31; // eax
  btConvexHullInternal::Edge *v32; // esi
  btConvexHullInternal::Edge *v33; // edi
  btConvexHullInternal::Edge *k; // eax
  btConvexHullInternal::Edge *v35; // edx
  btConvexHullInternal::Edge *v36; // eax
  btConvexHullInternal::Edge *v37; // ecx
  btConvexHullInternal::Edge *v38; // eax
  btConvexHullInternal::Vertex *v39; // ecx
  btConvexHullInternal::Edge *v40; // eax
  btConvexHullInternal::Vertex *v41; // ebx
  btConvexHullInternal::Edge *v42; // eax
  btConvexHullInternal::Edge *reverse; // eax
  btConvexHullInternal::Edge *v44; // esi
  btConvexHullInternal::Edge *v45; // eax
  btConvexHullInternal::Edge *v46; // ecx
  btConvexHullInternal::Edge *v47; // eax
  btConvexHullInternal::Edge *v48; // edi
  btConvexHullInternal::Edge *v49; // eax
  btConvexHullInternal::Edge *v50; // ecx
  btConvexHullInternal::Edge **v51; // esi
  btConvexHullInternal::Edge *v52; // ecx
  btConvexHullInternal::Edge *v53; // eax
  btConvexHullInternal::Edge *v54; // eax
  btConvexHullInternal::Edge *z; // edi
  btConvexHullInternal::Edge *v56; // eax
  btConvexHullInternal::Edge *v57; // ecx
  btConvexHullInternal::Point32 *v58; // [esp+0h] [ebp-F4h]
  btConvexHullInternal::Vertex *v59; // [esp+4h] [ebp-F0h]
  btConvexHullInternal::Point64 v60; // [esp+10h] [ebp-E4h] BYREF
  btConvexHullInternal::Point64 v61; // [esp+28h] [ebp-CCh] BYREF
  btConvexHullInternal::Point32 *v62; // [esp+40h] [ebp-B4h]
  btConvexHullInternal::Vertex *v63; // [esp+44h] [ebp-B0h]
  btConvexHullInternal::Point32 v64; // [esp+48h] [ebp-ACh] BYREF
  btConvexHullInternal::Rational64 v65; // [esp+58h] [ebp-9Ch] BYREF
  btConvexHullInternal::Rational64 b; // [esp+70h] [ebp-84h] BYREF
  btConvexHullInternal::Point64 v67; // [esp+88h] [ebp-6Ch] BYREF
  btConvexHullInternal::Edge *v68; // [esp+A0h] [ebp-54h] BYREF
  btConvexHullInternal::Edge **p_next; // [esp+A4h] [ebp-50h]
  btConvexHullInternal::Edge *v70; // [esp+A8h] [ebp-4Ch]
  btConvexHullInternal::Edge *v71; // [esp+ACh] [ebp-48h] BYREF
  btConvexHullInternal::Edge *v72; // [esp+B0h] [ebp-44h]
  btConvexHullInternal::Vertex *v73; // [esp+B4h] [ebp-40h]
  btConvexHullInternal::Point32 point; // [esp+B8h] [ebp-3Ch] BYREF
  btConvexHullInternal::Edge *v75; // [esp+C8h] [ebp-2Ch]
  btConvexHullInternal::Edge *v76; // [esp+CCh] [ebp-28h]
  btConvexHullInternal::Edge *v77; // [esp+D0h] [ebp-24h]
  btConvexHullInternal::Edge *v78; // [esp+D4h] [ebp-20h]
  btConvexHullInternal::Edge *MaxAngle; // [esp+D8h] [ebp-1Ch] BYREF
  char j; // [esp+DFh] [ebp-15h]
  btConvexHullInternal::Vertex *v81; // [esp+E0h] [ebp-14h] BYREF
  int v82; // [esp+E4h] [ebp-10h] BYREF
  btConvexHullInternal::Vertex *target; // [esp+E8h] [ebp-Ch] BYREF
  const btConvexHullInternal::Edge *edges; // [esp+ECh] [ebp-8h]

  if ( !h1->maxXy )
    return;
  if ( !h0->scaling.mVec128.m128_i32[1] )
  {
    h0->scaling = (btVector3)*h1;
    return;
  }
  --this->mergeStamp;
  v81 = 0;
  v70 = 0;
  v72 = 0;
  v76 = 0;
  v78 = 0;
  target = 0;
  p_next = 0;
  LODWORD(v67.z) = 0;
  v75 = 0;
  v77 = 0;
  if ( btConvexHullInternal::mergeProjection(h0, (btConvexHullInternal::IntermediateHull *)h0, h1, &v81, &target) )
  {
    v3 = v81;
    btConvexHullInternal::Point32::operator-(&v81->point, (btConvexHullInternal::Point32 *)&v67, &target->point, v58);
    point.z = -1;
    point.index = -1;
    point.x = 0;
    point.y = 0;
    btConvexHullInternal::Point32::cross((const btConvexHullInternal::Point32 *)&v67, &v65, &point);
    btConvexHullInternal::Point32::cross(v4, (int)&v61, &v67, (const btConvexHullInternal::Point64 *)&v65);
    edges = v3->edges;
    v82 = 0;
    if ( edges )
    {
      do
      {
        p_point = &edges->target->point;
        btConvexHullInternal::Point32::operator-(&v81->point, &v64, p_point, v58);
        if ( !btConvexHullInternal::Point32::dot((const btConvexHullInternal::Point64 *)&v65, &v64) )
        {
          btConvexHullInternal::Point32::operator-(
            &v81->point,
            (btConvexHullInternal::Point32 *)&b.denominator,
            p_point,
            v58);
          if ( btConvexHullInternal::Point32::dot(&v61, (btConvexHullInternal::Point32 *)&b.denominator) > 0 )
          {
            if ( !v82
              || (point.z = -1,
                  point.index = -1,
                  point.x = 0,
                  point.y = 0,
                  btConvexHullInternal::getOrientation(
                    (const btConvexHullInternal::Edge *)v82,
                    edges,
                    (const btConvexHullInternal::Point32 *)&v67,
                    &point) == 1) )
            {
              v82 = (int)edges;
            }
          }
        }
        edges = edges->next;
      }
      while ( edges != v81->edges );
    }
    next = target->edges;
    MaxAngle = 0;
    for ( i = next == 0; ; i = edges->next == target->edges )
    {
      edges = next;
      if ( i )
        break;
      v8 = &edges->target->point;
      btConvexHullInternal::Point32::operator-(&target->point, (btConvexHullInternal::Point32 *)&b.denominator, v8, v58);
      if ( !btConvexHullInternal::Point32::dot(
              (const btConvexHullInternal::Point64 *)&v65,
              (btConvexHullInternal::Point32 *)&b.denominator) )
      {
        btConvexHullInternal::Point32::operator-(&target->point, &v64, v8, v58);
        if ( btConvexHullInternal::Point32::dot(&v61, &v64) > 0 )
        {
          if ( !MaxAngle
            || (point.z = -1,
                point.index = -1,
                point.x = 0,
                point.y = 0,
                btConvexHullInternal::getOrientation(
                  MaxAngle,
                  edges,
                  (const btConvexHullInternal::Point32 *)&v67,
                  &point) == 2) )
          {
            MaxAngle = (btConvexHullInternal::Edge *)edges;
          }
        }
      }
      next = edges->next;
    }
    if ( v82 || MaxAngle )
    {
      btConvexHullInternal::findEdgeForCoplanarFaces(
        target,
        this,
        v81,
        (btConvexHullInternal::Edge **)&v82,
        &MaxAngle,
        (btConvexHullInternal::Vertex *)v58,
        v59);
      if ( v82 )
        v81 = *(btConvexHullInternal::Vertex **)(v82 + 12);
      if ( MaxAngle )
        target = MaxAngle->target;
    }
    point = target->point;
    ++point.z;
  }
  else
  {
    point = target->point;
    ++point.x;
  }
  HIDWORD(v67.y) = -1;
  v9 = v81;
  v63 = v81;
  v73 = target;
  for ( j = 1; ; j = 0 )
  {
    HIDWORD(v67.z) = &target->point;
    v62 = &v9->point;
    btConvexHullInternal::Point32::operator-(&v9->point, &v64, &target->point, v58);
    LODWORD(v67.x) = point.x - v9->point.x;
    HIDWORD(v67.x) = point.y - v9->point.y;
    LODWORD(v67.y) = point.z - v9->point.z;
    btConvexHullInternal::Point32::cross(&v64, &v61, (btConvexHullInternal::Point32 *)&v67);
    btConvexHullInternal::Point32::cross(v10, (int)&v60, (btConvexHullInternal::Point64 *)&v64, &v61);
    memset(&v65, 0, 20);
    MaxAngle = btConvexHullInternal::findMaxAngle(
                 v11,
                 (int)this,
                 0,
                 (const btConvexHullInternal::Point32 *)v9,
                 &v64,
                 &v61,
                 &v60,
                 &v65);
    memset(&b, 0, 20);
    v13 = btConvexHullInternal::findMaxAngle(
            v12,
            (int)this,
            (const btConvexHullInternal::Vertex *)1,
            (const btConvexHullInternal::Point32 *)target,
            &v64,
            &v61,
            &v60,
            &b);
    edges = v13;
    if ( MaxAngle )
    {
      if ( edges )
      {
        v15 = (btConvexHullInternal::Edge *)btConvexHullInternal::Rational64::compare(&b, &v65);
        v9 = v81;
        v82 = (int)v15;
      }
      else
      {
        v82 = -1;
      }
    }
    else
    {
      if ( !v13 )
      {
        v41 = target;
        v42 = btConvexHullInternal::newEdgePair(
                (btConvexHullInternal *)v14,
                (btConvexHullInternal::Edge ***)this,
                v9,
                target);
        v42->next = v42;
        v42->prev = v42;
        v9->edges = v42;
        reverse = v42->reverse;
        reverse->next = reverse;
        reverse->prev = reverse;
        v41->edges = reverse;
        return;
      }
      v82 = 1;
    }
    if ( !j )
    {
      if ( v82 < 0 )
      {
        if ( v65.sign >= 0 )
          goto LABEL_43;
        v16 = v65.denominator == 0;
      }
      else
      {
        if ( b.sign >= 0 )
          goto LABEL_43;
        v16 = b.denominator == 0;
      }
      if ( v16 )
      {
        v17 = 1;
        goto LABEL_44;
      }
LABEL_43:
      v17 = 0;
LABEL_44:
      v14 = v17 == 0;
      if ( v17 )
        goto LABEL_52;
    }
    v18 = btConvexHullInternal::newEdgePair(
            (btConvexHullInternal *)v14,
            (btConvexHullInternal::Edge ***)this,
            v9,
            target);
    if ( v78 )
      v78->prev = v18;
    else
      v76 = v18;
    v18->next = v78;
    v19 = v77;
    v78 = v18;
    v20 = v18->reverse;
    if ( v77 )
      v77->next = v20;
    else
      v75 = v20;
    v20->prev = v19;
    v77 = v20;
LABEL_52:
    v71 = MaxAngle;
    v68 = (btConvexHullInternal::Edge *)edges;
    v21 = v82 < 0;
    if ( !v82 )
    {
      btConvexHullInternal::findEdgeForCoplanarFaces(
        target,
        this,
        v9,
        &v71,
        &v68,
        (btConvexHullInternal::Vertex *)v58,
        v59);
      v21 = v82 < 0;
    }
    if ( !v21 && v68 )
    {
      v22 = p_next;
      if ( p_next )
      {
        v23 = *p_next;
        if ( *p_next != edges )
        {
          do
          {
            v24 = v23->next;
            btConvexHullInternal::removeEdgePair(this, v23);
            v23 = (btConvexHullInternal::Edge *)v24;
          }
          while ( v24 != edges );
        }
      }
      v25 = v77;
      if ( v77 )
      {
        v26 = edges;
        if ( v22 )
        {
          v27 = v75;
          *v22 = v75;
          v27->prev = (btConvexHullInternal::Edge *)v22;
        }
        else
        {
          v28 = v75;
          prev = edges->prev;
          prev->next = v75;
          v28->prev = prev;
          LODWORD(v67.z) = v28;
        }
        v25->next = (btConvexHullInternal::Edge *)v26;
        v26->prev = v25;
        v75 = 0;
        v77 = 0;
      }
      else if ( !v22 )
      {
        LODWORD(v67.z) = edges;
      }
      v30 = v68->target;
      v31 = v68->reverse;
      point = *(btConvexHullInternal::Point32 *)HIDWORD(v67.z);
      v9 = v81;
      target = v30;
      p_next = &v31->next;
    }
    if ( v82 <= 0 && v71 )
    {
      v32 = v70;
      v33 = MaxAngle;
      if ( v70 )
      {
        for ( k = v70->prev; k != v33; k = (btConvexHullInternal::Edge *)HIDWORD(v67.z) )
        {
          HIDWORD(v67.z) = k->prev;
          btConvexHullInternal::removeEdgePair(this, k);
        }
      }
      v35 = v78;
      if ( v78 )
      {
        if ( v32 )
        {
          v36 = v76;
          v76->next = v32;
          v32->prev = v36;
        }
        else
        {
          v37 = v76;
          v38 = v33->next;
          v76->next = v33->next;
          v38->prev = v37;
          v72 = v37;
        }
        v33->next = v35;
        v35->prev = v33;
        v76 = 0;
        v78 = 0;
      }
      else if ( !v32 )
      {
        v72 = v33;
      }
      v39 = v71->target;
      v40 = v71->reverse;
      point = *v62;
      v81 = v39;
      v70 = v40;
      v9 = v39;
    }
    if ( v9 == v63 && target == v73 )
      break;
  }
  v44 = v70;
  if ( v70 )
  {
    v47 = v70->prev;
    v48 = v72;
    while ( v47 != v48 )
    {
      v73 = (btConvexHullInternal::Vertex *)v47->prev;
      btConvexHullInternal::removeEdgePair(this, v47);
      v47 = (btConvexHullInternal::Edge *)v73;
    }
    v49 = v78;
    if ( v78 )
    {
      v50 = v76;
      v76->next = v44;
      v44->prev = v50;
      v48->next = v49;
      v49->prev = v48;
    }
  }
  else
  {
    v45 = v78;
    v46 = v76;
    v76->next = v78;
    v45->prev = v46;
    v9->edges = v45;
  }
  v51 = p_next;
  if ( p_next )
  {
    v54 = *p_next;
    z = (btConvexHullInternal::Edge *)v67.z;
    while ( v54 != z )
    {
      v73 = (btConvexHullInternal::Vertex *)v54->next;
      btConvexHullInternal::removeEdgePair(this, v54);
      v54 = (btConvexHullInternal::Edge *)v73;
    }
    v56 = v77;
    if ( v77 )
    {
      v57 = v75;
      *v51 = v75;
      v57->prev = (btConvexHullInternal::Edge *)v51;
      v56->next = z;
      z->prev = v56;
    }
  }
  else
  {
    v52 = v75;
    v53 = v77;
    v77->next = v75;
    v52->prev = v53;
    target->edges = v53;
  }
}
