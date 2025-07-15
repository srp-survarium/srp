void __usercall survarium::weapon_core_throw_grenade_state::on_throw_event_fired(
        survarium::weapon_core_throw_grenade_state *this@<ecx>,
        int a2@<eax>,
        __m128i a3@<xmm0>)
{
  int *v4; // esi
  survarium::base_player *v5; // ecx
  int v6; // ebx
  float v7; // xmm0_4
  vostok::intrusive_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp+10h] [ebp-90h] BYREF
  float v9[3]; // [esp+14h] [ebp-8Ch] BYREF
  vostok::math::float4x4 v10; // [esp+20h] [ebp-80h] BYREF
  vostok::math::float4x4 v11; // [esp+60h] [ebp-40h] BYREF

  v4 = (int *)(a2 + 360);
  survarium::grenade_set_core::logic_transform((survarium::grenade_set_core *)this, *(_DWORD *)(a2 + 360), a3, &v11);
  survarium::base_player::computed_head_transform(
    v5,
    *(vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> **)(*(_DWORD *)(a2 + 288) + 8),
    &v10);
  v6 = *v4;
  vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base>(
    (vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> *)&v8,
    (const vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(*v4 + 288) + 4 * *(unsigned __int16 *)(*v4 + 280)));
  if ( !v8.m_object->m_exploded && !v8.m_object->m_physics_world )
  {
    v7 = *(float *)(v6 + 360);
    v9[0] = v7 * v10.k.x;
    v9[1] = v7 * v10.k.y;
    v9[2] = v7 * v10.k.z;
    ((void (__stdcall *)(vostok::math::float4x4 *, float *))v8.m_object->throw_grenade)(&v11, v9);
  }
  vostok::intrusive_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v8);
}
