char __userpurge vostok::resources::resource_freeing_functionality::try_collect_parents_to_free@<al>(
        vostok::resources::resource_base *resource@<eax>,
        vostok::threading::simple_lock *a2@<ecx>,
        vostok::resources::resource_freeing_functionality *this)
{
  vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *p_m_parent_resources; // esi
  char v4; // bl
  vostok::resources::resource_link *i; // eax
  vostok::resources::resource_link *v7; // esi
  vostok::threading::simple_lock::mutex_raii v8; // [esp+8h] [ebp-Ch] BYREF

  p_m_parent_resources = &resource->m_parent_resources;
  v4 = 0;
  if ( !resource->m_parent_resources.m_first )
    return 1;
  v8.lock = &resource->m_parent_resources.vostok::threading::simple_lock;
  vostok::threading::simple_lock::lock(a2, (int)&resource->m_parent_resources.vostok::threading::simple_lock);
  v8.locked = 1;
  for ( i = vostok::resources::resource_link_list_front_no_dying(p_m_parent_resources);
        ;
        i = vostok::resources::resource_link_list_next_no_dying(v7) )
  {
    v7 = i;
    if ( !i )
      break;
    if ( !vostok::resources::resource_freeing_functionality::try_collect_to_free_resource(this, i->resource) )
      goto LABEL_8;
  }
  v4 = 1;
LABEL_8:
  vostok::threading::simple_lock::mutex_raii::~mutex_raii(&v8);
  return v4;
}
