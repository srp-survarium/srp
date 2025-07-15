void __thiscall vostok::render::shader_constant_table::shader_constant_table(
        vostok::render::shader_constant_table *this,
        vostok::render::shader_constant *other,
        vostok::render::shader_constant_buffer *a3)
{
  vostok::render::shader_constant *v3; // ebx
  vostok::render::shader_constant_buffer *v4; // eax

  v3 = other;
  *(_DWORD *)&other->m_slot.m_class_id = 0;
  HIDWORD(v3->m_slot.m_value) = &v3->m_host;
  v3->m_source.m_pointer = &v3->m_host;
  v3->m_source.m_size = (const unsigned int)&v3[32].m_host;
  other = (vostok::render::shader_constant *)a3->m_name.m_end;
  vostok::buffer_vector<vostok::render::shader_constant>::assign<vostok::render::shader_constant const *>(
    (vostok::buffer_vector<vostok::render::shader_constant> *)((char *)&v3->m_slot.m_value + 4),
    (const vostok::render::shader_constant *)a3->m_name.m_begin,
    (const vostok::render::shader_constant *const *)&other);
  v3[32].m_host = (const vostok::render::shader_constant_host *)((char *)&v3[33].m_slot.m_value + 4);
  *((_DWORD *)&v3[32].m_host + 1) = (char *)v3 + 796;
  *(_DWORD *)&v3[33].m_slot.m_class_id = (char *)v3 + 924;
  v4 = *(vostok::render::shader_constant_buffer **)&a3[7].m_name.m_buffer[40];
  a3 = *(vostok::render::shader_constant_buffer **)&a3[7].m_name.m_buffer[44];
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::assign<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> const *>(
    (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)&v3[32].m_host,
    (const vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v4,
    (const vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *const *)&a3);
  LOBYTE(v3[38].m_source.m_size) = 0;
}


void __usercall vostok::render::shader_constant_table::shader_constant_table(
        vostok::render::shader_constant_table *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = a2 + 16;
  *(_DWORD *)(a2 + 8) = a2 + 16;
  *(_DWORD *)(a2 + 12) = a2 + 784;
  *(_DWORD *)(a2 + 784) = a2 + 796;
  *(_DWORD *)(a2 + 788) = a2 + 796;
  *(_DWORD *)(a2 + 792) = a2 + 924;
  *(_BYTE *)(a2 + 924) = 0;
}
