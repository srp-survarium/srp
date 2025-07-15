void __cdecl Scaleform::GFx::AS2::SelectionCtorFunction::GetFocusArray(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // esi
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::InteractiveObject *v5; // eax
  Scaleform::GFx::AS2::ArrayObject *v6; // ebp
  void **p_Data; // esi
  void *v8; // eax
  unsigned int i; // edi
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  Scaleform::GFx::Sprite *pObject; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *v13; // [esp+0h] [ebp-20h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+10h] [ebp-10h] BYREF
  Scaleform::RefCountNTSImpl *v16; // [esp+24h] [ebp+4h]

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 1;
  Env = fn->Env;
  if ( Env && Env->StringContext.pContext->GFxExtensions.Value == 1 && fn->NArgs >= 1 )
  {
    v13 = fn->Env;
    v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
    v5 = Scaleform::GFx::AS2::Value::ToCharacter(v4, v13);
    v16 = v5;
    if ( v5 )
      ++v5->RefCount;
    v6 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                               fn->Env,
                                               fn->Env->StringContext.pContext->pGlobal.pObject,
                                               (const Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pASSupport,
                                               0,
                                               -1);
    p_Data = (void **)&v6->Elements.Data.Data;
    if ( v6->Elements.Data.Policy.Capacity < 6 )
    {
      if ( *p_Data )
      {
        v8 = Scaleform::Memory::pGlobalHeap->Realloc(Scaleform::Memory::pGlobalHeap, *p_Data, 32);
      }
      else
      {
        result.pObject = (Scaleform::GFx::Sprite *)2;
        v8 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, p_Data, 32, &result);
      }
      *p_Data = v8;
      v6->Elements.Data.Policy.Capacity = 8;
    }
    for ( i = 0; i < 6; ++i )
    {
      pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
      Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&pMovieImpl->FocusGroups[pMovieImpl->FocusGroupIndexes[i]].LastFocused,
        &result);
      pObject = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        Scaleform::RefCountNTSImpl::Release(pObject);
      }
      if ( pObject == v16 )
      {
        val.T.Type = 4;
        val.NV.Int32Value = i;
        Scaleform::GFx::AS2::ArrayObject::PushBack(v6, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
    }
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v6);
    if ( v6 )
    {
      RefCount = v6->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v6->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
      }
    }
    if ( v16 )
      Scaleform::RefCountNTSImpl::Release(v16);
  }
}
