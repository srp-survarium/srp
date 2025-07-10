void __thiscall vostok::sound::voice_factory::~voice_factory(vostok::sound::voice_factory *this)
{
  int v2; // [esp+4h] [ebp-30h]
  vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy> *j; // [esp+8h] [ebp-2Ch]
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+27h] [ebp-Dh] BYREF
  vostok::sound::voice_bridge *object_to_be_deleted; // [esp+28h] [ebp-Ch] BYREF
  vostok::sound::voice_bridge *current_voice; // [esp+2Ch] [ebp-8h]
  unsigned int i; // [esp+30h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    current_voice = this->m_voices_pool.elems[i].m_first;
    while ( current_voice )
    {
      object_to_be_deleted = current_voice;
      current_voice = current_voice->m_next;
      call_destructor_predicate = 0;
      vostok::memory::detail::delete_helper_impl<vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>,vostok::sound::voice_bridge,vostok::memory::detail::call_destructor_predicate>(
        &this->m_voices_allocator,
        &object_to_be_deleted,
        &call_destructor_predicate);
    }
  }
  v2 = 2;
  for ( j = &this->m_voices_allocator;
        --v2 >= 0;
        j = (vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy> *)((char *)j - 16) )
  {
    ;
  }
}
