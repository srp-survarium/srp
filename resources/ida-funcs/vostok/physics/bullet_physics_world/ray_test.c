vostok::physics::closest_ray_result *__thiscall vostok::physics::bullet_physics_world::ray_test(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::closest_ray_result *result,
        const vostok::math::float3 *ray_from,
        const vostok::math::float3 *ray_dir,
        const float ray_length,
        unsigned __int16 filter_group,
        unsigned __int16 filter_mask,
        void *initiator,
        bool keep_unflipped_normal)
{
  float y; // xmm1_4
  float z; // xmm3_4
  float v11; // xmm6_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  btSoftRigidDynamicsWorld *m_dynamicsWorld; // ecx
  vostok::physics::closest_ray_result *v15; // eax
  int v16; // ecx
  vostok::physics::base_physics_object *v17; // ecx
  float v18; // xmm1_4
  float v19; // xmm0_4
  int v20; // ecx
  __int64 v21; // [esp+1Ch] [ebp-9Ch]
  float v23[2]; // [esp+28h] [ebp-90h] BYREF
  int v24; // [esp+30h] [ebp-88h]
  int v25; // [esp+34h] [ebp-84h]
  float v26[4]; // [esp+38h] [ebp-80h] BYREF
  void **v27; // [esp+48h] [ebp-70h] BYREF
  float v28; // [esp+4Ch] [ebp-6Ch]
  int v29; // [esp+50h] [ebp-68h]
  unsigned __int16 v30; // [esp+54h] [ebp-64h]
  unsigned __int16 v31; // [esp+56h] [ebp-62h]
  int v32; // [esp+58h] [ebp-60h]
  float v33; // [esp+68h] [ebp-50h]
  float v34; // [esp+6Ch] [ebp-4Ch]
  int v35; // [esp+70h] [ebp-48h]
  int v36; // [esp+74h] [ebp-44h]
  float v37; // [esp+78h] [ebp-40h]
  float v38; // [esp+7Ch] [ebp-3Ch]
  int v39; // [esp+80h] [ebp-38h]
  int v40; // [esp+84h] [ebp-34h]
  float v41; // [esp+88h] [ebp-30h]
  int v42; // [esp+8Ch] [ebp-2Ch]
  int v43; // [esp+90h] [ebp-28h]
  float v44; // [esp+98h] [ebp-20h]
  int v45; // [esp+9Ch] [ebp-1Ch]
  int v46; // [esp+A0h] [ebp-18h]
  int v47; // [esp+A8h] [ebp-10h]
  void *v48; // [esp+ACh] [ebp-Ch]
  bool v49; // [esp+B0h] [ebp-8h]
  char v50; // [esp+B1h] [ebp-7h]
  char v51; // [esp+B2h] [ebp-6h]

  y = ray_from->y;
  z = ray_from->z;
  v11 = ray_dir->z * ray_length;
  v12 = ray_dir->x * ray_length;
  v13 = ray_dir->y * ray_length;
  v26[0] = ray_from->x;
  v26[1] = y;
  LODWORD(v26[2]) = LODWORD(z) ^ _mask__NegFloat_;
  v26[3] = 0.0;
  v23[0] = v26[0] + v12;
  v23[1] = y + v13;
  v24 = COERCE_UNSIGNED_INT(z + v11) ^ _mask__NegFloat_;
  v25 = 0;
  btCollisionWorld::RayResultCallback::RayResultCallback((btCollisionWorld::RayResultCallback *)this, (int)&v27);
  v27 = &vostok::physics::closest_ray_result_callback::`vftable';
  v33 = v26[0];
  v34 = y;
  v35 = LODWORD(z) ^ _mask__NegFloat_;
  v36 = 0;
  v37 = v26[0] + v12;
  v38 = y + v13;
  v39 = v24;
  v40 = 0;
  v47 = -1;
  v48 = initiator;
  v30 = filter_group;
  v49 = 0;
  v50 = 0;
  v51 = 0;
  v31 = filter_mask;
  if ( keep_unflipped_normal )
    v32 |= 2u;
  this->m_dynamicsWorld->rayTest(
    this->m_dynamicsWorld,
    (const btVector3 *)v26,
    (const btVector3 *)v23,
    (btCollisionWorld::RayResultCallback *)&v27);
  if ( v50 )
  {
    m_dynamicsWorld = this->m_dynamicsWorld;
    v51 = 1;
    v50 = 0;
    v28 = s_bm_current_air_resistance;
    v29 = 0;
    m_dynamicsWorld->rayTest(
      m_dynamicsWorld,
      (const btVector3 *)v26,
      (const btVector3 *)v23,
      (btCollisionWorld::RayResultCallback *)&v27);
  }
  v15 = result;
  v16 = v29;
  result->triangle_index = -1;
  result->object = 0;
  result->is_shape_index = 0;
  result->fraction = 0.0;
  if ( v16 )
  {
    v17 = *(vostok::physics::base_physics_object **)(v16 + 248);
    LODWORD(v21) = v45;
    HIDWORD(v21) = v46 ^ _mask__NegFloat_;
    v18 = v41;
    result->hit_point_world.x = v44;
    *(_QWORD *)&result->hit_point_world.elements[1] = v21;
    LODWORD(v21) = v42;
    v19 = v28;
    HIDWORD(v21) = v43 ^ _mask__NegFloat_;
    result->hit_normal_world.x = v18;
    result->object = v17;
    v20 = v47;
    LODWORD(result->hit_normal_world.y) = v21;
    result->triangle_index = v20;
    result->is_shape_index = v49;
    result->hit_normal_world.z = *((float *)&v21 + 1);
    result->fraction = v19;
  }
  return v15;
}
