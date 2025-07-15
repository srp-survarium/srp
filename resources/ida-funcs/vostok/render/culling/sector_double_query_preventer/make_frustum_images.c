void __thiscall vostok::render::culling::sector_double_query_preventer::make_frustum_images(
        vostok::render::culling::sector_double_query_preventer *this,
        const vostok::math::float3 *furthest_vertices,
        int a3)
{
  const vostok::math::float3 *v3; // esi
  float y; // eax
  const vostok::math::frustum **v5; // edi
  vostok::buffer_vector<vostok::render::culling::sector_double_query_preventer::frustum_image> *y_low; // ecx
  const vostok::math::frustum *v7; // eax
  int v8; // eax
  char v9; // dl
  int v10; // eax
  float *v11; // esi
  vostok::buffer_vector<vostok::render::culling::sector_double_query_preventer::frustum_image> *v12; // ecx
  float *v13; // ebx
  float *v14; // esi
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  int v21; // ecx
  const vostok::math::frustum *v22; // ebx
  vostok::buffer_vector<vostok::render::culling::sector_double_query_preventer::frustum_image> *v23; // [esp-4h] [ebp-17Ch]
  vostok::math::frustum v24; // [esp+10h] [ebp-168h] BYREF
  _BYTE v25[96]; // [esp+8Ch] [ebp-ECh] BYREF
  int v26; // [esp+ECh] [ebp-8Ch]
  vostok::math::plane v27[6]; // [esp+F0h] [ebp-88h] BYREF
  float v28; // [esp+154h] [ebp-24h]
  float v29; // [esp+158h] [ebp-20h]
  float v30; // [esp+15Ch] [ebp-1Ch]
  const vostok::math::frustum **v31; // [esp+160h] [ebp-18h]
  vostok::buffer_vector<vostok::render::culling::sector_double_query_preventer::frustum_image> *v32; // [esp+164h] [ebp-14h]
  const vostok::math::frustum **v33; // [esp+168h] [ebp-10h]
  int v34; // [esp+16Ch] [ebp-Ch]
  const vostok::math::frustum *v35; // [esp+170h] [ebp-8h]
  float *v36; // [esp+174h] [ebp-4h]
  float *v37; // [esp+184h] [ebp+Ch]

  v34 = 0;
  v3 = furthest_vertices;
  furthest_vertices[1].z = furthest_vertices[1].y;
  y = furthest_vertices->y;
  v5 = *(const vostok::math::frustum ***)LODWORD(y);
  v31 = *(const vostok::math::frustum ***)(LODWORD(y) + 4);
  v33 = v5;
  if ( v5 != v31 )
  {
    v36 = (float *)(a3 + 4);
    do
    {
      y_low = (vostok::buffer_vector<vostok::render::culling::sector_double_query_preventer::frustum_image> *)LODWORD(v3->y);
      v7 = v5[1];
      v35 = v7;
      if ( v5 == (const vostok::math::frustum **)y_low->m_begin )
      {
        v22 = *v5;
        if ( *v5 != v7 )
        {
          do
          {
            v26 = -1;
            vostok::buffer_vector<vostok::render::culling::sector_double_query_preventer::frustum_image>::push_back(
              y_low,
              (const vostok::render::culling::sector_double_query_preventer::frustum_image *)&v3[1].elements[1],
              v25);
            vostok::math::get_frustum_vertices(v22++, (vostok::math::float3 (*)[8])(LODWORD(v3[1].z) - 100));
            y_low = v23;
            *(_DWORD *)(LODWORD(v3[1].z) - 4) = -16711936;
          }
          while ( v22 != v35 );
        }
      }
      else
      {
        v8 = 134775813 * v34 + 1;
        v9 = (unsigned __int64)(unsigned int)v8 >> 25;
        v10 = 134775813 * v8 + 1;
        v34 = 134775813 * v10 + 1;
        v11 = (float *)*v5;
        v12 = (vostok::buffer_vector<vostok::render::culling::sector_double_query_preventer::frustum_image> *)((unsigned __int8)(((unsigned __int64)(unsigned int)v34 >> 25) + 0x80) | (((unsigned __int8)(((unsigned __int64)(unsigned int)v10 >> 25) + 0x80) | (((v9 + 0x80) | 0xFFFFFF00) << 8)) << 8));
        v32 = v12;
        v37 = v11;
        if ( v11 == (float *)v35 )
        {
          v3 = furthest_vertices;
        }
        else
        {
          v13 = v11 + 22;
          while ( 1 )
          {
            v26 = -1;
            vostok::buffer_vector<vostok::render::culling::sector_double_query_preventer::frustum_image>::push_back(
              v12,
              (const vostok::render::culling::sector_double_query_preventer::frustum_image *)&furthest_vertices[1].elements[1],
              v25);
            v27[0].normal.x = *v11;
            v14 = v11 + 1;
            v27[0].normal.y = *v14;
            *(_QWORD *)&v27[0].vector.elements[2] = *(_QWORD *)(v14 + 1);
            v27[1] = *(vostok::math::plane *)(v13 - 17);
            v27[2] = (vostok::math::plane)*((_OWORD *)v13 - 3);
            v15 = *(v13 - 2);
            v16 = *(v13 - 1);
            v17 = *v13;
            v18 = *(v36 - 1);
            v27[3] = *(vostok::math::plane *)(v13 - 7);
            v28 = v15;
            v29 = v16;
            v30 = v17;
            v19 = v18 * v15;
            v20 = *v36;
            *(_QWORD *)&v27[4].normal.x = __PAIR64__(LODWORD(v16), LODWORD(v28));
            v27[4].normal.z = v17;
            LODWORD(v27[4].d) = COERCE_UNSIGNED_INT((float)(v19 + (float)(v20 * v16)) + (float)(v36[1] * v17))
                              ^ _mask__NegFloat_;
            v27[5] = *(vostok::math::plane *)(v13 + 3);
            vostok::math::frustum::frustum(v21, (const vostok::math::plane (*)[6])v27, &v24);
            v3 = furthest_vertices;
            vostok::math::get_frustum_vertices(
              &v24,
              (vostok::math::float3 (*)[8])(LODWORD(furthest_vertices[1].z) - 100));
            v37 += 30;
            v12 = v32;
            *(_DWORD *)(LODWORD(furthest_vertices[1].z) - 4) = v32;
            v13 += 30;
            if ( v37 == (float *)v35 )
              break;
            v11 = v37;
          }
          v5 = v33;
        }
      }
      v36 += 3;
      v5 = (const vostok::math::frustum **)((char *)v5 + (_DWORD)&loc_1E00A + 2);
      v33 = v5;
    }
    while ( v5 != v31 );
  }
}
