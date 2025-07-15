void __thiscall vostok::render::culling::portal_sector_structure::load(
        vostok::render::culling::portal_sector_structure *this,
        vostok::configs::binary_config_value *value_ptr,
        vostok::configs::binary_config_value *a3)
{
  const void *pointer; // esi
  char *v5; // eax
  int v6; // eax
  vostok::math::float4x4 *v7; // ecx
  float x; // ecx
  int v9; // esi
  vostok::math::float3 *v10; // eax
  vostok::memory::base_allocator *v11; // eax
  vostok::collision::object *v12; // eax
  const vostok::configs::binary_config_value *v13; // eax
  _DWORD *v14; // edx
  float v15; // ecx
  int v16; // eax
  int v17; // esi
  _DWORD *v18; // edi
  vostok::render::culling::portal_sector_structure *v19; // ecx
  int v20; // esi
  int v21; // esi
  int v22; // esi
  int v23; // edi
  vostok::memory::base_allocator *v24; // eax
  vostok::collision::object *v25; // eax
  vostok::buffer_vector<vostok::render::culling::portal> *v26; // [esp-4h] [ebp-184h]
  void *v27; // [esp-4h] [ebp-184h]
  vostok::math::float4x4 v28; // [esp+10h] [ebp-170h] BYREF
  vostok::math::plane v29; // [esp+54h] [ebp-12Ch] BYREF
  int v30; // [esp+64h] [ebp-11Ch]
  int v31; // [esp+68h] [ebp-118h]
  vostok::math::float3 max; // [esp+6Ch] [ebp-114h]
  __int64 v33; // [esp+78h] [ebp-108h]
  float z; // [esp+80h] [ebp-100h]
  __int64 v35; // [esp+84h] [ebp-FCh]
  float v36; // [esp+8Ch] [ebp-F4h]
  vostok::math::float3 v37; // [esp+90h] [ebp-F0h]
  char v38; // [esp+9Ch] [ebp-E4h]
  _BYTE v39[24]; // [esp+A0h] [ebp-E0h] BYREF
  _DWORD *v40; // [esp+B8h] [ebp-C8h]
  int v41; // [esp+BCh] [ebp-C4h]
  _DWORD v42[6]; // [esp+C0h] [ebp-C0h] BYREF
  _DWORD v43[6]; // [esp+D8h] [ebp-A8h] BYREF
  vostok::math::float3 v44[2]; // [esp+F0h] [ebp-90h] BYREF
  vostok::math::aabb v45; // [esp+10Ch] [ebp-74h] BYREF
  int v46; // [esp+124h] [ebp-5Ch]
  int v47; // [esp+128h] [ebp-58h]
  vostok::math::aabb epsilon; // [esp+12Ch] [ebp-54h] BYREF
  vostok::math::aabb position; // [esp+144h] [ebp-3Ch] BYREF
  void *user_data; // [esp+15Ch] [ebp-24h]
  vostok::math::aabb other; // [esp+160h] [ebp-20h] BYREF
  int **i; // [esp+178h] [ebp-8h]
  _DWORD *v53; // [esp+17Ch] [ebp-4h]
  int x_low; // [esp+188h] [ebp+8h]
  int v55; // [esp+188h] [ebp+8h]
  vostok::configs::binary_config_value *j; // [esp+18Ch] [ebp+Ch]
  char v57; // [esp+18Fh] [ebp+Fh]

  qmemcpy(v43, vostok::configs::binary_config_value::operator[](a3, "portals"), sizeof(v43));
  pointer = value_ptr[11].data.pointer;
  v5 = type_info::raw_name(&unsigned int `RTTI Type Descriptor');
  v6 = (*(int (__fastcall **)(const void *, int, int, char *, const char *, const char *, int))(*(_DWORD *)pointer + 16))(
         pointer,
         24 * HIWORD(v43[5]) % 24,
         8 * (24 * HIWORD(v43[5]) / 24),
         v5,
         "vostok::render::culling::portal_sector_structure::load",
         ".\\portal_sector_structure.cpp",
         135);
  user_data = 0;
  *(_DWORD *)&value_ptr[11].type = v6;
  v53 = (_DWORD *)v6;
  vostok::math::float4x4::identity(v7, &v28);
  qmemcpy(&other, vostok::configs::binary_config_value::operator[](a3, "sectors"), sizeof(other));
  x = other.min.x;
  v46 = LODWORD(other.min.x) + 24 * HIWORD(other.max.elements[2]);
  x_low = LODWORD(other.min.x);
  if ( LODWORD(other.min.x) != v46 )
  {
    memset(&epsilon.max, 0, sizeof(epsilon.max));
    memset(&position.max, 0, sizeof(position.max));
    do
    {
      v45.min = position.max;
      v45.max = epsilon.max;
      v57 = 0;
      if ( vostok::configs::binary_config_value::value_exists(
             (vostok::configs::binary_config_value *)LODWORD(x),
             x_low,
             (unsigned int)"volumes") )
      {
        qmemcpy(
          v42,
          vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)x_low, "volumes"),
          sizeof(v42));
        v47 = v42[0] + 24 * HIWORD(v42[5]);
        for ( i = (int **)v42[0]; i != (int **)v47; i += 6 )
        {
          v9 = **i;
          v10 = (vostok::math::float3 *)(*i)[6];
          other.min.x = *(float *)v9;
          *(_QWORD *)&other.min.elements[1] = *(_QWORD *)(v9 + 4);
          other.max = *v10;
          epsilon.min.x = (float)(other.max.x - other.min.x) * 0.5;
          epsilon.min.y = (float)(other.max.y - other.min.y) * 0.5;
          epsilon.min.z = (float)(other.max.z - other.min.z) * 0.5;
          v11 = (vostok::memory::base_allocator *)value_ptr[11].data.pointer;
          position.min.x = (float)(other.min.x + other.max.x) * 0.5;
          position.min.y = (float)(other.min.y + other.max.y) * 0.5;
          position.min.z = (float)(other.min.z + other.max.z) * 0.5;
          v12 = vostok::collision::new_aabb_object(v11, 1u, &position.min, &epsilon.min, user_data);
          (**(void (__thiscall ***)(unsigned int, vostok::collision::object *, vostok::math::float4x4 *))value_ptr[12].id_crc)(
            value_ptr[12].id_crc,
            v12,
            &v28);
          if ( v57 )
          {
            vostok::math::aabb::modify(&other, &v45);
          }
          else
          {
            qmemcpy(&v45, &other, sizeof(v45));
            v57 = 1;
          }
        }
      }
      v13 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)x_low, "portals");
      v14 = v53;
      qmemcpy(v44, v13, sizeof(v44));
      v15 = v44[0].x;
      v16 = LODWORD(v44[0].x) + 24 * HIWORD(v44[1].elements[2]);
      while ( LODWORD(v15) != v16 )
      {
        v17 = *(_DWORD *)LODWORD(v15);
        v18 = v53++;
        *v18 = v17;
        LODWORD(v15) += 24;
      }
      qmemcpy(v39, &v45, sizeof(v39));
      v40 = v14;
      v41 = 24 * HIWORD(v44[1].elements[2]) / 24;
      vostok::buffer_vector<vostok::render::culling::spatial_sector>::push_back(
        (vostok::buffer_vector<vostok::render::culling::spatial_sector> *)0x18,
        (const vostok::render::culling::spatial_sector *)((char *)&value_ptr[12].data.max_storage + 4),
        v39);
      x_low += 24;
      user_data = (char *)user_data + 1;
    }
    while ( x_low != v46 );
  }
  v19 = (vostok::render::culling::portal_sector_structure *)v43[0];
  v55 = v43[0] + 24 * HIWORD(v43[5]);
  for ( j = (vostok::configs::binary_config_value *)v43[0]; j != (vostok::configs::binary_config_value *)v55; ++j )
  {
    qmemcpy(v42, vostok::configs::binary_config_value::operator[](j, "points"), sizeof(v42));
    position.max = *(vostok::math::float3 *)*(_DWORD *)v42[0];
    v20 = *(_DWORD *)(v42[0] + 24);
    position.min.x = *(float *)v20;
    *(_QWORD *)&position.min.elements[1] = *(_QWORD *)(v20 + 4);
    v21 = *(_DWORD *)(v42[0] + 48);
    epsilon.min.x = *(float *)v21;
    *(_QWORD *)&epsilon.min.elements[1] = *(_QWORD *)(v21 + 4);
    v45.max = *(vostok::math::float3 *)*(_DWORD *)(v42[0] + 72);
    qmemcpy(v43, vostok::configs::binary_config_value::operator[](j, "sectors"), sizeof(v43));
    v22 = *(_DWORD *)v43[0];
    v23 = *(_DWORD *)(v43[0] + 24);
    vostok::math::create_plane(&position.max, &epsilon.min, &v29, &position.min.x);
    v30 = v22;
    v31 = v23;
    v38 = 1;
    max = position.max;
    v33 = *(_QWORD *)&position.min.x;
    z = position.min.z;
    v35 = *(_QWORD *)&epsilon.min.x;
    v36 = epsilon.min.z;
    v37 = v45.max;
    vostok::buffer_vector<vostok::render::culling::portal>::push_back(
      v26,
      (const vostok::render::culling::portal *)&value_ptr[11].id,
      &v29);
    other.min = position.max;
    other.max = position.max;
    vostok::math::aabb::modify(&position, &other);
    vostok::math::aabb::modify(&epsilon, &other);
    vostok::math::aabb::modify((vostok::math::aabb *)&v45.max, &other);
    v27 = (void *)(HIDWORD(value_ptr[11].id.max_storage) - 76);
    epsilon.max.x = (float)(other.max.x - other.min.x) * 0.5;
    epsilon.max.y = (float)(other.max.y - other.min.y) * 0.5;
    epsilon.max.z = (float)(other.max.z - other.min.z) * 0.5;
    v24 = (vostok::memory::base_allocator *)value_ptr[11].data.pointer;
    v44[1].x = (float)(other.max.x + other.min.x) * 0.5;
    v44[1].y = (float)(other.max.y + other.min.y) * 0.5;
    v44[1].z = (float)(other.max.z + other.min.z) * 0.5;
    v25 = vostok::collision::new_aabb_object(v24, 2u, &v44[1], &epsilon.max, v27);
    (***(void (__thiscall ****)(_DWORD, vostok::collision::object *, vostok::math::float4x4 *))&value_ptr[12].type)(
      *(_DWORD *)&value_ptr[12].type,
      v25,
      &v28);
  }
  vostok::render::culling::portal_sector_structure::initialize_portals_geometry(v19, (int)value_ptr);
}
