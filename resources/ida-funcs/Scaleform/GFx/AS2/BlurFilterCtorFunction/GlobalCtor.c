long double __usercall Scaleform::GFx::AS2::BlurFilterCtorFunction::GlobalCtor@<st0>(
        int a1@<ebx>,
        int a2@<edi>,
        Scaleform::GFx::AS2::FnCall *fn,
        int a4,
        char a5)
{
  Scaleform::GFx::AS2::FnCall *v5; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::BitmapFilterObject *p_pProto; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::BlurFilterObject *v9; // eax
  Scaleform::GFx::AS2::BitmapFilterObject *v10; // eax
  long double result; // st7
  _DWORD *v12; // edx
  Scaleform::GFx::AS2::Value *v13; // ecx
  Scaleform::Render::BlurFilterParams *v14; // eax
  Scaleform::GFx::AS2::Value *v15; // eax
  Scaleform::Render::BlurFilterParams *v16; // eax
  Scaleform::GFx::AS2::Value *v17; // eax
  unsigned int v18; // edi
  Scaleform::GFx::AS2::Environment *v19; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::ObjectInterface *v22; // edi
  Scaleform::GFx::ASStringNode *v23; // eax
  Scaleform::GFx::AS2::GlobalContext *v24; // eax
  Scaleform::GFx::ASStringNode *v25; // eax
  Scaleform::GFx::AS2::GlobalContext *v26; // eax
  Scaleform::GFx::ASStringNode *v27; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp+24h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *v30; // [esp+24h] [ebp-2Ch]
  __int64 v32; // [esp+38h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value v33; // [esp+40h] [ebp-10h] BYREF

  v5 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_BlurFilter )
  {
    ThisPtr = v5->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::BitmapFilterObject *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
        p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      p_pProto = 0;
    }
  }
  else
  {
    pHeap = v5->Env->StringContext.pContext->pHeap;
    v9 = (Scaleform::GFx::AS2::BlurFilterObject *)pHeap->Alloc(pHeap, 56u, 0);
    if ( v9 )
      Scaleform::GFx::AS2::BlurFilterObject::BlurFilterObject(v9, v5->Env);
    else
      v10 = 0;
    p_pProto = v10;
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v5->Result, p_pProto);
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Colors[0].Channels.Alpha = -1;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->BlurX = 80.0;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->BlurY = 80.0;
  result = 1.0;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Strength = 1.0;
  if ( v5->NArgs > 0 )
  {
    v12 = &v5->Env->__vftable;
    v13 = 0;
    if ( v5->FirstArgBottomIndex <= (unsigned int)(32 * (v12[6] - 1) + ((v12[1] - v12[2]) >> 4)) )
      v13 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)(v12[5] + 4 * ((unsigned int)v5->FirstArgBottomIndex >> 5))
                                         + 16 * (v5->FirstArgBottomIndex & 0x1F));
    *(float *)&fn = Scaleform::GFx::AS2::Value::ToNumber(v13, v5->Env);
    *(float *)&fn = *(float *)&fn * 20.0;
    v14 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
    result = *(float *)&fn;
    v14->BlurX = *(float *)&fn;
    if ( v5->NArgs > 1 )
    {
      Env = v5->Env;
      v15 = Scaleform::GFx::AS2::FnCall::Arg(v5, 1);
      *(float *)&fn = Scaleform::GFx::AS2::Value::ToNumber(v15, Env);
      *(float *)&fn = *(float *)&fn * 20.0;
      v16 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
      result = *(float *)&fn;
      v16->BlurY = *(float *)&fn;
      if ( v5->NArgs > 2 )
      {
        v30 = v5->Env;
        v17 = Scaleform::GFx::AS2::FnCall::Arg(v5, 2);
        result = Scaleform::GFx::AS2::Value::ToNumber(v17, v30);
        v32 = (__int64)result;
        v18 = (__int64)result;
        if ( v18 >= 0xF )
          v18 = 15;
        Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Passes = v18;
      }
    }
  }
  v19 = v5->Env;
  pContext = v19->StringContext.pContext;
  p_StringContext = &v19->StringContext;
  LOBYTE(fn) = 0;
  v33.T.Type = 10;
  v22 = &p_pProto->Scaleform::GFx::AS2::ObjectInterface;
  LODWORD(v32) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "blurX",
                   5u,
                   0);
  ++*(_DWORD *)(v32 + 12);
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, __int64 *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::FnCall **, int, int))p_pProto->SetMemberRaw)(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    &v32,
    &v33,
    &fn,
    a2,
    a1);
  v23 = *(Scaleform::GFx::ASStringNode **)&v33.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v33.T.Type + 12);
  if ( !v23->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  if ( BYTE4(v33.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v33.NV.NumberValue + 4));
  v24 = p_StringContext->pContext;
  BYTE4(v33.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v33.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v24->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "blurY",
                             5u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v33.T.Type + 12);
  v22->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v33,
    (Scaleform::GFx::AS2::Value *)((char *)&v33.NV.NumberValue + 4),
    (const Scaleform::GFx::AS2::PropFlags *)&a5);
  v25 = *(Scaleform::GFx::ASStringNode **)&v33.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v33.T.Type + 12);
  if ( !v25->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  if ( BYTE4(v33.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v33.NV.NumberValue + 4));
  v26 = p_StringContext->pContext;
  BYTE4(v33.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v33.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v26->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "quality",
                             7u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v33.T.Type + 12);
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Value *))v22->SetMemberRaw)(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    &v33);
  v27 = (Scaleform::GFx::ASStringNode *)v32;
  --*(_DWORD *)(v32 + 12);
  if ( !v27->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  if ( v33.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v33);
  RefCount = p_pProto->RefCount;
  if ( (RefCount & 0x3FFFFFF) != 0 )
  {
    p_pProto->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
  }
  return result;
}
