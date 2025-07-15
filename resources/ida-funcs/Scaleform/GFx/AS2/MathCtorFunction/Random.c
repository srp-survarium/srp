void __usercall Scaleform::GFx::AS2::MathCtorFunction::Random(int a1@<ebx>, const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // esi
  unsigned int NextRandom; // [esp+10h] [ebp+4h]

  NextRandom = Scaleform::GFx::AS2::Math::GetNextRandom(a1, (Scaleform::String)fn->Env->Target->pASRoot->pMovieImpl);
  Result = fn->Result;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 3;
  Result->NV.NumberValue = (double)NextRandom / 4294967295.0;
}
