void __thiscall btConvexHullInternal::computeInternal(
        btConvexHullInternal *this,
        int start,
        int end,
        btConvexHullInternal::IntermediateHull *result)
{
  int v5; // eax
  btConvexHullInternal::Vertex **v6; // edx
  btConvexHullInternal::Point32 *p_point; // ecx
  int i; // edi
  btConvexHullInternal::Vertex *v9; // edi
  btConvexHullInternal::Vertex *v10; // ebx
  btConvexHullInternal *v11; // ecx
  int v12; // edx
  btConvexHullInternal::IntermediateHull *v13; // eax
  btConvexHullInternal::Edge *v14; // eax
  btConvexHullInternal::Edge *reverse; // eax
  btConvexHullInternal::Vertex *v16; // eax
  btConvexHullInternal::Point32 p; // [esp+18h] [ebp-10h] BYREF

  if ( end == start )
  {
    result->minXy = 0;
    result->maxXy = 0;
    result->minYx = 0;
    result->maxYx = 0;
    return;
  }
  if ( end - start == 1 )
    goto LABEL_30;
  if ( end - start == 2 )
  {
    v9 = this->originalVertices.m_data[start];
    v10 = v9 + 1;
    if ( v9->point.x != v9[1].point.x || v9->point.y != v9[1].point.y || v9->point.z != v9[1].point.z )
    {
      v11 = (btConvexHullInternal *)(v9->point.x - v9[1].point.x);
      v12 = v9->point.y - v9[1].point.y;
      if ( v9->point.x != v9[1].point.x || v12 )
      {
        v9->next = v10;
        v9->prev = v10;
        v10->next = v9;
        v9[1].prev = v9;
        if ( (int)v11 >= 0 && (v11 || v12 >= 0) )
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
        if ( v12 >= 0 && (v12 || (int)v11 >= 0) )
        {
          v13->minYx = v10;
          v13->maxYx = v9;
LABEL_29:
          v14 = btConvexHullInternal::newEdgePair(v11, this, v9, v10);
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
      goto LABEL_29;
    }
LABEL_30:
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
  p_point = &(*(v6 - 1))->point;
  p = *p_point;
  for ( i = v5; i < end; ++v6 )
  {
    if ( (*v6)->point.x != p.x )
      break;
    if ( (*v6)->point.y != p.y )
      break;
    if ( (*v6)->point.z != p.z )
      break;
    ++i;
  }
  btConvexHullInternal::computeInternal(this, start, start + (end - start) / 2, result);
  memset(&p, 0, sizeof(p));
  btConvexHullInternal::computeInternal(this, i, end, (btConvexHullInternal::IntermediateHull *)&p);
  btConvexHullInternal::merge((btConvexHullInternal *)result, (btVector3 *)&p, this);
}
