void __usercall Scaleform::GFx::AS2::DropShadowFilterCtorFunction::GlobalCtor(int a1@<ebx>, float fn, char a3)
{
  const Scaleform::GFx::AS2::FnCall *v3; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::BitmapFilterObject *p_pProto; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::DropShadowFilterObject *v7; // eax
  Scaleform::GFx::AS2::BitmapFilterObject *v8; // eax
  Scaleform::Render::BlurFilterParams *v9; // eax
  unsigned __int8 Alpha; // cl
  Scaleform::Render::BlurFilterParams *v11; // eax
  Scaleform::Render::BlurFilterParams *v12; // eax
  Scaleform::GFx::AS2::Environment *Env; // edx
  int v14; // ecx
  unsigned int FirstArgBottomIndex; // eax
  Scaleform::GFx::AS2::Value *v16; // eax
  Scaleform::GFx::AS2::Value *v17; // eax
  Scaleform::GFx::AS2::Value *v18; // eax
  unsigned int v19; // edi
  Scaleform::Render::BlurFilterParams *v20; // eax
  unsigned __int8 v21; // cl
  Scaleform::GFx::AS2::Value *v22; // eax
  Scaleform::GFx::AS2::Value *v23; // eax
  Scaleform::GFx::AS2::Value *v24; // eax
  Scaleform::GFx::AS2::Value *v25; // eax
  Scaleform::Render::BlurFilterParams *v26; // eax
  Scaleform::GFx::AS2::Value *v27; // eax
  Scaleform::GFx::AS2::Value *v28; // eax
  char v29; // al
  Scaleform::GFx::AS2::Value *v30; // eax
  char v31; // al
  Scaleform::GFx::AS2::Value *v32; // eax
  char v33; // al
  Scaleform::GFx::AS2::Environment *v34; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::ObjectInterface *v37; // edi
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
  Scaleform::GFx::AS2::GlobalContext *v51; // eax
  Scaleform::GFx::ASStringNode *v52; // eax
  Scaleform::GFx::AS2::GlobalContext *v53; // eax
  Scaleform::GFx::ASStringNode *v54; // eax
  Scaleform::GFx::AS2::GlobalContext *v55; // eax
  Scaleform::GFx::ASStringNode *v56; // eax
  Scaleform::GFx::AS2::GlobalContext *v57; // eax
  Scaleform::GFx::ASStringNode *v58; // eax
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
  __int64 v72; // [esp+B8h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value v73; // [esp+C0h] [ebp-10h] BYREF

  v3 = (const Scaleform::GFx::AS2::FnCall *)LODWORD(fn);
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
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Strength = 1.0;
  v11 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
  v11->Mode &= ~0x10u;
  v12 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
  v12->Mode &= ~0x40u;
  if ( v3->NArgs > 0 )
  {
    Env = v3->Env;
    v14 = (char *)Env->Stack.pCurrent - (char *)Env->Stack.pPageStart;
    FirstArgBottomIndex = v3->FirstArgBottomIndex;
    fn = 0.0;
    v16 = FirstArgBottomIndex > 32 * (Env->Stack.Pages.Data.Size - 1) + (v14 >> 4)
        ? (Scaleform::GFx::AS2::Value *)LODWORD(fn)
        : &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    LODWORD(fn) = (__int16)Scaleform::GFx::AS2::Value::ToInt32(v16, Env);
    d = (float)SLODWORD(fn);
    Scaleform::GFx::AS2::BitmapFilterObject::SetDistance(p_pProto, d);
    if ( v3->NArgs > 1 )
    {
      da = v3->Env;
      v17 = Scaleform::GFx::AS2::FnCall::Arg(v3, 1);
      LODWORD(fn) = (__int16)Scaleform::GFx::AS2::Value::ToInt32(v17, da);
      db = (float)SLODWORD(fn);
      Scaleform::GFx::AS2::BitmapFilterObject::SetAngle(p_pProto, db);
      if ( v3->NArgs > 2 )
      {
        dc = v3->Env;
        v18 = Scaleform::GFx::AS2::FnCall::Arg(v3, 2);
        v19 = Scaleform::GFx::AS2::Value::ToUInt32(v18, dc);
        v20 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
        v21 = v20->Colors[0].Channels.Alpha;
        v20->Colors[0].Raw = v19;
        v20->Colors[0].Channels.Alpha = v21;
        if ( v3->NArgs > 3 )
        {
          dd = v3->Env;
          v22 = Scaleform::GFx::AS2::FnCall::Arg(v3, 3);
          fn = Scaleform::GFx::AS2::Value::ToNumber(v22, dd);
          Scaleform::GFx::AS2::BitmapFilterObject::SetAlpha(p_pProto, fn);
          if ( v3->NArgs > 4 )
          {
            de = v3->Env;
            v23 = Scaleform::GFx::AS2::FnCall::Arg(v3, 4);
            fn = Scaleform::GFx::AS2::Value::ToNumber(v23, de);
            Scaleform::GFx::AS2::BitmapFilterObject::SetBlurX(p_pProto, fn);
            if ( v3->NArgs > 5 )
            {
              df = v3->Env;
              v24 = Scaleform::GFx::AS2::FnCall::Arg(v3, 5);
              fn = Scaleform::GFx::AS2::Value::ToNumber(v24, df);
              Scaleform::GFx::AS2::BitmapFilterObject::SetBlurY(p_pProto, fn);
              if ( v3->NArgs > 6 )
              {
                dg = v3->Env;
                v25 = Scaleform::GFx::AS2::FnCall::Arg(v3, 6);
                fn = Scaleform::GFx::AS2::Value::ToNumber(v25, dg);
                v26 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
                v26->Strength = fn;
                if ( v3->NArgs > 7 )
                {
                  dh = v3->Env;
                  v27 = Scaleform::GFx::AS2::FnCall::Arg(v3, 7);
                  v72 = (__int64)Scaleform::GFx::AS2::Value::ToNumber(v27, dh);
                  Scaleform::GFx::AS2::BitmapFilterObject::SetPasses(p_pProto, v72);
                  if ( v3->NArgs > 8 )
                  {
                    di = v3->Env;
                    v28 = Scaleform::GFx::AS2::FnCall::Arg(v3, 8);
                    v29 = Scaleform::GFx::AS2::Value::ToBool(v28, di);
                    Scaleform::GFx::AS2::BitmapFilterObject::SetInnerShadow(p_pProto, v29);
                    if ( v3->NArgs > 9 )
                    {
                      dj = v3->Env;
                      v30 = Scaleform::GFx::AS2::FnCall::Arg(v3, 9);
                      v31 = Scaleform::GFx::AS2::Value::ToBool(v30, dj);
                      Scaleform::GFx::AS2::BitmapFilterObject::SetKnockOut(p_pProto, v31);
                      if ( v3->NArgs > 10 )
                      {
                        dk = v3->Env;
                        v32 = Scaleform::GFx::AS2::FnCall::Arg(v3, 10);
                        v33 = Scaleform::GFx::AS2::Value::ToBool(v32, dk);
                        Scaleform::GFx::AS2::BitmapFilterObject::SetHideObject(p_pProto, v33);
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
  v34 = v3->Env;
  pContext = v34->StringContext.pContext;
  p_StringContext = &v34->StringContext;
  v73.T.Type = 10;
  LOBYTE(fn) = 0;
  v37 = &p_pProto->Scaleform::GFx::AS2::ObjectInterface;
  LODWORD(v72) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "distance",
                   8u,
                   0);
  ++*(_DWORD *)(v72 + 12);
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, __int64 *, Scaleform::GFx::AS2::Value *, float *, int))p_pProto->SetMemberRaw)(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    &v72,
    &v73,
    &fn,
    a1);
  v38 = (Scaleform::GFx::ASStringNode *)HIDWORD(v72);
  --*(_DWORD *)(HIDWORD(v72) + 12);
  if ( !v38->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  if ( v73.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v73.NV.4);
  v39 = p_StringContext->pContext;
  v73.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v72) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v39->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "angle",
                   5u,
                   0);
  ++*(_DWORD *)(HIDWORD(v72) + 12);
  v37->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v72 + 1,
    (const Scaleform::GFx::AS2::Value *)&v73.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v40 = (Scaleform::GFx::ASStringNode *)HIDWORD(v72);
  --*(_DWORD *)(HIDWORD(v72) + 12);
  if ( !v40->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v40);
  if ( v73.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v73.NV.4);
  v41 = p_StringContext->pContext;
  v73.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v72) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v41->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   (char *)&stru_9555EC,
                   5u,
                   0);
  ++*(_DWORD *)(HIDWORD(v72) + 12);
  v37->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v72 + 1,
    (const Scaleform::GFx::AS2::Value *)&v73.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v42 = (Scaleform::GFx::ASStringNode *)HIDWORD(v72);
  --*(_DWORD *)(HIDWORD(v72) + 12);
  if ( !v42->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v42);
  if ( v73.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v73.NV.4);
  v43 = p_StringContext->pContext;
  v73.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v72) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v43->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "alpha",
                   5u,
                   0);
  ++*(_DWORD *)(HIDWORD(v72) + 12);
  v37->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v72 + 1,
    (const Scaleform::GFx::AS2::Value *)&v73.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v44 = (Scaleform::GFx::ASStringNode *)HIDWORD(v72);
  --*(_DWORD *)(HIDWORD(v72) + 12);
  if ( !v44->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v44);
  if ( v73.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v73.NV.4);
  v45 = p_StringContext->pContext;
  v73.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v72) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v45->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "blurX",
                   5u,
                   0);
  ++*(_DWORD *)(HIDWORD(v72) + 12);
  v37->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v72 + 1,
    (const Scaleform::GFx::AS2::Value *)&v73.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v46 = (Scaleform::GFx::ASStringNode *)HIDWORD(v72);
  --*(_DWORD *)(HIDWORD(v72) + 12);
  if ( !v46->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v46);
  if ( v73.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v73.NV.4);
  v47 = p_StringContext->pContext;
  v73.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v72) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v47->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "blurY",
                   5u,
                   0);
  ++*(_DWORD *)(HIDWORD(v72) + 12);
  v37->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v72 + 1,
    (const Scaleform::GFx::AS2::Value *)&v73.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v48 = (Scaleform::GFx::ASStringNode *)HIDWORD(v72);
  --*(_DWORD *)(HIDWORD(v72) + 12);
  if ( !v48->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v48);
  if ( v73.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v73.NV.4);
  v49 = p_StringContext->pContext;
  v73.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v72) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v49->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "strength",
                   8u,
                   0);
  ++*(_DWORD *)(HIDWORD(v72) + 12);
  v37->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v72 + 1,
    (const Scaleform::GFx::AS2::Value *)&v73.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v50 = (Scaleform::GFx::ASStringNode *)HIDWORD(v72);
  --*(_DWORD *)(HIDWORD(v72) + 12);
  if ( !v50->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v50);
  if ( v73.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v73.NV.4);
  v51 = p_StringContext->pContext;
  v73.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v72) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v51->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "knockout",
                   8u,
                   0);
  ++*(_DWORD *)(HIDWORD(v72) + 12);
  v37->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v72 + 1,
    (const Scaleform::GFx::AS2::Value *)&v73.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v52 = (Scaleform::GFx::ASStringNode *)HIDWORD(v72);
  --*(_DWORD *)(HIDWORD(v72) + 12);
  if ( !v52->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v52);
  if ( v73.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v73.NV.4);
  v53 = p_StringContext->pContext;
  v73.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v72) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v53->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "hideObject",
                   0xAu,
                   0);
  ++*(_DWORD *)(HIDWORD(v72) + 12);
  v37->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v72 + 1,
    (const Scaleform::GFx::AS2::Value *)&v73.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v54 = (Scaleform::GFx::ASStringNode *)HIDWORD(v72);
  --*(_DWORD *)(HIDWORD(v72) + 12);
  if ( !v54->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v54);
  if ( v73.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v73.NV.4);
  v55 = p_StringContext->pContext;
  v73.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v72) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v55->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "inner",
                   5u,
                   0);
  ++*(_DWORD *)(HIDWORD(v72) + 12);
  v37->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v72 + 1,
    (const Scaleform::GFx::AS2::Value *)&v73.NV.4,
    (const Scaleform::GFx::AS2::PropFlags *)&a3);
  v56 = (Scaleform::GFx::ASStringNode *)HIDWORD(v72);
  --*(_DWORD *)(HIDWORD(v72) + 12);
  if ( !v56->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v56);
  if ( v73.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v73.NV.4);
  v57 = p_StringContext->pContext;
  v73.V.BooleanValue = 10;
  a3 = 0;
  HIDWORD(v72) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v57->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "quality",
                   7u,
                   0);
  ++*(_DWORD *)(HIDWORD(v72) + 12);
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, char *, $B8BD913BABC9324639AA48504BEFB2FC *))v37->SetMemberRaw)(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (char *)&v72 + 4,
    &v73.NV.4);
  v58 = (Scaleform::GFx::ASStringNode *)v72;
  --*(_DWORD *)(v72 + 12);
  if ( !v58->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v58);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  RefCount = p_pProto->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
  {
    p_pProto->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
  }
}
