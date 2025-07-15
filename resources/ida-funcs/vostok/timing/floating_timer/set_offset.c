void __userpurge vostok::timing::floating_timer::set_offset(
        vostok::timing::floating_timer *this@<ecx>,
        int a2@<esi>,
        const __int16 offset_time_in_ms)
{
  float v3; // xmm1_4
  float *v4; // eax
  float v5; // xmm0_4

  vostok::timing::floating_timer::set_time_factor_impl(this, a2, *(float *)(a2 + 24), *(float *)(a2 + 32));
  if ( offset_time_in_ms >= 0 )
    v3 = s_bm_current_air_resistance;
  else
    v3 = FLOAT_N1_0;
  v4 = (float *)(a2 + 36);
  if ( *(float *)(a2 + 24) != 0.0 )
    v4 = (float *)(a2 + 32);
  *v4 = *(float *)(a2 + 40) * v3;
  if ( *(float *)(a2 + 24) == 0.0 )
    v5 = *(float *)(a2 + 36);
  else
    v5 = *(float *)(a2 + 32);
  *(_QWORD *)(a2 + 16) = *(_QWORD *)(a2 + 8)
                       + (unsigned __int64)((double)offset_time_in_ms
                                          / (v5
                                           * 1000.0)
                                          * (double)*(unsigned __int64 *)(*(_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                        + 8));
}
