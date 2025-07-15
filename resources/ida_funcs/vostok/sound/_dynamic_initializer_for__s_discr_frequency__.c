void vostok::sound::_dynamic_initializer_for__s_discr_frequency__()
{
  vostok::command_line::key::key(
    &s_discr_frequency,
    "rms_discreteness",
    "rms_discr",
    "sound rms",
    "set discretization frequency(floats per second). Default 50.",
    (const char *)&buf);
}
