void __usercall survarium::scheduler::scheduler(survarium::scheduler *this@<ecx>, _DWORD *a2@<eax>)
{
  vostok::memory::doug_lea_allocator *v2; // edx

  v2 = survarium::g_allocator;
  *a2 = 0;
  a2[1] = 0;
  a2[3] = 0;
  a2[2] = v2;
  a2[4] = 0;
  a2[5] = 0;
  a2[7] = 0;
  a2[6] = v2;
  a2[10] = 0;
  a2[11] = 0;
  a2[8] = a2;
  a2[9] = a2 + 4;
}
