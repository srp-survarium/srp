void __usercall _fpmath(int a1@<ebx>, int a2@<edi>, int initPrecision)
{
  _cfltcvt_init();
  _adjust_fdiv = _ms_p5_mp_test_fdiv();
  if ( initPrecision )
    _setdefaultprecision(a1, a2);
  __asm { fnclex }
}
