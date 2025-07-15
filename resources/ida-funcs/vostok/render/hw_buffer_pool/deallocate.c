void __usercall vostok::render::hw_buffer_pool::deallocate(const vostok::render::hw_buffer_pool_range *in_range@<eax>)
{
  vostok::render::hw_buffer_pool_chunk *owner; // esi
  vostok::render::hw_buffer_pool_range *m_end; // edi
  vostok::render::hw_buffer_pool_range __val; // [esp+8h] [ebp-10h] BYREF
  vostok::render::hw_buffer_pool_range *where; // [esp+14h] [ebp-4h] BYREF

  __val = *in_range;
  owner = in_range->owner;
  m_end = in_range->owner->allocations.m_end;
  where = stlp_std::priv::__find<vostok::render::hw_buffer_pool_range *,vostok::render::hw_buffer_pool_range>(
            in_range->owner->allocations.m_begin,
            m_end,
            &__val);
  if ( where != m_end )
    vostok::buffer_vector<vostok::render::hw_buffer_pool_range>::erase(&where, &owner->allocations);
}
