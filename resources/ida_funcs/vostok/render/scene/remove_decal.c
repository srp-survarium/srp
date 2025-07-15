void __usercall vostok::render::scene::remove_decal(
        vostok::render::scene *this@<ecx>,
        int a2@<edx>,
        vostok::memory::detail::call_destructor_predicate *a3@<ebp>)
{
  vostok::render::scene::decal_instance_node *v3; // eax
  vostok::render::scene::decal_instance_node *instance; // [esp+0h] [ebp-4h] BYREF

  instance = (vostok::render::scene::decal_instance_node *)this;
  v3 = *(vostok::render::scene::decal_instance_node **)(a2 + 884);
  instance = v3;
  if ( v3 )
  {
    while ( (vostok::render::scene *)v3->decal.m_object->m_id != this )
    {
      v3 = v3->next;
      if ( !v3 )
      {
        instance = 0;
        return;
      }
    }
    instance = v3;
    vostok::intrusive_list<vostok::render::scene::decal_instance_node,vostok::render::scene::decal_instance_node *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
      (vostok::intrusive_list<vostok::render::scene::decal_instance_node,vostok::render::scene::decal_instance_node *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)(a2 + 876),
      v3);
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::scene::decal_instance_node,vostok::memory::detail::call_destructor_predicate>(
      (vostok::render::decal_instance *)vostok::render::g_allocator.m_object,
      a3,
      (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
      (vostok::render::decal_instance ***)&instance);
  }
}
