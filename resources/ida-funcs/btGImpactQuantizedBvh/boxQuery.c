bool __userpurge btGImpactQuantizedBvh::boxQuery@<al>(
        const btAABB *box@<eax>,
        btGImpactQuantizedBvh *this,
        btAlignedObjectArray<int> *collided_results)
{
  float v3; // xmm4_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  int v13; // esi
  BT_QUANTIZED_BVH_NODE *v14; // eax
  int m_escapeIndexOrDataIndex; // edx
  int m_capacity; // ecx
  int m_size; // eax
  int v18; // edi
  int v19; // edx
  int v20; // ecx
  int *v21; // eax
  int *v22; // eax
  char v24; // [esp+Eh] [ebp-3Ah]
  bool v25; // [esp+Fh] [ebp-39h]
  int v26; // [esp+10h] [ebp-38h]
  int *v27; // [esp+14h] [ebp-34h]
  int v28; // [esp+18h] [ebp-30h]
  int v29; // [esp+1Ch] [ebp-2Ch]
  int m_num_nodes; // [esp+24h] [ebp-24h]
  unsigned __int16 v31; // [esp+28h] [ebp-20h]
  unsigned __int16 v32; // [esp+2Ah] [ebp-1Eh]
  unsigned __int16 v33; // [esp+2Ch] [ebp-1Ch]
  unsigned __int16 v34; // [esp+30h] [ebp-18h]
  unsigned __int16 v35; // [esp+32h] [ebp-16h]
  unsigned __int16 v36; // [esp+34h] [ebp-14h]

  v26 = 0;
  v3 = this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[0];
  v4 = box->m_min.mVec128.m128_f32[0];
  m_num_nodes = this->m_box_tree.m_num_nodes;
  if ( v3 > box->m_min.mVec128.m128_f32[0] )
    v4 = this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[0];
  v5 = box->m_min.mVec128.m128_f32[1];
  if ( this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1] > v5 )
    v5 = this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1];
  v6 = box->m_min.mVec128.m128_f32[2];
  if ( this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2] > v6 )
    v6 = this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2];
  if ( v4 > this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[0] )
    v4 = this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[0];
  if ( v5 > this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[1] )
    v5 = this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[1];
  if ( v6 > this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[2] )
    v6 = this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[2];
  v7 = v5 - this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1];
  v8 = v4 - v3;
  v9 = this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[0];
  v34 = (int)(float)((float)(this->m_box_tree.m_bvhQuantization.mVec128.m128_f32[0] * v8) + 0.5);
  v10 = box->m_max.mVec128.m128_f32[0];
  v35 = (int)(float)((float)(this->m_box_tree.m_bvhQuantization.mVec128.m128_f32[1] * v7) + 0.5);
  v36 = (int)(float)((float)(this->m_box_tree.m_bvhQuantization.mVec128.m128_f32[2]
                           * (float)(v6 - this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2]))
                   + 0.5);
  if ( v9 > v10 )
    v10 = this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[0];
  v11 = box->m_max.mVec128.m128_f32[1];
  if ( this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1] > v11 )
    v11 = this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1];
  v12 = box->m_max.mVec128.m128_f32[2];
  if ( this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2] > v12 )
    v12 = this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2];
  if ( v10 > this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[0] )
    v10 = this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[0];
  if ( v11 > this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[1] )
    v11 = this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[1];
  if ( v12 > this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[2] )
    v12 = this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[2];
  v31 = (int)(float)((float)(this->m_box_tree.m_bvhQuantization.mVec128.m128_f32[0] * (float)(v10 - v9)) + 0.5);
  v32 = (int)(float)((float)(this->m_box_tree.m_bvhQuantization.mVec128.m128_f32[1]
                           * (float)(v11 - this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1]))
                   + 0.5);
  v33 = (int)(float)((float)(this->m_box_tree.m_bvhQuantization.mVec128.m128_f32[2]
                           * (float)(v12 - this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2]))
                   + 0.5);
  if ( this->m_box_tree.m_num_nodes > 0 )
  {
    do
    {
      v13 = v26;
      v14 = &this->m_box_tree.m_node_array.m_data[v26];
      if ( v14->m_quantizedAabbMin[0] > v31
        || v14->m_quantizedAabbMax[0] < v34
        || v14->m_quantizedAabbMin[1] > v32
        || v14->m_quantizedAabbMax[1] < v35
        || v14->m_quantizedAabbMin[2] > v33
        || (v24 = 1, v14->m_quantizedAabbMax[2] < v36) )
      {
        v24 = 0;
      }
      m_escapeIndexOrDataIndex = v14->m_escapeIndexOrDataIndex;
      v25 = m_escapeIndexOrDataIndex >= 0;
      v29 = m_escapeIndexOrDataIndex;
      if ( m_escapeIndexOrDataIndex >= 0 )
      {
        if ( !v24 )
          goto LABEL_57;
        m_capacity = collided_results->m_capacity;
        m_size = collided_results->m_size;
        if ( m_size == m_capacity )
        {
          v18 = m_size ? 2 * m_size : 1;
          v28 = v18;
          if ( m_capacity < v18 )
          {
            if ( v18 )
              v27 = (int *)btAlignedAllocInternal(4 * v18);
            else
              v27 = 0;
            v19 = collided_results->m_size;
            v20 = 0;
            if ( v19 > 0 )
            {
              v21 = v27;
              do
              {
                if ( v21 )
                {
                  *v21 = collided_results->m_data[v20];
                  v18 = v28;
                }
                ++v20;
                ++v21;
              }
              while ( v20 < v19 );
            }
            if ( collided_results->m_data )
            {
              if ( collided_results->m_ownsMemory )
                btAlignedFreeInternal(collided_results->m_data);
              collided_results->m_data = 0;
            }
            m_escapeIndexOrDataIndex = v29;
            collided_results->m_ownsMemory = 1;
            collided_results->m_data = v27;
            collided_results->m_capacity = v18;
          }
        }
        v22 = &collided_results->m_data[collided_results->m_size];
        if ( v22 )
          *v22 = m_escapeIndexOrDataIndex;
        ++collided_results->m_size;
        v13 = v26;
      }
      if ( v24 )
        goto LABEL_59;
LABEL_57:
      if ( v25 )
      {
LABEL_59:
        ++v26;
        continue;
      }
      v26 -= this->m_box_tree.m_node_array.m_data[v13].m_escapeIndexOrDataIndex;
    }
    while ( v26 < m_num_nodes );
  }
  return collided_results->m_size > 0;
}
