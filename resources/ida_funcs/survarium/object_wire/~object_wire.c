void __thiscall survarium::object_wire::~object_wire(survarium::object_wire *this)
{
  char *m_points; // eax
  malloc_state *v3; // esi
  vostok::render::render_model_instance *m_object; // eax

  this->__vftable = (survarium::object_wire_vtbl *)&survarium::object_wire::`vftable';
  m_points = (char *)this->m_points;
  if ( m_points )
  {
    v3 = *(malloc_state **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v3, m_points);
    this->m_points = 0;
  }
  m_object = this->m_visual.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_visual.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_visual.m_object);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
