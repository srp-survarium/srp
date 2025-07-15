void __usercall Scaleform::GFx::AS2::GlowFilterCtorFunction::GlobalCtor(
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
  Scaleform::GFx::AS2::GlowFilterObject *v9; // eax
  Scaleform::GFx::AS2::BitmapFilterObject *v10; // eax
  Scaleform::Render::BlurFilterParams *v11; // eax
  unsigned __int8 Alpha; // cl
  Scaleform::Render::BlurFilterParams *v13; // eax
  Scaleform::Render::BlurFilterParams *v14; // eax
  _DWORD *v15; // eax
  Scaleform::GFx::AS2::Value *v16; // ecx
  unsigned int v17; // edi
  Scaleform::Render::BlurFilterParams *v18; // eax
  unsigned __int8 v19; // cl
  Scaleform::GFx::AS2::Value *v20; // eax
  Scaleform::GFx::AS2::Value *v21; // eax
  Scaleform::Render::BlurFilterParams *v22; // eax
  Scaleform::GFx::AS2::Value *v23; // eax
  Scaleform::GFx::AS2::Value *v24; // eax
  Scaleform::Render::BlurFilterParams *v25; // eax
  Scaleform::GFx::AS2::Value *v26; // eax
  Scaleform::GFx::AS2::Value *v27; // eax
  char v28; // al
  Scaleform::GFx::AS2::Value *v29; // eax
  char v30; // al
  Scaleform::GFx::AS2::Environment *Env; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::ObjectInterface *v34; // edi
  Scaleform::GFx::ASStringNode *v35; // eax
  Scaleform::GFx::AS2::GlobalContext *v36; // eax
  Scaleform::GFx::ASStringNode *v37; // eax
  Scaleform::GFx::AS2::GlobalContext *v38; // eax
  Scaleform::GFx::ASStringNode *v39; // eax
  Scaleform::GFx::AS2::GlobalContext *v40; // eax
  Scaleform::GFx::ASStringNode *v41; // eax
  Scaleform::GFx::AS2::GlobalContext *v42; // eax
  Scaleform::GFx::ASStringNode *v43; // eax
  Scaleform::GFx::AS2::GlobalContext *v44; // eax
  Scaleform::GFx::ASStringNode *v45; // eax
  Scaleform::GFx::AS2::GlobalContext *v46; // eax
  Scaleform::GFx::ASStringNode *v47; // eax
  Scaleform::GFx::AS2::GlobalContext *v48; // eax
  Scaleform::GFx::ASStringNode *v49; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *d; // [esp+74h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *da; // [esp+74h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *db; // [esp+74h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *dc; // [esp+74h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *dd; // [esp+74h] [ebp-2Ch]
  const Scaleform::GFx::AS2::Environment *de; // [esp+74h] [ebp-2Ch]
  const Scaleform::GFx::AS2::Environment *df; // [esp+74h] [ebp-2Ch]
  __int64 v59; // [esp+88h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value v60; // [esp+90h] [ebp-10h] BYREF

  v5 = (const Scaleform::GFx::AS2::FnCall *)LODWORD(fn);
  if ( *(_DWORD *)(LODWORD(fn) + 8)
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(fn) + 8) + 8))(*(_DWORD *)(LODWORD(fn) + 8)) == 39 )
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
    v9 = (Scaleform::GFx::AS2::GlowFilterObject *)pHeap->Alloc(pHeap, 56u, 0);
    if ( v9 )
      Scaleform::GFx::AS2::GlowFilterObject::GlowFilterObject(v9, v5->Env);
    else
      v10 = 0;
    p_pProto = v10;
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v5->Result, p_pProto);
  Scaleform::GFx::AS2::BitmapFilterObject::SetDistance(p_pProto, 0.0);
  Scaleform::GFx::AS2::BitmapFilterObject::SetAngle(p_pProto, 0.0);
  v11 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
  Alpha = v11->Colors[0].Channels.Alpha;
  v11->Colors[0].Raw = (unsigned int)&vostok::memory::s_CRT_arena[5508664];
  v11->Colors[0].Channels.Alpha = Alpha;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Colors[0].Channels.Alpha = -1;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->BlurX = 120.0;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->BlurY = 120.0;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Strength = 2.0;
  v13 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
  v13->Mode &= ~0x10u;
  v14 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
  v14->Mode &= ~0x40u;
  if ( v5->NArgs > 0 )
  {
    v15 = &v5->Env->__vftable;
    v16 = 0;
    if ( v5->FirstArgBottomIndex <= (unsigned int)(32 * (v15[6] - 1) + ((v15[1] - v15[2]) >> 4)) )
      v16 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)(v15[5] + 4 * ((unsigned int)v5->FirstArgBottomIndex >> 5))
                                         + 16 * (v5->FirstArgBottomIndex & 0x1F));
    v17 = Scaleform::GFx::AS2::Value::ToUInt32(v16, v5->Env);
    v18 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
    v19 = v18->Colors[0].Channels.Alpha;
    v18->Colors[0].Raw = v17;
    v18->Colors[0].Channels.Alpha = v19;
    if ( v5->NArgs > 1 )
    {
      d = v5->Env;
      v20 = Scaleform::GFx::AS2::FnCall::Arg(v5, 1);
      fn = Scaleform::GFx::AS2::Value::ToNumber(v20, d);
      Scaleform::GFx::AS2::BitmapFilterObject::SetAlpha(p_pProto, fn);
      if ( v5->NArgs > 2 )
      {
        da = v5->Env;
        v21 = Scaleform::GFx::AS2::FnCall::Arg(v5, 2);
        fn = Scaleform::GFx::AS2::Value::ToNumber(v21, da);
        fn = fn * 20.0;
        v22 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
        v22->BlurX = fn;
        if ( v5->NArgs > 3 )
        {
          db = v5->Env;
          v23 = Scaleform::GFx::AS2::FnCall::Arg(v5, 3);
          fn = Scaleform::GFx::AS2::Value::ToNumber(v23, db);
          Scaleform::GFx::AS2::BitmapFilterObject::SetBlurY(p_pProto, fn);
          if ( v5->NArgs > 4 )
          {
            dc = v5->Env;
            v24 = Scaleform::GFx::AS2::FnCall::Arg(v5, 4);
            fn = Scaleform::GFx::AS2::Value::ToNumber(v24, dc);
            v25 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
            v25->Strength = fn;
            if ( v5->NArgs > 5 )
            {
              dd = v5->Env;
              v26 = Scaleform::GFx::AS2::FnCall::Arg(v5, 5);
              v59 = (__int64)Scaleform::GFx::AS2::Value::ToNumber(v26, dd);
              Scaleform::GFx::AS2::BitmapFilterObject::SetPasses(p_pProto, v59);
              if ( v5->NArgs > 6 )
              {
                de = v5->Env;
                v27 = Scaleform::GFx::AS2::FnCall::Arg(v5, 6);
                v28 = Scaleform::GFx::AS2::Value::ToBool(v27, de);
                Scaleform::GFx::AS2::BitmapFilterObject::SetInnerShadow(p_pProto, v28);
                if ( v5->NArgs > 7 )
                {
                  df = v5->Env;
                  v29 = Scaleform::GFx::AS2::FnCall::Arg(v5, 7);
                  v30 = Scaleform::GFx::AS2::Value::ToBool(v29, df);
                  Scaleform::GFx::AS2::BitmapFilterObject::SetKnockOut(p_pProto, v30);
                }
              }
            }
          }
        }
      }
    }
  }
  Env = v5->Env;
  pContext = Env->StringContext.pContext;
  p_StringContext = &Env->StringContext;
  LOBYTE(fn) = 0;
  v60.T.Type = 10;
  v34 = &p_pProto->Scaleform::GFx::AS2::ObjectInterface;
  LODWORD(v59) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   (char *)&stru_9555EC,
                   5u,
                   0);
  ++*(_DWORD *)(v59 + 12);
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, __int64 *, Scaleform::GFx::AS2::Value *, float *, int, int))p_pProto->SetMemberRaw)(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    &v59,
    &v60,
    &fn,
    a2,
    a1);
  v35 = *(Scaleform::GFx::ASStringNode **)&v60.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v60.T.Type + 12);
  if ( !v35->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  if ( BYTE4(v60.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v60.NV.NumberValue + 4));
  v36 = p_StringContext->pContext;
  BYTE4(v60.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v60.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v36->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "alpha",
                             5u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v60.T.Type + 12);
  v34->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v60,
    (Scaleform::GFx::AS2::Value *)((char *)&v60.NV.NumberValue + 4),
    (const Scaleform::GFx::AS2::PropFlags *)&a5);
  v37 = *(Scaleform::GFx::ASStringNode **)&v60.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v60.T.Type + 12);
  if ( !v37->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  if ( BYTE4(v60.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v60.NV.NumberValue + 4));
  v38 = p_StringContext->pContext;
  BYTE4(v60.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v60.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v38->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "blurX",
                             5u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v60.T.Type + 12);
  v34->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v60,
    (Scaleform::GFx::AS2::Value *)((char *)&v60.NV.NumberValue + 4),
    (const Scaleform::GFx::AS2::PropFlags *)&a5);
  v39 = *(Scaleform::GFx::ASStringNode **)&v60.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v60.T.Type + 12);
  if ( !v39->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v39);
  if ( BYTE4(v60.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v60.NV.NumberValue + 4));
  v40 = p_StringContext->pContext;
  BYTE4(v60.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v60.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v40->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "blurY",
                             5u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v60.T.Type + 12);
  v34->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v60,
    (Scaleform::GFx::AS2::Value *)((char *)&v60.NV.NumberValue + 4),
    (const Scaleform::GFx::AS2::PropFlags *)&a5);
  v41 = *(Scaleform::GFx::ASStringNode **)&v60.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v60.T.Type + 12);
  if ( !v41->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v41);
  if ( BYTE4(v60.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v60.NV.NumberValue + 4));
  v42 = p_StringContext->pContext;
  BYTE4(v60.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v60.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v42->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "strength",
                             8u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v60.T.Type + 12);
  v34->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v60,
    (Scaleform::GFx::AS2::Value *)((char *)&v60.NV.NumberValue + 4),
    (const Scaleform::GFx::AS2::PropFlags *)&a5);
  v43 = *(Scaleform::GFx::ASStringNode **)&v60.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v60.T.Type + 12);
  if ( !v43->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
  if ( BYTE4(v60.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v60.NV.NumberValue + 4));
  v44 = p_StringContext->pContext;
  BYTE4(v60.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v60.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v44->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "knockout",
                             8u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v60.T.Type + 12);
  v34->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v60,
    (Scaleform::GFx::AS2::Value *)((char *)&v60.NV.NumberValue + 4),
    (const Scaleform::GFx::AS2::PropFlags *)&a5);
  v45 = *(Scaleform::GFx::ASStringNode **)&v60.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v60.T.Type + 12);
  if ( !v45->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v45);
  if ( BYTE4(v60.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v60.NV.NumberValue + 4));
  v46 = p_StringContext->pContext;
  BYTE4(v60.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v60.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v46->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "inner",
                             5u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v60.T.Type + 12);
  v34->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v60,
    (Scaleform::GFx::AS2::Value *)((char *)&v60.NV.NumberValue + 4),
    (const Scaleform::GFx::AS2::PropFlags *)&a5);
  v47 = *(Scaleform::GFx::ASStringNode **)&v60.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v60.T.Type + 12);
  if ( !v47->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v47);
  if ( BYTE4(v60.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v60.NV.NumberValue + 4));
  v48 = p_StringContext->pContext;
  BYTE4(v60.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v60.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v48->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "quality",
                             7u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v60.T.Type + 12);
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Value *))v34->SetMemberRaw)(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    &v60);
  v49 = (Scaleform::GFx::ASStringNode *)v59;
  --*(_DWORD *)(v59 + 12);
  if ( !v49->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v49);
  if ( v60.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v60);
  RefCount = p_pProto->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
  {
    p_pProto->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
  }
}
