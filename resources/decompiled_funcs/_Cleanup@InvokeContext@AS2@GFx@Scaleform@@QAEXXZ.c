void __thiscall Scaleform::GFx::AS2::InvokeContext::Cleanup(Scaleform::GFx::AS2::InvokeContext *this)
{
  Scaleform::GFx::AS2::Object *pObject; // eax
  Scaleform::GFx::AS2::ObjectInterface *v3; // esi
  Scaleform::GFx::AS2::Environment *pOurEnv; // esi
  Scaleform::GFx::MovieImpl *pMovieRoot; // ecx
  unsigned int Size; // eax
  const Scaleform::GFx::ASString *p_pMovieImpl; // ebp
  Scaleform::GFx::AS2::Value *Local; // eax
  Scaleform::GFx::AS2::Environment *v9; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  unsigned int v11; // eax
  const Scaleform::GFx::ASString *p_pASSupport; // ebp
  Scaleform::GFx::AS2::Value *v13; // eax
  Scaleform::GFx::AS2::Environment *v14; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v15; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value val; // [esp+8h] [ebp-10h] BYREF

  pObject = this->PassedThisObj.pObject;
  if ( pObject )
  {
    v3 = &pObject->Scaleform::GFx::AS2::ObjectInterface;
    if ( pObject != (Scaleform::GFx::AS2::Object *)-16 && v3->IsSuper(v3) )
      Scaleform::GFx::AS2::SuperObject::ResetAltProto((Scaleform::GFx::AS2::SuperObject *)&v3[-2].pProto);
  }
  if ( this->pThis->ExecType != 2 || (this->pThis->Function2Flags & 2) == 0 )
  {
    pOurEnv = this->pOurEnv;
    val.T.Type = 0;
    pMovieRoot = pOurEnv->StringContext.pContext->pMovieRoot;
    Size = pOurEnv->LocalFrames.Data.Size;
    p_pMovieImpl = (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[20].pMovieImpl;
    if ( Size )
    {
      if ( pOurEnv->LocalFrames.Data.Data[Size - 1].pObject )
      {
        Local = (Scaleform::GFx::AS2::Value *)Scaleform::GFx::AS2::Environment::FindLocal(
                                                pOurEnv,
                                                (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[20].pMovieImpl);
        if ( Local )
          Scaleform::GFx::AS2::Value::operator=(Local, &val);
        else
          Scaleform::GFx::AS2::Environment::AddLocal(pOurEnv, p_pMovieImpl, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
    }
  }
  if ( this->pThis->ExecType != 2 || (this->pThis->Function2Flags & 0x20) == 0 )
  {
    v9 = this->pOurEnv;
    val.T.Type = 0;
    pContext = v9->StringContext.pContext;
    v11 = v9->LocalFrames.Data.Size;
    p_pASSupport = (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[20].pASSupport;
    if ( v11 )
    {
      if ( v9->LocalFrames.Data.Data[v11 - 1].pObject )
      {
        v13 = (Scaleform::GFx::AS2::Value *)Scaleform::GFx::AS2::Environment::FindLocal(
                                              v9,
                                              (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[20].pASSupport);
        if ( v13 )
          Scaleform::GFx::AS2::Value::operator=(v13, &val);
        else
          Scaleform::GFx::AS2::Environment::AddLocal(v9, p_pASSupport, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
    }
  }
  Scaleform::GFx::AS2::Environment::SetLocalFrameTop(this->pOurEnv, this->LocalStackTop);
  if ( this->pThis->ExecType == 2 )
    Scaleform::GFx::AS2::Environment::DropLocalRegisters(this->pOurEnv, this->pThis->LocalRegisterCount);
  v14 = this->pOurEnv;
  if ( v14 )
  {
    v15 = v14->CallStack.pCurrent->pObject;
    if ( v15 )
    {
      RefCount = v15->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v15->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
      }
    }
    if ( --v14->CallStack.pCurrent < v14->CallStack.pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::PopPage(&v14->CallStack);
  }
}
