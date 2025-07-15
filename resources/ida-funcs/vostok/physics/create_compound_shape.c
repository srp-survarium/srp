void __cdecl vostok::physics::create_compound_shape(
        const vostok::configs::binary_config_value *shapes_root,
        const vostok::math::float3 *local_scale)
{
  const vostok::configs::binary_config_value *v3; // esi
  vostok::memory::base_allocator *v4; // edi
  vostok::configs::binary_config_value *v5; // ebx
  char *v6; // eax
  int v7; // eax
  btCompoundShape *v8; // ecx
  int v9; // eax
  vostok::memory::base_allocator *v10; // esi
  char *v11; // eax
  int v12; // esi
  float **v13; // eax
  float *v14; // esi
  float **v15; // eax
  float *v16; // esi
  float **v17; // eax
  float *v18; // esi
  vostok::configs::binary_config_value *v19; // ecx
  __int16 v20; // ax
  vostok::memory::base_allocator *v21; // esi
  btCollisionShape *v22; // eax
  btCollisionShape *v23; // esi
  vostok::math::float4x4 *v24; // edi
  vostok::math::float4x4 *v25; // eax
  int v26; // eax
  vostok::physics::bt_collision_shape *v27; // eax
  int v28; // eax
  btCompoundShape *v29; // [esp+18h] [ebp-154h]
  vostok::resources::unmanaged_resource *v30; // [esp+18h] [ebp-154h]
  vostok::configs::binary_config_value *pointer; // [esp+28h] [ebp-144h]
  vostok::memory::base_allocator *counta; // [esp+2Ch] [ebp-140h]
  unsigned int countb; // [esp+2Ch] [ebp-140h]
  _WORD *count; // [esp+2Ch] [ebp-140h]
  const btTransform *localTransform; // [esp+30h] [ebp-13Ch]
  const void *v36; // [esp+34h] [ebp-138h]
  unsigned __int8 *v37; // [esp+38h] [ebp-134h]
  vostok::math::float3 v38; // [esp+3Ch] [ebp-130h] BYREF
  int v39; // [esp+48h] [ebp-124h]
  vostok::math::float3 v40; // [esp+54h] [ebp-118h] BYREF
  vostok::math::float3 v41; // [esp+60h] [ebp-10Ch] BYREF
  btTransform shape; // [esp+6Ch] [ebp-100h] BYREF
  vostok::math::float4x4 v43; // [esp+ACh] [ebp-C0h] BYREF
  vostok::math::float4x4 v44; // [esp+ECh] [ebp-80h] BYREF
  _BYTE v45[64]; // [esp+12Ch] [ebp-40h] BYREF

  v3 = shapes_root;
  v4 = vostok::physics::g_allocator;
  pointer = (vostok::configs::binary_config_value *)shapes_root->data.pointer;
  v5 = (vostok::configs::binary_config_value *)((char *)shapes_root->data.pointer + 24 * shapes_root->count);
  counta = vostok::physics::g_allocator;
  v6 = type_info::raw_name(&btCompoundShape `RTTI Type Descriptor');
  v7 = (int)v4->call_malloc(counta, 96u, v6, "vostok::physics::create_compound_shape", ".\\collision_shapes.cpp", 237u);
  if ( v7 )
  {
    v3 = shapes_root;
    localTransform = (const btTransform *)btCompoundShape::btCompoundShape(v8, v7);
  }
  else
  {
    localTransform = 0;
  }
  v9 = 24 * v3->count / 24;
  v10 = vostok::physics::g_allocator;
  countb = v9;
  v11 = type_info::raw_name(&unsigned short `RTTI Type Descriptor');
  countb *= 2;
  v12 = (int)v10->call_malloc(
               v10,
               countb,
               v11,
               "vostok::physics::create_compound_shape",
               ".\\collision_shapes.cpp",
               240u);
  v37 = (unsigned __int8 *)v12;
  memset(v12, 0, countb);
  if ( pointer != v5 )
  {
    count = (_WORD *)v12;
    do
    {
      v36 = vostok::configs::binary_config_value::operator[](pointer, "type")->data.pointer;
      v13 = (float **)vostok::configs::binary_config_value::operator[](pointer, "position");
      v14 = *v13;
      v41.x = **v13;
      *(_QWORD *)&v41.elements[1] = *(_QWORD *)(v14 + 1);
      v15 = (float **)vostok::configs::binary_config_value::operator[](pointer, "rotation");
      v16 = *v15;
      v38.x = **v15;
      *(_QWORD *)&v38.elements[1] = *(_QWORD *)(v16 + 1);
      v17 = (float **)vostok::configs::binary_config_value::operator[](pointer, "scale");
      v18 = *v17;
      v40.x = **v17;
      *(_QWORD *)&v40.elements[1] = *(_QWORD *)(v18 + 1);
      if ( vostok::configs::binary_config_value::value_exists(v19, (int)pointer, (unsigned int)"mtl") )
        v20 = (__int16)vostok::configs::binary_config_value::operator[](pointer, "mtl")->data.pointer;
      else
        v20 = 0;
      v21 = vostok::physics::g_allocator;
      *count = v20;
      vostok::physics::create_bt_primitive((vostok::collision::primitive_type)v36, &v40, v21);
      v23 = v22;
      v24 = vostok::math::create_translation(&v41, &v44);
      v25 = vostok::math::create_rotation(&v38, (int)v24, (int)v45);
      vostok::math::mul4x3(v24, v25, &v43);
      vostok::physics::from_vostok(&v43, &shape.m_basis);
      btCompoundShape::addChildShape(v29, localTransform, &shape, v23);
      ++pointer;
      ++count;
    }
    while ( pointer != v5 );
  }
  *(_QWORD *)&v38.x = *(_QWORD *)&local_scale->x;
  v26 = localTransform->m_basis.m_el[0].mVec128.m128_i32[0];
  v38.z = local_scale->z;
  v39 = 0;
  (*(void (__thiscall **)(const btTransform *, vostok::math::float3 *))(v26 + 20))(localTransform, &v38);
  v27 = (vostok::physics::bt_collision_shape *)vostok::memory::new_helper<vostok::physics::bt_collision_shape>::call<vostok::memory::base_allocator>(
                                                 vostok::physics::g_allocator,
                                                 "vostok::physics::create_compound_shape",
                                                 (const char *const)0x121);
  if ( v27 )
    vostok::physics::bt_collision_shape::bt_collision_shape(v27, (btCollisionShape *)localTransform, v30);
  else
    v28 = 0;
  *(_DWORD *)(v28 + 272) = v37;
}
