vostok::render::res_render_output *__thiscall vostok::render::resource_manager::create_render_output(
        vostok::render::resource_manager *this,
        vostok::render::resource_manager *window,
        HWND__ *windowed,
        vostok::render::res_render_output *r_output)
{
  vostok::render::res_render_output *v4; // eax
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v5; // ecx
  vostok::render::res_render_output *v6; // eax
  vostok::render::res_render_output *v7; // esi
  void **M_finish; // eax
  bool v10; // [esp+0h] [ebp-8h]

  v4 = (vostok::render::res_render_output *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              0xE8u);
  if ( v4 )
  {
    vostok::render::res_render_output::res_render_output(v4, windowed, (bool)r_output);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  v7->m_is_registered = 1;
  M_finish = window->m_render_outputs._M_impl._M_finish;
  r_output = v7;
  if ( M_finish == window->m_render_outputs._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
      v5,
      (int)&window->m_render_outputs,
      M_finish,
      (void *const *)&r_output,
      (const stlp_std::__true_type *)1,
      1,
      v10);
  }
  else
  {
    *M_finish = v7;
    ++window->m_render_outputs._M_impl._M_finish;
  }
  return v7;
}
