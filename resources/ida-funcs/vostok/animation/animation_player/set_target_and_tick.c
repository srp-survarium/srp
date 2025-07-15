char __userpurge vostok::animation::animation_player::set_target_and_tick@<al>(
        vostok::animation::animation_player *this@<ecx>,
        float a2@<xmm4>,
        const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *expression,
        vostok::animation::mixing::expression *current_time_in_ms,
        vostok::animation::subscribed_channel **transform_in_case_of_a_single_object_usage,
        int a5)
{
  char v6; // bl
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  __int64 v9; // [esp+8h] [ebp-28h] BYREF
  boost::function<vostok::math::float4x4 __cdecl(void const *)> v10; // [esp+10h] [ebp-20h] BYREF

  LODWORD(v9) = vostok::animation::single_object_get_transform;
  HIDWORD(v9) = a5;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)this) )
  {
    v10.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v10.functor.obj_ptr = v9;
    v10.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<vostok::math::float4x4,void const *>::assign_to<boost::_bi::bind_t<vostok::math::float4x4,vostok::math::float4x4 (__cdecl *)(vostok::math::float4x4 const &,void const *),boost::_bi::list2<boost::reference_wrapper<vostok::math::float4x4 const>,boost::arg<1>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  v6 = vostok::animation::animation_player::set_target_and_tick(
         (vostok::animation::animation_player *)&v9,
         expression,
         a2,
         current_time_in_ms,
         transform_in_case_of_a_single_object_usage,
         &v10);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)&v10);
  return v6;
}


char __userpurge vostok::animation::animation_player::set_target_and_tick@<al>(
        vostok::animation::animation_player *this@<ecx>,
        const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *a2@<eax>,
        float a3@<xmm4>,
        vostok::animation::mixing::expression *expression,
        vostok::animation::subscribed_channel **current_time_in_ms,
        const boost::function<vostok::math::float4x4 __cdecl(void const *)> *get_transform_functor)
{
  vostok::particle::particle_system_instance_impl *(__thiscall *v7)(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // edi
  vostok::animation::animation_player *v8; // ecx
  char v9; // bl
  vostok::animation::animation_player *v10; // ecx
  unsigned int v12; // [esp+0h] [ebp-14h]
  bool v13; // [esp+4h] [ebp-10h]
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> v14; // [esp+10h] [ebp-4h] BYREF

  v7 = vostok::animation::tree(a2 + 16432, &v14)->m_object != 0
     ? vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
     : 0;
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&v14);
  if ( v7 )
    vostok::animation::animation_player::tick_impl(v8, (int)a2, a3, current_time_in_ms, v12, v13);
  v9 = vostok::animation::animation_player::set_target(
         v8,
         a3,
         (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>)a2,
         expression,
         (boost::function<vostok::math::float4x4 __cdecl(void const *)> *)current_time_in_ms,
         *(float *)&get_transform_functor);
  vostok::animation::animation_player::tick_impl(v10, (int)a2, a3, current_time_in_ms, v12, v13);
  return v9;
}
