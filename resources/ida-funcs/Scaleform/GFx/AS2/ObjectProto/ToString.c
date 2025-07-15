void __cdecl Scaleform::GFx::AS2::ObjectProto::ToString(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::ASMovieRootBase *pObject; // edi
  int v3; // eax
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::DisplayObject *v5; // ecx
  Scaleform::GFx::CharacterHandle *CharacterHandle; // eax
  const Scaleform::GFx::ASString *CharacterNamePath; // eax
  Scaleform::GFx::AS2::Value *v8; // esi
  const Scaleform::GFx::ASString *v9; // edi
  int pNode; // eax
  Scaleform::GFx::AS2::Value *v11; // esi
  Scaleform::GFx::ASMovieRootBase *v12; // edi
  volatile int RefCount; // eax
  Scaleform::GFx::AS2::Value v14; // [esp+8h] [ebp-10h] BYREF

  if ( fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Function )
  {
    Result = fn->Result;
    pObject = fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 5;
    v3 = *(_DWORD *)&pObject[24].AVMVersion;
    Result->NV.Int32Value = v3;
    ++*(_DWORD *)(v3 + 12);
  }
  else if ( (unsigned int)(fn->ThisPtr->GetObjectType(fn->ThisPtr) - 2) > 3 )
  {
    v11 = fn->Result;
    v12 = fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    if ( v11->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v11);
    v11->T.Type = 5;
    RefCount = v12[25].RefCount;
    v11->NV.Int32Value = RefCount;
    ++*(_DWORD *)(RefCount + 12);
  }
  else
  {
    ThisPtr = fn->ThisPtr;
    if ( (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 )
      v5 = 0;
    else
      v5 = (Scaleform::GFx::DisplayObject *)ThisPtr[1].__vftable;
    v14.T.Type = 7;
    if ( v5 )
    {
      CharacterHandle = v5->pNameHandle.pObject;
      if ( !CharacterHandle )
        CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v5);
      v14.NV.Int32Value = (int)CharacterHandle;
      if ( CharacterHandle )
        ++CharacterHandle->RefCount;
    }
    else
    {
      v14.NV.Int32Value = 0;
    }
    CharacterNamePath = Scaleform::GFx::AS2::Value::GetCharacterNamePath(&v14, fn->Env);
    v8 = fn->Result;
    v9 = CharacterNamePath;
    if ( v8->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v8);
    v8->T.Type = 5;
    pNode = (int)v9->pNode;
    v8->NV.Int32Value = (int)v9->pNode;
    ++*(_DWORD *)(pNode + 12);
    Scaleform::GFx::AS2::Value::DropRefs(&v14);
  }
}
