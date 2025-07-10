bool __thiscall Scaleform::GFx::AS2::AvmCharacter::ExecuteEvent(
        Scaleform::GFx::AS2::AvmCharacter *this,
        const Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::InteractiveObject *pDispObj; // eax
  Scaleform::GFx::AS2::Environment *v4; // esi
  Scaleform::RefCountNTSImpl *Target; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int ControllerIndex; // eax
  Scaleform::GFx::KeyboardState *v9; // ecx
  Scaleform::GFx::AS2::FunctionObject *v10; // edi
  unsigned __int8 v11; // bl
  unsigned int v12; // eax
  Scaleform::GFx::AS2::LocalFrame *v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // ecx
  Scaleform::GFx::InteractiveObject *v16; // ecx
  Scaleform::GFx::CharacterHandle *CharacterHandle; // eax
  const char *v18; // edi
  Scaleform::GFx::AS2::FunctionRef *v19; // eax
  unsigned int v20; // edx
  Scaleform::GFx::AS2::FunctionObject *v21; // ecx
  unsigned int v22; // edx
  Scaleform::GFx::AS2::LocalFrame *v23; // ecx
  HINSTANCE__ *v24; // eax
  Scaleform::GFx::AS2::LocalFrame *AsciiCode; // edx
  Scaleform::GFx::AS2::Value *v26; // eax
  Scaleform::GFx::AS2::Value **p_pCurrent; // edi
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *v28)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::Node *, Scaleform::GFx::XML::RootNode *); // eax
  bool v29; // zf
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // edi
  Scaleform::GFx::AS2::Value *v31; // eax
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  Scaleform::GFx::AS2::LocalFrame *RollOverCnt; // ecx
  char v34; // al
  Scaleform::GFx::AS2::Value **v35; // edi
  Scaleform::GFx::AS2::Value *v36; // eax
  unsigned int Flags; // ecx
  Scaleform::GFx::InteractiveObject *v38; // ecx
  Scaleform::GFx::CharacterHandle *pObject; // eax
  const char *pData; // edi
  Scaleform::GFx::AS2::FunctionRef *v41; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v44; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  Scaleform::GFx::InteractiveObject *v46; // ecx
  Scaleform::GFx::CharacterHandle *v47; // eax
  const char *v48; // edi
  Scaleform::GFx::AS2::FunctionRef *v49; // eax
  unsigned int v50; // edx
  Scaleform::GFx::AS2::FunctionObject *v51; // ecx
  unsigned int v52; // edx
  Scaleform::GFx::AS2::LocalFrame *v53; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  bool v55; // bl
  int nArgs; // [esp+Ch] [ebp-38h]
  Scaleform::GFx::ASString methodName; // [esp+14h] [ebp-30h] BYREF
  int handlerFoundCnt; // [esp+18h] [ebp-2Ch]
  Scaleform::RefCountNTSImpl *v61; // [esp+1Ch] [ebp-28h]
  Scaleform::RefCountNTSImpl *v62; // [esp+20h] [ebp-24h]
  Scaleform::GFx::AS2::FunctionRef mfref; // [esp+24h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value method; // [esp+34h] [ebp-10h] BYREF
  bool handlerFound; // [esp+48h] [ebp+4h]

  pDispObj = this->pDispObj;
  v62 = pDispObj;
  if ( pDispObj )
    ++pDispObj->RefCount;
  v4 = this->GetASEnvironment(this);
  Target = v4->Target;
  v61 = Target;
  if ( Target )
    ++Target->RefCount;
  if ( id->Id == 64 || id->Id == 128 )
  {
    pMovieImpl = v4->Target->pASRoot->pMovieImpl;
    if ( pMovieImpl )
    {
      ControllerIndex = id->ControllerIndex;
      if ( ControllerIndex >= 6 )
        v9 = 0;
      else
        v9 = &pMovieImpl->KeyboardStates[ControllerIndex];
      Scaleform::GFx::KeyboardState::UpdateListeners(v9, id);
    }
  }
  handlerFoundCnt = 0;
  method.T.Type = 0;
  if ( Scaleform::GFx::AS2::AvmCharacter::HasClipEventHandler(this, id) && !id->RollOverCnt )
  {
    Scaleform::GFx::AS2::AvmCharacter::InvokeClipEventHandlers(
      this,
      v4,
      (const Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy> *)id);
    handlerFoundCnt = 1;
  }
  Scaleform::GFx::AS2::EventId_GetFunctionName(
    &methodName,
    (Scaleform::GFx::AS2::StringManager *)&v4->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
    id);
  if ( methodName.pNode->Size
    && this->GetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, &v4->StringContext, &methodName, &method) )
  {
    if ( method.T.Type == 9 )
    {
      LOBYTE(mfref.Function) = 0;
      Scaleform::GFx::AS2::Value::GetPropertyValue(
        &method,
        v4,
        &this->Scaleform::GFx::AS2::ObjectInterface,
        (Scaleform::GFx::AS2::Value *)&mfref);
      Scaleform::GFx::AS2::Value::operator=(&method, (const Scaleform::GFx::AS2::Value *)&mfref);
      if ( LOBYTE(mfref.Function) >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&mfref);
    }
    if ( method.T.Type != 1 )
    {
      if ( v4->StringContext.pContext->GFxExtensions.Value != 1 )
      {
        if ( id->RollOverCnt )
          goto LABEL_114;
        Flags = v4->Target->pASRoot->pMovieImpl->Flags;
        ++handlerFoundCnt;
        if ( (Flags & 4) != 0 )
        {
          v38 = this->pDispObj;
          pObject = v38->pNameHandle.pObject;
          if ( !pObject )
            pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v38);
          pData = pObject->NamePath.pNode->pData;
          v41 = Scaleform::GFx::AS2::Value::ToFunction(&method, &mfref, v4);
          Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
            v4,
            "\n!!! ExecuteEvent started '%s' = %p for %s\n",
            methodName.pNode->pData,
            v41->Function,
            pData);
          if ( (mfref.Flags & 2) == 0 )
          {
            if ( mfref.Function )
            {
              RefCount = mfref.Function->RefCount;
              Function = mfref.Function;
              if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
              {
                mfref.Function->RefCount = RefCount - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
              }
            }
          }
          mfref.Function = 0;
          if ( (mfref.Flags & 1) == 0 )
          {
            if ( mfref.pLocalFrame )
            {
              v44 = mfref.pLocalFrame->RefCount;
              pLocalFrame = mfref.pLocalFrame;
              if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v44) != 0 )
              {
                mfref.pLocalFrame->RefCount = v44 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
              }
            }
          }
        }
        Scaleform::GFx::AS2::GAS_Invoke(
          &method,
          0,
          &this->Scaleform::GFx::AS2::ObjectInterface,
          v4,
          0,
          v4->Stack.pCurrent - v4->Stack.pPageStart + 32 * v4->Stack.Pages.Data.Size - 31,
          0);
        goto LABEL_103;
      }
      nArgs = 0;
      handlerFound = 1;
      if ( !id->RollOverCnt )
        goto LABEL_34;
      Scaleform::GFx::AS2::Value::ToFunction(&method, &mfref, v4);
      v10 = mfref.Function;
      if ( mfref.Function )
        handlerFound = mfref.Function->GetNumArgs(mfref.Function) >= 2;
      v11 = mfref.Flags;
      if ( (mfref.Flags & 2) == 0 )
      {
        if ( v10 )
        {
          v12 = v10->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v12) != 0 )
          {
            v10->RefCount = v12 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
          }
        }
      }
      if ( (v11 & 1) == 0 )
      {
        v13 = mfref.pLocalFrame;
        if ( mfref.pLocalFrame )
        {
          v14 = mfref.pLocalFrame->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v14) != 0 )
          {
            mfref.pLocalFrame->RefCount = v14 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
          }
        }
      }
      if ( handlerFound )
      {
LABEL_34:
        v15 = v4->Target->pASRoot->pMovieImpl->Flags;
        ++handlerFoundCnt;
        if ( (v15 & 4) != 0 )
        {
          v16 = this->pDispObj;
          CharacterHandle = v16->pNameHandle.pObject;
          if ( !CharacterHandle )
            CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v16);
          v18 = CharacterHandle->NamePath.pNode->pData;
          v19 = Scaleform::GFx::AS2::Value::ToFunction(&method, &mfref, v4);
          Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
            v4,
            "\n!!! ExecuteEvent started '%s' = %p for %s\n",
            methodName.pNode->pData,
            v19->Function,
            v18);
          if ( (mfref.Flags & 2) == 0 )
          {
            if ( mfref.Function )
            {
              v20 = mfref.Function->RefCount;
              v21 = mfref.Function;
              if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v20) != 0 )
              {
                mfref.Function->RefCount = v20 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v21);
              }
            }
          }
          mfref.Function = 0;
          if ( (mfref.Flags & 1) == 0 )
          {
            if ( mfref.pLocalFrame )
            {
              v22 = mfref.pLocalFrame->RefCount;
              v23 = mfref.pLocalFrame;
              if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v22) != 0 )
              {
                mfref.pLocalFrame->RefCount = v22 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v23);
              }
            }
          }
        }
        v24 = (HINSTANCE__ *)id->Id;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[5049912] & id->Id) != 0
          || v24 == (HINSTANCE__ *)0x8000
          || v24 == &_sbh_sizeHeaderList
          || v24 == (HINSTANCE__ *)4096
          || v24 == (HINSTANCE__ *)2048
          || v24 == (HINSTANCE__ *)1024 )
        {
          AsciiCode = (Scaleform::GFx::AS2::LocalFrame *)id->AsciiCode;
          v26 = ++v4->Stack.pCurrent;
          p_pCurrent = &v4->Stack.pCurrent;
          LOBYTE(mfref.Function) = 4;
          mfref.pLocalFrame = AsciiCode;
          if ( v26 >= v4->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v4->Stack);
          if ( *p_pCurrent )
          {
            Scaleform::GFx::AS2::Value::Value(*p_pCurrent, (const Scaleform::GFx::AS2::Value *)&mfref);
            if ( LOBYTE(mfref.Function) >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&mfref);
          }
          nArgs = 1;
        }
        v28 = (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::Node *, Scaleform::GFx::XML::RootNode *))id->Id;
        if ( id->Id == 0x2000
          || v28 == (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::Node *, Scaleform::GFx::XML::RootNode *))0x4000
          || v28 == (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::Node *, Scaleform::GFx::XML::RootNode *))0x8000
          || (char *)v28 == (char *)&_sbh_sizeHeaderList
          || v28 == Scaleform::GFx::AS2::CreateShadow
          || (char *)v28 == (char *)&unk_800000 )
        {
          RollOverCnt = (Scaleform::GFx::AS2::LocalFrame *)id->RollOverCnt;
          LOBYTE(mfref.Function) = 4;
          mfref.pLocalFrame = RollOverCnt;
          p_Stack = &v4->Stack;
        }
        else
        {
          if ( v28 != (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::Node *, Scaleform::GFx::XML::RootNode *))1024
            && v28 != (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::Node *, Scaleform::GFx::XML::RootNode *))2048
            && v28 != (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::Node *, Scaleform::GFx::XML::RootNode *))((char *)&loc_7FFFE + 2)
            && v28 != (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::Node *, Scaleform::GFx::XML::RootNode *))((char *)&loc_FFFFF + 1) )
          {
            goto LABEL_80;
          }
          v29 = id->KeyCode == 0;
          LOBYTE(mfref.Function) = 4;
          p_Stack = &v4->Stack;
          if ( !v29 )
          {
            v31 = ++p_Stack->pCurrent;
            mfref.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)-1;
            if ( v31 >= v4->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v4->Stack);
            pCurrent = p_Stack->pCurrent;
            if ( !p_Stack->pCurrent )
              goto LABEL_79;
