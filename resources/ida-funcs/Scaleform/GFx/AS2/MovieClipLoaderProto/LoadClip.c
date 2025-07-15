void __cdecl Scaleform::GFx::AS2::MovieClipLoaderProto::LoadClip(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v5; // ecx
  Scaleform::GFx::AS2::Environment *v6; // ecx
  unsigned int v7; // eax
  Scaleform::GFx::AS2::Value *v8; // edx
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::InteractiveObject *v10; // eax
  Scaleform::RefCountNTSImpl *v11; // ebx
  Scaleform::GFx::AS2::Value *v12; // eax
  Scaleform::GFx::InteractiveObject *Target; // eax
  Scaleform::GFx::ASStringNode *v14; // ecx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *pNode; // ebp
  unsigned int Version; // eax
  Scaleform::GFx::AS2::Value *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // edi
  unsigned int v20; // eax
  unsigned int v21; // ebp
  Scaleform::GFx::ASStringNode *v22; // ecx
  const char *pData; // edi
  Scaleform::GFx::AS2::Value *v24; // eax
  Scaleform::GFx::ASStringNode *v25; // edi
  Scaleform::GFx::AS2::Value *v26; // esi
  const __m128i *v27; // [esp-18h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *v28; // [esp-14h] [ebp-28h]
  Scaleform::GFx::AS2::Environment *v29; // [esp-14h] [ebp-28h]
  Scaleform::GFx::AS2::Environment *v30; // [esp-14h] [ebp-28h]
  Scaleform::GFx::AS2::Environment *v31; // [esp-Ch] [ebp-20h]
  Scaleform::GFx::ASString v32; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::GFx::ASStringNode *v33; // [esp+Ch] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v34; // [esp+10h] [ebp-4h] BYREF
  Scaleform::GFx::AS2::FnCall *p_pProto; // [esp+18h] [ebp+4h]

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 2;
  Result->V.BooleanValue = 0;
  if ( fn->NArgs < 2 )
    return;
  p_pProto = 0;
  if ( fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_MovieClipLoader )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::FnCall *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
  }
  Env = fn->Env;
  v5 = 0;
  if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
    v5 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::ToStringImpl(v5, &v32, Env, -1, 0);
  v6 = fn->Env;
  v7 = fn->FirstArgBottomIndex - 1;
  v8 = 0;
  if ( v7 <= 32 * (v6->Stack.Pages.Data.Size - 1) + v6->Stack.pCurrent - v6->Stack.pPageStart )
    v8 = &v6->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
  if ( v8->T.Type == 7 )
  {
    v31 = fn->Env;
    v9 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
    v10 = Scaleform::GFx::AS2::Value::ToCharacter(v9, v31);
    if ( v10 )
      ++v10->RefCount;
    v11 = v10;
  }
  else
  {
    v28 = fn->Env;
    v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
    Scaleform::GFx::AS2::Value::ToStringImpl(v12, (Scaleform::GFx::ASString *)&v33, v28, -1, 0);
    Target = Scaleform::GFx::AS2::Environment::FindTarget(fn->Env, (const Scaleform::GFx::ASString *)&v33, 0);
    if ( Target )
      ++Target->RefCount;
    v14 = v33;
    v15 = v33->RefCount-- == 1;
    v11 = Target;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
  if ( v11 )
  {
    pNode = v32.pNode;
    Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
      (Scaleform::GFx::AS2::MovieRoot *)fn->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      (Scaleform::String)v11,
      (const __m128i *)v32.pNode->pData,
      LM_None,
      (Scaleform::GFx::AS2::MovieClipLoader *)p_pProto);
LABEL_27:
    v26 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v26);
    v26->T.Type = 2;
    v26->V.BooleanValue = 1;
    if ( v11 )
      Scaleform::RefCountNTSImpl::Release(v11);
    v15 = pNode->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  Version = Scaleform::GFx::DisplayObjectBase::GetVersion(fn->Env->Target);
  v29 = fn->Env;
  LOBYTE(v34) = Version > 6;
  v18 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
  Scaleform::GFx::AS2::Value::ToStringImpl(v18, (Scaleform::GFx::ASString *)&v33, v29, -1, 0);
  v19 = v33;
  v20 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName((const char *)v34, 0, v33->pData, (const char **)&v34, (bool)v34);
  v15 = v19->RefCount-- == 1;
  v21 = v20;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( v21 != -1 )
  {
    pNode = v32.pNode;
    pData = v32.pNode->pData;
    v30 = fn->Env;
    v24 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
    Scaleform::GFx::AS2::Value::ToStringImpl(v24, (Scaleform::GFx::ASString *)&v34, v30, -1, 0);
    v27 = (const __m128i *)pData;
    v25 = v34;
    Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
      (Scaleform::GFx::AS2::MovieRoot *)fn->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      (Scaleform::String)v34->pData,
      v27,
      (Scaleform::String)fn->Env,
      LM_None,
      (Scaleform::GFx::AS2::MovieClipLoader *)p_pProto);
    v15 = v25->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    goto LABEL_27;
  }
  v22 = v32.pNode;
  v15 = v32.pNode->RefCount-- == 1;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
}
