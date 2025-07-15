void __thiscall Scaleform::GFx::AS3::TextSnapshotGlyphVisitor::OnVisit(
        Scaleform::GFx::AS3::TextSnapshotGlyphVisitor *this)
{
  Scaleform::GFx::AS3::Instances::fl::Object *pV; // ebx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // esi
  unsigned int RunIdx; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int Flags; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  __m128i *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  unsigned int v11; // eax
  Scaleform::GFx::ASStringNode *Raw; // ebp
  Scaleform::GFx::ASStringNode *v13; // eax
  unsigned int v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  unsigned int v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  unsigned int v18; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  unsigned int v20; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  unsigned int v22; // eax
  Scaleform::GFx::ASStringNode *v23; // eax
  unsigned int v24; // eax
  Scaleform::GFx::ASStringNode *v25; // eax
  unsigned int v26; // eax
  Scaleform::GFx::ASStringNode *v27; // eax
  unsigned int v28; // eax
  Scaleform::GFx::ASStringNode *v29; // eax
  unsigned int v30; // eax
  Scaleform::GFx::ASStringNode *v31; // eax
  unsigned int v32; // eax
  Scaleform::GFx::ASStringNode *v33; // eax
  unsigned int v34; // eax
  Scaleform::GFx::ASStringNode *v35; // eax
  unsigned int v36; // eax
  Scaleform::GFx::ASStringNode *v37; // eax
  unsigned int v38; // eax
  Scaleform::GFx::ASStringNode *v39; // eax
  unsigned int v40; // eax
  Scaleform::GFx::ASStringNode *v41; // eax
  unsigned int v42; // eax
  Scaleform::GFx::ASStringNode *v43; // eax
  unsigned int RefCount; // eax
  bool bSelected; // [esp+17h] [ebp-49h]
  Scaleform::GFx::ASString prop_name; // [esp+1Ch] [ebp-44h] BYREF
  float y2; // [esp+20h] [ebp-40h]
  Scaleform::GFx::ASString v[2]; // [esp+24h] [ebp-3Ch] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> result; // [esp+2Ch] [ebp-34h] BYREF
  long double v51; // [esp+30h] [ebp-30h]
  long double v52; // [esp+38h] [ebp-28h]
  Scaleform::GFx::AS3::Value v53; // [esp+40h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value val; // [esp+50h] [ebp-10h] BYREF

  pV = Scaleform::GFx::AS3::VM::MakeObject(this->pVM, &result)->pV;
  StringManagerRef = this->pVM->StringManagerRef;
  RunIdx = this->RunIdx;
  val.Bonus.pWeakProxy = 0;
  val.Flags = 3;
  *(_QWORD *)&val.value.VNumber = __PAIR64__((unsigned int)v53.Bonus.pWeakProxy, RunIdx);
  *(float *)&prop_name.pNode = COERCE_FLOAT(
                                 Scaleform::GFx::ASStringManager::CreateStringNode(
                                   StringManagerRef->pStringManager,
                                   (__m128i *)"indexInRun"));
  ++prop_name.pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, &prop_name, &val, aNone);
  pNode = prop_name.pNode;
  --prop_name.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Flags = val.Flags;
  bSelected = this->bSelected;
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    Flags = val.Flags;
  }
  val.Flags = Flags & 0xFFFFFFE0 | 1;
  LOBYTE(v53.Flags) = bSelected;
  val.value.VNumber = *(long double *)&v53.Flags;
  *(float *)&prop_name.pNode = COERCE_FLOAT(
                                 Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                   StringManagerRef->pStringManager,
                                   "selected",
                                   8u,
                                   0));
  ++prop_name.pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, &prop_name, &val, aNone);
  v7 = prop_name.pNode;
  --prop_name.pNode->RefCount;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v8 = (__m128i *)this->pFont->GetName(this->pFont);
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, v8);
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&v53, v);
  *(float *)&prop_name.pNode = COERCE_FLOAT(
                                 Scaleform::GFx::ASStringManager::CreateStringNode(
                                   StringManagerRef->pStringManager,
                                   (__m128i *)"font"));
  ++prop_name.pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, &prop_name, &v53, aNone);
  v9 = prop_name.pNode;
  --prop_name.pNode->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( (v53.Flags & 0x1F) > 9 )
  {
    if ( (v53.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v53);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v53);
  }
  v10 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v11 = val.Flags;
  Raw = (Scaleform::GFx::ASStringNode *)this->ColorValue.Raw;
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    v11 = val.Flags;
  }
  v[0].pNode = Raw;
  val.Flags = v11 & 0xFFFFFFE0 | 4;
  val.value.VNumber = (double)(unsigned int)Raw;
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(StringManagerRef->pStringManager, "color", 5u, 0);
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, v, &val, aNone);
  v13 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v14 = val.Flags;
  v[0] = LODWORD(this->Height);
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    v14 = val.Flags;
  }
  val.value.VNumber = *(float *)&v[0].pNode;
  val.Flags = v14 & 0xFFFFFFE0 | 4;
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(StringManagerRef->pStringManager, "height", 6u, 0);
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, v, &val, aNone);
  v15 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v15->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  v16 = val.Flags;
  *(float *)&v[0].pNode = this->Matrix.M[0][0] * 0.05000000074505806;
  *(double *)&v53.Flags = *(float *)&v[0].pNode;
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    v16 = val.Flags;
  }
  val.value.VNumber = *(double *)&v53.Flags;
  val.Flags = v16 & 0xFFFFFFE0 | 4;
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManagerRef->pStringManager,
                 (__m128i *)"matrix_a");
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, v, &val, aNone);
  v17 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v17->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  v18 = val.Flags;
  *(float *)&v[0].pNode = this->Matrix.M[1][0] * 0.05000000074505806;
  *(double *)&v53.Flags = *(float *)&v[0].pNode;
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    v18 = val.Flags;
  }
  val.value.VNumber = *(double *)&v53.Flags;
  val.Flags = v18 & 0xFFFFFFE0 | 4;
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManagerRef->pStringManager,
                 (__m128i *)"matrix_b");
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, v, &val, aNone);
  v19 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v19->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  v20 = val.Flags;
  *(float *)&v[0].pNode = this->Matrix.M[0][1] * 0.05000000074505806;
  *(double *)&v53.Flags = *(float *)&v[0].pNode;
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    v20 = val.Flags;
  }
  val.value.VNumber = *(double *)&v53.Flags;
  val.Flags = v20 & 0xFFFFFFE0 | 4;
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManagerRef->pStringManager,
                 (__m128i *)"matrix_c");
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, v, &val, aNone);
  v21 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v21->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  v22 = val.Flags;
  *(float *)&v[0].pNode = this->Matrix.M[1][1] * 0.05000000074505806;
  *(double *)&v53.Flags = *(float *)&v[0].pNode;
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    v22 = val.Flags;
  }
  val.value.VNumber = *(double *)&v53.Flags;
  val.Flags = v22 & 0xFFFFFFE0 | 4;
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManagerRef->pStringManager,
                 (__m128i *)"matrix_d");
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, v, &val, aNone);
  v23 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v23->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  v24 = val.Flags;
  *(float *)&v[0].pNode = this->Matrix.M[0][3] * 0.05000000074505806;
  *(double *)&v53.Flags = *(float *)&v[0].pNode;
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    v24 = val.Flags;
  }
  val.value.VNumber = *(double *)&v53.Flags;
  val.Flags = v24 & 0xFFFFFFE0 | 4;
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManagerRef->pStringManager,
                 (__m128i *)"matrix_tx");
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, v, &val, aNone);
  v25 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v25->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  v26 = val.Flags;
  *(float *)&v[0].pNode = this->Matrix.M[1][3] * 0.05000000074505806;
  *(double *)&v53.Flags = *(float *)&v[0].pNode;
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    v26 = val.Flags;
  }
  val.value.VNumber = *(double *)&v53.Flags;
  val.Flags = v26 & 0xFFFFFFE0 | 4;
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManagerRef->pStringManager,
                 (__m128i *)"matrix_ty");
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, v, &val, aNone);
  v27 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v27->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  prop_name.pNode = (Scaleform::GFx::ASStringNode *)LODWORD(this->Corners.x1);
  y2 = this->Corners.y2;
  *(float *)&v51 = this->Corners.x2;
  *((float *)&v51 + 1) = this->Corners.y2;
  *(float *)&v53.Flags = this->Corners.x1;
  *(float *)&v53.Bonus.pWeakProxy = this->Corners.y1;
  *(float *)&v52 = this->Corners.x2;
  v28 = val.Flags;
  *((float *)&v52 + 1) = this->Corners.y1;
  *(float *)&v[0].pNode = *(float *)&prop_name.pNode * 0.05000000074505806;
  *(double *)&v[0].pNode = *(float *)&v[0].pNode;
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    v28 = val.Flags;
  }
  val.value.VNumber = *(double *)&v[0].pNode;
  val.Flags = v28 & 0xFFFFFFE0 | 4;
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManagerRef->pStringManager,
                 (__m128i *)"corner0x");
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, v, &val, aNone);
  v29 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v29->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  v30 = val.Flags;
  *(float *)&v[0].pNode = y2 * 0.05000000074505806;
  *(double *)&v[0].pNode = *(float *)&v[0].pNode;
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    v30 = val.Flags;
  }
  val.value.VNumber = *(double *)&v[0].pNode;
  val.Flags = v30 & 0xFFFFFFE0 | 4;
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManagerRef->pStringManager,
                 (__m128i *)"corner0y");
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, v, &val, aNone);
  v31 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v31->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  v32 = val.Flags;
  *(float *)&v[0].pNode = *(float *)&v51 * 0.05000000074505806;
  *(double *)&v[0].pNode = *(float *)&v[0].pNode;
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    v32 = val.Flags;
  }
  val.value.VNumber = *(double *)&v[0].pNode;
  val.Flags = v32 & 0xFFFFFFE0 | 4;
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManagerRef->pStringManager,
                 (__m128i *)"corner1x");
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, v, &val, aNone);
  v33 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v33->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  v34 = val.Flags;
  *(float *)&v[0].pNode = *((float *)&v51 + 1) * 0.05000000074505806;
  v51 = *(float *)&v[0].pNode;
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    v34 = val.Flags;
  }
  val.value.VNumber = v51;
  val.Flags = v34 & 0xFFFFFFE0 | 4;
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManagerRef->pStringManager,
                 (__m128i *)"corner1y");
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, v, &val, aNone);
  v35 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v35->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  v36 = val.Flags;
  *(float *)&v[0].pNode = *(float *)&v52 * 0.05000000074505806;
  v51 = *(float *)&v[0].pNode;
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    v36 = val.Flags;
  }
  val.value.VNumber = v51;
  val.Flags = v36 & 0xFFFFFFE0 | 4;
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManagerRef->pStringManager,
                 (__m128i *)"corner2x");
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, v, &val, aNone);
  v37 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v37->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  v38 = val.Flags;
  *(float *)&v[0].pNode = *((float *)&v52 + 1) * 0.05000000074505806;
  v52 = *(float *)&v[0].pNode;
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    v38 = val.Flags;
  }
  val.value.VNumber = v52;
  val.Flags = v38 & 0xFFFFFFE0 | 4;
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManagerRef->pStringManager,
                 (__m128i *)"corner2y");
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, v, &val, aNone);
  v39 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v39->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v39);
  v40 = val.Flags;
  *(float *)&v[0].pNode = *(float *)&v53.Flags * 0.05000000074505806;
  v52 = *(float *)&v[0].pNode;
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    v40 = val.Flags;
  }
  val.value.VNumber = v52;
  val.Flags = v40 & 0xFFFFFFE0 | 4;
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManagerRef->pStringManager,
                 (__m128i *)"corner3x");
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, v, &val, aNone);
  v41 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v41->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v41);
  v42 = val.Flags;
  *(float *)&v[0].pNode = *(float *)&v53.Bonus.pWeakProxy * 0.05000000074505806;
  *(double *)&v53.Flags = *(float *)&v[0].pNode;
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    v42 = val.Flags;
  }
  val.value.VNumber = *(double *)&v53.Flags;
  val.Flags = v42 & 0xFFFFFFE0 | 4;
  v[0].pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManagerRef->pStringManager,
                 (__m128i *)"corner3y");
  ++v[0].pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, v, &val, aNone);
  v43 = v[0].pNode;
  --v[0].pNode->RefCount;
  if ( !v43->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
  v53.Flags = 0;
  v53.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Value::AssignUnsafe(&v53, pV);
  Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&this->pArray->SA, &v53);
  if ( (v53.Flags & 0x1F) > 9 )
  {
    if ( (v53.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v53);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v53);
  }
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
  }
  if ( pV && ((unsigned __int8)pV & 1) == 0 )
  {
    RefCount = pV->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      pV->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
    }
  }
}
