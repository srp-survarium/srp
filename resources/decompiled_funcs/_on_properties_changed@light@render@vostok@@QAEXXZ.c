void __thiscall vostok::render::light::on_properties_changed(vostok::render::light *this, vostok::render::light *thisa)
{
  vostok::collision::space_partitioning_tree *m_collision_tree; // ecx
  vostok::collision::object *m_collision_object; // esi
  vostok::render::grass_render_model *m_object; // edi
  _BYTE *v5; // eax
  vostok::collision::object_vtbl *v6; // edx
  void **v7; // esi
  float v8; // xmm5_4
  float z; // eax
  float x; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm4_4
  float v13; // ecx
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  float v17; // xmm4_4
  float v18; // xmm2_4
  const vostok::math::float4x4 *v19; // xmm1_4
  float v20; // xmm4_4
  float v21; // xmm6_4
  float v22; // xmm1_4
  float v23; // xmm5_4
  float v24; // edx
  vostok::render::light::light_flags flags; // ecx
  float v26; // eax
  __int64 v27; // xmm0_8
  const vostok::math::float4x4 *v28; // eax
  vostok::collision::geometry_instance *v29; // eax
  const vostok::math::float4x4 *v30; // eax
  float range; // xmm0_4
  long double v32; // st7
  float v33; // xmm4_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  vostok::math::float4x4 *v36; // ecx
  const vostok::math::float3 *angles_xyz; // eax
  const vostok::math::float4x4 *v38; // eax
  const vostok::math::float4x4 *v39; // eax
  void (__thiscall *decrease_quality)(struct vostok::resources::resource_base *, unsigned int); // edx
  vostok::collision::box_geometry_instance *v41; // eax
  vostok::collision::geometry_instance *v42; // eax
  float v43; // xmm0_4
  vostok::math::float4x4 *v44; // ecx
  const vostok::math::float3 *v45; // eax
  const vostok::math::float4x4 *v46; // eax
  float v47; // xmm0_4
  vostok::math::float4x4 *v48; // ecx
  const vostok::math::float3 *v49; // eax
  const vostok::math::float4x4 *v50; // eax
  const vostok::math::float4x4 *v51; // eax
  vostok::collision::box_geometry_instance *v52; // eax
  const vostok::math::float4x4 *v53; // eax
  vostok::collision::geometry_instance *v54; // eax
  const vostok::math::float4x4 *v55; // eax
  long double v56; // st7
  float v57; // xmm5_4
  float v58; // xmm6_4
  float v59; // xmm7_4
  float v60; // xmm4_4
  float v61; // xmm3_4
  long double v62; // st7
  float v63; // xmm0_4
  float v64; // xmm2_4
  float v65; // xmm6_4
  float v66; // xmm3_4
  vostok::math::float4x4 *v67; // ecx
  const vostok::math::float3 *v68; // eax
  const vostok::math::float4x4 *v69; // eax
  vostok::collision::box_geometry_instance *v70; // eax
  const vostok::math::float4x4 *v71; // [esp+26F8h] [ebp-43Ch]
  const vostok::math::float4x4 *v72; // [esp+26F8h] [ebp-43Ch]
  const vostok::math::float4x4 *_X_4; // [esp+2704h] [ebp-430h]
  const vostok::math::float4x4 *_X_4a; // [esp+2704h] [ebp-430h]
  vostok::math::float3 position; // [esp+2714h] [ebp-420h] BYREF
  float y; // [esp+2720h] [ebp-414h]
  float v77; // [esp+2724h] [ebp-410h]
  _BYTE *p_m_aabb; // [esp+2728h] [ebp-40Ch]
  __int64 v79; // [esp+272Ch] [ebp-408h]
  unsigned int v80; // [esp+2734h] [ebp-400h]
  __int64 v81; // [esp+2738h] [ebp-3FCh]
  float v82; // [esp+2740h] [ebp-3F4h]
  float v83; // [esp+2744h] [ebp-3F0h]
  __int64 v84; // [esp+2748h] [ebp-3ECh]
  unsigned int left_4; // [esp+2750h] [ebp-3E4h]
  vostok::math::float4x4 left_8; // [esp+2754h] [ebp-3E0h] BYREF
  vostok::math::float4x4 dst_8; // [esp+2794h] [ebp-3A0h] BYREF
  vostok::math::float4x4 matrix_8; // [esp+27D4h] [ebp-360h] BYREF
  vostok::math::float4x4 v89; // [esp+2834h] [ebp-300h] BYREF
  vostok::math::float4x4 v90; // [esp+2874h] [ebp-2C0h] BYREF
  vostok::math::float4x4 v91; // [esp+28B4h] [ebp-280h] BYREF
  vostok::math::float4x4 v92; // [esp+28F4h] [ebp-240h] BYREF
  vostok::math::float4x4 result; // [esp+2934h] [ebp-200h] BYREF
  vostok::math::float4x4 v94; // [esp+2974h] [ebp-1C0h] BYREF
  vostok::math::float4x4 v95; // [esp+29B4h] [ebp-180h] BYREF
  vostok::math::float4x4 v96; // [esp+29F4h] [ebp-140h] BYREF
  vostok::math::float4x4 v97; // [esp+2A34h] [ebp-100h] BYREF
  vostok::math::float4x4 v98; // [esp+2A74h] [ebp-C0h] BYREF
  vostok::math::float4x4 v99; // [esp+2AB4h] [ebp-80h] BYREF
  vostok::math::float4x4 v100; // [esp+2AF4h] [ebp-40h] BYREF

  thisa->m_xform_frame = -1;
  vostok::render::light::xform_calc(this, thisa);
  m_collision_tree = thisa->m_collision_tree;
  if ( m_collision_tree && thisa->m_collision_object )
    m_collision_tree->erase(m_collision_tree, thisa->m_collision_object);
  m_collision_object = thisa->m_collision_object;
  m_object = vostok::render::g_allocator.m_object;
  if ( m_collision_object )
  {
    v5 = __RTCastToVoid((void **)&thisa->m_collision_object->__vftable);
    v6 = m_collision_object->__vftable;
    p_m_aabb = v5;
    ((void (__thiscall *)(vostok::collision::object *, _DWORD))v6->~vostok::collision::object)(m_collision_object, 0);
    ((void (__thiscall *)(vostok::render::grass_render_model *, _BYTE *))m_object->is_increasing_quality)(
      m_object,
      p_m_aabb);
    m_object = vostok::render::g_allocator.m_object;
  }
  v7 = (void **)&thisa->m_collision_geometry->__vftable;
  if ( v7 )
  {
    (*(void (__thiscall **)(void **, vostok::render::grass_render_model *))*v7)(v7, m_object);
    p_m_aabb = __RTCastToVoid(v7);
    (*((void (__thiscall **)(void **, _DWORD))*v7 + 32))(v7, 0);
    ((void (__thiscall *)(vostok::render::grass_render_model *, _BYTE *))m_object->is_increasing_quality)(
      m_object,
      p_m_aabb);
  }
  v8 = *(float *)&clear_value;
  *(_QWORD *)&position.elements[1] = 0;
  *(_QWORD *)&thisa->m_aabb.max.x = 0;
  *(_QWORD *)&thisa->m_aabb.min.x = 0;
  y = 0.0;
  thisa->m_aabb.max.z = 0.0;
  thisa->m_aabb.min.z = 0.0;
  thisa->m_aabb.min.x = thisa->m_aabb.min.x - v8;
  thisa->m_aabb.min.y = thisa->m_aabb.min.y - v8;
  thisa->m_aabb.min.z = thisa->m_aabb.min.z - v8;
  thisa->m_aabb.max.x = thisa->m_aabb.max.x + v8;
  thisa->m_aabb.max.y = thisa->m_aabb.max.y + v8;
  thisa->m_aabb.max.z = thisa->m_aabb.max.z + v8;
  z = thisa->direction.z;
  x = thisa->right.x;
  v11 = thisa->right.z * thisa->right.z;
  v81 = *(_QWORD *)&thisa->direction.x;
  v12 = (float)((float)(x * x) + v11) + (float)(thisa->right.y * thisa->right.y);
  p_m_aabb = &thisa->m_aabb;
  v82 = z;
  if ( v12 <= 0.0000099999997 )
  {
    v20 = v82 * 0.0;
    v21 = 0.0;
    if ( COERCE_FLOAT(
           COERCE_UNSIGNED_INT((float)((float)(*(float *)&v81 * 0.0) + (float)(v82 * 0.0)) + *((float *)&v81 + 1))
         & _mask__AbsFloat_) > 0.99000001 )
    {
      v21 = *(float *)&clear_value;
      v8 = 0.0;
    }
    *(float *)&v80 = (float)(*((float *)&v81 + 1) * 0.0) - (float)(*(float *)&v81 * v8);
    v77 = sqrtf(
            (float)((float)(*(float *)&v80 * *(float *)&v80)
                  + (float)((float)((float)(*(float *)&v81 * v21) - v20) * (float)((float)(*(float *)&v81 * v21) - v20)))
          + (float)((float)((float)(v8 * v82) - (float)(v21 * *((float *)&v81 + 1)))
                  * (float)((float)(v8 * v82) - (float)(v21 * *((float *)&v81 + 1)))));
    v22 = (float)(*(float *)&clear_value / v77) * (float)((float)(v8 * v82) - (float)(v21 * *((float *)&v81 + 1)));
    v23 = (float)(*(float *)&clear_value / v77) * (float)((float)(*(float *)&v81 * v21) - v20);
    *(float *)&v79 = v22;
    *(float *)&v80 = (float)(*(float *)&clear_value / v77) * *(float *)&v80;
    position.y = (float)(*((float *)&v81 + 1) * *(float *)&v80) - (float)(v82 * v23);
    position.z = (float)(v22 * v82) - (float)(*(float *)&v81 * *(float *)&v80);
    y = (float)(*(float *)&v81 * v23) - (float)(v22 * *((float *)&v81 + 1));
    *((float *)&v79 + 1) = v23;
    v77 = sqrtf((float)((float)(position.y * position.y) + (float)(y * y)) + (float)(position.z * position.z));
    v19 = clear_value;
    *(float *)&v84 = (float)(*(float *)&clear_value / v77) * position.y;
    *((float *)&v84 + 1) = (float)(*(float *)&clear_value / v77) * position.z;
    *(float *)&left_4 = (float)(*(float *)&clear_value / v77) * y;
  }
  else
  {
    v13 = thisa->right.z;
    v79 = *(_QWORD *)&thisa->right.x;
    *(float *)&v80 = v13;
    v77 = sqrtf(
            (float)((float)(v13 * v13) + (float)(*((float *)&v79 + 1) * *((float *)&v79 + 1)))
          + (float)(*(float *)&v79 * *(float *)&v79));
    v14 = (float)(*(float *)&clear_value / v77) * *(float *)&v79;
    v15 = (float)(*(float *)&clear_value / v77) * *(float *)&v80;
    v16 = (float)(*(float *)&clear_value / v77) * *((float *)&v79 + 1);
    position.y = (float)(*((float *)&v81 + 1) * v15) - (float)(v82 * v16);
    *((float *)&v84 + 1) = (float)(v14 * v82) - (float)(*(float *)&v81 * v15);
    *(float *)&left_4 = (float)(*(float *)&v81 * v16) - (float)(v14 * *((float *)&v81 + 1));
    v77 = sqrtf(
            (float)((float)(*(float *)&left_4 * *(float *)&left_4) + (float)(*((float *)&v84 + 1) * *((float *)&v84 + 1)))
          + (float)(position.y * position.y));
    v17 = (float)(*(float *)&clear_value / v77) * *((float *)&v84 + 1);
    v18 = (float)(v17 * v82)
        - (float)((float)((float)(*(float *)&clear_value / v77) * *(float *)&left_4) * *((float *)&v81 + 1));
    *(float *)&v84 = (float)(*(float *)&clear_value / v77) * position.y;
    *((float *)&v84 + 1) = v17;
    *(float *)&left_4 = (float)(*(float *)&clear_value / v77) * *(float *)&left_4;
    position.y = v18;
    position.z = (float)(*(float *)&v81 * *(float *)&left_4) - (float)(*(float *)&v84 * v82);
    y = (float)(*(float *)&v84 * *((float *)&v81 + 1)) - (float)(*(float *)&v81 * v17);
    v77 = sqrtf((float)((float)(y * y) + (float)(position.z * position.z)) + (float)(v18 * v18));
    v19 = clear_value;
    *(float *)&v79 = (float)(*(float *)&clear_value / v77) * v18;
    *((float *)&v79 + 1) = (float)(*(float *)&clear_value / v77) * position.z;
    *(float *)&v80 = (float)(*(float *)&clear_value / v77) * y;
  }
  v24 = thisa->direction.z;
  *(_QWORD *)&dst_8.i.x = v79;
  *(_QWORD *)&dst_8.lines[1].elements[2] = left_4;
  flags = thisa->flags;
  *(_QWORD *)&dst_8.lines[0].elements[2] = v80;
  v26 = thisa->position.z;
  *(_QWORD *)&dst_8.lines[1].x = v84;
  v27 = *(_QWORD *)&thisa->position.x;
  *(_QWORD *)&dst_8.lines[2].x = *(_QWORD *)&thisa->direction.x;
  *(_QWORD *)&dst_8.lines[2].elements[2] = LODWORD(v24);
  *(_QWORD *)&dst_8.lines[3].x = v27;
  *(_QWORD *)&dst_8.lines[3].elements[2] = __PAIR64__((unsigned int)v19, LODWORD(v26));
  switch ( *(_BYTE *)&flags & 0xF )
  {
    case 0:
    case 4:
      position.y = thisa->range;
      position.z = position.y;
      y = position.y;
      memset((int)&dst_8, 0, sizeof(dst_8));
      dst_8.j.y = position.y;
      dst_8.i.x = position.y;
      dst_8.k.z = position.y;
      LODWORD(dst_8.c.w) = clear_value;
      v28 = vostok::math::create_translation(&result, &thisa->position);
      vostok::math::mul4x3(&left_8, &dst_8, v28);
      v29 = vostok::collision::new_sphere_geometry_instance((vostok::memory::base_allocator *)&left_8, _X_4);
      thisa->m_collision_geometry = v29;
      thisa->m_collision_object = vostok::collision::new_collision_object(
                                    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
                                    1u,
                                    v29,
                                    thisa);
      position.y = thisa->range;
      position.z = position.y;
      y = position.y;
      memset((int)&dst_8, 0, sizeof(dst_8));
      dst_8.j.y = position.y;
      dst_8.i.x = position.y;
      dst_8.k.z = position.y;
      LODWORD(dst_8.c.w) = clear_value;
      v30 = vostok::math::create_translation(&v91, &thisa->position);
      vostok::math::mul4x3(&left_8, &dst_8, v30);
      matrix_8.i = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&left_8);
      matrix_8.lines[1] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&left_8.lines[1]);
      matrix_8.lines[2] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&left_8.lines[2]);
      matrix_8.lines[3] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&left_8.lines[3]);
      goto LABEL_27;
    case 1:
      range = thisa->range;
      qmemcpy((void *)&matrix_8, &thisa->m_xform, sizeof(matrix_8));
      v77 = range;
      v32 = tanf(thisa->spot_penumbra_angle * 0.5);
      v33 = thisa->range;
      v83 = v32 * range;
      v34 = thisa->direction.y;
      v35 = thisa->direction.z;
      v82 = range * 0.5;
      position.y = (float)((float)(v33 * thisa->direction.x) * 0.5) + thisa->position.x;
      position.z = thisa->position.y + (float)((float)(v34 * v33) * 0.5);
      y = thisa->position.z + (float)((float)(v35 * v33) * 0.5);
      memset((int)&left_8, 0, sizeof(left_8));
      left_8.i.x = v83;
      left_8.j.y = v83;
      left_8.k.z = range * 0.5;
      LODWORD(left_8.c.w) = clear_value;
      angles_xyz = vostok::math::float4x4::get_angles_xyz(v36, (vostok::math::float3 *)_X_4);
      v38 = vostok::math::create_rotation(&v99, angles_xyz);
      vostok::math::mul4x3(&dst_8, &left_8, v38);
      v39 = vostok::math::create_translation(&v89, (vostok::math::float3 *)&position.elements[1]);
      vostok::math::mul4x3(&left_8, &dst_8, v39);
      matrix_8.i = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&left_8);
      matrix_8.lines[1] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&left_8.lines[1]);
      matrix_8.lines[2] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&left_8.lines[2]);
      matrix_8.lines[3] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&left_8.lines[3]);
      memset((int)&left_8, 0, sizeof(left_8));
      decrease_quality = vostok::render::g_allocator.m_object->decrease_quality;
      LODWORD(left_8.i.x) = clear_value;
      LODWORD(left_8.j.y) = clear_value;
      LODWORD(left_8.k.z) = clear_value;
      LODWORD(left_8.c.w) = clear_value;
      v41 = (vostok::collision::box_geometry_instance *)((int (__thiscall *)(vostok::render::grass_render_model *, int))decrease_quality)(
                                                          vostok::render::g_allocator.m_object,
                                                          136);
      if ( !v41 )
        goto LABEL_17;
      vostok::collision::box_geometry_instance::box_geometry_instance(v41, &left_8);
      goto LABEL_26;
    case 2:
      v43 = thisa->range;
      position.y = thisa->scale.x + v43;
      position.z = thisa->scale.y + v43;
      y = thisa->scale.z + v43;
      memset((int)&left_8, 0, sizeof(left_8));
      left_8.j.y = position.z;
      left_8.i.x = position.y;
      left_8.k.z = y;
      LODWORD(left_8.c.w) = clear_value;
      v45 = vostok::math::float4x4::get_angles_xyz(v44, (vostok::math::float3 *)_X_4);
      v46 = vostok::math::create_rotation(&v97, v45);
      vostok::math::mul4x3(&dst_8, &left_8, v46);
      v71 = vostok::math::create_translation(&v95, &thisa->position);
      vostok::math::mul4x3(&left_8, &dst_8, v71);
      goto LABEL_23;
    case 3:
      v47 = thisa->range;
      v83 = thisa->scale.x + v47;
      y = thisa->scale.z + v47;
      memset((int)&left_8, 0, sizeof(left_8));
      left_8.i.x = v83;
      left_8.j.y = v83;
      left_8.k.z = y;
      LODWORD(left_8.c.w) = clear_value;
      v49 = vostok::math::float4x4::get_angles_xyz(v48, (vostok::math::float3 *)_X_4);
      v50 = vostok::math::create_rotation(&v90, v49);
      vostok::math::mul4x3(&dst_8, &left_8, v50);
      v51 = vostok::math::create_translation(&v92, &thisa->position);
      vostok::math::mul4x3(&left_8, &dst_8, v51);
      matrix_8.i = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&left_8);
      matrix_8.lines[1] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&left_8.lines[1]);
      matrix_8.lines[2] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&left_8.lines[2]);
      matrix_8.lines[3] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&left_8.lines[3]);
      v52 = (vostok::collision::box_geometry_instance *)((int (__thiscall *)(vostok::render::grass_render_model *, int))vostok::render::g_allocator.m_object->decrease_quality)(
                                                          vostok::render::g_allocator.m_object,
                                                          136);
      if ( v52 )
        vostok::collision::box_geometry_instance::box_geometry_instance(v52, &matrix_8);
      else
