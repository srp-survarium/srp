vostok::math::float4x4 *__userpurge survarium::base_player::computed_head_transform@<eax>(
        survarium::base_player *this@<ecx>,
        vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *a2@<eax>,
        vostok::math::float4x4 *result)
{
  const vostok::animation::skeleton *v4; // edi
  int bone_index; // eax
  vostok::math::float4x4 *v6; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // [esp-4h] [ebp-6Ch]
  boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> bone_mask; // [esp+8h] [ebp-60h] BYREF
  vostok::math::float4x4 resulta; // [esp+28h] [ebp-40h] BYREF

  bone_mask.vtable = 0;
  v4 = *(const vostok::animation::skeleton **)((char *)&dword_10E28 + (_DWORD)a2);
  bone_index = vostok::animation::skeleton::get_bone_index((vostok::animation::skeleton *)this, (int)v4, "Head");
  v6 = vostok::animation::animation_player::computed_bone_matrix(
         (vostok::animation::animation_player *)&bone_mask,
         a2 + 212,
         &resulta,
         v4,
         (const vostok::animation::skeleton_bone *)&v4[1] + bone_index,
         a2,
         &bone_mask,
         (const boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *)&byte_10E2C[(_DWORD)a2]);
  vostok::animation::calculated_head_matrix(
    (int)v4,
    result,
    v6,
    (const vostok::math::float4x4 *)&byte_10E2C[(_DWORD)a2]);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)&bone_mask);
  return result;
}
