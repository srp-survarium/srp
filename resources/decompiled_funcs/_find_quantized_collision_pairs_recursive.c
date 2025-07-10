void __cdecl find_quantized_collision_pairs_recursive(
        btGImpactQuantizedBvh *boxset0,
        btGImpactQuantizedBvh *boxset1,
        btPairSet *collision_pairs,
        const BT_BOX_BOX_TRANSFORM_CACHE *trans_cache_1to0,
        int node0,
        int node1,
        bool complete_primitive_tests)
{
  btGImpactQuantizedBvh *v7; // ebx
  BT_QUANTIZED_BVH_NODE *m_data; // edx
  btGImpactQuantizedBvh *v9; // esi
  float v10; // xmm3_4
  int v11; // ecx
  unsigned __int16 *m_quantizedAabbMin; // eax
  float v13; // xmm6_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  int v16; // ecx
  float v17; // xmm2_4
  int v18; // edx
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  BT_QUANTIZED_BVH_NODE *v22; // ecx
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm3_4
  int v26; // edx
  unsigned __int16 *v27; // eax
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  int v32; // edx
  float v33; // xmm6_4
  int v34; // ecx
  float v35; // xmm5_4
  int v36; // edx
  float v37; // xmm3_4
  int v38; // eax
  float v39; // xmm3_4
  float v40; // xmm4_4
  float v41; // xmm5_4
  float v42; // xmm6_4
  __m128i v43; // xmm0
  float v44; // xmm0_4
  float v45; // xmm1_4
  float v46; // xmm2_4
  __m128i v47; // xmm3
  float *v48; // eax
  long double v49; // st7
  int v50; // eax
  long double v51; // st7
  int v52; // ecx
  int v53; // ebx
  int v54; // esi
  BOOL v55; // edx
  BOOL v56; // eax
  float v57; // xmm0_4
  int v58; // ecx
  float v59; // xmm0_4
  float *m128_f32; // esi
  float *v61; // ebx
  long double v62; // st7
  int v63; // eax
  int v64; // ecx
  bool v65; // sf
  int v66; // eax
  int v67; // ecx
  int m_escapeIndexOrDataIndex; // ecx
  int v69; // eax
  int v70; // ecx
  int v71; // eax
  int v72; // eax
  int v73; // ecx
  int v74; // edx
  int v75; // eax
  float _X; // [esp+0h] [ebp-114h]
  int v77; // [esp+4h] [ebp-110h] BYREF
  int v78; // [esp+10h] [ebp-104h]
  btVector3 *v79; // [esp+14h] [ebp-100h]
  int v80; // [esp+18h] [ebp-FCh]
  int v81; // [esp+1Ch] [ebp-F8h]
  int v82; // [esp+20h] [ebp-F4h]
  int v83; // [esp+24h] [ebp-F0h]
  btVector3 *v84; // [esp+28h] [ebp-ECh]
  unsigned __int16 *v85; // [esp+2Ch] [ebp-E8h]
  BOOL v86; // [esp+30h] [ebp-E4h]
  __m128i v87; // [esp+34h] [ebp-E0h] BYREF
  float v88; // [esp+4Ch] [ebp-C8h]
  float v89; // [esp+50h] [ebp-C4h]
  float v90; // [esp+54h] [ebp-C0h]
  int v91; // [esp+58h] [ebp-BCh]
  unsigned __int16 *v92; // [esp+5Ch] [ebp-B8h]
  float v93; // [esp+60h] [ebp-B4h]
  __m128i v94; // [esp+64h] [ebp-B0h] BYREF
  int v95; // [esp+7Ch] [ebp-98h]
  float v96; // [esp+80h] [ebp-94h]
  float v97; // [esp+84h] [ebp-90h]
  float v98; // [esp+88h] [ebp-8Ch]
  float v99; // [esp+8Ch] [ebp-88h]
  float v100[4]; // [esp+94h] [ebp-80h]
  float v101; // [esp+A4h] [ebp-70h]
  float v102; // [esp+A8h] [ebp-6Ch]
  float v103; // [esp+ACh] [ebp-68h]
  float v104; // [esp+B4h] [ebp-60h]
  float v105; // [esp+B8h] [ebp-5Ch]
  float v106; // [esp+BCh] [ebp-58h]
  float v107; // [esp+C4h] [ebp-50h]
  float v108; // [esp+C8h] [ebp-4Ch]
  float v109; // [esp+CCh] [ebp-48h]
  __m128i v110; // [esp+D4h] [ebp-40h] BYREF
  __m128i v111; // [esp+E4h] [ebp-30h]
  __m128i v112; // [esp+F4h] [ebp-20h]
  __m128i v113; // [esp+104h] [ebp-10h] BYREF

  v110.m128i_i32[3] = 0;
  v87.m128i_i32[3] = 0;
  v94.m128i_i32[3] = 0;
  v95 = (char *)trans_cache_1to0 - (char *)&v113;
LABEL_2:
  v7 = boxset0;
  m_data = boxset0->m_box_tree.m_node_array.m_data;
  v9 = boxset1;
  v10 = boxset0->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[0];
  v11 = m_data[node0].m_quantizedAabbMin[0];
  v83 = 16 * node0;
  m_quantizedAabbMin = m_data[node0].m_quantizedAabbMin;
  v13 = boxset1->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[0];
  v14 = v10 + (float)((float)v11 / boxset0->m_box_tree.m_bvhQuantization.mVec128.m128_f32[0]);
  v15 = boxset0->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1]
      + (float)((float)m_quantizedAabbMin[1] / boxset0->m_box_tree.m_bvhQuantization.mVec128.m128_f32[1]);
  v16 = m_quantizedAabbMin[4];
  v17 = (float)m_quantizedAabbMin[2] / boxset0->m_box_tree.m_bvhQuantization.mVec128.m128_f32[2];
  v18 = m_quantizedAabbMin[5];
  v19 = (float)m_quantizedAabbMin[3] / boxset0->m_box_tree.m_bvhQuantization.mVec128.m128_f32[0];
  v97 = v14;
  v92 = m_quantizedAabbMin;
  v98 = v15;
  v20 = boxset0->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2] + v17;
  v21 = (float)v16;
  v22 = boxset1->m_box_tree.m_node_array.m_data;
  v23 = v21 / boxset0->m_box_tree.m_bvhQuantization.mVec128.m128_f32[1];
  v99 = v20;
  v24 = boxset0->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[0];
  v25 = (float)v18 / boxset0->m_box_tree.m_bvhQuantization.mVec128.m128_f32[2];
  v26 = v22[node1].m_quantizedAabbMin[0];
  v82 = 16 * node1;
  v27 = v22[node1].m_quantizedAabbMin;
  v28 = v24 + v19;
  v29 = boxset0->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1] + v23;
  v30 = boxset0->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2] + v25;
  v31 = (float)v26 / boxset1->m_box_tree.m_bvhQuantization.mVec128.m128_f32[0];
  v32 = v27[2];
  v33 = v13 + v31;
  v34 = v27[3];
  v105 = boxset1->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1]
       + (float)((float)v27[1] / boxset1->m_box_tree.m_bvhQuantization.mVec128.m128_f32[1]);
  v35 = (float)v32 / boxset1->m_box_tree.m_bvhQuantization.mVec128.m128_f32[2];
  v36 = v27[4];
  v37 = boxset1->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2] + v35;
  v85 = v27;
  v38 = v27[5];
  v106 = v37;
  v39 = (float)((float)v34 / boxset1->m_box_tree.m_bvhQuantization.mVec128.m128_f32[0])
      + boxset1->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[0];
  v40 = (float)((float)v36 / boxset1->m_box_tree.m_bvhQuantization.mVec128.m128_f32[1])
      + boxset1->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1];
  v41 = (float)((float)v38 / boxset1->m_box_tree.m_bvhQuantization.mVec128.m128_f32[2])
      + boxset1->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2];
  v104 = v33;
  v107 = v39;
  v108 = v40;
  v109 = v41;
  *(float *)&v110.m128i_i32[1] = (float)(v29 + v98) * 0.5;
  v42 = (float)(v28 + v97) * 0.5;
  *(float *)&v110.m128i_i32[2] = (float)(v30 + v99) * 0.5;
  *(float *)v87.m128i_i32 = v28 - v42;
  *(float *)&v87.m128i_i32[1] = v29 - *(float *)&v110.m128i_i32[1];
  *(float *)&v87.m128i_i32[2] = v30 - *(float *)&v110.m128i_i32[2];
  v43 = _mm_load_si128(&v87);
  *(float *)v110.m128i_i32 = v42;
  v113 = _mm_load_si128(&v110);
  v112 = v43;
  v44 = (float)(v39 + v104) * 0.5;
  v45 = (float)(v40 + v105) * 0.5;
  v46 = (float)(v41 + v106) * 0.5;
  *(float *)v94.m128i_i32 = v39 - v44;
  *(float *)&v94.m128i_i32[1] = v40 - v45;
  *(float *)&v94.m128i_i32[2] = v41 - v46;
  v47 = _mm_load_si128(&v94);
  v48 = &trans_cache_1to0->m_R1to0.m_el[0].mVec128.m128_f32[2];
  v101 = (float)(v107 + v104) * 0.5;
  v102 = v45;
  v103 = v46;
  v111 = v47;
  v78 = (int)&trans_cache_1to0->m_R1to0.m_el[0].mVec128.m128_i32[2];
  v79 = 0;
  while ( 1 )
  {
    v88 = (float)((float)((float)((float)(*(v48 - 2) * v44) + (float)(*(v48 - 1) * v45))
                        + *(float *)((char *)v113.m128i_i32 + (_DWORD)v79 + v95))
                + (float)(v46 * *v48))
        - *(float *)((char *)v113.m128i_i32 + (_DWORD)v79);
    _X = v88;
    *(float *)((char *)v100 + (_DWORD)v79) = v88;
    v49 = fabsf(_X);
    if ( v49 > *(float *)(v78 + 40) * *(float *)v94.m128i_i32
             + *(float *)(v78 + 48) * *(float *)&v94.m128i_i32[2]
             + *(float *)(v78 + 44) * *(float *)&v94.m128i_i32[1]
             + *(float *)((char *)v112.m128i_i32 + (_DWORD)v79) )
      break;
    v78 += 16;
    v79 = (btVector3 *)((char *)v79 + 4);
    if ( (int)v79 >= 12 )
    {
      v50 = 32;
      v78 = 32;
      v80 = (int)(&v77 + 48);
      while ( 1 )
      {
        v51 = fabsf(
                (float)((float)(*(float *)((char *)trans_cache_1to0->m_T1to0.mVec128.m128_f32 + v50) * v100[1])
                      + (float)(*(float *)((char *)trans_cache_1to0->m_R1to0.m_el[0].mVec128.m128_f32 + v50) * v100[2]))
              + (float)(*(float *)((char *)&trans_cache_1to0->m_T1to0.mVec128.m128_f32[-4] + v50) * v100[0]));
        if ( v51 > *(float *)((char *)trans_cache_1to0->m_R1to0.m_el[2].mVec128.m128_f32 + v78)
                 * *(float *)&v87.m128i_i32[1]
                 + *(float *)((char *)trans_cache_1to0->m_AR.m_el[0].mVec128.m128_f32 + v78)
                 * *(float *)&v87.m128i_i32[2]
                 + *(float *)((char *)trans_cache_1to0->m_R1to0.m_el[1].mVec128.m128_f32 + v78)
                 * *(float *)v87.m128i_i32
                 + *(float *)(v80 + v78) )
          return;
        v78 += 4;
        if ( v78 >= 44 )
        {
          if ( complete_primitive_tests )
          {
            v52 = 0;
            v81 = 0;
            v80 = 16;
LABEL_13:
            v53 = (v52 + 1) % 3;
            v54 = (v52 + 2) % 3;
            v55 = v52 == 0;
            v56 = v52 != 2;
            v96 = v100[v54];
            v93 = v100[v53];
            v57 = *(float *)&v112.m128i_i32[v56 + 1];
            v84 = &trans_cache_1to0->m_AR.m_el[v56 + 1];
            v58 = 0;
            v90 = v57;
            v59 = *(float *)&v112.m128i_i32[v55];
            m128_f32 = trans_cache_1to0->m_R1to0.m_el[v54].mVec128.m128_f32;
            v78 = 0;
            v89 = v59;
            v79 = &trans_cache_1to0->m_AR.m_el[v55];
            v61 = trans_cache_1to0->m_R1to0.m_el[v53].mVec128.m128_f32;
            while ( 1 )
            {
              _X = (float)(v96 * *v61) - (float)(v93 * *m128_f32);
              v91 = (v58 != 2) + 1;
              v86 = v58 == 0;
              v62 = fabsf(_X);
              if ( v62 > trans_cache_1to0->m_T1to0.mVec128.m128_f32[v80 + v91] * *(float *)&v111.m128i_i32[v86]
                       + trans_cache_1to0->m_T1to0.mVec128.m128_f32[v86 + v80] * *(float *)&v111.m128i_i32[v91]
                       + v89 * v84->mVec128.m128_f32[0]
                       + v90 * v79->mVec128.m128_f32[0] )
                return;
              v79 = (btVector3 *)((char *)v79 + 4);
              v84 = (btVector3 *)((char *)v84 + 4);
              ++v61;
              ++m128_f32;
              if ( ++v78 >= 3 )
              {
                ++v81;
                v80 += 4;
                if ( v80 < 28 )
                {
                  v52 = v81;
                  goto LABEL_13;
                }
                v7 = boxset0;
                v9 = boxset1;
                break;
              }
              v58 = v78;
            }
          }
          if ( *((int *)v92 + 3) < 0 )
          {
            v65 = *((int *)v85 + 3) < 0;
            _X = 0.0;
            if ( v65 )
            {
              find_quantized_collision_pairs_recursive(
                v7,
                v9,
                collision_pairs,
                trans_cache_1to0,
                node0 + 1,
                node1 + 1,
                SLOBYTE(_X));
              m_escapeIndexOrDataIndex = v9->m_box_tree.m_node_array.m_data[v82 / 0x10u + 1].m_escapeIndexOrDataIndex;
              if ( m_escapeIndexOrDataIndex < 0 )
                v69 = node1 - m_escapeIndexOrDataIndex + 1;
              else
                v69 = node1 + 2;
              find_quantized_collision_pairs_recursive(v7, v9, collision_pairs, trans_cache_1to0, node0 + 1, v69, 0);
              v70 = v7->m_box_tree.m_node_array.m_data[v83 / 0x10u + 1].m_escapeIndexOrDataIndex;
              if ( v70 < 0 )
                v71 = node0 - v70 + 1;
              else
                v71 = node0 + 2;
              find_quantized_collision_pairs_recursive(v7, v9, collision_pairs, trans_cache_1to0, v71, node1 + 1, 0);
              v72 = v9->m_box_tree.m_node_array.m_data[v82 / 0x10u + 1].m_escapeIndexOrDataIndex;
              if ( v72 < 0 )
                v73 = node1 - v72 + 1;
              else
                v73 = node1 + 2;
              v74 = v7->m_box_tree.m_node_array.m_data[v83 / 0x10u + 1].m_escapeIndexOrDataIndex;
              if ( v74 < 0 )
                v75 = node0 - v74 + 1;
              else
                v75 = node0 + 2;
              complete_primitive_tests = 0;
              node1 = v73;
              node0 = v75;
            }
            else
            {
              find_quantized_collision_pairs_recursive(
                v7,
                v9,
                collision_pairs,
                trans_cache_1to0,
                node0 + 1,
                node1,
                SLOBYTE(_X));
              v66 = v7->m_box_tree.m_node_array.m_data[v83 / 0x10u + 1].m_escapeIndexOrDataIndex;
              if ( v66 < 0 )
                v67 = node0 - v66 + 1;
              else
                v67 = node0 + 2;
              complete_primitive_tests = 0;
              node0 = v67;
            }
          }
          else
          {
            if ( *((int *)v85 + 3) >= 0 )
            {
              btPairSet::push_pair(
                (btPairSet *)v7->m_box_tree.m_node_array.m_data,
                (int)collision_pairs,
                v7->m_box_tree.m_node_array.m_data[node0].m_escapeIndexOrDataIndex,
                v9->m_box_tree.m_node_array.m_data[node1].m_escapeIndexOrDataIndex);
              return;
            }
            find_quantized_collision_pairs_recursive(v7, v9, collision_pairs, trans_cache_1to0, node0, node1 + 1, 0);
            v63 = v9->m_box_tree.m_node_array.m_data[v82 / 0x10u + 1].m_escapeIndexOrDataIndex;
            if ( v63 < 0 )
              v64 = node1 - v63 + 1;
            else
              v64 = node1 + 2;
            complete_primitive_tests = 0;
            node1 = v64;
          }
          goto LABEL_2;
        }
        v50 = v78;
      }
    }
    v46 = v103;
    v45 = v102;
    v44 = v101;
    v48 = (float *)v78;
  }
}
