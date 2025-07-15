void __userpurge vostok::resources::sorting_functionality::sort_resources_if_needed(
        vostok::resources::memory_type *memory_type@<eax>,
        vostok::resources::sorting_functionality *this)
{
  vostok::intrusive_double_linked_list<vostok::resources::resource_base,vostok::resources::resource_base *,156,152,vostok::threading::single_threading_policy,vostok::size_policy,vostok::debug_policy> *p_resources; // ebx
  unsigned int m_size; // edi
  void *v4; // esp
  vostok::resources::resource_base *m_first; // esi
  const char **v6; // edi
  int v7; // eax
  int v8; // esi
  int i; // ecx
  vostok::resources::resource_base **v10; // esi
  vostok::resources::resource_base **v11; // esi
  unsigned __int64 v12; // [esp-8h] [ebp-2Ch]
  const char *v13[4]; // [esp+0h] [ebp-24h] BYREF
  vostok::resources::resource_base **__last; // [esp+10h] [ebp-14h]
  vostok::resources::sorting_predicate __comp[4]; // [esp+18h] [ebp-Ch] BYREF
  vostok::resources::resource_base **__first; // [esp+1Ch] [ebp-8h]
  bool do_debug_break; // [esp+20h] [ebp-4h] BYREF

  if ( LODWORD(memory_type->sort_actuality_tick) != LODWORD(this->m_sort_actuality_tick)
    || HIDWORD(memory_type->sort_actuality_tick) != HIDWORD(this->m_sort_actuality_tick) )
  {
    p_resources = &memory_type->resources;
    m_size = memory_type->resources.m_size;
    v4 = alloca(m_size * 4);
    m_first = memory_type->resources.m_first;
    __first = (vostok::resources::resource_base **)v13;
    __last = (vostok::resources::resource_base **)v13;
    v6 = &v13[m_size];
    while ( m_first )
    {
      if ( __last >= (vostok::resources::resource_base **)v6
        && !`vostok::buffer_vector<vostok::resources::resource_base *>::push_back'::`11'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::resources::resource_base *>::push_back",
          (const char *)0x12E,
          "buffer overflow",
          v13[0]);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
      if ( __last )
        *__last = m_first;
      HIDWORD(v12) = HIDWORD(this->m_sort_actuality_tick);
      ++__last;
      LODWORD(v12) = this->m_sort_actuality_tick;
      vostok::resources::resource_reconstruction_info::update_reconstruction_info(
        &m_first->vostok::resources::resource_reconstruction_info,
        v12);
      m_first = m_first->m_next_in_memory_type;
    }
    v7 = 0;
    __comp[0] = 0;
    if ( __first != __last )
    {
      v8 = __last - __first;
      for ( i = v8; i != 1; i >>= 1 )
        ++v7;
      stlp_std::priv::__introsort_loop<vostok::resources::resource_base * *,vostok::resources::resource_base *,int,vostok::resources::sorting_predicate>(
        &__comp[1],
        __first,
        __last,
        0,
        2 * v7,
        *(vostok::resources::resource_base ***)__comp);
      if ( v8 <= 16 )
      {
        do_debug_break = (bool)__comp[0];
        stlp_std::priv::__insertion_sort<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
          __first,
          (vostok::resources::sorting_predicate *)p_resources,
          __last,
          (vostok::resources::sorting_predicate *)&do_debug_break);
      }
      else
      {
        v10 = __first + 16;
        stlp_std::priv::__insertion_sort<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
          __first,
          (vostok::resources::sorting_predicate *)p_resources,
          __first + 16,
          __comp);
        while ( v10 != __last )
        {
          stlp_std::priv::__unguarded_linear_insert<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
            v10,
            *v10);
          ++v10;
        }
      }
    }
    v11 = __first;
    p_resources->m_first = 0;
    p_resources->m_last = 0;
    p_resources->m_size = 0;
    while ( v11 != __last )
      vostok::intrusive_double_linked_list<vostok::resources::resource_base,vostok::resources::resource_base *,156,152,vostok::threading::single_threading_policy,vostok::size_policy,vostok::debug_policy>::push_back(
        (vostok::intrusive_double_linked_list<vostok::resources::resource_base,vostok::resources::resource_base *,156,152,vostok::threading::single_threading_policy,vostok::size_policy,vostok::debug_policy> *)*v11++,
        p_resources);
    ++this->m_sort_actuality_tick;
  }
}
