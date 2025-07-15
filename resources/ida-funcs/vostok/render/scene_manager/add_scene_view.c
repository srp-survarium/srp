void __userpurge vostok::render::scene_manager::add_scene_view(
        vostok::render::scene_manager *this@<ecx>,
        int a2@<eax>,
        vostok::render::scene_view *in_scene_view)
{
  void **v4; // eax
  int v5; // edi
  bool v6; // [esp+0h] [ebp-4h]

  v4 = *(void ***)(a2 + 16);
  v5 = a2 + 12;
  if ( v4 == *(void ***)(v5 + 8) )
  {
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
      &this->m_scenes._M_impl,
      v5,
      v4,
      (void *const *)&in_scene_view,
      (const stlp_std::__true_type *)1,
      1,
      v6);
  }
  else
  {
    *v4 = in_scene_view;
    *(_DWORD *)(v5 + 4) += 4;
  }
}
