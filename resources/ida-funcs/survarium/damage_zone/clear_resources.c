void __usercall survarium::damage_zone::clear_resources(survarium::damage_zone *this@<ecx>, _DWORD *a2@<esi>)
{
  unsigned int v2; // ebp
  unsigned int i; // ebx
  vostok::sound::sound_instance_proxy *v4; // edi
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v5; // ecx
  vostok::sound::sound_instance_proxy *v6; // edi
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v7; // ecx
  unsigned int v8; // ebp
  unsigned int j; // ebx
  int v10; // edi
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v11; // eax
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v12; // eax
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v13; // eax
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v14; // eax

  v2 = a2[144];
  for ( i = 0; i < v2; ++i )
  {
    v4 = (vostok::sound::sound_instance_proxy *)(a2[149] + 4 * i);
    if ( v4->__vftable
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      (*((void (__thiscall **)(vostok::sound::sound_instance_proxy_vtbl *))v4->play + 3))(v4->__vftable);
      vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
        v5,
        v4);
    }
    v6 = (vostok::sound::sound_instance_proxy *)(a2[150] + 4 * i);
    if ( v6->__vftable
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      (*((void (__thiscall **)(vostok::sound::sound_instance_proxy_vtbl *))v6->play + 3))(v6->__vftable);
      vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
        v7,
        v6);
    }
  }
  v8 = a2[152];
  for ( j = 0; j < v8; ++j )
  {
    v10 = 4 * j;
    v11 = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(4 * j + a2[153]);
    if ( v11->m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      survarium::damage_zone::stop_particle(
        (survarium::damage_zone *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
        (int)a2,
        v11,
        1);
    }
    v12 = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(v10 + a2[154]);
    if ( v12->m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      survarium::damage_zone::stop_particle(
        (survarium::damage_zone *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
        (int)a2,
        v12,
        1);
    }
    v13 = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(v10 + a2[155]);
    if ( v13->m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      survarium::damage_zone::stop_particle(
        (survarium::damage_zone *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
        (int)a2,
        v13,
        1);
    }
    v14 = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(v10 + a2[156]);
    if ( v14->m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        survarium::damage_zone::stop_particle(
          (survarium::damage_zone *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
          (int)a2,
          v14,
          1);
    }
  }
}
