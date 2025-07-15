void __thiscall vostok::render::stage_shadow_direct::calculate_matrices(
        vostok::render::stage_shadow_direct *this,
        float cascade_id,
        unsigned int cascade_index,
        unsigned int shadow_map_size,
        unsigned int setup_index,
        float a7)
{
  float v7; // ebx
  int v8; // ecx
  float v9; // xmm0_4
  float *v10; // esi
  float *v11; // eax
  vostok::render::environment_properties *v12; // ecx
  vostok::math::float3 *sun_direction; // eax
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  int v17; // eax
  vostok::render::environment_properties *v18; // ecx
  vostok::math::float3 *v19; // eax
  float *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm5_4
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm2_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  vostok::render::environment_properties *v32; // ecx
  const vostok::render::ray **v33; // eax
  int v34; // eax
  int i; // ecx
  float v36; // xmm0_4
  float v37; // xmm2_4
  float v38; // xmm1_4
  float *v39; // edi
  vostok::render::shadow_cascade_volume *v40; // ecx
  vostok::render::ray **v41; // eax
  _DWORD *v42; // edi
  vostok::fixed_vector<vostok::render::ray,8>::allign_helper *m_buffer; // esi
  float *v44; // edi
  float v45; // esi
  int v46; // eax
  vostok::render::environment_properties *v47; // ecx
  vostok::math::float3 *v48; // eax
  unsigned int v49; // eax
  char *v50; // edi
  _DWORD *v51; // ecx
  vostok::math::plane *m_begin; // eax
  float *v53; // edi
  float v54; // eax
  vostok::math::plane v55; // [esp+4h] [ebp-48Ch]
  vostok::math::float3 *v56; // [esp+Ch] [ebp-484h]
  vostok::math::plane v57[16]; // [esp+1Ch] [ebp-474h] BYREF
  char v58; // [esp+128h] [ebp-368h] BYREF
  vostok::fixed_vector<vostok::math::plane,16> value; // [esp+12Ch] [ebp-364h] BYREF
  char v60; // [esp+288h] [ebp-208h] BYREF
  vostok::math::float4x4 v61; // [esp+30Ch] [ebp-184h] BYREF
  vostok::math::float4x4 light_space_transform; // [esp+34Ch] [ebp-144h] BYREF
  vostok::math::float4x4 v63; // [esp+38Ch] [ebp-104h] BYREF
  _DWORD v64[6]; // [esp+3CCh] [ebp-C4h] BYREF
  vostok::math::float4x4 v65; // [esp+3E4h] [ebp-ACh] BYREF
  _DWORD *v66; // [esp+428h] [ebp-68h]
  int v67; // [esp+42Ch] [ebp-64h]
  float v68; // [esp+430h] [ebp-60h] BYREF
  float v69; // [esp+434h] [ebp-5Ch]
  float v70; // [esp+438h] [ebp-58h]
  unsigned int v71; // [esp+43Ch] [ebp-54h]
  float v72; // [esp+440h] [ebp-50h]
  float v73; // [esp+444h] [ebp-4Ch]
  float v74; // [esp+448h] [ebp-48h]
  vostok::math::float3 v75; // [esp+44Ch] [ebp-44h] BYREF
  float mult; // [esp+458h] [ebp-38h] BYREF
  float v77; // [esp+45Ch] [ebp-34h]
  float v78; // [esp+460h] [ebp-30h]
  float v79; // [esp+464h] [ebp-2Ch]
  float v80; // [esp+468h] [ebp-28h]
  float v81; // [esp+46Ch] [ebp-24h]
  float v82; // [esp+470h] [ebp-20h]
  float v83; // [esp+474h] [ebp-1Ch] BYREF
  float v84; // [esp+478h] [ebp-18h]
  float v85; // [esp+47Ch] [ebp-14h]
  vostok::math::float3 light_xz_shift; // [esp+480h] [ebp-10h] BYREF

  v7 = cascade_id;
  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)&cascade_index + 3,
    (int)L"stage_shadow_direct");
  v8 = *(_DWORD *)(LODWORD(v7) + 4);
  v67 = 2252 * LODWORD(a7);
  v66 = (_DWORD *)(2252 * LODWORD(a7) + v8 + 11720);
  v9 = *(float *)(280 * cascade_index + *v66 + 268);
  v71 = 280 * cascade_index;
  a7 = v9;
  if ( v9 >= 0.0000001 )
  {
    *(_QWORD *)&v75.x = *(_QWORD *)(v8 + 21148);
    v10 = (float *)(v8 + 21156);
    v11 = (float *)(v8 + 21132);
    v12 = *(vostok::render::environment_properties **)(v8 + 16268);
    v75.z = *v10;
    v79 = *v11 - (float)(v75.x * off_mult);
    v80 = v11[1] - (float)(v75.y * off_mult);
    v81 = v11[2] - (float)(v75.z * off_mult);
    sun_direction = vostok::render::environment_properties::get_sun_direction(
                      v12,
                      (int)&v12->use_sky_clouds_lighting,
                      &v83);
    x = sun_direction->x;
    y = sun_direction->y;
    z = sun_direction->z;
    v17 = *(_DWORD *)(*(_DWORD *)(LODWORD(v7) + 4) + 16268);
    v68 = v79 - (float)(x * 300.0);
    v69 = v80 - (float)(y * 300.0);
    v70 = v81 - (float)(z * 300.0);
    *(_QWORD *)&light_xz_shift.x = LODWORD(s_bm_current_air_resistance);
    light_xz_shift.z = 0.0;
    v19 = vostok::render::environment_properties::get_sun_direction(v18, v17 + 280, &v83);
    vostok::math::create_camera_direction(v19, &light_xz_shift, &v63, &v68);
    vostok::math::create_orthographic_projection(
      (int)&v61,
      (float)(a7 * 1.41421) + 300.0,
      (vostok::math *)LODWORD(a7),
      (struct vostok::math::float4x4 *)LODWORD(a7),
      1.0);
    LODWORD(v57[0].normal.x) = &v57[0].d;
    LODWORD(v57[0].normal.y) = &v57[0].d;
    LODWORD(v57[0].normal.z) = &v58;
    memset(&light_xz_shift, 0, sizeof(light_xz_shift));
    value.m_begin = (vostok::math::plane *)value.m_buffer;
    value.m_end = (vostok::math::plane *)value.m_buffer;
    value.m_max_end = (vostok::math::plane *)&value.m_buffer[12];
    if ( shadow_map_size )
    {
      v33 = (const vostok::render::ray **)(v71 + *v66 + 64);
      cascade_id = *(float *)(v71 + *v66 + 68);
      vostok::buffer_vector<vostok::render::ray>::assign<vostok::render::ray const *>(
        (vostok::buffer_vector<vostok::render::ray> *)&value,
        *v33,
        (const vostok::render::ray **)&cascade_id);
    }
    else
    {
      cascade_id = 0.0;
      do
      {
        v20 = *(float **)(LODWORD(v7) + 4);
        v72 = *(float *)((char *)v20 + LODWORD(cascade_id) + 20932);
        v73 = *(float *)((char *)v20 + LODWORD(cascade_id) + 20936);
        v74 = *(float *)((char *)v20 + LODWORD(cascade_id) + 20940);
        v21 = fsqrt((float)((float)(v72 * v72) + (float)(v74 * v74)) + (float)(v73 * v73));
        v22 = v74 * (float)(s_bm_current_air_resistance / v21);
        v23 = v73 * (float)(s_bm_current_air_resistance / v21);
        v24 = (float)(s_bm_current_air_resistance / v21) * v72;
        v25 = (float)((float)(v20[4917] * v22) + (float)(v20[4913] * v23)) + (float)(v24 * v20[4909]);
        v26 = (float)((float)(v20[4910] * v24) + (float)(v20[4918] * v22)) + (float)(v20[4914] * v23);
        v27 = v20[4911];
        v72 = v24;
        v28 = (float)(v27 * v24) + (float)(v20[4919] * v22);
        v29 = v20[4915];
        mult = v25;
        v77 = v26;
        v30 = v28 + (float)(v29 * v23);
        v31 = v20[4056];
        v78 = v30;
        *(float *)v64 = v25;
        *(float *)&v64[1] = v26;
        *(float *)&v64[2] = v30;
        v83 = (float)(v25 * v31) + v79;
        v84 = (float)(v26 * v31) + v80;
        v85 = (float)(v30 * v31) + v81;
        *(float *)&v64[3] = v83;
        *(float *)&v64[4] = v84;
        v73 = v23;
        v74 = v22;
        *(float *)&v64[5] = v85;
        vostok::buffer_vector<vostok::render::ray>::push_back(
          (vostok::buffer_vector<vostok::render::ray> *)LODWORD(cascade_id),
          (const vostok::render::ray *)&value,
          v64);
        LODWORD(cascade_id) += 12;
      }
      while ( SLODWORD(cascade_id) < 48 );
    }
    *(float *)&value.m_buffer[12].m_store[12] = v79;
    *(float *)value.m_buffer[13].m_store = v80;
    *(float *)&value.m_buffer[13].m_store[4] = v81;
    v34 = *(_DWORD *)(LODWORD(v7) + 4);
    *(_QWORD *)value.m_buffer[12].m_store = *(_QWORD *)&v75.x;
    *(float *)&value.m_buffer[12].m_store[8] = v75.z;
    *(float *)&value.m_buffer[14].m_store[4] = v68;
    *(float *)&value.m_buffer[14].m_store[8] = v69;
    *(float *)&value.m_buffer[14].m_store[12] = v70;
    *(vostok::math::float3 *)&value.m_buffer[13].m_store[8] = *vostok::render::environment_properties::get_sun_direction(
                                                                 v32,
                                                                 *(_DWORD *)(v34 + 16268) + 280,
                                                                 &v83);
    vostok::math::mul4x3(&v61, &v63, &light_space_transform);
    vostok::math::invert4x3(&light_space_transform, &v65);
    for ( i = 0; i < 24; i += 3 )
    {
      v36 = *(&corners[0].x + i);
      v37 = *(float *)((char *)&corners[0].z + i * 4);
      v38 = *(&corners[0].y + i);
      v82 = (float)((float)((float)(v65.i.x * v36) + (float)(v65.k.x * v37)) + (float)(v65.j.x * v38)) + v65.c.x;
      v83 = (float)((float)((float)(v65.i.y * v36) + (float)(v65.k.y * v37)) + (float)(v65.j.y * v38)) + v65.c.y;
      v84 = (float)((float)((float)(v65.i.z * v36) + (float)(v65.k.z * v37)) + (float)(v65.j.z * v38)) + v65.c.z;
      *(float *)&value.m_buffer[15].m_store[i * 4] = v82;
      *(float *)&value.m_buffer[15].m_store[i * 4 + 4] = v83;
      v39 = (float *)&value.m_buffer[15].m_store[i * 4 + 8];
      *v39 = v84;
    }
    v40 = (vostok::render::shadow_cascade_volume *)facetable;
    v41 = (vostok::render::ray **)&v60;
    do
    {
      *v41 = v40->view_frustum_rays.m_begin;
      v41[1] = v40->view_frustum_rays.m_end;
      v41[2] = v40->view_frustum_rays.m_max_end;
      m_buffer = v40->view_frustum_rays.m_buffer;
      v42 = v41 + 3;
      v40 = (vostok::render::shadow_cascade_volume *)((char *)v40 + 16);
      v41 += 8;
      *v42 = *(_DWORD *)m_buffer->m_store;
      LODWORD(v45) = &m_buffer->m_store[4];
      v44 = (float *)(v42 + 1);
    }
    while ( (int)v40 < (int)facetable[4] );
    v55.normal.y = a7;
    LODWORD(v55.normal.x) = &light_xz_shift;
    vostok::render::shadow_cascade_volume::compute_caster_model_fixed(v40, v44, v45, &value, v57, v55);
    vostok::math::mul4x3(&v61, &v63, &light_space_transform);
    cascade_id = (float)setup_index;
    vostok::render::stage_shadow_direct::compute_aligment(
      &light_xz_shift,
      cascade_id,
      (vostok::render::stage_shadow_direct *)&v83,
      &mult,
      v56);
    v46 = *(_DWORD *)(*(_DWORD *)(LODWORD(v7) + 4) + 16268);
    *(_QWORD *)&v75.x = LODWORD(s_bm_current_air_resistance);
    v75.z = 0.0;
    mult = (float)(light_xz_shift.x + v68) + v83;
    v77 = v84 + (float)(light_xz_shift.y + v69);
    v78 = v85 + (float)(light_xz_shift.z + v70);
    v48 = vostok::render::environment_properties::get_sun_direction(v47, v46 + 280, &v83);
    qmemcpy(&v63, vostok::math::create_camera_direction(v48, &v75, &v65, &mult), sizeof(v63));
    v50 = (char *)&loc_406F3 + 64 * shadow_map_size + LODWORD(v7) + 5;
    shadow_map_size <<= 6;
    v49 = shadow_map_size;
    qmemcpy(v50, &v63, 0x40u);
    qmemcpy((char *)&loc_407F4 + v49 + LODWORD(v7) + 4, &v61, 0x40u);
    v51 = (_DWORD *)(v67 + *(_DWORD *)(LODWORD(v7) + 4) + 11720);
    if ( cascade_index < (*(_DWORD *)(v67 + *(_DWORD *)(LODWORD(v7) + 4) + 11724) - *v51) / 280 - 1 )
    {
      cascade_id = *(float *)&value.m_end;
      vostok::buffer_vector<vostok::render::ray>::assign<vostok::render::ray const *>(
        (vostok::buffer_vector<vostok::render::ray> *)(v71 + *v51 + 344),
        (const vostok::render::ray *)value.m_begin,
        (const vostok::render::ray **)&cascade_id);
    }
    qmemcpy(
      (char *)&loc_408F7 + shadow_map_size + LODWORD(v7) + 1,
      (const void *)(*(_DWORD *)(LODWORD(v7) + 4) + 19636),
      0x40u);
    vostok::math::mul4x3(&v61, &v63, &light_space_transform);
    qmemcpy((void *)(shadow_map_size + *(_DWORD *)(LODWORD(v7) + 4) + 20676), &light_space_transform, 0x40u);
    m_begin = value.m_begin;
    v53 = (float *)(LODWORD(v7) + 12 * (cascade_index + 21985));
    *v53++ = v63.c.x;
    *v53 = v63.c.y;
    value.m_end = m_begin;
    v54 = v57[0].normal.x;
    v53[1] = v63.c.z;
    v57[0].normal.y = v54;
  }
  D3DPERF_EndEvent();
}
