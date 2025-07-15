vostok::math::float4x4 *__thiscall survarium::player::computed_shadow_bone_visual_transform(
        survarium::player *this,
        vostok::math::float4x4 *result,
        vostok::math::float4x4 *bone_name,
        char *a4)
{
  const vostok::animation::skeleton *v4; // edi
  int bone_index; // esi
  survarium::player *v6; // ecx
  boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *v7; // eax
  vostok::animation::animation_player *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  const boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *v11; // [esp+0h] [ebp-34h]
  int v12[9]; // [esp+10h] [ebp-24h] BYREF

  v4 = *(const vostok::animation::skeleton **)((char *)&dword_10E28 + (_DWORD)result);
  bone_index = vostok::animation::skeleton::get_bone_index((vostok::animation::skeleton *)this, (int)v4, a4);
  v7 = (boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *)survarium::player::third_person_animations_resolver(v6, (boost::_bi::bind_t<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,boost::_mfi::mf1<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,survarium::animations_registry,unsigned short>,boost::_bi::list2<boost::_bi::value<survarium::animations_registry *>,boost::arg<1> > > *)v12);
  vostok::animation::animation_player::computed_bone_matrix(
    v8,
    (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&result[13].lines[1],
    bone_name,
    v4,
    (const vostok::animation::skeleton_bone *)&v4[1] + bone_index,
    result,
    v7,
    v11);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v9, v12);
  return bone_name;
}
