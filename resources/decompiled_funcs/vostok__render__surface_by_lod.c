vostok::render::grass_render_surface *__usercall vostok::render::surface_by_lod@<eax>(
        const unsigned int lod_index@<eax>,
        vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> mod)
{
  int v2; // eax
  vostok::render::grass_render_surface *m_l1; // esi
  vostok::resources::unmanaged_intrusive_base *v5; // eax
  bool v6; // zf

  if ( lod_index )
  {
    v2 = lod_index - 1;
    if ( !v2 )
    {
      m_l1 = mod.m_object->m_l1;
      if ( !m_l1 )
        m_l1 = mod.m_object->m_l0;
      v6 = _InterlockedExchangeAdd(&mod.m_object->m_reference_count, 0xFFFFFFFF) == 0;
      goto LABEL_18;
    }
    if ( v2 != 1 )
    {
      if ( mod.m_object )
      {
        if ( !_InterlockedExchangeAdd(&mod.m_object->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(
            &mod.m_object->vostok::resources::unmanaged_intrusive_base,
            mod.m_object);
      }
      return 0;
    }
    if ( mod.m_object->m_l2 )
    {
      m_l1 = mod.m_object->m_l2;
      v5 = &mod.m_object->vostok::resources::unmanaged_intrusive_base;
    }
    else
    {
      m_l1 = mod.m_object->m_l1;
      if ( !m_l1 )
        m_l1 = mod.m_object->m_l0;
      v5 = &mod.m_object->vostok::resources::unmanaged_intrusive_base;
    }
  }
  else
  {
    m_l1 = mod.m_object->m_l0;
    v5 = &mod.m_object->vostok::resources::unmanaged_intrusive_base;
  }
  v6 = _InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) == 0;
LABEL_18:
  if ( v6 )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &mod.m_object->vostok::resources::unmanaged_intrusive_base,
      mod.m_object);
  return m_l1;
}
