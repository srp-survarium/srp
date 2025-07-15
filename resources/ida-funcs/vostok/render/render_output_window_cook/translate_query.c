void __thiscall vostok::render::render_output_window_cook::translate_query(
        vostok::render::render_output_window_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::variant<32> *m_user_data; // esi
  int *v3; // eax
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v4; // ecx
  vostok::configs::binary_config *v5; // eax
  vostok::configs::binary_config *v6; // esi
  void **M_finish; // eax
  vostok::render::vector<vostok::render::render_output_window *> *p_m_output_windows; // edi
  vostok::resources::query_result_for_cook *v9; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp-Ch] [ebp-34h] BYREF
  const vostok::resources::memory_type *v11; // [esp-8h] [ebp-30h]
  unsigned int v12; // [esp-4h] [ebp-2Ch]
  bool v13; // [esp+0h] [ebp-28h]
  void *__x; // [esp+10h] [ebp-18h] BYREF
  vostok::render::output_window_configuration window_configuration; // [esp+14h] [ebp-14h] BYREF

  __x = 0;
  m_user_data = parent->m_user_data;
  memset(&window_configuration, 0, 13);
  window_configuration.windowed = 1;
  window_configuration.scaleform_render_queue = 0;
  vostok::variant<32>::try_get<vostok::render::output_window_configuration>(
    m_user_data,
    &window_configuration,
    (int)this);
  v3 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x2CF0u);
  if ( v3 )
  {
    vostok::render::render_output_window::render_output_window(
      (vostok::render::render_output_window *)&window_configuration,
      (vostok::render::render_output_window *)v3,
      &window_configuration);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  M_finish = vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_output_windows._M_impl._M_finish;
  p_m_output_windows = &vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_output_windows;
  __x = v6;
  if ( M_finish == vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_output_windows._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
      v4,
      (int)p_m_output_windows,
      M_finish,
      &__x,
      (const stlp_std::__true_type *)1,
      1,
      v13);
  }
  else
  {
    *M_finish = v6;
    ++p_m_output_windows->_M_impl._M_finish;
  }
  v12 = 11504;
  v11 = &vostok::resources::nocache_memory;
  v10.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v10,
    v6);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    parent,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v10.m_object,
    v11,
    v12);
  vostok::resources::query_result_for_cook::finish_query_impl(v9, (int)parent, result_success, assert_on_fail_true, 0);
}
