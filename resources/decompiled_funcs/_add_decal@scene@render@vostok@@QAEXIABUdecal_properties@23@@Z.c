void __thiscall vostok::render::scene::add_decal(
        vostok::render::scene *this,
        vostok::render::scene *id,
        const vostok::render::decal_properties *properties,
        const vostok::render::decal_properties *propertiesa)
{
  vostok::memory::detail::call_destructor_predicate *v4; // edi
  vostok::intrusive_ptr<vostok::render::decal_instance,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v5; // ecx
  vostok::render::decal_instance *v6; // eax

  v4 = (vostok::memory::detail::call_destructor_predicate *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                              8u);
  if ( v4 )
  {
    if ( vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           0x9Cu) )
    {
      vostok::render::decal_instance::decal_instance(
        (vostok::render::decal_instance *)id->m_decals_tree,
        id->m_decals_tree,
        propertiesa,
        (const unsigned int)properties);
    }
    else
    {
      v6 = 0;
    }
    *(_DWORD *)v4 = 0;
    vostok::intrusive_ptr<vostok::render::decal_instance,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
      v5,
      v4,
      (vostok::intrusive_ptr<vostok::render::decal_instance,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v4,
      v6);
    *(_DWORD *)&v4[4] = 0;
  }
  else
  {
    v4 = 0;
  }
  *(_DWORD *)&v4[4] = 0;
  ++id->m_decals.m_size;
  if ( id->m_decals.m_first )
    id->m_decals.m_last->next = (vostok::render::scene::decal_instance_node *)v4;
  else
    id->m_decals.m_first = (vostok::render::scene::decal_instance_node *)v4;
  id->m_decals.m_last = (vostok::render::scene::decal_instance_node *)v4;
}
