void __cdecl vostok::debug::bugtrap::restart_application_on_crash(bool value)
{
  if ( value )
    s_BT_SetFlags(0x205u);
  else
    s_BT_SetFlags(5u);
}
