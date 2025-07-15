void __cdecl Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::Call(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // eax
  bool v2; // zf
  Scaleform::GFx::ASStringNode *RefCount; // ebx
  unsigned int v4; // ebp
  bool v5; // cc
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::Value *v9; // eax
  unsigned int v10; // edi
  Scaleform::GFx::AS2::Environment *v11; // ecx
  int v12; // edx
  unsigned int Size; // ebx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // ecx
  unsigned int v15; // eax
  Scaleform::GFx::AS2::Value *v16; // eax
  Scaleform::GFx::Value *v17; // ebx
  Scaleform::GFx::Value *v18; // ecx
  Scaleform::GFx::AS2::Value *p_pMovieImpl; // edi
  Scaleform::GFx::MovieImpl *v20; // edi
  Scaleform::GFx::Value *v21; // esi
  unsigned int v22; // edi
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Environment *v24; // [esp-8h] [ebp-120h]
  Scaleform::GFx::ASStringNode *pData; // [esp+14h] [ebp-104h] BYREF
  Scaleform::GFx::Value *v26; // [esp+18h] [ebp-100h]
  Scaleform::GFx::MovieImpl *pMovieImpl; // [esp+1Ch] [ebp-FCh]
  Scaleform::GFx::Value *v28; // [esp+20h] [ebp-F8h]
  Scaleform::GFx::AS2::Value *v29; // [esp+24h] [ebp-F4h]
  char v30; // [esp+28h] [ebp-F0h] BYREF

  Env = fn->Env;
  v2 = Env->Target->pASRoot->pMovieImpl->pExtIntfHandler.pObject == 0;
  pMovieImpl = Env->Target->pASRoot->pMovieImpl;
  if ( v2 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::LogScriptWarning(
      &fn->Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>,
      "ExternalInterface.call - handler is not installed.");
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 0;
  }
  else
  {
    RefCount = (Scaleform::GFx::ASStringNode *)Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
    ++RefCount->RefCount;
    v4 = 0;
    v5 = fn->NArgs < 1;
    pData = RefCount;
    if ( v5 )
      goto LABEL_9;
    v24 = fn->Env;
    v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
    Scaleform::GFx::AS2::Value::ToStringImpl(v6, (Scaleform::GFx::ASString *)&pData, v24, -1, 0);
    v7 = pData;
    ++pData->RefCount;
    v2 = RefCount->RefCount-- == 1;
    if ( v2 )
      Scaleform::GFx::ASStringNode::ReleaseNode(RefCount);
    v2 = v7->RefCount-- == 1;
    RefCount = v7;
    pData = v7;
    if ( v2 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    v4 = fn->NArgs - 1;
    if ( v4 <= 0xA )
    {
LABEL_9:
      v9 = (Scaleform::GFx::Value *)&v30;
    }
    else
    {
      pHeap = fn->Env->StringContext.pContext->pHeap;
      v9 = (Scaleform::GFx::Value *)pHeap->Alloc(pHeap, 24 * v4, 0);
    }
    v10 = 0;
    v26 = v9;
    if ( v4 )
    {
      v28 = v9;
      do
      {
        v11 = fn->Env;
        v12 = (char *)v11->Stack.pCurrent - (char *)v11->Stack.pPageStart;
        Size = v11->Stack.Pages.Data.Size;
        p_Stack = &v11->Stack;
        v15 = fn->FirstArgBottomIndex - v10 - 1;
        v29 = 0;
        if ( v15 > 32 * (Size - 1) + (v12 >> 4) )
          v16 = v29;
        else
          v16 = &p_Stack->Pages.Data.Data[v15 >> 5]->Values[v15 & 0x1F];
        v17 = v28;
        v18 = 0;
        if ( v28 )
        {
          v28->pObjectInterface = 0;
          v17->Type = VT_Undefined;
          v18 = v17;
        }
        Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
          (Scaleform::GFx::AS2::MovieRoot *)pMovieImpl->pASMovieRoot.pObject,
          fn->Env,
          v16,
          v18);
        ++v10;
        v28 = v17 + 1;
      }
      while ( v10 < v4 );
      RefCount = pData;
    }
    p_pMovieImpl = (Scaleform::GFx::AS2::Value *)&pMovieImpl->pASMovieRoot.pObject[2].pMovieImpl;
    Scaleform::GFx::AS2::Value::DropRefs(p_pMovieImpl);
    p_pMovieImpl->T.Type = 0;
    if ( RefCount->Size )
      pData = (Scaleform::GFx::ASStringNode *)RefCount->pData;
    else
      pData = 0;
    v20 = pMovieImpl;
    pMovieImpl->pExtIntfHandler.pObject->Callback(
      pMovieImpl->pExtIntfHandler.pObject,
      pMovieImpl,
      (const char *)pData,
      v26,
      v4);
    Scaleform::GFx::AS2::Value::operator=(
      fn->Result,
      (const Scaleform::GFx::AS2::Value *)&v20->pASMovieRoot.pObject[2].pMovieImpl);
    if ( v4 )
    {
      v21 = v26;
      v22 = v4;
      do
      {
        if ( (v21->Type & 0x40) != 0 )
        {
          ((void (__stdcall *)(Scaleform::GFx::Value *, int))v21->pObjectInterface->ObjectRelease)(
            v21,
            v21->mValue.IValue);
          v21->pObjectInterface = 0;
        }
        v21->Type = VT_Undefined;
        ++v21;
        --v22;
      }
      while ( v22 );
    }
    if ( v4 > 0x3C )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v26);
    v2 = RefCount->RefCount-- == 1;
    if ( v2 )
      Scaleform::GFx::ASStringNode::ReleaseNode(RefCount);
  }
}
