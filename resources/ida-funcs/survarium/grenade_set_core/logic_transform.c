vostok::math::float4x4 *__userpurge survarium::grenade_set_core::logic_transform@<eax>(
        survarium::grenade_set_core *this@<ecx>,
        int a2@<eax>,
        __m128i a3@<xmm0>,
        vostok::math::float4x4 *result)
{
  int v5; // eax
  long double v6; // rdi
  const vostok::animation::skeleton *v7; // esi
  vostok::animation::skeleton *v8; // ecx
  int bone_index; // eax
  vostok::animation::animation_player *v10; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  vostok::math::float4x4 *v12; // eax
  vostok::math::float4x4 *v13; // eax
  float x; // xmm7_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm6_4
  float v18; // xmm0_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // eax
  const vostok::math::float4x4 *v23; // eax
  void *v25; // [esp-4h] [ebp-ACh]
  const boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *v26; // [esp+4h] [ebp-A4h]
  vostok::math::float4x4 v27; // [esp+14h] [ebp-94h] BYREF
  vostok::math::float4x4 v28; // [esp+54h] [ebp-54h] BYREF
  int v29; // [esp+94h] [ebp-14h] BYREF
  float v30; // [esp+9Ch] [ebp-Ch]
  float v31; // [esp+A0h] [ebp-8h]
  vostok::math::float4x4 *resulta; // [esp+B0h] [ebp+8h]

  v5 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 272) + 376) + 12))(*(_DWORD *)(*(_DWORD *)(a2 + 272) + 376));
  v28.k.x = 0.0;
  LODWORD(v6) = v5;
  v7 = *(const vostok::animation::skeleton **)((char *)&dword_10E28 + v5);
  v25 = (void *)v5;
  resulta = (vostok::math::float4x4 *)v5;
  bone_index = vostok::animation::skeleton::get_bone_index(v8, (int)v7, "RightMiddle1");
  vostok::animation::animation_player::computed_bone_matrix(
    v10,
    (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)(LODWORD(v6) + 848),
    result,
    v7,
    (const vostok::animation::skeleton_bone *)&v7[1] + bone_index,
    v25,
    (boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *)&v28.lines[2],
    v26);
  HIDWORD(v6) = &v28.k;
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v11,
    (int *)&v28.k.0);
  v12 = vostok::math::create_rotation_x(v6, a3, &v27, -1.5707964);
  vostok::math::mul4x3(result, v12, &v28);
  qmemcpy(result, &v28, sizeof(vostok::math::float4x4));
  HIDWORD(v6) = &v29;
  LODWORD(v6) = result + 1;
  v13 = vostok::math::create_rotation_y(v6, a3, &v27, 3.1415927);
  vostok::math::mul4x3(result, v13, &v28);
  qmemcpy(result, &v28, sizeof(vostok::math::float4x4));
  x = result->k.x;
  v15 = result->j.x * 0.029999999;
  v16 = result->j.y * 0.029999999;
  v17 = result->j.z * 0.029999999;
  v30 = result->k.y * 0.050000001;
  v18 = result->i.x;
  v31 = result->k.z * 0.050000001;
  v19 = (float)((float)(v18 * 0.02) + (float)(x * 0.050000001)) + v15;
  v20 = (float)((float)((float)(result->i.y * 0.02) + v30) + v16) + result->c.y;
  v21 = (float)((float)((float)(result->i.z * 0.02) + v31) + v17) + result->c.z;
  v22 = resulta[4].j.x;
  result->c.x = result->c.x + v19;
  result->c.y = v20;
  result->c.z = v21;
  v23 = (const vostok::math::float4x4 *)(*(int (__thiscall **)($91D1B2149FAC90180ECB9AC277F76009 *))(LODWORD(v22) + 4))(&resulta[4].j.0);
  vostok::math::mul4x3(v23, result, &v28);
  qmemcpy(result, &v28, sizeof(vostok::math::float4x4));
  return result;
}
