void __cdecl Scaleform::GFx::AS2::MovieClipLoaderProto::UnloadClip(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *Env; // edi
  Scaleform::GFx::AS2::Value *v4; // ecx
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::Sprite *LevelMovie; // eax
  Scaleform::RefCountNTSImpl *v7; // edi
  unsigned __int8 Type; // al
  Scaleform::GFx::AS2::Environment *v9; // eax
  Scaleform::GFx::AS2::MovieRoot *pObject; // edi
  Scaleform::GFx::AS2::Value *v11; // eax
  int v12; // eax
  Scaleform::GFx::AS2::Value *v13; // eax
  Scaleform::GFx::InteractiveObject *Target; // eax
  Scaleform::GFx::ASStringNode *v15; // ecx
  bool v16; // zf
  Scaleform::GFx::AS2::Value *v17; // esi
  Scaleform::GFx::AS2::Environment *v18; // [esp-4h] [ebp-10h]

  v1 = fn;
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 2;
  Result->V.BooleanValue = 0;
  if ( v1->NArgs >= 1 )
  {
    Env = v1->Env;
    v4 = 0;
    if ( v1->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v4 = &Env->Stack.Pages.Data.Data[(unsigned int)v1->FirstArgBottomIndex >> 5]->Values[v1->FirstArgBottomIndex
                                                                                         & 0x1F];
    if ( v4->T.Type == 7 )
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      LevelMovie = (Scaleform::GFx::Sprite *)Scaleform::GFx::AS2::Value::ToCharacter(v5, Env);
      if ( LevelMovie )
      {
        ++LevelMovie->RefCount;
        v7 = LevelMovie;
        goto LABEL_16;
      }
    }
    else
    {
      Type = Scaleform::GFx::AS2::FnCall::Arg(v1, 0)->T.Type;
      if ( Type != 3 && Type != 4 )
      {
        v13 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
        Scaleform::GFx::AS2::Value::ToStringImpl(v13, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
        Target = Scaleform::GFx::AS2::Environment::FindTarget(v1->Env, (const Scaleform::GFx::ASString *)&fn, 0);
        if ( Target )
          ++Target->RefCount;
        v15 = (Scaleform::GFx::ASStringNode *)fn;
        v16 = fn->ThisFunctionRef.Function-- == (Scaleform::GFx::AS2::FunctionObject *)1;
        v7 = Target;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        goto LABEL_16;
      }
      v9 = Env;
      pObject = (Scaleform::GFx::AS2::MovieRoot *)Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject;
      v18 = v9;
      v11 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      v12 = Scaleform::GFx::AS2::Value::ToInt32(v11, v18);
      LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, v12);
      if ( LevelMovie )
        ++LevelMovie->RefCount;
    }
    v7 = LevelMovie;
LABEL_16:
    if ( v7 )
    {
      Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
        (Scaleform::GFx::AS2::MovieRoot *)v1->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
        (Scaleform::String)v7,
        (const __m128i *)uri,
        LM_None,
        0);
      v17 = v1->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v17);
      v17->V.BooleanValue = 1;
      v17->T.Type = 2;
      Scaleform::RefCountNTSImpl::Release(v7);
    }
  }
}
