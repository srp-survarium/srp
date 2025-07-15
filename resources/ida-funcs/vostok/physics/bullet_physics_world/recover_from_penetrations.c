char __thiscall vostok::physics::bullet_physics_world::recover_from_penetrations(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::bt_collision_shape *const shape,
        const vostok::math::float4x4 *transform_initial,
        vostok::math::float4x4 *transform_result,
        int filter_group,
        int filter_mask)
{
  vostok::physics::bullet_physics_world *v6; // ebx
  btCollisionShape *m_bt_shape; // edi
  vostok::math::quaternion *v8; // eax
  __m128i si128; // xmm0
  int (__thiscall *v10)(void *); // edx
  btMatrix3x3 *v11; // ecx
  int v12; // esi
  int v13; // ecx
  int v14; // eax
  int **v15; // ebx
  float v16; // xmm2_4
  int v17; // ecx
  int v18; // edi
  float v19; // xmm0_4
  int v20; // edx
  int v21; // esi
  unsigned int v22; // ecx
  float *v23; // eax
  float v24; // xmm4_4
  float v25; // xmm3_4
  unsigned int v26; // xmm3_4
  float v27; // xmm4_4
  float v28; // xmm3_4
  unsigned int v29; // xmm3_4
  float v30; // xmm4_4
  float v31; // xmm3_4
  unsigned int v32; // xmm3_4
  float v33; // xmm4_4
  float v34; // xmm3_4
  unsigned int v35; // xmm3_4
  float *v36; // eax
  int v37; // edx
  float v38; // xmm4_4
  float v39; // xmm3_4
  unsigned int v40; // xmm3_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm3_4
  void (__cdecl *v44)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  int v45; // edx
  int v46; // ecx
  void (__cdecl *v47)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  int (__thiscall *v48)(void *); // edx
  int v49; // esi
  btVector3 v50; // xmm1
  btVector3 v51; // xmm2
  btVector3 v52; // xmm0
  __m128i v54; // [esp+F88h] [ebp-210h] BYREF
  int v55; // [esp+F9Ch] [ebp-1FCh]
  int v56; // [esp+FA0h] [ebp-1F8h]
  int v57; // [esp+FA4h] [ebp-1F4h] BYREF
  int v58; // [esp+FA8h] [ebp-1F0h]
  int v59; // [esp+FACh] [ebp-1ECh]
  void *ptr; // [esp+FB0h] [ebp-1E8h]
  int v61; // [esp+FB4h] [ebp-1E4h]
  int v62; // [esp+FB8h] [ebp-1E0h]
  int v63; // [esp+FBCh] [ebp-1DCh]
  int i; // [esp+FC0h] [ebp-1D8h]
  float v65; // [esp+FC4h] [ebp-1D4h]
  float v66; // [esp+FC8h] [ebp-1D0h]
  float v67; // [esp+FCCh] [ebp-1CCh]
  float v68; // [esp+FD0h] [ebp-1C8h]
  __m128i v69; // [esp+FD8h] [ebp-1C0h]
  vostok::physics::bullet_physics_world *v70; // [esp+FF4h] [ebp-1A4h]
  __m128i v71; // [esp+FF8h] [ebp-1A0h] BYREF
  float v72; // [esp+1014h] [ebp-184h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+1018h] [ebp-180h] BYREF
  btCollisionObject v74; // [esp+104Ch] [ebp-14Ch] BYREF
  void *v75; // [esp+1174h] [ebp-24h]
  char v76; // [esp+1178h] [ebp-20h]
  void *v77; // [esp+1188h] [ebp-10h]

  v6 = this;
  m_bt_shape = shape->m_bt_shape;
  v70 = this;
  v55 = 0;
  btPairCachingGhostObject::btPairCachingGhostObject((btPairCachingGhostObject *)this);
  v74.m_collisionFlags = (int)m_bt_shape;
  v74.m_companionId = (int)m_bt_shape;
  v74.m_activationState1 = 16;
  v8 = vostok::physics::from_vostok(transform_initial, (vostok::math::quaternion *)&log_callback);
  btCollisionObject::setWorldTransform((btCollisionObject *)(&v74.__vftable + 3), (const btTransform *)v8);
  v6->m_dynamicsWorld->addCollisionObject(
    v6->m_dynamicsWorld,
    (btCollisionObject *)(&v74.__vftable + 3),
    filter_group,
    filter_mask);
  v62 = 3;
  do
  {
    ((void (__stdcall *)(void *, btDispatcherInfo *, btDispatcher *))v6->m_dynamicsWorld->m_dispatcher1->dispatchAllCollisionPairs)(
      v77,
      &v6->m_dynamicsWorld->m_dispatchInfo,
      v6->m_dynamicsWorld->m_dispatcher1);
    si128 = _mm_load_si128((const __m128i *)&v74.m_worldTransform.m_origin.m_floats[3]);
    LOBYTE(v61) = 1;
    ptr = 0;
    v58 = 0;
    v59 = 0;
    v10 = *(int (__thiscall **)(void *))(*(_DWORD *)v77 + 32);
    v71 = si128;
    v63 = 0;
    if ( v10(v77) > 0 )
    {
      v56 = 0;
      while ( 1 )
      {
        v65 = 0.0;
        v12 = v58;
        if ( v58 < 0 )
        {
          if ( v59 < 0 )
          {
            if ( ptr && (_BYTE)v61 )
            {
              ++gNumAlignedFree;
              sAlignedFreeFunc(ptr);
            }
            LOBYTE(v61) = 1;
            ptr = 0;
            v59 = 0;
          }
          if ( v12 < 0 )
          {
            v13 = 4 * v12;
            do
            {
              if ( (char *)ptr + v13 )
                *(_DWORD *)((char *)ptr + v13) = 0;
              v13 += 4;
            }
            while ( v13 < 0 );
          }
        }
        v58 = 0;
        v14 = (*(int (__thiscall **)(void *))(*(_DWORD *)v77 + 24))(v77);
        v15 = (int **)(v56 + *(_DWORD *)(v14 + 12));
        if ( v15[2] )
          (*(void (__thiscall **)(int *, int *))(*v15[2] + 12))(v15[2], &v57);
        v16 = v65;
        v17 = 0;
        for ( i = 0; v17 < v58; i = v17 )
        {
          v18 = *((_DWORD *)ptr + v17);
          if ( *(btCollisionObject **)(v18 + 1168) == (btCollisionObject *)(&v74.__vftable + 3) )
            v19 = -1.0;
          else
            v19 = *(float *)&clear_value;
          v20 = *(_DWORD *)(v18 + 1176);
          v21 = 0;
          if ( v20 >= 4 )
          {
            v22 = ((unsigned int)(v20 - 4) >> 2) + 1;
            v23 = (float *)(v18 + 88);
            v21 = 4 * v22;
            do
            {
              v24 = v23[2];
              if ( v24 < 0.0 && v16 > v24 )
              {
                v25 = *(v23 - 1);
                if ( v25 > 0.0 )
                {
                  *(float *)&v54.m128i_i32[1] = v25 * v19;
                  v16 = v24;
                  *(float *)&v26 = v19 * *v23;
                  *(float *)v54.m128i_i32 = *(v23 - 2) * v19;
                  v54.m128i_i64[1] = v26;
                  v69 = _mm_load_si128(&v54);
                }
              }
              v27 = v23[74];
              if ( v27 < 0.0 && v16 > v27 )
              {
                v28 = v23[71];
                if ( v28 > 0.0 )
                {
                  *(float *)&v54.m128i_i32[1] = v28 * v19;
                  v16 = v27;
                  *(float *)&v29 = v23[72] * v19;
                  *(float *)v54.m128i_i32 = v23[70] * v19;
                  v54.m128i_i64[1] = v29;
                  v69 = _mm_load_si128(&v54);
                }
              }
              v30 = v23[146];
              if ( v30 < 0.0 && v16 > v30 )
              {
                v31 = v23[143];
                if ( v31 > 0.0 )
                {
                  *(float *)&v54.m128i_i32[1] = v31 * v19;
                  v16 = v30;
                  *(float *)&v32 = v23[144] * v19;
                  *(float *)v54.m128i_i32 = v23[142] * v19;
                  v54.m128i_i64[1] = v32;
                  v69 = _mm_load_si128(&v54);
                }
              }
              v33 = v23[218];
              if ( v33 < 0.0 && v16 > v33 )
              {
                v34 = v23[215];
                if ( v34 > 0.0 )
                {
                  *(float *)&v54.m128i_i32[1] = v34 * v19;
                  v16 = v33;
                  *(float *)&v35 = v23[216] * v19;
                  *(float *)v54.m128i_i32 = v23[214] * v19;
                  v54.m128i_i64[1] = v35;
                  v69 = _mm_load_si128(&v54);
                }
              }
              v23 += 288;
              --v22;
            }
            while ( v22 );
            v17 = i;
          }
          if ( v21 < v20 )
          {
            v36 = (float *)(288 * v21 + v18 + 88);
            v37 = v20 - v21;
            do
            {
              v38 = v36[2];
              if ( v38 < 0.0 && v16 > v38 )
              {
                v39 = *(v36 - 1);
                if ( v39 > 0.0 )
                {
                  *(float *)&v54.m128i_i32[1] = v39 * v19;
                  v16 = v38;
                  *(float *)&v40 = v19 * *v36;
                  *(float *)v54.m128i_i32 = *(v36 - 2) * v19;
                  v54.m128i_i64[1] = v40;
                  v69 = _mm_load_si128(&v54);
                }
              }
              v36 += 72;
              --v37;
            }
            while ( v37 );
          }
          ++v17;
        }
        v68 = *(float *)&v69.m128i_i32[2] * v16;
        v41 = -(float)(*(float *)&v69.m128i_i32[2] * v16);
        v42 = *(float *)v69.m128i_i32 * v16;
        v43 = *(float *)&v69.m128i_i32[1] * v16;
        v66 = *(float *)v69.m128i_i32 * v16;
        v67 = *(float *)&v69.m128i_i32[1] * v16;
        v72 = v41;
        if ( !vostok::core::g_log_filter_tree )
          goto LABEL_52;
        if ( vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "physics:", info) )
          break;
LABEL_58:
        if ( (v55 & 1) != 0 )
        {
          v55 &= ~1u;
          if ( log_callback.vtable )
          {
            if ( ((int)log_callback.vtable & 1) == 0 )
            {
              v47 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
              if ( v47 )
                v47(&log_callback.functor, &log_callback.functor, 2);
            }
          }
        }
        v48 = *(int (__thiscall **)(void *))(*(_DWORD *)v77 + 32);
        v56 += 16;
        *(float *)v71.m128i_i32 = *(float *)v71.m128i_i32 + v66;
        *(float *)&v71.m128i_i32[1] = *(float *)&v71.m128i_i32[1] + v67;
        *(float *)&v71.m128i_i32[2] = *(float *)&v71.m128i_i32[2] + v68;
        v49 = ++v63;
        if ( v49 >= v48(v77) )
        {
          v6 = v70;
          goto LABEL_65;
        }
      }
      v42 = v66;
      v43 = v67;
      v41 = v72;
LABEL_52:
      v44 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      {
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
        v42 = v66;
        v43 = v67;
        v41 = v72;
      }
      if ( v44 )
      {
        log_callback.functor.obj_ptr = v44;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v45 = *v15[1];
      v46 = **v15;
      v55 |= 1u;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\bullet_physics_world.cpp",
        0x1CCu,
        "bool __thiscall vostok::physics::bullet_physics_world::recover_from_penetrations(class vostok::physics::bt_colli"
        "sion_shape *const ,const class vostok::math::float4x4 &,class vostok::math::float4x4 &,unsigned short,unsigned short)",
        "physics:",
        info,
        "recover from %x:%x delta %.3f %.3f %.3f",
        v46,
        v45,
        v42,
        v43,
        v41);
      goto LABEL_58;
    }
LABEL_65:
    v50.mVec128 = (__m128)_mm_load_si128((const __m128i *)&v74.m_worldTransform.m_basis.m_el[1].m_floats[3]);
    v51.mVec128 = (__m128)_mm_load_si128((const __m128i *)&v74.m_worldTransform.m_basis.m_el[2].m_floats[3]);
    *(__m128i *)((char *)v74.m_worldTransform.m_basis.m_el + 12) = _mm_load_si128((const __m128i *)&v74.m_worldTransform.m_basis.m_el[0].m_floats[3]);
    v52.mVec128 = (__m128)_mm_load_si128(&v71);
    *(btVector3 *)((char *)&v74.m_worldTransform.m_basis.m_el[1] + 12) = (btVector3)v50.mVec128;
    *(btVector3 *)((char *)&v74.m_worldTransform.m_basis.m_el[2] + 12) = (btVector3)v51.mVec128;
    *(btVector3 *)((char *)&v74.m_worldTransform.m_origin + 12) = (btVector3)v52.mVec128;
    if ( ptr && (_BYTE)v61 )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(ptr);
    }
    --v62;
  }
  while ( v62 );
  qmemcpy(
    (void *)transform_result,
    vostok::physics::from_bullet(
      (const btTransform *)&v74.m_worldTransform.m_basis.m_el[0].m_floats[3],
      v11,
      (vostok::math::float4x4 *)&log_callback),
    sizeof(vostok::math::float4x4));
  v6->m_dynamicsWorld->removeCollisionObject(v6->m_dynamicsWorld, (btCollisionObject *)(&v74.__vftable + 3));
  *((_DWORD *)&v74.__vftable + 3) = &btPairCachingGhostObject::`vftable';
  (**(void (__thiscall ***)(void *, _DWORD))v77)(v77, 0);
  if ( v77 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v77);
  }
  *((_DWORD *)&v74.__vftable + 3) = &btGhostObject::`vftable';
  if ( v75 && v76 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v75);
  }
  return 1;
}