LABEL_77:
            Scaleform::GFx::AS2::Value::Value(pCurrent, (const Scaleform::GFx::AS2::Value *)&mfref);
            if ( LOBYTE(mfref.Function) >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&mfref);
LABEL_79:
            ++nArgs;
LABEL_80:
            v34 = id->ControllerIndex;
            if ( v34 >= 0 || nArgs )
            {
              ++v4->Stack.pCurrent;
              v35 = &v4->Stack.pCurrent;
              mfref.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)v34;
              v36 = v4->Stack.pCurrent;
              LOBYTE(mfref.Function) = 4;
              if ( v36 >= v4->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v4->Stack);
              if ( *v35 )
              {
                Scaleform::GFx::AS2::Value::Value(*v35, (const Scaleform::GFx::AS2::Value *)&mfref);
                if ( LOBYTE(mfref.Function) >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&mfref);
              }
              ++nArgs;
            }
            Scaleform::GFx::AS2::GAS_Invoke(
              &method,
              0,
              &this->Scaleform::GFx::AS2::ObjectInterface,
              v4,
              nArgs,
              v4->Stack.pCurrent - v4->Stack.pPageStart + 32 * v4->Stack.Pages.Data.Size - 32,
              methodName.pNode->pData);
            if ( nArgs )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&v4->Stack, nArgs);
