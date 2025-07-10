void __userpurge vostok::math::cuboid::cuboid(
        const vostok::math::aabb *aabb@<ecx>,
        const vostok::math::float4x4 *matrix@<eax>,
        vostok::math::cuboid *this)
{
  float x; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  float v7; // xmm7_4
  float z; // xmm5_4
  float v9; // xmm4_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm5_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm5_4
  float v16; // xmm7_4
  float v17; // xmm6_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm5_4
  float v24; // xmm7_4
  float v25; // xmm5_4
  float v26; // xmm7_4
  float v27; // xmm5_4
  float v28; // xmm6_4
  float v29; // xmm7_4
  float v30; // xmm5_4
  float v31; // xmm7_4
  float v32; // xmm5_4
  float v33; // xmm7_4
  float v34; // xmm6_4
  float v35; // xmm5_4
  float v36; // xmm7_4
  float v37; // xmm6_4
  float v38; // xmm7_4
  float v39; // xmm6_4
  float v40; // xmm5_4
  float v41; // xmm6_4
  float v42; // xmm5_4
  float v43; // xmm7_4
  float v44; // xmm5_4
  float v45; // xmm6_4
  float v46; // xmm5_4
  float v47; // xmm6_4
  float v48; // xmm7_4
  float v49; // xmm3_4
  float v50; // xmm2_4
  vostok::math::cuboid *v51; // esi
  float y; // [esp+Ch] [ebp-7Ch]
  float v53; // [esp+Ch] [ebp-7Ch]
  float v54; // [esp+Ch] [ebp-7Ch]
  float v55; // [esp+Ch] [ebp-7Ch]
  float v56; // [esp+Ch] [ebp-7Ch]
  float v57; // [esp+Ch] [ebp-7Ch]
  float v58; // [esp+10h] [ebp-78h]
  float v59; // [esp+10h] [ebp-78h]
  float v60; // [esp+10h] [ebp-78h]
  float v61; // [esp+10h] [ebp-78h]
  float v62; // [esp+14h] [ebp-74h]
  float v63[2]; // [esp+18h] [ebp-70h] BYREF
  float v64; // [esp+20h] [ebp-68h]
  vostok::math::float3 vertices[8]; // [esp+28h] [ebp-60h] BYREF

  x = matrix->j.x;
  v4 = matrix->i.x;
  v5 = matrix->c.x;
  y = aabb->min.y;
  v6 = matrix->k.x;
  v7 = matrix->i.y * aabb->min.x;
  z = aabb->min.z;
  v9 = matrix->k.y;
  vertices[0].x = (float)((float)((float)(matrix->i.x * aabb->min.x) + (float)(x * y)) + (float)(v6 * z)) + v5;
  v10 = (float)(v7 + (float)(matrix->j.y * y)) + (float)(v9 * z);
  v11 = matrix->j.z;
  v12 = matrix->i.z;
  vertices[0].y = v10 + matrix->c.y;
  v13 = (float)((float)(v12 * aabb->min.x) + (float)(v11 * aabb->min.y)) + (float)(matrix->k.z * aabb->min.z);
  v14 = aabb->min.y;
  v15 = aabb->min.x;
  vertices[0].z = v13 + matrix->c.z;
  v53 = aabb->max.z;
  v58 = v14;
  v16 = (float)((float)(v15 * v4) + (float)(v14 * x)) + (float)(v53 * v6);
  v17 = v15 * matrix->i.y;
  v18 = matrix->j.y;
  vertices[1].x = v16 + v5;
  v19 = (float)((float)(v17 + (float)(v58 * v18)) + (float)(v53 * v9)) + matrix->c.y;
  v20 = matrix->i.z;
  vertices[1].y = v19;
  v21 = aabb->max.y;
  v22 = (float)((float)((float)(v20 * aabb->min.x) + (float)(v58 * matrix->j.z)) + (float)(v53 * matrix->k.z))
      + matrix->c.z;
  v23 = aabb->min.x;
  vertices[1].z = v22;
  v54 = aabb->min.z;
  vertices[2].x = (float)((float)((float)(v23 * v4) + (float)(v21 * x)) + (float)(v54 * v6)) + v5;
  v24 = matrix->j.z;
  vertices[2].y = (float)((float)((float)(v23 * matrix->i.y) + (float)(v21 * matrix->j.y)) + (float)(v54 * v9))
                + matrix->c.y;
  v25 = (float)((float)((float)(v23 * matrix->i.z) + (float)(v21 * v24)) + (float)(v54 * matrix->k.z)) + matrix->c.z;
  v26 = aabb->max.y;
  v55 = aabb->max.z;
  vertices[2].z = v25;
  v27 = aabb->min.x;
  v59 = v26;
  vertices[3].x = (float)((float)((float)(aabb->min.x * v4) + (float)(v26 * x)) + (float)(v55 * v6)) + v5;
  v28 = (float)(v27 * matrix->i.y) + (float)(v26 * matrix->j.y);
  v29 = matrix->j.z;
  vertices[3].y = (float)(v28 + (float)(v55 * v9)) + matrix->c.y;
  v30 = (float)((float)((float)(v27 * matrix->i.z) + (float)(v59 * v29)) + (float)(v55 * matrix->k.z)) + matrix->c.z;
  v31 = aabb->min.z;
  v60 = aabb->min.y;
  vertices[3].z = v30;
  v32 = aabb->max.x;
  v56 = v31;
  v33 = (float)((float)(v32 * v4) + (float)(v60 * x)) + (float)(v31 * v6);
  v62 = v32;
  v34 = v32 * matrix->i.y;
  v35 = matrix->j.y;
  vertices[4].x = v33 + v5;
  v36 = matrix->j.z;
  vertices[4].y = (float)((float)(v34 + (float)(v60 * v35)) + (float)(v56 * v9)) + matrix->c.y;
  v37 = aabb->max.x;
  vertices[4].z = (float)((float)((float)(v62 * matrix->i.z) + (float)(v60 * v36)) + (float)(v56 * matrix->k.z))
                + matrix->c.z;
  v61 = aabb->min.y;
  v38 = (float)((float)(v4 * v37) + (float)(x * v61)) + (float)(v6 * aabb->max.z);
  v39 = matrix->i.y * aabb->max.x;
  v40 = matrix->j.y * v61;
  vertices[5].x = v38 + v5;
  v41 = (float)((float)(v39 + v40) + (float)(v9 * aabb->max.z)) + matrix->c.y;
  v42 = matrix->i.z;
  vertices[5].y = v41;
  v43 = aabb->max.y;
  v57 = aabb->min.z;
  vertices[5].z = (float)((float)((float)(v42 * aabb->max.x) + (float)(matrix->j.z * v61))
                        + (float)(matrix->k.z * aabb->max.z))
                + matrix->c.z;
  vertices[6].x = (float)((float)((float)(v4 * aabb->max.x) + (float)(x * v43)) + (float)(v6 * v57)) + v5;
  v44 = matrix->i.z;
  vertices[6].y = (float)((float)((float)(matrix->i.y * aabb->max.x) + (float)(matrix->j.y * aabb->max.y))
                        + (float)(v9 * v57))
                + matrix->c.y;
  v45 = (float)((float)(v44 * aabb->max.x) + (float)(matrix->j.z * aabb->max.y)) + (float)(matrix->k.z * v57);
  v46 = matrix->c.z;
  v64 = aabb->max.z;
  vertices[6].z = v45 + v46;
  v63[0] = aabb->max.x;
  v47 = aabb->max.y;
  v48 = (float)((float)((float)(v63[0] * v4) + (float)(v47 * x)) + (float)(v64 * v6)) + v5;
  v49 = v63[0] * matrix->i.y;
  v50 = matrix->j.y;
  vertices[7].x = v48;
  *(_QWORD *)&vertices[7].elements[1] = __PAIR64__(
                                          (float)((float)((float)(v47 * matrix->j.z) + (float)(v64 * matrix->k.z))
                                                + (float)(v63[0] * matrix->i.z))
                                        + v46,
                                          (float)((float)(v49 + (float)(v47 * v50)) + (float)(v64 * v9)) + matrix->c.y);
  this->m_planes[0].plane = *vostok::math::create_plane(vertices, &vertices[2], &vertices[1], (int)v63);
  this->m_planes[1].plane = *vostok::math::create_plane(vertices, &vertices[4], &vertices[2], (int)v63);
  this->m_planes[2].plane = *vostok::math::create_plane(vertices, &vertices[1], &vertices[4], (int)v63);
  this->m_planes[3].plane = *vostok::math::create_plane(&vertices[7], &vertices[6], &vertices[5], (int)v63);
  this->m_planes[4].plane = *vostok::math::create_plane(&vertices[7], &vertices[5], &vertices[3], (int)v63);
  this->m_planes[5].plane = *vostok::math::create_plane(&vertices[7], &vertices[3], &vertices[6], (int)v63);
  v51 = this;
  do
  {
    vostok::math::aabb_plane::normalize(v51->m_planes);
    v51 = (vostok::math::cuboid *)((char *)v51 + 20);
  }
  while ( v51 != &this[1] );
}
