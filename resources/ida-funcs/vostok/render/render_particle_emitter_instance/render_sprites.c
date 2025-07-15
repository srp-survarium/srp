void __thiscall vostok::render::render_particle_emitter_instance::render_sprites(
        vostok::render::render_particle_emitter_instance *this,
        const vostok::math::float3 *offset_to_camera,
        float *a3)
{
  int v3; // eax
  float x; // esi
  char *v5; // eax
  float v6; // esi
  vostok::render::vertex_buffer *v7; // ecx
  int v8; // ebx
  __int16 v9; // cx
  char *v10; // eax
  unsigned int v11; // xmm4_4
  bool v12; // zf
  float v13; // eax
  unsigned int v14; // xmm0_4
  unsigned int v15; // xmm1_4
  float v16; // xmm2_4
  unsigned int v17; // xmm3_4
  float v18; // xmm0_4
  unsigned int v19; // xmm1_4
  float v20; // xmm2_4
  unsigned int v21; // xmm1_4
  unsigned int v22; // xmm2_4
  float v23; // xmm0_4
  unsigned int v24; // xmm1_4
  float v25; // xmm2_4
  unsigned int v26; // xmm1_4
  unsigned int v27; // xmm2_4
  float v28; // xmm0_4
  unsigned int v29; // xmm1_4
  float v30; // xmm2_4
  unsigned int v31; // xmm1_4
  unsigned int v32; // xmm2_4
  float v33; // xmm0_4
  unsigned int v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // eax
  vostok::render::untyped_buffer *v37; // ecx
  int v38; // edx
  vostok::render::res_geometry *v39; // ecx
  vostok::render::backend *v40; // ecx
  vostok::math::float3 v41; // [esp-38h] [ebp-E0h]
  vostok::math::float3 v42; // [esp-38h] [ebp-E0h]
  vostok::math::float3 v43; // [esp-38h] [ebp-E0h]
  vostok::render::particle_sprite_vertex v44; // [esp-1Ch] [ebp-C4h] BYREF
  unsigned int v45; // [esp+20h] [ebp-88h]
  unsigned int v46; // [esp+24h] [ebp-84h]
  vostok::math::float3 v47; // [esp+28h] [ebp-80h]
  float v48; // [esp+34h] [ebp-74h]
  unsigned int v49; // [esp+38h] [ebp-70h]
  float v50; // [esp+3Ch] [ebp-6Ch]
  float v51; // [esp+40h] [ebp-68h]
  unsigned int v52; // [esp+44h] [ebp-64h]
  float v53; // [esp+48h] [ebp-60h]
  float v54; // [esp+4Ch] [ebp-5Ch]
  unsigned int v55; // [esp+50h] [ebp-58h]
  float v56; // [esp+54h] [ebp-54h]
  float v57; // [esp+58h] [ebp-50h]
  unsigned int v58; // [esp+5Ch] [ebp-4Ch]
  unsigned int v59; // [esp+60h] [ebp-48h]
  float v60; // [esp+64h] [ebp-44h]
  unsigned int v61; // [esp+68h] [ebp-40h]
  float v62; // [esp+6Ch] [ebp-3Ch]
  vostok::math::float4 v63; // [esp+70h] [ebp-38h]
  unsigned int v64; // [esp+84h] [ebp-24h]
  unsigned int v_offset; // [esp+88h] [ebp-20h] BYREF
  unsigned int i_offset; // [esp+8Ch] [ebp-1Ch] BYREF
  unsigned int index_count; // [esp+90h] [ebp-18h]
  char *v68; // [esp+94h] [ebp-14h]
  unsigned int v69; // [esp+98h] [ebp-10h]
  int i; // [esp+9Ch] [ebp-Ch]
  int v71; // [esp+A0h] [ebp-8h]
  char *v72; // [esp+A4h] [ebp-4h]

  v3 = *(_DWORD *)LODWORD(offset_to_camera[28].y);
  i = v3;
  if ( v3 )
  {
    x = offset_to_camera[27].x;
    i_offset = 0;
    v_offset = 0;
    index_count = 6 * v3;
    v5 = vostok::render::index_buffer::lock((vostok::render::index_buffer *)LODWORD(x), &i_offset, 6 * v3);
    v6 = offset_to_camera[24].x;
    v68 = v5;
    v72 = vostok::render::vertex_buffer::lock((vostok::render::vertex_buffer *)LODWORD(v6), &v_offset, 4 * i, 0x3Cu);
    v8 = *(_DWORD *)(LODWORD(offset_to_camera[28].y) + 36);
    if ( v8 )
    {
      v9 = 0;
      for ( i = 0; ; v9 = i )
      {
        v10 = v68;
        *(_WORD *)v68 = v9;
        v10 += 2;
        *(_WORD *)v10 = v9 + 3;
        v10 += 2;
        *(_WORD *)v10 = v9 + 2;
        v10 += 2;
        *(_WORD *)v10 = v9;
        v10 += 2;
        *(_WORD *)v10 = v9 + 2;
        v10 += 2;
        *(_WORD *)v10 = v9 + 1;
        v11 = *(_DWORD *)(v8 + 116);
        v12 = LODWORD(offset_to_camera[31].x) == 0;
        v68 = v10 + 2;
        v13 = offset_to_camera[30].x;
        *(float *)&v14 = *(float *)LODWORD(v13) * *(float *)v8;
        *(float *)&v15 = *(float *)(LODWORD(v13) + 4) * *(float *)(v8 + 4);
        v16 = *(float *)(LODWORD(v13) + 8) * *(float *)(v8 + 8);
        v63.w = *(float *)(LODWORD(v13) + 12) * *(float *)(v8 + 12);
        v17 = *(_DWORD *)(v8 + 120);
        *(_QWORD *)&v63.x = __PAIR64__(v15, v14);
        v63.z = v16;
        v69 = v11;
        v64 = v17;
        if ( v12 )
        {
          v17 = v11;
          v64 = v11;
        }
        v18 = *a3;
        v71 = *(int *)(v8 + 212);
        *(float *)&v19 = *(float *)(v8 + 36) + a3[1];
        v20 = *(float *)(v8 + 40) + a3[2];
        v48 = v18 + *(float *)(v8 + 32);
        v49 = v19;
        v50 = v20;
        *(_QWORD *)&v44.color.elements[1] = __PAIR64__(v19, LODWORD(v48));
        *(_QWORD *)&v44.position.elements[2] = __PAIR64__(v17, v11);
        v44.color.w = v20;
        *(_QWORD *)&v44.position.x = 0;
        *(float *)&v21 = *(float *)(v8 + 24) + a3[1];
        *(float *)&v22 = *(float *)(v8 + 28) + a3[2];
        v44.rotation = *a3 + *(float *)(v8 + 20);
        *(_QWORD *)&v44.old_position.x = __PAIR64__(v22, v21);
        v41.x = v44.rotation;
        *(_QWORD *)&v41.elements[1] = __PAIR64__(v22, v21);
        vostok::render::particle_sprite_vertex::set(
          &v44,
          (int)v72,
          v71,
          v41,
          v63,
          0,
          (vostok::math::float2)__PAIR64__(v17, v11),
          v48,
          *(struct vostok::math::float3 *)&v44.color.elements[2]);
        v72 += 60;
        v23 = *a3;
        v71 = *(int *)(v8 + 212);
        *(float *)&v24 = *(float *)(v8 + 36) + a3[1];
        v25 = *(float *)(v8 + 40) + a3[2];
        v54 = v23 + *(float *)(v8 + 32);
        v55 = v24;
        v56 = v25;
        *(_QWORD *)&v44.color.elements[1] = __PAIR64__(v24, LODWORD(v54));
        *(_QWORD *)&v44.position.elements[2] = __PAIR64__(v64, v69);
        v44.color.w = v25;
        v44.position.x = 0.0;
        v44.position.y = s_bm_current_air_resistance;
        *(float *)&v26 = *(float *)(v8 + 24) + a3[1];
        *(float *)&v27 = *(float *)(v8 + 28) + a3[2];
        v44.old_position.z = *(float *)(v8 + 20) + *a3;
        v45 = v26;
        v46 = v27;
        v42.x = v44.old_position.z;
        *(_QWORD *)&v42.elements[1] = __PAIR64__(v27, v26);
        vostok::render::particle_sprite_vertex::set(
          &v44,
          (int)v72,
          v71,
          v42,
          v63,
          *(vostok::math::float2 *)&v44.position.x,
          (vostok::math::float2)__PAIR64__(v64, v69),
          v54,
          *(struct vostok::math::float3 *)&v44.color.elements[2]);
        v28 = *(float *)(v8 + 32) + *a3;
        v71 = *(int *)(v8 + 212);
        *(float *)&v29 = *(float *)(v8 + 36) + a3[1];
        v30 = *(float *)(v8 + 40) + a3[2];
        v60 = v28;
        v61 = v29;
        v62 = v30;
        v72 += 60;
        *(_QWORD *)&v44.position.elements[2] = __PAIR64__(v64, v69);
        *(_QWORD *)&v44.color.elements[1] = __PAIR64__(v29, LODWORD(v28));
        v44.color.w = v30;
        v44.position.x = s_bm_current_air_resistance;
        v44.position.y = s_bm_current_air_resistance;
        *(float *)&v31 = *(float *)(v8 + 24) + a3[1];
        *(float *)&v32 = *(float *)(v8 + 28) + a3[2];
        v57 = *a3 + *(float *)(v8 + 20);
        v58 = v31;
        v59 = v32;
        v43.x = v57;
        *(_QWORD *)&v43.elements[1] = __PAIR64__(v32, v31);
        vostok::render::particle_sprite_vertex::set(
          &v44,
          (int)v72,
          v71,
          v43,
          v63,
          *(vostok::math::float2 *)&v44.position.x,
          (vostok::math::float2)__PAIR64__(v64, v69),
          v28,
          *(struct vostok::math::float3 *)&v44.color.elements[2]);
        v33 = *a3 + *(float *)(v8 + 32);
        v71 = *(int *)(v8 + 212);
        *(float *)&v34 = *(float *)(v8 + 36) + a3[1];
        v35 = *(float *)(v8 + 40) + a3[2];
        v51 = v33;
        *(_QWORD *)&v44.position.elements[2] = __PAIR64__(v64, v69);
        v52 = v34;
        v53 = v35;
        *(_QWORD *)&v44.color.elements[1] = __PAIR64__(v34, LODWORD(v33));
        v44.color.w = v35;
        v72 += 60;
        *(_QWORD *)&v44.position.x = LODWORD(s_bm_current_air_resistance);
        v47.x = *(float *)(v8 + 20) + *a3;
        v47.y = *(float *)(v8 + 24) + a3[1];
        v47.z = *(float *)(v8 + 28) + a3[2];
        vostok::render::particle_sprite_vertex::set(
          &v44,
          (int)v72,
          v71,
          v47,
          v63,
          (vostok::math::float2)LODWORD(s_bm_current_air_resistance),
          (vostok::math::float2)__PAIR64__(v64, v69),
          v33,
          *(struct vostok::math::float3 *)&v44.color.elements[2]);
        v8 = *(_DWORD *)(v8 + 208);
        v72 += 60;
        i += 4;
        if ( !v8 )
          break;
      }
    }
    vostok::render::vertex_buffer::unlock(v7, (int *)LODWORD(offset_to_camera[24].x));
    v36 = offset_to_camera[27].x;
    v37 = *(vostok::render::untyped_buffer **)(LODWORD(v36) + 16);
    v38 = *(_DWORD *)LODWORD(v36);
    *(_DWORD *)(LODWORD(v36) + 8) += v37;
    vostok::render::untyped_buffer::unmap(v37, v38);
    vostok::render::res_geometry::apply(v39, LODWORD(offset_to_camera[20].z));
    vostok::render::backend::render_indexed(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      index_count,
      v40,
      D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
      i_offset,
      v_offset);
    vostok::quasi_singleton<vostok::render::statistics>::pinst->visibility_stat_group.num_triangles.value += index_count / 3;
  }
}
