void __cdecl vostok::debug::initialize(vostok::debug::engine *engine)
{
  s_debug_engine = engine;
  vostok::debug::g_disable_output_to_debugger = !engine->output_to_debugger(engine);
}
