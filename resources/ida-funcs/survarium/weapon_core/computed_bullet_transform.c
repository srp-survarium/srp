vostok::math::float4x4 *__userpurge survarium::weapon_core::computed_bullet_transform@<eax>(
        survarium::weapon_core *this@<ecx>,
        int a2@<eax>,
        vostok::math::float4x4 *result)
{
  const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v4; // eax
  const vostok::animation::skeleton *v5; // esi
  const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v6; // ebx
  int bone_index; // eax
  vostok::animation::animation_player *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  int v10; // edi
  const vostok::math::float4x4 *v11; // eax
  vostok::math::float4x4 *v12; // eax
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v13; // [esp-8h] [ebp-9Ch]
  const boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *v14; // [esp+0h] [ebp-94h]
  vostok::math::float4x4 resulta; // [esp+10h] [ebp-84h] BYREF
  vostok::math::float4x4 v16; // [esp+50h] [ebp-44h] BYREF

  v16.k.x = 0.0;
  v4 = *(const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 8);
  v5 = *(const vostok::animation::skeleton **)((char *)&dword_10E28 + (_DWORD)v4);
  v6 = v4;
  v13 = (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)v4;
  bone_index = vostok::animation::skeleton::get_bone_index((vostok::animation::skeleton *)this, (int)v5, "Head");
  vostok::animation::animation_player::computed_bone_matrix(
    v8,
    v6 + 212,
    &resulta,
    v5,
    (const vostok::animation::skeleton_bone *)&v5[1] + bone_index,
    v13,
    (boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *)&v16.lines[2],
    v14);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)&v16.k.0);
  v10 = *(_DWORD *)(a2 + 8);
  v11 = (const vostok::math::float4x4 *)(*(int (__thiscall **)(int))(*(_DWORD *)(v10 + 272) + 4))(v10 + 272);
  vostok::animation::calculated_head_matrix(v10, &v16, &resulta, v11);
  v12 = result;
  qmemcpy(result, &v16, sizeof(vostok::math::float4x4));
  return v12;
}
