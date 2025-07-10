bool __usercall vostok::render::utils::calc_lists_diff_range<vostok::render::res_texture_list>@<al>(
        const vostok::render::res_texture_list *first@<ecx>,
        unsigned int *min@<eax>,
        const vostok::render::res_texture_list *second,
        unsigned int *max)
{
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *M_start; // edx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *M_finish; // ebx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v7; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v9; // eax
  unsigned int v10; // eax
  bool v11; // dl
  int v13; // esi
  unsigned int v14; // edi

  M_start = second->m_container._M_impl._M_start;
  M_finish = second->m_container._M_impl._M_finish;
  v7 = first->m_container._M_impl._M_finish;
  v9 = first->m_container._M_impl._M_start;
  *max = 0;
  for ( *min = 0; v9 != v7; ++M_start )
  {
    if ( M_start == M_finish )
      break;
    if ( v9->m_object != M_finish->m_object )
      break;
    ++*min;
    ++v9;
  }
  if ( ((((char *)v7 - (char *)first->m_container._M_impl._M_start)
       ^ ((char *)second->m_container._M_impl._M_finish - (char *)second->m_container._M_impl._M_start))
      & 0xFFFFFFFC) != 0 )
  {
    v10 = vostok::math::max(
            first->m_container._M_impl._M_finish - first->m_container._M_impl._M_start,
            second->m_container._M_impl._M_finish - second->m_container._M_impl._M_start);
    v11 = *min != v10;
    *max = v10;
    return v11;
  }
  else
  {
    v13 = *min;
    if ( v9 != v7 )
    {
      v14 = v13 + 1;
      do
      {
        if ( M_start == M_finish )
          break;
        if ( v9->m_object != M_finish->m_object )
          *max = v14;
        ++v9;
        ++M_start;
        ++v14;
      }
      while ( v9 != v7 );
    }
    return v13 != *max;
  }
}
