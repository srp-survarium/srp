void readtimer()
{
  void *v0; // esp
  void *v1; // esp
  DWORD buf; // [esp+8h] [ebp-Ch] BYREF
  LARGE_INTEGER PerformanceCount; // [esp+Ch] [ebp-8h] BYREF

  if ( have_perfc )
  {
    if ( QueryPerformanceCounter(&PerformanceCount) )
    {
      v0 = alloca(8);
      RAND_add(&PerformanceCount, 8, 0.0);
      if ( have_perfc )
        return;
    }
    else
    {
      have_perfc = 0;
    }
  }
  buf = GetTickCount();
  v1 = alloca(8);
  RAND_add(&buf, 4, 0.0);
}
