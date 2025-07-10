void __userpurge vostok::render::scene::remove_environment_probe(
        vostok::render::find_environment_probe_predicate id@<eax>,
        vostok::memory::detail::call_destructor_predicate *a2@<edi>,
        vostok::render::scene *this)
{
  void **M_finish; // esi
  vostok::render::environment_probe **environment_probe; // eax
  vostok::render::environment_probe *v5; // ecx
  void **v6; // ebp
  vostok::render::grass_render_model *m_object; // esi
  vostok::render::environment_probe *v8; // edi
  void **v9; // eax

  M_finish = this->m_environment_probes._M_impl._M_finish;
  environment_probe = stlp_std::priv::__find_if<vostok::render::environment_probe * *,vostok::render::find_environment_probe_predicate>(
                        (vostok::render::environment_probe **)this->m_environment_probes._M_impl._M_start,
                        (vostok::render::environment_probe **)M_finish,
                        id);
  v6 = (void **)environment_probe;
  if ( environment_probe != (vostok::render::environment_probe **)M_finish )
  {
    m_object = vostok::render::g_allocator.m_object;
    v8 = *environment_probe;
    if ( *environment_probe )
    {
      vostok::memory::detail::call_destructor_predicate::operator()<vostok::render::environment_probe>(v8, v5, a2);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), v8);
    }
    v9 = this->m_environment_probes._M_impl._M_finish;
    if ( v6 + 1 != v9 )
      stlp_std::priv::__copy_ptrs<void * *,void * *>(v6 + 1, v9, v6);
    --this->m_environment_probes._M_impl._M_finish;
  }
}
