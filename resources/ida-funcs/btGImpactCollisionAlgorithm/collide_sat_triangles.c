void __userpurge btGImpactCollisionAlgorithm::collide_sat_triangles(
        btGImpactCollisionAlgorithm *this@<ecx>,
        int a2@<edi>,
        btCollisionObject *body0,
        btCollisionObject *body1,
        btGImpactMeshShapePart *shape0,
        btGImpactMeshShapePart *shape1,
        int *pairs,
        int pair_count)
{
  void (__thiscall *lockChildShapes)(struct btGImpactMeshShapePart *); // edx
  btGImpactMeshShapePart *v9; // esi
  int v11; // eax
  const btPrimitiveManagerBase *v12; // eax
  int v13; // eax
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm4_4
  float v24; // xmm1_4
  int m_point_count; // esi
  btVector3 *v26; // ebx
  int v27; // [esp+AA0h] [ebp-278h]
  int v28; // [esp+AA0h] [ebp-278h]
  float v29; // [esp+AA0h] [ebp-278h]
  float v30; // [esp+AA0h] [ebp-278h]
  float v31; // [esp+AA4h] [ebp-274h]
  unsigned __int64 v32; // [esp+AA8h] [ebp-270h]
  float v33; // [esp+AB0h] [ebp-268h]
  float v34; // [esp+ABCh] [ebp-25Ch]
  float v35; // [esp+AC0h] [ebp-258h]
  float v36; // [esp+AC0h] [ebp-258h]
  const int *v37; // [esp+AD0h] [ebp-248h]
  float v38; // [esp+AD4h] [ebp-244h]
  btPrimitiveTriangle v39; // [esp+AD8h] [ebp-240h] BYREF
  btPrimitiveTriangle other; // [esp+B28h] [ebp-1F0h] BYREF
  btTransform v41; // [esp+B78h] [ebp-1A0h] BYREF
  btTransform t; // [esp+BB8h] [ebp-160h] BYREF
  GIM_TRIANGLE_CONTACT contacts; // [esp+BF8h] [ebp-120h] BYREF

  t = body0->m_worldTransform;
  v41.m_basis.m_el[0].mVec128.m128_u64[0] = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
  v41.m_basis.m_el[0].mVec128.m128_u64[1] = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
  v41.m_basis.m_el[1] = body1->m_worldTransform.m_basis.m_el[1];
  v41.m_basis.m_el[2] = body1->m_worldTransform.m_basis.m_el[2];
  v41.m_origin.mVec128.m128_u64[0] = body1->m_worldTransform.m_origin.mVec128.m128_u64[0];
  lockChildShapes = shape0->lockChildShapes;
  v41.m_origin.mVec128.m128_u64[1] = body1->m_worldTransform.m_origin.mVec128.m128_u64[1];
  v39.m_margin = 0.0099999998;
  other.m_margin = 0.0099999998;
  lockChildShapes(shape0);
  v9 = shape1;
  shape1->lockChildShapes(shape1);
  while ( pair_count )
  {
    v11 = *pairs;
    --pair_count;
    *(_DWORD *)(a2 + 24) = *pairs;
    *(_DWORD *)(a2 + 32) = pairs[1];
    v27 = v11;
    pairs += 2;
    v37 = pairs;
    v12 = shape0->getPrimitiveManager(shape0);
    v12->get_primitive_triangle((btPrimitiveManagerBase *)v12, v27, &v39);
    v28 = *(_DWORD *)(a2 + 32);
    v13 = (int)v9->getPrimitiveManager(v9);
    (*(void (__thiscall **)(int, int, btPrimitiveTriangle *))(*(_DWORD *)v13 + 16))(v13, v28, &other);
    btPrimitiveTriangle::applyTransform(&v39, &t);
    btPrimitiveTriangle::applyTransform(&other, &v41);
    v14 = (float)((float)(v39.m_vertices[1].mVec128.m128_f32[1] - v39.m_vertices[0].mVec128.m128_f32[1])
                * (float)(v39.m_vertices[2].mVec128.m128_f32[2] - v39.m_vertices[0].mVec128.m128_f32[2]))
        - (float)((float)(v39.m_vertices[1].mVec128.m128_f32[2] - v39.m_vertices[0].mVec128.m128_f32[2])
                * (float)(v39.m_vertices[2].mVec128.m128_f32[1] - v39.m_vertices[0].mVec128.m128_f32[1]));
    v15 = (float)((float)(v39.m_vertices[1].mVec128.m128_f32[2] - v39.m_vertices[0].mVec128.m128_f32[2])
                * (float)(v39.m_vertices[2].mVec128.m128_f32[0] - v39.m_vertices[0].mVec128.m128_f32[0]))
        - (float)((float)(v39.m_vertices[2].mVec128.m128_f32[2] - v39.m_vertices[0].mVec128.m128_f32[2])
                * (float)(v39.m_vertices[1].mVec128.m128_f32[0] - v39.m_vertices[0].mVec128.m128_f32[0]));
    v16 = (float)((float)(v39.m_vertices[2].mVec128.m128_f32[1] - v39.m_vertices[0].mVec128.m128_f32[1])
                * (float)(v39.m_vertices[1].mVec128.m128_f32[0] - v39.m_vertices[0].mVec128.m128_f32[0]))
        - (float)((float)(v39.m_vertices[1].mVec128.m128_f32[1] - v39.m_vertices[0].mVec128.m128_f32[1])
                * (float)(v39.m_vertices[2].mVec128.m128_f32[0] - v39.m_vertices[0].mVec128.m128_f32[0]));
    v29 = 1.0 / sqrtf((float)((float)(v14 * v14) + (float)(v16 * v16)) + (float)(v15 * v15));
    *(float *)&v32 = v14 * v29;
    *((float *)&v32 + 1) = v15 * v29;
    v33 = v16 * v29;
    v31 = (float)((float)((float)(v14 * v29) * v39.m_vertices[0].mVec128.m128_f32[0])
                + (float)((float)(v15 * v29) * v39.m_vertices[0].mVec128.m128_f32[1]))
        + (float)((float)(v16 * v29) * v39.m_vertices[0].mVec128.m128_f32[2]);
    v39.m_plane.mVec128.m128_u64[0] = v32;
    v39.m_plane.mVec128.m128_f32[2] = v16 * v29;
    v39.m_plane.mVec128.m128_f32[3] = v31;
    v17 = (float)((float)(other.m_vertices[1].mVec128.m128_f32[1] - other.m_vertices[0].mVec128.m128_f32[1])
                * (float)(other.m_vertices[2].mVec128.m128_f32[2] - other.m_vertices[0].mVec128.m128_f32[2]))
        - (float)((float)(other.m_vertices[1].mVec128.m128_f32[2] - other.m_vertices[0].mVec128.m128_f32[2])
                * (float)(other.m_vertices[2].mVec128.m128_f32[1] - other.m_vertices[0].mVec128.m128_f32[1]));
    v18 = (float)((float)(other.m_vertices[1].mVec128.m128_f32[2] - other.m_vertices[0].mVec128.m128_f32[2])
                * (float)(other.m_vertices[2].mVec128.m128_f32[0] - other.m_vertices[0].mVec128.m128_f32[0]))
        - (float)((float)(other.m_vertices[2].mVec128.m128_f32[2] - other.m_vertices[0].mVec128.m128_f32[2])
                * (float)(other.m_vertices[1].mVec128.m128_f32[0] - other.m_vertices[0].mVec128.m128_f32[0]));
    v19 = (float)((float)(other.m_vertices[2].mVec128.m128_f32[1] - other.m_vertices[0].mVec128.m128_f32[1])
                * (float)(other.m_vertices[1].mVec128.m128_f32[0] - other.m_vertices[0].mVec128.m128_f32[0]))
        - (float)((float)(other.m_vertices[1].mVec128.m128_f32[1] - other.m_vertices[0].mVec128.m128_f32[1])
                * (float)(other.m_vertices[2].mVec128.m128_f32[0] - other.m_vertices[0].mVec128.m128_f32[0]));
    v35 = v19;
    v34 = v18;
    v30 = 1.0 / sqrtf((float)((float)(v17 * v17) + (float)(v19 * v19)) + (float)(v18 * v18));
    v20 = v17 * v30;
    v21 = v18 * v30;
    v22 = (float)(v35 * v30) * other.m_vertices[0].mVec128.m128_f32[2];
    v36 = v35 * v30;
    other.m_plane.mVec128.m128_f32[2] = v36;
    v23 = v39.m_margin + other.m_margin;
    v24 = (float)((float)((float)(v17 * v30) * other.m_vertices[0].mVec128.m128_f32[0])
                + (float)((float)(v18 * v30) * other.m_vertices[0].mVec128.m128_f32[1]))
        + v22;
    other.m_plane.mVec128.m128_f32[0] = v17 * v30;
    other.m_plane.mVec128.m128_f32[1] = v34 * v30;
    other.m_plane.mVec128.m128_f32[3] = v24;
    if ( ((float)((float)((float)((float)((float)(other.m_vertices[0].mVec128.m128_f32[0] * *(float *)&v32)
                                        + (float)(other.m_vertices[0].mVec128.m128_f32[2] * v33))
                                + (float)(other.m_vertices[0].mVec128.m128_f32[1] * *((float *)&v32 + 1)))
                        - v31)
                - (float)(v39.m_margin + other.m_margin)) <= 0.0
       || (float)((float)((float)((float)((float)(other.m_vertices[1].mVec128.m128_f32[0] * *(float *)&v32)
                                        + (float)(other.m_vertices[1].mVec128.m128_f32[2] * v33))
                                + (float)(other.m_vertices[1].mVec128.m128_f32[1] * *((float *)&v32 + 1)))
                        - v31)
                - v23) <= 0.0
       || (float)((float)((float)((float)((float)(other.m_vertices[2].mVec128.m128_f32[0] * *(float *)&v32)
                                        + (float)(other.m_vertices[2].mVec128.m128_f32[2] * v33))
                                + (float)(other.m_vertices[2].mVec128.m128_f32[1] * *((float *)&v32 + 1)))
                        - v31)
                - v23) <= 0.0)
      && ((float)((float)((float)((float)((float)(v20 * v39.m_vertices[0].mVec128.m128_f32[0])
                                        + (float)(v21 * v39.m_vertices[0].mVec128.m128_f32[1]))
                                + (float)(v36 * v39.m_vertices[0].mVec128.m128_f32[2]))
                        - v24)
                - v23) <= 0.0
       || (float)((float)((float)((float)((float)(v39.m_vertices[1].mVec128.m128_f32[0] * v20)
                                        + (float)(v39.m_vertices[1].mVec128.m128_f32[2] * v36))
                                + (float)(v39.m_vertices[1].mVec128.m128_f32[1] * v21))
                        - v24)
                - v23) <= 0.0
       || (float)((float)((float)((float)((float)(v39.m_vertices[2].mVec128.m128_f32[0] * v20)
                                        + (float)(v39.m_vertices[2].mVec128.m128_f32[2] * v36))
                                + (float)(v39.m_vertices[2].mVec128.m128_f32[1] * v21))
                        - v24)
                - v23) <= 0.0) )
    {
      if ( btPrimitiveTriangle::find_triangle_collision_clip_method(&v39, &other, &contacts) )
      {
        m_point_count = contacts.m_point_count;
        if ( contacts.m_point_count )
        {
          v26 = &contacts.m_points[contacts.m_point_count];
          do
          {
            --m_point_count;
            --v26;
            v38 = -contacts.m_penetration_depth;
            (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(a2 + 16) + 4))(
              *(_DWORD *)(a2 + 16),
              *(_DWORD *)(a2 + 28),
              *(_DWORD *)(a2 + 24));
            (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(a2 + 16) + 8))(
              *(_DWORD *)(a2 + 16),
              *(_DWORD *)(a2 + 36),
              *(_DWORD *)(a2 + 32));
            if ( !*(_DWORD *)(a2 + 12) )
              *(_DWORD *)(a2 + 12) = (*(int (__thiscall **)(_DWORD, btCollisionObject *, btCollisionObject *))(**(_DWORD **)(a2 + 4) + 8))(
                                       *(_DWORD *)(a2 + 4),
                                       body0,
                                       body1);
            *(_DWORD *)(*(_DWORD *)(a2 + 16) + 4) = *(_DWORD *)(a2 + 12);
            (*(void (__stdcall **)(btVector4 *, btVector3 *, float))(**(_DWORD **)(a2 + 16) + 12))(
              &contacts.m_separating_normal,
              v26,
              COERCE_FLOAT(LODWORD(v38)));
          }
          while ( m_point_count );
          pairs = (int *)v37;
        }
      }
      v9 = shape1;
    }
  }
  shape0->unlockChildShapes(shape0);
  v9->unlockChildShapes(v9);
}
