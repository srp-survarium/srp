void vostok::sound::_dynamic_initializer_for__s_propagators_count__()
{
  vostok::command_line::key::key(
    &s_propagators_count,
    "propagators_count",
    (const char *)&buf,
    "sound engine",
    "count of sound_instance_propagator's, default is 64.",
    (const char *)&buf);
}
