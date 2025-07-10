void __thiscall vostok::render::engine::world::set_model_lod_params(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *v,
        int type,
        int use_default,
        float p0,
        float p1,
        float p2)
{
  vostok::render::render_model_instance *m_object; // esi

  m_object = 0;
  if ( v->m_object )
  {
    m_object = v->m_object;
    _InterlockedExchangeAdd(&v->m_object->m_reference_count, 1u);
  }
  ((void (__thiscall *)(vostok::render::render_model_instance *, int, int, _DWORD, _DWORD, _DWORD))m_object->set_lod_params)(
    m_object,
    type,
    use_default,
    LODWORD(p0),
    LODWORD(p1),
    LODWORD(p2));
  if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
}
