void __usercall survarium::weapon_core::get_dispersion(survarium::weapon_core *this@<ecx>, int a2@<esi>)
{
  float v2; // xmm0_4
  survarium::weapon_core *v3; // ecx
  survarium::weapon_core *v4; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v5; // [esp+8h] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp+Ch] [ebp-Ch] BYREF
  float v7; // [esp+10h] [ebp-8h]
  int v8; // [esp+14h] [ebp-4h]

  v8 = 0;
  v2 = s_bm_current_air_resistance;
  if ( *(float *)(a2 + 1124) == s_bm_current_air_resistance )
    v2 = 0.0;
  v3 = *(survarium::weapon_core **)(a2 + 664);
  v7 = v2;
  if ( survarium::weapon_core::ammunition(v3, &v5)->m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v4 = *(survarium::weapon_core **)(a2 + 664);
    v8 = 1;
    survarium::weapon_core::ammunition(v4, &v6);
  }
  if ( (v8 & 1) != 0 )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v6);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
}
