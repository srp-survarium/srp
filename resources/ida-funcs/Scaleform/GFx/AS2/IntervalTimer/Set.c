void __cdecl Scaleform::GFx::AS2::IntervalTimer::Set(Scaleform::GFx::ASString fn, bool timeout)
{
  Scaleform::GFx::AS2::FnCall *pNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // edi
  char v4; // bl
  _DWORD *v5; // eax
  int v6; // ebp
  unsigned int FirstArgBottomIndex; // ecx
  unsigned int v8; // edx
  _BYTE *v9; // ecx
  Scaleform::GFx::AS2::IntervalTimer *v10; // edi
  Scaleform::GFx::AS2::Value *v11; // eax
  const Scaleform::GFx::AS2::FunctionRef *v12; // eax
  int v13; // eax
  int v14; // ebp
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v17; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  Scaleform::GFx::AS2::IntervalTimer *v19; // edi
  Scaleform::GFx::AS2::Value *v20; // eax
  Scaleform::GFx::AS2::Value *v21; // eax
  Scaleform::GFx::AS2::Object *v22; // eax
  int v23; // eax
  bool v24; // zf
  Scaleform::GFx::AS2::IntervalTimer *v25; // edi
  Scaleform::GFx::AS2::Value *v26; // eax
  Scaleform::GFx::AS2::Value *v27; // eax
  Scaleform::GFx::InteractiveObject *v28; // eax
  int v29; // eax
  Scaleform::GFx::ASStringNode *v30; // ecx
  Scaleform::GFx::InteractiveObject *Target; // ecx
  Scaleform::GFx::DisplayObject *v32; // eax
  Scaleform::GFx::CharacterHandle *pObject; // ebx
  Scaleform::GFx::CharacterHandle *v34; // edi
  Scaleform::GFx::ASStringNode *v35; // edi
  Scaleform::GFx::AS2::Value *v36; // eax
  unsigned __int64 v37; // rax
  char *v38; // edi
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *v39; // ebp
  _DWORD *v40; // ecx
  int v41; // edx
  int v42; // ebx
  _DWORD *v43; // ecx
  unsigned int v44; // eax
  Scaleform::GFx::ASStringNode *v45; // ebx
  int Size; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // edi
  Scaleform::GFx::ASStringNode *v48; // eax
  Scaleform::GFx::AS2::Value *v49; // esi
  bool v50; // cf
  long double v51; // st7
  Scaleform::GFx::AS2::Environment *v52; // [esp-Ch] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *v53; // [esp-Ch] [ebp-2Ch]
  const Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-28h]
  Scaleform::GFx::AS2::Environment *v55; // [esp-8h] [ebp-28h]
  const Scaleform::GFx::AS2::Environment *v56; // [esp-8h] [ebp-28h]
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // [esp-4h] [ebp-24h]
  int v58; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS2::FunctionRef result; // [esp+14h] [ebp-Ch] BYREF

  pNode = (Scaleform::GFx::AS2::FnCall *)fn.pNode;
  pManager = fn.pNode->pManager;
  v4 = 0;
  Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)pManager);
  LOBYTE(pManager->__vftable) = 0;
  if ( pNode->NArgs >= 2 )
  {
    v5 = &pNode->Env->__vftable;
    v6 = *(_DWORD *)(v5[29] + 24);
    FirstArgBottomIndex = pNode->FirstArgBottomIndex;
    v8 = 32 * (v5[6] - 1) + ((v5[1] - v5[2]) >> 4);
    fn.pNode = (Scaleform::GFx::ASStringNode *)1;
    if ( FirstArgBottomIndex > v8 )
      v9 = 0;
    else
      v9 = (_BYTE *)(*(_DWORD *)(v5[5] + 4 * (FirstArgBottomIndex >> 5)) + 16 * (FirstArgBottomIndex & 0x1F));
    if ( *v9 == 8 || *v9 == 11 )
    {
      v10 = (Scaleform::GFx::AS2::IntervalTimer *)(*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v6 + 40))(
                                                    v6,
                                                    80,
                                                    0);
      if ( v10 )
      {
        p_StringContext = &pNode->Env->StringContext;
        Env = pNode->Env;
        v4 = 1;
        v11 = Scaleform::GFx::AS2::FnCall::Arg(pNode, 0);
        v12 = Scaleform::GFx::AS2::Value::ToFunction(v11, &result, Env);
        Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(v10, v12, p_StringContext);
      }
      else
      {
        v13 = 0;
      }
      v14 = v13;
      v58 = v13;
      if ( (v4 & 1) != 0 )
      {
        if ( (result.Flags & 2) == 0 )
        {
          if ( result.Function )
          {
            RefCount = result.Function->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              Function = result.Function;
              result.Function->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
            }
          }
        }
        result.Function = 0;
        if ( (result.Flags & 1) == 0 )
        {
          if ( result.pLocalFrame )
          {
            v17 = result.pLocalFrame->RefCount;
            pLocalFrame = result.pLocalFrame;
            if ( (v17 & 0x3FFFFFF) != 0 )
            {
              result.pLocalFrame->RefCount = v17 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
            }
          }
        }
        result.pLocalFrame = 0;
      }
    }
    else
    {
      if ( Scaleform::GFx::AS2::FnCall::Arg(pNode, 0)->T.Type == 6 )
      {
        v19 = (Scaleform::GFx::AS2::IntervalTimer *)(*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v6 + 40))(
                                                      v6,
                                                      80,
                                                      0);
        if ( v19 )
        {
          v52 = pNode->Env;
          v20 = Scaleform::GFx::AS2::FnCall::Arg(pNode, 1);
          Scaleform::GFx::AS2::Value::ToStringImpl(v20, &fn, v52, -1, 0);
          v55 = pNode->Env;
          v21 = Scaleform::GFx::AS2::FnCall::Arg(pNode, 0);
          v22 = Scaleform::GFx::AS2::Value::ToObject(v21, v55);
          Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(v19, v22, &fn);
          v14 = v23;
          v58 = v23;
          v24 = 0;
        }
        else
        {
          v14 = 0;
          v58 = 0;
          v24 = 1;
        }
      }
      else
      {
        if ( Scaleform::GFx::AS2::FnCall::Arg(pNode, 0)->T.Type != 7 )
          return;
        v25 = (Scaleform::GFx::AS2::IntervalTimer *)(*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v6 + 40))(
                                                      v6,
                                                      80,
                                                      0);
        if ( v25 )
        {
          v53 = pNode->Env;
          v4 = 4;
          v26 = Scaleform::GFx::AS2::FnCall::Arg(pNode, 1);
          Scaleform::GFx::AS2::Value::ToStringImpl(v26, &fn, v53, -1, 0);
          v56 = pNode->Env;
          v27 = Scaleform::GFx::AS2::FnCall::Arg(pNode, 0);
          v28 = Scaleform::GFx::AS2::Value::ToCharacter(v27, v56);
          Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(v25, v28, &fn);
        }
        else
        {
          v29 = 0;
        }
        v14 = v29;
        v58 = v29;
        v24 = (v4 & 4) == 0;
      }
      if ( !v24 )
      {
        v30 = fn.pNode;
        v24 = fn.pNode->RefCount-- == 1;
        if ( v24 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v30);
      }
      fn.pNode = (Scaleform::GFx::ASStringNode *)2;
    }
    if ( pNode->NArgs > (int)fn.pNode )
    {
      Target = pNode->Env->Target;
      if ( Target )
      {
        v32 = Target->GetTopParent(Target, 0);
        if ( v32->pNameHandle.pObject )
          pObject = v32->pNameHandle.pObject;
        else
          pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v32);
        if ( pObject )
          ++pObject->RefCount;
        v34 = *(Scaleform::GFx::CharacterHandle **)(v14 + 68);
        if ( v34 )
        {
          if ( --v34->RefCount <= 0 )
          {
            Scaleform::GFx::CharacterHandle::~CharacterHandle(v34);
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v34);
          }
        }
        *(_DWORD *)(v14 + 68) = pObject;
      }
      v35 = fn.pNode;
      v36 = Scaleform::GFx::AS2::FnCall::Arg(pNode, (int)fn.pNode);
      v37 = 1000 * (unsigned __int64)Scaleform::GFx::AS2::Value::ToNumber(v36, pNode->Env);
      *(_DWORD *)(v14 + 52) = HIDWORD(v37);
      BYTE4(v37) = timeout;
      v38 = (char *)&v35->pData + 1;
      *(_DWORD *)(v14 + 48) = v37;
      *(_BYTE *)(v14 + 73) = BYTE4(v37);
      if ( (int)v38 < pNode->NArgs )
      {
        v39 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *)(v14 + 32);
        do
        {
          v40 = &pNode->Env->__vftable;
          v41 = v40[1] - v40[2];
          v42 = v40[6];
          v43 = v40 + 1;
          v44 = pNode->FirstArgBottomIndex - (_DWORD)v38;
          fn.pNode = 0;
          if ( v44 > 32 * (v42 - 1) + (v41 >> 4) )
            v45 = fn.pNode;
          else
            v45 = (Scaleform::GFx::ASStringNode *)(*(_DWORD *)(v43[4] + 4 * (v44 >> 5)) + 16 * (v44 & 0x1F));
          Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            v39,
            v39,
            v39->Size + 1);
          Size = v39->Size;
          if ( &v39->Data[Size] != (Scaleform::GFx::AS2::Value *)16 )
            Scaleform::GFx::AS2::Value::Value(&v39->Data[Size - 1], (const Scaleform::GFx::AS2::Value *)v45);
          ++v38;
        }
        while ( (int)v38 < pNode->NArgs );
        v14 = v58;
      }
      pMovieImpl = pNode->Env->Target->pASRoot->pMovieImpl;
      v48 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::MovieImpl::AddIntervalTimer(
                                              pMovieImpl,
                                              (Scaleform::GFx::Resource *)v14);
      v49 = pNode->Result;
      v50 = v49->T.Type < 5u;
      fn.pNode = v48;
      if ( !v50 )
        Scaleform::GFx::AS2::Value::DropRefs(v49);
      v51 = (double)(int)fn.pNode;
      v49->T.Type = 3;
      v49->NV.NumberValue = v51;
      (*(void (__thiscall **)(int, Scaleform::GFx::MovieImpl *))(*(_DWORD *)v14 + 4))(v14, pMovieImpl);
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v14);
    }
    else if ( v14 )
    {
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v14);
    }
  }
}
