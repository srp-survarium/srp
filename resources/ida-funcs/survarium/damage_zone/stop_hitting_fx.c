void __usercall survarium::damage_zone::stop_hitting_fx(survarium::damage_zone *this@<ecx>, int a2@<esi>)
{
  unsigned int v2; // ebx
  vostok::sound::sound_instance_proxy *v3; // edi
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v4; // ecx
  unsigned int v5; // ebx
  unsigned int i; // edi
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v7; // eax
  unsigned int v8; // [esp+8h] [ebp-4h]

  if ( *(_BYTE *)(a2 + 340) )
  {
    v2 = 0;
    v8 = *(_DWORD *)(a2 + 576);
    if ( v8 )
    {
      do
      {
        v3 = (vostok::sound::sound_instance_proxy *)(*(_DWORD *)(a2 + 600) + 4 * v2);
        if ( v3->__vftable
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          (*((void (__thiscall **)(vostok::sound::sound_instance_proxy_vtbl *))v3->play + 3))(v3->__vftable);
          vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
            v4,
            v3);
        }
        ++v2;
      }
      while ( v2 < v8 );
    }
  }
  v5 = *(_DWORD *)(a2 + 608);
  for ( i = 0; i < v5; ++i )
  {
    v7 = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(a2 + 624) + 4 * i);
    if ( v7->m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        survarium::damage_zone::stop_particle(
          (survarium::damage_zone *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
          a2,
          v7,
          0);
    }
  }
}
