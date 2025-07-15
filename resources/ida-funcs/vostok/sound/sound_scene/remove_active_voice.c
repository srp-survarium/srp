void __thiscall vostok::sound::sound_scene::remove_active_voice(
        vostok::sound::sound_scene *this,
        vostok::sound::sound_voice *voice)
{
  vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
    &this->m_active_voices,
    voice);
}
