void __userpurge vostok::math::cuboid::cuboid(
        const vostok::math::aabb *aabb@<ecx>,
        const vostok::math::float4x4 *matrix@<eax>,
        vostok::math::cuboid *this)
{
  float y; // xmm1_4
  float x; // xmm0_4
  float v5; // xmm5_4
  float v6; // xmm4_4
  float v7; // xmm3_4
  float v8; // xmm6_4
  float v10; // xmm2_4
  float v11; // xmm7_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm7_4
  float v15; // xmm7_4
  float v16; // xmm7_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm7_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm7_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm7_4
  float v40; // xmm0_4
  float v41; // xmm7_4
  float v42; // xmm0_4
  float v43; // xmm7_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm0_4
  float v50; // xmm2_4
  float v51; // xmm7_4
  float v52; // xmm4_4
  float v53; // xmm5_4
  float v54; // xmm3_4
  float v55; // xmm0_4
  vostok::math::cuboid *v56; // ecx
  int v57; // ecx
  vostok::math::float3 v58; // [esp+4h] [ebp-7Ch] BYREF
  vostok::math::float3 v59; // [esp+10h] [ebp-70h] BYREF
  vostok::math::float3 v60; // [esp+1Ch] [ebp-64h] BYREF
  vostok::math::float3 v61; // [esp+28h] [ebp-58h] BYREF
  vostok::math::float3 v62; // [esp+34h] [ebp-4Ch] BYREF
  vostok::math::float3 v63; // [esp+40h] [ebp-40h] BYREF
  vostok::math::float3 v64; // [esp+4Ch] [ebp-34h] BYREF
  vostok::math::float3 v65; // [esp+58h] [ebp-28h] BYREF
  vostok::math::plane v66; // [esp+68h] [ebp-18h] BYREF
  float z; // [esp+78h] [ebp-8h]
  float v68; // [esp+88h] [ebp+8h]
  float v69; // [esp+88h] [ebp+8h]
  float v70; // [esp+88h] [ebp+8h]
  float v71; // [esp+88h] [ebp+8h]
  vostok::math::aabb_plane *v72; // [esp+88h] [ebp+8h]
  float v73; // [esp+88h] [ebp+8h]

  y = aabb->min.y;
  x = aabb->min.x;
  v5 = matrix->i.x;
  v6 = matrix->j.x;
  v7 = matrix->k.x;
  v8 = matrix->c.x;
  z = aabb->min.z;
  v10 = matrix->i.y;
  v58.x = (float)((float)((float)(v5 * x) + (float)(v6 * y)) + (float)(v7 * z)) + v8;
  v11 = (float)((float)((float)(v10 * x) + (float)(matrix->j.y * y)) + (float)(matrix->k.y * z)) + matrix->c.y;
  v12 = matrix->i.z;
  v13 = matrix->j.z * y;
  v58.y = v11;
  v14 = (float)((float)((float)(v12 * x) + v13) + (float)(matrix->k.z * z)) + matrix->c.z;
  v68 = aabb->min.y;
  z = aabb->max.z;
  v58.z = v14;
  v59.x = (float)((float)((float)(x * v5) + (float)(v68 * v6)) + (float)(z * v7)) + v8;
  v15 = matrix->i.z;
  v59.y = (float)((float)((float)(x * matrix->i.y) + (float)(v68 * matrix->j.y)) + (float)(z * matrix->k.y))
        + matrix->c.y;
  v16 = (float)((float)((float)(v15 * x) + (float)(v68 * matrix->j.z)) + (float)(z * matrix->k.z)) + matrix->c.z;
  v69 = aabb->max.y;
  z = aabb->min.z;
  v59.z = v16;
  v17 = matrix->i.y;
  v60.x = (float)((float)((float)(x * v5) + (float)(v69 * v6)) + (float)(z * v7)) + v8;
  v18 = (float)((float)((float)(x * v17) + (float)(v69 * matrix->j.y)) + (float)(z * matrix->k.y)) + matrix->c.y;
  v19 = x * matrix->i.z;
  v60.y = v18;
  v20 = (float)((float)(v19 + (float)(v69 * matrix->j.z)) + (float)(z * matrix->k.z)) + matrix->c.z;
  v70 = aabb->max.y;
  z = aabb->max.z;
  v60.z = v20;
  v21 = aabb->min.x;
  v22 = matrix->i.y;
  v61.x = (float)((float)((float)(aabb->min.x * v5) + (float)(v70 * v6)) + (float)(z * v7)) + v8;
  v23 = (float)((float)((float)(v21 * v22) + (float)(v70 * matrix->j.y)) + (float)(z * matrix->k.y)) + matrix->c.y;
  v24 = matrix->i.z;
  v61.y = v23;
  v25 = (float)((float)((float)(v21 * v24) + (float)(v70 * matrix->j.z)) + (float)(z * matrix->k.z)) + matrix->c.z;
  v71 = aabb->min.y;
  z = aabb->min.z;
  v61.z = v25;
  v26 = aabb->max.x;
  v27 = v26 * matrix->i.y;
  v28 = matrix->j.y;
  v62.x = (float)((float)((float)(v26 * v5) + (float)(v71 * v6)) + (float)(z * v7)) + v8;
  v29 = matrix->k.y;
  v30 = v26 * matrix->i.z;
  v62.y = (float)((float)(v27 + (float)(v71 * v28)) + (float)(z * v29)) + matrix->c.y;
  v31 = aabb->min.y;
  v62.z = (float)((float)(v30 + (float)(v71 * matrix->j.z)) + (float)(z * matrix->k.z)) + matrix->c.z;
  *(float *)&v72 = v31;
  v32 = (float)(v5 * aabb->max.x) + (float)(v6 * v31);
  v33 = (float)(matrix->i.y * aabb->max.x) + (float)(matrix->j.y * v31);
  v34 = aabb->max.z;
  v63.x = (float)(v32 + (float)(v7 * v34)) + v8;
  v35 = (float)(v33 + (float)(v29 * v34)) + matrix->c.y;
  v36 = matrix->i.z;
  v63.y = v35;
  v37 = (float)((float)((float)(v36 * aabb->max.x) + (float)(matrix->j.z * *(float *)&v72))
              + (float)(matrix->k.z * aabb->max.z))
      + matrix->c.z;
  v38 = aabb->max.x;
  v73 = aabb->min.z;
  v63.z = v37;
  v39 = (float)((float)(v5 * v38) + (float)(v6 * aabb->max.y)) + (float)(v7 * v73);
  v40 = matrix->i.y;
  v64.x = v39 + v8;
  v41 = v40 * aabb->max.x;
  v42 = aabb->max.y;
  v43 = (float)((float)(v41 + (float)(matrix->j.y * v42)) + (float)(v29 * v73)) + matrix->c.y;
  v44 = matrix->j.z * v42;
  v45 = matrix->k.z * v73;
  v46 = (float)(matrix->i.z * aabb->max.x) + v44;
  v47 = aabb->max.x;
  v64.y = v43;
  v48 = (float)(v46 + v45) + matrix->c.z;
  v49 = aabb->max.y;
  v64.z = v48;
  v50 = aabb->max.z;
  v51 = (float)((float)(v47 * v5) + (float)(v49 * v6)) + (float)(v50 * v7);
  v52 = (float)(v47 * matrix->i.y) + (float)(v49 * matrix->j.y);
  v53 = v50 * matrix->k.y;
  v54 = matrix->c.y;
  v65.x = v51 + v8;
  v55 = (float)((float)((float)(v49 * matrix->j.z) + (float)(v50 * matrix->k.z)) + (float)(v47 * matrix->i.z))
      + matrix->c.z;
  v65.y = (float)(v52 + v53) + v54;
  v65.z = v55;
  this->m_planes[0].plane = *vostok::math::create_plane(&v58, &v59, &v66, &v60.x);
  this->m_planes[1].plane = *vostok::math::create_plane(&v58, &v60, &v66, &v62.x);
  this->m_planes[2].plane = *vostok::math::create_plane(&v58, &v62, &v66, &v59.x);
  this->m_planes[3].plane = *vostok::math::create_plane(&v65, &v63, &v66, &v64.x);
  this->m_planes[4].plane = *vostok::math::create_plane(&v65, &v61, &v66, &v63.x);
  this->m_planes[5].plane = *vostok::math::create_plane(&v65, &v64, &v66, &v61.x);
  v56 = this;
  do
  {
    vostok::math::aabb_plane::normalize(v56->m_planes);
    v56 = (vostok::math::cuboid *)(v57 + 20);
  }
  while ( v56 != &this[1] );
}
