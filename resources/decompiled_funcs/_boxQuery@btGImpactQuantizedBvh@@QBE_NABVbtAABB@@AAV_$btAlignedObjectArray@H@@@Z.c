bool __usercall btGImpactQuantizedBvh::boxQuery@<al>(
        btGImpactQuantizedBvh *this@<edi>,
        const btAABB *box@<eax>,
        btAlignedObjectArray<int> *collided_results@<esi>)
{
  float v3; // xmm3_4
  float v4; // xmm2_4
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  int v13; // edx
  BT_QUANTIZED_BVH_NODE *v14; // eax
  bool v15; // al
  int m_capacity; // ecx
  int m_size; // eax
  int v18; // ebx
  int v19; // edx
  int v20; // eax
  int *v21; // ecx
  int *m_data; // eax
  int *v23; // eax
  char v25; // [esp+D0h] [ebp-3Ah]
  int v26; // [esp+D2h] [ebp-38h]
  int *v27; // [esp+D6h] [ebp-34h]
  int v28; // [esp+DAh] [ebp-30h]
  int v29; // [esp+DEh] [ebp-2Ch]
  int m_escapeIndexOrDataIndex; // [esp+E2h] [ebp-28h]
  int m_num_nodes; // [esp+E6h] [ebp-24h]
  unsigned __int16 v32; // [esp+EAh] [ebp-20h]
  unsigned __int16 v33; // [esp+ECh] [ebp-1Eh]
  unsigned __int16 v34; // [esp+EEh] [ebp-1Ch]
  unsigned __int16 v35; // [esp+F2h] [ebp-18h]
  unsigned __int16 v36; // [esp+F4h] [ebp-16h]
  unsigned __int16 v37; // [esp+F6h] [ebp-14h]
  btVector3 v38; // [esp+FAh] [ebp-10h]

  v3 = this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[0];
  v4 = box->m_min.mVec128.m128_f32[0];
  v5 = 0;
  v26 = 0;
  m_num_nodes = this->m_box_tree.m_num_nodes;
  if ( v3 > box->m_min.mVec128.m128_f32[0] )
    v4 = this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[0];
  v6 = box->m_min.mVec128.m128_f32[1];
  if ( this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1] > v6 )
    v6 = this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1];
  v7 = box->m_min.mVec128.m128_f32[2];
  if ( this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2] > v7 )
    v7 = this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2];
  if ( v4 > this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[0] )
    v4 = this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[0];
  if ( v6 > this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[1] )
    v6 = this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[1];
  if ( v7 > this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[2] )
    v7 = this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[2];
  v38.mVec128 = (__m128)box->m_max;
  v35 = (int)(float)((float)(this->m_box_tree.m_bvhQuantization.mVec128.m128_f32[0] * (float)(v4 - v3)) + 0.5);
  v8 = this->m_box_tree.m_bvhQuantization.mVec128.m128_f32[2]
     * (float)(v7 - this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2]);
  v9 = this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[0];
  v10 = v38.mVec128.m128_f32[0];
  v36 = (int)(float)((float)(this->m_box_tree.m_bvhQuantization.mVec128.m128_f32[1]
                           * (float)(v6 - this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1]))
                   + 0.5);
  v37 = (int)(float)(v8 + 0.5);
  if ( v9 > v38.mVec128.m128_f32[0] )
    v10 = this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[0];
  v11 = box->m_max.mVec128.m128_f32[1];
  if ( this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1] > v38.mVec128.m128_f32[1] )
    v11 = this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1];
  v12 = box->m_max.mVec128.m128_f32[2];
  if ( this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2] > v38.mVec128.m128_f32[2] )
    v12 = this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2];
  if ( v10 > this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[0] )
    v10 = this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[0];
  if ( v11 > this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[1] )
    v11 = this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[1];
  if ( v12 > this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[2] )
    v12 = this->m_box_tree.m_global_bound.m_max.mVec128.m128_f32[2];
  v32 = (int)(float)((float)(this->m_box_tree.m_bvhQuantization.mVec128.m128_f32[0] * (float)(v10 - v9)) + 0.5);
  v33 = (int)(float)((float)(this->m_box_tree.m_bvhQuantization.mVec128.m128_f32[1]
                           * (float)(v11 - this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[1]))
                   + 0.5);
  v34 = (int)(float)((float)(this->m_box_tree.m_bvhQuantization.mVec128.m128_f32[2]
                           * (float)(v12 - this->m_box_tree.m_global_bound.m_min.mVec128.m128_f32[2]))
                   + 0.5);
  if ( this->m_box_tree.m_num_nodes > 0 )
  {
    do
    {
      v13 = 16 * v5;
      v14 = &this->m_box_tree.m_node_array.m_data[v5];
      v29 = 16 * v5;
      if ( v14->m_quantizedAabbMin[0] > v32
        || v14->m_quantizedAabbMax[0] < v35
        || v14->m_quantizedAabbMin[1] > v33
        || v14->m_quantizedAabbMax[1] < v36
        || v14->m_quantizedAabbMin[2] > v34
        || (v25 = 1, v14->m_quantizedAabbMax[2] < v37) )
      {
        v25 = 0;
      }
      m_escapeIndexOrDataIndex = v14->m_escapeIndexOrDataIndex;
      v15 = m_escapeIndexOrDataIndex >= 0;
      if ( m_escapeIndexOrDataIndex >= 0 )
      {
        if ( !v25 )
          goto LABEL_57;
        m_capacity = collided_results->m_capacity;
        m_size = collided_results->m_size;
        if ( m_size == m_capacity )
        {
          v18 = 2 * m_size;
          if ( !m_size )
            v18 = 1;
          v28 = v18;
          if ( m_capacity < v18 )
          {
            if ( v18 )
            {
              ++gNumAlignedAllocs;
              v27 = (int *)sAlignedAllocFunc(4 * v18, 16);
            }
            else
            {
              v27 = 0;
            }
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
            m_data = collided_results->m_data;
            if ( m_data )
            {
              if ( collided_results->m_ownsMemory )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(m_data);
              }
              collided_results->m_data = 0;
            }
            v13 = v29;
            collided_results->m_ownsMemory = 1;
            collided_results->m_data = v27;
            collided_results->m_capacity = v18;
          }
          v5 = v26;
        }
        v23 = &collided_results->m_data[collided_results->m_size];
        if ( v23 )
          *v23 = m_escapeIndexOrDataIndex;
        ++collided_results->m_size;
        v15 = m_escapeIndexOrDataIndex >= 0;
      }
      if ( v25 )
        goto LABEL_59;
LABEL_57:
      if ( v15 )
      {
LABEL_59:
        ++v5;
        goto LABEL_60;
      }
      v5 -= *(_DWORD *)((char *)&this->m_box_tree.m_node_array.m_data->m_quantizedAabbMax[3] + v13);
LABEL_60:
      v26 = v5;
    }
    while ( v5 < m_num_nodes );
  }
  return collided_results->m_size > 0;
}
