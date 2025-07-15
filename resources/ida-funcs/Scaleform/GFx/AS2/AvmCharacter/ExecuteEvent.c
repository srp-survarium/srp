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
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // edi
  char v11; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v13; // ecx
  int v14; // eax
  unsigned int v15; // ecx
  Scaleform::GFx::InteractiveObject *v16; // ecx
  Scaleform::GFx::CharacterHandle *CharacterHandle; // eax
  const char *v18; // edi
  Scaleform::GFx::AS2::FunctionRef *v19; // eax
  int v20; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v21; // ecx
  int v22; // edx
  Scaleform::GFx::ASStringNode *v23; // ecx
  HINSTANCE__ *v24; // eax
  int AsciiCode; // edx
  Scaleform::GFx::AS2::Value *v26; // eax
  Scaleform::GFx::AS2::Value **p_pCurrent; // edi
  HINSTANCE__ *v28; // eax
  bool v29; // zf
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // edi
  Scaleform::GFx::AS2::Value *v31; // eax
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  int RollOverCnt; // ecx
  char v34; // al
  Scaleform::GFx::AS2::Value **v35; // edi
  Scaleform::GFx::AS2::Value *v36; // eax
  unsigned int Flags; // ecx
  Scaleform::GFx::InteractiveObject *v38; // ecx
  Scaleform::GFx::CharacterHandle *pObject; // eax
  const char *pData; // edi
  Scaleform::GFx::AS2::FunctionRef *v41; // eax
  int v42; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v43; // ecx
  int v44; // edx
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  Scaleform::GFx::InteractiveObject *v46; // ecx
  Scaleform::GFx::CharacterHandle *v47; // eax
  const char *v48; // edi
  Scaleform::GFx::AS2::FunctionRef *v49; // eax
  int v50; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v51; // ecx
  int v52; // edx
  Scaleform::GFx::ASStringNode *v53; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  bool v55; // bl
  int n; // [esp+Ch] [ebp-38h]
  Scaleform::GFx::ASString result; // [esp+14h] [ebp-30h] BYREF
  int v60; // [esp+18h] [ebp-2Ch]
  Scaleform::RefCountNTSImpl *v61; // [esp+1Ch] [ebp-28h]
  Scaleform::RefCountNTSImpl *v62; // [esp+20h] [ebp-24h]
  Scaleform::GFx::AS2::Value v; // [esp+24h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v64; // [esp+34h] [ebp-10h] BYREF
  bool evt; // [esp+48h] [ebp+4h]

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
  v60 = 0;
  v64.T.Type = 0;
  if ( Scaleform::GFx::AS2::AvmCharacter::HasClipEventHandler(this, id) && !id->RollOverCnt )
  {
    Scaleform::GFx::AS2::AvmCharacter::InvokeClipEventHandlers(this, v4, id);
    v60 = 1;
  }
  Scaleform::GFx::AS2::EventId_GetFunctionName(
    &result,
    (Scaleform::GFx::AS2::StringManager *)&v4->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
    id);
  if ( result.pNode->Size
    && this->GetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, &v4->StringContext, &result, &v64) )
  {
    if ( v64.T.Type == 9 )
    {
      v.T.Type = 0;
      Scaleform::GFx::AS2::Value::GetPropertyValue(&v64, v4, &this->Scaleform::GFx::AS2::ObjectInterface, &v);
      Scaleform::GFx::AS2::Value::operator=(&v64, &v);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
    }
    if ( v64.T.Type != 1 )
    {
      if ( v4->StringContext.pContext->GFxExtensions.Value != 1 )
      {
        if ( id->RollOverCnt )
          goto LABEL_114;
        Flags = v4->Target->pASRoot->pMovieImpl->Flags;
        ++v60;
        if ( (Flags & 4) != 0 )
        {
          v38 = this->pDispObj;
          pObject = v38->pNameHandle.pObject;
          if ( !pObject )
            pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v38);
          pData = pObject->NamePath.pNode->pData;
          v41 = Scaleform::GFx::AS2::Value::ToFunction(&v64, (Scaleform::GFx::AS2::FunctionRef *)&v, v4);
          Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
            v4,
            "\n!!! ExecuteEvent started '%s' = %p for %s\n",
            result.pNode->pData,
            v41->Function,
            pData);
          if ( (BYTE4(v.NV.NumberValue) & 2) == 0 )
          {
            if ( *(_DWORD *)&v.T.Type )
            {
              v42 = *(_DWORD *)(*(_DWORD *)&v.T.Type + 12);
              v43 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v.T.Type;
              if ( (v42 & 0x3FFFFFF) != 0 )
              {
                *(_DWORD *)(*(_DWORD *)&v.T.Type + 12) = v42 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v43);
              }
            }
          }
          *(_DWORD *)&v.T.Type = 0;
          if ( (BYTE4(v.NV.NumberValue) & 1) == 0 )
          {
            if ( v.NV.Int32Value )
            {
              v44 = *(_DWORD *)(v.NV.Int32Value + 12);
              pStringNode = v.V.pStringNode;
              if ( (v44 & 0x3FFFFFF) != 0 )
              {
                *(_DWORD *)(v.NV.Int32Value + 12) = v44 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
              }
            }
          }
        }
        Scaleform::GFx::AS2::GAS_Invoke(
          &v64,
          0,
          &this->Scaleform::GFx::AS2::ObjectInterface,
          v4,
          0,
          v4->Stack.pCurrent - v4->Stack.pPageStart + 32 * v4->Stack.Pages.Data.Size - 31,
          0);
        goto LABEL_103;
      }
      n = 0;
      evt = 1;
      if ( !id->RollOverCnt )
        goto LABEL_34;
      Scaleform::GFx::AS2::Value::ToFunction(&v64, (Scaleform::GFx::AS2::FunctionRef *)&v, v4);
      v10 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v.T.Type;
      if ( *(_DWORD *)&v.T.Type )
        evt = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&v.T.Type + 64))(*(_DWORD *)&v.T.Type) >= 2;
      v11 = BYTE4(v.NV.NumberValue);
      if ( (BYTE4(v.NV.NumberValue) & 2) == 0 )
      {
        if ( v10 )
        {
          RefCount = v10->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v10->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
          }
        }
      }
      if ( (v11 & 1) == 0 )
      {
        v13 = v.V.pStringNode;
        if ( v.NV.Int32Value )
        {
          v14 = *(_DWORD *)(v.NV.Int32Value + 12);
          if ( (v14 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)(v.NV.Int32Value + 12) = v14 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v13);
          }
        }
      }
      if ( evt )
      {
LABEL_34:
        v15 = v4->Target->pASRoot->pMovieImpl->Flags;
        ++v60;
        if ( (v15 & 4) != 0 )
        {
          v16 = this->pDispObj;
          CharacterHandle = v16->pNameHandle.pObject;
          if ( !CharacterHandle )
            CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v16);
          v18 = CharacterHandle->NamePath.pNode->pData;
          v19 = Scaleform::GFx::AS2::Value::ToFunction(&v64, (Scaleform::GFx::AS2::FunctionRef *)&v, v4);
          Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
            v4,
            "\n!!! ExecuteEvent started '%s' = %p for %s\n",
            result.pNode->pData,
            v19->Function,
            v18);
          if ( (BYTE4(v.NV.NumberValue) & 2) == 0 )
          {
            if ( *(_DWORD *)&v.T.Type )
            {
              v20 = *(_DWORD *)(*(_DWORD *)&v.T.Type + 12);
              v21 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v.T.Type;
              if ( (v20 & 0x3FFFFFF) != 0 )
              {
                *(_DWORD *)(*(_DWORD *)&v.T.Type + 12) = v20 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v21);
              }
            }
          }
          *(_DWORD *)&v.T.Type = 0;
          if ( (BYTE4(v.NV.NumberValue) & 1) == 0 )
          {
            if ( v.NV.Int32Value )
            {
              v22 = *(_DWORD *)(v.NV.Int32Value + 12);
              v23 = v.V.pStringNode;
              if ( (v22 & 0x3FFFFFF) != 0 )
              {
                *(_DWORD *)(v.NV.Int32Value + 12) = v22 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v23);
              }
            }
          }
        }
        v24 = (HINSTANCE__ *)id->Id;
        if ( (id->Id & 0xF80000) != 0
          || v24 == (HINSTANCE__ *)0x8000
          || v24 == &_sbh_sizeHeaderList
          || v24 == (HINSTANCE__ *)4096
          || v24 == (HINSTANCE__ *)2048
          || v24 == (HINSTANCE__ *)1024 )
        {
          AsciiCode = id->AsciiCode;
          v26 = ++v4->Stack.pCurrent;
          p_pCurrent = &v4->Stack.pCurrent;
          v.T.Type = 4;
          v.NV.Int32Value = AsciiCode;
          if ( v26 >= v4->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v4->Stack);
          if ( *p_pCurrent )
          {
            Scaleform::GFx::AS2::Value::Value(*p_pCurrent, &v);
            if ( v.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&v);
          }
          n = 1;
        }
        v28 = (HINSTANCE__ *)id->Id;
        if ( id->Id == 0x2000
          || v28 == (HINSTANCE__ *)0x4000
          || v28 == (HINSTANCE__ *)0x8000
          || v28 == &_sbh_sizeHeaderList
          || v28 == (HINSTANCE__ *)&loc_400000
          || v28 == (HINSTANCE__ *)"esource_ptr<class vostok::sound::sound_emitter,class vostok::resources::unmanaged_intrusive_base>,const class vostok::sound::sound_propagator_emitter &,class vostok::sound::world_user &)" )
        {
          RollOverCnt = id->RollOverCnt;
          v.T.Type = 4;
          v.NV.Int32Value = RollOverCnt;
          p_Stack = &v4->Stack;
        }
        else
        {
          if ( v28 != (HINSTANCE__ *)1024
            && v28 != (HINSTANCE__ *)2048
            && v28 != (HINSTANCE__ *)((char *)&loc_7FFFE + 2)
            && v28 != (HINSTANCE__ *)&loc_100000 )
          {
            goto LABEL_80;
          }
          v29 = id->KeyCode == 0;
          v.T.Type = 4;
          p_Stack = &v4->Stack;
          if ( !v29 )
          {
            v31 = ++p_Stack->pCurrent;
            v.NV.Int32Value = -1;
            if ( v31 >= v4->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v4->Stack);
            pCurrent = p_Stack->pCurrent;
            if ( !p_Stack->pCurrent )
              goto LABEL_79;
LABEL_77:
            Scaleform::GFx::AS2::Value::Value(pCurrent, &v);
            if ( v.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&v);
LABEL_79:
            ++n;
LABEL_80:
            v34 = id->ControllerIndex;
            if ( v34 >= 0 || n )
            {
              ++v4->Stack.pCurrent;
              v35 = &v4->Stack.pCurrent;
              v.NV.Int32Value = v34;
              v36 = v4->Stack.pCurrent;
              v.T.Type = 4;
              if ( v36 >= v4->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v4->Stack);
              if ( *v35 )
              {
                Scaleform::GFx::AS2::Value::Value(*v35, &v);
                if ( v.T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(&v);
              }
              ++n;
            }
            Scaleform::GFx::AS2::GAS_Invoke(
              &v64,
              0,
              &this->Scaleform::GFx::AS2::ObjectInterface,
              v4,
              n,
              v4->Stack.pCurrent - v4->Stack.pPageStart + 32 * v4->Stack.Pages.Data.Size - 32,
              result.pNode->pData);
            if ( n )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&v4->Stack, n);
LABEL_103:
            if ( (v4->Target->pASRoot->pMovieImpl->Flags & 4) != 0 )
            {
              v46 = this->pDispObj;
              v47 = v46->pNameHandle.pObject;
              if ( !v47 )
                v47 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v46);
              v48 = v47->NamePath.pNode->pData;
              v49 = Scaleform::GFx::AS2::Value::ToFunction(&v64, (Scaleform::GFx::AS2::FunctionRef *)&v, v4);
              Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
                v4,
                "!!! ExecuteEvent finished '%s' = %p for %s\n\n",
                result.pNode->pData,
                v49->Function,
                v48);
              if ( (BYTE4(v.NV.NumberValue) & 2) == 0 )
              {
                if ( *(_DWORD *)&v.T.Type )
                {
                  v50 = *(_DWORD *)(*(_DWORD *)&v.T.Type + 12);
                  v51 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v.T.Type;
                  if ( (v50 & 0x3FFFFFF) != 0 )
                  {
                    *(_DWORD *)(*(_DWORD *)&v.T.Type + 12) = v50 - 1;
                    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v51);
                  }
                }
              }
              *(_DWORD *)&v.T.Type = 0;
              if ( (BYTE4(v.NV.NumberValue) & 1) == 0 )
              {
                if ( v.NV.Int32Value )
                {
                  v52 = *(_DWORD *)(v.NV.Int32Value + 12);
                  v53 = v.V.pStringNode;
                  if ( (v52 & 0x3FFFFFF) != 0 )
                  {
                    *(_DWORD *)(v.NV.Int32Value + 12) = v52 - 1;
                    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v53);
                  }
                }
              }
            }
            goto LABEL_114;
          }
          v.NV.Int32Value = 0;
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
  pNode = result.pNode;
  v55 = v60 != 0;
  --result.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v64.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v64);
  if ( v61 )
    Scaleform::RefCountNTSImpl::Release(v61);
  if ( v62 )
    Scaleform::RefCountNTSImpl::Release(v62);
  return v55;
}
