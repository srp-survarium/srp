void __cdecl Scaleform::GFx::AS2::BevelFilterCtorFunction::GlobalCtor(float fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::BitmapFilterObject *p_pProto; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::BevelFilterObject *v5; // eax
  Scaleform::GFx::AS2::BitmapFilterObject *v6; // eax
  Scaleform::Render::BlurFilterParams *v7; // eax
  unsigned __int8 Alpha; // cl
  Scaleform::Render::BlurFilterParams *v9; // eax
  unsigned __int8 v10; // cl
  Scaleform::Render::BlurFilterParams *v11; // eax
  Scaleform::Render::BlurFilterParams *v12; // eax
  _DWORD *v13; // edx
  Scaleform::GFx::AS2::Value *v14; // eax
  Scaleform::GFx::AS2::Value *v15; // eax
  Scaleform::GFx::AS2::Value *v16; // eax
  unsigned int v17; // edi
  Scaleform::Render::BlurFilterParams *v18; // eax
  unsigned __int8 v19; // cl
  Scaleform::GFx::AS2::Value *v20; // eax
  Scaleform::GFx::AS2::Value *v21; // eax
  unsigned int v22; // eax
  Scaleform::GFx::AS2::Value *v23; // eax
  Scaleform::GFx::AS2::Value *v24; // eax
  Scaleform::GFx::AS2::Value *v25; // eax
  Scaleform::GFx::AS2::Value *v26; // eax
  Scaleform::Render::BlurFilterParams *v27; // eax
  Scaleform::GFx::AS2::Value *v28; // eax
  Scaleform::GFx::AS2::Value *v29; // eax
  Scaleform::Render::BlurFilterParams *v30; // eax
  Scaleform::Render::BlurFilterParams *v31; // eax
  Scaleform::GFx::AS2::Value *v32; // eax
  char v33; // al
  Scaleform::GFx::ASStringNode *v34; // ecx
  Scaleform::GFx::AS2::Environment *v36; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::ObjectInterface *v39; // edi
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
  Scaleform::GFx::AS2::GlobalContext *v59; // eax
  Scaleform::GFx::ASStringNode *v60; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp+9Ch] [ebp-34h]
  float d; // [esp+A4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *da; // [esp+A4h] [ebp-2Ch]
  float db; // [esp+A4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *dc; // [esp+A4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *dd; // [esp+A4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *de; // [esp+A4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *df; // [esp+A4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *dg; // [esp+A4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *dh; // [esp+A4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *di; // [esp+A4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *dj; // [esp+A4h] [ebp-2Ch]
  const Scaleform::GFx::AS2::Environment *dk; // [esp+A4h] [ebp-2Ch]
  __int64 v75; // [esp+B8h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value v76; // [esp+C0h] [ebp-10h] BYREF

  v1 = (const Scaleform::GFx::AS2::FnCall *)LODWORD(fn);
  if ( *(_DWORD *)(LODWORD(fn) + 8)
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(fn) + 8) + 8))(*(_DWORD *)(LODWORD(fn) + 8)) == 41 )
  {
    ThisPtr = v1->ThisPtr;
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
    pHeap = v1->Env->StringContext.pContext->pHeap;
    v5 = (Scaleform::GFx::AS2::BevelFilterObject *)pHeap->Alloc(pHeap, 56u, 0);
    if ( v5 )
      Scaleform::GFx::AS2::BevelFilterObject::BevelFilterObject(v5, v1->Env);
    else
      v6 = 0;
    p_pProto = v6;
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, p_pProto);
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Passes = 1;
  Scaleform::GFx::AS2::BitmapFilterObject::SetDistance(p_pProto, 4.0);
  Scaleform::GFx::AS2::BitmapFilterObject::SetAngle(p_pProto, 45.0);
  v7 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
  Alpha = v7->Colors[0].Channels.Alpha;
  v7->Colors[0].Raw = 0;
  v7->Colors[0].Channels.Alpha = Alpha;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Colors[0].Channels.Alpha = -1;
  v9 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
  v10 = v9->Colors[1].Channels.Alpha;
  v9->Colors[1].Raw = (unsigned int)&vostok::memory::s_CRT_arena[5574199];
  v9->Colors[1].Channels.Alpha = v10;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Colors[1].Channels.Alpha = -1;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->BlurX = 80.0;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->BlurY = 80.0;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Strength = 1.0;
  v11 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
  v11->Mode &= ~0x10u;
  v12 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
  v12->Mode &= ~0x40u;
  if ( v1->NArgs > 0 )
  {
    v13 = &v1->Env->__vftable;
    v14 = v1->FirstArgBottomIndex > (unsigned int)(32 * (v13[6] - 1) + ((v13[1] - v13[2]) >> 4))
        ? 0
        : (Scaleform::GFx::AS2::Value *)(*(_DWORD *)(v13[5] + 4 * ((unsigned int)v1->FirstArgBottomIndex >> 5))
                                       + 16 * (v1->FirstArgBottomIndex & 0x1F));
    LODWORD(fn) = (__int16)Scaleform::GFx::AS2::Value::ToInt32(v14, v1->Env);
    d = (float)SLODWORD(fn);
    Scaleform::GFx::AS2::BitmapFilterObject::SetDistance(p_pProto, d);
    if ( v1->NArgs > 1 )
    {
      da = v1->Env;
      v15 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      LODWORD(fn) = (__int16)Scaleform::GFx::AS2::Value::ToInt32(v15, da);
      db = (float)SLODWORD(fn);
      Scaleform::GFx::AS2::BitmapFilterObject::SetAngle(p_pProto, db);
      if ( v1->NArgs > 2 )
      {
        dc = v1->Env;
        v16 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
        v17 = Scaleform::GFx::AS2::Value::ToUInt32(v16, dc);
        v18 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
        v19 = v18->Colors[0].Channels.Alpha;
        v18->Colors[0].Raw = v17;
        v18->Colors[0].Channels.Alpha = v19;
        if ( v1->NArgs > 3 )
        {
          dd = v1->Env;
          v20 = Scaleform::GFx::AS2::FnCall::Arg(v1, 3);
          fn = Scaleform::GFx::AS2::Value::ToNumber(v20, dd);
          Scaleform::GFx::AS2::BitmapFilterObject::SetAlpha(p_pProto, fn);
          if ( v1->NArgs > 4 )
          {
            de = v1->Env;
            v21 = Scaleform::GFx::AS2::FnCall::Arg(v1, 4);
            v22 = Scaleform::GFx::AS2::Value::ToUInt32(v21, de);
            Scaleform::GFx::AS2::BitmapFilterObject::SetColor2(p_pProto, v22);
            if ( v1->NArgs > 5 )
            {
              df = v1->Env;
              v23 = Scaleform::GFx::AS2::FnCall::Arg(v1, 5);
              fn = Scaleform::GFx::AS2::Value::ToNumber(v23, df);
              Scaleform::GFx::AS2::BitmapFilterObject::SetAlpha2(p_pProto, fn);
              if ( v1->NArgs > 6 )
              {
                dg = v1->Env;
                v24 = Scaleform::GFx::AS2::FnCall::Arg(v1, 6);
                fn = Scaleform::GFx::AS2::Value::ToNumber(v24, dg);
                Scaleform::GFx::AS2::BitmapFilterObject::SetBlurX(p_pProto, fn);
                if ( v1->NArgs > 7 )
                {
                  dh = v1->Env;
                  v25 = Scaleform::GFx::AS2::FnCall::Arg(v1, 7);
                  fn = Scaleform::GFx::AS2::Value::ToNumber(v25, dh);
                  Scaleform::GFx::AS2::BitmapFilterObject::SetBlurY(p_pProto, fn);
                  if ( v1->NArgs > 8 )
                  {
                    di = v1->Env;
                    v26 = Scaleform::GFx::AS2::FnCall::Arg(v1, 8);
                    fn = Scaleform::GFx::AS2::Value::ToNumber(v26, di);
                    v27 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
                    v27->Strength = fn;
                    if ( v1->NArgs > 9 )
                    {
                      dj = v1->Env;
                      v28 = Scaleform::GFx::AS2::FnCall::Arg(v1, 9);
                      v75 = (__int64)Scaleform::GFx::AS2::Value::ToNumber(v28, dj);
                      Scaleform::GFx::AS2::BitmapFilterObject::SetPasses(p_pProto, v75);
                      if ( v1->NArgs > 10 )
                      {
                        Env = v1->Env;
                        v29 = Scaleform::GFx::AS2::FnCall::Arg(v1, 10);
                        Scaleform::GFx::AS2::Value::ToStringImpl(v29, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
                        if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&fn, "inner") )
                        {
                          v30 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
                          v30->Mode |= 0x20u;
                        }
                        else
                        {
                          v31 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
                          v31->Mode &= ~0x20u;
                        }
                        if ( v1->NArgs > 11 )
                        {
                          dk = v1->Env;
                          v32 = Scaleform::GFx::AS2::FnCall::Arg(v1, 11);
                          v33 = Scaleform::GFx::AS2::Value::ToBool(v32, dk);
                          Scaleform::GFx::AS2::BitmapFilterObject::SetKnockOut(p_pProto, v33);
                        }
                        v34 = (Scaleform::GFx::ASStringNode *)LODWORD(fn);
                        if ( (*(_DWORD *)(LODWORD(fn) + 12))-- == 1 )
                          Scaleform::GFx::ASStringNode::ReleaseNode(v34);
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
  v36 = v1->Env;
  pContext = v36->StringContext.pContext;
  p_StringContext = &v36->StringContext;
  v76.T.Type = 10;
  LOBYTE(fn) = 0;
  v39 = &p_pProto->Scaleform::GFx::AS2::ObjectInterface;
  LODWORD(v75) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "shadowColor",
                   0xBu,
                   0);
  ++*(_DWORD *)(v75 + 12);
  p_pProto->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v75,
    &v76,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v40 = (Scaleform::GFx::ASStringNode *)v75;
  --*(_DWORD *)(v75 + 12);
  if ( !v40->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v40);
  if ( v76.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v76);
  v41 = p_StringContext->pContext;
  v76.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v75) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v41->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "shadowAlpha",
                   0xBu,
                   0);
  ++*(_DWORD *)(v75 + 12);
  v39->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v75,
    &v76,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v42 = (Scaleform::GFx::ASStringNode *)v75;
  --*(_DWORD *)(v75 + 12);
  if ( !v42->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v42);
  if ( v76.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v76);
  v43 = p_StringContext->pContext;
  v76.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v75) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v43->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "highlightColor",
                   0xEu,
                   0);
  ++*(_DWORD *)(v75 + 12);
  v39->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v75,
    &v76,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v44 = (Scaleform::GFx::ASStringNode *)v75;
  --*(_DWORD *)(v75 + 12);
  if ( !v44->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v44);
  if ( v76.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v76);
  v45 = p_StringContext->pContext;
  v76.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v75) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v45->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "highlightAlpha",
                   0xEu,
                   0);
  ++*(_DWORD *)(v75 + 12);
  v39->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v75,
    &v76,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v46 = (Scaleform::GFx::ASStringNode *)v75;
  --*(_DWORD *)(v75 + 12);
  if ( !v46->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v46);
  if ( v76.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v76);
  v47 = p_StringContext->pContext;
  v76.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v75) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v47->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "blurX",
                   5u,
                   0);
  ++*(_DWORD *)(v75 + 12);
  v39->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v75,
    &v76,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v48 = (Scaleform::GFx::ASStringNode *)v75;
  --*(_DWORD *)(v75 + 12);
  if ( !v48->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v48);
  if ( v76.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v76);
  v49 = p_StringContext->pContext;
  v76.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v75) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v49->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "blurY",
                   5u,
                   0);
  ++*(_DWORD *)(v75 + 12);
  v39->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v75,
    &v76,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v50 = (Scaleform::GFx::ASStringNode *)v75;
  --*(_DWORD *)(v75 + 12);
  if ( !v50->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v50);
  if ( v76.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v76);
  v51 = p_StringContext->pContext;
  v76.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v75) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v51->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "strength",
                   8u,
                   0);
  ++*(_DWORD *)(v75 + 12);
  v39->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v75,
    &v76,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v52 = (Scaleform::GFx::ASStringNode *)v75;
  --*(_DWORD *)(v75 + 12);
  if ( !v52->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v52);
  if ( v76.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v76);
  v53 = p_StringContext->pContext;
  v76.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v75) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v53->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "knockout",
                   8u,
                   0);
  ++*(_DWORD *)(v75 + 12);
  v39->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v75,
    &v76,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v54 = (Scaleform::GFx::ASStringNode *)v75;
  --*(_DWORD *)(v75 + 12);
  if ( !v54->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v54);
  if ( v76.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v76);
  v55 = p_StringContext->pContext;
  v76.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v75) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v55->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "inner",
                   5u,
                   0);
  ++*(_DWORD *)(v75 + 12);
  v39->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v75,
    &v76,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v56 = (Scaleform::GFx::ASStringNode *)v75;
  --*(_DWORD *)(v75 + 12);
  if ( !v56->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v56);
  if ( v76.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v76);
  v57 = p_StringContext->pContext;
  v76.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v75) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v57->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "type",
                   4u,
                   0);
  ++*(_DWORD *)(v75 + 12);
  v39->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v75,
    &v76,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v58 = (Scaleform::GFx::ASStringNode *)v75;
  --*(_DWORD *)(v75 + 12);
  if ( !v58->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v58);
  if ( v76.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v76);
  v59 = p_StringContext->pContext;
  v76.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v75) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v59->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "quality",
                   7u,
                   0);
  ++*(_DWORD *)(v75 + 12);
  v39->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v75,
    &v76,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v60 = (Scaleform::GFx::ASStringNode *)v75;
  --*(_DWORD *)(v75 + 12);
  if ( !v60->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v60);
  if ( v76.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v76);
  RefCount = p_pProto->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
  {
    p_pProto->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
  }
}
