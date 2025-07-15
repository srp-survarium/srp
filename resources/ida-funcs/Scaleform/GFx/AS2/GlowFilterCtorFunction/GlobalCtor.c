long double __usercall Scaleform::GFx::AS2::GlowFilterCtorFunction::GlobalCtor@<st0>(
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
  Scaleform::GFx::AS2::GlowFilterObject *v9; // eax
  Scaleform::GFx::AS2::BitmapFilterObject *v10; // eax
  Scaleform::Render::BlurFilterParams *v11; // eax
  unsigned __int8 Alpha; // cl
  long double result; // st7
  Scaleform::Render::BlurFilterParams *v14; // eax
  Scaleform::Render::BlurFilterParams *v15; // eax
  _DWORD *v16; // eax
  Scaleform::GFx::AS2::Value *v17; // ecx
  int v18; // edi
  Scaleform::Render::BlurFilterParams *v19; // eax
  unsigned __int8 v20; // cl
  Scaleform::GFx::AS2::Value *v21; // eax
  Scaleform::GFx::AS2::Value *v22; // eax
  Scaleform::Render::BlurFilterParams *v23; // eax
  Scaleform::GFx::AS2::Value *v24; // eax
  Scaleform::GFx::AS2::Value *v25; // eax
  Scaleform::Render::BlurFilterParams *v26; // eax
  Scaleform::GFx::AS2::Value *v27; // eax
  Scaleform::GFx::AS2::Value *v28; // eax
  bool v29; // al
  Scaleform::GFx::AS2::Value *v30; // eax
  bool v31; // al
  Scaleform::GFx::AS2::Environment *Env; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::ObjectInterface *v35; // edi
  Scaleform::GFx::ASStringNode *v36; // eax
  Scaleform::GFx::AS2::GlobalContext *v37; // eax
  Scaleform::GFx::ASStringNode *v38; // eax
  Scaleform::GFx::AS2::GlobalContext *v39; // eax
  Scaleform::GFx::ASStringNode *v40; // eax
  Scaleform::GFx::AS2::GlobalContext *v41; // eax
  Scaleform::GFx::ASStringNode *v42; // eax
  Scaleform::GFx::AS2::GlobalContext *v43; // eax
  Scaleform::GFx::ASStringNode *v44; // eax
  Scaleform::GFx::AS2::GlobalContext *v45; // eax
  Scaleform::GFx::ASStringNode *v46; // eax
  Scaleform::GFx::AS2::GlobalContext *v47; // eax
  Scaleform::GFx::ASStringNode *v48; // eax
  Scaleform::GFx::AS2::GlobalContext *v49; // eax
  Scaleform::GFx::ASStringNode *v50; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *d; // [esp+74h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *da; // [esp+74h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *db; // [esp+74h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *dc; // [esp+74h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *dd; // [esp+74h] [ebp-2Ch]
  const Scaleform::GFx::AS2::Environment *de; // [esp+74h] [ebp-2Ch]
  const Scaleform::GFx::AS2::Environment *df; // [esp+74h] [ebp-2Ch]
  __int64 v60; // [esp+88h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value v61; // [esp+90h] [ebp-10h] BYREF

  v5 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_GlowFilter )
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
  v11->Colors[0].Raw = 16711680;
  v11->Colors[0].Channels.Alpha = Alpha;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Colors[0].Channels.Alpha = -1;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->BlurX = 120.0;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->BlurY = 120.0;
  result = 2.0;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Strength = 2.0;
  v14 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
  v14->Mode &= ~0x10u;
  v15 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
  v15->Mode &= ~0x40u;
  if ( v5->NArgs > 0 )
  {
    v16 = &v5->Env->__vftable;
    v17 = 0;
    if ( v5->FirstArgBottomIndex <= (unsigned int)(32 * (v16[6] - 1) + ((v16[1] - v16[2]) >> 4)) )
      v17 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)(v16[5] + 4 * ((unsigned int)v5->FirstArgBottomIndex >> 5))
                                         + 16 * (v5->FirstArgBottomIndex & 0x1F));
    v18 = Scaleform::GFx::AS2::Value::ToUInt32(v17, v5->Env);
    v19 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
    v20 = v19->Colors[0].Channels.Alpha;
    v19->Colors[0].Raw = v18;
    v19->Colors[0].Channels.Alpha = v20;
    if ( v5->NArgs > 1 )
    {
      d = v5->Env;
      v21 = Scaleform::GFx::AS2::FnCall::Arg(v5, 1);
      *(float *)&fn = Scaleform::GFx::AS2::Value::ToNumber(v21, d);
      result = *(float *)&fn;
      Scaleform::GFx::AS2::BitmapFilterObject::SetAlpha(p_pProto, *(float *)&fn);
      if ( v5->NArgs > 2 )
      {
        da = v5->Env;
        v22 = Scaleform::GFx::AS2::FnCall::Arg(v5, 2);
        *(float *)&fn = Scaleform::GFx::AS2::Value::ToNumber(v22, da);
        *(float *)&fn = *(float *)&fn * 20.0;
        v23 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
        result = *(float *)&fn;
        v23->BlurX = *(float *)&fn;
        if ( v5->NArgs > 3 )
        {
          db = v5->Env;
          v24 = Scaleform::GFx::AS2::FnCall::Arg(v5, 3);
          *(float *)&fn = Scaleform::GFx::AS2::Value::ToNumber(v24, db);
          result = *(float *)&fn;
          Scaleform::GFx::AS2::BitmapFilterObject::SetBlurY(p_pProto, *(float *)&fn);
          if ( v5->NArgs > 4 )
          {
            dc = v5->Env;
            v25 = Scaleform::GFx::AS2::FnCall::Arg(v5, 4);
            *(float *)&fn = Scaleform::GFx::AS2::Value::ToNumber(v25, dc);
            v26 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
            result = *(float *)&fn;
            v26->Strength = *(float *)&fn;
            if ( v5->NArgs > 5 )
            {
              dd = v5->Env;
              v27 = Scaleform::GFx::AS2::FnCall::Arg(v5, 5);
              result = Scaleform::GFx::AS2::Value::ToNumber(v27, dd);
              v60 = (__int64)result;
              Scaleform::GFx::AS2::BitmapFilterObject::SetPasses(p_pProto, (__int64)result);
              if ( v5->NArgs > 6 )
              {
                de = v5->Env;
                v28 = Scaleform::GFx::AS2::FnCall::Arg(v5, 6);
                v29 = Scaleform::GFx::AS2::Value::ToBool(v28, v18, de);
                Scaleform::GFx::AS2::BitmapFilterObject::SetInnerShadow(p_pProto, v29);
                if ( v5->NArgs > 7 )
                {
                  df = v5->Env;
                  v30 = Scaleform::GFx::AS2::FnCall::Arg(v5, 7);
                  v31 = Scaleform::GFx::AS2::Value::ToBool(v30, v18, df);
                  Scaleform::GFx::AS2::BitmapFilterObject::SetKnockOut(p_pProto, v31);
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
  v61.T.Type = 10;
  v35 = &p_pProto->Scaleform::GFx::AS2::ObjectInterface;
  LODWORD(v60) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "color",
                   5u,
                   0);
  ++*(_DWORD *)(v60 + 12);
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, __int64 *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::FnCall **, int, int))p_pProto->SetMemberRaw)(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    &v60,
    &v61,
    &fn,
    a2,
    a1);
  v36 = *(Scaleform::GFx::ASStringNode **)&v61.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v61.T.Type + 12);
  if ( !v36->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v36);
  if ( BYTE4(v61.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v61.NV.NumberValue + 4));
  v37 = p_StringContext->pContext;
  BYTE4(v61.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v61.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v37->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "alpha",
                             5u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v61.T.Type + 12);
  v35->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v61,
    (Scaleform::GFx::AS2::Value *)((char *)&v61.NV.NumberValue + 4),
    (const Scaleform::GFx::AS2::PropFlags *)&a5);
  v38 = *(Scaleform::GFx::ASStringNode **)&v61.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v61.T.Type + 12);
  if ( !v38->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  if ( BYTE4(v61.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v61.NV.NumberValue + 4));
  v39 = p_StringContext->pContext;
  BYTE4(v61.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v61.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v39->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "blurX",
                             5u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v61.T.Type + 12);
  v35->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v61,
    (Scaleform::GFx::AS2::Value *)((char *)&v61.NV.NumberValue + 4),
    (const Scaleform::GFx::AS2::PropFlags *)&a5);
  v40 = *(Scaleform::GFx::ASStringNode **)&v61.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v61.T.Type + 12);
  if ( !v40->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v40);
  if ( BYTE4(v61.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v61.NV.NumberValue + 4));
  v41 = p_StringContext->pContext;
  BYTE4(v61.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v61.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v41->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "blurY",
                             5u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v61.T.Type + 12);
  v35->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v61,
    (Scaleform::GFx::AS2::Value *)((char *)&v61.NV.NumberValue + 4),
    (const Scaleform::GFx::AS2::PropFlags *)&a5);
  v42 = *(Scaleform::GFx::ASStringNode **)&v61.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v61.T.Type + 12);
  if ( !v42->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v42);
  if ( BYTE4(v61.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v61.NV.NumberValue + 4));
  v43 = p_StringContext->pContext;
  BYTE4(v61.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v61.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v43->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "strength",
                             8u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v61.T.Type + 12);
  v35->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v61,
    (Scaleform::GFx::AS2::Value *)((char *)&v61.NV.NumberValue + 4),
    (const Scaleform::GFx::AS2::PropFlags *)&a5);
  v44 = *(Scaleform::GFx::ASStringNode **)&v61.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v61.T.Type + 12);
  if ( !v44->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v44);
  if ( BYTE4(v61.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v61.NV.NumberValue + 4));
  v45 = p_StringContext->pContext;
  BYTE4(v61.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v61.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v45->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "knockout",
                             8u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v61.T.Type + 12);
  v35->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v61,
    (Scaleform::GFx::AS2::Value *)((char *)&v61.NV.NumberValue + 4),
    (const Scaleform::GFx::AS2::PropFlags *)&a5);
  v46 = *(Scaleform::GFx::ASStringNode **)&v61.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v61.T.Type + 12);
  if ( !v46->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v46);
  if ( BYTE4(v61.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v61.NV.NumberValue + 4));
  v47 = p_StringContext->pContext;
  BYTE4(v61.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v61.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v47->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "inner",
                             5u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v61.T.Type + 12);
  v35->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v61,
    (Scaleform::GFx::AS2::Value *)((char *)&v61.NV.NumberValue + 4),
    (const Scaleform::GFx::AS2::PropFlags *)&a5);
  v48 = *(Scaleform::GFx::ASStringNode **)&v61.T.Type;
  --*(_DWORD *)(*(_DWORD *)&v61.T.Type + 12);
  if ( !v48->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v48);
  if ( BYTE4(v61.NV.NumberValue) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v61.NV.NumberValue + 4));
  v49 = p_StringContext->pContext;
  BYTE4(v61.NV.NumberValue) = 10;
  a5 = 0;
  *(_DWORD *)&v61.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                             (Scaleform::GFx::ASStringManager *)v49->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             "quality",
                             7u,
                             0);
  ++*(_DWORD *)(*(_DWORD *)&v61.T.Type + 12);
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Value *))v35->SetMemberRaw)(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    &v61);
  v50 = (Scaleform::GFx::ASStringNode *)v60;
  --*(_DWORD *)(v60 + 12);
  if ( !v50->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v50);
  if ( v61.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v61);
  RefCount = p_pProto->RefCount;
  if ( (RefCount & 0x3FFFFFF) != 0 )
  {
    p_pProto->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
  }
  return result;
}
