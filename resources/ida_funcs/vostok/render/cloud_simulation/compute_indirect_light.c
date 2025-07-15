void __userpurge vostok::render::cloud_simulation::compute_indirect_light(
        const vostok::math::float3 *sun_direction@<eax>,
        vostok::render::cloud_simulation *this,
        const vostok::render::cloud_key_parameters *init_key)
{
  float v3; // xmm4_4
  float v4; // xmm0_4
  const vostok::math::float4x4 *v5; // xmm1_4
  unsigned int m_clouds_size_y; // eax
  double v7; // st7
  double v8; // st5
  double v9; // st6
  double v10; // st7
  double v11; // st6
  unsigned int v12; // esi
  unsigned int v13; // ebp
  unsigned int v14; // ecx
  unsigned int v15; // edi
  unsigned int v16; // edx
  unsigned int m_clouds_size_x; // ebp
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  signed int v21; // esi
  signed int v22; // esi
  unsigned int m_clouds_size_z; // edi
  double v24; // st5
  double v25; // st7
  double v26; // st6
  long double v27; // st7
  float v28; // xmm0_4
  float v29; // [esp+1Ch] [ebp-88h]
  float z; // [esp+2Ch] [ebp-78h]
  unsigned int za; // [esp+2Ch] [ebp-78h]
  unsigned int y; // [esp+30h] [ebp-74h]
  float accumulated; // [esp+34h] [ebp-70h]
  float accumulateda; // [esp+34h] [ebp-70h]
  unsigned int v35; // [esp+38h] [ebp-6Ch]
  float v36; // [esp+38h] [ebp-6Ch]
  vostok::render::cloud_simulation::voxel v; // [esp+40h] [ebp-64h]
  unsigned int x; // [esp+44h] [ebp-60h]
  unsigned int num; // [esp+48h] [ebp-5Ch]
  float coord; // [esp+4Ch] [ebp-58h]
  float coord_8; // [esp+54h] [ebp-50h]
  float v42; // [esp+58h] [ebp-4Ch]
  unsigned int i; // [esp+5Ch] [ebp-48h]
  float v44; // [esp+60h] [ebp-44h]
  float v45; // [esp+64h] [ebp-40h]
  float v46; // [esp+68h] [ebp-3Ch]
  float v47; // [esp+6Ch] [ebp-38h]
  float v48; // [esp+70h] [ebp-34h]
  float v49; // [esp+74h] [ebp-30h]
  float v50; // [esp+78h] [ebp-2Ch]
  float v51; // [esp+7Ch] [ebp-28h]
  float v52; // [esp+80h] [ebp-24h]
  float v53; // [esp+84h] [ebp-20h]
  float v54; // [esp+8Ch] [ebp-18h]
  float v55; // [esp+94h] [ebp-10h]
  float v56; // [esp+98h] [ebp-Ch]
  float v57; // [esp+9Ch] [ebp-8h]

  v3 = 0.0;
  v54 = sun_direction->x;
  v53 = sun_direction->z;
  v4 = fabs((float)((float)(sun_direction->x + v53) * 0.0) + sun_direction->y);
  v52 = sun_direction->y;
  v5 = clear_value;
  if ( v4 > 0.0 )
  {
    if ( *(float *)&clear_value < v4 )
      z = *(float *)&clear_value;
    else
      z = v4;
  }
  else
  {
    z = 0.0;
  }
  m_clouds_size_y = this->m_clouds_size_y;
  v7 = z;
  v8 = (1.0 - z) * (double)(6 * m_clouds_size_y);
  za = 0;
  v9 = v7 * (double)m_clouds_size_y + v8;
  v10 = 1.0;
  num = (__int64)v9;
  if ( this->m_clouds_size_z )
  {
    v11 = 0.0;
    do
    {
      v12 = 0;
      x = 0;
      if ( !this->m_clouds_size_x )
        goto LABEL_65;
      do
      {
        v13 = 0;
        y = 0;
        if ( !this->m_clouds_size_y )
          goto LABEL_64;
        do
        {
          v14 = this->m_clouds_size_y;
          v15 = za * v14 + v13;
          v35 = v15;
          v = this->m_voxels[v12 + v15 * this->m_clouds_size_x];
          if ( !v.x )
            goto LABEL_63;
          v16 = 0;
          accumulated = 0.0;
          i = 0;
          if ( !num )
            goto LABEL_55;
          v55 = (float)v12;
          v56 = (float)v13;
          m_clouds_size_x = this->m_clouds_size_x;
          v57 = (float)za;
          while ( 1 )
          {
            v29 = (double)v16 + v10;
            v18 = v55 + (float)(v54 * v29);
            v19 = v57 + (float)(v53 * v29);
            v20 = (float)(v52 * v29) + v56;
            v49 = v19 <= 0.0 ? 0.0 : v57 + (float)(v53 * v29);
            v45 = v20 <= 0.0 ? 0.0 : (float)(v52 * v29) + v56;
            v48 = v18 <= 0.0 ? 0.0 : v55 + (float)(v54 * v29);
            if ( (unsigned int)(__int64)v48 >= m_clouds_size_x
              || (unsigned int)(__int64)v45 >= v14
              || (unsigned int)(__int64)v49 >= this->m_clouds_size_z )
            {
              break;
            }
LABEL_41:
            if ( v19 <= 0.0 )
              v42 = 0.0;
            else
              v42 = v19;
            if ( v20 <= 0.0 )
              v46 = 0.0;
            else
              v46 = (float)(v52 * v29) + v56;
            if ( v18 <= 0.0 )
              v50 = 0.0;
            else
              v50 = v18;
            v14 = this->m_clouds_size_y;
            if ( !this->m_voxels[(__int64)v50 + m_clouds_size_x * ((__int64)v46 + v14 * (__int64)v42)].x )
              goto LABEL_54;
LABEL_51:
            ++v16;
            accumulated = accumulated + *(float *)&clear_value;
            i = v16;
            if ( v16 >= num )
              goto LABEL_54;
          }
          if ( (unsigned int)(__int64)(float)(v55 + (float)(v54 * v29)) < m_clouds_size_x
            && (unsigned int)(__int64)(float)((float)(v52 * v29) + v56) > v14
            && (unsigned int)(__int64)(float)(v57 + (float)(v53 * v29)) < this->m_clouds_size_z )
          {
            goto LABEL_51;
          }
          v21 = ~(~(LODWORD(v18) - 1) & 0x80000000) & LODWORD(v18);
          coord = (float)(((v21 >> 31)
                         ^ ((158 - (unsigned __int8)(v21 >> 23) - 96 + 64) >> 31)
                         & (((v21 | 0xFF800000) << 8 >> (-98 - (v21 >> 23)))
                          - ((v21 >> 31) & ((v21 & (((1 << (-98 - (v21 >> 23) - 96)) - 1) >> 8)) == 0))))
                        % m_clouds_size_x);
          v22 = ~(~(LODWORD(v19) - 1) & 0x80000000) & LODWORD(v19);
          m_clouds_size_z = this->m_clouds_size_z;
          v24 = (double)(((v22 >> 31)
                        ^ ((158 - (unsigned __int8)(v22 >> 23) - 96 + 64) >> 31)
                        & (((v22 | 0xFF800000) << 8 >> (-98 - (v22 >> 23)))
                         - ((v22 >> 31) & ((v22 & (((1 << (-98 - (v22 >> 23) - 96)) - 1) >> 8)) == 0))))
                       % m_clouds_size_z);
          coord_8 = v24;
          v19 = coord_8;
          if ( v24 <= v11 )
            v47 = 0.0;
          else
            v47 = v24;
          if ( v20 <= 0.0 )
            v44 = 0.0;
          else
            v44 = (float)(v52 * v29) + v56;
          v18 = coord;
          if ( coord <= 0.0 )
            v51 = 0.0;
          else
            v51 = coord;
          if ( (unsigned int)(__int64)v51 < m_clouds_size_x
            && (unsigned int)(__int64)v44 < this->m_clouds_size_y
            && (unsigned int)(__int64)v47 < m_clouds_size_z )
          {
            v16 = i;
            v12 = x;
            goto LABEL_41;
          }
          v12 = x;
LABEL_54:
          v5 = clear_value;
          v13 = y;
          v15 = v35;
LABEL_55:
          v25 = v11;
          v26 = accumulated / (double)num;
          if ( v25 < v26 )
          {
            v3 = v26;
            accumulateda = v26;
            if ( *(float *)&v5 < accumulateda )
              v3 = *(float *)&v5;
          }
          v27 = powf(*(float *)&v5 - v3, init_key->extinction);
          v3 = 0.0;
          if ( v27 > 0.0 )
          {
            v28 = v27;
            v36 = v27;
            if ( *(float *)&clear_value < v36 )
              v28 = *(float *)&clear_value;
          }
          else
          {
            v28 = 0.0;
          }
          v11 = 0.0;
          v10 = 1.0;
          v5 = clear_value;
          v.y = (int)(float)(v28 * 255.0);
          this->m_voxels[v12 + v15 * this->m_clouds_size_x] = v;
LABEL_63:
          y = ++v13;
        }
        while ( v13 < this->m_clouds_size_y );
LABEL_64:
        x = ++v12;
      }
      while ( v12 < this->m_clouds_size_x );
LABEL_65:
      ++za;
    }
    while ( za < this->m_clouds_size_z );
  }
}
