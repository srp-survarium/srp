void __thiscall vostok::render::render_particle_emitter_instance::render_subuv_sprites(
        vostok::render::render_particle_emitter_instance *this,
        const vostok::math::float3 *offset_to_camera,
        float *a3)
{
  float v3; // eax
  float x; // esi
  char *v5; // eax
  float v6; // esi
  vostok::render::vertex_buffer *v7; // ecx
  int v8; // ebx
  int v9; // esi
  bool v10; // zf
  float v11; // xmm0_4
  float v12; // xmm2_4
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // rax
  unsigned int v15; // eax
  signed int v16; // eax
  float v17; // xmm0_4
  char *v18; // eax
  float v19; // xmm1_4
  float v20; // eax
  unsigned int v21; // xmm2_4
  unsigned int v22; // xmm3_4
  unsigned int v23; // xmm4_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  double v26; // st7
  float v27; // xmm3_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  double v35; // st7
  float v36; // xmm3_4
  float v37; // xmm4_4
  float v38; // xmm5_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  unsigned int v43; // xmm3_4
  float v44; // xmm0_4
  float v45; // xmm1_4
  vostok::render::subuv_particle_sprite_vertex *v46; // ecx
  float v47; // xmm3_4
  float v48; // xmm4_4
  float v49; // xmm5_4
  float v50; // xmm0_4
  float v51; // xmm2_4
  float v52; // xmm1_4
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm2_4
  vostok::render::subuv_particle_sprite_vertex *v56; // ecx
  float v57; // xmm0_4
  float v58; // xmm1_4
  float v59; // xmm2_4
  float v60; // xmm3_4
  float v61; // xmm1_4
  float v62; // xmm2_4
  float v63; // xmm3_4
  unsigned int v64; // xmm3_4
  float v65; // xmm0_4
  vostok::render::subuv_particle_sprite_vertex *v66; // ecx
  float v67; // eax
  vostok::render::untyped_buffer *v68; // ecx
  int v69; // edx
  vostok::render::res_geometry *v70; // ecx
  vostok::render::backend *v71; // ecx
  vostok::math::float3 v72; // [esp-10h] [ebp-188h]
  vostok::math::float3 v73; // [esp-10h] [ebp-188h]
  vostok::math::float3 v74; // [esp-10h] [ebp-188h]
  vostok::math::float3 v75; // [esp-10h] [ebp-188h]
  vostok::math::float4 v76; // [esp-4h] [ebp-17Ch] BYREF
  vostok::math::float2 v77; // [esp+Ch] [ebp-16Ch]
  vostok::math::float2 v78; // [esp+14h] [ebp-164h]
  unsigned int v79; // [esp+1Ch] [ebp-15Ch]
  vostok::math::float3 v80; // [esp+20h] [ebp-158h]
  vostok::math::float2 v81; // [esp+2Ch] [ebp-14Ch]
  vostok::math::float4 v82; // [esp+34h] [ebp-144h]
  double v83; // [esp+44h] [ebp-134h]
  float v84; // [esp+54h] [ebp-124h]
  float v85; // [esp+58h] [ebp-120h]
  float v86; // [esp+5Ch] [ebp-11Ch]
  int v87; // [esp+60h] [ebp-118h]
  float v88; // [esp+64h] [ebp-114h]
  float v89; // [esp+68h] [ebp-110h]
  float v90; // [esp+6Ch] [ebp-10Ch]
  int v91; // [esp+70h] [ebp-108h]
  float v92; // [esp+74h] [ebp-104h]
  float v93; // [esp+78h] [ebp-100h]
  float v94; // [esp+7Ch] [ebp-FCh]
  int v95; // [esp+80h] [ebp-F8h]
  float v96; // [esp+84h] [ebp-F4h]
  float v97; // [esp+88h] [ebp-F0h]
  float v98; // [esp+8Ch] [ebp-ECh]
  int v99; // [esp+90h] [ebp-E8h]
  float v100; // [esp+94h] [ebp-E4h]
  float v101; // [esp+98h] [ebp-E0h]
  float v102; // [esp+9Ch] [ebp-DCh]
  __int64 v103; // [esp+A0h] [ebp-D8h]
  float v104; // [esp+A8h] [ebp-D0h]
  unsigned int v105; // [esp+ACh] [ebp-CCh]
  float v106; // [esp+B0h] [ebp-C8h]
  float v107; // [esp+B4h] [ebp-C4h]
  __int64 v108; // [esp+B8h] [ebp-C0h]
  float v109; // [esp+C0h] [ebp-B8h]
  __int64 v110; // [esp+C4h] [ebp-B4h]
  float v111; // [esp+CCh] [ebp-ACh]
  __int64 v112; // [esp+D0h] [ebp-A8h]
  float v113; // [esp+D8h] [ebp-A0h]
  unsigned int v114; // [esp+DCh] [ebp-9Ch]
  float v115; // [esp+E0h] [ebp-98h]
  float v116; // [esp+E4h] [ebp-94h]
  float v117; // [esp+E8h] [ebp-90h]
  float v118; // [esp+ECh] [ebp-8Ch]
  float v119; // [esp+F0h] [ebp-88h]
  float v120; // [esp+F4h] [ebp-84h]
  float v121; // [esp+F8h] [ebp-80h]
  float v122; // [esp+FCh] [ebp-7Ch] BYREF
  float v123; // [esp+100h] [ebp-78h]
  float v124; // [esp+104h] [ebp-74h]
  float y; // [esp+108h] [ebp-70h]
  float v126; // [esp+10Ch] [ebp-6Ch]
  float v127; // [esp+110h] [ebp-68h]
  float v128; // [esp+114h] [ebp-64h]
  float v129; // [esp+118h] [ebp-60h]
  vostok::math::float2 v130; // [esp+11Ch] [ebp-5Ch]
  unsigned int v131; // [esp+124h] [ebp-54h]
  float v132; // [esp+128h] [ebp-50h]
  float v133; // [esp+12Ch] [ebp-4Ch]
  float v134; // [esp+134h] [ebp-44h]
  unsigned int index_count; // [esp+138h] [ebp-40h]
  float v136; // [esp+13Ch] [ebp-3Ch]
  unsigned int v_offset; // [esp+140h] [ebp-38h] BYREF
  unsigned int i_offset; // [esp+144h] [ebp-34h] BYREF
  char *v139; // [esp+148h] [ebp-30h]
  float v140; // [esp+14Ch] [ebp-2Ch]
  float v141; // [esp+150h] [ebp-28h]
  int i; // [esp+154h] [ebp-24h]
  float v143; // [esp+158h] [ebp-20h]
  float v144; // [esp+15Ch] [ebp-1Ch]
  float v145; // [esp+160h] [ebp-18h]
  float v146; // [esp+164h] [ebp-14h]
  float v147; // [esp+168h] [ebp-10h]
  float v148; // [esp+16Ch] [ebp-Ch]
  unsigned int v149; // [esp+170h] [ebp-8h]
  char *v150; // [esp+174h] [ebp-4h]

  v3 = *(float *)LODWORD(offset_to_camera[28].y);
  *(float *)&v149 = v3;
  if ( v3 != 0.0 )
  {
    x = offset_to_camera[27].x;
    i_offset = 0;
    v_offset = 0;
    index_count = 6 * LODWORD(v3);
    v5 = vostok::render::index_buffer::lock((vostok::render::index_buffer *)LODWORD(x), &i_offset, 6 * LODWORD(v3));
    v6 = offset_to_camera[24].x;
    v139 = v5;
    v150 = vostok::render::vertex_buffer::lock((vostok::render::vertex_buffer *)LODWORD(v6), &v_offset, 4 * v149, 0x54u);
    v8 = *(_DWORD *)(LODWORD(offset_to_camera[28].y) + 36);
    if ( v8 )
    {
      v9 = 0;
      v99 = 0;
      v91 = 0;
      v95 = 0;
      v87 = 0;
      for ( i = 0; ; v9 = i )
      {
        v10 = *(_DWORD *)(LODWORD(offset_to_camera[29].x) + 12) == 0;
        v11 = *(float *)(v8 + 264);
        v12 = *(float *)(v8 + 268);
        v140 = 0.0;
        v141 = 0.0;
        v143 = 0.0;
        v144 = 0.0;
        v136 = v11;
        v127 = v12;
        v147 = s_bm_current_air_resistance;
        v146 = s_bm_current_air_resistance;
        if ( !v10 )
        {
          v13 = (unsigned __int64)v136;
          v148 = *(float *)(LODWORD(offset_to_camera[29].x) + 12);
          v140 = (float)((unsigned int)v13 % LODWORD(v148));
          v141 = (float)((unsigned int)v13 / LODWORD(v148));
          v14 = (unsigned __int64)v127;
          v149 = (unsigned int)v14 / LODWORD(v148);
          v143 = (float)((unsigned int)v14 % LODWORD(v148));
          v144 = (float)((unsigned int)v14 / LODWORD(v148));
          v149 = *(unsigned int *)(LODWORD(offset_to_camera[29].x) + 16);
          v147 = 1.0 / (double)LODWORD(v148);
          v11 = v136;
          v146 = 1.0 / (double)v149;
        }
        LODWORD(v83) = &v122;
        v122 = v11;
        v148 = modf(v11, v83);
        if ( *(_DWORD *)(LODWORD(offset_to_camera[29].x) + 4) == 3 )
        {
          vostok::particle::base_particle::get_linear_lifetime_impl(
            (vostok::particle::base_particle *)LODWORD(v83),
            v8,
            *(float *)(v8 + 248));
          v15 = *(_DWORD *)(LODWORD(offset_to_camera[29].x) + 20);
          v120 = v11;
          *(float *)&v149 = (double)v15 * v11;
          v16 = vostok::math::floor(*(float *)&v149);
          v17 = *(float *)&v149 - (float)v16;
          v148 = v17;
        }
        else
        {
          v17 = v148;
        }
        v18 = v139;
        *(_WORD *)v139 = v9;
        v18 += 2;
        *(_WORD *)v18 = v9 + 3;
        v18 += 2;
        *(_WORD *)v18 = v9 + 2;
        v18 += 2;
        *(_WORD *)v18 = v9;
        v18 += 2;
        *(_WORD *)v18 = v9 + 2;
        v18 += 2;
        *(_WORD *)v18 = v9 + 1;
        v19 = *(float *)v8;
        v10 = LODWORD(offset_to_camera[31].x) == 0;
        v139 = v18 + 2;
        v20 = offset_to_camera[30].x;
        *(float *)&v21 = *(float *)(LODWORD(v20) + 4) * *(float *)(v8 + 4);
        *(float *)&v22 = *(float *)(LODWORD(v20) + 8) * *(float *)(v8 + 8);
        *(float *)&v23 = *(float *)(LODWORD(v20) + 12) * *(float *)(v8 + 12);
        v129 = v19 * *(float *)LODWORD(v20);
        v24 = *(float *)(v8 + 120);
        v130 = (vostok::math::float2)__PAIR64__(v22, v21);
        v25 = *(float *)(v8 + 116);
        v131 = v23;
        v145 = v25;
        v134 = v24;
        if ( v10 )
        {
          v24 = v25;
          v134 = v25;
        }
        v96 = v17;
        v97 = v147 * v143;
        v121 = v147 * v143;
        v98 = v146 * v144;
        v128 = v146 * v144;
        v82.x = 0.0;
        v82.y = v17;
        v82.z = v147 * v143;
        v82.w = v146 * v144;
        LODWORD(v83) = v99;
        v80.z = v25;
        v81 = (vostok::math::float2)LODWORD(v24);
        v80.x = v147 * v140;
        v78 = v130;
        v133 = v147 * v140;
        v80.y = v146 * v141;
        v26 = *(float *)(v8 + 212);
        v27 = *a3;
        v28 = a3[1];
        v29 = a3[2];
        v30 = *(float *)(v8 + 36);
        v31 = *(float *)(v8 + 40);
        v79 = v131;
        v124 = v146 * v141;
        *(float *)&v110 = *(float *)(v8 + 32) + v27;
        v32 = *(float *)(v8 + 20);
        *((float *)&v110 + 1) = v30 + v28;
        v33 = *(float *)(v8 + 24);
        v111 = v31 + v29;
        v34 = *(float *)(v8 + 28);
        *(_QWORD *)&v76.elements[2] = v110;
        v117 = v32 + v27;
        v76.y = v26;
        v118 = v33 + v28;
        v119 = v34 + v29;
        v72.y = v32 + v27;
        v72.z = v33 + v28;
        v76.x = v34 + v29;
        LODWORD(v72.x) = v150;
        vostok::render::subuv_particle_sprite_vertex::set(
          (vostok::render::subuv_particle_sprite_vertex *)(v9 + 2),
          COERCE_FLOAT((vostok::math::float4 *)&v76.elements[1]),
          v72,
          v76,
          (vostok::math::float2)__PAIR64__(LODWORD(v129), LODWORD(v111)),
          v130,
          v131,
          v80,
          v81,
          v82,
          v99);
        v88 = v148;
        v89 = v121;
        v90 = (float)(v144 + s_bm_current_air_resistance) * v146;
        *(_QWORD *)&v82.x = __PAIR64__(LODWORD(v148), LODWORD(s_bm_current_air_resistance));
        v123 = v90;
        v82.z = v121;
        v82.w = v90;
        v80.z = v145;
        v81 = (vostok::math::float2)LODWORD(v134);
        LODWORD(v83) = v91;
        v80.x = v133;
        v150 += 84;
        v77.y = v129;
        v78 = v130;
        v80.y = (float)(v141 + s_bm_current_air_resistance) * v146;
        v35 = *(float *)(v8 + 212);
        v36 = *a3;
        v37 = a3[1];
        v38 = a3[2];
        v39 = *(float *)(v8 + 32);
        v40 = *(float *)(v8 + 40);
        v79 = v131;
        y = v80.y;
        v41 = *(float *)(v8 + 36);
        v42 = v39 + v36;
        *(float *)&v43 = v36 + *(float *)(v8 + 20);
        *(float *)&v112 = v42;
        v44 = *(float *)(v8 + 24);
        *((float *)&v112 + 1) = v41 + v37;
        v45 = *(float *)(v8 + 28);
        v113 = v40 + v38;
        *(_QWORD *)&v76.elements[2] = v112;
        v77.x = v40 + v38;
        v76.y = v35;
        v105 = v43;
        v106 = v44 + v37;
        v107 = v45 + v38;
        *(_QWORD *)&v73.x = __PAIR64__(v43, (unsigned int)v150);
        v73.z = v44 + v37;
        v76.x = v45 + v38;
        vostok::render::subuv_particle_sprite_vertex::set(
          v46,
          COERCE_FLOAT((vostok::math::float4 *)&v76.elements[1]),
          v73,
          v76,
          v77,
          v130,
          v131,
          v80,
          (vostok::math::float2)LODWORD(v134),
          v82,
          v91);
        v92 = v148;
        v93 = (float)(v143 + s_bm_current_air_resistance) * v147;
        v132 = v93;
        v94 = v123;
        *(_QWORD *)&v82.x = __PAIR64__(LODWORD(v148), LODWORD(s_bm_current_air_resistance));
        v82.z = v93;
        v150 += 84;
        v82.w = v123;
        v81 = (vostok::math::float2)__PAIR64__(LODWORD(s_bm_current_air_resistance), LODWORD(v134));
        LODWORD(v83) = v95;
        v78 = v130;
        v80.x = (float)(v140 + s_bm_current_air_resistance) * v147;
        *(_QWORD *)&v80.elements[1] = __PAIR64__(LODWORD(v145), LODWORD(y));
        v47 = *a3;
        v48 = a3[1];
        v49 = a3[2];
        v50 = *(float *)(v8 + 32);
        v51 = *(float *)(v8 + 40);
        v126 = v80.x;
        v52 = *(float *)(v8 + 36);
        v79 = v131;
        *(float *)&v108 = v50 + v47;
        v53 = *(float *)(v8 + 20);
        *((float *)&v108 + 1) = v52 + v48;
        v54 = *(float *)(v8 + 24);
        v109 = v51 + v49;
        v55 = *(float *)(v8 + 28);
        *(_QWORD *)&v76.elements[2] = v108;
        v100 = v53 + v47;
        v101 = v54 + v48;
        v102 = v55 + v49;
        v77 = (vostok::math::float2)__PAIR64__(LODWORD(v129), LODWORD(v109));
        v76.y = *(float *)(v8 + 212);
        LODWORD(v74.x) = v150;
        v74.y = v53 + v47;
        v74.z = v54 + v48;
        v76.x = v55 + v49;
        vostok::render::subuv_particle_sprite_vertex::set(
          v56,
          COERCE_FLOAT((vostok::math::float4 *)&v76.elements[1]),
          v74,
          v76,
          (vostok::math::float2)__PAIR64__(LODWORD(v129), LODWORD(v109)),
          v130,
          v131,
          v80,
          (vostok::math::float2)__PAIR64__(LODWORD(s_bm_current_air_resistance), LODWORD(v134)),
          v82,
          v95);
        v84 = v148;
        v85 = v132;
        v86 = v128;
        v82.x = 0.0;
        *(_QWORD *)&v82.elements[1] = __PAIR64__(LODWORD(v132), LODWORD(v148));
        v82.w = v128;
        v81 = (vostok::math::float2)__PAIR64__(LODWORD(s_bm_current_air_resistance), LODWORD(v134));
        LODWORD(v83) = v87;
        v80.x = v126;
        v150 += 84;
        *(_QWORD *)&v80.elements[1] = __PAIR64__(LODWORD(v145), LODWORD(v124));
        v57 = *a3;
        v58 = *(float *)(v8 + 32);
        v59 = *(float *)(v8 + 36);
        v60 = *(float *)(v8 + 40);
        v78 = v130;
        *(float *)&v103 = v58 + v57;
        v61 = a3[1];
        v79 = v131;
        *((float *)&v103 + 1) = v59 + v61;
        v62 = a3[2];
        v104 = v60 + v62;
        v63 = *(float *)(v8 + 20);
        *(_QWORD *)&v76.elements[2] = v103;
        *(float *)&v64 = v63 + v57;
        v115 = *(float *)(v8 + 24) + v61;
        v65 = *(float *)(v8 + 28) + v62;
        v114 = v64;
        v116 = v65;
        v77 = (vostok::math::float2)__PAIR64__(LODWORD(v129), LODWORD(v104));
        v76.y = *(float *)(v8 + 212);
        LODWORD(v75.x) = v150;
        *(_QWORD *)&v75.elements[1] = __PAIR64__(LODWORD(v115), v64);
        v76.x = v65;
        vostok::render::subuv_particle_sprite_vertex::set(
          v66,
          COERCE_FLOAT((vostok::math::float4 *)&v76.elements[1]),
          v75,
          v76,
          (vostok::math::float2)__PAIR64__(LODWORD(v129), LODWORD(v104)),
          v130,
          v131,
          v80,
          (vostok::math::float2)__PAIR64__(LODWORD(s_bm_current_air_resistance), LODWORD(v134)),
          v82,
          v87);
        v8 = *(_DWORD *)(v8 + 208);
        v150 += 84;
        i += 4;
        if ( !v8 )
          break;
      }
    }
    vostok::render::vertex_buffer::unlock(v7, (int *)LODWORD(offset_to_camera[24].x));
    v67 = offset_to_camera[27].x;
    v68 = *(vostok::render::untyped_buffer **)(LODWORD(v67) + 16);
    v69 = *(_DWORD *)LODWORD(v67);
    *(_DWORD *)(LODWORD(v67) + 8) += v68;
    vostok::render::untyped_buffer::unmap(v68, v69);
    vostok::render::res_geometry::apply(v70, LODWORD(offset_to_camera[21].x));
    vostok::render::backend::render_indexed(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      index_count,
      v71,
      D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
      i_offset,
      v_offset);
    vostok::quasi_singleton<vostok::render::statistics>::pinst->visibility_stat_group.num_triangles.value += index_count / 3;
  }
}
