void __userpurge vostok::render::scene_manager::add_render_output_window(
        vostok::render::scene_manager *this@<ecx>,
        int a2@<eax>,
        vostok::render::render_output_window *in_output_window)
{
  void **v4; // eax
  int v5; // edi
  bool v6; // [esp+0h] [ebp-4h]

  v4 = *(void ***)(a2 + 28);
  v5 = a2 + 24;
  if ( v4 == *(void ***)(v5 + 8) )
  {
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
      &this->m_scenes._M_impl,
      v5,
      v4,
      (void *const *)&in_output_window,
      (const stlp_std::__true_type *)1,
      1,
      v6);
  }
  else
  {
    *v4 = in_output_window;
    *(_DWORD *)(v5 + 4) += 4;
  }
}
