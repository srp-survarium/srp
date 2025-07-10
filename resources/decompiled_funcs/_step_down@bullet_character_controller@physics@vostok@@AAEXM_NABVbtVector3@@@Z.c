void __userpurge vostok::physics::bullet_character_controller::step_down(
        vostok::physics::bullet_character_controller *this@<ecx>,
        int a2@<edi>,
        float dt,
        const btVector3 *change_size_only,
        const btVector3 *pos_up_correction)
{
  CProfileNode *Sub_Node; // eax
  int RecursionCounter; // ecx
  float v7; // xmm2_4
  float v8; // xmm2_4
  float *v9; // esi
  double v10; // st7
  btCollisionObject *v11; // eax
  float v12; // xmm1_4
  unsigned int v13; // xmm1_4
  bool v14; // zf
  __int16 v15; // dx
  const btTransform *v16; // ebx
  float m_closestHitFraction; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v20; // ecx
  void (__cdecl *v21)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  double v22; // st7
  char v23; // al
  CProfileNode *v24; // ecx
  float callback_124; // [esp+23Ch] [ebp-154h]
  char v26; // [esp+24Ch] [ebp-144h]
  btTransform in_buffer; // [esp+250h] [ebp-140h] BYREF
  btCollisionWorld::ConvexResultCallback resultCallback; // [esp+290h] [ebp-100h] BYREF
  int v29; // [esp+29Ch] [ebp-F4h]
  int v30; // [esp+2A0h] [ebp-F0h]
  const vostok::math::float4x4 *v31; // [esp+2A4h] [ebp-ECh]
  int v32; // [esp+2A8h] [ebp-E8h]
  int v33; // [esp+2ACh] [ebp-E4h]
  int v34; // [esp+2B0h] [ebp-E0h]
  int v35; // [esp+2B4h] [ebp-DCh]
  const vostok::math::float4x4 *v36; // [esp+2B8h] [ebp-D8h]
  int v37; // [esp+2BCh] [ebp-D4h]
  __m128i si128; // [esp+2C0h] [ebp-D0h]
  btTransform convexToWorld; // [esp+2D0h] [ebp-C0h] BYREF
  vostok::physics::character_move_test_callback v40; // [esp+310h] [ebp-80h] BYREF

  Sub_Node = CProfileManager::CurrentNode;
  v26 = 0;
  if ( CProfileManager::CurrentNode->Name != "step_down" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
  convexToWorld.m_origin = *(btVector3 *)(a2 + 48);
  v7 = *(float *)(a2 + 232);
  convexToWorld.m_basis.m_el[0].mVec128.m128_u64[0] = (unsigned int)clear_value;
  memset(&convexToWorld.m_basis.m_el[0].m_floats[2], 0, 12);
  *(unsigned __int64 *)((char *)convexToWorld.m_basis.m_el[1].mVec128.m128_u64 + 4) = (unsigned int)clear_value;
  memset(&convexToWorld.m_basis.m_el[1].m_floats[3], 0, 12);
  convexToWorld.m_basis.m_el[2].mVec128.m128_u64[1] = (unsigned int)clear_value;
  if ( v7 >= 0.0 )
    v8 = 0.0;
  else
    v8 = -(float)(v7 * dt);
  if ( s_step_height > v8 && *(_BYTE *)(a2 + 256) )
    v8 = s_step_height;
  v9 = (float *)change_size_only;
  v10 = *(float *)(a2 + 248);
  v11 = *(btCollisionObject **)(a2 + 136);
  resultCallback.__vftable = (btCollisionWorld::ConvexResultCallback_vtbl *)clear_value;
  v31 = clear_value;
  v36 = clear_value;
  v12 = (float)(*(float *)(a2 + 80) + change_size_only->mVec128.m128_f32[1]) + v8;
  in_buffer.m_basis.m_el[0].mVec128.m128_f32[0] = *(float *)(a2 + 48)
                                                - (float)(vostok::physics::bullet_character_controller::m_up_vector.mVec128.m128_f32[0]
                                                        * v12);
  in_buffer.m_basis.m_el[0].mVec128.m128_f32[1] = *(float *)(a2 + 52)
                                                - (float)(vostok::physics::bullet_character_controller::m_up_vector.mVec128.m128_f32[1]
                                                        * v12);
  callback_124 = v10;
  *(float *)&v13 = *(float *)(a2 + 56)
                 - (float)(vostok::physics::bullet_character_controller::m_up_vector.mVec128.m128_f32[2] * v12);
  resultCallback.m_closestHitFraction = 0.0;
  *(_DWORD *)&resultCallback.m_collisionFilterGroup = 0;
  v29 = 0;
  v30 = 0;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v37 = 0;
  in_buffer.m_basis.m_el[0].mVec128.m128_u64[1] = v13;
  si128 = _mm_load_si128((const __m128i *)&in_buffer);
  vostok::physics::character_move_test_callback::character_move_test_callback(
    &v40,
    &vostok::physics::bullet_character_controller::m_up_vector,
    v11,
    callback_124);
  v14 = *(_BYTE *)(a2 + 258) == 0;
  v15 = *(_WORD *)(a2 + 228);
  v40.m_collisionFilterGroup = *(_WORD *)(a2 + 226);
  v40.m_collisionFilterMask = v15;
  v16 = (const btTransform *)(a2 + 144);
  if ( v14 )
    btCollisionWorld::convexSweepTest(
      *(btCollisionWorld **)(a2 + 4),
      *(const btConvexShape **)(a2 + 4),
      v16,
      &convexToWorld,
      &resultCallback,
      COERCE_FLOAT(&v40));
  else
    btGhostObject::convexSweepTest(
      (btGhostObject *)&resultCallback,
      *(const btConvexShape **)(a2 + 136),
      (const btTransform *)(a2 + 144),
      &convexToWorld,
      &resultCallback,
      COERCE_FLOAT(&v40));
  if ( *(float *)&clear_value <= v40.m_closestHitFraction )
  {
    *(__m128i *)(a2 + 48) = si128;
  }
  else
  {
    btTransform::inverse((btTransform *)(*(_DWORD *)(a2 + 136) + 16), &in_buffer);
    if ( s_step_height < (float)((float)((float)((float)((float)((float)((float)(in_buffer.m_basis.m_el[1].mVec128.m128_f32[0]
                                                                               * v40.m_hitPointWorld.mVec128.m128_f32[0])
                                                                       + (float)(in_buffer.m_basis.m_el[1].mVec128.m128_f32[1]
                                                                               * v40.m_hitPointWorld.mVec128.m128_f32[1]))
                                                               + (float)(in_buffer.m_basis.m_el[1].mVec128.m128_f32[2]
                                                                       * v40.m_hitPointWorld.mVec128.m128_f32[2]))
                                                       + in_buffer.m_origin.mVec128.m128_f32[1])
                                               * vostok::physics::bullet_character_controller::m_up_vector.mVec128.m128_f32[1])
                                       + (float)((float)((float)((float)((float)(in_buffer.m_basis.m_el[2].mVec128.m128_f32[0]
                                                                               * v40.m_hitPointWorld.mVec128.m128_f32[0])
                                                                       + (float)(in_buffer.m_basis.m_el[2].mVec128.m128_f32[1]
                                                                               * v40.m_hitPointWorld.mVec128.m128_f32[1]))
                                                               + (float)(in_buffer.m_basis.m_el[2].mVec128.m128_f32[2]
                                                                       * v40.m_hitPointWorld.mVec128.m128_f32[2]))
                                                       + in_buffer.m_origin.mVec128.m128_f32[2])
                                               * vostok::physics::bullet_character_controller::m_up_vector.mVec128.m128_f32[2]))
                               + (float)((float)((float)((float)((float)(v40.m_hitPointWorld.mVec128.m128_f32[0]
                                                                       * in_buffer.m_basis.m_el[0].mVec128.m128_f32[0])
                                                               + (float)(v40.m_hitPointWorld.mVec128.m128_f32[1]
                                                                       * in_buffer.m_basis.m_el[0].mVec128.m128_f32[1]))
                                                       + (float)(v40.m_hitPointWorld.mVec128.m128_f32[2]
                                                               * in_buffer.m_basis.m_el[0].mVec128.m128_f32[2]))
                                               + in_buffer.m_origin.mVec128.m128_f32[0])
                                       * vostok::physics::bullet_character_controller::m_up_vector.mVec128.m128_f32[0])) )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "physics:", info) )
      {
        v21 = vostok::core::g_log_callback;
        in_buffer.m_basis.m_el[0].mVec128.m128_i32[0] = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            (const boost::detail::function::function_buffer *)&in_buffer.m_basis.m_el[0].m_floats[2],
            (boost::detail::function::function_buffer *)&in_buffer.m_basis.m_el[0].m_floats[2],
            destroy_functor_tag);
        if ( v21 )
        {
          in_buffer.m_basis.m_el[0].mVec128.m128_i32[2] = (int)v21;
          in_buffer.m_basis.m_el[0].mVec128.m128_i32[0] = (int)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                        + 1;
        }
        else
        {
          in_buffer.m_basis.m_el[0].mVec128.m128_i32[0] = 0;
        }
        v26 = 1;
        vostok::logging::append(
          (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&in_buffer,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\bullet_character_controller.cpp",
          0x29Du,
          "void __thiscall vostok::physics::bullet_character_controller::step_down(float,bool,const class btVector3 &)",
          "physics:",
          info,
          "dddd");
        v9 = (float *)change_size_only;
      }
      if ( (v26 & 1) != 0 )
      {
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v20,
          (int *)&in_buffer);
        v9 = (float *)change_size_only;
      }
    }
    else
    {
      m_closestHitFraction = v40.m_closestHitFraction;
      v18 = *(float *)&clear_value - v40.m_closestHitFraction;
      v19 = *(float *)&si128.m128i_i32[1];
      *(float *)(a2 + 48) = (float)(convexToWorld.m_origin.mVec128.m128_f32[0]
                                  * (float)(*(float *)&clear_value - v40.m_closestHitFraction))
                          + (float)(*(float *)si128.m128i_i32 * v40.m_closestHitFraction);
      *(float *)(a2 + 52) = (float)(convexToWorld.m_origin.mVec128.m128_f32[1] * v18)
                          + (float)(v19 * m_closestHitFraction);
      *(float *)(a2 + 56) = (float)(convexToWorld.m_origin.mVec128.m128_f32[2] * v18)
                          + (float)(*(float *)&si128.m128i_i32[2] * m_closestHitFraction);
      *(_DWORD *)(a2 + 232) = 0;
      *(_BYTE *)(a2 + 257) = 0;
      *(_BYTE *)(a2 + 260) = 0;
    }
  }
  *(float *)(a2 + 48) = *(float *)(a2 + 48) + *v9;
  *(float *)(a2 + 52) = *(float *)(a2 + 52) + v9[1];
  *(float *)(a2 + 56) = v9[2] + *(float *)(a2 + 56);
  v22 = ((double (__thiscall *)(int))*(_DWORD *)(v16->m_basis.m_el[0].mVec128.m128_i32[0] + 40))(a2 + 144);
  v23 = *(_BYTE *)(a2 + 224);
  *(float *)(a2 + 52) = v22 + *(float *)(a2 + 52);
  vostok::physics::bullet_character_controller::setup_crouch_state(
    (vostok::physics::bullet_character_controller *)a2,
    v23,
    (int)v9);
  v40.__vftable = (vostok::physics::character_move_test_callback_vtbl *)&btCollisionWorld::ConvexResultCallback::`vftable';
  if ( CProfileNode::Return(v24) )
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
}
