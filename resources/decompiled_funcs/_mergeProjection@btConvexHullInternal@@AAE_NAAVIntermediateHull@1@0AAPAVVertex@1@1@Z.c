char __thiscall btConvexHullInternal::mergeProjection(
        btConvexHullInternal *this,
        btConvexHullInternal::IntermediateHull *h0,
        btConvexHullInternal::IntermediateHull *h1,
        btConvexHullInternal::Vertex **c0,
        btConvexHullInternal::Vertex **c1)
{
  btConvexHullInternal::Vertex *minYx; // eax
  btConvexHullInternal::Vertex *maxYx; // ecx
  btConvexHullInternal::Vertex *prev; // edx
  btConvexHullInternal::Edge *edges; // ecx
  btConvexHullInternal::Vertex *next; // ecx
  int x; // esi
  int v12; // edi
  int v13; // eax
  int v14; // esi
  btConvexHullInternal::Vertex *maxXy; // edx
  btConvexHullInternal::Vertex *minXy; // esi
  int v17; // ebp
  int v18; // eax
  int v19; // ebp
  btConvexHullInternal::Vertex *v20; // edi
  int v21; // eax
  btConvexHullInternal::Vertex *v22; // ebp
  int v23; // edi
  int v24; // ecx
  int v25; // eax
  int v26; // ecx
  btConvexHullInternal::Vertex *v27; // ebp
  int v28; // eax
  int v29; // edi
  btConvexHullInternal::Vertex *v30; // ebp
  int v31; // ebx
  int v32; // edi
  int v33; // eax
  int y; // ebx
  btConvexHullInternal::Vertex *v35; // edi
  btConvexHullInternal::Vertex *v36; // eax
  int v37; // ebx
  btConvexHullInternal::Vertex *v38; // edi
  btConvexHullInternal::Vertex *v39; // eax
  btConvexHullInternal::Vertex *v40; // eax
  int sign; // [esp+10h] [ebp-18h]
  int v42; // [esp+14h] [ebp-14h]
  int side; // [esp+18h] [ebp-10h]
  btConvexHullInternal::Vertex *v00; // [esp+1Ch] [ebp-Ch]
  btConvexHullInternal::Vertex *v10; // [esp+20h] [ebp-8h]
  int dy; // [esp+24h] [ebp-4h]
  int dya; // [esp+24h] [ebp-4h]

  minYx = h1->minYx;
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
      v12 = prev->point.x;
      if ( x < v12 || x == v12 && next->point.y < prev->point.y )
        h1->minXy = next;
      else
        h1->minXy = prev;
    }
    if ( minYx == h1->maxXy )
    {
      v13 = next->point.x;
      v14 = prev->point.x;
      if ( v13 > v14 || v13 == v14 && next->point.y > prev->point.y )
        h1->maxXy = next;
      else
        h1->maxXy = prev;
    }
  }
  maxXy = h0->maxXy;
  minXy = h1->maxXy;
  v00 = 0;
  v10 = 0;
  sign = 1;
  for ( side = 0; side <= 1; ++side )
  {
    v17 = maxXy->point.x;
    v18 = sign * (minXy->point.x - v17);
    v42 = v18;
    if ( v18 <= 0 )
    {
      if ( v18 >= 0 )
      {
        y = maxXy->point.y;
        v35 = maxXy;
        while ( 1 )
        {
          v36 = side ? v35->next : v35->prev;
          if ( v36 == maxXy || v36->point.x != v17 || v36->point.y > y )
            break;
          v35 = v36;
          y = v36->point.y;
        }
        v37 = minXy->point.y;
        maxXy = v35;
        v38 = minXy;
        while ( 1 )
        {
          v39 = side ? v38->prev : v38->next;
          if ( v39 == minXy || v39->point.x != v17 || v39->point.y < v37 )
            break;
          v38 = v39;
          v37 = v39->point.y;
        }
        minXy = v38;
      }
      else
      {
        while ( 1 )
        {
          while ( 1 )
          {
            dya = minXy->point.y - maxXy->point.y;
            v27 = side ? minXy->prev : minXy->next;
            if ( v27 == minXy )
              break;
            v28 = sign * (v27->point.x - minXy->point.x);
            v29 = v27->point.y - minXy->point.y;
            if ( v29 < 0 || v28 && (v28 >= 0 || v42 * v29 > dya * v28) )
              break;
            minXy = v27;
            v42 = sign * (v27->point.x - maxXy->point.x);
          }
          v30 = side ? maxXy->prev : maxXy->next;
          if ( v30 == maxXy )
            break;
          v31 = v30->point.x;
          v32 = v30->point.y - maxXy->point.y;
          v33 = sign * (v31 - maxXy->point.x);
          if ( sign * (minXy->point.x - v31) >= 0 || v32 <= 0 || v33 && (v33 >= 0 || v42 * v32 >= dya * v33) )
            break;
          maxXy = v30;
          v42 = sign * (minXy->point.x - v31);
        }
      }
    }
    else
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v19 = maxXy->point.y;
          dy = minXy->point.y - v19;
          v20 = side ? maxXy->next : maxXy->prev;
          if ( v20 == maxXy )
            break;
          v21 = sign * (v20->point.x - maxXy->point.x);
          if ( v20->point.y - v19 > 0 || v21 && (v21 >= 0 || v42 * (v20->point.y - v19) > dy * v21) )
            break;
          maxXy = v20;
          v42 = sign * (minXy->point.x - v20->point.x);
        }
        v22 = side ? minXy->next : minXy->prev;
        if ( v22 == minXy )
          break;
        v23 = v22->point.y - minXy->point.y;
        v24 = v22->point.x;
        v25 = sign * (v24 - maxXy->point.x);
        v26 = sign * (v24 - minXy->point.x);
        if ( v25 <= 0 || v23 >= 0 || v26 && (v26 >= 0 || v42 * v23 >= dy * v26) )
          break;
        minXy = v22;
        v42 = v25;
      }
    }
    if ( !side )
    {
      v00 = maxXy;
      maxXy = h0->minXy;
      v10 = minXy;
      minXy = h1->minXy;
      sign = -1;
    }
  }
  maxXy->prev = minXy;
  minXy->next = maxXy;
  v00->next = v10;
  v10->prev = v00;
  if ( h1->minXy->point.x < h0->minXy->point.x )
    h0->minXy = h1->minXy;
  v40 = h1->maxXy;
  if ( v40->point.x >= h0->maxXy->point.x )
    h0->maxXy = v40;
  h0->maxYx = h1->maxYx;
  *c0 = v00;
  *c1 = v10;
  return 1;
}
