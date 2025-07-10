void __thiscall vostok::collision::triangle_mesh_geometry::render(
        vostok::collision::triangle_mesh_geometry *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::render::debug::renderer *renderer,
        const vostok::math::float4x4 *matrix)
{
  Opcode::MeshInterface *m_mesh; // eax
  const IceMaths::IndexedTriangle *mTris; // ecx
  const IceMaths::Point *mVerts; // ebx
  unsigned int *v7; // edi
  float x; // xmm3_4
  float v9; // xmm0_4
  float z; // xmm6_4
  float y; // xmm5_4
  float v12; // xmm2_4
  float *p_x; // eax
  float v14; // xmm1_4
  float v15; // xmm7_4
  float v16; // xmm2_4
  float v17; // xmm7_4
  float v18; // xmm5_4
  int v19; // eax
  float v20; // xmm5_4
  float v21; // xmm6_4
  float *v22; // eax
  float v23; // xmm5_4
  float v24; // xmm6_4
  float *v25; // eax
  float v26; // xmm7_4
  float v27; // xmm5_4
  float v28; // xmm6_4
  float v29; // xmm1_4
  bool v30; // [esp+0h] [ebp-80h]
  float v31; // [esp+Ch] [ebp-74h]
  float v32; // [esp+10h] [ebp-70h]
  float v33; // [esp+14h] [ebp-6Ch]
  float v34; // [esp+18h] [ebp-68h]
  const IceMaths::IndexedTriangle *e; // [esp+1Ch] [ebp-64h]
  float v36; // [esp+24h] [ebp-5Ch]
  float v37; // [esp+28h] [ebp-58h]
  __int64 positions; // [esp+2Ch] [ebp-54h]
  float positions_8; // [esp+34h] [ebp-4Ch]
  __int64 positions_12; // [esp+38h] [ebp-48h]
  float positions_20; // [esp+40h] [ebp-40h]
  __int64 positions_24; // [esp+44h] [ebp-3Ch]
  vostok::render::vertex_colored draw_vertices[3]; // [esp+50h] [ebp-30h] BYREF

  m_mesh = this->m_mesh;
  mTris = m_mesh->mTris;
  mVerts = m_mesh->mVerts;
  e = &mTris[m_mesh->mNbTris];
  if ( mTris != e )
  {
    v7 = &mTris->mVRef[2];
    do
    {
      x = matrix->j.x;
      v9 = matrix->k.x;
      z = mVerts[*(v7 - 2)].z;
      y = mVerts[*(v7 - 2)].y;
      v12 = mVerts[*(v7 - 2)].x;
      p_x = &mVerts[*(v7 - 2)].x;
      *(float *)&positions = (float)((float)((float)(x * y) + (float)(v9 * z)) + (float)(matrix->i.x * v12))
                           + matrix->c.x;
      v32 = matrix->i.y;
      v31 = matrix->j.y;
      v14 = matrix->k.y;
      v15 = (float)((float)(v31 * y) + (float)(v14 * z)) + (float)(v32 * v12);
      v16 = matrix->k.z;
      *((float *)&positions + 1) = v15 + matrix->c.y;
      v33 = matrix->i.z;
      v34 = matrix->j.z;
      v17 = (float)(v34 * p_x[1]) + (float)(v16 * z);
      v18 = *p_x;
      v19 = *(v7 - 1);
      positions_8 = (float)(v17 + (float)(v33 * v18)) + matrix->c.z;
      v20 = mVerts[v19].y;
      v21 = mVerts[v19].z;
      v22 = &mVerts[v19].x;
      *(float *)&positions_12 = (float)((float)((float)(x * v20) + (float)(v9 * v21)) + (float)(matrix->i.x * *v22))
                              + matrix->c.x;
      *((float *)&positions_12 + 1) = (float)((float)((float)(v31 * v22[1]) + (float)(v14 * v22[2]))
                                            + (float)(v32 * *v22))
                                    + matrix->c.y;
      v23 = *v22;
      v24 = (float)(v34 * v22[1]) + (float)(v16 * v22[2]);
      v25 = &mVerts[*v7].x;
      v26 = v33 * v23;
      v27 = matrix->c.z;
      v36 = v25[1];
      v37 = v25[2];
      positions_20 = (float)(v24 + v26) + v27;
      v28 = *v25;
      *(float *)&positions_24 = (float)((float)((float)(v9 * v37) + (float)(x * v36)) + (float)(matrix->i.x * *v25))
                              + matrix->c.x;
      v29 = (float)((float)((float)(v14 * v37) + (float)(v31 * v36)) + (float)(v32 * *v25)) + matrix->c.y;
      draw_vertices[1].position.z = positions_20;
      draw_vertices[0].color.m_value = 2130738944;
      draw_vertices[1].color.m_value = 2130738944;
      draw_vertices[2].color.m_value = 2130738944;
      *(_QWORD *)&draw_vertices[0].position.x = positions;
      draw_vertices[0].position.z = positions_8;
      *((float *)&positions_24 + 1) = v29;
      *(_QWORD *)&draw_vertices[1].position.x = positions_12;
      *(_QWORD *)&draw_vertices[2].position.x = positions_24;
      draw_vertices[2].position.z = (float)((float)((float)(v16 * v37) + (float)(v34 * v36)) + (float)(v33 * v28)) + v27;
      vostok::render::debug::renderer::draw_triangle(
        (vostok::render::debug::renderer *)LODWORD(draw_vertices[2].position.z),
        scene,
        (const vostok::render::vertex_colored (*)[3])draw_vertices,
        v30);
      v7 += 3;
    }
    while ( v7 - 2 != (unsigned int *)e );
  }
}
