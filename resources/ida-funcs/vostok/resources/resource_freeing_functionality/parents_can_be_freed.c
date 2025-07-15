char __userpurge vostok::resources::resource_freeing_functionality::parents_can_be_freed@<al>(
        vostok::resources::resource_base *resource@<eax>,
        bool *can_try_free@<edi>,
        vostok::threading::simple_lock *a3@<ecx>,
        vostok::resources::resource_freeing_functionality *this,
        bool *can_try_decrease_quality)
{
  bool *v5; // ebx
  vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *p_m_parent_resources; // esi
  vostok::threading::simple_lock *v7; // eax
  vostok::resources::resource_link *i; // eax
  vostok::resources::resource_flags *v9; // ecx
  vostok::resources::resource_link *v10; // esi
  char v11; // bl
  vostok::threading::simple_lock::mutex_raii v13; // [esp+8h] [ebp-Ch] BYREF
  bool can_try_decrease_qualitya; // [esp+13h] [ebp-1h] BYREF

  v5 = can_try_decrease_quality;
  p_m_parent_resources = &resource->m_parent_resources;
  if ( resource == (vostok::resources::resource_base *)-60 )
    v7 = 0;
  else
    v7 = &resource->m_parent_resources.vostok::threading::simple_lock;
  v13.lock = v7;
  vostok::threading::simple_lock::lock(a3, (int)v7);
  *can_try_free = 1;
  v13.locked = 1;
  *v5 = 1;
  for ( i = vostok::resources::resource_link_list_front_no_dying(p_m_parent_resources);
        ;
        i = vostok::resources::resource_link_list_next_no_dying(v10) )
  {
    v10 = i;
    if ( !i )
    {
      v11 = 1;
      goto LABEL_13;
    }
    v9 = i->resource;
    HIBYTE(can_try_decrease_quality) = 0;
    can_try_decrease_qualitya = 0;
    if ( (vostok::resources::resource_flags::cast_base_of_intrusive_base(v9)->m_flags.m_flags & 1) != 0 )
      vostok::resources::resource_freeing_functionality::can_be_freed(
        this,
        v10->resource,
        (bool *)&can_try_decrease_quality + 3,
        &can_try_decrease_qualitya);
    if ( !HIBYTE(can_try_decrease_quality) )
    {
      *can_try_free = 0;
      if ( v10->quality_value == -1 )
        break;
    }
  }
  *v5 = 0;
  v11 = 0;
LABEL_13:
  vostok::threading::simple_lock::mutex_raii::~mutex_raii(&v13);
  return v11;
}
