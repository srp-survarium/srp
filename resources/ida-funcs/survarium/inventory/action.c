char __thiscall survarium::inventory::action(
        survarium::inventory *this,
        _DWORD *slot_id,
        int key_down,
        unsigned int current_time_in_ms,
        int a5)
{
  _DWORD *v5; // ebx
  int v6; // esi
  char v8; // bl

  v5 = slot_id;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&slot_id,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&slot_id[key_down + 68]);
  if ( slot_id
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    if ( slot_id[67] == 1 )
    {
      (*(void (__stdcall **)(unsigned int, int))(*slot_id + 32))(current_time_in_ms, a5);
    }
    else if ( slot_id[67] == 2 )
    {
      v6 = key_down;
      if ( v5[93] == key_down && !v5[95] )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&slot_id);
        return 1;
      }
      (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v5[94] + 4))(v5[94], slot_id - 4);
      v5[93] = v6;
    }
    v8 = 1;
  }
  else
  {
    v8 = 0;
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&slot_id);
  return v8;
}
