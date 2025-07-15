// bad sp value at call has been detected, the output may be wrong!
void __thiscall survarium::base_player::select_animations(
        survarium::base_player *this,
        _DWORD *current_time_in_ms,
        vostok::animation::subscribed_channel **current_time_in_msa)
{
  void *v3; // esp
  int v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  int v7; // [esp-8000h] [ebp-8058h] BYREF
  vostok::animation::animation_player *v8; // [esp-4h] [ebp-5Ch]
  vostok::math::float4x4 *(__thiscall *v9)(survarium::base_player *, vostok::math::float4x4 *, survarium::base_player *); // [esp+10h] [ebp-48h] BYREF
  _BYTE v10[12]; // [esp+14h] [ebp-44h]
  boost::function<vostok::math::float4x4 __cdecl(void const *)> get_transform_functor; // [esp+20h] [ebp-38h] BYREF
  _DWORD v12[2]; // [esp+40h] [ebp-18h] BYREF
  _DWORD v13[2]; // [esp+48h] [ebp-10h] BYREF
  vostok::animation::mixing::expression expression; // [esp+50h] [ebp-8h] BYREF
  char current_time_in_ms_3; // [esp+67h] [ebp+Fh]

  survarium::base_player::tick_active_object(
    this,
    (survarium::weapon_core *)current_time_in_ms,
    (int)current_time_in_msa);
  v3 = alloca(0x8000);
  v4 = current_time_in_ms[80];
  v13[0] = &v7;
  v13[1] = 0x8000;
  (*(void (__thiscall **)(int, vostok::animation::mixing::expression *, _DWORD *))(*(_DWORD *)v4 + 40))(
    v4,
    &expression,
    v13);
  v12[0] = &survarium::selected_animations_dumper::`vftable';
  v12[1] = current_time_in_ms;
  expression.m_node.m_object->accept(expression.m_node.m_object, (vostok::animation::mixing::binary_tree_visitor *)v12);
  get_transform_functor.functor.vostok_pointer_size_alignment[2] = survarium::base_player::get_transform_for_animation_player;
  *(_QWORD *)(&get_transform_functor.functor.data + 12) = __PAIR64__((unsigned int)current_time_in_ms, 0);
  v9 = survarium::base_player::get_transform_for_animation_player;
  *(_QWORD *)v10 = __PAIR64__((unsigned int)current_time_in_ms, 0);
  v8 = (vostok::animation::animation_player *)&v9;
  *(_DWORD *)&v10[8] = get_transform_functor.functor.vostok_pointer_size_alignment[5];
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    get_transform_functor.vtable = 0;
  }
  else
  {
    *(_QWORD *)&get_transform_functor.functor.obj_ptr = __PAIR64__(*(unsigned int *)v10, (unsigned int)v9);
    *((_QWORD *)&get_transform_functor.functor.data + 1) = *(_QWORD *)&v10[4];
    get_transform_functor.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<vostok::math::float4x4,void const *>::assign_to<boost::_bi::bind_t<vostok::math::float4x4,boost::_mfi::cmf1<vostok::math::float4x4,survarium::base_player,void const *>,boost::_bi::list2<boost::_bi::value<survarium::base_player *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                                          + 1);
  }
  current_time_in_ms_3 = vostok::animation::animation_player::set_target_and_tick(
                           v8,
                           (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)current_time_in_ms
                         + 212,
                           &expression,
                           current_time_in_msa,
                           &get_transform_functor);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)&get_transform_functor);
  if ( current_time_in_ms_3 )
    current_time_in_ms[192] = -1;
  if ( expression.m_node.m_object )
  {
    if ( expression.m_node.m_object->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))expression.m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        expression.m_node.m_object,
        0);
  }
}
