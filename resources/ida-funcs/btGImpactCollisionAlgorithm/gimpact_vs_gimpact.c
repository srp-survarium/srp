void __thiscall btGImpactCollisionAlgorithm::gimpact_vs_gimpact(
        btGImpactCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        btGImpactMeshShapePart *shape0,
        btGImpactShapeInterface *shape1)
{
  btStridingMeshInterface *m_meshInterface; // eax
  btPairSet *v7; // ecx
  void *m_userPointer; // eax
  btGImpactMeshShapePart *v9; // esi
  btAlignedObjectArray<GrahamVector2> *v10; // ecx
  btGImpactCollisionAlgorithm *v11; // ecx
  GIM_ShapeRetriever *v12; // ecx
  GIM_ShapeRetriever *v13; // ecx
  GIM_PAIR *v14; // eax
  int m_index1; // ecx
  btCollisionShape *v16; // eax
  GIM_ShapeRetriever::ChildShapeRetriever_vtbl *v17; // edx
  float *v18; // eax
  float v19; // xmm2_4
  float v20; // xmm5_4
  float v21; // xmm7_4
  float v22; // xmm5_4
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm6_4
  float v26; // xmm5_4
  float v27; // xmm2_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  float v30; // xmm6_4
  float v31; // xmm5_4
  float v32; // xmm6_4
  float v33; // xmm5_4
  float *v34; // eax
  float v35; // xmm6_4
  float v36; // xmm2_4
  unsigned int v37; // xmm5_4
  float v38; // xmm6_4
  float v39; // xmm5_4
  float v40; // xmm7_4
  float v41; // xmm6_4
  float v42; // xmm7_4
  float v43; // xmm6_4
  float v44; // xmm5_4
  float v45; // xmm2_4
  float v46; // xmm5_4
  float v47; // xmm6_4
  float v48; // xmm6_4
  float v49; // xmm5_4
  float v50; // xmm6_4
  float v51; // xmm5_4
  GIM_ShapeRetriever *v52; // ecx
  GIM_ShapeRetriever *v53; // ecx
  btPairSet *v54; // [esp+Ah] [ebp-520h]
  const float *v55; // [esp+Ah] [ebp-520h]
  bool v56; // [esp+18h] [ebp-512h]
  bool v57; // [esp+19h] [ebp-511h]
  int i; // [esp+1Ah] [ebp-510h]
  float v59; // [esp+1Eh] [ebp-50Ch]
  float v60; // [esp+22h] [ebp-508h]
  float v61; // [esp+26h] [ebp-504h]
  float v62; // [esp+2Ah] [ebp-500h]
  float v63; // [esp+2Eh] [ebp-4FCh]
  float v64; // [esp+32h] [ebp-4F8h]
  float v65; // [esp+36h] [ebp-4F4h]
  float v66; // [esp+3Ah] [ebp-4F0h]
  float v67; // [esp+3Eh] [ebp-4ECh]
  float v68; // [esp+4Ah] [ebp-4E0h] BYREF
  float v69; // [esp+4Eh] [ebp-4DCh]
  float v70; // [esp+52h] [ebp-4D8h] BYREF
  float v71; // [esp+56h] [ebp-4D4h]
  float v72; // [esp+5Ah] [ebp-4D0h] BYREF
  float v73; // [esp+5Eh] [ebp-4CCh] BYREF
  float v74; // [esp+62h] [ebp-4C8h] BYREF
  float v75; // [esp+66h] [ebp-4C4h] BYREF
  float v76; // [esp+6Ah] [ebp-4C0h] BYREF
  float v77; // [esp+6Eh] [ebp-4BCh] BYREF
  float v78; // [esp+72h] [ebp-4B8h] BYREF
  float v79; // [esp+76h] [ebp-4B4h] BYREF
  float v80; // [esp+7Ah] [ebp-4B0h] BYREF
  btMatrix3x3 v81; // [esp+7Eh] [ebp-4ACh] BYREF
  float v82; // [esp+AEh] [ebp-47Ch]
  float v83[2]; // [esp+B2h] [ebp-478h] BYREF
  float v84; // [esp+BAh] [ebp-470h]
  float v85; // [esp+BEh] [ebp-46Ch] BYREF
  btPairSet v86; // [esp+C2h] [ebp-468h] BYREF
  float v87; // [esp+D6h] [ebp-454h] BYREF
  btCollisionObject v88; // [esp+DAh] [ebp-450h] BYREF
  btTransform v89; // [esp+1EAh] [ebp-340h] BYREF
  GIM_ShapeRetriever v90; // [esp+22Ah] [ebp-300h] BYREF
  GIM_ShapeRetriever v91; // [esp+3AAh] [ebp-180h] BYREF

  if ( shape0->getGImpactShapeType(shape0) == CONST_GIMPACT_TRIMESH_SHAPE )
  {
    m_meshInterface = shape0->m_primitive_manager.m_meshInterface;
    for ( this->m_part0 = (int)m_meshInterface;
          this->m_part0;
          btGImpactCollisionAlgorithm::gimpact_vs_gimpact(
            this,
            body0,
            body1,
            *(btGImpactMeshShapePart **)(shape0->m_primitive_manager.m_scale.mVec128.m128_i32[0] + 4 * this->m_part0),
            shape1) )
    {
      --this->m_part0;
    }
    --this->m_part0;
  }
  else if ( shape1->getGImpactShapeType(shape1) == CONST_GIMPACT_TRIMESH_SHAPE )
  {
    m_userPointer = shape1[1].m_userPointer;
    for ( this->m_part1 = (int)m_userPointer;
          this->m_part1;
          btGImpactCollisionAlgorithm::gimpact_vs_gimpact(
            this,
            body0,
            body1,
            shape0,
            *(btGImpactShapeInterface **)(shape1[1].m_localAABB.m_min.mVec128.m128_i32[0] + 4 * this->m_part1)) )
    {
      --this->m_part1;
    }
    --this->m_part1;
  }
  else
  {
    v88.m_worldTransform.m_origin = body0->m_worldTransform.m_basis.m_el[0];
    v88.m_interpolationWorldTransform.m_basis.m_el[0] = body0->m_worldTransform.m_basis.m_el[1];
    v88.m_interpolationWorldTransform.m_basis.m_el[1] = body0->m_worldTransform.m_basis.m_el[2];
    v88.m_interpolationWorldTransform.m_basis.m_el[2] = body0->m_worldTransform.m_origin;
    *(_QWORD *)&v88.__vftable = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
    *((_QWORD *)&v88.__vftable + 1) = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
    v88.m_worldTransform.m_basis.m_el[0] = body1->m_worldTransform.m_basis.m_el[1];
    v88.m_worldTransform.m_basis.m_el[1] = body1->m_worldTransform.m_basis.m_el[2];
    v88.m_worldTransform.m_basis.m_el[2] = body1->m_worldTransform.m_origin;
    btPairSet::btPairSet(v7, &v86);
    v9 = shape0;
    btGImpactCollisionAlgorithm::gimpact_vs_gimpact_find_pairs(
      shape0,
      (const btTransform *)&v88.m_worldTransform.m_origin,
      (const btTransform *)&v88,
      (const btTransform *)shape1,
      &v86,
      v54);
    if ( v86.m_size )
    {
      if ( shape0->getGImpactShapeType(shape0) == CONST_GIMPACT_TRIMESH_SHAPE_PART
        && shape1->getGImpactShapeType(shape1) == CONST_GIMPACT_TRIMESH_SHAPE_PART )
      {
        btGImpactCollisionAlgorithm::collide_sat_triangles(
          v11,
          (btCollisionObject *)this,
          body0,
          body1,
          shape0,
          (btVector3 *)shape1,
          &v86.m_data->m_index1,
          v86.m_size);
      }
      else
      {
        shape0->lockChildShapes(shape0);
        shape1->lockChildShapes(shape1);
        GIM_ShapeRetriever::GIM_ShapeRetriever(v12, &v91, shape0);
        GIM_ShapeRetriever::GIM_ShapeRetriever(v13, &v90, shape1);
        v57 = shape0->childrenHasTransform(shape0);
        v56 = shape1->childrenHasTransform(shape1);
        for ( i = v86.m_size; i; v9 = shape0 )
        {
          v14 = &v86.m_data[--i];
          m_index1 = v14->m_index1;
          this->m_triface0 = v14->m_index1;
          this->m_triface1 = v14->m_index2;
          v16 = v91.m_current_retriever->getChildShape(v91.m_current_retriever, m_index1);
          v17 = v90.m_current_retriever->__vftable;
          v81.m_el[1].mVec128.m128_i32[3] = (int)v16;
          v81.m_el[1].mVec128.m128_i32[1] = (int)v17->getChildShape(v90.m_current_retriever, this->m_triface1);
          if ( v57 )
          {
            v18 = (float *)v9->getChildTransform(v9, &v89, this->m_triface0);
            v19 = v18[13];
            v20 = v18[14];
            v84 = v18[12];
            v88.m_interpolationWorldTransform.m_origin.mVec128.m128_f32[0] = (float)((float)((float)(v88.m_worldTransform.m_origin.mVec128.m128_f32[0] * v84)
                                                                                           + (float)(v88.m_worldTransform.m_origin.mVec128.m128_f32[1] * v19))
                                                                                   + (float)(v88.m_worldTransform.m_origin.mVec128.m128_f32[2]
                                                                                           * v20))
                                                                           + v88.m_interpolationWorldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
            v88.m_interpolationWorldTransform.m_origin.mVec128.m128_f32[1] = (float)((float)((float)(v88.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v84)
                                                                                           + (float)(v88.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v19))
                                                                                   + (float)(v88.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[2]
                                                                                           * v20))
                                                                           + v88.m_interpolationWorldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
            v88.m_interpolationWorldTransform.m_origin.mVec128.m128_i32[3] = 0;
            v21 = v88.m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v18[10];
            v88.m_interpolationWorldTransform.m_origin.mVec128.m128_f32[2] = (float)((float)((float)(v88.m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v20)
                                                                                           + (float)(v88.m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v84))
                                                                                   + (float)(v88.m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[1]
                                                                                           * v19))
                                                                           + v88.m_interpolationWorldTransform.m_basis.m_el[2].mVec128.m128_f32[2];
            v22 = v18[5];
            v23 = v18[1];
            v73 = (float)(v21 + (float)(v88.m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v18[2]))
                + (float)(v88.m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v18[6]);
            v24 = (float)((float)(v88.m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v23)
                        + (float)(v88.m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v22))
                + (float)(v88.m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v18[9]);
            v25 = v18[8];
            v65 = v18[9];
            v26 = *v18;
            v87 = v24;
            v61 = v26;
            v63 = v25;
            v59 = v18[4];
            v27 = (float)((float)(v88.m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v26)
                        + (float)(v88.m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v59))
                + (float)(v88.m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v25);
            v28 = v18[6];
            v75 = v27;
            v29 = v88.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v18[2];
            v82 = v18[2];
            v69 = v28;
            v30 = (float)(v29 + (float)(v88.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v28))
                + (float)(v88.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v18[10]);
            v81.m_el[2].mVec128.m128_f32[0] = v18[10];
            v31 = v18[1];
            v81.m_el[2].mVec128.m128_f32[3] = v30;
            v32 = v88.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v31;
            v71 = v31;
            v33 = v18[5];
            v85 = (float)((float)(v88.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v61)
                        + (float)(v88.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v59))
                + (float)(v88.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v63);
            v79 = (float)((float)(v88.m_worldTransform.m_origin.mVec128.m128_f32[0] * v82)
                        + (float)(v88.m_worldTransform.m_origin.mVec128.m128_f32[1] * v69))
                + (float)(v88.m_worldTransform.m_origin.mVec128.m128_f32[2] * v81.m_el[2].mVec128.m128_f32[0]);
            v83[1] = v33;
            v77 = (float)(v32 + (float)(v88.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v33))
                + (float)(v88.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v65);
            v83[0] = (float)((float)(v88.m_worldTransform.m_origin.mVec128.m128_f32[0] * v71)
                           + (float)(v88.m_worldTransform.m_origin.mVec128.m128_f32[1] * v33))
                   + (float)(v88.m_worldTransform.m_origin.mVec128.m128_f32[2] * v65);
            v81.m_el[0].mVec128.m128_f32[0] = (float)((float)(v88.m_worldTransform.m_origin.mVec128.m128_f32[0] * v61)
                                                    + (float)(v88.m_worldTransform.m_origin.mVec128.m128_f32[1] * v59))
                                            + (float)(v88.m_worldTransform.m_origin.mVec128.m128_f32[2] * v63);
            btMatrix3x3::setValue(
              &v81,
              (int)&v88.m_interpolationAngularVelocity,
              v83,
              &v79,
              &v85,
              &v77,
              &v81.m_el[2].mVec128.m128_f32[3],
              &v75,
              &v87,
              &v73,
              v55);
            *(btVector3 *)&v88.m_extensionPointer = v88.m_interpolationAngularVelocity;
            *(btVector3 *)&v88.m_companionId = v88.m_anisotropicFriction;
            LODWORD(v88.m_restitution) = v88.m_hasAnisotropicFriction;
            v88.m_internalType = LODWORD(v88.m_contactProcessingThreshold);
            v88.m_userObjectPointer = v88.m_broadphaseHandle;
            LODWORD(v88.m_hitFraction) = v88.m_collisionShape;
            *(btVector3 *)&v88.m_ccdSweptSphereRadius = v88.m_interpolationWorldTransform.m_origin;
            btCollisionObject::setWorldTransform((btCollisionObject *)&v88.m_extensionPointer, (btVector3 *)body0);
          }
          if ( v56 )
          {
            v34 = (float *)shape1->getChildTransform(shape1, &v89, this->m_triface1);
            v35 = v34[13];
            v36 = v34[14];
            v67 = v34[12];
            v88.m_interpolationLinearVelocity.mVec128.m128_f32[0] = (float)((float)((float)(*(float *)&v88.__vftable
                                                                                          * v67)
                                                                                  + (float)(*((float *)&v88.__vftable + 1)
                                                                                          * v35))
                                                                          + (float)(*((float *)&v88.__vftable + 2) * v36))
                                                                  + v88.m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
            v88.m_interpolationLinearVelocity.mVec128.m128_f32[1] = (float)((float)((float)(v88.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0]
                                                                                          * v67)
                                                                                  + (float)(v88.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]
                                                                                          * v35))
                                                                          + (float)(v88.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]
                                                                                  * v36))
                                                                  + v88.m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
            v81.m_el[0].mVec128.m128_f32[2] = v36;
            *(float *)&v37 = (float)((float)((float)(v88.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v67)
                                           + (float)(v88.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v35))
                                   + (float)(v88.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v36))
                           + v88.m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2];
            v38 = v34[2];
            v88.m_interpolationLinearVelocity.mVec128.m128_u64[1] = v37;
            v39 = v34[5];
            v40 = (float)((float)(v88.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v38)
                        + (float)(v88.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v34[6]))
                + (float)(v88.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v34[10]);
            v41 = v34[1];
            v68 = v40;
            v42 = (float)((float)(v88.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v41)
                        + (float)(v88.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v39))
                + (float)(v88.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v34[9]);
            v43 = v34[8];
            v60 = v34[9];
            v44 = *v34;
            v70 = v42;
            v62 = v44;
            v66 = v43;
            v64 = v34[4];
            v45 = (float)((float)(v88.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v44)
                        + (float)(v88.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v64))
                + (float)(v88.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v43);
            v46 = v34[6];
            v72 = v45;
            v47 = v88.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v34[2];
            v81.m_el[2].mVec128.m128_f32[1] = v34[2];
            v81.m_el[1].mVec128.m128_f32[0] = v46;
            v48 = (float)(v47 + (float)(v88.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v46))
                + (float)(v88.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v34[10]);
            v81.m_el[2].mVec128.m128_f32[2] = v34[10];
            v49 = v34[1];
            v74 = v48;
            v50 = v88.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v49;
            v81.m_el[1].mVec128.m128_f32[2] = v49;
            v51 = v34[5];
            v78 = (float)((float)(v88.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v62)
                        + (float)(v88.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v64))
                + (float)(v88.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v66);
            v80 = (float)((float)(*(float *)&v88.__vftable * v81.m_el[2].mVec128.m128_f32[1])
                        + (float)(*((float *)&v88.__vftable + 1) * v81.m_el[1].mVec128.m128_f32[0]))
                + (float)(*((float *)&v88.__vftable + 2) * v81.m_el[2].mVec128.m128_f32[2]);
            v76 = (float)(v50 + (float)(v88.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v51))
                + (float)(v88.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v60);
            v81.m_el[0].mVec128.m128_f32[1] = (float)((float)(*(float *)&v88.__vftable * v81.m_el[1].mVec128.m128_f32[2])
                                                    + (float)(*((float *)&v88.__vftable + 1) * v51))
                                            + (float)(*((float *)&v88.__vftable + 2) * v60);
            v81.m_el[0].mVec128.m128_f32[3] = (float)((float)(*(float *)&v88.__vftable * v62)
                                                    + (float)(*((float *)&v88.__vftable + 1) * v64))
                                            + (float)(*((float *)&v88.__vftable + 2) * v66);
            btMatrix3x3::setValue(
              (btMatrix3x3 *)&v81.m_el[0].m_floats[3],
              (int)&v88.m_interpolationAngularVelocity,
              &v81.m_el[0].mVec128.m128_f32[1],
              &v80,
              &v78,
              &v76,
              &v74,
              &v72,
              &v70,
              &v68,
              v55);
            *(btVector3 *)&v88.m_extensionPointer = v88.m_interpolationAngularVelocity;
            *(btVector3 *)&v88.m_companionId = v88.m_anisotropicFriction;
            LODWORD(v88.m_restitution) = v88.m_hasAnisotropicFriction;
            v88.m_internalType = LODWORD(v88.m_contactProcessingThreshold);
            v88.m_userObjectPointer = v88.m_broadphaseHandle;
            LODWORD(v88.m_hitFraction) = v88.m_collisionShape;
            *(btVector3 *)&v88.m_ccdSweptSphereRadius = v88.m_interpolationLinearVelocity;
            btCollisionObject::setWorldTransform((btCollisionObject *)&v88.m_extensionPointer, (btVector3 *)body1);
          }
          btGImpactCollisionAlgorithm::convex_vs_convex_collision(
            this,
            body1,
            body0,
            (btCollisionShape *)v81.m_el[1].mVec128.m128_i32[3],
            (btCollisionShape *)v81.m_el[1].mVec128.m128_i32[1]);
          if ( v57 )
            btCollisionObject::setWorldTransform(
              (btCollisionObject *)&v88.m_worldTransform.m_origin,
              (btVector3 *)body0);
          if ( v56 )
            btCollisionObject::setWorldTransform(&v88, (btVector3 *)body1);
        }
        v9->unlockChildShapes(v9);
        shape1->unlockChildShapes(shape1);
        GIM_ShapeRetriever::~GIM_ShapeRetriever(v52, (int)&v90);
        GIM_ShapeRetriever::~GIM_ShapeRetriever(v53, (int)&v91);
      }
    }
    btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v10, (int)&v86);
  }
}
