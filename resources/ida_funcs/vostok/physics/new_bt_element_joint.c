btCompoundShape *__usercall vostok::physics::new_bt_element_joint@<eax>(
        vostok::configs::binary_config_value *target@<eax>,
        float a2@<xmm4>,
        vostok::memory::base_allocator *allocator,
        vostok::collision::bone_collision_data *data)
{
  btCompoundShape *v5; // ecx
  const void *pointer; // esi
  const vostok::configs::binary_config_value *v7; // eax
  __int64 v8; // xmm0_8
  float v9; // eax
  float *v10; // eax
  _DWORD *v11; // eax
  __int64 v12; // xmm0_8
  btCollisionShape *v13; // eax
  btCollisionShape *v14; // ebx
  const vostok::math::float4x4 *v15; // esi
  const vostok::math::float4x4 *v16; // eax
  bool v18; // [esp+630h] [ebp-140h]
  vostok::math::float3 angles; // [esp+648h] [ebp-128h] BYREF
  vostok::math::float3 v20; // [esp+654h] [ebp-11Ch] BYREF
  vostok::math::float3 dimension; // [esp+660h] [ebp-110h] BYREF
  int v22; // [esp+66Ch] [ebp-104h]
  vostok::math::float4x4 m; // [esp+670h] [ebp-100h] BYREF
  btTransform localTransform; // [esp+6B0h] [ebp-C0h] BYREF
  vostok::math::float4x4 result; // [esp+6F0h] [ebp-80h] BYREF
  vostok::math::float4x4 v26; // [esp+730h] [ebp-40h] BYREF

  if ( allocator->call_malloc(allocator, 96) )
    LODWORD(angles.x) = btCompoundShape::btCompoundShape(v5, v18);
  else
    angles.x = 0.0;
  pointer = vostok::configs::binary_config_value::operator[](target, "type")->data.pointer;
  v7 = vostok::configs::binary_config_value::operator[](target, "position");
  v8 = *(_QWORD *)v7->data.pointer;
  v9 = *((float *)v7->data.pointer + 2);
  *(_QWORD *)&v20.elements[1] = v8;
  dimension.x = v9;
  v10 = (float *)vostok::configs::binary_config_value::operator[](target, "rotation")->data.pointer;
  v20.x = v10[2];
  *(_QWORD *)&angles.elements[1] = *(_QWORD *)v10;
  v11 = vostok::configs::binary_config_value::operator[](target, "scale")->data.pointer;
  v12 = *(_QWORD *)v11;
  v22 = v11[2];
  *(_QWORD *)&dimension.elements[1] = v12;
  vostok::physics::new_bt_primitive(
    (const vostok::collision::primitive_type)pointer,
    (vostok::math::float3 *)&dimension.elements[1],
    allocator,
    a2);
  v14 = v13;
  v13->m_userPointer = data;
  v15 = vostok::math::create_translation(&result, (vostok::math::float3 *)&v20.elements[1]);
  v16 = vostok::math::create_rotation(&v26, (vostok::math::float3 *)&angles.elements[1]);
  vostok::math::mul4x3(&m, v16, v15);
  vostok::physics::from_vostok(&m, (vostok::math::quaternion *)&localTransform);
  btCompoundShape::addChildShape((btCompoundShape *)LODWORD(angles.x), &localTransform, v14);
  return (btCompoundShape *)LODWORD(angles.x);
}
