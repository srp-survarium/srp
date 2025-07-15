void __usercall vostok::memory::delete_array_helper<vostok::memory::doug_lea_allocator,vostok::render::model_asset>(
        vostok::render::model_asset **pointer@<eax>,
        vostok::memory::doug_lea_allocator *a2@<ecx>,
        vostok::memory::doug_lea_allocator *allocator)
{
  int v3; // ebx
  char *v4; // edi
  int v5; // esi
  const char *v6; // [esp+0h] [ebp-14h]
  const char *v7; // [esp+4h] [ebp-10h]
  unsigned int v8; // [esp+8h] [ebp-Ch]
  int v9; // [esp+10h] [ebp-4h]

  v3 = (int)*pointer;
  if ( *pointer )
  {
    v4 = (char *)(v3 - 8);
    v9 = *(_DWORD *)(v3 - 8 + 4);
    v5 = v3 + v9 * *(_DWORD *)(v3 - 8);
    while ( v3 != v5 )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(v3 + 8));
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(v3 + 4));
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)v3);
      v3 += v9;
    }
    vostok::memory::doug_lea_allocator::free_impl(a2, (int)allocator, v4, v6, v7, v8);
  }
}
