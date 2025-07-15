char __thiscall btConvexHullInternal::mergeProjection(
        btConvexHullInternal *this,
        btConvexHullInternal::IntermediateHull *h0,
        btConvexHullInternal::IntermediateHull *h1,
        btConvexHullInternal::Vertex **c0,
        btConvexHullInternal::Vertex **c1)
{
  btConvexHullInternal::IntermediateHull *v5; // ebx
  btConvexHullInternal::Vertex *minYx; // eax
  btConvexHullInternal::IntermediateHull *v7; // edi
  btConvexHullInternal::Vertex *maxYx; // ecx
  btConvexHullInternal::Vertex *prev; // edx
  btConvexHullInternal::Edge *edges; // ecx
  btConvexHullInternal::Vertex *next; // ecx
  int x; // esi
  int v14; // edi
  int v15; // eax
  int v16; // esi
  btConvexHullInternal::Vertex *maxXy; // eax
  btConvexHullInternal::Vertex *minXy; // ecx
  int v19; // edx
  int v20; // esi
  btConvexHullInternal::Vertex *v21; // edi
  int v22; // edx
  int v23; // edi
  int v24; // edx
  btConvexHullInternal::Vertex *v25; // edi
  int v26; // edx
  int v27; // edi
  int v28; // esi
  int v29; // edx
  int v30; // esi
  btConvexHullInternal::Vertex *v31; // edi
  int v32; // edx
  int v33; // edi
  btConvexHullInternal::Vertex *v34; // esi
  int v35; // ebx
  int v36; // esi
  int v37; // edx
  btConvexHullInternal::Vertex *v38; // esi
  btConvexHullInternal::Vertex *v39; // esi
  int v40; // esi
  btConvexHullInternal::Vertex *v41; // edx
  btConvexHullInternal::Vertex *v42; // esi
  int v43; // esi
  btConvexHullInternal::Vertex *v44; // eax
  btConvexHullInternal::Vertex *v45; // [esp+Ch] [ebp-20h]
  int v46; // [esp+10h] [ebp-1Ch]
  int v47; // [esp+10h] [ebp-1Ch]
  int v48; // [esp+10h] [ebp-1Ch]
  int v49; // [esp+14h] [ebp-18h]
  btConvexHullInternal::Vertex *v50; // [esp+14h] [ebp-18h]
  btConvexHullInternal::Vertex *v51; // [esp+14h] [ebp-18h]
  int y; // [esp+14h] [ebp-18h]
  int v53; // [esp+14h] [ebp-18h]
  btConvexHullInternal::Vertex *v54; // [esp+18h] [ebp-14h]
  btConvexHullInternal::Vertex *v55; // [esp+1Ch] [ebp-10h]
  btConvexHullInternal::Vertex *v56; // [esp+1Ch] [ebp-10h]
  int v57; // [esp+1Ch] [ebp-10h]
  btConvexHullInternal::Vertex *v58; // [esp+1Ch] [ebp-10h]
  btConvexHullInternal::Vertex *v59; // [esp+1Ch] [ebp-10h]
  int v60; // [esp+20h] [ebp-Ch]
  btConvexHullInternal::Vertex *v61; // [esp+20h] [ebp-Ch]
  btConvexHullInternal::Vertex *v62; // [esp+20h] [ebp-Ch]
  int i; // [esp+24h] [ebp-8h]
  int v64; // [esp+28h] [ebp-4h]

  v5 = h1;
  minYx = h1->minYx;
  v7 = h0;
  maxYx = h0->maxYx;
  if ( maxYx->point.x == minYx->point.x && maxYx->point.y == minYx->point.y )
  {
    prev = minYx->prev;
    if ( prev == minYx )
    {
      *c0 = maxYx;
      edges = minYx->edges;
      if ( edges )
        minYx = edges->target;
      *c1 = minYx;
      return 0;
    }
    next = minYx->next;
    prev->next = minYx->next;
    next->prev = prev;
    if ( minYx == h1->minXy )
    {
      x = next->point.x;
      v14 = prev->point.x;
      if ( x < v14 || x == v14 && next->point.y < prev->point.y )
        h1->minXy = next;
      else
        h1->minXy = prev;
      v7 = h0;
    }
    if ( minYx == h1->maxXy )
    {
      v15 = next->point.x;
      v16 = prev->point.x;
      if ( v15 > v16 || v15 == v16 && next->point.y > prev->point.y )
        h1->maxXy = next;
      else
        h1->maxXy = prev;
    }
  }
  maxXy = v7->maxXy;
  minXy = h1->maxXy;
  v45 = 0;
  v54 = 0;
  v64 = 1;
  for ( i = 0; i <= 1; ++i )
  {
    v19 = maxXy->point.x;
    v20 = v64 * (minXy->point.x - v19);
    v46 = v19;
    v60 = v20;
    if ( v20 > 0 )
    {
      while ( 1 )
      {
        v49 = minXy->point.y - maxXy->point.y;
        if ( i )
          v21 = maxXy->next;
        else
          v21 = maxXy->prev;
        v55 = v21;
        if ( v21 != maxXy )
        {
          v22 = v21->point.x;
          v23 = v21->point.y - maxXy->point.y;
          v47 = v22;
          v24 = v64 * (v22 - maxXy->point.x);
          if ( v23 <= 0 && (!v24 || v24 < 0 && v20 * v23 <= v49 * v24) )
          {
            maxXy = v55;
            v20 = v64 * (minXy->point.x - v47);
            goto LABEL_31;
          }
          v5 = h1;
        }
        if ( i )
          v25 = minXy->next;
        else
          v25 = minXy->prev;
        v56 = v25;
        if ( v25 == minXy )
          goto LABEL_84;
        v26 = v25->point.x;
        v27 = v25->point.y - minXy->point.y;
        v28 = v26;
        v29 = v64 * (v26 - maxXy->point.x);
        v30 = v64 * (v28 - minXy->point.x);
        if ( v29 <= 0 || v27 >= 0 || v30 && (v30 >= 0 || v60 * v27 >= v49 * v30) )
          goto LABEL_83;
        minXy = v56;
        v20 = v29;
LABEL_31:
        v5 = h1;
        v60 = v20;
      }
    }
    if ( v20 >= 0 )
    {
      y = maxXy->point.y;
      v38 = maxXy;
      v58 = maxXy;
      while ( 1 )
      {
        v39 = i ? v38->next : v38->prev;
        v61 = v39;
        if ( v39 == maxXy )
          break;
        if ( v39->point.x != v19 )
          break;
        v40 = v39->point.y;
        if ( v40 > y )
          break;
        v58 = v61;
        v19 = maxXy->point.x;
        y = v40;
        v38 = v61;
      }
      maxXy = v58;
      v53 = minXy->point.y;
      v41 = minXy;
      v59 = minXy;
      while ( 1 )
      {
        if ( i )
          v42 = v41->prev;
        else
          v42 = v41->next;
        v62 = v42;
        if ( v42 == minXy )
          goto LABEL_82;
        if ( v42->point.x != v46 )
          break;
        v43 = v42->point.y;
        if ( v43 < v53 )
          break;
        v41 = v62;
        v59 = v62;
        v53 = v43;
      }
      v41 = v59;
LABEL_82:
      minXy = v41;
      goto LABEL_85;
    }
    while ( 1 )
    {
      v57 = minXy->point.y - maxXy->point.y;
      if ( i )
        v31 = minXy->prev;
      else
        v31 = minXy->next;
      v50 = v31;
      if ( v31 != minXy )
      {
        v48 = v31->point.x;
        v32 = v64 * (v48 - minXy->point.x);
        v33 = v31->point.y - minXy->point.y;
        if ( v33 >= 0 && (!v32 || v32 < 0 && v20 * v33 <= v57 * v32) )
        {
          minXy = v50;
          v20 = v64 * (v48 - maxXy->point.x);
          goto LABEL_53;
        }
        v5 = h1;
      }
      if ( i )
        v34 = maxXy->prev;
      else
        v34 = maxXy->next;
      v51 = v34;
      if ( v34 == maxXy )
        goto LABEL_84;
      v35 = v34->point.x;
      v36 = v34->point.y - maxXy->point.y;
      v37 = v64 * (v35 - maxXy->point.x);
      if ( v64 * (minXy->point.x - v35) >= 0 || v36 <= 0 || v37 && (v37 >= 0 || v60 * v36 >= v57 * v37) )
        break;
      maxXy = v51;
      v20 = v64 * (minXy->point.x - v35);
LABEL_53:
      v5 = h1;
      v60 = v20;
    }
LABEL_83:
    v5 = h1;
LABEL_84:
    v7 = h0;
LABEL_85:
    if ( !i )
    {
      v64 = -1;
      v45 = maxXy;
      maxXy = v7->minXy;
      v54 = minXy;
      minXy = v5->minXy;
    }
  }
  maxXy->prev = minXy;
  minXy->next = maxXy;
  v45->next = v54;
  v54->prev = v45;
  if ( v5->minXy->point.x < v7->minXy->point.x )
    v7->minXy = v5->minXy;
  v44 = v5->maxXy;
  if ( v44->point.x >= v7->maxXy->point.x )
    v7->maxXy = v44;
  v7->maxYx = v5->maxYx;
  *c0 = v45;
  *c1 = v54;
  return 1;
}
