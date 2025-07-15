void __cdecl Scaleform::GFx::AS2::SelectionCtorFunction::SetModalClip(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebp
  int v4; // edx
  Scaleform::GFx::AS2::Environment *v5; // eax
  Scaleform::GFx::CharacterHandle *v6; // ecx
  Scaleform::GFx::InteractiveObject *v7; // eax
  Scaleform::GFx::Sprite *v8; // esi
  Scaleform::GFx::AS2::Value *v9; // eax
  unsigned int v10; // eax
  Scaleform::GFx::AS2::Environment *v11; // [esp-Ch] [ebp-14h]

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    pMovieImpl = Env->Target->pASRoot->pMovieImpl;
    v4 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v4 = (int)&Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                              & 0x1F];
    v5 = fn->Env;
    if ( *(_BYTE *)v4 == 7
      && v5
      && (v6 = *(Scaleform::GFx::CharacterHandle **)(v4 + 4)) != 0
      && (v7 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v6, v5->Target->pASRoot->pMovieImpl)) != 0 )
    {
      v8 = LOBYTE(v7->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0
         ? (Scaleform::GFx::Sprite *)v7
         : 0;
      if ( v8 )
        ++v8->RefCount;
    }
    else
    {
      v8 = 0;
    }
    if ( fn->NArgs < 2 )
    {
      v10 = 0;
    }
    else
    {
      v11 = fn->Env;
      v9 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      v10 = Scaleform::GFx::AS2::Value::ToUInt32(v9, v11);
    }
    if ( v8
      && (v8->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
        & 0x400) != 0 )
    {
      Scaleform::GFx::MovieImpl::SetModalClip(pMovieImpl, v8, v10);
    }
    else
    {
      Scaleform::GFx::MovieImpl::SetModalClip(pMovieImpl, 0, v10);
    }
    if ( v8 )
      Scaleform::RefCountNTSImpl::Release(v8);
  }
}
