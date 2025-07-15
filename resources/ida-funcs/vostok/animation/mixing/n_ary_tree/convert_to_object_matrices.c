void __userpurge vostok::animation::mixing::n_ary_tree::convert_to_object_matrices(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        void *animated_object,
        const vostok::animation::skeleton *skeleton,
        vostok::math::float4x4 *const begin,
        vostok::math::float4x4 *const end,
        const unsigned __int8 calc_mask)
{
  vostok::animation::bone_matrices_computer *v6; // eax
  vostok::animation::bone_matrices_computer *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  unsigned __int8 v9; // [esp+0h] [ebp-40h]
  vostok::animation::bone_matrices_computer v10; // [esp+8h] [ebp-38h] BYREF
  boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> animation_resolver; // [esp+20h] [ebp-20h] BYREF

  animation_resolver.vtable = 0;
  vostok::animation::bone_matrices_computer::bone_matrices_computer(
    this->m_animation_states,
    this->m_animations_count,
    &v10,
    animated_object,
    skeleton,
    &animation_resolver);
  vostok::animation::bone_matrices_computer::convert_to_object_matrices(begin, v6, end, v9);
  vostok::animation::bone_matrices_computer::~bone_matrices_computer(v7, (int)&v10);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)&animation_resolver);
}
