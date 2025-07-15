void __userpurge vostok::render::scene::remove_sky_ambient_occlusion(
        vostok::render::find_by_id_predicate<vostok::render::sky_ambient_occlusion> id@<eax>,
        vostok::render::scene *this)
{
  vostok::render::scene *v2; // ebx
  void **M_finish; // esi
  vostok::render::sky_ambient_occlusion **v4; // edi
  void **v5; // eax

  v2 = this;
  M_finish = this->m_sky_ao_volumes._M_impl._M_finish;
  v4 = stlp_std::priv::__find_if<vostok::render::sky_ambient_occlusion * *,vostok::render::find_by_id_predicate<vostok::render::sky_ambient_occlusion>>(
         (vostok::render::sky_ambient_occlusion **)this->m_sky_ao_volumes._M_impl._M_start,
         (vostok::render::sky_ambient_occlusion **)M_finish,
         id);
  if ( v4 != (vostok::render::sky_ambient_occlusion **)M_finish )
  {
    this = (vostok::render::scene *)*v4;
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::sky_ambient_occlusion,vostok::memory::detail::call_destructor_predicate>(
      (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
      (vostok::render::sky_ambient_occlusion **)&this);
    v5 = v2->m_sky_ao_volumes._M_impl._M_finish;
    if ( v4 + 1 != (vostok::render::sky_ambient_occlusion **)v5 )
    {
      LOBYTE(this) = 0;
      stlp_std::priv::__copy_ptrs<void * *,void * *>((void **)v4 + 1, v5, (void **)v4);
    }
    --v2->m_sky_ao_volumes._M_impl._M_finish;
  }
}
