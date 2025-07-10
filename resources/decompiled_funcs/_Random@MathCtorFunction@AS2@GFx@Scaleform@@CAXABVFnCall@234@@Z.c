void __usercall Scaleform::GFx::AS2::MathCtorFunction::Random(
        unsigned int a1@<ebx>,
        const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // esi
  const Scaleform::GFx::AS2::FnCall *fna; // [esp+10h] [ebp+4h]

  fna = (const Scaleform::GFx::AS2::FnCall *)Scaleform::GFx::AS2::Math::GetNextRandom(
                                               a1,
                                               (Scaleform::String)fn->Env->Target->pASRoot->pMovieImpl);
  Result = fn->Result;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 3;
  Result->NV.NumberValue = (double)(unsigned int)fna / 4294967295.0;
}
