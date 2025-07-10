void __userpurge vostok::resources::sorting_functionality::sort_resources_if_needed(
        vostok::resources::memory_type *memory_type@<esi>,
        vostok::resources::sorting_functionality *this)
{
  void *v2; // esp
  vostok::resources::resource_base *m_first; // edi
  vostok::resources::resource_base **v4; // ecx
  vostok::resources::resource_base **v5; // ebx
  int v6; // eax
  int i; // edi
  vostok::resources::resource_base *v8; // eax
  _BYTE v9[12]; // [esp+0h] [ebp-14h] BYREF
  vostok::resources::sorting_predicate __comp[4]; // [esp+Ch] [ebp-8h]
  vostok::resources::resource_base **__first; // [esp+10h] [ebp-4h]

  if ( LODWORD(memory_type->sort_actuality_tick) != LODWORD(this->m_sort_actuality_tick)
    || HIDWORD(memory_type->sort_actuality_tick) != HIDWORD(this->m_sort_actuality_tick) )
  {
    v2 = alloca(4 * memory_type->resources.m_size);
    m_first = memory_type->resources.m_first;
    v4 = (vostok::resources::resource_base **)v9;
    __first = (vostok::resources::resource_base **)v9;
    v5 = (vostok::resources::resource_base **)v9;
    if ( m_first )
    {
      do
      {
        if ( v5 )
          *v5 = m_first;
        ++v5;
        vostok::resources::resource_reconstruction_info::update_reconstruction_info(
          &m_first->vostok::resources::resource_reconstruction_info,
          this->m_sort_actuality_tick);
        m_first = m_first->m_next_in_memory_type;
      }
      while ( m_first );
      v4 = __first;
    }
    __comp[0] = 0;
    if ( v4 != v5 )
    {
      v6 = v5 - v4;
      for ( i = 0; v6 != 1; ++i )
        v6 >>= 1;
      stlp_std::priv::__introsort_loop<vostok::resources::resource_base * *,vostok::resources::resource_base *,int,vostok::resources::sorting_predicate>(
        (vostok::resources::sorting_predicate)i,
        v4,
        v5,
        0,
        2 * i,
        *(vostok::resources::resource_base ***)__comp);
      stlp_std::priv::__final_insertion_sort<vostok::resources::resource_base * *,vostok::resources::sorting_predicate>(
        __first,
        (vostok::resources::sorting_predicate)memory_type,
        v5,
        __comp[0]);
      v4 = __first;
    }
    memory_type->resources.m_first = 0;
    memory_type->resources.m_last = 0;
    for ( memory_type->resources.m_size = 0; v4 != v5; memory_type->resources.m_last = v8 )
    {
      v8 = *v4;
      ++memory_type->resources.m_size;
      v8->m_next_in_memory_type = 0;
      if ( memory_type->resources.m_first )
      {
        v8->m_prev_in_memory_type = memory_type->resources.m_last;
        memory_type->resources.m_last->m_next_in_memory_type = v8;
      }
      else
      {
        v8->m_prev_in_memory_type = 0;
        memory_type->resources.m_first = v8;
      }
      ++v4;
    }
    ++this->m_sort_actuality_tick;
  }
}
