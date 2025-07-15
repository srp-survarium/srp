unsigned __int64 __usercall vostok::timing::floating_timer::get_elapsed_ticks_impl@<edx:eax>(
        vostok::timing::floating_timer *this@<esi>,
        LARGE_INTEGER *qpc@<eax>)
{
  LARGE_INTEGER v3; // rax
  int HighPart; // edi
  unsigned int LowPart; // ebx
  unsigned __int64 v6; // rax
  unsigned __int64 time_with_factor; // rax
  float time_factor; // [esp+0h] [ebp-14h]

  v3 = vostok::timing::get_QPC();
  time_factor = this->m_time_floating_factor;
  *qpc = v3;
  HighPart = v3.HighPart;
  LowPart = v3.LowPart;
  v6 = vostok::math::min(this->m_stop_floating_ticks, v3.QuadPart);
  time_with_factor = vostok::timing::floating_timer::get_time_with_factor(this, v6, time_factor);
  return this->m_current_time
       + vostok::timing::floating_timer::get_time_with_factor(this, __PAIR64__(HighPart, LowPart), this->m_time_factor)
       + time_with_factor;
}
