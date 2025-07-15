void __thiscall survarium::artefact_lifebone_core::config::config(
        survarium::artefact_lifebone_core::config *this,
        survarium::artefact_lifebone_core::config *__that,
        int a3)
{
  int v4; // ecx
  const vostok::fixed_string<16> *v5; // edx
  const vostok::fixed_string<16> *v6; // edi
  vostok::fixed_string<16> *i; // esi
  const vostok::fixed_string<16> *v8; // [esp+18h] [ebp+8h]

  qmemcpy(__that, (const void *)a3, 0x14u);
  stlp_std::priv::_Impl_vector<survarium::artefact_lifebone_core::regeneration_modifier,survarium::std_allocator<survarium::artefact_lifebone_core::regeneration_modifier>>::_Impl_vector<survarium::artefact_lifebone_core::regeneration_modifier,survarium::std_allocator<survarium::artefact_lifebone_core::regeneration_modifier>>(
    &__that->passive.regeneration_modifiers._M_impl,
    (const stlp_std::priv::_Impl_vector<survarium::artefact_lifebone_core::regeneration_modifier,survarium::std_allocator<survarium::artefact_lifebone_core::regeneration_modifier> > *)(a3 + 20));
  __that->active.removed_affects.m_max_end = (survarium::artefact_lifebone_core::removed_affect *)&__that->active.duration_ms;
  v4 = a3;
  __that->active.removed_affects.m_end = (survarium::artefact_lifebone_core::removed_affect *)__that->active.removed_affects.m_buffer;
  __that->active.removed_affects.m_begin = (survarium::artefact_lifebone_core::removed_affect *)__that->active.removed_affects.m_buffer;
  v5 = *(const vostok::fixed_string<16> **)(a3 + 36);
  v6 = *(const vostok::fixed_string<16> **)(a3 + 32);
  __that->active.removed_affects.m_end = (survarium::artefact_lifebone_core::removed_affect *)&__that->active.removed_affects.m_buffer[((char *)v5 - (char *)v6) >> 5];
  v8 = v5;
  for ( i = (vostok::fixed_string<16> *)__that->active.removed_affects.m_buffer;
        v6 != v8;
        i = (vostok::fixed_string<16> *)((char *)i + 32) )
  {
    if ( i )
    {
      vostok::fixed_string<16>::fixed_string<16>(i, v6);
      v4 = a3;
      i[1].m_begin = v6[1].m_begin;
    }
    v6 = (const vostok::fixed_string<16> *)((char *)v6 + 32);
  }
  __that->active.duration_ms = *(_DWORD *)(v4 + 332);
}
