void __thiscall vostok::render::sky_ambient_occlusion::set_properties(
        vostok::render::sky_ambient_occlusion *this,
        const vostok::render::sky_ambient_occlusion_properties *in_properties,
        vostok::fixed_string<260> *a3)
{
  const vostok::render::sky_ambient_occlusion_properties *v3; // edi
  int v4; // ecx
  const char *v5; // edi
  char *v6; // esi
  bool v7; // cf
  bool v8; // zf
  vostok::render::res_texture *texture; // eax
  vostok::render::resource_manager *v10; // esi
  vostok::math::aabb scale; // [esp+10h] [ebp-58h] BYREF
  vostok::math::float4x4 v12; // [esp+28h] [ebp-40h] BYREF

  vostok::fixed_string<260>::operator=(a3, (const vostok::fixed_string<260> *)&in_properties->texture_name.m_end);
  *(_QWORD *)&in_properties->location.elements[1] = *(_QWORD *)&a3[1].m_begin;
  LODWORD(in_properties->width) = a3[1].m_max_end;
  in_properties->height = *(float *)a3[1].m_buffer;
  v3 = in_properties;
  in_properties->depth = *(float *)&a3[1].m_buffer[4];
  *(float *)&in_properties->enabled = *(float *)&a3[1].m_buffer[8];
  LOBYTE(in_properties[1].texture_name.m_begin) = a3[1].m_buffer[12];
  BYTE1(in_properties[1].texture_name.m_begin) = a3[1].m_buffer[13];
  if ( a3[1].m_buffer[13] )
  {
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      0,
      (vostok::render::res_texture *)&in_properties[1].texture_name.m_buffer[16]);
    if ( in_properties == (const vostok::render::sky_ambient_occlusion_properties *)-16 )
      goto LABEL_9;
    v5 = "null";
    v6 = &in_properties->texture_name.m_buffer[4];
    v4 = 5;
    texture = 0;
    v7 = 0;
    v8 = 1;
    do
    {
      if ( !v4 )
        break;
      v7 = (unsigned __int8)*v6 < (unsigned int)*v5;
      v8 = *v6++ == *v5++;
      --v4;
    }
    while ( v8 );
    if ( !v8 )
      texture = (vostok::render::res_texture *)(-v7 - (v7 - 1));
    v3 = in_properties;
    if ( texture )
    {
LABEL_9:
      v10 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
      texture = (vostok::render::res_texture *)vostok::render::resource_manager::find_texture(
                                                 (vostok::render::resource_manager *)v4,
                                                 (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                                 &in_properties->texture_name.m_buffer[4]);
      if ( !texture )
        texture = vostok::render::resource_manager::load_texture(
                    v10,
                    &v3->texture_name.m_buffer[4],
                    0,
                    0,
                    0,
                    1,
                    1,
                    0xFFFFFFFF,
                    1,
                    0);
    }
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      texture,
      (vostok::render::res_texture *)&v3[1].texture_name.m_buffer[16]);
  }
  vostok::math::create_translation((const vostok::math::float3 *)&a3[1], &v12);
  scale.min.x = *(float *)a3[1].m_buffer;
  scale.min.y = *(float *)&a3[1].m_buffer[8];
  scale.min.z = *(float *)&a3[1].m_buffer[4];
  vostok::math::float4x4::set_scale(&v12, &scale.min);
  qmemcpy(&v3[1].texture_name.m_end, vostok::math::create_identity_aabb(&scale), 0x18u);
  vostok::math::aabb::modify((vostok::math::aabb *)&v12, (vostok::math::aabb *)&v3[1].texture_name.m_end);
}
