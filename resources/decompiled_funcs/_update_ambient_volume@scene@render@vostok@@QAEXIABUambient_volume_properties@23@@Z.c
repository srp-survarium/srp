void __userpurge vostok::render::scene::update_ambient_volume(
        vostok::render::scene *this@<ecx>,
        int a2@<eax>,
        unsigned int id,
        const vostok::render::ambient_volume_properties *properties)
{
  const vostok::render::ambient_volume_properties *v4; // ebp
  vostok::render::ambient_volume **v5; // esi
  int v6; // edi
  vostok::render::ambient_volume **v7; // eax
  vostok::render::ambient_volume *v8; // eax
  const vostok::render::ambient_volume_properties *v9; // eax
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v10; // ecx
  bool v11; // [esp+0h] [ebp-14h]

  v4 = properties;
  v5 = *(vostok::render::ambient_volume ***)(a2 + 868);
  v6 = a2 + 864;
  v7 = stlp_std::priv::__find_if<vostok::render::ambient_volume * *,vostok::render::find_by_id_predicate<vostok::render::ambient_volume>>(
         *(vostok::render::ambient_volume ***)(a2 + 864),
         v5,
         (vostok::render::find_by_id_predicate<vostok::render::ambient_volume>)id);
  if ( v7 == v5 )
  {
    v8 = (vostok::render::ambient_volume *)vostok::memory::doug_lea_allocator::malloc_impl(
                                             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                             0x70u);
    if ( v8 )
      vostok::render::ambient_volume::ambient_volume(v8, v4, id);
    else
      v9 = 0;
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
      v10->_M_start = (void **)v9;
      *(_DWORD *)(v6 + 4) += 4;
    }
  }
  else
  {
    vostok::render::ambient_volume::set_properties(*v7, v4);
  }
}
