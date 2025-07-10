void __usercall vostok::render::scene::remove_clouds(vostok::render::scene *this@<ecx>, int a2@<eax>)
{
  _DWORD *v2; // esi

  v2 = (_DWORD *)(a2 + 960);
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::clouds,vostok::memory::detail::call_destructor_predicate>(
    (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
    (vostok::render::clouds **)(a2 + 960));
  *v2 = 0;
}
