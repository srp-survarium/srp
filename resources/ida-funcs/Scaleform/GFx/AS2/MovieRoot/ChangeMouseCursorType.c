void __thiscall Scaleform::GFx::AS2::MovieRoot::ChangeMouseCursorType(
        Scaleform::GFx::AS2::MovieRoot *this,
        unsigned int mouseIdx,
        unsigned int newCursorType)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  unsigned int Size; // ecx
  unsigned int v6; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // edi
  Scaleform::GFx::MovieImpl::LevelInfo *v8; // edx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  Scaleform::GFx::AS2::Environment *v10; // edi
  Scaleform::GFx::MovieImpl *v11; // eax
  Scaleform::GFx::AS2::GlobalContext *v12; // edx
  Scaleform::GFx::AS2::Object *v13; // eax
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // ebp
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::Value *pCurrent; // eax
  Scaleform::GFx::AS2::Value *v18; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // edi
  const Scaleform::GFx::AS2::FnCall *v20; // eax
  Scaleform::GFx::AS2::Value *v21; // ecx
  int v22; // ebx
  unsigned __int8 Flags; // bl
  unsigned int RefCount; // eax
  unsigned int v25; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [esp+20h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value ThisIn; // [esp+2Ch] [ebp-54h] BYREF
  Scaleform::GFx::AS2::Value v28; // [esp+3Ch] [ebp-44h] BYREF
  Scaleform::GFx::AS2::Value ResIn; // [esp+4Ch] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v30; // [esp+5Ch] [ebp-24h] BYREF

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v6 = 0;
  if ( Size )
  {
    Data = pMovieImpl->MovieLevels.Data.Data;
    v8 = Data;
    while ( v8->Level )
    {
      ++v6;
      ++v8;
      if ( v6 >= Size )
        goto LABEL_5;
    }
    pObject = Data[v6].pSprite.pObject;
  }
  else
  {
LABEL_5:
    pObject = 0;
  }
  v10 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                         + pObject->AvmObjOffset)
                                                                       + 124))((int)pObject + 4 * pObject->AvmObjOffset);
  v11 = this->pMovieImpl;
  if ( (v11->Flags & 0x1000) != 0 && (v12 = v10->StringContext.pContext, v12->GFxExtensions.Value == 1) )
  {
    ThisIn.T.Type = 0;
    if ( v12->pGlobal.pObject->GetMemberRaw(
           &v12->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
           &v10->StringContext,
           (const Scaleform::GFx::ASString *)&v12->pMovieRoot->pASMovieRoot.pObject[13].pASSupport,
           &ThisIn) )
    {
      v13 = Scaleform::GFx::AS2::Value::ToObject(&ThisIn, v10);
      if ( v13 )
      {
        pContext = v10->StringContext.pContext;
        v28.T.Type = 0;
        if ( v13->GetMember(
               &v13->Scaleform::GFx::AS2::ObjectInterface,
               v10,
               (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[35].pMovieImpl,
               &v28) )
        {
          Scaleform::GFx::AS2::Value::ToFunction(&v28, &result, v10);
          Function = result.Function;
          if ( result.Function )
          {
            ResIn.T.Type = 0;
            ++v10->Stack.pCurrent;
            p_Stack = &v10->Stack;
            if ( v10->Stack.pCurrent >= v10->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v10->Stack);
            pCurrent = p_Stack->pCurrent;
            if ( p_Stack->pCurrent )
            {
              pCurrent->T.Type = 3;
              pCurrent->NV.NumberValue = (double)mouseIdx;
            }
            ++p_Stack->pCurrent;
            if ( v10->Stack.pCurrent >= v10->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v10->Stack);
            v18 = p_Stack->pCurrent;
            if ( p_Stack->pCurrent )
            {
              v18->T.Type = 3;
              v18->NV.NumberValue = (double)newCursorType;
            }
            Scaleform::GFx::AS2::FnCall::FnCall(
              &v30,
              &ResIn,
              &ThisIn,
              v10,
              2,
              v10->Stack.pCurrent - v10->Stack.pPageStart + 32 * v10->Stack.Pages.Data.Size - 32);
            pLocalFrame = result.pLocalFrame;
            Function->Invoke(Function, v20, result.pLocalFrame, 0);
            Scaleform::GFx::AS2::FnCall::~FnCall(&v30);
            v21 = p_Stack->pCurrent;
            if ( &p_Stack->pCurrent[-2] >= p_Stack->pPageStart )
            {
              if ( v21->T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(v21);
              --p_Stack->pCurrent;
              if ( p_Stack->pCurrent->T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
              --p_Stack->pCurrent;
            }
            else
            {
              v22 = 2;
              do
              {
                if ( p_Stack->pCurrent->T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
                if ( --p_Stack->pCurrent < p_Stack->pPageStart )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
                --v22;
              }
              while ( v22 );
            }
            if ( ResIn.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&ResIn);
          }
          else
          {
            pLocalFrame = result.pLocalFrame;
          }
          Flags = result.Flags;
          if ( (result.Flags & 2) == 0 )
          {
            if ( Function )
            {
              RefCount = Function->RefCount;
              if ( (RefCount & 0x3FFFFFF) != 0 )
              {
                Function->RefCount = RefCount - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
              }
            }
          }
          if ( (Flags & 1) == 0 )
          {
            if ( pLocalFrame )
            {
              v25 = pLocalFrame->RefCount;
              if ( (v25 & 0x3FFFFFF) != 0 )
              {
                pLocalFrame->RefCount = v25 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
              }
            }
          }
        }
        if ( v28.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v28);
      }
    }
    if ( ThisIn.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&ThisIn);
  }
  else if ( newCursorType != v11->mMouseState[mouseIdx].CursorType )
  {
    Scaleform::GFx::AS2::MouseCtorFunction::SetCursorType(v11, mouseIdx, newCursorType);
  }
}
