void __cdecl _fpmath(int initPrecision)
{
  _cfltcvt_init();
  _adjust_fdiv = _ms_p5_mp_test_fdiv();
  if ( initPrecision )
    _setdefaultprecision();
  __asm { fnclex }
}
