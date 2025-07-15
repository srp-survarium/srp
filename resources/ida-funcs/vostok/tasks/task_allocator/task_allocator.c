void __usercall vostok::tasks::task_allocator::task_allocator(vostok::tasks::task_allocator *this@<ecx>, int a2@<eax>)
{
  unsigned int v2; // edx
  _DWORD *v3; // ecx

  *(int *)((char *)&dword_60000 + a2) = 0;
  *(int *)((char *)&dword_60004 + a2) = 0;
  v2 = 0;
  v3 = (_DWORD *)(a2 + 88);
  do
  {
    *v3 = 0;
    *(v3 - 21) = v2++ != 4095 ? v3 + 2 : 0;
    v3 += 24;
  }
  while ( v2 < 0x1000 );
  *(int *)((char *)&dword_60000 + a2) = a2;
}
