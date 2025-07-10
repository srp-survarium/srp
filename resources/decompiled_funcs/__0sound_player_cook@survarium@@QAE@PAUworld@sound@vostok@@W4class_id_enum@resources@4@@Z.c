void __userpurge survarium::sound_player_cook::sound_player_cook(
        survarium::sound_player_cook *this@<ecx>,
        vostok::sound::world *world,
        vostok::resources::class_id_enum class_id)
{
  s_sound_player_cook.__vftable = (survarium::sound_player_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  s_sound_player_cook.m_cook_users_count.m_count = 0;
  s_sound_player_cook.m_class_id = sound_player_class;
  s_sound_player_cook.m_reuse_type = reuse_false;
  s_sound_player_cook.m_creation_thread_id = -1;
  s_sound_player_cook.m_allocate_thread_id = GetCurrentThreadId();
  s_sound_player_cook.m_next = 0;
  s_sound_player_cook.m_world = world;
  s_sound_player_cook.m_flags.m_flags = 8;
  s_sound_player_cook.__vftable = (survarium::sound_player_cook_vtbl *)&survarium::sound_player_cook::`vftable';
}
