void __userpurge GIM_TRIANGLE_CONTACT::merge_points(
        GIM_TRIANGLE_CONTACT *this@<eax>,
        const btVector4 *plane@<edi>,
        float a3@<xmm2>,
        const btVector3 *points,
        int point_count)
{
  int v6; // ebp
  int v7; // ecx
  int v8; // esi
  float *v9; // edx
  float v10; // xmm0_4
  int m_point_count; // ebx
  float v12; // xmm0_4
  int v13; // ebx
  float v14; // xmm0_4
  int v15; // ebx
  float v16; // xmm0_4
  int v17; // ebx
  float *v18; // edx
  float v19; // xmm0_4
  int v20; // esi
  int v21; // edx
  btVector3 *m_points; // esi
  const btVector3 *v23; // ecx
  int point_indices[16]; // [esp+0h] [ebp-40h]

  v6 = point_count;
  v7 = 0;
  *(_QWORD *)&this->m_penetration_depth = 3296329728LL;
  if ( point_count >= 4 )
  {
    v8 = 2;
    v9 = &points[1].mVec128.m128_f32[1];
    do
    {
      v10 = a3
          - (float)((float)((float)((float)(*(v9 - 4) * plane->mVec128.m128_f32[1])
                                  + (float)(*(v9 - 3) * plane->mVec128.m128_f32[2]))
                          + (float)(*(v9 - 5) * plane->mVec128.m128_f32[0]))
                  - plane->mVec128.m128_f32[3]);
      if ( v10 >= 0.0 )
      {
        if ( v10 <= this->m_penetration_depth )
        {
          if ( (float)(v10 + 0.00000011920929) >= this->m_penetration_depth )
          {
            m_point_count = this->m_point_count;
            point_indices[m_point_count] = v7;
            this->m_point_count = m_point_count + 1;
          }
        }
        else
        {
          this->m_penetration_depth = v10;
          point_indices[0] = v7;
          this->m_point_count = 1;
        }
      }
      v12 = a3
          - (float)((float)((float)((float)(v9[1] * plane->mVec128.m128_f32[2])
                                  + (float)(*(v9 - 1) * plane->mVec128.m128_f32[0]))
                          + (float)(*v9 * plane->mVec128.m128_f32[1]))
                  - plane->mVec128.m128_f32[3]);
      if ( v12 >= 0.0 )
      {
        if ( v12 <= this->m_penetration_depth )
        {
          if ( (float)(v12 + 0.00000011920929) >= this->m_penetration_depth )
          {
            v13 = this->m_point_count;
            point_indices[v13] = v8 - 1;
            v6 = point_count;
            this->m_point_count = v13 + 1;
          }
        }
        else
        {
          this->m_penetration_depth = v12;
          point_indices[0] = v8 - 1;
          this->m_point_count = 1;
        }
      }
      v14 = a3
          - (float)((float)((float)((float)(v9[4] * plane->mVec128.m128_f32[1])
                                  + (float)(v9[5] * plane->mVec128.m128_f32[2]))
                          + (float)(v9[3] * plane->mVec128.m128_f32[0]))
                  - plane->mVec128.m128_f32[3]);
      if ( v14 >= 0.0 )
      {
        if ( v14 <= this->m_penetration_depth )
        {
          if ( (float)(v14 + 0.00000011920929) >= this->m_penetration_depth )
          {
            v15 = this->m_point_count;
            point_indices[v15] = v8;
            this->m_point_count = v15 + 1;
          }
        }
        else
        {
          this->m_penetration_depth = v14;
          point_indices[0] = v8;
          this->m_point_count = 1;
        }
      }
      v16 = a3
          - (float)((float)((float)((float)(v9[8] * plane->mVec128.m128_f32[1])
                                  + (float)(v9[9] * plane->mVec128.m128_f32[2]))
                          + (float)(v9[7] * plane->mVec128.m128_f32[0]))
                  - plane->mVec128.m128_f32[3]);
      if ( v16 >= 0.0 )
      {
        if ( v16 <= this->m_penetration_depth )
        {
          if ( (float)(v16 + 0.00000011920929) >= this->m_penetration_depth )
          {
            v17 = this->m_point_count;
            point_indices[v17] = v8 + 1;
            v6 = point_count;
            this->m_point_count = v17 + 1;
          }
        }
        else
        {
          this->m_penetration_depth = v16;
          point_indices[0] = v8 + 1;
          this->m_point_count = 1;
        }
      }
      v7 += 4;
      v9 += 16;
      v8 += 4;
    }
    while ( v7 < v6 - 3 );
  }
  if ( v7 < v6 )
  {
    v18 = &points[v7].mVec128.m128_f32[1];
    do
    {
      v19 = a3
          - (float)((float)((float)((float)(v18[1] * plane->mVec128.m128_f32[2])
                                  + (float)(*(v18 - 1) * plane->mVec128.m128_f32[0]))
                          + (float)(*v18 * plane->mVec128.m128_f32[1]))
                  - plane->mVec128.m128_f32[3]);
      if ( v19 >= 0.0 )
      {
        if ( v19 <= this->m_penetration_depth )
        {
          if ( (float)(v19 + 0.00000011920929) >= this->m_penetration_depth )
          {
            v20 = this->m_point_count;
            point_indices[v20] = v7;
            this->m_point_count = v20 + 1;
          }
        }
        else
        {
          this->m_penetration_depth = v19;
          point_indices[0] = v7;
          this->m_point_count = 1;
        }
      }
      ++v7;
      v18 += 4;
    }
    while ( v7 < v6 );
  }
  v21 = 0;
  if ( this->m_point_count > 0 )
  {
    m_points = this->m_points;
    do
    {
      v23 = &points[point_indices[v21]];
      m_points->mVec128.m128_u64[0] = v23->mVec128.m128_u64[0];
      m_points->mVec128.m128_u64[1] = v23->mVec128.m128_u64[1];
      ++v21;
      ++m_points;
    }
    while ( v21 < this->m_point_count );
  }
}
