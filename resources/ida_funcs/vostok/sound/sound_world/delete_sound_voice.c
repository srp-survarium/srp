void __thiscall vostok::sound::sound_world::delete_sound_voice(
        vostok::sound::sound_world *this,
        vostok::sound::sound_scene *scene,
        vostok::sound::sound_voice *voice)
{
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+2Fh] [ebp-9h] BYREF
  vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy> *allocator; // [esp+30h] [ebp-8h]
  char v6; // [esp+36h] [ebp-2h]
  char v7; // [esp+37h] [ebp-1h]

  v7 = 0;
  vostok::sound::sound_scene::remove_active_voice(scene, voice);
  if ( vostok::sound::sound_voice::can_be_deleted(voice) )
  {
    v6 = 0;
    allocator = this->m_sound_voices_allocator.m_variable;
    call_destructor_predicate = 0;
    vostok::memory::detail::delete_helper_impl<vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>,vostok::sound::sound_voice,vostok::memory::detail::call_destructor_predicate>(
      allocator,
      &voice,
      &call_destructor_predicate);
  }
  else
  {
    vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &this->m_voices_to_delete,
      voice,
      0);
  }
}
