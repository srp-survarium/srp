void __usercall vostok::timing::floating_timer::floating_timer(
        vostok::timing::floating_timer *this@<ecx>,
        LARGE_INTEGER *a2@<esi>)
{
  LARGE_INTEGER QPC; // rax
  float v3; // xmm0_4

  a2->LowPart = 0;
  a2->HighPart = 0;
  QPC = vostok::timing::get_QPC();
  v3 = s_bm_current_air_resistance;
  a2[2].LowPart = 0;
  a2[2].HighPart = 0;
  *(float *)&a2[3].LowPart = v3;
  *(float *)&a2[3].HighPart = v3;
  a2[1] = QPC;
  a2[4].LowPart = 0;
  a2[4].HighPart = 0;
}
