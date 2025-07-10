void __userpurge vostok::render::shader_constant_host::shader_constant_host(
        vostok::render::shader_constant_host *this@<ecx>,
        int a2@<esi>,
        const vostok::shared_string *name,
        vostok::render::enum_constant_type type)
{
  vostok::strings::shared::profile *m_object; // eax

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  `vector constructor iterator'(
    (char *)(a2 + 8),
    8u,
    3,
    (void *(__thiscall *)(void *))vostok::render::shader_constant_slot::shader_constant_slot);
  *(_DWORD *)(a2 + 32) = 0;
  m_object = name->m_pointer.m_object;
  if ( name->m_pointer.m_object )
  {
    *(_DWORD *)(a2 + 32) = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 48) = type;
  *(_QWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 44) = 0;
}
