void __thiscall vostok::render::options::begin_render_options_changing(volatile int *waiting_for)
{
  _InterlockedExchange(waiting_for, 0);
}
