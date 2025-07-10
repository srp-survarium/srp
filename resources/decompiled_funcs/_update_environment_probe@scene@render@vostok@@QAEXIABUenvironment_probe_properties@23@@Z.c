void __thiscall vostok::render::scene::update_environment_probe(
        vostok::render::scene *this,
        vostok::render::scene *id,
        const vostok::render::environment_probe_properties *properties,
        const vostok::render::environment_probe_properties *propertiesa)
{
  vostok::render::environment_probe **M_finish; // esi
  vostok::render::environment_probe **environment_probe; // eax
  const vostok::render::environment_probe_properties *v6; // eax
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v7; // ecx
  bool v8; // [esp+0h] [ebp-10h]

  M_finish = (vostok::render::environment_probe **)id->m_environment_probes._M_impl._M_finish;
  environment_probe = stlp_std::priv::__find_if<vostok::render::environment_probe * *,vostok::render::find_environment_probe_predicate>(
                        (vostok::render::environment_probe **)id->m_environment_probes._M_impl._M_start,
                        M_finish,
                        (vostok::render::find_environment_probe_predicate)properties);
  if ( environment_probe == M_finish )
  {
    if ( vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           0x1B8u) )
    {
      vostok::render::environment_probe::environment_probe(
        (vostok::render::environment_probe *)propertiesa,
        id->m_environment_probes_tree,
        propertiesa,
        (const unsigned int)properties);
    }
    else
    {
      v6 = 0;
    }
    v7 = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)id->m_environment_probes._M_impl._M_finish;
    propertiesa = v6;
    if ( v7 == (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)id->m_environment_probes._M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
        v7,
        (int)&id->m_environment_probes,
        (void **)&v7->_M_start,
        (void *const *)&propertiesa,
        (const stlp_std::__true_type *)1,
        1,
        v8);
    }
    else
    {
      v7->_M_start = (void **)&v6->texture_name.m_begin;
      ++id->m_environment_probes._M_impl._M_finish;
    }
  }
  else
  {
    vostok::render::environment_probe::set_properties(
      (vostok::render::environment_probe *)propertiesa,
      (const vostok::render::environment_probe_properties *)*environment_probe);
  }
}
