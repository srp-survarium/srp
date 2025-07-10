void __usercall vostok::resources::cook_base::call_destroy_resource(
        vostok::resources::cook_base *this@<esi>,
        const vostok::resources::query_result_for_cook *resource@<edi>)
{
  unsigned int m_flags; // eax
  vostok::resources::cook_base *v3; // ecx

  _InterlockedExchangeAdd((volatile signed __int32 *)&resource->m_unmanaged_resource, 1u);
  vostok::threading::interlocked_or((volatile int *)&resource->m_save_generated_data, 8u);
  m_flags = this->m_flags.m_flags;
  if ( (m_flags & 0x20) == 0x20
    && ((m_flags & 0x10) != 0 && (m_flags & 8) == 0 || (this->m_flags.m_flags & 0x20) == 0x20 && (m_flags & 0x18) == 0) )
  {
    ((void (__thiscall *)(vostok::resources::cook_base *, const vostok::resources::query_result_for_cook *))this->__vftable[1].cache_by_game_resources_manager)(
      this,
      resource);
  }
  else
  {
    v3 = (m_flags & 8) != 8 ? 0 : this;
    v3->__vftable[1].calculate_quality_levels_count(v3, resource);
  }
}
