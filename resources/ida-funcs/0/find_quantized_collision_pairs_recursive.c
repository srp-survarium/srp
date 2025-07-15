void __cdecl find_quantized_collision_pairs_recursive(
        btGImpactQuantizedBvh *boxset0,
        btGImpactQuantizedBvh *boxset1,
        btPairSet *collision_pairs,
        const BT_BOX_BOX_TRANSFORM_CACHE *trans_cache_1to0,
        int node0,
        int node1,
        bool complete_primitive_tests)
{
  BT_QUANTIZED_BVH_NODE *m_data; // edx
  float v8; // xmm7_4
  unsigned __int16 *m_quantizedAabbMin; // eax
  float v10; // xmm2_4
  float v11; // xmm7_4
  float v12; // xmm0_4
  int v13; // edx
  float v14; // xmm1_4
  float v15; // xmm6_4
  int v16; // eax
  float v17; // xmm0_4
  float v18; // xmm2_4
  BT_QUANTIZED_BVH_NODE *v19; // edx
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  BT_QUANTIZED_BVH_NODE *v24; // eax
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm6_4
  int v28; // edx
  float v29; // xmm5_4
  int v30; // edx
  float v31; // xmm3_4
  int v32; // edx
  float v33; // xmm4_4
  float v34; // xmm5_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float *v38; // esi
  int v39; // edx
  float v40; // xmm3_4
  btVector3 *v41; // edx
  float v42; // xmm5_4
  float v43; // xmm6_4
  int v44; // edx
  int v45; // esi
  float v46; // xmm1_4
  int v47; // edi
  float v48; // xmm0_4
  BOOL v49; // eax
  float v50; // xmm2_4
  float v51; // xmm3_4
  float *m128_f32; // edi
  float *v53; // esi
  float v54; // xmm5_4
  int v55; // eax
  int v56; // ecx
  bool v57; // sf
  int v58; // eax
  int v59; // ecx
  unsigned int v60; // edi
  int m_escapeIndexOrDataIndex; // eax
  int v62; // ecx
  int v63; // ecx
  int v64; // eax
  int v65; // edi
  int v66; // eax
  int v67; // edx
  BOOL v68; // [esp-10h] [ebp-F4h]
  int v69; // [esp-Ch] [ebp-F0h] BYREF
  btVector3 *v70; // [esp+8h] [ebp-DCh]
  int v71; // [esp+Ch] [ebp-D8h]
  int v72; // [esp+10h] [ebp-D4h]
  int v73; // [esp+14h] [ebp-D0h]
  int v74; // [esp+18h] [ebp-CCh]
  int v75; // [esp+1Ch] [ebp-C8h]
  unsigned int v76; // [esp+20h] [ebp-C4h]
  float *v77; // [esp+24h] [ebp-C0h]
  unsigned int v78; // [esp+28h] [ebp-BCh]
  BT_QUANTIZED_BVH_NODE *v79; // [esp+2Ch] [ebp-B8h]
  BOOL v80; // [esp+30h] [ebp-B4h]
  float v81; // [esp+34h] [ebp-B0h]
  float v82; // [esp+38h] [ebp-ACh]
  float v83; // [esp+3Ch] [ebp-A8h]
  float v84; // [esp+40h] [ebp-A4h]
  int v85; // [esp+50h] [ebp-94h]
  float v86; // [esp+54h] [ebp-90h]
  float v87; // [esp+58h] [ebp-8Ch]
  float v88; // [esp+5Ch] [ebp-88h]
  float v89; // [esp+60h] [ebp-84h]
  float v90[5]; // [esp+64h] [ebp-80h]
  float v91; // [esp+78h] [ebp-6Ch]
  float v92; // [esp+7Ch] [ebp-68h]
  float v93; // [esp+84h] [ebp-60h]
  float v94; // [esp+88h] [ebp-5Ch]
  float v95; // [esp+8Ch] [ebp-58h]
  float v96; // [esp+90h] [ebp-54h]
  float v97; // [esp+94h] [ebp-50h]
  float v98; // [esp+98h] [ebp-4Ch]
  float v99; // [esp+A4h] [ebp-40h]
  float v100[3]; // [esp+A8h] [ebp-3Ch]
  float v101[5]; // [esp+B4h] [ebp-30h]
  float v102; // [esp+C8h] [ebp-1Ch]
  float v103; // [esp+CCh] [ebp-18h]
  float v104[4]; // [esp+D4h] [ebp-10h] BYREF

  v96 = 0.0;
  v89 = 0.0;
  v84 = 0.0;
  v85 = (char *)trans_cache_1to0 - (char *)v104;
LABEL_2:
  m_data = boxset0->m_box_tree.m_node_array.m_data;
  v8 = boxset0->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[0];
  v76 = 16 * node0;
  m_quantizedAabbMin = m_data[node0].m_quantizedAabbMin;
  v10 = (float)m_quantizedAabbMin[2] / boxset0->m_box_tree.m_bvhQuantization.mVec128.m128_f32[2];
  v11 = v8 + (float)((float)*m_quantizedAabbMin / boxset0->m_box_tree.m_bvhQuantization.mVec128.m128_f32[0]);
  v12 = boxset0->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1]
      + (float)((float)m_quantizedAabbMin[1] / boxset0->m_box_tree.m_bvhQuantization.mVec128.m128_f32[1]);
  v13 = m_quantizedAabbMin[4];
  v14 = (float)m_quantizedAabbMin[3] / boxset0->m_box_tree.m_bvhQuantization.mVec128.m128_f32[0];
  v15 = boxset1->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[0];
  v75 = (int)m_quantizedAabbMin;
  v16 = m_quantizedAabbMin[5];
  v102 = v12;
  v17 = boxset0->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2] + v10;
  v18 = (float)v13;
  v19 = boxset1->m_box_tree.m_node_array.m_data;
  v20 = v18 / boxset0->m_box_tree.m_bvhQuantization.mVec128.m128_f32[1];
  v21 = (float)v16 / boxset0->m_box_tree.m_bvhQuantization.mVec128.m128_f32[2];
  v103 = v17;
  v22 = boxset0->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[0] + v14;
  v23 = boxset0->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1];
  v78 = 16 * node1;
  v24 = &v19[node1];
  v25 = v23 + v20;
  v26 = boxset0->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2] + v21;
  v27 = v15 + (float)((float)v24->m_quantizedAabbMin[0] / boxset1->m_box_tree.m_bvhQuantization.mVec128.m128_f32[0]);
  v28 = v24->m_quantizedAabbMin[2];
  v91 = boxset1->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1]
      + (float)((float)v24->m_quantizedAabbMin[1] / boxset1->m_box_tree.m_bvhQuantization.mVec128.m128_f32[1]);
  v29 = (float)v28 / boxset1->m_box_tree.m_bvhQuantization.mVec128.m128_f32[2];
  v30 = v24->m_quantizedAabbMax[0];
  v92 = boxset1->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2] + v29;
  v31 = (float)((float)v30 / boxset1->m_box_tree.m_bvhQuantization.mVec128.m128_f32[0])
      + boxset1->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[0];
  v32 = v24->m_quantizedAabbMax[2];
  v33 = (float)((float)v24->m_quantizedAabbMax[1] / boxset1->m_box_tree.m_bvhQuantization.mVec128.m128_f32[1])
      + boxset1->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1];
  v90[4] = v27;
  v97 = v31;
  v34 = (float)((float)v32 / boxset1->m_box_tree.m_bvhQuantization.mVec128.m128_f32[2])
      + boxset1->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2];
  v79 = v24;
  v98 = v33;
  v94 = (float)(v25 + v102) * 0.5;
  v95 = (float)(v26 + v103) * 0.5;
  v93 = (float)(v22 + v11) * 0.5;
  v104[0] = v93;
  v104[1] = v94;
  v104[2] = v95;
  v104[3] = v96;
  v87 = v25 - v94;
  v88 = v26 - v95;
  v86 = v22 - v93;
  v99 = v22 - v93;
  v100[0] = v25 - v94;
  v100[1] = v26 - v95;
  v100[2] = v89;
  v35 = (float)(v31 + v27) * 0.5;
  v36 = (float)(v33 + v91) * 0.5;
  v37 = (float)(v34 + v92) * 0.5;
  v81 = v31 - v35;
  v82 = v33 - v36;
  v83 = v34 - v37;
  v101[0] = v31 - v35;
  v101[1] = v33 - v36;
  v101[2] = v34 - v37;
  v101[3] = v84;
  v38 = &trans_cache_1to0->m_R1to0.m_el[0].mVec128.m128_f32[2];
  v39 = 0;
  v70 = 0;
  while ( 1 )
  {
    v40 = (float)((float)((float)((float)(*(v38 - 2) * v35) + (float)(*(v38 - 1) * v36))
                        + *(float *)((char *)v104 + v39 + v85))
                + (float)(v37 * *v38))
        - *(float *)((char *)v104 + v39);
    v41 = v70;
    v42 = (float)(v38[10] * v81) + (float)(v38[12] * v83);
    v43 = v38[11] * v82;
    *(float *)((char *)v90 + (_DWORD)v70) = v40;
    if ( COERCE_FLOAT(LODWORD(v40) & _mask__AbsFloat_) > (float)((float)(v42 + v43)
                                                               + *(float *)((char *)&v100[-1] + (_DWORD)v41)) )
      break;
    v39 = (int)&v41->mVec128.m128_i32[1];
    v38 += 4;
    v70 = (btVector3 *)v39;
    if ( v39 >= 12 )
    {
      v44 = 8;
      while ( COERCE_FLOAT(
                COERCE_UNSIGNED_INT(
                  (float)((float)(trans_cache_1to0->m_T1to0.mVec128.m128_f32[v44 - 4] * v90[0])
                        + (float)(trans_cache_1to0->m_T1to0.mVec128.m128_f32[v44] * v90[1]))
                + (float)(trans_cache_1to0->m_R1to0.m_el[0].mVec128.m128_f32[v44] * v90[2]))
              & _mask__AbsFloat_) <= (float)((float)((float)((float)(trans_cache_1to0->m_AR.m_el[0].mVec128.m128_f32[v44]
                                                                   * v88)
                                                           + (float)(trans_cache_1to0->m_R1to0.m_el[1].mVec128.m128_f32[v44]
                                                                   * v86))
                                                   + (float)(trans_cache_1to0->m_R1to0.m_el[2].mVec128.m128_f32[v44]
                                                           * v87))
                                           + *(float *)((char *)&v69 + v44 * 4 + 160)) )
      {
        if ( ++v44 >= 11 )
        {
          if ( complete_primitive_tests )
          {
            v72 = 0;
            v71 = 16;
LABEL_10:
            v45 = (v72 + 1) % 3;
            v46 = v90[v45];
            v47 = (v72 + 2) % 3;
            v48 = v90[v47];
            v49 = v72 != 2;
            v50 = v100[v49];
            v73 = 0;
            v51 = v100[(v72 == 0) - 1];
            v74 = v72 == 0;
            v70 = &trans_cache_1to0->m_AR.m_el[v49 + 1];
            m128_f32 = trans_cache_1to0->m_R1to0.m_el[v47].mVec128.m128_f32;
            v77 = trans_cache_1to0->m_AR.m_el[v74].mVec128.m128_f32;
            v53 = trans_cache_1to0->m_R1to0.m_el[v45].mVec128.m128_f32;
            while ( 1 )
            {
              v54 = (float)(v48 * *v53) - (float)(v46 * *m128_f32);
              v74 = (v73 != 2) + 1;
              v80 = v73 == 0;
              if ( COERCE_FLOAT(LODWORD(v54) & _mask__AbsFloat_) > (float)((float)((float)((float)(trans_cache_1to0->m_T1to0.mVec128.m128_f32[v74 + v71]
                                                                                                 * v101[v80])
                                                                                         + (float)(trans_cache_1to0->m_T1to0.mVec128.m128_f32[v80 + v71]
                                                                                                 * v101[v74]))
                                                                                 + (float)(v51 * v70->mVec128.m128_f32[0]))
                                                                         + (float)(v50 * *v77)) )
                return;
              ++v73;
              ++v77;
              v70 = (btVector3 *)((char *)v70 + 4);
              ++v53;
              ++m128_f32;
              if ( v73 >= 3 )
              {
                v71 += 4;
                ++v72;
                if ( v71 < 28 )
                  goto LABEL_10;
                v24 = v79;
                break;
              }
            }
          }
          if ( *(int *)(v75 + 12) < 0 )
          {
            v57 = v24->m_escapeIndexOrDataIndex < 0;
            v68 = 0;
            if ( v57 )
            {
              v75 = node1 + 1;
              find_quantized_collision_pairs_recursive(
                boxset0,
                boxset1,
                collision_pairs,
                trans_cache_1to0,
                node0 + 1,
                node1 + 1,
                v68);
              v60 = v78;
              m_escapeIndexOrDataIndex = boxset1->m_box_tree.m_node_array.m_data[v78 / 0x10 + 1].m_escapeIndexOrDataIndex;
              if ( m_escapeIndexOrDataIndex < 0 )
                v62 = node1 - m_escapeIndexOrDataIndex + 1;
              else
                v62 = node1 + 2;
              find_quantized_collision_pairs_recursive(
                boxset0,
                boxset1,
                collision_pairs,
                trans_cache_1to0,
                node0 + 1,
                v62,
                0);
              v63 = boxset0->m_box_tree.m_node_array.m_data[v76 / 0x10 + 1].m_escapeIndexOrDataIndex;
              if ( v63 < 0 )
                v64 = node0 - v63 + 1;
              else
                v64 = node0 + 2;
              find_quantized_collision_pairs_recursive(boxset0, boxset1, collision_pairs, trans_cache_1to0, v64, v75, 0);
              v65 = *(_DWORD *)((char *)&boxset1->m_box_tree.m_node_array.m_data[1].m_quantizedAabbMax[3] + v60);
              if ( v65 < 0 )
                v66 = node1 - v65 + 1;
              else
                v66 = node1 + 2;
              v67 = boxset0->m_box_tree.m_node_array.m_data[v76 / 0x10 + 1].m_escapeIndexOrDataIndex;
              if ( v67 < 0 )
                v59 = node0 - v67 + 1;
              else
                v59 = node0 + 2;
              node1 = v66;
            }
            else
            {
              find_quantized_collision_pairs_recursive(
                boxset0,
                boxset1,
                collision_pairs,
                trans_cache_1to0,
                node0 + 1,
                node1,
                v68);
              v58 = boxset0->m_box_tree.m_node_array.m_data[v76 / 0x10 + 1].m_escapeIndexOrDataIndex;
              if ( v58 < 0 )
                v59 = node0 - v58 + 1;
              else
                v59 = node0 + 2;
            }
            complete_primitive_tests = 0;
            node0 = v59;
          }
          else
          {
            if ( v24->m_escapeIndexOrDataIndex >= 0 )
            {
              btPairSet::push_pair(
                (btPairSet *)boxset0,
                (int)collision_pairs,
                boxset0->m_box_tree.m_node_array.m_data[node0].m_escapeIndexOrDataIndex,
                boxset1->m_box_tree.m_node_array.m_data[node1].m_escapeIndexOrDataIndex);
              return;
            }
            find_quantized_collision_pairs_recursive(
              boxset0,
              boxset1,
              collision_pairs,
              trans_cache_1to0,
              node0,
              node1 + 1,
              0);
            v55 = boxset1->m_box_tree.m_node_array.m_data[v78 / 0x10 + 1].m_escapeIndexOrDataIndex;
            if ( v55 < 0 )
              v56 = node1 - v55 + 1;
            else
              v56 = node1 + 2;
            complete_primitive_tests = 0;
            node1 = v56;
          }
          goto LABEL_2;
        }
      }
      return;
    }
  }
}
