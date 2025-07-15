void __usercall readtimer(int a1@<edi>)
{
  void *v1; // esp
  void *v2; // esp
  DWORD buf; // [esp+8h] [ebp-Ch] BYREF
  LARGE_INTEGER PerformanceCount; // [esp+Ch] [ebp-8h] BYREF

  if ( have_perfc )
  {
    if ( QueryPerformanceCounter(&PerformanceCount) )
    {
      v1 = alloca(8);
      RAND_add(a1, &PerformanceCount, 8, 0.0);
      if ( have_perfc )
        return;
    }
    else
    {
      have_perfc = 0;
    }
  }
  buf = GetTickCount();
  v2 = alloca(8);
  RAND_add(a1, &buf, 4, 0.0);
}
