void vostok::sound::_dynamic_initializer_for__s_speed_of_sound__()
{
  vostok::command_line::key::key(
    &s_speed_of_sound,
    "speed_of_sound",
    (const char *)&buf,
    "sound engine",
    "speed of sound",
    (const char *)&buf);
}
