unsigned __int64 __thiscall vostok::timing::floating_timer::get_time_with_factor(
        vostok::timing::floating_timer *this,
        const unsigned __int64 qpc,
        const float time_factor)
{
  return (unsigned __int64)((double)(qpc - this->m_start_time) * time_factor);
}
