void __thiscall vostok::physics::bullet_physics_world::object_query(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::bt_collision_shape *const shape,
        const vostok::math::float4x4 *transform_from,
        const vostok::math::float4x4 *transform_to,
        vostok::vectora<vostok::physics::closest_ray_result> *results,
        __int16 filter_group,
        __int16 filter_mask)
{
  btCollisionShape *m_bt_shape; // eax
  int m_shapeType; // ecx
  int v9; // ebx
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm5_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm6_4
  float v16; // xmm5_4
  float v17; // xmm7_4
  float v18; // xmm6_4
  float v19; // xmm2_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm5_4
  float v23; // xmm6_4
  float v24; // xmm5_4
  float v25; // xmm2_4
  float v26; // xmm7_4
  float v27; // xmm6_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm5_4
  float v32; // xmm2_4
  unsigned int v33; // xmm6_4
  float v34; // xmm5_4
  float v35; // xmm6_4
  float v36; // xmm7_4
  float v37; // xmm6_4
  float v38; // xmm7_4
  bool has_passed_filters; // al
  btMatrix3x3 *v40; // [esp+0h] [ebp-184h]
  btCollisionWorld *v41; // [esp+0h] [ebp-184h]
  const float *v42; // [esp+4h] [ebp-180h]
  const float *v43; // [esp+4h] [ebp-180h]
  float v44; // [esp+10h] [ebp-174h] BYREF
  btMatrix3x3 v45; // [esp+14h] [ebp-170h] BYREF
  float v46; // [esp+44h] [ebp-140h] BYREF
  float v47; // [esp+48h] [ebp-13Ch] BYREF
  float v48; // [esp+4Ch] [ebp-138h] BYREF
  float v49; // [esp+50h] [ebp-134h] BYREF
  btTransform convexToWorld; // [esp+54h] [ebp-130h] BYREF
  btMatrix3x3 resultCallback; // [esp+94h] [ebp-F0h] BYREF
  boost::detail::function::vtable_base *vtable; // [esp+C4h] [ebp-C0h]
  boost::detail::function::vtable_base *v53; // [esp+C8h] [ebp-BCh]
  __int64 v54; // [esp+CCh] [ebp-B8h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+D4h] [ebp-B0h] BYREF
  btCollisionWorld::ConvexResultCallback allowedCcdPenetration; // [esp+F4h] [ebp-90h] BYREF
  vostok::vectora<vostok::physics::closest_ray_result> *v57; // [esp+100h] [ebp-84h]
  btTransform v58; // [esp+104h] [ebp-80h] BYREF
  btTransform v59; // [esp+144h] [ebp-40h] BYREF

  v45.m_el[0].mVec128.m128_i32[3] = 0;
  v45.m_el[2].mVec128.m128_i32[2] = (int)this;
  vostok::physics::from_vostok(transform_from, &convexToWorld.m_basis);
  vostok::physics::from_vostok(transform_to, &resultCallback);
  v57 = results;
  allowedCcdPenetration.m_collisionFilterGroup = filter_group;
  allowedCcdPenetration.m_collisionFilterMask = filter_mask;
  allowedCcdPenetration.m_closestHitFraction = s_bm_current_air_resistance;
  allowedCcdPenetration.__vftable = (btCollisionWorld::ConvexResultCallback_vtbl *)&`vostok::physics::bullet_physics_world::object_query'::`2'::object_query_callback::`vftable';
  btMatrix3x3::setIdentity(v40, (int)&v58);
  m_bt_shape = shape->m_bt_shape;
  memset(&v58.m_origin, 0, sizeof(v58.m_origin));
  m_shapeType = m_bt_shape->m_shapeType;
  if ( m_shapeType < 20 )
  {
    v45.m_el[0].mVec128.m128_i32[3] = (int)m_bt_shape;
LABEL_5:
    btCollisionWorld::convexSweepTest(
      (btCollisionWorld *)m_shapeType,
      *(const btCollisionWorld **)(v45.m_el[2].mVec128.m128_i32[2] + 56),
      (btConvexShape *)v45.m_el[0].mVec128.m128_i32[3],
      &convexToWorld,
      (btCollisionWorld::ConvexResultCallback *)&resultCallback,
      &allowedCcdPenetration,
      0.0);
    return;
  }
  if ( m_shapeType == 31 )
  {
    v9 = (int)m_bt_shape[2].__vftable;
    v45.m_el[0].mVec128.m128_i32[3] = *(_DWORD *)(v9 + 64);
    v58 = *btTransform::inverse((btTransform *)0x1F, v9, &v59);
    v10 = *(float *)(v9 + 52);
    v11 = *(float *)(v9 + 48);
    v12 = *(float *)(v9 + 56);
    *(float *)&log_callback.vtable = (float)((float)((float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[0] * v11)
                                                   + (float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[1] * v10))
                                           + (float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[2] * v12))
                                   + convexToWorld.m_origin.mVec128.m128_f32[0];
    *(float *)&(&log_callback.vtable)[1] = (float)((float)((float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[0]
                                                                 * v11)
                                                         + (float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[1]
                                                                 * v10))
                                                 + (float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[2] * v12))
                                         + convexToWorld.m_origin.mVec128.m128_f32[1];
    v13 = *(float *)(v9 + 8);
    *(float *)&log_callback.functor.obj_ptr = (float)((float)((float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[0]
                                                                    * *(float *)(v9 + 48))
                                                            + (float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[1]
                                                                    * v10))
                                                    + (float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[2] * v12))
                                            + convexToWorld.m_origin.mVec128.m128_f32[2];
    log_callback.functor.vostok_pointer_size_alignment[1] = 0;
    v14 = (float)((float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[0] * v13)
                + (float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[1] * *(float *)(v9 + 24)))
        + (float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[2] * *(float *)(v9 + 40));
    v15 = *(float *)(v9 + 4);
    v16 = *(float *)(v9 + 20);
    v45.m_el[0].mVec128.m128_f32[0] = v14;
    v17 = (float)((float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[0] * v15)
                + (float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[1] * v16))
        + (float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[2] * *(float *)(v9 + 36));
    v18 = *(float *)(v9 + 16);
    v19 = convexToWorld.m_basis.m_el[2].mVec128.m128_f32[2] * *(float *)(v9 + 32);
    v45.m_el[1].mVec128.m128_f32[1] = v17;
    v20 = *(float *)(v9 + 8);
    v45.m_el[1].mVec128.m128_f32[3] = (float)(v19
                                            + (float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[0] * *(float *)v9))
                                    + (float)(convexToWorld.m_basis.m_el[2].mVec128.m128_f32[1] * v18);
    v21 = convexToWorld.m_basis.m_el[1].mVec128.m128_f32[0] * v20;
    v22 = *(float *)(v9 + 4);
    v45.m_el[0].mVec128.m128_f32[1] = (float)(v21
                                            + (float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[1]
                                                    * *(float *)(v9 + 24)))
                                    + (float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[2] * *(float *)(v9 + 40));
    v23 = convexToWorld.m_basis.m_el[1].mVec128.m128_f32[0] * v22;
    v24 = *(float *)(v9 + 36);
    v25 = convexToWorld.m_basis.m_el[1].mVec128.m128_f32[0] * *(float *)v9;
    v26 = *(float *)(v9 + 16);
    v45.m_el[1].mVec128.m128_f32[0] = (float)(v23
                                            + (float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[1]
                                                    * *(float *)(v9 + 20)))
                                    + (float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[2] * v24);
    v27 = *(float *)(v9 + 32);
    v45.m_el[2].mVec128.m128_f32[0] = (float)((float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[2] * v27) + v25)
                                    + (float)(convexToWorld.m_basis.m_el[1].mVec128.m128_f32[1] * v26);
    v28 = *(float *)(v9 + 4);
    v44 = (float)((float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[0] * *(float *)(v9 + 8))
                + (float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[1] * *(float *)(v9 + 24)))
        + (float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[2] * *(float *)(v9 + 40));
    v29 = (float)((float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[0] * *(float *)v9)
                + (float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[1] * *(float *)(v9 + 16)))
        + (float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[2] * v27);
    v45.m_el[1].mVec128.m128_f32[2] = (float)((float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[0] * v28)
                                            + (float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[1]
                                                    * *(float *)(v9 + 20)))
                                    + (float)(convexToWorld.m_basis.m_el[0].mVec128.m128_f32[2] * v24);
    v45.m_el[0].mVec128.m128_f32[2] = v29;
    btMatrix3x3::setValue(
      (btMatrix3x3 *)&v45.m_el[0].m_floats[2],
      (int)&v59,
      &v45.m_el[1].mVec128.m128_f32[2],
      &v44,
      v45.m_el[2].mVec128.m128_f32,
      v45.m_el[1].mVec128.m128_f32,
      &v45.m_el[0].mVec128.m128_f32[1],
      &v45.m_el[1].mVec128.m128_f32[3],
      &v45.m_el[1].mVec128.m128_f32[1],
      (const float *)&v45,
      v42);
    convexToWorld.m_basis.m_el[0].mVec128.m128_u64[0] = v59.m_basis.m_el[0].mVec128.m128_u64[0];
    convexToWorld.m_basis.m_el[0].mVec128.m128_u64[1] = v59.m_basis.m_el[0].mVec128.m128_u64[1];
    convexToWorld.m_basis.m_el[1] = v59.m_basis.m_el[1];
    v30 = *(float *)(v9 + 48);
    v31 = *(float *)(v9 + 52);
    v32 = *(float *)(v9 + 56);
    convexToWorld.m_basis.m_el[2] = v59.m_basis.m_el[2];
    convexToWorld.m_origin.mVec128.m128_u64[0] = *(_QWORD *)&log_callback.vtable;
    convexToWorld.m_origin.mVec128.m128_u64[1] = *(_QWORD *)&log_callback.functor.obj_ptr;
    *(float *)&log_callback.vtable = (float)((float)((float)(resultCallback.m_el[0].mVec128.m128_f32[0] * v30)
                                                   + (float)(resultCallback.m_el[0].mVec128.m128_f32[1] * v31))
                                           + (float)(resultCallback.m_el[0].mVec128.m128_f32[2] * v32))
                                   + *(float *)&vtable;
    *(float *)&(&log_callback.vtable)[1] = (float)((float)((float)(resultCallback.m_el[1].mVec128.m128_f32[0] * v30)
                                                         + (float)(resultCallback.m_el[1].mVec128.m128_f32[1] * v31))
                                                 + (float)(resultCallback.m_el[1].mVec128.m128_f32[2] * v32))
                                         + *(float *)&v53;
    *(float *)&v33 = (float)((float)((float)(resultCallback.m_el[2].mVec128.m128_f32[0] * *(float *)(v9 + 48))
                                   + (float)(resultCallback.m_el[2].mVec128.m128_f32[1] * v31))
                           + (float)(resultCallback.m_el[2].mVec128.m128_f32[2] * *(float *)(v9 + 56)))
                   + *(float *)&v54;
    v45.m_el[0].mVec128.m128_i32[2] = *(_DWORD *)(v9 + 40);
    v34 = *(float *)(v9 + 24);
    *(_QWORD *)&log_callback.functor.obj_ptr = v33;
    v35 = *(float *)(v9 + 8);
    v44 = v34;
    v45.m_el[1].mVec128.m128_f32[2] = v35;
    v36 = (float)(resultCallback.m_el[2].mVec128.m128_f32[0] * v35)
        + (float)(resultCallback.m_el[2].mVec128.m128_f32[1] * v34);
    v37 = *(float *)(v9 + 4);
    v45.m_el[1].mVec128.m128_i32[0] = *(_DWORD *)(v9 + 20);
    v45.m_el[2].mVec128.m128_f32[0] = v37;
    v45.m_el[2].mVec128.m128_f32[1] = v36
                                    + (float)(resultCallback.m_el[2].mVec128.m128_f32[2]
                                            * v45.m_el[0].mVec128.m128_f32[2]);
    v45.m_el[0].mVec128.m128_i32[1] = *(_DWORD *)(v9 + 36);
    v45.m_el[1].mVec128.m128_i32[3] = *(_DWORD *)(v9 + 16);
    v45.m_el[1].mVec128.m128_i32[1] = *(_DWORD *)(v9 + 32);
    v45.m_el[2].mVec128.m128_f32[3] = (float)((float)(resultCallback.m_el[2].mVec128.m128_f32[0] * v37)
                                            + (float)(resultCallback.m_el[2].mVec128.m128_f32[1]
                                                    * v45.m_el[1].mVec128.m128_f32[0]))
                                    + (float)(resultCallback.m_el[2].mVec128.m128_f32[2]
                                            * v45.m_el[0].mVec128.m128_f32[1]);
    v38 = *(float *)v9;
    v47 = (float)((float)(resultCallback.m_el[2].mVec128.m128_f32[1] * v45.m_el[1].mVec128.m128_f32[3])
                + (float)(resultCallback.m_el[2].mVec128.m128_f32[2] * v45.m_el[1].mVec128.m128_f32[1]))
        + (float)(resultCallback.m_el[2].mVec128.m128_f32[0] * *(float *)v9);
    v49 = (float)((float)(resultCallback.m_el[1].mVec128.m128_f32[0] * v45.m_el[1].mVec128.m128_f32[2])
                + (float)(resultCallback.m_el[1].mVec128.m128_f32[1] * v34))
        + (float)(resultCallback.m_el[1].mVec128.m128_f32[2] * v45.m_el[0].mVec128.m128_f32[2]);
    v48 = (float)((float)(resultCallback.m_el[1].mVec128.m128_f32[0] * v37)
                + (float)(resultCallback.m_el[1].mVec128.m128_f32[1] * v45.m_el[1].mVec128.m128_f32[0]))
        + (float)(resultCallback.m_el[1].mVec128.m128_f32[2] * v45.m_el[0].mVec128.m128_f32[1]);
    v46 = (float)((float)(resultCallback.m_el[1].mVec128.m128_f32[1] * v45.m_el[1].mVec128.m128_f32[3])
                + (float)(resultCallback.m_el[1].mVec128.m128_f32[2] * v45.m_el[1].mVec128.m128_f32[1]))
        + (float)(resultCallback.m_el[1].mVec128.m128_f32[0] * v38);
    v44 = (float)((float)(resultCallback.m_el[0].mVec128.m128_f32[0] * v45.m_el[1].mVec128.m128_f32[2])
                + (float)(resultCallback.m_el[0].mVec128.m128_f32[1] * v34))
        + (float)(resultCallback.m_el[0].mVec128.m128_f32[2] * v45.m_el[0].mVec128.m128_f32[2]);
    v45.m_el[0].mVec128.m128_f32[1] = (float)((float)(resultCallback.m_el[0].mVec128.m128_f32[0] * v37)
                                            + (float)(resultCallback.m_el[0].mVec128.m128_f32[1]
                                                    * v45.m_el[1].mVec128.m128_f32[0]))
                                    + (float)(resultCallback.m_el[0].mVec128.m128_f32[2]
                                            * v45.m_el[0].mVec128.m128_f32[1]);
    v45.m_el[0].mVec128.m128_f32[0] = (float)((float)(resultCallback.m_el[0].mVec128.m128_f32[1]
                                                    * v45.m_el[1].mVec128.m128_f32[3])
                                            + (float)(resultCallback.m_el[0].mVec128.m128_f32[2]
                                                    * v45.m_el[1].mVec128.m128_f32[1]))
                                    + (float)(resultCallback.m_el[0].mVec128.m128_f32[0] * v38);
    btMatrix3x3::setValue(
      &v45,
      (int)&v59,
      &v45.m_el[0].mVec128.m128_f32[1],
      &v44,
      &v46,
      &v48,
      &v49,
      &v47,
      &v45.m_el[2].mVec128.m128_f32[3],
      &v45.m_el[2].mVec128.m128_f32[1],
      v43);
    resultCallback = v59.m_basis;
    vtable = log_callback.vtable;
    v53 = (&log_callback.vtable)[1];
    v54 = *(_QWORD *)&log_callback.functor.obj_ptr;
    goto LABEL_5;
  }
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)&stru_80075C,
                               (const char *)2),
        m_shapeType = (int)v41,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)m_shapeType,
      &log_callback);
    v45.m_el[0].mVec128.m128_i32[3] = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\bullet_physics_world.cpp",
      0x2E4u,
      "void __thiscall vostok::physics::bullet_physics_world::object_query(class vostok::physics::bt_collision_shape *con"
      "st ,const class vostok::math::float4x4 &,const class vostok::math::float4x4 &,class vostok::vectora<struct vostok:"
      ":physics::closest_ray_result> &,unsigned short,unsigned short)",
      (char *)&stru_80075C,
      error,
      "Unsupported shape passed");
  }
  if ( (v45.m_el[0].mVec128.m128_i8[12] & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_shapeType,
      (int *)&log_callback);
}
