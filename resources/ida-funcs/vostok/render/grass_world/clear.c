void __usercall vostok::render::grass_world::clear(vostok::render::grass_world *this@<ecx>, _DWORD *a2@<esi>)
{
  vostok::intrusive_list<vostok::render::grass_instance,vostok::render::grass_instance *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v2; // ebx
  vostok::render::grass_instance *m_first; // edi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v4; // edi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **v5; // ebx
  vostok::intrusive_list<vostok::render::grass_instance,vostok::render::grass_instance *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *i; // [esp+Ch] [ebp-4h]

  vostok::render::grass_world::remove_patches(this, a2);
  v2 = (vostok::intrusive_list<vostok::render::grass_instance,vostok::render::grass_instance *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)a2[67];
  for ( i = (vostok::intrusive_list<vostok::render::grass_instance,vostok::render::grass_instance *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)a2[68];
        v2 != i;
        v2 = (vostok::intrusive_list<vostok::render::grass_instance,vostok::render::grass_instance *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)((char *)v2 + 36) )
  {
    while ( 1 )
    {
      m_first = v2->m_first;
      if ( !m_first )
        break;
      vostok::intrusive_list<vostok::render::grass_instance,vostok::render::grass_instance *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
        v2,
        v2->m_first);
      m_first->template_ = (vostok::render::grass_template *)a2[78];
      a2[78] = m_first;
      --a2[79];
    }
  }
  v4 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)a2[67];
  v5 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 68);
  while ( v4 != *v5 )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v4 + 4);
    v4 += 9;
  }
  *v5 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)a2[67];
}
