const btTransform *__usercall vostok::physics::new_bt_element_joint@<eax>(
        float a1@<xmm10>,
        const vostok::configs::binary_config_value *target,
        vostok::memory::base_allocator *allocator,
        vostok::collision::bone_collision_data *data)
{
  char *v4; // eax
  void *v5; // eax
  btCompoundShape *v6; // ecx
  const void *pointer; // ebx
  float **v8; // eax
  float *v9; // esi
  float **v10; // eax
  float *v11; // esi
  float **v12; // eax
  float *v13; // esi
  btCollisionShape *v14; // eax
  btCollisionShape *v15; // esi
  vostok::math::float4x4 *v16; // edi
  vostok::math::float4x4 *v17; // eax
  btCompoundShape *v19; // [esp-4h] [ebp-144h]
  const btTransform *localTransform; // [esp+18h] [ebp-128h]
  vostok::math::float3 v21; // [esp+1Ch] [ebp-124h] BYREF
  vostok::math::float3 v22; // [esp+28h] [ebp-118h] BYREF
  vostok::math::float3 dim; // [esp+34h] [ebp-10Ch] BYREF
  vostok::math::float4x4 m; // [esp+40h] [ebp-100h] BYREF
  btTransform shape; // [esp+80h] [ebp-C0h] BYREF
  vostok::math::float4x4 v26; // [esp+C0h] [ebp-80h] BYREF
  _BYTE v27[64]; // [esp+100h] [ebp-40h] BYREF

  v4 = type_info::raw_name(&btCompoundShape `RTTI Type Descriptor');
  v5 = allocator->call_malloc(
         allocator,
         96,
         v4,
         "vostok::physics::new_bt_element_joint",
         ".\\animated_rigid_body.cpp",
         88);
  if ( v5 )
    localTransform = (const btTransform *)btCompoundShape::btCompoundShape(v6, (int)v5);
  else
    localTransform = 0;
  pointer = vostok::configs::binary_config_value::operator[](target, "type")->data.pointer;
  v8 = (float **)vostok::configs::binary_config_value::operator[](target, "position");
  v9 = *v8;
  v22.x = **v8;
  *(_QWORD *)&v22.elements[1] = *(_QWORD *)(v9 + 1);
  v10 = (float **)vostok::configs::binary_config_value::operator[](target, "rotation");
  v11 = *v10;
  v21.x = **v10;
  *(_QWORD *)&v21.elements[1] = *(_QWORD *)(v11 + 1);
  v12 = (float **)vostok::configs::binary_config_value::operator[](target, "scale");
  v13 = *v12;
  dim.x = **v12;
  *(_QWORD *)&dim.elements[1] = *(_QWORD *)(v13 + 1);
  vostok::physics::create_bt_primitive((vostok::collision::primitive_type)pointer, &dim, allocator, a1);
  v15 = v14;
  v14->m_userPointer = data;
  v16 = vostok::math::create_translation(&v22, &v26);
  v17 = vostok::math::create_rotation(&v21, (int)v16, (int)v27);
  vostok::math::mul4x3(v16, v17, &m);
  vostok::physics::from_vostok(&m, &shape.m_basis);
  btCompoundShape::addChildShape(v19, localTransform, &shape, v15);
  return localTransform;
}
