void __thiscall Scaleform::GFx::AS2::GASTextSnapshotGlyphVisitor::OnVisit(
        Scaleform::GFx::AS2::GASTextSnapshotGlyphVisitor *this)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::Object *v3; // eax
  Scaleform::GFx::AS2::Object *v4; // eax
  unsigned int RunIdx; // eax
  Scaleform::GFx::AS2::Environment *pEnv; // edx
  Scaleform::GFx::AS2::ObjectInterface *v7; // edi
  Scaleform::GFx::ASStringNode *v8; // eax
  char *v9; // eax
  Scaleform::GFx::ASStringNode *StringNode; // ebp
  Scaleform::GFx::AS2::Environment *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  unsigned int Raw; // ebp
  Scaleform::GFx::AS2::Environment *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::AS2::Environment *v17; // eax
  bool (__thiscall *SetMember)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // edx
  Scaleform::GFx::AS2::Environment *v19; // edx
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::GFx::AS2::Environment *v21; // ecx
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::AS2::Environment *v23; // eax
  Scaleform::GFx::ASStringNode *v24; // eax
  Scaleform::GFx::AS2::Environment *v25; // eax
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::GFx::AS2::Environment *v27; // eax
  Scaleform::GFx::ASStringNode *v28; // eax
  Scaleform::GFx::AS2::Environment *v29; // eax
  Scaleform::GFx::ASStringNode *v30; // eax
  Scaleform::GFx::AS2::Environment *v31; // eax
  Scaleform::GFx::ASStringNode *v32; // eax
  Scaleform::GFx::AS2::Environment *v33; // eax
  Scaleform::GFx::ASStringNode *v34; // eax
  Scaleform::GFx::AS2::Environment *v35; // eax
  Scaleform::GFx::ASStringNode *v36; // eax
  Scaleform::GFx::AS2::Environment *v37; // eax
  Scaleform::GFx::ASStringNode *v38; // eax
  Scaleform::GFx::AS2::Environment *v39; // eax
  Scaleform::GFx::ASStringNode *v40; // eax
  Scaleform::GFx::AS2::Environment *v41; // eax
  Scaleform::GFx::ASStringNode *v42; // eax
  Scaleform::GFx::AS2::Environment *v43; // eax
  Scaleform::GFx::ASStringNode *v44; // eax
  Scaleform::GFx::AS2::Environment *v45; // eax
  Scaleform::GFx::ASStringNode *v46; // eax
  Scaleform::GFx::AS2::Environment *v47; // eax
  Scaleform::GFx::ASStringNode *v48; // eax
  Scaleform::GFx::AS2::Object *v49; // edi
  const Scaleform::GFx::AS2::Value *v50; // eax
  unsigned int RefCount; // eax
  int v52; // [esp+134h] [ebp-48h] BYREF
  Scaleform::GFx::AS2::Object *v53; // [esp+138h] [ebp-44h]
  long double v54; // [esp+13Ch] [ebp-40h] BYREF
  long double v55; // [esp+144h] [ebp-38h]
  long double v56; // [esp+14Ch] [ebp-30h]
  long double v57; // [esp+154h] [ebp-28h]
  Scaleform::GFx::AS2::Value v58; // [esp+15Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+16Ch] [ebp-10h] BYREF

  pHeap = this->pEnv->StringContext.pContext->pHeap;
  v3 = (Scaleform::GFx::AS2::Object *)pHeap->Alloc(pHeap, 52u, 0);
  if ( v3 )
  {
    Scaleform::GFx::AS2::Object::Object(v3, this->pEnv);
    v53 = v4;
  }
  else
  {
    v53 = 0;
  }
  RunIdx = this->RunIdx;
  pEnv = this->pEnv;
  val.T.Type = 4;
  val.NV.Int32Value = RunIdx;
  HIBYTE(v52) = 0;
  v7 = &v53->Scaleform::GFx::AS2::ObjectInterface;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "indexInRun",
                   0xAu,
                   0);
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v8 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v9 = (char *)this->pFont->GetName(this->pFont);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)this->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 v9);
  ++StringNode->RefCount;
  v58.T.Type = 5;
  v58.NV.Int32Value = (int)StringNode;
  ++StringNode->RefCount;
  v11 = this->pEnv;
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v11->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "font",
                   4u,
                   0);
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &v58,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v12 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( v58.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v58);
  if ( StringNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  Raw = this->ColorValue.Raw;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LODWORD(v54) = Raw;
  val.T.Type = 3;
  v15 = this->pEnv;
  val.NV.NumberValue = (double)Raw;
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v15->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   (char *)&stru_9555EC,
                   5u,
                   0);
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v16 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v16->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  *(float *)&v54 = this->Height;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v17 = this->pEnv;
  val.NV.NumberValue = *(float *)&v54;
  val.T.Type = 3;
  SetMember = v7->SetMember;
  HIBYTE(v52) = 0;
  SetMember(
    v7,
    v17,
    (const Scaleform::GFx::ASString *)&v17->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  HIBYTE(v52) = this->bSelected;
  Scaleform::GFx::AS2::Value::DropRefs(&val);
  v19 = this->pEnv;
  val.T.Type = 2;
  val.V.BooleanValue = HIBYTE(v52);
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)v19->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "selected",
                   8u,
                   0);
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v20 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v20->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  *(float *)&v54 = this->Matrix.M[0][0] * 0.05000000074505806;
  *(double *)&v58.T.Type = *(float *)&v54;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v21 = this->pEnv;
  val.NV.NumberValue = *(double *)&v58.T.Type;
  val.T.Type = 3;
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v21->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "matrix_a");
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v22 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v22->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  *(float *)&v54 = this->Matrix.M[1][0] * 0.05000000074505806;
  *(double *)&v58.T.Type = *(float *)&v54;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v23 = this->pEnv;
  val.NV.NumberValue = *(double *)&v58.T.Type;
  val.T.Type = 3;
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v23->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "matrix_b");
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v24 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v24->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  *(float *)&v54 = this->Matrix.M[0][1] * 0.05000000074505806;
  *(double *)&v58.T.Type = *(float *)&v54;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v25 = this->pEnv;
  val.NV.NumberValue = *(double *)&v58.T.Type;
  val.T.Type = 3;
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v25->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "matrix_c");
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v26 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v26->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  *(float *)&v54 = this->Matrix.M[1][1] * 0.05000000074505806;
  *(double *)&v58.T.Type = *(float *)&v54;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v27 = this->pEnv;
  val.NV.NumberValue = *(double *)&v58.T.Type;
  val.T.Type = 3;
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v27->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "matrix_d");
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v28 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v28->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v28);
  *(float *)&v54 = this->Matrix.M[0][3] * 0.05000000074505806;
  *(double *)&v58.T.Type = *(float *)&v54;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v29 = this->pEnv;
  val.NV.NumberValue = *(double *)&v58.T.Type;
  val.T.Type = 3;
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v29->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "matrix_tx");
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v30 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v30->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v30);
  *(float *)&v54 = this->Matrix.M[1][3] * 0.05000000074505806;
  *(double *)&v58.T.Type = *(float *)&v54;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v31 = this->pEnv;
  val.NV.NumberValue = *(double *)&v58.T.Type;
  val.T.Type = 3;
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v31->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "matrix_ty");
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v32 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v32->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v32);
  *(float *)&v55 = this->Corners.x1;
  *((float *)&v55 + 1) = this->Corners.y2;
  *(float *)&v56 = this->Corners.x2;
  *((float *)&v56 + 1) = this->Corners.y2;
  *(float *)&v58.T.Type = this->Corners.x1;
  *(float *)&v58.V.pStringNode = this->Corners.y1;
  *(float *)&v57 = this->Corners.x2;
  *((float *)&v57 + 1) = this->Corners.y1;
  *(float *)&v54 = *(float *)&v55 * 0.05000000074505806;
  v54 = *(float *)&v54;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v33 = this->pEnv;
  val.NV.NumberValue = v54;
  val.T.Type = 3;
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v33->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "corner0x");
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v34 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v34->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v34);
  *(float *)&v54 = *((float *)&v55 + 1) * 0.05000000074505806;
  v55 = *(float *)&v54;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v35 = this->pEnv;
  val.NV.NumberValue = v55;
  val.T.Type = 3;
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v35->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "corner0y");
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v36 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v36->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v36);
  *(float *)&v54 = *(float *)&v56 * 0.05000000074505806;
  v55 = *(float *)&v54;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v37 = this->pEnv;
  val.NV.NumberValue = v55;
  val.T.Type = 3;
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v37->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "corner1x");
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v38 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v38->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  *(float *)&v54 = *((float *)&v56 + 1) * 0.05000000074505806;
  v56 = *(float *)&v54;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v39 = this->pEnv;
  val.NV.NumberValue = v56;
  val.T.Type = 3;
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v39->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "corner1y");
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v40 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v40->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v40);
  *(float *)&v54 = *(float *)&v57 * 0.05000000074505806;
  v56 = *(float *)&v54;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v41 = this->pEnv;
  val.NV.NumberValue = v56;
  val.T.Type = 3;
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v41->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "corner2x");
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v42 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v42->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v42);
  *(float *)&v54 = *((float *)&v57 + 1) * 0.05000000074505806;
  v57 = *(float *)&v54;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v43 = this->pEnv;
  val.NV.NumberValue = v57;
  val.T.Type = 3;
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v43->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "corner2y");
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v44 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v44->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v44);
  *(float *)&v54 = *(float *)&v58.T.Type * 0.05000000074505806;
  v57 = *(float *)&v54;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v45 = this->pEnv;
  val.NV.NumberValue = v57;
  val.T.Type = 3;
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v45->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "corner3x");
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v46 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v46->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v46);
  *(float *)&v54 = *(float *)&v58.V.pStringNode * 0.05000000074505806;
  *(double *)&v58.T.Type = *(float *)&v54;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v47 = this->pEnv;
  val.NV.NumberValue = *(double *)&v58.T.Type;
  val.T.Type = 3;
  HIBYTE(v52) = 0;
  LODWORD(v54) = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v47->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "corner3y");
  ++*(_DWORD *)(LODWORD(v54) + 12);
  v7->SetMember(
    v7,
    this->pEnv,
    (const Scaleform::GFx::ASString *)&v54,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&v52 + 3);
  v48 = (Scaleform::GFx::ASStringNode *)LODWORD(v54);
  --*(_DWORD *)(LODWORD(v54) + 12);
  if ( !v48->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v48);
  v49 = v53;
  Scaleform::GFx::AS2::Value::Value(&v58, v53);
  Scaleform::GFx::AS2::ArrayObject::PushBack(this->pArrayObj, v50);
  if ( v58.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v58);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  RefCount = v49->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
  {
    v49->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v49);
  }
}
