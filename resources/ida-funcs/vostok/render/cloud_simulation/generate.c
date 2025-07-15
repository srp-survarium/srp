void __userpurge vostok::render::cloud_simulation::generate(
        vostok::render::cloud_simulation *this@<ecx>,
        const vostok::math::float3 *sun_direction@<eax>,
        const vostok::render::cloud_key_parameters *a3@<edi>,
        const vostok::render::cloud_key_parameters *init_key)
{
  __int64 v4; // xmm0_8
  float v5; // eax
  const vostok::render::cloud_key_parameters *v6; // edi
  float v8; // xmm1_4
  float v9; // xmm1_4
  unsigned int v10; // eax
  unsigned int v11; // ecx
  unsigned int m_clouds_size_x; // eax
  unsigned int v13; // ebp
  float v14; // xmm0_4
  unsigned int v15; // edx
  unsigned int v16; // eax
  const vostok::math::float4x4 *v17; // xmm1_4
  vostok::render::cloud_simulation::voxel *m_voxels; // edi
  unsigned int v19; // ecx
  float v20; // xmm0_4
  vostok::render::cloud_simulation *v21; // ecx
  vostok::render::cloud_simulation *v22; // ecx
  float x; // [esp+0h] [ebp-44h]
  float y; // [esp+4h] [ebp-40h]
  float cloudiness3; // [esp+1Ch] [ebp-28h]
  float cloudiness2; // [esp+20h] [ebp-24h]
  unsigned int z; // [esp+24h] [ebp-20h]
  vostok::render::cloud_simulation::voxel v; // [esp+28h] [ebp-1Ch]
  float v30; // [esp+2Ch] [ebp-18h]
  unsigned int num_octaves; // [esp+30h] [ebp-14h]
  float cloudiness; // [esp+34h] [ebp-10h]
  vostok::math::float3 to_sun_direction; // [esp+38h] [ebp-Ch] BYREF

  v4 = *(_QWORD *)&sun_direction->x;
  v5 = sun_direction->z;
  v6 = init_key;
  *(_QWORD *)&to_sun_direction.x = v4;
  to_sun_direction.z = v5;
  vostok::render::cloud_simulation::fill_default_volume(this, (int *)this);
  v8 = *(float *)&clear_value - init_key->cloud_generate_cloudiness;
  cloudiness = v8;
  if ( (float)(v8 + 0.050000001) > 0.0 )
  {
    if ( *(float *)&clear_value < (float)(v8 + 0.050000001) )
      cloudiness2 = *(float *)&clear_value;
    else
      cloudiness2 = v8 + 0.050000001;
  }
  else
  {
    cloudiness2 = 0.0;
  }
  v9 = v8 + 0.1;
  if ( v9 > 0.0 )
  {
    if ( *(float *)&clear_value < v9 )
      cloudiness3 = *(float *)&clear_value;
    else
      cloudiness3 = v9;
  }
  else
  {
    cloudiness3 = 0.0;
  }
  v10 = vostok::math::floor(init_key->cloud_generate_octaves);
  v11 = 0;
  num_octaves = v10;
  for ( z = 0; v11 < this->m_clouds_size_z; z = v11 )
  {
    m_clouds_size_x = this->m_clouds_size_x;
    v13 = 0;
    if ( m_clouds_size_x )
    {
      v30 = (float)v11;
      do
      {
        y = v30 / (double)this->m_clouds_size_z;
        x = (double)v13 / (double)m_clouds_size_x;
        v14 = vostok::render::cloud_noise::evaluate(x, y, num_octaves);
        v15 = 1;
        v16 = 1;
        if ( (float)(v14 - cloudiness3) <= 0.0 )
        {
          if ( (float)(v14 - cloudiness2) <= 0.0 )
          {
            if ( (float)(v14 - cloudiness) > 0.0 )
            {
              v16 = 3;
              v15 = this->m_clouds_size_y - 4;
            }
          }
          else
          {
            v16 = 2;
            v15 = this->m_clouds_size_y - 3;
          }
        }
        else
        {
          v15 = this->m_clouds_size_y - 1;
        }
        if ( v15 - v16 > 1 && v16 < v15 )
        {
          v17 = clear_value;
          do
          {
            m_voxels = this->m_voxels;
            v19 = v16 + z * this->m_clouds_size_y;
            v = m_voxels[v13 + v19 * this->m_clouds_size_x];
            v20 = *(float *)&v17 - init_key->diffusivity;
            if ( v20 > 0.0 )
            {
              if ( *(float *)&v17 < v20 )
                v20 = *(float *)&v17;
            }
            else
            {
              v20 = 0.0;
            }
            v.x = (int)(float)(v20 * 255.0);
            ++v16;
            m_voxels[v13 + v19 * this->m_clouds_size_x] = v;
          }
          while ( v16 < v15 );
        }
        m_clouds_size_x = this->m_clouds_size_x;
        ++v13;
      }
      while ( v13 < m_clouds_size_x );
      v11 = z;
      v6 = init_key;
    }
    ++v11;
  }
  if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 286) )
  {
    vostok::render::cloud_simulation::compute_cloud_density(this);
    vostok::render::cloud_simulation::compute_indirect_light(&to_sun_direction, this, v6);
    vostok::render::cloud_simulation::compute_direct_light(v21, this, v6, a3);
    vostok::render::cloud_simulation::smooth_transparency(v22, this);
  }
}