LABEL_17:
        v42 = 0;
      goto LABEL_26;
    case 5:
      position.y = thisa->range;
      position.z = position.y;
      y = position.y;
      memset((int)&left_8, 0, sizeof(left_8));
      left_8.j.y = position.y;
      left_8.i.x = position.y;
      left_8.k.z = position.y;
      LODWORD(left_8.c.w) = clear_value;
      v53 = vostok::math::create_translation(&v94, &thisa->position);
      vostok::math::mul4x3(&dst_8, &left_8, v53);
      v54 = vostok::collision::new_sphere_geometry_instance((vostok::memory::base_allocator *)&dst_8, _X_4);
      thisa->m_collision_geometry = v54;
      thisa->m_collision_object = vostok::collision::new_collision_object(
                                    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
                                    1u,
                                    v54,
                                    thisa);
      position.y = thisa->range;
      position.z = position.y;
      y = position.y;
      memset((int)&left_8, 0, sizeof(left_8));
      left_8.j.y = position.y;
      left_8.i.x = position.y;
      left_8.k.z = position.y;
      LODWORD(left_8.c.w) = clear_value;
      v55 = vostok::math::create_translation(&v96, &thisa->position);
      vostok::math::mul4x3(&dst_8, &left_8, v55);
      matrix_8.i = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&dst_8);
      matrix_8.lines[1] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&dst_8.lines[1]);
      matrix_8.lines[2] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&dst_8.lines[2]);
      matrix_8.lines[3] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&dst_8.lines[3]);
      goto LABEL_27;
    case 6:
      v77 = thisa->range;
      v56 = tanf(thisa->spot_penumbra_angle * 0.5) * v77;
      v57 = thisa->right.z;
      v58 = thisa->direction.z;
      v59 = thisa->right.y;
      v60 = thisa->direction.y;
      *(float *)&v81 = thisa->scale.x + v56;
      v61 = thisa->right.x;
      v62 = v56 + thisa->scale.z;
      *((float *)&v81 + 1) = v77 * 0.5;
      v82 = v62;
      v63 = (float)(v57 * v60) - (float)(v59 * v58);
      v64 = v61 * v58;
      v65 = thisa->direction.x;
      y = (float)(v65 * v59) - (float)(v61 * v60);
      position.y = v63;
      position.z = v64 - (float)(v65 * v57);
      v83 = sqrtf((float)((float)(y * y) + (float)(position.z * position.z)) + (float)(v63 * v63));
      v66 = thisa->range;
      position.y = thisa->position.x
                 - (float)((float)(v66 * (float)((float)(*(float *)&clear_value / v83) * v63)) * 0.5);
      position.z = thisa->position.y
                 - (float)((float)(v66 * (float)((float)(*(float *)&clear_value / v83) * position.z)) * 0.5);
      y = thisa->position.z - (float)((float)(v66 * (float)((float)(*(float *)&clear_value / v83) * y)) * 0.5);
      memset((int)&left_8, 0, sizeof(left_8));
      LODWORD(left_8.i.x) = v81;
      left_8.k.z = v82;
      left_8.j.y = v77 * 0.5;
      LODWORD(left_8.c.w) = clear_value;
      v68 = vostok::math::float4x4::get_angles_xyz(v67, (vostok::math::float3 *)_X_4);
      v69 = vostok::math::create_rotation(&v98, v68);
      vostok::math::mul4x3(&dst_8, &left_8, v69);
      v72 = vostok::math::create_translation(&v100, (vostok::math::float3 *)&position.elements[1]);
      vostok::math::mul4x3(&left_8, &dst_8, v72);
LABEL_23:
      matrix_8.i = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&left_8);
      matrix_8.lines[1] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&left_8.lines[1]);
      matrix_8.lines[2] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&left_8.lines[2]);
      matrix_8.lines[3] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&left_8.lines[3]);
      v70 = (vostok::collision::box_geometry_instance *)((int (__thiscall *)(vostok::render::grass_render_model *, int))vostok::render::g_allocator.m_object->decrease_quality)(
                                                          vostok::render::g_allocator.m_object,
                                                          136);
      if ( v70 )
        vostok::collision::box_geometry_instance::box_geometry_instance(v70, &matrix_8);
      else
        v42 = 0;
LABEL_26:
      thisa->m_collision_geometry = v42;
      thisa->m_collision_object = vostok::collision::new_collision_object(
                                    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
                                    1u,
                                    v42,
                                    thisa);
LABEL_27:
      thisa->m_collision_tree->insert(thisa->m_collision_tree, thisa->m_collision_object, &matrix_8);
      vostok::math::aabb::modify((vostok::math::aabb *)&matrix_8, _X_4a);
      return;
  }
}
