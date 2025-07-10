void __thiscall vostok::physics::bullet_physics_world::object_query(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::bt_collision_shape *const shape,
        const vostok::math::float4x4 *transform_from,
        const vostok::math::float4x4 *transform_to,
        vostok::vectora<vostok::physics::closest_ray_result> *results,
        unsigned __int16 filter_group,
        unsigned __int16 filter_mask)
{
  char v7; // bl
  btCollisionShape *m_bt_shape; // eax
  int m_shapeType; // ecx
  btConvexShape *getBoundingSphere; // edi
  btCollisionShape_vtbl *v11; // esi
  float v12; // xmm4_4
  float v13; // xmm6_4
  float v14; // xmm1_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm1_4
  unsigned int v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm5_4
  float v24; // xmm0_4
  float v25; // xmm3_4
  float v26; // xmm5_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm3_4
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v30; // ecx
  void (__cdecl *v31)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  float v32; // [esp+244h] [ebp-16Ch]
  unsigned int v33; // [esp+248h] [ebp-168h]
  float v34; // [esp+248h] [ebp-168h]
  unsigned __int64 v35; // [esp+24Ch] [ebp-164h]
  unsigned int v36; // [esp+254h] [ebp-15Ch]
  float v37; // [esp+258h] [ebp-158h]
  unsigned int v38; // [esp+25Ch] [ebp-154h]
  btTransform resultCallback; // [esp+260h] [ebp-150h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> in_buffer; // [esp+2A0h] [ebp-110h] BYREF
  float v41; // [esp+2CCh] [ebp-E4h]
  btCollisionWorld *v42; // [esp+2D0h] [ebp-E0h]
  unsigned __int64 v43; // [esp+2D4h] [ebp-DCh]
  float v44; // [esp+2DCh] [ebp-D4h]
  btTransform v45; // [esp+2E0h] [ebp-D0h] BYREF
  btTransform convexToWorld; // [esp+320h] [ebp-90h] BYREF
  btCollisionWorld::ConvexResultCallback allowedCcdPenetration; // [esp+360h] [ebp-50h] BYREF
  vostok::vectora<vostok::physics::closest_ray_result> *v48; // [esp+36Ch] [ebp-44h]
  btTransform v49; // [esp+370h] [ebp-40h] BYREF

  v7 = 0;
  v42 = (btCollisionWorld *)this;
  vostok::physics::from_vostok(transform_from, (vostok::math::quaternion *)&convexToWorld);
  vostok::physics::from_vostok(transform_to, (vostok::math::quaternion *)&resultCallback);
  v48 = results;
  m_bt_shape = shape->m_bt_shape;
  LODWORD(allowedCcdPenetration.m_closestHitFraction) = clear_value;
  allowedCcdPenetration.__vftable = (btCollisionWorld::ConvexResultCallback_vtbl *)&`vostok::physics::bullet_physics_world::object_query'::`2'::object_query_callback::`vftable';
  allowedCcdPenetration.m_collisionFilterGroup = filter_group;
  allowedCcdPenetration.m_collisionFilterMask = filter_mask;
  v49.m_basis.m_el[0].mVec128.m128_u64[0] = (unsigned int)clear_value;
  memset(&v49.m_basis.m_el[0].m_floats[2], 0, 12);
  v49.m_basis.m_el[1].mVec128.m128_i32[1] = (int)clear_value;
  memset(&v49.m_basis.m_el[1].m_floats[2], 0, 16);
  v49.m_basis.m_el[2].mVec128.m128_u64[1] = (unsigned int)clear_value;
  memset(&v49.m_origin, 0, sizeof(v49.m_origin));
  m_shapeType = m_bt_shape->m_shapeType;
  if ( m_shapeType < 20 )
  {
    getBoundingSphere = (btConvexShape *)m_bt_shape;
LABEL_5:
    btCollisionWorld::convexSweepTest(
      v42,
      *(const btCollisionWorld **)&v42->m_dispatchInfo.m_enableSatConvex,
      getBoundingSphere,
      &convexToWorld,
      &resultCallback,
      &allowedCcdPenetration,
      0.0);
    return;
  }
  if ( m_shapeType == 31 )
  {
    v11 = m_bt_shape[2].__vftable;
    getBoundingSphere = (btConvexShape *)v11[1].getBoundingSphere;
    v49 = *btTransform::inverse((btTransform *)v11, &v45);
    v12 = *(float *)&v11->serializeSingleShape;
    v13 = *(float *)&v11->serialize;
    v14 = *(float *)&v11[1].~btCollisionShape;
    *(float *)&in_buffer.vtable = (float)((float)((float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[0] * v13)
                                                + (float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[1] * v12))
                                        + (float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[2] * v14))
                                + convexToWorld.m_origin.mVec128.m128_f32[0];
    *(float *)&(&in_buffer.vtable)[1] = (float)((float)((float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[0] * v13)
                                                      + (float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[1] * v12))
                                              + (float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[2] * v14))
                                      + convexToWorld.m_origin.mVec128.m128_f32[1];
    *(_QWORD *)&in_buffer.functor.obj_ptr = COERCE_UNSIGNED_INT(
                                              (float)((float)((float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[0]
                                                                    * v13)
                                                            + (float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[1]
                                                                    * v12))
                                                    + (float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[2]
                                                            * *(float *)&v11[1].~btCollisionShape))
                                            + convexToWorld.m_origin.mVec128.m128_f32[2]);
    *(float *)&v36 = (float)((float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[0]
                                   * *(float *)&v11->getBoundingSphere)
                           + (float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[1] * *(float *)&v11->getLocalScaling))
                   + (float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[2] * *(float *)&v11->getMargin);
    v15 = convexToWorld.m_basis.m_el[2].mVec128.m128_f32[1] * *(float *)&v11->getContactBreakingThreshold;
    v16 = *(float *)&v11->getName;
    v37 = (float)((float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[0] * *(float *)&v11->getAabb)
                + (float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[1] * *(float *)&v11->setLocalScaling))
        + (float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[2] * *(float *)&v11->setMargin);
    v17 = *(float *)&v11->~btCollisionShape;
    *(float *)&v33 = (float)((float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[0]
                                   * *(float *)&v11->getBoundingSphere)
                           + (float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[1] * *(float *)&v11->getLocalScaling))
                   + (float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[2] * *(float *)&v11->getMargin);
    *((float *)&v35 + 1) = (float)((float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[0] * *(float *)&v11->getAabb)
                                 + (float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[1]
                                         * *(float *)&v11->setLocalScaling))
                         + (float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[2] * *(float *)&v11->setMargin);
    *(float *)&v35 = (float)((float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[0]
                                   * *(float *)&v11->~btCollisionShape)
                           + (float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[1]
                                   * *(float *)&v11->getContactBreakingThreshold))
                   + (float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[2] * v16);
    *(float *)&v18 = (float)((float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[0]
                                   * *(float *)&v11->getBoundingSphere)
                           + (float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[1] * *(float *)&v11->getLocalScaling))
                   + (float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[2] * *(float *)&v11->getMargin);
    v19 = (float)((float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[0] * *(float *)&v11->getAabb)
                + (float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[1] * *(float *)&v11->setLocalScaling))
        + (float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[2] * *(float *)&v11->setMargin);
    v45.m_basis.m_el[0].mVec128.m128_f32[0] = (float)((float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[0]
                                                            * *(float *)&v11->~btCollisionShape)
                                                    + (float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[1]
                                                            * *(float *)&v11->getContactBreakingThreshold))
                                            + (float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[2] * v16);
    v45.m_basis.m_el[1].mVec128.m128_u64[0] = v35;
    v45.m_basis.m_el[1].mVec128.m128_u64[1] = v33;
    v45.m_basis.m_el[2].mVec128.m128_f32[0] = (float)((float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[0] * v17)
                                                    + v15)
                                            + (float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[2] * v16);
    v45.m_basis.m_el[2].mVec128.m128_f32[1] = v37;
    v45.m_basis.m_el[2].mVec128.m128_u64[1] = v36;
    v45.m_basis.m_el[0].mVec128.m128_u64[1] = v18;
    v20 = *(float *)&v11->serializeSingleShape;
    v45.m_basis.m_el[0].mVec128.m128_f32[1] = v19;
    v21 = *(float *)&v11[1].~btCollisionShape;
    convexToWorld.m_basis.m_el[0] = (btVector3)_mm_load_si128((const __m128i *)&v45);
    convexToWorld.m_basis.m_el[1] = (btVector3)_mm_load_si128((const __m128i *)&v45.m_basis.m_el[1]);
    convexToWorld.m_basis.m_el[2] = (btVector3)_mm_load_si128((const __m128i *)&v45.m_basis.m_el[2]);
    convexToWorld.m_origin = (btVector3)_mm_load_si128((const __m128i *)&in_buffer);
    v22 = *(float *)&v11->serialize;
    *(float *)&in_buffer.vtable = (float)((float)((float)(v22 * resultCallback.m_basis.m_el[0].mVec128.m128_f32[0])
                                                + (float)(v20 * resultCallback.m_basis.m_el[0].mVec128.m128_f32[1]))
                                        + (float)(v21 * resultCallback.m_basis.m_el[0].mVec128.m128_f32[2]))
                                + resultCallback.m_origin.mVec128.m128_f32[0];
    v23 = (float)((float)(v22 * resultCallback.m_basis.m_el[1].mVec128.m128_f32[0])
                + (float)(v20 * resultCallback.m_basis.m_el[1].mVec128.m128_f32[1]))
        + (float)(v21 * resultCallback.m_basis.m_el[1].mVec128.m128_f32[2]);
    v24 = (float)(v22 * resultCallback.m_basis.m_el[2].mVec128.m128_f32[0])
        + (float)(v20 * resultCallback.m_basis.m_el[2].mVec128.m128_f32[1]);
    v25 = *(float *)&v11->getLocalScaling;
    *(float *)&(&in_buffer.vtable)[1] = v23 + resultCallback.m_origin.mVec128.m128_f32[1];
    v26 = *(float *)&v11->getMargin;
    *(float *)&in_buffer.functor.obj_ptr = (float)(v24
                                                 + (float)(v21 * resultCallback.m_basis.m_el[2].mVec128.m128_f32[2]))
                                         + resultCallback.m_origin.mVec128.m128_f32[2];
    v27 = *(float *)&v11->getBoundingSphere;
    in_buffer.functor.vostok_pointer_size_alignment[1] = 0;
    *((float *)&v35 + 1) = v25;
    LODWORD(v35) = v11->setLocalScaling;
    *(float *)&v38 = (float)((float)(v27 * resultCallback.m_basis.m_el[2].mVec128.m128_f32[0])
                           + (float)(v25 * resultCallback.m_basis.m_el[2].mVec128.m128_f32[1]))
                   + (float)(v26 * resultCallback.m_basis.m_el[2].mVec128.m128_f32[2]);
    v32 = *(float *)&v11->setMargin;
    v28 = *(float *)&v11->getAabb;
    *((float *)&v43 + 1) = (float)((float)(v28 * resultCallback.m_basis.m_el[2].mVec128.m128_f32[0])
                                 + (float)(*(float *)&v35 * resultCallback.m_basis.m_el[2].mVec128.m128_f32[1]))
                         + (float)(v32 * resultCallback.m_basis.m_el[2].mVec128.m128_f32[2]);
    v34 = *(float *)&v11->getName;
    v29 = *(float *)&v11->getContactBreakingThreshold;
    *(float *)&v43 = (float)((float)(v29 * resultCallback.m_basis.m_el[2].mVec128.m128_f32[1])
                           + (float)(v34 * resultCallback.m_basis.m_el[2].mVec128.m128_f32[2]))
                   + (float)(v17 * resultCallback.m_basis.m_el[2].mVec128.m128_f32[0]);
    v41 = (float)((float)(v27 * resultCallback.m_basis.m_el[1].mVec128.m128_f32[0])
                + (float)(*((float *)&v35 + 1) * resultCallback.m_basis.m_el[1].mVec128.m128_f32[1]))
        + (float)(v26 * resultCallback.m_basis.m_el[1].mVec128.m128_f32[2]);
    v44 = (float)((float)(v28 * resultCallback.m_basis.m_el[1].mVec128.m128_f32[0])
                + (float)(*(float *)&v35 * resultCallback.m_basis.m_el[1].mVec128.m128_f32[1]))
        + (float)(v32 * resultCallback.m_basis.m_el[1].mVec128.m128_f32[2]);
    v45.m_basis.m_el[0].mVec128.m128_f32[2] = (float)((float)(v27 * resultCallback.m_basis.m_el[0].mVec128.m128_f32[0])
                                                    + (float)(*((float *)&v35 + 1)
                                                            * resultCallback.m_basis.m_el[0].mVec128.m128_f32[1]))
                                            + (float)(v26 * resultCallback.m_basis.m_el[0].mVec128.m128_f32[2]);
    v45.m_basis.m_el[1].mVec128.m128_f32[0] = (float)((float)(v29 * resultCallback.m_basis.m_el[1].mVec128.m128_f32[1])
                                                    + (float)(v34 * resultCallback.m_basis.m_el[1].mVec128.m128_f32[2]))
                                            + (float)(v17 * resultCallback.m_basis.m_el[1].mVec128.m128_f32[0]);
    v45.m_basis.m_el[1].mVec128.m128_f32[1] = v44;
    v45.m_basis.m_el[1].mVec128.m128_f32[2] = v41;
    v45.m_basis.m_el[2].mVec128.m128_u64[0] = v43;
    v45.m_basis.m_el[2].mVec128.m128_u64[1] = v38;
    v45.m_basis.m_el[0].mVec128.m128_f32[0] = (float)((float)(v29 * resultCallback.m_basis.m_el[0].mVec128.m128_f32[1])
                                                    + (float)(v34 * resultCallback.m_basis.m_el[0].mVec128.m128_f32[2]))
                                            + (float)(v17 * resultCallback.m_basis.m_el[0].mVec128.m128_f32[0]);
    v45.m_basis.m_el[0].mVec128.m128_f32[1] = (float)((float)(v28 * resultCallback.m_basis.m_el[0].mVec128.m128_f32[0])
                                                    + (float)(*(float *)&v35
                                                            * resultCallback.m_basis.m_el[0].mVec128.m128_f32[1]))
                                            + (float)(v32 * resultCallback.m_basis.m_el[0].mVec128.m128_f32[2]);
    v45.m_basis.m_el[0].mVec128.m128_i32[3] = 0;
    resultCallback.m_basis.m_el[0] = (btVector3)_mm_load_si128((const __m128i *)&v45);
    v45.m_basis.m_el[1].mVec128.m128_i32[3] = 0;
    resultCallback.m_basis.m_el[1] = (btVector3)_mm_load_si128((const __m128i *)&v45.m_basis.m_el[1]);
    resultCallback.m_basis.m_el[2] = (btVector3)_mm_load_si128((const __m128i *)&v45.m_basis.m_el[2]);
    resultCallback.m_origin = (btVector3)_mm_load_si128((const __m128i *)&in_buffer);
    goto LABEL_5;
  }
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "physics:", error) )
  {
    v31 = vostok::core::g_log_callback;
    in_buffer.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &in_buffer.functor,
        &in_buffer.functor,
        destroy_functor_tag);
    if ( v31 )
    {
      in_buffer.functor.obj_ptr = v31;
      in_buffer.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                + 1);
    }
    else
    {
      in_buffer.vtable = 0;
    }
    v7 = 1;
    vostok::logging::append(
      &in_buffer,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\bullet_physics_world.cpp",
      0x21Cu,
      "void __thiscall vostok::physics::bullet_physics_world::object_query(class vostok::physics::bt_collision_shape *con"
      "st ,const class vostok::math::float4x4 &,const class vostok::math::float4x4 &,class vostok::vectora<struct vostok:"
      ":physics::closest_ray_result> &,unsigned short,unsigned short)",
      "physics:",
      error,
      "Unsupported shape passed");
  }
  if ( (v7 & 1) != 0 )
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v30,
      (int *)&in_buffer);
}