LABEL_103:
            if ( (v4->Target->pASRoot->pMovieImpl->Flags & 4) != 0 )
            {
              v46 = this->pDispObj;
              v47 = v46->pNameHandle.pObject;
              if ( !v47 )
                v47 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v46);
              v48 = v47->NamePath.pNode->pData;
              v49 = Scaleform::GFx::AS2::Value::ToFunction(&method, &mfref, v4);
              Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
                v4,
                "!!! ExecuteEvent finished '%s' = %p for %s\n\n",
                methodName.pNode->pData,
                v49->Function,
                v48);
              if ( (mfref.Flags & 2) == 0 )
              {
                if ( mfref.Function )
                {
                  v50 = mfref.Function->RefCount;
                  v51 = mfref.Function;
                  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v50) != 0 )
                  {
                    mfref.Function->RefCount = v50 - 1;
                    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v51);
                  }
                }
              }
              mfref.Function = 0;
              if ( (mfref.Flags & 1) == 0 )
              {
                if ( mfref.pLocalFrame )
                {
                  v52 = mfref.pLocalFrame->RefCount;
                  v53 = mfref.pLocalFrame;
                  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v52) != 0 )
                  {
                    mfref.pLocalFrame->RefCount = v52 - 1;
                    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v53);
                  }
                }
              }
            }
            goto LABEL_114;
          }
          mfref.pLocalFrame = 0;
        }
        if ( ++p_Stack->pCurrent >= p_Stack->pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
        pCurrent = p_Stack->pCurrent;
        if ( !p_Stack->pCurrent )
          goto LABEL_79;
        goto LABEL_77;
      }
    }
  }
LABEL_114:
  pNode = methodName.pNode;
  v55 = handlerFoundCnt != 0;
  --methodName.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( method.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&method);
  if ( v61 )
    Scaleform::RefCountNTSImpl::Release(v61);
  if ( v62 )
    Scaleform::RefCountNTSImpl::Release(v62);
  return v55;
}
