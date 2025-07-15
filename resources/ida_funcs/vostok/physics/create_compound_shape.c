vostok::physics::bt_collision_shape *__usercall vostok::physics::create_compound_shape@<eax>(
        const vostok::configs::binary_config_value *shapes_root@<eax>,
        float a2@<xmm4>,
        const vostok::math::float3 *local_scale)
{
  vostok::configs::binary_config_value *pointer; // ebx
  void *v5; // eax
  btCompoundShape *v6; // ecx
  unsigned int v7; // esi
  int v8; // edi
  const void *v9; // esi
  float *v10; // eax
  __int64 v11; // xmm0_8
  float *v12; // eax
  float v13; // edx
  const vostok::configs::binary_config_value *v14; // eax
  __int64 v15; // xmm0_8
  float v16; // eax
  __int16 v17; // ax
  btCollisionShape *v18; // eax
  const vostok::math::float4x4 *v19; // esi
  const vostok::math::float4x4 *v20; // eax
  float v21; // xmm5_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm5_4
  btVector3 v25; // xmm0
  void (__thiscall *setLocalScaling)(struct btCompoundShape *, const btVector3 *); // edx
  _DWORD *v27; // eax
  _DWORD *v28; // esi
  vostok::resources::unmanaged_resource *v29; // ecx
  vostok::physics::bt_collision_shape *v30; // eax
  unsigned int v31; // [esp+C04h] [ebp-1D0h]
  btCompoundShape *v32; // [esp+C18h] [ebp-1BCh]
  _WORD *v33; // [esp+C1Ch] [ebp-1B8h]
  float v34; // [esp+C20h] [ebp-1B4h]
  float v35; // [esp+C20h] [ebp-1B4h]
  float v36; // [esp+C28h] [ebp-1ACh]
  vostok::configs::binary_config_value *v37; // [esp+C30h] [ebp-1A4h]
  __m128i v38; // [esp+C34h] [ebp-1A0h] BYREF
  float v39; // [esp+C50h] [ebp-184h]
  float _X; // [esp+C54h] [ebp-180h]
  float angle; // [esp+C58h] [ebp-17Ch] BYREF
  vostok::math::float3 axis; // [esp+C5Ch] [ebp-178h] BYREF
  btCollisionShape *shape; // [esp+C68h] [ebp-16Ch]
  float v44; // [esp+C6Ch] [ebp-168h]
  float v45; // [esp+C70h] [ebp-164h]
  float v46; // [esp+C74h] [ebp-160h]
  float v47; // [esp+C78h] [ebp-15Ch]
  float v48; // [esp+C7Ch] [ebp-158h]
  float v49; // [esp+C80h] [ebp-154h]
  vostok::math::float3 v50; // [esp+C90h] [ebp-144h] BYREF
  vostok::math::float3 angles; // [esp+C9Ch] [ebp-138h] BYREF
  vostok::math::float3 v52; // [esp+CA8h] [ebp-12Ch] BYREF
  btTransform localTransform; // [esp+CB4h] [ebp-120h] BYREF
  float v54[2]; // [esp+CFCh] [ebp-D8h]
  vostok::math::quaternion v55; // [esp+D04h] [ebp-D0h] BYREF
  vostok::math::float4x4 matrix_raw; // [esp+D14h] [ebp-C0h] BYREF
  vostok::math::float4x4 result; // [esp+D54h] [ebp-80h] BYREF
  vostok::math::float4x4 v58; // [esp+D94h] [ebp-40h] BYREF

  pointer = (vostok::configs::binary_config_value *)shapes_root->data.pointer;
  v37 = (vostok::configs::binary_config_value *)((char *)shapes_root->data.pointer + 24 * shapes_root->count);
  v5 = vostok::physics::g_ph_allocator->call_malloc(vostok::physics::g_ph_allocator, 96);
  if ( v5 )
    v32 = btCompoundShape::btCompoundShape(v6, (int)v5);
  else
    v32 = 0;
  v7 = 2 * (24 * shapes_root->count / 24);
  v8 = ((int (__stdcall *)(unsigned int))vostok::physics::g_ph_allocator->call_malloc)(v7);
  memset(v8, 0, v7);
  if ( pointer != v37 )
  {
    v38.m128i_i32[3] = 0;
    v33 = (_WORD *)v8;
    do
    {
      v9 = vostok::configs::binary_config_value::operator[](pointer, "type")->data.pointer;
      v10 = (float *)vostok::configs::binary_config_value::operator[](pointer, "position")->data.pointer;
      v11 = *(_QWORD *)v10;
      v52.z = v10[2];
      *(_QWORD *)&v52.x = v11;
      v12 = (float *)vostok::configs::binary_config_value::operator[](pointer, "rotation")->data.pointer;
      v13 = v12[2];
      *(_QWORD *)&angles.x = *(_QWORD *)v12;
      angles.z = v13;
      v14 = vostok::configs::binary_config_value::operator[](pointer, "scale");
      v15 = *(_QWORD *)v14->data.pointer;
      v16 = *((float *)v14->data.pointer + 2);
      *(_QWORD *)&v50.x = v15;
      v50.z = v16;
      if ( vostok::configs::binary_config_value::value_exists(pointer, "mtl") )
        v17 = (__int16)vostok::configs::binary_config_value::operator[](pointer, "mtl")->data.pointer;
      else
        v17 = 0;
      *v33 = v17;
      vostok::physics::create_bt_primitive((vostok::collision::primitive_type)v9, &v50, a2);
      shape = v18;
      v19 = vostok::math::create_translation(&result, &v52);
      v20 = vostok::math::create_rotation(&v58, &angles);
      vostok::math::mul4x3(&matrix_raw, v20, v19);
      vostok::math::quaternion::quaternion(&v55, &matrix_raw);
      vostok::math::quaternion::get_axis_and_angle(&v55, &axis, &angle);
      _X = angle * 0.5;
      v54[0] = -axis.z;
      v34 = sinf(_X);
      v35 = v34 / sqrtf((float)((float)(axis.x * axis.x) + (float)(axis.y * axis.y)) + (float)(v54[0] * v54[0]));
      v46 = v35 * axis.x;
      v47 = v35 * axis.y;
      v48 = v54[0] * v35;
      v49 = cosf(_X);
      v38.m128i_i64[0] = *(_QWORD *)&matrix_raw.lines[3].x;
      *(float *)&v38.m128i_i32[2] = -matrix_raw.c.z;
      v21 = 2.0
          / (float)((float)((float)((float)(v47 * v47) + (float)(v46 * v46)) + (float)(v48 * v48)) + (float)(v49 * v49));
      v22 = v21 * v46;
      v23 = v48 * v21;
      v45 = v49 * (float)(v21 * v46);
      v44 = v47 * v21;
      v39 = v49 * (float)(v47 * v21);
      v36 = v49 * (float)(v48 * v21);
      v24 = (float)(v48 * v21) * v46;
      localTransform.m_basis.m_el[1].mVec128.m128_f32[0] = (float)(v44 * v46) + v36;
      localTransform.m_basis.m_el[0].mVec128.m128_f32[1] = (float)(v44 * v46) - v36;
      localTransform.m_basis.m_el[0].mVec128.m128_f32[0] = *(float *)&clear_value
                                                         - (float)((float)(v48 * v23) + (float)(v47 * v44));
      localTransform.m_basis.m_el[1].mVec128.m128_f32[1] = *(float *)&clear_value
                                                         - (float)((float)(v48 * v23) + (float)(v22 * v46));
      a2 = v49 * v22;
      localTransform.m_basis.m_el[0].mVec128.m128_f32[2] = v24 + v39;
      localTransform.m_basis.m_el[2].mVec128.m128_f32[1] = (float)(v47 * v23) + (float)(v49 * v22);
      v25.mVec128 = (__m128)_mm_load_si128(&v38);
      localTransform.m_basis.m_el[0].mVec128.m128_i32[3] = 0;
      localTransform.m_basis.m_el[1].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)(v47 * v23) - (float)(v49 * v22));
      localTransform.m_basis.m_el[2].mVec128.m128_f32[0] = v24 - v39;
      localTransform.m_basis.m_el[2].mVec128.m128_f32[2] = *(float *)&clear_value
                                                         - (float)((float)(v47 * v44) + (float)(v22 * v46));
      localTransform.m_basis.m_el[2].mVec128.m128_i32[3] = 0;
      localTransform.m_origin = (btVector3)v25.mVec128;
      btCompoundShape::addChildShape(v32, &localTransform, shape);
      ++v33;
      ++pointer;
    }
    while ( pointer != v37 );
  }
  setLocalScaling = v32->setLocalScaling;
  v38.m128i_i64[0] = *(_QWORD *)&local_scale->x;
  v38.m128i_i64[1] = LODWORD(local_scale->z);
  setLocalScaling(v32, (const btVector3 *)&v38);
  v27 = vostok::physics::g_ph_allocator->call_malloc(vostok::physics::g_ph_allocator, 280);
  v28 = v27;
  if ( v27 )
  {
    vostok::resources::resource_base::resource_base(
      (vostok::resources::resource_base *)4,
      (int)v27,
      unknown_data_class,
      1u,
      v31);
    v28[52] = 0;
    v28[53] = 0;
    *v28 = &vostok::resources::unmanaged_resource::`vftable';
    v28[54] = 0;
    v28[55] = 0;
    v28[57] = 0;
    v28[64] = 0;
    vostok::resources::unmanaged_resource::constructor_impl(v29, (int)v28);
    v28[67] = 0;
    *v28 = &vostok::physics::bt_collision_shape::`vftable';
    v28[66] = v32;
    v32->m_userPointer = v28;
    v28[68] = v8;
    return (vostok::physics::bt_collision_shape *)v28;
  }
  else
  {
    v30 = 0;
    MEMORY[0x110] = v8;
  }
  return v30;
}
