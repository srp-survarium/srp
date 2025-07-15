void __userpurge vostok::render::light::on_properties_changed(
        vostok::render::light *this@<ecx>,
        long double rdi0@<esi:edi>,
        int a2)
{
  int v3; // ecx
  vostok::math::aabb *v4; // ecx
  float v5; // xmm0_4
  float v6; // xmm4_4
  float v7; // xmm7_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  int v16; // eax
  vostok::math::float4x4 *v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  double v23; // xmm0_8
  float v24; // xmm6_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm7_4
  float v28; // xmm1_4
  float v29; // xmm7_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  float v32; // xmm5_4
  float v33; // xmm4_4
  float v34; // xmm2_4
  vostok::math::float3 *v35; // eax
  vostok::math::float4x4 *v36; // eax
  vostok::math::float4x4 *v37; // eax
  vostok::math::float4x4 *v38; // esi
  vostok::math::float4x4 *v39; // edi
  float *v40; // esi
  vostok::math::float4x4 *v41; // eax
  vostok::collision::geometry_instance *v42; // eax
  vostok::math::float4x4 *v43; // eax
  char *v44; // ecx
  float v45; // xmm1_4
  vostok::math::float3 *v46; // eax
  vostok::math::float4x4 *v47; // eax
  vostok::math::float4x4 *v48; // eax
  float v49; // xmm0_4
  vostok::math::float3 *v50; // eax
  vostok::math::float4x4 *v51; // eax
  vostok::math::float4x4 *translation; // eax
  vostok::math::float4x4 *p_matrix; // eax
  float v54; // xmm0_4
  float v55; // xmm4_4
  float v56; // xmm2_4
  float v57; // xmm3_4
  vostok::math::float4x4 *v58; // ecx
  vostok::math::float3 *angles_xyz; // eax
  vostok::math::float4x4 *v60; // eax
  vostok::math::float4x4 *v61; // eax
  vostok::collision::geometry_instance *v62; // eax
  vostok::math::float4x4 *v63; // edi
  vostok::math::float4x4 *uniform_scale; // eax
  vostok::collision::geometry_instance *v65; // eax
  const vostok::math::float4x4 *v66; // edi
  vostok::math::float4x4 *v67; // eax
  long double v68; // [esp+0h] [ebp-660h]
  float v69; // [esp+10h] [ebp-650h]
  float v70; // [esp+10h] [ebp-650h]
  vostok::math::float4x4 *v71; // [esp+10h] [ebp-650h]
  vostok::math::float4x4 *v72; // [esp+10h] [ebp-650h]
  vostok::math::float4x4 *v73; // [esp+10h] [ebp-650h]
  float v74; // [esp+10h] [ebp-650h]
  vostok::math::float4x4 *rotation; // [esp+10h] [ebp-650h]
  vostok::math::float3 v76; // [esp+14h] [ebp-64Ch] BYREF
  __int64 v77; // [esp+20h] [ebp-640h] BYREF
  float v78; // [esp+28h] [ebp-638h]
  vostok::math::float3 v79; // [esp+2Ch] [ebp-634h] BYREF
  __int64 v80; // [esp+38h] [ebp-628h] BYREF
  float v81; // [esp+40h] [ebp-620h]
  vostok::math::aabb *v82; // [esp+44h] [ebp-61Ch]
  vostok::math::float4x4 v83; // [esp+48h] [ebp-618h] BYREF
  vostok::math::float4x4 v84; // [esp+88h] [ebp-5D8h] BYREF
  vostok::math::float4x4 matrix; // [esp+C8h] [ebp-598h] BYREF
  _BYTE v86[12]; // [esp+108h] [ebp-558h] BYREF
  _BYTE v87[12]; // [esp+114h] [ebp-54Ch] BYREF
  char v88[64]; // [esp+120h] [ebp-540h] BYREF
  char v89[64]; // [esp+160h] [ebp-500h] BYREF
  char v90[64]; // [esp+1A0h] [ebp-4C0h] BYREF
  vostok::math::float4x4 v91; // [esp+1E0h] [ebp-480h] BYREF
  char v92; // [esp+220h] [ebp-440h] BYREF
  char v93[64]; // [esp+260h] [ebp-400h] BYREF
  char v94[64]; // [esp+2A0h] [ebp-3C0h] BYREF
  char v95; // [esp+2E0h] [ebp-380h] BYREF
  char v96[64]; // [esp+320h] [ebp-340h] BYREF
  char v97[64]; // [esp+360h] [ebp-300h] BYREF
  vostok::math::float4x4 v98; // [esp+3A0h] [ebp-2C0h] BYREF
  char v99[64]; // [esp+3E0h] [ebp-280h] BYREF
  char v100[64]; // [esp+420h] [ebp-240h] BYREF
  vostok::math::float4x4 v101; // [esp+460h] [ebp-200h] BYREF
  vostok::math::float4x4 v102; // [esp+4A0h] [ebp-1C0h] BYREF
  char v103; // [esp+4E0h] [ebp-180h] BYREF
  char v104[64]; // [esp+520h] [ebp-140h] BYREF
  char v105[64]; // [esp+560h] [ebp-100h] BYREF
  vostok::math::float4x4 v106; // [esp+5A0h] [ebp-C0h] BYREF
  vostok::math::float4x4 v107; // [esp+5E0h] [ebp-80h] BYREF
  char v108; // [esp+620h] [ebp-40h] BYREF

  *(_DWORD *)(a2 + 616) = -1;
  vostok::render::light::xform_calc(this, rdi0, a2);
  v3 = *(_DWORD *)(a2 + 688);
  if ( v3 && *(_DWORD *)(a2 + 696) )
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 4))(v3, *(_DWORD *)(a2 + 696));
  vostok::collision::delete_object(vostok::render::g_allocator, *(vostok::collision::object **)(a2 + 696));
  vostok::collision::delete_geometry_instance(
    vostok::render::g_allocator,
    *(vostok::collision::geometry_instance **)(a2 + 692));
  *(_DWORD *)(a2 + 696) = 0;
  *(_DWORD *)(a2 + 692) = 0;
  v82 = (vostok::math::aabb *)(a2 + 872);
  vostok::math::aabb::zero(v4, (vostok::math::aabb *)(a2 + 872));
  v5 = s_bm_current_air_resistance;
  *(float *)(a2 + 872) = *(float *)(a2 + 872) - s_bm_current_air_resistance;
  *(float *)(a2 + 876) = *(float *)(a2 + 876) - v5;
  *(float *)(a2 + 880) = *(float *)(a2 + 880) - v5;
  *(float *)(a2 + 884) = *(float *)(a2 + 884) + v5;
  *(float *)(a2 + 888) = *(float *)(a2 + 888) + v5;
  *(float *)(a2 + 892) = *(float *)(a2 + 892) + v5;
  v79 = *(vostok::math::float3 *)(a2 + 548);
  if ( (float)((float)((float)(*(float *)(a2 + 584) * *(float *)(a2 + 584))
                     + (float)(*(float *)(a2 + 580) * *(float *)(a2 + 580)))
             + (float)(*(float *)(a2 + 576) * *(float *)(a2 + 576))) <= 0.0000099999997 )
  {
    v11 = v5;
    v12 = 0.0;
    *((float *)&v80 + 1) = v5;
    v81 = 0.0;
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(v79.x * 0.0) + v79.y) + (float)(v79.z * 0.0)) & _mask__AbsFloat_) > 0.99000001 )
    {
      v11 = 0.0;
      v12 = v5;
      HIDWORD(v80) = 0;
      v81 = v5;
    }
    v76.y = (float)(v12 * v79.x) - (float)(v79.z * 0.0);
    v13 = (float)(v11 * v79.z) - (float)(v12 * v79.y);
    v14 = fsqrt(
            (float)((float)((float)((float)(v79.y * 0.0) - (float)(v11 * v79.x))
                          * (float)((float)(v79.y * 0.0) - (float)(v11 * v79.x)))
                  + (float)(v76.y * v76.y))
          + (float)(v13 * v13));
    *(float *)&v77 = (float)(v5 / v14) * v13;
    v78 = (float)((float)(v79.y * 0.0) - (float)(v11 * v79.x)) * (float)(v5 / v14);
    *((float *)&v77 + 1) = v76.y * (float)(v5 / v14);
    v76.z = (float)(*((float *)&v77 + 1) * v79.x) - (float)(v79.y * *(float *)&v77);
    v76.x = (float)(v79.y * v78) - (float)(v79.z * *((float *)&v77 + 1));
    v76.y = (float)(v79.z * *(float *)&v77) - (float)(v78 * v79.x);
    v15 = v5 / fsqrt((float)((float)(v76.z * v76.z) + (float)(v76.y * v76.y)) + (float)(v76.x * v76.x));
    *(float *)&v80 = v15 * v76.x;
    *((float *)&v80 + 1) = v76.y * v15;
    v81 = v76.z * v15;
  }
  else
  {
    v77 = *(_QWORD *)(a2 + 576);
    v78 = *(float *)(a2 + 584);
    v6 = fsqrt(
           (float)((float)(v78 * v78) + (float)(*((float *)&v77 + 1) * *((float *)&v77 + 1)))
         + (float)(*(float *)&v77 * *(float *)&v77));
    v7 = (float)(v5 / v6) * *(float *)&v77;
    v78 = v78 * (float)(v5 / v6);
    *((float *)&v77 + 1) = *((float *)&v77 + 1) * (float)(v5 / v6);
    v8 = (float)(v79.y * v78) - (float)(v79.z * *((float *)&v77 + 1));
    v9 = v5
       / fsqrt(
           (float)((float)((float)((float)(*((float *)&v77 + 1) * v79.x) - (float)(v79.y * v7))
                         * (float)((float)(*((float *)&v77 + 1) * v79.x) - (float)(v79.y * v7)))
                 + (float)((float)((float)(v79.z * v7) - (float)(v78 * v79.x))
                         * (float)((float)(v79.z * v7) - (float)(v78 * v79.x))))
         + (float)(v8 * v8));
    v81 = (float)((float)(*((float *)&v77 + 1) * v79.x) - (float)(v79.y * v7)) * v9;
    *((float *)&v80 + 1) = (float)((float)(v79.z * v7) - (float)(v78 * v79.x)) * v9;
    *(float *)&v80 = v9 * v8;
    v76.x = (float)(*((float *)&v80 + 1) * v79.z) - (float)(v81 * v79.y);
    v76.y = (float)(v81 * v79.x) - (float)(v79.z * (float)(v9 * v8));
    v76.z = (float)(v79.y * (float)(v9 * v8)) - (float)(*((float *)&v80 + 1) * v79.x);
    v10 = v5 / fsqrt((float)((float)(v76.z * v76.z) + (float)(v76.y * v76.y)) + (float)(v76.x * v76.x));
    *(float *)&v77 = v10 * v76.x;
    *((float *)&v77 + 1) = v76.y * v10;
    v78 = v76.z * v10;
  }
  *(_QWORD *)&v83.i.x = v77;
  *(_QWORD *)&v83.lines[0].elements[2] = LODWORD(v78);
  *(_QWORD *)&v83.lines[1].x = v80;
  *(_QWORD *)&v83.lines[1].elements[2] = LODWORD(v81);
  v16 = *(_DWORD *)(a2 + 860);
  *(_QWORD *)&v83.lines[2].x = *(_QWORD *)(a2 + 548);
  *(_QWORD *)&v83.lines[2].elements[2] = *(unsigned int *)(a2 + 556);
  v17 = (vostok::math::float4x4 *)(a2 + 532);
  *(_QWORD *)&v83.lines[3].x = *(_QWORD *)(a2 + 532);
  v18 = v16 & 0xF;
  v83.c.z = *(float *)(a2 + 540);
  v83.c.w = v5;
  if ( !v18 )
    goto LABEL_23;
  v19 = v18 - 1;
  if ( !v19 )
  {
    v74 = *(float *)(a2 + 608);
    v54 = *(float *)(a2 + 572) * 0.5;
    qmemcpy(&matrix, (const void *)(a2 + 388), sizeof(matrix));
    __libm_sse2_tan(v68);
    v55 = *(float *)(a2 + 608);
    v76.x = v54 * v74;
    v76.y = v54 * v74;
    v56 = *(float *)(a2 + 552);
    v57 = *(float *)(a2 + 556);
    v76.z = v74 * 0.5;
    v79.x = *(float *)(a2 + 532) + (float)((float)(*(float *)(a2 + 548) * v55) * 0.5);
    v79.y = *(float *)(a2 + 536) + (float)((float)(v56 * v55) * 0.5);
    v79.z = *(float *)(a2 + 540) + (float)((float)(v57 * v55) * 0.5);
    angles_xyz = vostok::math::float4x4::get_angles_xyz(v58, (int)v87, (int)&v83);
    rotation = vostok::math::create_rotation(angles_xyz, (int)v87, (int)v94);
    v60 = vostok::math::create_scale(&v76, (vostok::math::float4x4 *)v96);
    vostok::math::mul4x3(rotation, v60, &v84);
    v61 = vostok::math::create_translation(&v79, &v98);
    vostok::math::mul4x3(v61, &v84, &v83);
    qmemcpy(&matrix, &v83, sizeof(matrix));
    v76.x = s_bm_current_air_resistance;
    v76.y = s_bm_current_air_resistance;
    v76.z = s_bm_current_air_resistance;
    p_matrix = vostok::math::create_scale(&v76, (vostok::math::float4x4 *)v100);
    goto LABEL_22;
  }
  v20 = v19 - 1;
  if ( !v20 )
  {
    v49 = *(float *)(a2 + 608);
    v76.x = *(float *)(a2 + 592) + v49;
    v76.y = *(float *)(a2 + 596) + v49;
    v76.z = *(float *)(a2 + 600) + v49;
    v50 = vostok::math::float4x4::get_angles_xyz(v17, (int)v86, a2 + 388);
    v73 = vostok::math::create_rotation(v50, (int)v86, (int)v89);
    v51 = vostok::math::create_scale(&v76, (vostok::math::float4x4 *)v90);
    vostok::math::mul4x3(v73, v51, &v84);
    v48 = (vostok::math::float4x4 *)&v92;
    goto LABEL_19;
  }
  v21 = v20 - 1;
  if ( !v21 )
  {
    v45 = *(float *)(a2 + 608);
    v76.x = *(float *)(a2 + 592) + v45;
    v76.y = v76.x;
    v76.z = *(float *)(a2 + 600) + v45;
    v46 = vostok::math::float4x4::get_angles_xyz(v17, (int)&v77, a2 + 388);
    v72 = vostok::math::create_rotation(v46, (int)&v77, (int)v105);
    v47 = vostok::math::create_scale(&v76, (vostok::math::float4x4 *)v97);
    vostok::math::mul4x3(v72, v47, &v84);
    v48 = (vostok::math::float4x4 *)&v103;
LABEL_19:
    translation = vostok::math::create_translation((const vostok::math::float3 *)(a2 + 532), v48);
    vostok::math::mul4x3(translation, &v84, &v83);
    v38 = &v83;
    goto LABEL_20;
  }
  v22 = v21 - 1;
  if ( !v22 )
  {
LABEL_23:
    v63 = vostok::math::create_translation((const vostok::math::float3 *)v17, &v102);
    v40 = (float *)(a2 + 608);
    uniform_scale = vostok::math::create_uniform_scale((float *)(a2 + 608), (int)v104);
    vostok::math::mul4x3(v63, uniform_scale, &v84);
    v65 = vostok::collision::new_sphere_geometry_instance((vostok::memory::base_allocator *)&v84);
    *(_DWORD *)(a2 + 692) = v65;
    *(_DWORD *)(a2 + 696) = vostok::collision::new_collision_object(
                              vostok::render::g_allocator,
                              (unsigned int)v65,
                              (vostok::collision::geometry_instance *)a2);
    v43 = vostok::math::create_translation((const vostok::math::float3 *)(a2 + 532), &v106);
    v44 = &v108;
    goto LABEL_24;
  }
  if ( v22 == 1 )
  {
    v39 = vostok::math::create_translation((const vostok::math::float3 *)v17, &v107);
    v40 = (float *)(a2 + 608);
    v41 = vostok::math::create_uniform_scale((float *)(a2 + 608), (int)v88);
    vostok::math::mul4x3(v39, v41, &v84);
    v42 = vostok::collision::new_sphere_geometry_instance((vostok::memory::base_allocator *)&v84);
    *(_DWORD *)(a2 + 692) = v42;
    *(_DWORD *)(a2 + 696) = vostok::collision::new_collision_object(
                              vostok::render::g_allocator,
                              (unsigned int)v42,
                              (vostok::collision::geometry_instance *)a2);
    v43 = vostok::math::create_translation((const vostok::math::float3 *)(a2 + 532), &v101);
    v44 = &v95;
LABEL_24:
    v66 = v43;
    v67 = vostok::math::create_uniform_scale(v40, (int)v44);
    vostok::math::mul4x3(v66, v67, &v84);
    qmemcpy(&matrix, &v84, sizeof(matrix));
    goto LABEL_25;
  }
  v69 = *(float *)(a2 + 608);
  v23 = (float)(*(float *)(a2 + 572) * 0.5);
  __libm_sse2_tan(v68);
  *(float *)&v23 = v23;
  *(float *)&v23 = *(float *)&v23 * v69;
  v76.x = *(float *)(a2 + 592) + *(float *)&v23;
  v76.y = v69 * 0.5;
  v76.z = *(float *)(a2 + 600) + *(float *)&v23;
  v24 = *(float *)(a2 + 584);
  v25 = *(float *)(a2 + 576);
  v70 = *(float *)(a2 + 580);
  v26 = *(float *)(a2 + 552);
  v27 = *(float *)(a2 + 556);
  *(float *)&v23 = (float)(v24 * v26) - (float)(v70 * v27);
  v28 = v25 * v27;
  v29 = *(float *)(a2 + 548);
  v30 = (float)(v29 * v70) - (float)(v25 * v26);
  v31 = v28 - (float)(v29 * v24);
  v32 = fsqrt((float)((float)(v30 * v30) + (float)(v31 * v31)) + (float)(*(float *)&v23 * *(float *)&v23));
  v33 = *(float *)(a2 + 608);
  v34 = *(float *)(a2 + 532)
      - (float)((float)((float)(*(float *)&v23 * (float)(s_bm_current_air_resistance / v32)) * v33) * 0.5);
  v79.y = *(float *)(a2 + 536) - (float)((float)((float)(v31 * (float)(s_bm_current_air_resistance / v32)) * v33) * 0.5);
  *(float *)&v23 = *(float *)(a2 + 540)
                 - (float)((float)((float)(v30 * (float)(s_bm_current_air_resistance / v32)) * v33) * 0.5);
  v79.x = v34;
  v79.z = *(float *)&v23;
  v35 = vostok::math::float4x4::get_angles_xyz((vostok::math::float4x4 *)(a2 + 576), (int)&v80, a2 + 388);
  v71 = vostok::math::create_rotation(v35, (int)&v80, (int)v93);
  v36 = vostok::math::create_scale(&v76, (vostok::math::float4x4 *)v99);
  vostok::math::mul4x3(v71, v36, &v83);
  v37 = vostok::math::create_translation(&v79, &v91);
  vostok::math::mul4x3(v37, &v83, &v84);
  v38 = &v84;
LABEL_20:
  qmemcpy(&matrix, v38, sizeof(matrix));
  p_matrix = &matrix;
LABEL_22:
  v62 = vostok::collision::new_box_geometry_instance(vostok::render::g_allocator, p_matrix);
  *(_DWORD *)(a2 + 692) = v62;
  *(_DWORD *)(a2 + 696) = vostok::collision::new_collision_object(
                            vostok::render::g_allocator,
                            (unsigned int)v62,
                            (vostok::collision::geometry_instance *)a2);
LABEL_25:
  (***(void (__thiscall ****)(_DWORD, _DWORD, vostok::math::float4x4 *))(a2 + 688))(
    *(_DWORD *)(a2 + 688),
    *(_DWORD *)(a2 + 696),
    &matrix);
  vostok::math::aabb::modify((vostok::math::aabb *)&matrix, v82);
}
