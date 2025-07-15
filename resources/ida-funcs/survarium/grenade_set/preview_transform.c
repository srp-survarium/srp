void __userpurge survarium::grenade_set::preview_transform(
        survarium::grenade_set *this@<ecx>,
        int a2@<eax>,
        __m128i a3@<xmm0>,
        vostok::math::float4x4 *transform,
        vostok::math::float4x4 *shadow_transform)
{
  int v6; // eax
  const vostok::animation::skeleton *v7; // edi
  vostok::animation::skeleton *v8; // ecx
  int bone_index; // esi
  survarium::player *v10; // ecx
  boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *third_person_animations_resolver; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v12; // ecx
  long double v13; // rdi
  vostok::math::float4x4 *v14; // eax
  vostok::math::float4x4 *v15; // eax
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm7_4
  float z; // xmm2_4
  float x; // xmm0_4
  __int128 y_low; // xmm1
  float v23; // xmm3_4
  __m128i v24; // xmm0
  vostok::animation::mixing::n_ary_tree_intrusive_base *m_object; // eax
  const vostok::math::float4x4 *v26; // eax
  survarium::player *v27; // ecx
  vostok::math::float4x4 *v28; // edi
  vostok::math::float4x4 *p_result; // esi
  vostok::math::float4x4 *v30; // eax
  long double v31; // rdi
  vostok::math::float4x4 *v32; // eax
  vostok::math::float4x4 *v33; // eax
  float v34; // xmm2_4
  float v35; // xmm5_4
  float v36; // xmm6_4
  float v37; // xmm4_4
  float v38; // xmm7_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm3_4
  float v42; // xmm0_4
  int v43; // ecx
  int v44; // eax
  const vostok::math::float4x4 *v45; // eax
  const boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *v46; // [esp+4h] [ebp-A0h]
  vostok::math::float4x4 v47; // [esp+14h] [ebp-90h] BYREF
  vostok::math::float4x4 result; // [esp+54h] [ebp-50h] BYREF
  _DWORD v49[2]; // [esp+94h] [ebp-10h] BYREF
  float v50; // [esp+9Ch] [ebp-8h]
  float v51; // [esp+A0h] [ebp-4h]
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *animated_object; // [esp+ACh] [ebp+8h]

  v6 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 272) + 376) + 12))(*(_DWORD *)(*(_DWORD *)(a2 + 272) + 376));
  v7 = *(const vostok::animation::skeleton **)((char *)&dword_10E28 + v6);
  animated_object = (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)v6;
  bone_index = vostok::animation::skeleton::get_bone_index(v8, (int)v7, "RightMiddle1");
  third_person_animations_resolver = (boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *)survarium::player::first_third_person_animations_resolver(v10, (int)animated_object, (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&v47.lines[2]);
  vostok::animation::animation_player::computed_bone_matrix(
    (vostok::animation::animation_player *)&result,
    animated_object + 212,
    &result,
    v7,
    (const vostok::animation::skeleton_bone *)&v7[1] + bone_index,
    animated_object,
    third_person_animations_resolver,
    v46);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v12,
    (int *)&v47.k.0);
  qmemcpy(transform, &result, sizeof(vostok::math::float4x4));
  HIDWORD(v13) = v49;
  LODWORD(v13) = transform + 1;
  v14 = vostok::math::create_rotation_x(v13, a3, &v47, -1.5707964);
  vostok::math::mul4x3(transform, v14, &result);
  qmemcpy(transform, &result, sizeof(vostok::math::float4x4));
  HIDWORD(v13) = v49;
  LODWORD(v13) = transform + 1;
  v15 = vostok::math::create_rotation_y(v13, a3, &v47, 3.1415927);
  vostok::math::mul4x3(transform, v15, &result);
  qmemcpy(transform, &result, sizeof(vostok::math::float4x4));
  v16 = transform->j.x * 0.029999999;
  v17 = transform->j.y * 0.029999999;
  v18 = transform->j.z * 0.029999999;
  v19 = transform->k.x * 0.050000001;
  z = transform->i.z;
  v50 = transform->k.y * 0.050000001;
  x = transform->i.x;
  v51 = transform->k.z * 0.050000001;
  y_low = LODWORD(transform->i.y);
  v23 = (float)((float)(x * 0.02) + v19) + v16;
  *(float *)&y_low = (float)((float)(*(float *)&y_low * 0.02) + v50) + v17;
  v24 = (__m128i)y_low;
  *(float *)v24.m128i_i32 = *(float *)&y_low + transform->c.y;
  *(float *)&y_low = (float)((float)((float)(z * 0.02) + v51) + v18) + transform->c.z;
  m_object = animated_object[68].m_object;
  transform->c.x = transform->c.x + v23;
  LODWORD(transform->c.y) = v24.m128i_i32[0];
  LODWORD(transform->c.z) = y_low;
  v49[0] = animated_object + 68;
  v26 = (const vostok::math::float4x4 *)((int (*)(void))m_object[1].m_reference_count)();
  vostok::math::mul4x3(v26, transform, &v47);
  qmemcpy(transform, &v47, sizeof(vostok::math::float4x4));
  if ( survarium::player::use_third_person_animations_resolver(0, (int)animated_object) )
  {
    v28 = shadow_transform;
    p_result = &v47;
  }
  else
  {
    v30 = survarium::player::computed_shadow_bone_visual_transform(
            v27,
            (vostok::math::float4x4 *)animated_object,
            &result,
            "RightMiddle1");
    qmemcpy(shadow_transform, v30, sizeof(vostok::math::float4x4));
    HIDWORD(v31) = v30 + 1;
    LODWORD(v31) = shadow_transform + 1;
    v32 = vostok::math::create_rotation_x(v31, v24, &v47, -1.5707964);
    vostok::math::mul4x3(shadow_transform, v32, &result);
    qmemcpy(shadow_transform, &result, sizeof(vostok::math::float4x4));
    HIDWORD(v31) = v49;
    LODWORD(v31) = shadow_transform + 1;
    v33 = vostok::math::create_rotation_y(v31, v24, &v47, 3.1415927);
    vostok::math::mul4x3(shadow_transform, v33, &result);
    qmemcpy(shadow_transform, &result, sizeof(vostok::math::float4x4));
    v34 = shadow_transform->i.z;
    v35 = shadow_transform->j.y * 0.029999999;
    v36 = shadow_transform->j.z * 0.029999999;
    v37 = shadow_transform->j.x * 0.029999999;
    v38 = shadow_transform->k.x * 0.050000001;
    v50 = shadow_transform->k.y * 0.050000001;
    v39 = shadow_transform->i.x * 0.02;
    v51 = shadow_transform->k.z * 0.050000001;
    v40 = (float)(v34 * 0.02) + v51;
    v41 = shadow_transform->c.x + (float)((float)(v39 + v38) + v37);
    shadow_transform->c.y = shadow_transform->c.y + (float)((float)((float)(shadow_transform->i.y * 0.02) + v50) + v35);
    v42 = shadow_transform->c.z;
    shadow_transform->c.x = v41;
    v43 = v49[0];
    v44 = *(_DWORD *)v49[0];
    shadow_transform->c.z = v42 + (float)(v40 + v36);
    v45 = (const vostok::math::float4x4 *)(*(int (__thiscall **)(int))(v44 + 4))(v43);
    vostok::math::mul4x3(v45, shadow_transform, &result);
    p_result = &result;
    v28 = shadow_transform;
  }
  qmemcpy(v28, p_result, sizeof(vostok::math::float4x4));
}
