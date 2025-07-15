void __cdecl Scaleform::GFx::AS2::IntervalTimer::ClearInterval(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // edi
  Scaleform::GFx::AS2::Value *v3; // ecx
  long double v4; // st7
  double v5; // [esp+4h] [ebp-8h]

  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    pMovieImpl = Env->Target->pASRoot->pMovieImpl;
    v3 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v3 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v4 = Scaleform::GFx::AS2::Value::ToNumber(v3, fn->Env);
    v5 = v4;
    if ( (HIDWORD(v5) & 0x7FF00000) != 0x7FF00000 || !(HIDWORD(v5) & 0xFFFFF | LODWORD(v5)) )
      Scaleform::GFx::MovieImpl::ClearIntervalTimer(pMovieImpl, (int)v4);
  }
}
