void __usercall vostok::particle::particle_system_instance_impl::prepare_render_resources(
        vostok::particle::particle_system_instance_impl *this@<ecx>,
        int a2@<esi>)
{
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v2; // eax
  vostok::particle::particle_system_instance_impl *m_object; // eax
  _DWORD *i; // edi
  bool v5; // zf
  void (__thiscall **v6)(_DWORD *, int); // ebx
  int v7; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp+Ch] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int v10; // [esp+14h] [ebp-4h]

  v2 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(*(int (__thiscall **)(_DWORD, vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *, _DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 584) + 416) + 8))(*(_DWORD *)(*(_DWORD *)(a2 + 584) + 416), &v9, *(_DWORD *)(a2 + 584));
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    v2,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(a2 + 728));
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
  v10 = 0;
  m_object = (vostok::particle::particle_system_instance_impl *)(a2 + 264);
  v9.m_object = (vostok::particle::particle_system_instance_impl *)(a2 + 264);
  do
  {
    if ( !m_object->__vftable )
      break;
    for ( i = (_DWORD *)*((_DWORD *)&m_object->vostok::resources::resource_flags + 3); i; i = (_DWORD *)i[123] )
    {
      v5 = i[117] == 0;
      i[114] = *(_DWORD *)(a2 + 584);
      if ( v5 )
      {
        v6 = (void (__thiscall **)(_DWORD *, int))(*i + 4);
        v7 = (*(int (__stdcall **)(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *, _DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 584) + 416) + 8))(
               &v8,
               *(_DWORD *)(a2 + 584),
               *(_DWORD *)(*(_DWORD *)(a2 + 584) + 416));
        (*v6)(i, v7);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v8);
        m_object = v9.m_object;
      }
    }
    ++v10;
    m_object = (vostok::particle::particle_system_instance_impl *)((char *)m_object + 32);
    v9.m_object = m_object;
  }
  while ( v10 < 0xA );
}
