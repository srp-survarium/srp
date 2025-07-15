void __userpurge btGImpactCollisionAlgorithm::gimpact_vs_gimpact_find_pairs(
        btGImpactShapeInterface *shape0@<edi>,
        const btTransform *this,
        const btTransform *trans0,
        const btTransform *trans1,
        btPairSet *shape1,
        btPairSet *pairset)
{
  int v6; // esi
  btPairSet *v7; // ecx
  int v8; // [esp+20h] [ebp-48h]
  int v9; // [esp+24h] [ebp-44h]
  float v10[4]; // [esp+28h] [ebp-40h] BYREF
  float v11[4]; // [esp+38h] [ebp-30h] BYREF
  float v12[4]; // [esp+48h] [ebp-20h] BYREF
  float v13[4]; // [esp+58h] [ebp-10h] BYREF

  if ( shape0->m_box_set.m_box_tree.m_num_nodes && trans1[1].m_basis.m_el[1].mVec128.m128_i32[0] )
  {
    btGImpactQuantizedBvh::find_collision(
      trans0,
      (const btTransform *)((char *)trans1 + 80),
      &shape0->m_box_set,
      this,
      (btGImpactQuantizedBvh *)&trans1[1].m_basis.m_el[1],
      shape1);
  }
  else
  {
    v6 = shape0->getNumChildShapes(shape0);
    while ( v6 )
    {
      v9 = --v6;
      shape0->getChildAabb(shape0, v6, this, (btVector3 *)v10, (btVector3 *)v11);
      v8 = (*(int (__thiscall **)(const btTransform *))(trans1->m_basis.m_el[0].mVec128.m128_i32[0] + 80))(trans1);
      while ( v8 )
      {
        --v8;
        (*(void (__thiscall **)(const btTransform *, int, const btTransform *, float *, float *))(trans1->m_basis.m_el[0].mVec128.m128_i32[0]
                                                                                                + 112))(
          trans1,
          v6,
          trans0,
          v12,
          v13);
        if ( v12[0] <= v11[0]
          && v10[0] <= v13[0]
          && v12[1] <= v11[1]
          && v10[1] <= v13[1]
          && v12[2] <= v11[2]
          && v10[2] <= v13[2] )
        {
          btPairSet::push_pair(v7, (int)shape1, v6, v8);
          v6 = v9;
        }
      }
    }
  }
}
