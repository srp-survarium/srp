void __usercall vostok::render::geometry_batch::geometry_batch(
        vostok::render::geometry_batch *this@<ecx>,
        int a2@<eax>)
{
  vostok::render::material_effects_instance *m_object; // edx
  vostok::render::res_geometry *v3; // edx

  *(_QWORD *)a2 = *(_QWORD *)&this->bbox.min.x;
  *(_QWORD *)(a2 + 8) = *(_QWORD *)&this->bbox.min.elements[2];
  *(_QWORD *)(a2 + 16) = *(_QWORD *)&this->bbox.max.elements[1];
  *(_DWORD *)(a2 + 24) = 0;
  m_object = this->mtl.m_object;
  if ( m_object )
  {
    *(_DWORD *)(a2 + 24) = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 28) = 0;
  v3 = this->geometry.m_object;
  if ( v3 )
  {
    *(_DWORD *)(a2 + 28) = v3;
    ++v3->m_reference_count;
  }
  *(_DWORD *)(a2 + 32) = this->num_indices;
}
