void __cdecl Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::AddCallback(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  _DWORD *v3; // eax
  Scaleform::GFx::AS2::Value *v4; // ecx
  const Scaleform::GFx::AS2::Environment *Env; // edx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::Value *v7; // ecx
  _DWORD *v8; // ecx
  unsigned int v9; // eax
  Scaleform::GFx::CharacterHandle *v10; // edi
  Scaleform::GFx::AS2::Object *v11; // ebp
  _BYTE *v12; // eax
  Scaleform::GFx::AS2::Value *v13; // eax
  Scaleform::GFx::InteractiveObject *v14; // eax
  Scaleform::GFx::DisplayObject *v15; // ebx
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::AS2::Value *v17; // eax
  Scaleform::GFx::AS2::Object *v18; // eax
  Scaleform::GFx::AS2::Value *v19; // esi
  unsigned int RefCount; // eax
  unsigned __int8 Flags; // bl
  Scaleform::GFx::AS2::FunctionObject *v22; // ecx
  unsigned int v23; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v25; // eax
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::GFx::AS2::Environment *v27; // [esp-Ch] [ebp-28h]
  Scaleform::GFx::MovieImpl *proot; // [esp+Ch] [ebp-10h]
  Scaleform::GFx::AS2::FunctionRef function; // [esp+10h] [ebp-Ch] BYREF

  v1 = fn;
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  if ( v1->NArgs >= 3 )
  {
    v3 = &v1->Env->__vftable;
    proot = *(Scaleform::GFx::MovieImpl **)(*(_DWORD *)(v3[28] + 16) + 8);
    v4 = 0;
    if ( v1->FirstArgBottomIndex <= (unsigned int)(32 * (v3[6] - 1) + ((v3[1] - v3[2]) >> 4)) )
      v4 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)(v3[5] + 4 * ((unsigned int)v1->FirstArgBottomIndex >> 5))
                                        + 16 * (v1->FirstArgBottomIndex & 0x1F));
    Scaleform::GFx::AS2::Value::ToStringImpl(v4, (Scaleform::GFx::ASString *)&fn, v1->Env, -1, 0);
    Env = v1->Env;
    v6 = v1->FirstArgBottomIndex - 2;
    v7 = 0;
    if ( v6 <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v7 = &Env->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    Scaleform::GFx::AS2::Value::ToFunction(v7, &function, Env);
    v8 = &v1->Env->__vftable;
    v9 = v1->FirstArgBottomIndex - 1;
    v10 = 0;
    v11 = 0;
    if ( v9 > 32 * (v8[6] - 1) + ((v8[1] - v8[2]) >> 4) )
      v12 = 0;
    else
      v12 = (_BYTE *)(*(_DWORD *)(v8[5] + 4 * (v9 >> 5)) + 16 * (v9 & 0x1F));
    v27 = v1->Env;
    if ( *v12 == 7 )
    {
      v13 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      v14 = Scaleform::GFx::AS2::Value::ToCharacter(v13, v27);
      v15 = v14;
      if ( v14 )
      {
        ++v14->RefCount;
        pObject = v14->pNameHandle.pObject;
        if ( pObject || (pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v15)) != 0 )
          ++pObject->RefCount;
        v10 = pObject;
        Scaleform::RefCountNTSImpl::Release(v15);
      }
    }
    else
    {
      v17 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      v18 = Scaleform::GFx::AS2::Value::ToObject(v17, v27);
      if ( v18 )
        v18->RefCount = (v18->RefCount + 1) & 0x8FFFFFFF;
      v11 = v18;
    }
    Scaleform::GFx::AS2::MovieRoot::AddInvokeAlias(
      (Scaleform::GFx::AS2::MovieRoot *)proot->pASMovieRoot.pObject,
      (const Scaleform::GFx::ASString *)&fn,
      v10,
      v11,
      &function);
    v19 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v19);
    v19->T.Type = 2;
    v19->V.BooleanValue = 1;
    if ( v11 )
    {
      RefCount = v11->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v11->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
      }
    }
    if ( v10 )
    {
      if ( --v10->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v10);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
      }
    }
    Flags = function.Flags;
    if ( (function.Flags & 2) == 0 )
    {
      v22 = function.Function;
      if ( function.Function )
      {
        v23 = function.Function->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v23) != 0 )
        {
          function.Function->RefCount = v23 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v22);
        }
      }
    }
    if ( (Flags & 1) == 0 )
    {
      pLocalFrame = function.pLocalFrame;
      if ( function.pLocalFrame )
      {
        v25 = function.pLocalFrame->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v25) != 0 )
        {
          function.pLocalFrame->RefCount = v25 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
    v26 = (Scaleform::GFx::ASStringNode *)fn;
    --fn->ThisFunctionRef.Function;
    if ( !v26->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  }
}
