void __thiscall vostok::render::cloud_simulation::compute_cloud_density(vostok::render::cloud_simulation *this)
{
  const vostok::math::float4x4 *v1; // xmm2_4
  unsigned int v2; // esi
  unsigned int v3; // edx
  unsigned int v4; // eax
  int v5; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4
  unsigned int v8; // ebx
  int v9; // esi
  unsigned int v10; // edi
  float v11; // xmm1_4
  unsigned int m_clouds_size_y; // eax
  unsigned int m_clouds_size_x; // ebp
  int v14; // esi
  unsigned int v15; // edi
  float v16; // xmm1_4
  unsigned int v17; // eax
  unsigned int v18; // ebp
  int v19; // esi
  unsigned int v20; // edi
  float v21; // xmm1_4
  unsigned int v22; // eax
  unsigned int v23; // ebp
  int v24; // esi
  unsigned int v25; // edi
  float v26; // xmm1_4
  unsigned int v27; // eax
  unsigned int v28; // ebp
  int v29; // esi
  unsigned int v30; // edi
  unsigned int v31; // ebp
  unsigned int z; // [esp+0h] [ebp-1Ch]
  unsigned int v33; // [esp+4h] [ebp-18h]
  unsigned int x; // [esp+8h] [ebp-14h]
  unsigned int y; // [esp+Ch] [ebp-10h]
  int v36; // [esp+10h] [ebp-Ch]
  int x0; // [esp+14h] [ebp-8h]
  float *out_density; // [esp+18h] [ebp-4h]

  z = 0;
  if ( this->m_clouds_size_z )
  {
    v1 = clear_value;
    do
    {
      v2 = 0;
      for ( x = 0; v2 < this->m_clouds_size_x; x = v2 )
      {
        v3 = 1;
        for ( y = 1; v3 < this->m_clouds_size_y - 1; y = v3 )
        {
          v4 = v3 + z * this->m_clouds_size_y;
          out_density = &this->m_densities[v2 + v4 * this->m_clouds_size_x];
          if ( this->m_voxels[v2 + v4 * this->m_clouds_size_x].x )
          {
            v5 = -2;
            v6 = 0.0;
            v7 = 0.0;
            x0 = -2;
            do
            {
              v33 = v2 + v5;
              v8 = y - 2;
              v36 = 5;
              do
              {
                v9 = v33;
                v10 = z - 2;
                v11 = v7 + *(float *)&v1;
                if ( v33 < this->m_clouds_size_x
                  && (m_clouds_size_y = this->m_clouds_size_y, v8 < m_clouds_size_y)
                  && v10 < this->m_clouds_size_z
                  || (m_clouds_size_x = this->m_clouds_size_x,
                      v9 = v33 % m_clouds_size_x,
                      v10 %= this->m_clouds_size_z,
                      v33 % m_clouds_size_x < m_clouds_size_x)
                  && (m_clouds_size_y = this->m_clouds_size_y, v8 < m_clouds_size_y)
                  && v10 < this->m_clouds_size_z )
                {
                  v6 = (float)((float)this->m_voxels[v9 + this->m_clouds_size_x * (v8 + v10 * m_clouds_size_y)].x
                             * 0.0039215689)
                     + v6;
                }
                v14 = v33;
                v15 = z - 1;
                v16 = v11 + *(float *)&v1;
                if ( v33 < this->m_clouds_size_x
                  && (v17 = this->m_clouds_size_y, v8 < v17)
                  && v15 < this->m_clouds_size_z
                  || (v18 = this->m_clouds_size_x, v14 = v33 % v18, v15 %= this->m_clouds_size_z, v33 % v18 < v18)
                  && (v17 = this->m_clouds_size_y, v8 < v17)
                  && v15 < this->m_clouds_size_z )
                {
                  v6 = (float)((float)this->m_voxels[v14 + this->m_clouds_size_x * (v8 + v15 * v17)].x * 0.0039215689)
                     + v6;
                }
                v19 = v33;
                v20 = z;
                v21 = v16 + *(float *)&v1;
                if ( v33 < this->m_clouds_size_x && (v22 = this->m_clouds_size_y, v8 < v22) && z < this->m_clouds_size_z
                  || (v23 = this->m_clouds_size_x, v19 = v33 % v23, v20 = z % this->m_clouds_size_z, v33 % v23 < v23)
                  && (v22 = this->m_clouds_size_y, v8 < v22)
                  && v20 < this->m_clouds_size_z )
                {
                  v6 = (float)((float)this->m_voxels[v19 + this->m_clouds_size_x * (v8 + v20 * v22)].x * 0.0039215689)
                     + v6;
                }
                v24 = v33;
                v25 = z + 1;
                v26 = v21 + *(float *)&v1;
                if ( v33 < this->m_clouds_size_x
                  && (v27 = this->m_clouds_size_y, v8 < v27)
                  && v25 < this->m_clouds_size_z
                  || (v28 = this->m_clouds_size_x, v24 = v33 % v28, v25 %= this->m_clouds_size_z, v33 % v28 < v28)
                  && (v27 = this->m_clouds_size_y, v8 < v27)
                  && v25 < this->m_clouds_size_z )
                {
                  v6 = (float)((float)this->m_voxels[v24 + this->m_clouds_size_x * (v8 + v25 * v27)].x * 0.0039215689)
                     + v6;
                }
                v29 = v33;
                v30 = z + 2;
                v7 = v26 + *(float *)&v1;
                if ( v33 < this->m_clouds_size_x && v8 < this->m_clouds_size_y && v30 < this->m_clouds_size_z
                  || (v31 = this->m_clouds_size_x, v29 = v33 % v31, v30 %= this->m_clouds_size_z, v33 % v31 < v31)
                  && v8 < this->m_clouds_size_y
                  && v30 < this->m_clouds_size_z )
                {
                  v6 = (float)((float)this->m_voxels[v29 + this->m_clouds_size_x * (v8 + v30 * this->m_clouds_size_y)].x
                             * 0.0039215689)
                     + v6;
                }
                ++v8;
                --v36;
              }
              while ( v36 );
              v2 = x;
              v5 = ++x0;
            }
            while ( x0 <= 2 );
            if ( v7 <= 0.0 )
              *out_density = 0.0;
            else
              *out_density = v6 / v7;
          }
          else
          {
            this->m_densities[v2 + v4 * this->m_clouds_size_x] = 0.0;
          }
          v3 = y + 1;
        }
        ++v2;
      }
      ++z;
    }
    while ( z < this->m_clouds_size_z );
  }
}
