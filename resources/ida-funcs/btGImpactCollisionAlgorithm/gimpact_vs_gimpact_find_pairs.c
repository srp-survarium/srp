void __thiscall btGImpactCollisionAlgorithm::gimpact_vs_gimpact_find_pairs(
        btGImpactCollisionAlgorithm *this,
        const btTransform *trans0,
        const btTransform *trans1,
        btGImpactShapeInterface *shape0,
        btGImpactShapeInterface *shape1,
        btPairSet *pairset)
{
  btGImpactShapeInterface *v6; // esi
  btGImpactShapeInterface *v7; // edi
  int v8; // ebx
  int v9; // edi
  btPairSet *v10; // ecx
  float v11[4]; // [esp+70h] [ebp-40h] BYREF
  float v12[4]; // [esp+80h] [ebp-30h] BYREF
  float v13[4]; // [esp+90h] [ebp-20h] BYREF
  float v14[4]; // [esp+A0h] [ebp-10h] BYREF

  v6 = shape1;
  v7 = shape0;
  if ( shape0->m_box_set.m_box_tree.m_num_nodes && shape1->m_box_set.m_box_tree.m_num_nodes )
  {
    btGImpactQuantizedBvh::find_collision(&shape0->m_box_set, trans0, &shape1->m_box_set, trans1, pairset);
  }
  else
  {
    v8 = shape0->getNumChildShapes(shape0);
    if ( v8 )
    {
      while ( 1 )
      {
        v7->getChildAabb(v7, --v8, trans0, (btVector3 *)v11, (btVector3 *)v12);
        v9 = v6->getNumChildShapes(v6);
        while ( v9 )
        {
          --v9;
          v6->getChildAabb(v6, v8, trans1, (btVector3 *)v13, (btVector3 *)v14);
          if ( v13[0] <= v12[0]
            && v11[0] <= v14[0]
            && v13[1] <= v12[1]
            && v11[1] <= v14[1]
            && v13[2] <= v12[2]
            && v11[2] <= v14[2] )
          {
            btPairSet::push_pair(v10, (int)pairset, v8, v9);
            v6 = shape1;
          }
        }
        if ( !v8 )
          break;
        v7 = shape0;
      }
    }
  }
}
