void __cdecl vostok::core::core_engine_flush()
{
  if ( s_engine_0 )
    s_engine_0->on_crash(s_engine_0);
}
