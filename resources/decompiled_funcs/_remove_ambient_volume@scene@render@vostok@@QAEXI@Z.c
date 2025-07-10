void __userpurge vostok::render::scene::remove_ambient_volume(
        vostok::render::find_by_id_predicate<vostok::render::ambient_volume> id@<eax>,
        vostok::render::scene *this)
{
  void **M_finish; // esi
  vostok::render::ambient_volume **v3; // eax
  void **v4; // edi
  vostok::render::ambient_volume *v5; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void **v7; // eax

  M_finish = this->m_ambient_volumes._M_impl._M_finish;
  v3 = stlp_std::priv::__find_if<vostok::render::ambient_volume * *,vostok::render::find_by_id_predicate<vostok::render::ambient_volume>>(
         (vostok::render::ambient_volume **)this->m_ambient_volumes._M_impl._M_start,
         (vostok::render::ambient_volume **)M_finish,
         id);
  v4 = (void **)v3;
  if ( v3 != (vostok::render::ambient_volume **)M_finish )
  {
    v5 = *v3;
    if ( *v4 )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v5);
    }
    v7 = this->m_ambient_volumes._M_impl._M_finish;
    if ( v4 + 1 != v7 )
      stlp_std::priv::__copy_ptrs<void * *,void * *>(v4 + 1, v7, v4);
    --this->m_ambient_volumes._M_impl._M_finish;
  }
}
