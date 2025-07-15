void __thiscall vostok::render::render_output_window_cook::delete_resource(
        vostok::render::render_output_window_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::resources::resource_base *v2; // esi
  void **M_finish; // eax
  vostok::render::vector<vostok::render::render_output_window *> *p_m_output_windows; // edi
  vostok::render::grass_render_model *m_object; // ebx
  char *v6; // edi
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  bool v8; // [esp+0h] [ebp-Ch]

  v2 = resource;
  M_finish = vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_output_windows._M_impl._M_finish;
  p_m_output_windows = &vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_output_windows;
  if ( M_finish == vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_output_windows._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)&resource,
      (int)p_m_output_windows,
      M_finish,
      (void *const *)&resource,
      (const stlp_std::__true_type *)1,
      1,
      v8);
  }
  else
  {
    *M_finish = resource;
    ++p_m_output_windows->_M_impl._M_finish;
  }
  m_object = vostok::render::g_allocator.m_object;
  if ( v2 )
  {
    v6 = __RTCastToVoid((void **)&v2->__vftable);
    ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))v2->~vostok::resources::resource_base)(v2, 0);
    if ( v6 )
    {
      m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
    }
  }
}
