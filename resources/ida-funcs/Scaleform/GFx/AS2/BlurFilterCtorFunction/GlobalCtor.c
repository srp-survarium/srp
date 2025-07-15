void __usercall Scaleform::GFx::AS2::BlurFilterCtorFunction::GlobalCtor(
        int a1@<ebx>,
        int a2@<edi>,
        float fn,
        int a4,
        char a5)
{
  const Scaleform::GFx::AS2::FnCall *v5; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::BitmapFilterObject *p_pProto; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::BlurFilterObject *v9; // eax
  Scaleform::GFx::AS2::BitmapFilterObject *v10; // eax
  _DWORD *v11; // edx
  Scaleform::GFx::AS2::Value *v12; // ecx
  Scaleform::Render::BlurFilterParams *v13; // eax
  Scaleform::GFx::AS2::Value *v14; // eax
  Scaleform::Render::BlurFilterParams *v15; // eax
  Scaleform::GFx::AS2::Value *v16; // eax
  unsigned int v17; // edi
  Scaleform::GFx::AS2::Environment *v18; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::ObjectInterface *v21; // edi
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::AS2::GlobalContext *v23; // eax
  Scaleform::GFx::ASStringNode *v24; // eax
  Scaleform::GFx::AS2::GlobalContext *v25; // eax
  Scaleform::GFx::ASStringNode *v26; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp+24h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *v29; // [esp+24h] [ebp-2Ch]
  __int64 v31; // [esp+38h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value v32; // [esp+40h] [ebp-10h] BYREF

  v5 = (const Scaleform::GFx::AS2::FnCall *)LODWORD(fn);
  if ( *(_DWORD *)(LODWORD(fn) + 8)
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(fn) + 8) + 8))(*(_DWORD *)(LODWORD(fn) + 8)) == 40 )
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
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Strength = 1.0;
  if ( v5->NArgs > 0 )
  {
    v11 = &v5->Env->__vftable;
    v12 = 0;
    if ( v5->FirstArgBottomIndex <= (unsigned int)(32 * (v11[6] - 1) + ((v11[1] - v11[2]) >> 4)) )
      v12 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)(v11[5] + 4 * ((unsigned int)v5->FirstArgBottomIndex >> 5))
                                         + 16 * (v5->FirstArgBottomIndex & 0x1F));
    fn = Scaleform::GFx::AS2::Value::ToNumber(v12, v5->Env);
    fn = fn * 20.0;
    v13 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
    v13->BlurX = fn;
    if ( v5->NArgs > 1 )
    {
      Env = v5->Env;
      v14 = Scaleform::GFx::AS2::FnCall::Arg(v5, 1);
      fn = Scaleform::GFx::AS2::Value::ToNumber(v14, Env);
      fn = fn * 20.0;
      v15 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
      v15->BlurY = fn;
      if ( v5->NArgs > 2 )
      {
        v29 = v5->Env;
        v16 = Scaleform::GFx::AS2::FnCall::Arg(v5, 2);
        v31 = (__int64)Scaleform::GFx::AS2::Value::ToNumber(v16, v29);
        v17 = v31;
        if ( (unsigned int)v31 >= 0xF )
          v17 = 15;
        Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Passes = v17;
      }
    }
  }
  v18 = v5->Env;
  pContext = v18->StringContext.pContext;
  p_StringContext = &v18->StringContext;
  LOBYTE(fn) = 0;
  v32.T.Type = 10;
  v21 = &p_pProto->Scaleform::GFx::AS2::ObjectInterface;
  LODWORD(v31) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "blurX",
                   5u,
                   0);
  ++*(_DWORD *)(v31 + 12);
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, __int64 *, Scaleform::GFx::AS2::Value *, float *, int, int))p_pProto->SetMemberRaw)(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    &v31,
    &v32,
    &fn,
    a2,
    a1);
  v22 = *(Scaleform::GFx::ASStringNode **)&v32.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v32.T.Type + 12);
  if ( !v22->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  if ( BYTE4(v32.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v32.NV.NumberValue + 4));
  v23 = p_StringContext->pContext;
  BYTE4(v32.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v32.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v23->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "blurY",
                             5u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v32.T.Type + 12);
  v21->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v32,
    (Scaleform::GFx::AS2::Value *)((char *)&v32.NV.NumberValue + 4),
    (const Scaleform::GFx::AS2::PropFlags *)&a5);
  v24 = *(Scaleform::GFx::ASStringNode **)&v32.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v32.T.Type + 12);
  if ( !v24->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  if ( BYTE4(v32.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v32.NV.NumberValue + 4));
  v25 = p_StringContext->pContext;
  BYTE4(v32.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v32.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v25->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "quality",
                             7u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v32.T.Type + 12);
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Value *))v21->SetMemberRaw)(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    &v32);
  v26 = (Scaleform::GFx::ASStringNode *)v31;
  --*(_DWORD *)(v31 + 12);
  if ( !v26->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  if ( v32.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v32);
  RefCount = p_pProto->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
  {
    p_pProto->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
  }
}
