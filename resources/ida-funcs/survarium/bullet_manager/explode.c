void __userpurge survarium::bullet_manager::explode(
        long double position@<esi:edi>,
        survarium::bullet_manager *this,
        unsigned int current_time_in_ms,
        const survarium::hit_initiator *const initiator)
{
  vostok::physics::world *m_physics_world; // ecx
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  float *v9; // eax
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  vostok::physics::world *v16; // ecx
  int v17; // ecx
  float v18; // xmm0_4
  int **v19; // eax
  int v20; // edx
  unsigned __int16 v21; // ax
  survarium::game_material_manager *v22; // ecx
  float m_armor; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm3_4
  int v26; // eax
  float v27; // xmm1_4
  float v28; // [esp+40h] [ebp-FCh]
  unsigned int v29; // [esp+50h] [ebp-ECh]
  vostok::math::float4x4 v30; // [esp+58h] [ebp-E4h] BYREF
  vostok::math::float4x4 v31; // [esp+98h] [ebp-A4h] BYREF
  float v32; // [esp+D8h] [ebp-64h]
  float v33; // [esp+DCh] [ebp-60h]
  float v34; // [esp+E0h] [ebp-5Ch]
  int *v35; // [esp+E4h] [ebp-58h]
  const vostok::math::float4x4 *v36; // [esp+E8h] [ebp-54h]
  float v37; // [esp+ECh] [ebp-50h] BYREF
  float v38; // [esp+F0h] [ebp-4Ch]
  float v39; // [esp+F4h] [ebp-48h]
  int v40; // [esp+F8h] [ebp-44h] BYREF
  int v41; // [esp+FCh] [ebp-40h]
  vostok::memory::pthreads3_allocator *v42; // [esp+100h] [ebp-3Ch]
  int v43; // [esp+104h] [ebp-38h]
  int v44; // [esp+108h] [ebp-34h] BYREF
  int v45; // [esp+10Ch] [ebp-30h]
  vostok::memory::pthreads3_allocator *v46; // [esp+110h] [ebp-2Ch]
  int v47; // [esp+114h] [ebp-28h]
  int (__thiscall ****v48)(_DWORD); // [esp+118h] [ebp-24h]
  int v49; // [esp+11Ch] [ebp-20h]
  int v50; // [esp+120h] [ebp-1Ch]
  unsigned int v51; // [esp+124h] [ebp-18h]
  float v52; // [esp+128h] [ebp-14h]
  survarium::base_player *v53; // [esp+12Ch] [ebp-10h]
  vostok::physics::bt_animated_rigid_body **v54; // [esp+130h] [ebp-Ch]
  vostok::physics::bt_animated_rigid_body *v55; // [esp+134h] [ebp-8h]

  m_physics_world = this->m_physics_world;
  v28 = *(float *)(HIDWORD(position) + 40);
  v44 = 0;
  v45 = 0;
  v46 = &vostok::memory::g_mt_allocator;
  v47 = 0;
  ((void (__thiscall *)(vostok::physics::world *, _DWORD, _DWORD, int, int, int *))m_physics_world->get_all_objects_in_radius)(
    m_physics_world,
    LODWORD(position),
    LODWORD(v28),
    16,
    64,
    &v44);
  v50 = 0;
  if ( (v45 - v44) >> 2 )
  {
    v6 = 0;
    while ( 1 )
    {
      v7 = *(_DWORD *)(v44 + 4 * v6);
      v8 = *(_DWORD *)(v7 + 12);
      v48 = (int (__thiscall ****)(_DWORD))v7;
      v53 = (survarium::base_player *)(*(int (__thiscall **)(int))(*(_DWORD *)v8 + 8))(v8);
      if ( v53 )
      {
        v9 = (float *)((int (__thiscall *)(int (__thiscall ****)(_DWORD), vostok::math::float4x4 *))(*v48)[7])(
                        v48,
                        &v30);
        v10 = *(float *)(LODWORD(position) + 8) - v9[14];
        v11 = *(float *)(LODWORD(position) + 4) - v9[13];
        v12 = (float)(*(float *)(HIDWORD(position) + 40)
                    - fsqrt(
                        (float)((float)(v10 * v10) + (float)(v11 * v11))
                      + (float)((float)(*(float *)LODWORD(position) - v9[12])
                              * (float)(*(float *)LODWORD(position) - v9[12]))))
            / *(float *)(HIDWORD(position) + 40);
        if ( v12 >= 0.0 )
        {
          v34 = (float)((float)(*(float *)(HIDWORD(position) + 48) - *(float *)(HIDWORD(position) + 44)) * v12)
              + *(float *)(HIDWORD(position) + 44);
          survarium::base_player::recompute_damage_collision_bones(v53, 0);
          v36 = v53->transform(&v53->survarium::collision_user);
          v55 = (vostok::physics::bt_animated_rigid_body *)*(_DWORD *)HIDWORD(position);
          if ( v55 != (vostok::physics::bt_animated_rigid_body *)-1 )
            break;
        }
      }
LABEL_18:
      v6 = (unsigned __int16)++v50;
      v5 = (v45 - v44) >> 2;
      if ( (unsigned __int16)v50 >= v5 )
        goto LABEL_19;
    }
    v54 = (vostok::physics::bt_animated_rigid_body **)HIDWORD(position);
    while ( 1 )
    {
      vostok::physics::bt_animated_rigid_body::get_bone_transform(
        v55,
        *(_DWORD *)(*(int *)((char *)&dword_10E78 + (_DWORD)v53) + 300),
        position,
        &v30,
        v29);
      vostok::math::mul4x3(v36, &v30, &v31);
      v13 = v31.c.x - *(float *)LODWORD(position);
      v14 = v31.c.z - *(float *)(LODWORD(position) + 8);
      v15 = v31.c.y - *(float *)(LODWORD(position) + 4);
      v16 = this->m_physics_world;
      v33 = fsqrt((float)((float)(v13 * v13) + (float)(v14 * v14)) + (float)(v15 * v15));
      v40 = 0;
      v41 = 0;
      v42 = &vostok::memory::g_mt_allocator;
      v43 = 0;
      v37 = (float)(s_bm_current_air_resistance / v33) * v13;
      v38 = v15 * (float)(s_bm_current_air_resistance / v33);
      v39 = v14 * (float)(s_bm_current_air_resistance / v33);
      v16->ray_query(
        v16,
        (const vostok::math::float3 *)LODWORD(position),
        (const vostok::math::float3 *)&v37,
        COERCE_FLOAT(LODWORD(v33)),
        (vostok::vectora<vostok::physics::closest_ray_result> *)&v40,
        16u,
        8u);
      v17 = 40;
      v18 = *(float *)(HIDWORD(position) + 52);
      v52 = v18;
      v51 = 0;
      if ( (v41 - v40) / 40 )
        break;
LABEL_15:
      v32 = (float)(v18 / *(float *)(HIDWORD(position) + 52)) * v34;
      if ( v18 > 0.0 )
      {
        v26 = (**v48[3])(v48[3]);
        (*(void (__thiscall **)(int, unsigned int, const survarium::hit_initiator *const, vostok::physics::bt_animated_rigid_body *, _DWORD, float, _DWORD, _DWORD, vostok::math::float4_pod *, _DWORD, _DWORD))(*(_DWORD *)v26 + 24))(
          v26,
          current_time_in_ms,
          initiator,
          v55,
          *(_DWORD *)(HIDWORD(position) + 32),
          COERCE_FLOAT(LODWORD(v32)),
          1.0,
          0,
          &v31.c,
          0,
          *(unsigned __int16 *)(HIDWORD(position) + 36));
      }
      vostok::vectora<vostok::physics::closest_ray_result>::~vectora<vostok::physics::closest_ray_result>(
        (vostok::vectora<vostok::physics::closest_ray_result> *)v17,
        (int)&v40);
      v55 = *++v54;
      if ( v55 == (vostok::physics::bt_animated_rigid_body *)-1 )
        goto LABEL_18;
    }
    v49 = 0;
    while ( 1 )
    {
      v19 = (int **)(v40 + v49);
      if ( (float)((float)((float)(*(float *)(v40 + v49 + 24) * v39) + (float)(*(float *)(v40 + v49 + 20) * v38))
                 + (float)(*(float *)(v40 + v49 + 16) * v37)) < 0.0 )
        break;
LABEL_14:
      v17 = 40;
      ++v51;
      v49 += 40;
      if ( v51 >= (v41 - v40) / 40 )
        goto LABEL_15;
    }
    v20 = **v19;
    v35 = *v19;
    v21 = (*(int (__thiscall **)(int *, int *, _DWORD))(v20 + 16))(v35, v19[7], *((unsigned __int8 *)v19 + 32));
    m_armor = survarium::game_material_manager::get_material(v22, (int)this->m_game_material_manager, v21)->m_armor;
    if ( m_armor == 0.0 )
    {
      v24 = s_bm_current_air_resistance;
    }
    else
    {
      v27 = (float)(v52 - m_armor) / m_armor;
      v24 = s_bm_current_air_resistance;
      if ( v27 <= 0.0 )
      {
        v25 = 0.0;
        goto LABEL_13;
      }
      if ( s_bm_current_air_resistance >= v27 )
      {
        v25 = v27;
        goto LABEL_13;
      }
    }
    v25 = v24;
LABEL_13:
    v18 = (float)(v24 - (float)((float)(v24 - v25) * (float)(v24 - v25))) * v52;
    v52 = v18;
    goto LABEL_14;
  }
LABEL_19:
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
    (stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *> > *)v5,
    (int)&v44);
}
