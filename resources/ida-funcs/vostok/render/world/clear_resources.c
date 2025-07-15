void __usercall vostok::render::world::clear_resources(vostok::render::world *this@<ecx>, int a2@<eax>)
{
  int v2; // esi
  int v3; // eax
  int v4; // eax
  vostok::particle::particle_system_instance_impl *v5; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp+4h] [ebp-4h] BYREF

  v2 = *(_DWORD *)(**(_DWORD **)(a2 + 352) + 480);
  v3 = *(_DWORD *)(v2 + 16264);
  if ( v3 )
  {
    v4 = *(int *)((char *)&dword_8B9664 + v3);
    if ( v4 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 80))(v4);
  }
  v5 = *(vostok::particle::particle_system_instance_impl **)(v2 + 16268);
  *(_DWORD *)(v2 + 16268) = 0;
  v6.m_object = v5;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v6);
}
