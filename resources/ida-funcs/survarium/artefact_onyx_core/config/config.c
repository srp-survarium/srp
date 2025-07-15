void __thiscall survarium::artefact_onyx_core::config::config(
        survarium::artefact_onyx_core::config *this,
        survarium::artefact_onyx_core::config *__that,
        int a3)
{
  const vostok::fixed_string<16> *v4; // edi
  vostok::fixed_string<16> *m_buffer; // esi
  const vostok::fixed_string<16> *v6; // [esp+14h] [ebp+8h]

  qmemcpy(__that, (const void *)a3, 0x14u);
  __that->protected_body_parts.m_max_end = (vostok::fixed_string<16> *)&__that->hit_type;
  __that->protected_body_parts.m_end = (vostok::fixed_string<16> *)__that->protected_body_parts.m_buffer;
  __that->protected_body_parts.m_begin = (vostok::fixed_string<16> *)__that->protected_body_parts.m_buffer;
  v4 = *(const vostok::fixed_string<16> **)(a3 + 20);
  v6 = *(const vostok::fixed_string<16> **)(a3 + 24);
  m_buffer = (vostok::fixed_string<16> *)__that->protected_body_parts.m_buffer;
  __that->protected_body_parts.m_end = (vostok::fixed_string<16> *)&__that->protected_body_parts.m_buffer[v6 - v4];
  while ( v4 != v6 )
  {
    if ( m_buffer )
      vostok::fixed_string<16>::fixed_string<16>(m_buffer, v4);
    ++v4;
    ++m_buffer;
  }
  __that->hit_type = *(_DWORD *)(a3 + 620);
  __that->passive.damage_add = *(float *)(a3 + 624);
  __that->passive.damage_mul = *(float *)(a3 + 628);
  __that->passive.armor_piercing_add = *(float *)(a3 + 632);
  __that->passive.armor_piercing_mul = *(float *)(a3 + 636);
  qmemcpy(&__that->active, (const void *)(a3 + 640), sizeof(__that->active));
}
