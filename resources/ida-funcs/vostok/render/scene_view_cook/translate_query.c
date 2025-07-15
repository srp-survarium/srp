void __thiscall vostok::render::scene_view_cook::translate_query(
        vostok::render::scene_view_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  int *v2; // eax
  vostok::render::scene_view *v3; // ecx
  vostok::configs::binary_config *v4; // eax
  vostok::configs::binary_config *v5; // esi
  void **M_finish; // eax
  vostok::render::vector<vostok::render::scene_view *> *p_m_views; // edi
  vostok::resources::query_result_for_cook *v8; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp-Ch] [ebp-1Ch] BYREF
  const vostok::resources::memory_type *v10; // [esp-8h] [ebp-18h]
  unsigned int v11; // [esp-4h] [ebp-14h]
  bool v12; // [esp+0h] [ebp-10h]
  vostok::configs::binary_config *__x; // [esp+Ch] [ebp-4h] BYREF

  __x = 0;
  v2 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x5E0u);
  if ( v2 )
  {
    vostok::render::scene_view::scene_view(v3, (int)v2);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  M_finish = vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_views._M_impl._M_finish;
  p_m_views = &vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_views;
  __x = v5;
  if ( M_finish == vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_views._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)&__x,
      (int)p_m_views,
      M_finish,
      (void *const *)&__x,
      (const stlp_std::__true_type *)1,
      1,
      v12);
  }
  else
  {
    *M_finish = v5;
    ++p_m_views->_M_impl._M_finish;
  }
  v11 = 1504;
  v10 = &vostok::resources::nocache_memory;
  v9.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v9,
    v5);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    parent,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v9.m_object,
    v10,
    v11);
  vostok::resources::query_result_for_cook::finish_query_impl(v8, (int)parent, result_success, assert_on_fail_true, 0);
}
