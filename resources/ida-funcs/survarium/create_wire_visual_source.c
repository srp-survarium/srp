void __cdecl survarium::create_wire_visual_source(
        vostok::memory::writer *writer,
        vostok::math::float3 *points,
        vostok::memory::writer *points_count,
        vostok::memory::writer *material_name)
{
  vostok::memory::writer *v4; // ebx
  vostok::memory::writer_base *v5; // ecx
  vostok::memory::writer_vtbl *v6; // eax
  vostok::memory::writer_base *v7; // ecx
  vostok::memory::writer *v8; // esi
  vostok::memory::writer_vtbl *v9; // eax
  vostok::memory::writer_base *v10; // ecx
  vostok::math::float3 *v11; // edi
  _BYTE v12[4]; // [esp+Ch] [ebp-38h] BYREF
  vostok::math::aabb v13; // [esp+10h] [ebp-34h] BYREF
  float v14; // [esp+38h] [ebp-Ch]
  float v15; // [esp+3Ch] [ebp-8h]
  float v16; // [esp+40h] [ebp-4h]

  v4 = writer;
  vostok::math::create_zero_aabb(&v13);
  v12[0] = 0;
  v13.min.x = FLOAT_N1_0;
  v13.min.y = FLOAT_N1_0;
  v13.min.z = FLOAT_N1_0;
  v14 = s_bm_current_air_resistance;
  v15 = s_bm_current_air_resistance;
  v16 = s_bm_current_air_resistance;
  *(_QWORD *)&v13.max.x = __PAIR64__(LODWORD(s_bm_current_air_resistance), LODWORD(s_bm_current_air_resistance));
  v13.max.z = s_bm_current_air_resistance;
  v12[1] = 101;
  vostok::memory::writer_base::open_chunk(v4, 1u);
  v4->write(v4, v12, 44u);
  vostok::memory::writer_base::close_chunk(v5, v4);
  vostok::memory::writer_base::open_chunk(v4, 2u);
  v4->write(v4, "editor/wire", strlen("editor/wire") + 1);
  v6 = v4->__vftable;
  writer = material_name;
  v6->write(v4, &writer, 4u);
  vostok::memory::writer_base::close_chunk(v7, v4);
  vostok::memory::writer_base::open_chunk(v4, 3u);
  v8 = points_count;
  v9 = v4->__vftable;
  writer = points_count;
  v9->write(v4, &writer, 4u);
  if ( v8 )
  {
    v11 = points;
    do
    {
      v4->write(v4, v11++, 12u);
      v8 = (vostok::memory::writer *)((char *)v8 - 1);
    }
    while ( v8 );
  }
  vostok::memory::writer_base::close_chunk(v10, v4);
}
