bool __usercall vostok::render::has_surface_by_lod@<al>(
        const unsigned int lod_index@<eax>,
        vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> mod)
{
  int v2; // eax
  vostok::render::grass_render_model *m_object; // eax
  bool v5; // zf
  bool v6; // bl
  bool v7; // zf

  if ( !lod_index )
  {
    m_object = mod.m_object;
    v5 = mod.m_object->m_l0 == 0;
LABEL_11:
    v6 = !v5;
    v7 = _InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) == 0;
    goto LABEL_12;
  }
  v2 = lod_index - 1;
  if ( v2 )
  {
    v5 = v2 == 1;
    m_object = mod.m_object;
    if ( !v5 )
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
    v5 = mod.m_object->m_l2 == 0;
    goto LABEL_11;
  }
  v6 = mod.m_object->m_l1 != 0;
  v7 = _InterlockedExchangeAdd(&mod.m_object->m_reference_count, 0xFFFFFFFF) == 0;
LABEL_12:
  if ( v7 )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &mod.m_object->vostok::resources::unmanaged_intrusive_base,
      mod.m_object);
  return v6;
}
