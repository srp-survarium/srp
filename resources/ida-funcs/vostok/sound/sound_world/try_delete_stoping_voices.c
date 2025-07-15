void __thiscall vostok::sound::sound_world::try_delete_stoping_voices(vostok::sound::sound_world *this)
{
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+1Fh] [ebp-39h] BYREF
  vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy> *allocator; // [esp+20h] [ebp-38h]
  char v4; // [esp+27h] [ebp-31h]
  vostok::sound::sound_voice *m_first; // [esp+4Ch] [ebp-Ch]
  vostok::sound::sound_voice *next; // [esp+50h] [ebp-8h]
  vostok::sound::sound_voice *voice; // [esp+54h] [ebp-4h] BYREF

  m_first = this->m_voices_to_delete.m_first;
  for ( voice = m_first; voice; voice = next )
  {
    next = voice->m_next_for_delete;
    if ( vostok::sound::sound_voice::can_be_deleted(voice) )
    {
      vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
        &this->m_voices_to_delete,
        voice);
      v4 = 0;
      allocator = this->m_sound_voices_allocator.m_variable;
      call_destructor_predicate = 0;
      vostok::memory::detail::delete_helper_impl<vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>,vostok::sound::sound_voice,vostok::memory::detail::call_destructor_predicate>(
        allocator,
        &voice,
        &call_destructor_predicate);
    }
  }
}
