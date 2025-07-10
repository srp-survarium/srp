unsigned int __userpurge vostok::render::grass_world::add_template@<eax>(
        vostok::render::grass_world *this@<ecx>,
        bool a2@<dil>,
        vostok::render::grass_world *in_render_model,
        const vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *in_render_modela)
{
  unsigned int v4; // esi
  vostok::render::grass_template *v5; // eax
  const vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *v6; // eax
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *M_finish; // ecx

  v4 = ++g_template_counter;
  v5 = (vostok::render::grass_template *)vostok::memory::doug_lea_allocator::malloc_impl(
                                           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                           0x20u);
  if ( v5 )
    vostok::render::grass_template::grass_template(v5, v4, in_render_modela);
  else
    v6 = 0;
  M_finish = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)in_render_model->m_templates._M_impl._M_finish;
  in_render_modela = v6;
  if ( M_finish == (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)in_render_model->m_templates._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
      M_finish,
      (int)&in_render_model->m_templates,
      (void **)&M_finish->_M_start,
      (void *const *)&in_render_modela,
      (const stlp_std::__true_type *)1,
      1,
      a2);
  }
  else
  {
    M_finish->_M_start = (void **)&v6->m_object;
    ++in_render_model->m_templates._M_impl._M_finish;
  }
  return v4;
}
