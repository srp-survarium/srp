void __thiscall vostok::collision::triangle_mesh_geometry::destroy(
        vostok::collision::triangle_mesh_geometry *this,
        vostok::memory::base_allocator *allocator)
{
  Opcode::Model *m_model; // eax
  _BYTE *v4; // ebx

  m_model = this->m_model;
  if ( m_model )
  {
    v4 = __RTCastToVoid((void **)&m_model->__vftable);
    ((void (__thiscall *)(Opcode::Model *, _DWORD))this->m_model->~Opcode::Model)(this->m_model, 0);
    allocator->call_free(allocator, v4);
    this->m_model = 0;
  }
  if ( this->m_mesh )
  {
    allocator->call_free(allocator, this->m_mesh);
    this->m_mesh = 0;
  }
}
