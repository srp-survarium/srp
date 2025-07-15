double __thiscall vostok::timing::timer::get_elapsed_sec(vostok::timing::timer *this)
{
  return (double)vostok::timing::timer::get_elapsed_ticks(this)
       / (double)(unsigned __int64)vostok::timing::g_qpc_per_second.QuadPart;
}
