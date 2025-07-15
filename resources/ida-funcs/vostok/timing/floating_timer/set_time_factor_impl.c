void __userpurge vostok::timing::floating_timer::set_time_factor_impl(
        vostok::timing::floating_timer *this@<ecx>,
        int a2@<eax>,
        float time_factor,
        float time_floating_factor)
{
  unsigned __int64 elapsed_ticks_impl; // rax
  unsigned int LowPart; // edi
  unsigned int v7; // ecx
  int HighPart; // eax
  unsigned int v9; // edx
  int v10; // xmm0_4
  double v11; // st7
  LARGE_INTEGER v12; // [esp+20h] [ebp-10h] BYREF
  int v13; // [esp+28h] [ebp-8h]
  int v14; // [esp+2Ch] [ebp-4h]

  elapsed_ticks_impl = vostok::timing::floating_timer::get_elapsed_ticks_impl(
                         (vostok::timing::floating_timer *)a2,
                         &v12);
  LowPart = v12.LowPart;
  v7 = *(_DWORD *)(a2 + 16);
  *(_DWORD *)a2 = elapsed_ticks_impl;
  HighPart = v12.HighPart;
  *(_DWORD *)(a2 + 4) = HIDWORD(elapsed_ticks_impl);
  v9 = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(a2 + 8) = LowPart;
  *(_DWORD *)(a2 + 12) = HighPart;
  if ( __PAIR64__(HighPart, LowPart) >= __PAIR64__(v9, v7) )
  {
    *(_DWORD *)(a2 + 16) = LowPart;
    *(_DWORD *)(a2 + 20) = HighPart;
  }
  else
  {
    if ( *(float *)(a2 + 24) == 0.0 )
      v10 = *(_DWORD *)(a2 + 36);
    else
      v10 = *(_DWORD *)(a2 + 32);
    v13 = v10 & 0x7FFFFFFF;
    v14 = v10 & 0x7FFFFFFF;
    v11 = (double)*(unsigned __int64 *)(*(_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + 8);
    *(_QWORD *)(a2 + 16) = v12.QuadPart
                         + (unsigned __int64)(v11
                                            * ((double)(unsigned __int64)((double)(__PAIR64__(v9, v7) - v12.QuadPart)
                                                                        * COERCE_FLOAT(v10 & 0x7FFFFFFF))
                                             / (v11
                                              * COERCE_FLOAT(v10 & 0x7FFFFFFF))));
  }
  *(float *)(a2 + 24) = time_factor;
  *(float *)(a2 + 32) = time_floating_factor;
}
