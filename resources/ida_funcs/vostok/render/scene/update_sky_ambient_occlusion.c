void __userpurge vostok::render::scene::update_sky_ambient_occlusion(
        vostok::render::scene *this@<ecx>,
        int a2@<eax>,
        unsigned int id,
        const vostok::render::sky_ambient_occlusion_properties *properties)
{
  const vostok::render::sky_ambient_occlusion_properties *v4; // ebp
  vostok::render::sky_ambient_occlusion **v5; // esi
  int v6; // edi
  vostok::render::sky_ambient_occlusion **v7; // eax
  vostok::render::sky_ambient_occlusion *v8; // ecx
  const vostok::render::sky_ambient_occlusion_properties *v9; // eax
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v10; // ecx
  bool v11; // [esp+0h] [ebp-14h]

  v4 = properties;
  v5 = *(vostok::render::sky_ambient_occlusion ***)(a2 + 856);
  v6 = a2 + 852;
  v7 = stlp_std::priv::__find_if<vostok::render::sky_ambient_occlusion * *,vostok::render::find_by_id_predicate<vostok::render::sky_ambient_occlusion>>(
         *(vostok::render::sky_ambient_occlusion ***)(a2 + 852),
         v5,
         (vostok::render::find_by_id_predicate<vostok::render::sky_ambient_occlusion>)id);
  if ( v7 == v5 )
  {
    if ( vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           0x158u) )
    {
      vostok::render::sky_ambient_occlusion::sky_ambient_occlusion(v8, v4, id);
    }
    else
    {
      v9 = 0;
    }
    v10 = *(stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > **)(v6 + 4);
    properties = v9;
    if ( v10 == *(stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > **)(v6 + 8) )
    {
      stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
        v10,
        v6,
        (void **)&v10->_M_start,
        (void *const *)&properties,
        (const stlp_std::__true_type *)1,
        1,
        v11);
    }
    else
    {
      v10->_M_start = (void **)&v9->texture_name.m_begin;
      *(_DWORD *)(v6 + 4) += 4;
    }
  }
  else
  {
    vostok::render::sky_ambient_occlusion::set_properties(*v7, v4);
  }
}
