vostok::render::light_data *__userpurge stlp_std::priv::_Impl_vector<vostok::render::light_data,vostok::render::std_allocator<vostok::render::light_data>>::_M_erase@<eax>(
        stlp_std::priv::_Impl_vector<vostok::render::light_data,vostok::render::std_allocator<vostok::render::light_data> > *this@<ecx>,
        int a2@<eax>,
        vostok::render::light_data *__pos,
        const stlp_std::__false_type *__formal)
{
  vostok::render::light_data *v5; // edx
  _DWORD **v6; // esi
  _DWORD *v7; // eax
  _DWORD *v9; // edi
  vostok::render::grass_render_model *m_object; // esi
  const stlp_std::random_access_iterator_tag *v12; // [esp+0h] [ebp-10h]
  int *v13; // [esp+4h] [ebp-Ch]

  v5 = *(vostok::render::light_data **)(a2 + 4);
  if ( &__pos[1] != v5 )
    stlp_std::priv::__copy<vostok::render::light_data *,vostok::render::light_data *,int>(
      __pos + 1,
      v5,
      __pos,
      v12,
      v13);
  *(_DWORD *)(a2 + 4) -= 8;
  v6 = *(_DWORD ***)(a2 + 4);
  v7 = *v6;
  if ( *v6 )
  {
    if ( (*v7)-- == 1 )
    {
      v9 = *v6;
      m_object = vostok::render::g_allocator.m_object;
      if ( v9 )
      {
        vostok::render::light::~light((vostok::render::light *)this);
        BYTE2(m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), v9);
      }
    }
  }
  return __pos;
}
