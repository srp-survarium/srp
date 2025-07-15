void __usercall survarium::weapon_core::reload_one_round(survarium::weapon_core *this@<ecx>, int a2@<esi>)
{
  bool v2; // bl
  int m_last_low; // edi
  int *v4; // eax
  survarium::weapon_core *v5; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp+8h] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp+Ch] [ebp-4h] BYREF

  v7.m_object = 0;
  v2 = 0;
  if ( *(_WORD *)(a2 + 1102) != *(_WORD *)(a2 + 1100) )
  {
    v7.m_object = (vostok::particle::particle_system_instance_impl *)1;
    if ( LOWORD(survarium::weapon_core::ammunition((survarium::weapon_core *)a2, &v6)->m_object->m_lods[0].m_emitter_instance_list.m_last) )
      v2 = 1;
  }
  if ( ((int)v7.m_object & 1) != 0 )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v6);
  if ( v2 )
  {
    ++*(_WORD *)(a2 + 1102);
    m_last_low = LOWORD(survarium::weapon_core::ammunition((survarium::weapon_core *)a2, &v7)->m_object->m_lods[0].m_emitter_instance_list.m_last);
    v4 = (int *)survarium::weapon_core::ammunition((survarium::weapon_core *)a2, &v6);
    survarium::inventory_item::set_amount((survarium::inventory_item *)(m_last_low - 1), *v4);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v6);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)a2 + 168))(a2);
  *(_DWORD *)(a2 + 624) = -1;
  *(_DWORD *)(a2 + 628) = -1;
  *(_DWORD *)(a2 + 632) = -1;
  *(_DWORD *)(a2 + 604) = 0;
  *(_DWORD *)(a2 + 608) = 0;
  *(_DWORD *)(a2 + 612) = 0;
  *(_DWORD *)(a2 + 616) = 0;
  *(_DWORD *)(a2 + 620) = 0;
  *(float *)(a2 + 600) = s_bm_current_air_resistance;
  survarium::weapon_core::reset_fire_queue(v5, a2);
  *(_BYTE *)(a2 + 1116) = 0;
}
