// bad sp value at call has been detected, the output may be wrong!
void __userpurge survarium::player::select_animations(
        survarium::player *this@<ecx>,
        int a2@<eax>,
        vostok::animation::subscribed_channel **current_time_in_ms)
{
  int v4; // eax
  bool v5; // al
  int v6; // edi
  void *v7; // esp
  vostok::animation::animation_player *v8; // ecx
  vostok::animation::animation_player *v9; // ecx
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::animation::animation_player *v11; // ecx
  vostok::animation::animation_player *v12; // esi
  vostok::animation::animation_player *v13; // ecx
  void (__cdecl *v14)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  unsigned __int8 v16; // [esp-4000h] [ebp-4044h] BYREF
  boost::_bi::bind_t<vostok::math::float4x4,boost::_mfi::cmf2<vostok::math::float4x4,survarium::player,void const *,vostok::math::float4x4 const &>,boost::_bi::list3<boost::_bi::value<survarium::player *>,boost::arg<1>,boost::reference_wrapper<vostok::math::float4x4 const > > > v17; // [esp-10h] [ebp-54h]
  int v18; // [esp+0h] [ebp-44h]
  boost::function<vostok::math::float4x4 __cdecl(void const *)> get_transform_functor; // [esp+10h] [ebp-34h] BYREF
  vostok::mutable_buffer buffer; // [esp+30h] [ebp-14h] BYREF
  vostok::animation::mixing::expression expression; // [esp+38h] [ebp-Ch] BYREF

  survarium::base_player::tick_active_object((survarium::base_player *)a2);
  v4 = *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_10F04 + a2) + 952) + 8);
  v5 = v4
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && *(_BYTE *)(v4 + 52) == *(_BYTE *)(a2 + 52);
  if ( LOBYTE(survarium::g_allocator.l_.a2_.t_) )
  {
    v6 = 0;
  }
  else if ( v5 )
  {
    v6 = *(_DWORD *)(*(int *)((char *)&dword_10EF4 + a2) + 408);
  }
  else
  {
    v6 = 2;
  }
  v7 = alloca(0x4000);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &buffer,
    &v16,
    0x4000u);
  (*(void (__thiscall **)(_DWORD, vostok::animation::mixing::expression *, vostok::mutable_buffer *, bool))(**(_DWORD **)(a2 + 64) + 48))(
    *(_DWORD *)(a2 + 64),
    &expression,
    &buffer,
    v6 == 2);
  get_transform_functor.functor.vostok_pointer_size_alignment[2] = survarium::player::get_transform_for_animation_player;
  get_transform_functor.functor.vostok_pointer_size_alignment[3] = 0;
  v17.f_.f_ = (vostok::math::float4x4 *(__thiscall *__ptr64)(survarium::player *, vostok::math::float4x4 *, const void *, const vostok::math::float4x4 *))(unsigned int)survarium::player::get_transform_for_animation_player;
  get_transform_functor.functor.bound_memfunc_ptr.obj_ptr = (void *)a2;
  get_transform_functor.functor.vostok_pointer_size_alignment[5] = &byte_10D44[a2];
  v17.l_ = (boost::_bi::list3<boost::_bi::value<survarium::player *>,boost::arg<1>,boost::reference_wrapper<vostok::math::float4x4 const > >)*((_QWORD *)&get_transform_functor.functor.data + 2);
  boost::function1<vostok::math::float4x4,void const *>::function1<vostok::math::float4x4,void const *>(
    0,
    (int)&get_transform_functor,
    a2,
    v17,
    v18);
  if ( *(int *)((char *)&dword_10D18 + a2) )
    vostok::animation::animation_player::tick(v8, a2 + 34812, current_time_in_ms);
  vostok::animation::animation_player::set_target(
    &expression,
    (vostok::animation::mixing::n_ary_tree_converter *)v8,
    (vostok::animation::animation_player *)(a2 + 34812),
    (char *)current_time_in_ms,
    &get_transform_functor);
  vostok::animation::animation_player::tick(v9, a2 + 34812, current_time_in_ms);
  if ( get_transform_functor.vtable )
  {
    if ( ((int)get_transform_functor.vtable & 1) == 0 )
    {
      v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)get_transform_functor.vtable & 0xFFFFFFFE);
      if ( v10 )
        v10(&get_transform_functor.functor, &get_transform_functor.functor, 2);
    }
  }
  get_transform_functor.functor.vostok_pointer_size_alignment[2] = survarium::player::get_transform_for_animation_player;
  get_transform_functor.functor.vostok_pointer_size_alignment[3] = 0;
  v17.f_.f_ = (vostok::math::float4x4 *(__thiscall *__ptr64)(survarium::player *, vostok::math::float4x4 *, const void *, const vostok::math::float4x4 *))(unsigned int)survarium::player::get_transform_for_animation_player;
  get_transform_functor.functor.bound_memfunc_ptr.obj_ptr = (void *)a2;
  get_transform_functor.functor.vostok_pointer_size_alignment[5] = (void *)(a2 + 34672);
  v17.l_ = (boost::_bi::list3<boost::_bi::value<survarium::player *>,boost::arg<1>,boost::reference_wrapper<vostok::math::float4x4 const > >)*((_QWORD *)&get_transform_functor.functor.data + 2);
  boost::function1<vostok::math::float4x4,void const *>::function1<vostok::math::float4x4,void const *>(
    0,
    (int)&get_transform_functor,
    a2,
    v17,
    v18);
  v12 = (vostok::animation::animation_player *)(a2 + 552);
  if ( v12->m_mixing_tree.m_animations_count )
    vostok::animation::animation_player::tick(v11, (int)v12, current_time_in_ms);
  vostok::animation::animation_player::set_target(
    &expression,
    (vostok::animation::mixing::n_ary_tree_converter *)v11,
    v12,
    (char *)current_time_in_ms,
    &get_transform_functor);
  vostok::animation::animation_player::tick(v13, (int)v12, current_time_in_ms);
  if ( get_transform_functor.vtable )
  {
    if ( ((int)get_transform_functor.vtable & 1) == 0 )
    {
      v14 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)get_transform_functor.vtable & 0xFFFFFFFE);
      if ( v14 )
        v14(&get_transform_functor.functor, &get_transform_functor.functor, 2);
    }
  }
  if ( expression.m_node.m_object )
  {
    if ( expression.m_node.m_object->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))expression.m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        expression.m_node.m_object,
        0);
  }
}
