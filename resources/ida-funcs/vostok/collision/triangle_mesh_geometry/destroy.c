void __thiscall vostok::collision::triangle_mesh_geometry::destroy(
        vostok::collision::triangle_mesh_geometry *this,
        vostok::memory::base_allocator *allocator)
{
  Opcode::MeshInterface *m_mesh; // eax
  _BYTE *v5; // [esp+14h] [ebp+4h]

  if ( this->m_model )
  {
    v5 = __RTCastToVoid((void **)&this->m_model->__vftable);
    ((void (__thiscall *)(Opcode::Model *, _DWORD))this->m_model->~Opcode::Model)(this->m_model, 0);
    allocator->call_free(
      allocator,
      v5,
      "vostok::collision::triangle_mesh_geometry::destroy",
      ".\\triangle_mesh_geometry.cpp",
      74u);
    this->m_model = 0;
  }
  m_mesh = this->m_mesh;
  if ( m_mesh )
  {
    allocator->call_free(
      allocator,
      m_mesh,
      "vostok::collision::triangle_mesh_geometry::destroy",
      ".\\triangle_mesh_geometry.cpp",
      75u);
    this->m_mesh = 0;
  }
}
