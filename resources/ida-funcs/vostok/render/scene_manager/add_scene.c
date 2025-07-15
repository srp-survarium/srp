void __userpurge vostok::render::scene_manager::add_scene(
        vostok::render::scene_manager *this@<ecx>,
        int a2@<eax>,
        vostok::render::scene *in_scene)
{
  void **v4; // eax
  bool v5; // [esp+0h] [ebp-4h]

  v4 = *(void ***)(a2 + 4);
  if ( v4 == *(void ***)(a2 + 8) )
  {
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
      &this->m_scenes._M_impl,
      a2,
      v4,
      (void *const *)&in_scene,
      (const stlp_std::__true_type *)1,
      1,
      v5);
  }
  else
  {
    *v4 = in_scene;
    *(_DWORD *)(a2 + 4) += 4;
  }
}
