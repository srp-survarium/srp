unsigned __int64 __usercall vostok::timing::timer::get_elapsed_ticks@<edx:eax>(
        vostok::timing::timer *this@<ecx>,
        int a2@<esi>)
{
  return *(_QWORD *)a2
       + (unsigned __int64)((double)(unsigned __int64)(*(_QWORD *)&vostok::timing::get_QPC() - *(_QWORD *)(a2 + 8))
                          * *(float *)(a2 + 16));
}
