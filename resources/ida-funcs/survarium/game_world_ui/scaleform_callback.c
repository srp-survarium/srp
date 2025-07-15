void __thiscall survarium::game_world_ui::scaleform_callback(
        survarium::game_world_ui *this,
        survarium::flash_movie *__formal,
        char *methodName,
        const survarium::flash_value *args,
        unsigned int a5)
{
  const char *v6; // edi
  char *v7; // esi
  int v8; // ecx
  bool v9; // zf
  survarium::game *v10; // ecx

  v6 = "finish_match_clicked";
  v7 = methodName;
  v8 = 21;
  v9 = 1;
  do
  {
    if ( !v8 )
      break;
    v9 = *v7++ == *v6++;
    --v8;
  }
  while ( v9 );
  if ( v9 )
  {
    survarium::game_world::on_finish_match(
      (survarium::game_world *)v8,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)this->m_game_world);
  }
  else if ( !vostok::strings::compare(methodName, "sound_play") )
  {
    survarium::game::play_ui_sound(v10, (int)this->m_game_world->m_game, args->body[8]);
  }
}
