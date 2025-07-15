double __cdecl Scaleform::GFx::AS2::BevelFilterCtorFunction::GlobalCtor(int fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::BitmapFilterObject *p_pProto; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::BevelFilterObject *v5; // eax
  Scaleform::GFx::AS2::BitmapFilterObject *v6; // eax
  Scaleform::Render::BlurFilterParams *v7; // eax
  unsigned __int8 Alpha; // cl
  Scaleform::Render::BlurFilterParams *v9; // eax
  unsigned __int8 v10; // cl
  double result; // st7
  Scaleform::Render::BlurFilterParams *v12; // eax
  Scaleform::Render::BlurFilterParams *v13; // eax
  _DWORD *v14; // edx
  Scaleform::GFx::AS2::Value *v15; // eax
  Scaleform::GFx::AS2::Value *v16; // eax
  Scaleform::GFx::AS2::Value *v17; // eax
  int v18; // edi
  Scaleform::Render::BlurFilterParams *v19; // eax
  unsigned __int8 v20; // cl
  Scaleform::GFx::AS2::Value *v21; // eax
  Scaleform::GFx::AS2::Value *v22; // eax
  unsigned int v23; // eax
  Scaleform::GFx::AS2::Value *v24; // eax
  Scaleform::GFx::AS2::Value *v25; // eax
  Scaleform::GFx::AS2::Value *v26; // eax
  Scaleform::GFx::AS2::Value *v27; // eax
  Scaleform::Render::BlurFilterParams *v28; // eax
  Scaleform::GFx::AS2::Value *v29; // eax
  Scaleform::GFx::AS2::Value *v30; // eax
  Scaleform::Render::BlurFilterParams *v31; // eax
  Scaleform::Render::BlurFilterParams *v32; // eax
  Scaleform::GFx::AS2::Value *v33; // eax
  bool v34; // al
  Scaleform::GFx::ASStringNode *v35; // ecx
  Scaleform::GFx::AS2::Environment *v37; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::ObjectInterface *v40; // edi
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
  Scaleform::GFx::AS2::GlobalContext *v60; // eax
  Scaleform::GFx::ASStringNode *v61; // eax
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
  __int64 v76; // [esp+B8h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value v77; // [esp+C0h] [ebp-10h] BYREF

  v1 = (Scaleform::GFx::AS2::FnCall *)fn;
  if ( *(_DWORD *)(fn + 8) && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(fn + 8) + 8))(*(_DWORD *)(fn + 8)) == 41 )
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
  v9->Colors[1].Raw = 0xFFFFFF;
  v9->Colors[1].Channels.Alpha = v10;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Colors[1].Channels.Alpha = -1;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->BlurX = 80.0;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->BlurY = 80.0;
  result = 1.0;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto)->Strength = 1.0;
  v12 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
  v12->Mode &= ~0x10u;
  v13 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
  v13->Mode &= ~0x40u;
  if ( v1->NArgs > 0 )
  {
    v14 = &v1->Env->__vftable;
    v15 = v1->FirstArgBottomIndex > (unsigned int)(32 * (v14[6] - 1) + ((v14[1] - v14[2]) >> 4))
        ? 0
        : (Scaleform::GFx::AS2::Value *)(*(_DWORD *)(v14[5] + 4 * ((unsigned int)v1->FirstArgBottomIndex >> 5))
                                       + 16 * (v1->FirstArgBottomIndex & 0x1F));
    fn = (__int16)Scaleform::GFx::AS2::Value::ToInt32(v15, v1->Env);
    result = (double)fn;
    d = result;
    Scaleform::GFx::AS2::BitmapFilterObject::SetDistance(p_pProto, d);
    if ( v1->NArgs > 1 )
    {
      da = v1->Env;
      v16 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      fn = (__int16)Scaleform::GFx::AS2::Value::ToInt32(v16, da);
      result = (double)fn;
      db = result;
      Scaleform::GFx::AS2::BitmapFilterObject::SetAngle(p_pProto, db);
      if ( v1->NArgs > 2 )
      {
        dc = v1->Env;
        v17 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
        v18 = Scaleform::GFx::AS2::Value::ToUInt32(v17, dc);
        v19 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
        v20 = v19->Colors[0].Channels.Alpha;
        v19->Colors[0].Raw = v18;
        v19->Colors[0].Channels.Alpha = v20;
        if ( v1->NArgs > 3 )
        {
          dd = v1->Env;
          v21 = Scaleform::GFx::AS2::FnCall::Arg(v1, 3);
          *(float *)&fn = Scaleform::GFx::AS2::Value::ToNumber(v21, dd);
          result = *(float *)&fn;
          Scaleform::GFx::AS2::BitmapFilterObject::SetAlpha(p_pProto, *(float *)&fn);
          if ( v1->NArgs > 4 )
          {
            de = v1->Env;
            v22 = Scaleform::GFx::AS2::FnCall::Arg(v1, 4);
            v23 = Scaleform::GFx::AS2::Value::ToUInt32(v22, de);
            Scaleform::GFx::AS2::BitmapFilterObject::SetColor2(p_pProto, v23);
            if ( v1->NArgs > 5 )
            {
              df = v1->Env;
              v24 = Scaleform::GFx::AS2::FnCall::Arg(v1, 5);
              *(float *)&fn = Scaleform::GFx::AS2::Value::ToNumber(v24, df);
              result = *(float *)&fn;
              Scaleform::GFx::AS2::BitmapFilterObject::SetAlpha2(p_pProto, *(float *)&fn);
              if ( v1->NArgs > 6 )
              {
                dg = v1->Env;
                v25 = Scaleform::GFx::AS2::FnCall::Arg(v1, 6);
                *(float *)&fn = Scaleform::GFx::AS2::Value::ToNumber(v25, dg);
                result = *(float *)&fn;
                Scaleform::GFx::AS2::BitmapFilterObject::SetBlurX(p_pProto, *(float *)&fn);
                if ( v1->NArgs > 7 )
                {
                  dh = v1->Env;
                  v26 = Scaleform::GFx::AS2::FnCall::Arg(v1, 7);
                  *(float *)&fn = Scaleform::GFx::AS2::Value::ToNumber(v26, dh);
                  result = *(float *)&fn;
                  Scaleform::GFx::AS2::BitmapFilterObject::SetBlurY(p_pProto, *(float *)&fn);
                  if ( v1->NArgs > 8 )
                  {
                    di = v1->Env;
                    v27 = Scaleform::GFx::AS2::FnCall::Arg(v1, 8);
                    *(float *)&fn = Scaleform::GFx::AS2::Value::ToNumber(v27, di);
                    v28 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
                    result = *(float *)&fn;
                    v28->Strength = *(float *)&fn;
                    if ( v1->NArgs > 9 )
                    {
                      dj = v1->Env;
                      v29 = Scaleform::GFx::AS2::FnCall::Arg(v1, 9);
                      result = Scaleform::GFx::AS2::Value::ToNumber(v29, dj);
                      v76 = (__int64)result;
                      Scaleform::GFx::AS2::BitmapFilterObject::SetPasses(p_pProto, (__int64)result);
                      if ( v1->NArgs > 10 )
                      {
                        Env = v1->Env;
                        v30 = Scaleform::GFx::AS2::FnCall::Arg(v1, 10);
                        Scaleform::GFx::AS2::Value::ToStringImpl(v30, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
                        if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&fn, "inner") )
                        {
                          v31 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
                          v31->Mode |= 0x20u;
                        }
                        else
                        {
                          v32 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(p_pProto);
                          v32->Mode &= ~0x20u;
                        }
                        if ( v1->NArgs > 11 )
                        {
                          dk = v1->Env;
                          v33 = Scaleform::GFx::AS2::FnCall::Arg(v1, 11);
                          v34 = Scaleform::GFx::AS2::Value::ToBool(v33, v18, dk);
                          Scaleform::GFx::AS2::BitmapFilterObject::SetKnockOut(p_pProto, v34);
                        }
                        v35 = (Scaleform::GFx::ASStringNode *)fn;
                        if ( (*(_DWORD *)(fn + 12))-- == 1 )
                          Scaleform::GFx::ASStringNode::ReleaseNode(v35);
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
  v37 = v1->Env;
  pContext = v37->StringContext.pContext;
  p_StringContext = &v37->StringContext;
  v77.T.Type = 10;
  LOBYTE(fn) = 0;
  v40 = &p_pProto->Scaleform::GFx::AS2::ObjectInterface;
  LODWORD(v76) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "shadowColor",
                   0xBu,
                   0);
  ++*(_DWORD *)(v76 + 12);
  p_pProto->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v76,
    &v77,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v41 = (Scaleform::GFx::ASStringNode *)v76;
  --*(_DWORD *)(v76 + 12);
  if ( !v41->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v41);
  if ( v77.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v77);
  v42 = p_StringContext->pContext;
  v77.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v76) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v42->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "shadowAlpha",
                   0xBu,
                   0);
  ++*(_DWORD *)(v76 + 12);
  v40->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v76,
    &v77,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v43 = (Scaleform::GFx::ASStringNode *)v76;
  --*(_DWORD *)(v76 + 12);
  if ( !v43->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
  if ( v77.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v77);
  v44 = p_StringContext->pContext;
  v77.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v76) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v44->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "highlightColor",
                   0xEu,
                   0);
  ++*(_DWORD *)(v76 + 12);
  v40->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v76,
    &v77,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v45 = (Scaleform::GFx::ASStringNode *)v76;
  --*(_DWORD *)(v76 + 12);
  if ( !v45->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v45);
  if ( v77.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v77);
  v46 = p_StringContext->pContext;
  v77.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v76) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v46->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "highlightAlpha",
                   0xEu,
                   0);
  ++*(_DWORD *)(v76 + 12);
  v40->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v76,
    &v77,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v47 = (Scaleform::GFx::ASStringNode *)v76;
  --*(_DWORD *)(v76 + 12);
  if ( !v47->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v47);
  if ( v77.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v77);
  v48 = p_StringContext->pContext;
  v77.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v76) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v48->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "blurX",
                   5u,
                   0);
  ++*(_DWORD *)(v76 + 12);
  v40->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v76,
    &v77,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v49 = (Scaleform::GFx::ASStringNode *)v76;
  --*(_DWORD *)(v76 + 12);
  if ( !v49->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v49);
  if ( v77.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v77);
  v50 = p_StringContext->pContext;
  v77.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v76) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v50->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "blurY",
                   5u,
                   0);
  ++*(_DWORD *)(v76 + 12);
  v40->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v76,
    &v77,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v51 = (Scaleform::GFx::ASStringNode *)v76;
  --*(_DWORD *)(v76 + 12);
  if ( !v51->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v51);
  if ( v77.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v77);
  v52 = p_StringContext->pContext;
  v77.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v76) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v52->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "strength",
                   8u,
                   0);
  ++*(_DWORD *)(v76 + 12);
  v40->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v76,
    &v77,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v53 = (Scaleform::GFx::ASStringNode *)v76;
  --*(_DWORD *)(v76 + 12);
  if ( !v53->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v53);
  if ( v77.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v77);
  v54 = p_StringContext->pContext;
  v77.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v76) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v54->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "knockout",
                   8u,
                   0);
  ++*(_DWORD *)(v76 + 12);
  v40->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v76,
    &v77,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v55 = (Scaleform::GFx::ASStringNode *)v76;
  --*(_DWORD *)(v76 + 12);
  if ( !v55->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v55);
  if ( v77.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v77);
  v56 = p_StringContext->pContext;
  v77.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v76) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v56->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "inner",
                   5u,
                   0);
  ++*(_DWORD *)(v76 + 12);
  v40->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v76,
    &v77,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v57 = (Scaleform::GFx::ASStringNode *)v76;
  --*(_DWORD *)(v76 + 12);
  if ( !v57->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v57);
  if ( v77.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v77);
  v58 = p_StringContext->pContext;
  v77.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v76) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v58->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "type",
                   4u,
                   0);
  ++*(_DWORD *)(v76 + 12);
  v40->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v76,
    &v77,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v59 = (Scaleform::GFx::ASStringNode *)v76;
  --*(_DWORD *)(v76 + 12);
  if ( !v59->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v59);
  if ( v77.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v77);
  v60 = p_StringContext->pContext;
  v77.T.Type = 10;
  LOBYTE(fn) = 0;
  LODWORD(v76) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v60->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "quality",
                   7u,
                   0);
  ++*(_DWORD *)(v76 + 12);
  v40->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    (const Scaleform::GFx::ASString *)&v76,
    &v77,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v61 = (Scaleform::GFx::ASStringNode *)v76;
  --*(_DWORD *)(v76 + 12);
  if ( !v61->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v61);
  if ( v77.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v77);
  RefCount = p_pProto->RefCount;
  if ( (RefCount & 0x3FFFFFF) != 0 )
  {
    p_pProto->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
  }
  return result;
}
