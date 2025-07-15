double __usercall Scaleform::GFx::AS2::DropShadowFilterCtorFunction::GlobalCtor@<st0>(int a1@<ebx>, float fn, char a3)
{
  Scaleform::GFx::AS2::FnCall *v3; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::BitmapFilterObject *p_pProto; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::DropShadowFilterObject *v7; // eax
  Scaleform::GFx::AS2::BitmapFilterObject *v8; // eax
  Scaleform::Render::BlurFilterParams *v9; // eax
  unsigned __int8 Alpha; // cl
  double result; // st7
  Scaleform::Render::BlurFilterParams *v12; // eax
  Scaleform::Render::BlurFilterParams *v13; // eax
  Scaleform::GFx::AS2::Environment *Env; // edx
  int v15; // ecx
  unsigned int FirstArgBottomIndex; // eax
  Scaleform::GFx::AS2::Value *v17; // eax
  Scaleform::GFx::AS2::Value *v18; // eax
  Scaleform::GFx::AS2::Value *v19; // eax
  int v20; // edi
  Scaleform::Render::BlurFilterParams *v21; // eax
  unsigned __int8 v22; // cl
  Scaleform::GFx::AS2::Value *v23; // eax
  Scaleform::GFx::AS2::Value *v24; // eax
  Scaleform::GFx::AS2::Value *v25; // eax
  Scaleform::GFx::AS2::Value *v26; // eax
  Scaleform::Render::BlurFilterParams *v27; // eax
  Scaleform::GFx::AS2::Value *v28; // eax
  Scaleform::GFx::AS2::Value *v29; // eax
  bool v30; // al
  Scaleform::GFx::AS2::Value *v31; // eax
  bool v32; // al
  Scaleform::GFx::AS2::Value *v33; // eax
  bool v34; // al
  Scaleform::GFx::AS2::Environment *v35; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::ObjectInterface *v38; // edi
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
  Scaleform::GFx::AS2::GlobalContext *v50; // eax
  Scaleform::GFx::ASStringNode *v51; // eax
  Scaleform::GFx::AS2::GlobalContext *v52; // eax
  Scaleform::GFx::ASStringNode *v53; // eax
  Scaleform::GFx::AS2::GlobalContext *v54; // eax
  Scaleform::GFx::ASStringNode *v55; // eax
  Scaleform::GFx::AS2::GlobalContext *v56; // eax
  Scaleform::GFx::ASStringNode *v57; // eax
  Scaleform::GFx::AS2::GlobalContext *v58; // eax
  Scaleform::GFx::ASStringNode *v59; // eax
  unsigned int RefCount; // eax
  float d; // [esp+A4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *da; // [esp+A4h] [ebp-2Ch]
  float db; // [esp+A4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *dc; // [esp+A4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *dd; // [esp+A4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *de; // [esp+A4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *df; // [esp+A4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *dg; // [esp+A4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *dh; // [esp+A4h] [ebp-2Ch]
  const Scaleform::GFx::AS2::Environment *di; // [esp+A4h] [ebp-2Ch]
  const Scaleform::GFx::AS2::Environment *dj; // [esp+A4h] [ebp-2Ch]
  const Scaleform::GFx::AS2::Environment *dk; // [esp+A4h] [ebp-2Ch]
  __int64 v73; // [esp+B8h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value v74; // [esp+C0h] [ebp-10h] BYREF

  v3 = (Scaleform::GFx::AS2::FnCall *)LODWORD(fn);
  if ( *(_DWORD *)(LODWORD(fn) + 8)
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(fn) + 8) + 8))(*(_DWORD *)(LODWORD(fn) + 8)) == 38 )
  {
    ThisPtr = v3->ThisPtr;
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
    pHeap = v3->Env->StringContext.pContext->pHeap;
    v7 = (Scaleform::GFx::AS2::DropShadowFilterObject *)pHeap->Alloc(pHeap, 56u, 0);
    if ( v7 )
      Scaleform::GFx::AS2::DropShadowFilterObject::DropShadowFilterObject(v7, v3->Env);
    else
      v8 = 0;
    p_pProto = v8;
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v3->Result, p_pProto);
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Passes = 1;
  Scaleform::GFx::AS2::BitmapFilterObject::SetDistance(p_pProto, 4.0);
  Scaleform::GFx::AS2::BitmapFilterObject::SetAngle(p_pProto, 45.0);
  v9 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
  Alpha = v9->Colors[0].Channels.Alpha;
  v9->Colors[0].Raw = 0;
  v9->Colors[0].Channels.Alpha = Alpha;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Colors[0].Channels.Alpha = -1;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->BlurX = 80.0;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->BlurY = 80.0;
  result = 1.0;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Strength = 1.0;
  v12 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
  v12->Mode &= ~0x10u;
  v13 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
  v13->Mode &= ~0x40u;
  if ( v3->NArgs > 0 )
  {
    Env = v3->Env;
    v15 = (char *)Env->Stack.pCurrent - (char *)Env->Stack.pPageStart;
    FirstArgBottomIndex = v3->FirstArgBottomIndex;
    fn = 0.0;
    v17 = FirstArgBottomIndex > 32 * (Env->Stack.Pages.Data.Size - 1) + (v15 >> 4)
        ? (Scaleform::GFx::AS2::Value *)LODWORD(fn)
        : &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    LODWORD(fn) = (__int16)Scaleform::GFx::AS2::Value::ToInt32(v17, Env);
    result = (double)SLODWORD(fn);
    d = result;
    Scaleform::GFx::AS2::BitmapFilterObject::SetDistance(p_pProto, d);
    if ( v3->NArgs > 1 )
    {
      da = v3->Env;
      v18 = Scaleform::GFx::AS2::FnCall::Arg(v3, 1);
      LODWORD(fn) = (__int16)Scaleform::GFx::AS2::Value::ToInt32(v18, da);
      result = (double)SLODWORD(fn);
      db = result;
      Scaleform::GFx::AS2::BitmapFilterObject::SetAngle(p_pProto, db);
      if ( v3->NArgs > 2 )
      {
        dc = v3->Env;
        v19 = Scaleform::GFx::AS2::FnCall::Arg(v3, 2);
        v20 = Scaleform::GFx::AS2::Value::ToUInt32(v19, dc);
        v21 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
        v22 = v21->Colors[0].Channels.Alpha;
        v21->Colors[0].Raw = v20;
        v21->Colors[0].Channels.Alpha = v22;
        if ( v3->NArgs > 3 )
        {
          dd = v3->Env;
          v23 = Scaleform::GFx::AS2::FnCall::Arg(v3, 3);
          fn = Scaleform::GFx::AS2::Value::ToNumber(v23, dd);
          result = fn;
          Scaleform::GFx::AS2::BitmapFilterObject::SetAlpha(p_pProto, fn);
          if ( v3->NArgs > 4 )
          {
            de = v3->Env;
            v24 = Scaleform::GFx::AS2::FnCall::Arg(v3, 4);
            fn = Scaleform::GFx::AS2::Value::ToNumber(v24, de);
            result = fn;
            Scaleform::GFx::AS2::BitmapFilterObject::SetBlurX(p_pProto, fn);
            if ( v3->NArgs > 5 )
            {
              df = v3->Env;
              v25 = Scaleform::GFx::AS2::FnCall::Arg(v3, 5);
              fn = Scaleform::GFx::AS2::Value::ToNumber(v25, df);
              result = fn;
              Scaleform::GFx::AS2::BitmapFilterObject::SetBlurY(p_pProto, fn);
              if ( v3->NArgs > 6 )
              {
                dg = v3->Env;
                v26 = Scaleform::GFx::AS2::FnCall::Arg(v3, 6);
                fn = Scaleform::GFx::AS2::Value::ToNumber(v26, dg);
                v27 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
                result = fn;
                v27->Strength = fn;
                if ( v3->NArgs > 7 )
                {
                  dh = v3->Env;
                  v28 = Scaleform::GFx::AS2::FnCall::Arg(v3, 7);
                  result = Scaleform::GFx::AS2::Value::ToNumber(v28, dh);
                  v73 = (__int64)result;
                  Scaleform::GFx::AS2::BitmapFilterObject::SetPasses(p_pProto, (__int64)result);
                  if ( v3->NArgs > 8 )
                  {
                    di = v3->Env;
                    v29 = Scaleform::GFx::AS2::FnCall::Arg(v3, 8);
                    v30 = Scaleform::GFx::AS2::Value::ToBool(v29, v20, di);
                    Scaleform::GFx::AS2::BitmapFilterObject::SetInnerShadow(p_pProto, v30);
                    if ( v3->NArgs > 9 )
                    {
                      dj = v3->Env;
                      v31 = Scaleform::GFx::AS2::FnCall::Arg(v3, 9);
                      v32 = Scaleform::GFx::AS2::Value::ToBool(v31, v20, dj);
                      Scaleform::GFx::AS2::BitmapFilterObject::SetKnockOut(p_pProto, v32);
                      if ( v3->NArgs > 10 )
                      {
                        dk = v3->Env;
                        v33 = Scaleform::GFx::AS2::FnCall::Arg(v3, 10);
                        v34 = Scaleform::GFx::AS2::Value::ToBool(v33, v20, dk);
                        Scaleform::GFx::AS2::BitmapFilterObject::SetHideObject(p_pProto, v34);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  v35 = v3->Env;
  pContext = v35->StringContext.pContext;
  p_StringContext = &v35->StringContext;
  v74.T.Type = 10;
  LOBYTE(fn) = 0;
  v38 = &p_pProto->Scaleform::GFx::AS2::ObjectInterface;
  LODWORD(v73) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "distance",
                   8u,
                   0);
  ++*(_DWORD *)(v73 + 12);
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, __int64 *, Scaleform::GFx::AS2::Value *, float *, int))p_pProto->SetMemberRaw)(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    &v73,
    &v74,
    &fn,
    a1);
  v39 = (Scaleform::GFx::ASStringNode *)HIDWORD(v73);
  --*(_DWORD *)(HIDWORD(v73) + 12);
  if ( !v39->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v39);
  if ( v74.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v74.NV.4);
  v40 = p_StringContext->pContext;
  v74.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v73) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v40->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "angle",
                   5u,
                   0);
  ++*(_DWORD *)(HIDWORD(v73) + 12);
  v38->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v73 + 1,
    (const Scaleform::GFx::AS2::Value *)&v74.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v41 = (Scaleform::GFx::ASStringNode *)HIDWORD(v73);
  --*(_DWORD *)(HIDWORD(v73) + 12);
  if ( !v41->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v41);
  if ( v74.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v74.NV.4);
  v42 = p_StringContext->pContext;
  v74.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v73) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v42->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "color",
                   5u,
                   0);
  ++*(_DWORD *)(HIDWORD(v73) + 12);
  v38->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v73 + 1,
    (const Scaleform::GFx::AS2::Value *)&v74.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v43 = (Scaleform::GFx::ASStringNode *)HIDWORD(v73);
  --*(_DWORD *)(HIDWORD(v73) + 12);
  if ( !v43->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
  if ( v74.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v74.NV.4);
  v44 = p_StringContext->pContext;
  v74.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v73) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v44->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "alpha",
                   5u,
                   0);
  ++*(_DWORD *)(HIDWORD(v73) + 12);
  v38->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v73 + 1,
    (const Scaleform::GFx::AS2::Value *)&v74.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v45 = (Scaleform::GFx::ASStringNode *)HIDWORD(v73);
  --*(_DWORD *)(HIDWORD(v73) + 12);
  if ( !v45->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v45);
  if ( v74.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v74.NV.4);
  v46 = p_StringContext->pContext;
  v74.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v73) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v46->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "blurX",
                   5u,
                   0);
  ++*(_DWORD *)(HIDWORD(v73) + 12);
  v38->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v73 + 1,
    (const Scaleform::GFx::AS2::Value *)&v74.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v47 = (Scaleform::GFx::ASStringNode *)HIDWORD(v73);
  --*(_DWORD *)(HIDWORD(v73) + 12);
  if ( !v47->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v47);
  if ( v74.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v74.NV.4);
  v48 = p_StringContext->pContext;
  v74.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v73) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v48->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "blurY",
                   5u,
                   0);
  ++*(_DWORD *)(HIDWORD(v73) + 12);
  v38->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v73 + 1,
    (const Scaleform::GFx::AS2::Value *)&v74.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v49 = (Scaleform::GFx::ASStringNode *)HIDWORD(v73);
  --*(_DWORD *)(HIDWORD(v73) + 12);
  if ( !v49->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v49);
  if ( v74.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v74.NV.4);
  v50 = p_StringContext->pContext;
  v74.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v73) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v50->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "strength",
                   8u,
                   0);
  ++*(_DWORD *)(HIDWORD(v73) + 12);
  v38->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v73 + 1,
    (const Scaleform::GFx::AS2::Value *)&v74.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v51 = (Scaleform::GFx::ASStringNode *)HIDWORD(v73);
  --*(_DWORD *)(HIDWORD(v73) + 12);
  if ( !v51->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v51);
  if ( v74.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v74.NV.4);
  v52 = p_StringContext->pContext;
  v74.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v73) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v52->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "knockout",
                   8u,
                   0);
  ++*(_DWORD *)(HIDWORD(v73) + 12);
  v38->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v73 + 1,
    (const Scaleform::GFx::AS2::Value *)&v74.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v53 = (Scaleform::GFx::ASStringNode *)HIDWORD(v73);
  --*(_DWORD *)(HIDWORD(v73) + 12);
  if ( !v53->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v53);
  if ( v74.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v74.NV.4);
  v54 = p_StringContext->pContext;
  v74.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v73) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v54->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "hideObject",
                   0xAu,
                   0);
  ++*(_DWORD *)(HIDWORD(v73) + 12);
  v38->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v73 + 1,
    (const Scaleform::GFx::AS2::Value *)&v74.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v55 = (Scaleform::GFx::ASStringNode *)HIDWORD(v73);
  --*(_DWORD *)(HIDWORD(v73) + 12);
  if ( !v55->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v55);
  if ( v74.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v74.NV.4);
  v56 = p_StringContext->pContext;
  v74.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v73) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v56->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "inner",
                   5u,
                   0);
  ++*(_DWORD *)(HIDWORD(v73) + 12);
  v38->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v73 + 1,
    (const Scaleform::GFx::AS2::Value *)&v74.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v57 = (Scaleform::GFx::ASStringNode *)HIDWORD(v73);
  --*(_DWORD *)(HIDWORD(v73) + 12);
  if ( !v57->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v57);
  if ( v74.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v74.NV.4);
  v58 = p_StringContext->pContext;
  v74.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v73) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v58->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "quality",
                   7u,
                   0);
  ++*(_DWORD *)(HIDWORD(v73) + 12);
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, char *, $B8BD913BABC9324639AA48504BEFB2FC *))v38->SetMemberRaw)(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (char *)&v73 + 4,
    &v74.NV.4);
  v59 = (Scaleform::GFx::ASStringNode *)v73;
  --*(_DWORD *)(v73 + 12);
  if ( !v59->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v59);
  if ( v74.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v74);
  RefCount = p_pProto->RefCount;
  if ( (RefCount & 0x3FFFFFF) != 0 )
  {
    p_pProto->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
  }
  return result;
}
