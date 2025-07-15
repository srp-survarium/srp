void __thiscall btConvexHullInternal::computeInternal(
        btConvexHullInternal *this,
        int start,
        int end,
        btConvexHullInternal::IntermediateHull *result)
{
  int v5; // eax
  btConvexHullInternal::Vertex **v6; // edx
  btConvexHullInternal::Vertex **p_point; // esi
  btConvexHullInternal::Vertex **v8; // esi
  btConvexHullInternal::Vertex *v9; // edi
  btConvexHullInternal::Vertex *v10; // ebx
  int v11; // edx
  int v12; // esi
  btConvexHullInternal::IntermediateHull *v13; // eax
  btConvexHullInternal::Edge *v14; // eax
  btConvexHullInternal::Edge *reverse; // eax
  btConvexHullInternal::Vertex *v16; // eax
  btConvexHullInternal::IntermediateHull h1; // [esp+Ch] [ebp-18h] BYREF
  btConvexHullInternal *v18; // [esp+1Ch] [ebp-8h]
  int enda; // [esp+30h] [ebp+Ch]

  v18 = this;
  if ( end == start )
  {
    result->minXy = 0;
    result->maxXy = 0;
    result->minYx = 0;
    result->maxYx = 0;
    return;
  }
  if ( end - start == 1 )
    goto LABEL_31;
  if ( end - start == 2 )
  {
    v9 = this->originalVertices.m_data[start];
    v10 = v9 + 1;
    if ( v9->point.x != v9[1].point.x || v9->point.y != v9[1].point.y || v9->point.z != v9[1].point.z )
    {
      v11 = v9->point.x - v9[1].point.x;
      v12 = v9->point.y - v9[1].point.y;
      if ( v9->point.x != v9[1].point.x || v12 )
      {
        v9->next = v10;
        v9->prev = v10;
        v10->next = v9;
        v9[1].prev = v9;
        if ( v11 >= 0 && (v11 || v12 >= 0) )
        {
          v13 = result;
          result->minXy = v10;
          result->maxXy = v9;
        }
        else
        {
          v13 = result;
          result->minXy = v9;
          result->maxXy = v10;
        }
        if ( v12 >= 0 && (v12 || v11 >= 0) )
        {
          v13->minYx = v10;
          v13->maxYx = v9;
LABEL_30:
          v14 = btConvexHullInternal::newEdgePair(
                  (btConvexHullInternal *)start,
                  (btConvexHullInternal::Edge ***)v18,
                  v9,
                  v10);
          v14->next = v14;
          v14->prev = v14;
          v9->edges = v14;
          reverse = v14->reverse;
          reverse->next = reverse;
          reverse->prev = reverse;
          v10->edges = reverse;
          return;
        }
        v13->maxYx = v10;
      }
      else
      {
        if ( v9->point.z > v9[1].point.z )
        {
          v10 = this->originalVertices.m_data[start];
          ++v9;
        }
        v13 = result;
        v9->next = v9;
        v9->prev = v9;
        result->minXy = v9;
        result->maxXy = v9;
        result->maxYx = v9;
      }
      v13->minYx = v9;
      goto LABEL_30;
    }
LABEL_31:
    v16 = this->originalVertices.m_data[start];
    v16->edges = 0;
    v16->next = v16;
    v16->prev = v16;
    result->minXy = v16;
    result->maxXy = v16;
    result->minYx = v16;
    result->maxYx = v16;
    return;
  }
  v5 = start + (end - start) / 2;
  v6 = &this->originalVertices.m_data[v5];
  p_point = (btConvexHullInternal::Vertex **)&(*(v6 - 1))->point;
  h1.minXy = *p_point++;
  h1.maxXy = *p_point++;
  h1.minYx = *p_point;
  h1.maxYx = p_point[1];
  enda = v5;
  if ( v5 < end )
  {
    v8 = v6;
    do
    {
      if ( (btConvexHullInternal::Vertex *)(*v8)->point.x != h1.minXy )
        break;
      if ( (btConvexHullInternal::Vertex *)(*v8)->point.y != h1.maxXy )
        break;
      if ( (btConvexHullInternal::Vertex *)(*v8)->point.z != h1.minYx )
        break;
      ++enda;
      ++v8;
    }
    while ( enda < end );
  }
  btConvexHullInternal::computeInternal(v18, start, v5, result);
  memset(&h1, 0, sizeof(h1));
  btConvexHullInternal::computeInternal(v18, enda, end, &h1);
  btConvexHullInternal::merge((btConvexHullInternal *)result, (btVector3 *)&h1, v18);
}
