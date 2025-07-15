btConvexHullInternal::Edge *__usercall btConvexHullInternal::Pool<btConvexHullInternal::Edge>::newObject@<eax>(
        btConvexHullInternal::Pool<btConvexHullInternal::Edge> *this@<ecx>,
        btConvexHullInternal::Edge ***a2@<edi>)
{
  btConvexHullInternal::Edge *result; // eax
  btConvexHullInternal::Edge **v3; // eax
  btConvexHullInternal::Edge **v4; // esi
  btConvexHullInternal::Edge *v5; // eax
  btConvexHullInternal::Edge *v6; // ecx
  btConvexHullInternal::Edge *v7; // edx
  int i; // esi
  btConvexHullInternal::Edge *v9; // ecx

  result = (btConvexHullInternal::Edge *)a2[2];
  if ( !result )
  {
    v3 = a2[1];
    if ( v3 )
    {
      a2[1] = (btConvexHullInternal::Edge **)v3[2];
    }
    else
    {
      v4 = (btConvexHullInternal::Edge **)btAlignedAllocInternal(0xCu);
      if ( v4 )
      {
        v5 = (btConvexHullInternal::Edge *)a2[3];
        v4[2] = 0;
        v4[1] = v5;
        *v4 = (btConvexHullInternal::Edge *)btAlignedAllocInternal(24 * (_DWORD)v5);
        v3 = v4;
      }
      else
      {
        v3 = 0;
      }
      v3[2] = (btConvexHullInternal::Edge *)*a2;
      *a2 = v3;
    }
    v6 = v3[1];
    v7 = *v3;
    for ( i = 0; i < (int)v6; ++v7 )
    {
      if ( ++i >= (int)v6 )
        v9 = 0;
      else
        v9 = v7 + 1;
      v7->next = v9;
      v6 = v3[1];
    }
    result = *v3;
  }
  a2[2] = &result->next->next;
  return result;
}


btConvexHullInternal::Vertex *__usercall btConvexHullInternal::Pool<btConvexHullInternal::Vertex>::newObject@<eax>(
        btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *this@<ecx>,
        btConvexHullInternal::Vertex ***a2@<edi>)
{
  btConvexHullInternal::Vertex *result; // eax
  btConvexHullInternal::Vertex **v3; // eax
  btConvexHullInternal::Vertex **v4; // esi
  btConvexHullInternal::Vertex *v5; // eax
  btConvexHullInternal::Vertex *v6; // ecx
  btConvexHullInternal::Vertex *v7; // edx
  int i; // esi
  btConvexHullInternal::Vertex *v9; // ecx

  result = (btConvexHullInternal::Vertex *)a2[2];
  if ( !result )
  {
    v3 = a2[1];
    if ( v3 )
    {
      a2[1] = (btConvexHullInternal::Vertex **)v3[2];
    }
    else
    {
      v4 = (btConvexHullInternal::Vertex **)btAlignedAllocInternal(0xCu);
      if ( v4 )
      {
        v5 = (btConvexHullInternal::Vertex *)a2[3];
        v4[1] = v5;
        v4[2] = 0;
        *v4 = (btConvexHullInternal::Vertex *)btAlignedAllocInternal(112 * (_DWORD)v5);
        v3 = v4;
      }
      else
      {
        v3 = 0;
      }
      v3[2] = (btConvexHullInternal::Vertex *)*a2;
      *a2 = v3;
    }
    v6 = v3[1];
    v7 = *v3;
    for ( i = 0; i < (int)v6; ++v7 )
    {
      if ( ++i >= (int)v6 )
        v9 = 0;
      else
        v9 = v7 + 1;
      v7->next = v9;
      v6 = v3[1];
    }
    result = *v3;
  }
  a2[2] = &result->next->next;
  result->copy = -1;
  result->next = 0;
  result->prev = 0;
  result->edges = 0;
  result->firstNearbyFace = 0;
  result->lastNearbyFace = 0;
  return result;
}
