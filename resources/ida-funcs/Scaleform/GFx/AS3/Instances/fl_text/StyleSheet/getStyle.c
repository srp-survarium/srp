void __thiscall Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::getStyle(
        Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result,
        const Scaleform::GFx::ASString *styleName)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  unsigned int Size; // eax
  const Scaleform::Render::Text::Style *v6; // edi
  Scaleform::GFx::AS3::Instances::fl::Object *v7; // ecx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ebp
  unsigned int ColorV; // ebx
  Scaleform::GFx::AS3::Instances::fl::Object *pV; // edi
  Scaleform::GFx::AS3::Instances::fl::Object_vtbl *v14; // ebx
  const Scaleform::GFx::AS3::Value *v15; // eax
  const Scaleform::GFx::AS3::Multiname *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  void *v19; // edi
  Scaleform::GFx::AS3::Instances::fl::Object *v20; // edi
  Scaleform::StringDH *FontList; // eax
  Scaleform::GFx::AS3::Instances::fl::Object_vtbl *v22; // ebx
  const Scaleform::GFx::AS3::Value *v23; // eax
  const Scaleform::GFx::AS3::Multiname *v24; // eax
  Scaleform::GFx::ASStringNode *v25; // eax
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v27; // ebx
  Scaleform::GFx::AS3::CheckResult *(__thiscall **p_SetProperty)(struct Scaleform::GFx::AS3::Instances::fl::Object *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Multiname *, const Scaleform::GFx::AS3::Value *); // edi
  const Scaleform::GFx::AS3::Multiname *v29; // eax
  Scaleform::GFx::ASStringNode *v30; // eax
  __m128i *v31; // ebx
  Scaleform::GFx::AS3::Instances::fl::Object *v32; // edi
  Scaleform::GFx::AS3::Instances::fl::Object_vtbl *v33; // ebx
  const Scaleform::GFx::AS3::Value *v34; // eax
  const Scaleform::GFx::AS3::Multiname *v35; // eax
  Scaleform::GFx::ASStringNode *v36; // eax
  Scaleform::GFx::ASStringNode *v37; // eax
  __m128i *v38; // ebx
  Scaleform::GFx::AS3::Instances::fl::Object *v39; // edi
  Scaleform::GFx::AS3::Instances::fl::Object_vtbl *v40; // ebx
  const Scaleform::GFx::AS3::Value *v41; // eax
  const Scaleform::GFx::AS3::Multiname *v42; // eax
  Scaleform::GFx::ASStringNode *v43; // eax
  Scaleform::GFx::ASStringNode *v44; // eax
  __m128i *v45; // ebx
  Scaleform::GFx::AS3::Instances::fl::Object *v46; // edi
  Scaleform::GFx::AS3::Instances::fl::Object_vtbl *v47; // ebx
  const Scaleform::GFx::AS3::Value *v48; // eax
  const Scaleform::GFx::AS3::Multiname *v49; // eax
  Scaleform::GFx::ASStringNode *v50; // eax
  Scaleform::GFx::ASStringNode *v51; // eax
  Scaleform::GFx::AS3::Value::V1U v52; // edx
  Scaleform::GFx::AS3::Instances::fl::Object *v53; // ebx
  Scaleform::GFx::AS3::CheckResult *(__thiscall **v54)(struct Scaleform::GFx::AS3::Instances::fl::Object *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Multiname *, const Scaleform::GFx::AS3::Value *); // edi
  const Scaleform::GFx::AS3::Multiname *v55; // eax
  Scaleform::GFx::ASStringNode *v56; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v57; // ebx
  Scaleform::GFx::AS3::CheckResult *(__thiscall **v58)(struct Scaleform::GFx::AS3::Instances::fl::Object *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Multiname *, const Scaleform::GFx::AS3::Value *); // edi
  const Scaleform::GFx::AS3::Multiname *v59; // eax
  Scaleform::GFx::ASStringNode *v60; // eax
  Scaleform::String::DataDesc *p_mParagraphFormat; // edi
  char v62; // al
  Scaleform::GFx::AS3::Value::V1U v63; // edx
  Scaleform::GFx::AS3::Instances::fl::Object *v64; // ebx
  Scaleform::GFx::AS3::CheckResult *(__thiscall **v65)(struct Scaleform::GFx::AS3::Instances::fl::Object *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Multiname *, const Scaleform::GFx::AS3::Value *); // edi
  const Scaleform::GFx::AS3::Multiname *v66; // eax
  Scaleform::GFx::ASStringNode *v67; // eax
  Scaleform::GFx::AS3::Value::V1U v68; // edx
  Scaleform::GFx::AS3::Instances::fl::Object *v69; // ebx
  Scaleform::GFx::AS3::CheckResult *(__thiscall **v70)(struct Scaleform::GFx::AS3::Instances::fl::Object *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Multiname *, const Scaleform::GFx::AS3::Value *); // edi
  const Scaleform::GFx::AS3::Multiname *v71; // eax
  Scaleform::GFx::ASStringNode *v72; // eax
  bool v73; // zf
  __m128i *v74; // ebx
  Scaleform::GFx::AS3::Instances::fl::Object *v75; // edi
  Scaleform::GFx::AS3::Instances::fl::Object_vtbl *v76; // ebx
  const Scaleform::GFx::AS3::Value *v77; // eax
  const Scaleform::GFx::AS3::Multiname *v78; // eax
  Scaleform::GFx::ASStringNode *v79; // eax
  Scaleform::GFx::ASStringNode *v80; // eax
  __m128i *v81; // ebx
  Scaleform::GFx::AS3::Instances::fl::Object *v82; // edi
  Scaleform::GFx::AS3::Instances::fl::Object_vtbl *v83; // ebx
  const Scaleform::GFx::AS3::Value *v84; // eax
  const Scaleform::GFx::AS3::Multiname *v85; // eax
  Scaleform::GFx::ASStringNode *v86; // eax
  Scaleform::GFx::ASStringNode *v87; // eax
  Scaleform::String::DataDesc *pData; // ebx
  Scaleform::GFx::AS3::Value::V1U v89; // edx
  Scaleform::GFx::AS3::Instances::fl::Object *v90; // edi
  Scaleform::GFx::AS3::CheckResult *(__thiscall **v91)(struct Scaleform::GFx::AS3::Instances::fl::Object *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Multiname *, const Scaleform::GFx::AS3::Value *); // esi
  const Scaleform::GFx::AS3::Multiname *v92; // eax
  Scaleform::GFx::ASStringNode *v93; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v94; // ecx
  Scaleform::GFx::AS3::Instances::fl::Object *v95; // edi
  unsigned int RefCount; // eax
  const Scaleform::GFx::AS3::Value *v97; // [esp+94h] [ebp-60h]
  const Scaleform::GFx::AS3::Value *v98; // [esp+94h] [ebp-60h]
  const Scaleform::GFx::AS3::Value *v99; // [esp+94h] [ebp-60h]
  const Scaleform::GFx::AS3::Value *v100; // [esp+94h] [ebp-60h]
  const Scaleform::GFx::AS3::Value *v101; // [esp+94h] [ebp-60h]
  const Scaleform::GFx::AS3::Value *v102; // [esp+94h] [ebp-60h]
  const Scaleform::GFx::AS3::Value *v103; // [esp+94h] [ebp-60h]
  const Scaleform::Render::Text::Style *pstyle; // [esp+A8h] [ebp-4Ch]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> pobj; // [esp+ACh] [ebp-48h] BYREF
  Scaleform::String colorStr; // [esp+B0h] [ebp-44h] BYREF
  Scaleform::GFx::ASString v107; // [esp+B4h] [ebp-40h] BYREF
  Scaleform::GFx::ASString v; // [esp+B8h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS3::Value name; // [esp+BCh] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value v110; // [esp+CCh] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname v111; // [esp+DCh] [ebp-18h] BYREF

  pNode = styleName->pNode;
  Size = styleName->pNode->Size;
  if ( Size && *pNode->pData == 46 )
  {
    v6 = this->CSS.GetStyle(&this->CSS, 1, pNode->pData + 1, Size - 1);
    pstyle = v6;
  }
  else
  {
    v6 = this->CSS.GetStyle(&this->CSS, 0, pNode->pData, styleName->pNode->Size);
    pstyle = v6;
  }
  if ( v6 )
  {
    Scaleform::GFx::AS3::VM::MakeObject(this->pTraits.pObject->pVM, &pobj);
    pVM = this->pTraits.pObject->pVM;
    StringManagerRef = pVM->StringManagerRef;
    pObject = pVM->PublicNamespace.pObject;
    if ( (v6->mTextFormat.PresentMask & 1) != 0 )
    {
      Scaleform::String::String(&colorStr);
      Scaleform::String::AppendChar(&colorStr, 0x23u);
      ColorV = pstyle->mTextFormat.ColorV;
      Scaleform::String::AppendChar(&colorStr, a0123456789abcd_2[BYTE2(ColorV) >> 4]);
      Scaleform::String::AppendChar(&colorStr, a0123456789abcd_2[BYTE2(ColorV) & 0xF]);
      Scaleform::String::AppendChar(&colorStr, a0123456789abcd_2[BYTE1(ColorV) >> 4]);
      Scaleform::String::AppendChar(&colorStr, a0123456789abcd_2[BYTE1(ColorV) & 0xF]);
      Scaleform::String::AppendChar(&colorStr, a0123456789abcd_2[(unsigned __int8)ColorV >> 4]);
      Scaleform::String::AppendChar(&colorStr, a0123456789abcd_2[ColorV & 0xF]);
      v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, (__m128i *)"color");
      ++v.pNode->RefCount;
      Scaleform::GFx::AS3::Value::Value(&name, &v);
      pV = pobj.pV;
      *(float *)&v107.pNode = COERCE_FLOAT(
                                Scaleform::GFx::ASStringManager::CreateStringNode(
                                  StringManagerRef->pStringManager,
                                  (__m128i *)((colorStr.HeapTypeBits & 0xFFFFFFFC) + 8),
                                  *(_DWORD *)(colorStr.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF));
      ++v107.pNode->RefCount;
      v14 = pV->__vftable;
      Scaleform::GFx::AS3::Value::Value(&v110, &v107);
      v97 = v15;
      Scaleform::GFx::AS3::Multiname::Multiname(&v111, pObject, &name);
      v14->SetProperty(pV, (Scaleform::GFx::AS3::CheckResult *)&styleName, v16, v97);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v111);
      if ( (v110.Flags & 0x1F) > 9 )
      {
        if ( (v110.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v110);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v110);
      }
      v17 = v107.pNode;
      --v107.pNode->RefCount;
      if ( !v17->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      if ( (name.Flags & 0x1F) > 9 )
      {
        if ( (name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
      }
      v18 = v.pNode;
      --v.pNode->RefCount;
      if ( !v18->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      v19 = (void *)(colorStr.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((colorStr.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
    }
    if ( (pstyle->mTextFormat.PresentMask & 4) != 0 )
    {
      *(float *)&v107.pNode = COERCE_FLOAT(
                                Scaleform::GFx::ASStringManager::CreateStringNode(
                                  StringManagerRef->pStringManager,
                                  (__m128i *)"fontFamily"));
      ++v107.pNode->RefCount;
      Scaleform::GFx::AS3::Value::Value(&name, &v107);
      v20 = pobj.pV;
      FontList = Scaleform::Render::Text::TextFormat::GetFontList(&pstyle->mTextFormat);
      v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                  StringManagerRef->pStringManager,
                  (__m128i *)((FontList->HeapTypeBits & 0xFFFFFFFC) + 8),
                  *(_DWORD *)(FontList->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
      ++v.pNode->RefCount;
      v22 = v20->__vftable;
      Scaleform::GFx::AS3::Value::Value(&v110, &v);
      v98 = v23;
      Scaleform::GFx::AS3::Multiname::Multiname(&v111, pObject, &name);
      v22->SetProperty(v20, (Scaleform::GFx::AS3::CheckResult *)&styleName, v24, v98);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v111);
      if ( (v110.Flags & 0x1F) > 9 )
      {
        if ( (v110.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v110);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v110);
      }
      v25 = v.pNode;
      --v.pNode->RefCount;
      if ( !v25->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      if ( (name.Flags & 0x1F) > 9 )
      {
        if ( (name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
      }
      v26 = v107.pNode;
      --v107.pNode->RefCount;
      if ( !v26->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v26);
    }
    if ( (pstyle->mTextFormat.PresentMask & 8) != 0 )
    {
      v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                  StringManagerRef->pStringManager,
                  (__m128i *)"fontSize");
      ++v.pNode->RefCount;
      Scaleform::GFx::AS3::Value::Value(&v110, &v);
      v107.pNode = (Scaleform::GFx::ASStringNode *)pstyle->mTextFormat.FontSize;
      name.Flags = 4;
      name.Bonus.pWeakProxy = 0;
      v27 = pobj.pV;
      *(float *)&v107.pNode = (double)(int)v107.pNode * 0.05000000074505806;
      name.value.VNumber = *(float *)&v107.pNode;
      p_SetProperty = &pobj.pV->SetProperty;
      Scaleform::GFx::AS3::Multiname::Multiname(&v111, pObject, &v110);
      (*p_SetProperty)(v27, (Scaleform::GFx::AS3::CheckResult *)&styleName, v29, &name);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v111);
      if ( (name.Flags & 0x1F) > 9 )
      {
        if ( (name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
      }
      if ( (v110.Flags & 0x1F) > 9 )
      {
        if ( (v110.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v110);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v110);
      }
      v30 = v.pNode;
      --v.pNode->RefCount;
      if ( !v30->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v30);
    }
    if ( (pstyle->mTextFormat.PresentMask & 0x20) != 0 )
    {
      v31 = (__m128i *)"italic";
      if ( (pstyle->mTextFormat.FormatFlags & 2) == 0 )
        v31 = (__m128i *)"normal";
      *(float *)&v107.pNode = COERCE_FLOAT(
                                Scaleform::GFx::ASStringManager::CreateStringNode(
                                  StringManagerRef->pStringManager,
                                  (__m128i *)"fontStyle"));
      ++v107.pNode->RefCount;
      Scaleform::GFx::AS3::Value::Value(&v110, &v107);
      v32 = pobj.pV;
      v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, v31);
      ++v.pNode->RefCount;
      v33 = v32->__vftable;
      Scaleform::GFx::AS3::Value::Value(&name, &v);
      v99 = v34;
      Scaleform::GFx::AS3::Multiname::Multiname(&v111, pObject, &v110);
      v33->SetProperty(v32, (Scaleform::GFx::AS3::CheckResult *)&styleName, v35, v99);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v111);
      if ( (name.Flags & 0x1F) > 9 )
      {
        if ( (name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
      }
      v36 = v.pNode;
      --v.pNode->RefCount;
      if ( !v36->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v36);
      if ( (v110.Flags & 0x1F) > 9 )
      {
        if ( (v110.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v110);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v110);
      }
      v37 = v107.pNode;
      --v107.pNode->RefCount;
      if ( !v37->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v37);
    }
    if ( (pstyle->mTextFormat.PresentMask & 0x10) != 0 )
    {
      v38 = (__m128i *)"bold";
      if ( (pstyle->mTextFormat.FormatFlags & 1) == 0 )
        v38 = (__m128i *)"normal";
      *(float *)&v107.pNode = COERCE_FLOAT(
                                Scaleform::GFx::ASStringManager::CreateStringNode(
                                  StringManagerRef->pStringManager,
                                  (__m128i *)"fontWeight"));
      ++v107.pNode->RefCount;
      Scaleform::GFx::AS3::Value::Value(&v110, &v107);
      v39 = pobj.pV;
      v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, v38);
      ++v.pNode->RefCount;
      v40 = v39->__vftable;
      Scaleform::GFx::AS3::Value::Value(&name, &v);
      v100 = v41;
      Scaleform::GFx::AS3::Multiname::Multiname(&v111, pObject, &v110);
      v40->SetProperty(v39, (Scaleform::GFx::AS3::CheckResult *)&styleName, v42, v100);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v111);
      if ( (name.Flags & 0x1F) > 9 )
      {
        if ( (name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
      }
      v43 = v.pNode;
      --v.pNode->RefCount;
      if ( !v43->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v43);
      if ( (v110.Flags & 0x1F) > 9 )
      {
        if ( (v110.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v110);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v110);
      }
      v44 = v107.pNode;
      --v107.pNode->RefCount;
      if ( !v44->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v44);
    }
    if ( SLOBYTE(pstyle->mTextFormat.PresentMask) < 0 )
    {
      v45 = (__m128i *)"true";
      if ( (pstyle->mTextFormat.FormatFlags & 8) == 0 )
        v45 = (__m128i *)"false";
      *(float *)&v107.pNode = COERCE_FLOAT(
                                Scaleform::GFx::ASStringManager::CreateStringNode(
                                  StringManagerRef->pStringManager,
                                  (__m128i *)"kerning"));
      ++v107.pNode->RefCount;
      Scaleform::GFx::AS3::Value::Value(&v110, &v107);
      v46 = pobj.pV;
      v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, v45);
      ++v.pNode->RefCount;
      v47 = v46->__vftable;
      Scaleform::GFx::AS3::Value::Value(&name, &v);
      v101 = v48;
      Scaleform::GFx::AS3::Multiname::Multiname(&v111, pObject, &v110);
      v47->SetProperty(v46, (Scaleform::GFx::AS3::CheckResult *)&styleName, v49, v101);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v111);
      if ( (name.Flags & 0x1F) > 9 )
      {
        if ( (name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
      }
      v50 = v.pNode;
      --v.pNode->RefCount;
      if ( !v50->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v50);
      if ( (v110.Flags & 0x1F) > 9 )
      {
        if ( (v110.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v110);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v110);
      }
      v51 = v107.pNode;
      --v107.pNode->RefCount;
      if ( !v51->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v51);
    }
    if ( (pstyle->mParagraphFormat.PresentMask & 8) != 0 )
    {
      v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                  StringManagerRef->pStringManager,
                  (__m128i *)"leading");
      ++v.pNode->RefCount;
      Scaleform::GFx::AS3::Value::Value(&v110, &v);
      v52.VInt = pstyle->mParagraphFormat.Leading;
      name.Flags = 2;
      name.Bonus.pWeakProxy = 0;
      name.value.VS._1 = v52;
      v53 = pobj.pV;
      v54 = &pobj.pV->SetProperty;
      Scaleform::GFx::AS3::Multiname::Multiname(&v111, pObject, &v110);
      (*v54)(v53, (Scaleform::GFx::AS3::CheckResult *)&styleName, v55, &name);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v111);
      if ( (name.Flags & 0x1F) > 9 )
      {
        if ( (name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
      }
      if ( (v110.Flags & 0x1F) > 9 )
      {
        if ( (v110.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v110);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v110);
      }
      v56 = v.pNode;
      --v.pNode->RefCount;
      if ( !v56->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v56);
    }
    if ( (pstyle->mTextFormat.PresentMask & 2) != 0 )
    {
      v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                  StringManagerRef->pStringManager,
                  (__m128i *)"letterSpacing");
      ++v.pNode->RefCount;
      Scaleform::GFx::AS3::Value::Value(&v110, &v);
      v107.pNode = (Scaleform::GFx::ASStringNode *)(pstyle->mTextFormat.LetterSpacing / 20);
      v57 = pobj.pV;
      name.Flags = 4;
      name.Bonus.pWeakProxy = 0;
      name.value.VNumber = (double)(int)v107.pNode;
      v58 = &pobj.pV->SetProperty;
      Scaleform::GFx::AS3::Multiname::Multiname(&v111, pObject, &v110);
      (*v58)(v57, (Scaleform::GFx::AS3::CheckResult *)&styleName, v59, &name);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v111);
      if ( (name.Flags & 0x1F) > 9 )
      {
        if ( (name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
      }
      if ( (v110.Flags & 0x1F) > 9 )
      {
        if ( (v110.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v110);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v110);
      }
      v60 = v.pNode;
      --v.pNode->RefCount;
      if ( !v60->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v60);
    }
    p_mParagraphFormat = (Scaleform::String::DataDesc *)&pstyle->mParagraphFormat;
    v62 = LOBYTE(pstyle->mParagraphFormat.PresentMask) >> 4;
    colorStr.pData = (Scaleform::String::DataDesc *)&pstyle->mParagraphFormat;
    if ( (v62 & 1) != 0 )
    {
      v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                  StringManagerRef->pStringManager,
                  (__m128i *)"marginLeft");
      ++v.pNode->RefCount;
      Scaleform::GFx::AS3::Value::Value(&v110, &v);
      v63.VInt = pstyle->mParagraphFormat.LeftMargin;
      name.Flags = 3;
      name.Bonus.pWeakProxy = 0;
      name.value.VS._1 = v63;
      v64 = pobj.pV;
      v65 = &pobj.pV->SetProperty;
      Scaleform::GFx::AS3::Multiname::Multiname(&v111, pObject, &v110);
      (*v65)(v64, (Scaleform::GFx::AS3::CheckResult *)&styleName, v66, &name);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v111);
      if ( (name.Flags & 0x1F) > 9 )
      {
        if ( (name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
      }
      if ( (v110.Flags & 0x1F) > 9 )
      {
        if ( (v110.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v110);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v110);
      }
      v67 = v.pNode;
      --v.pNode->RefCount;
      if ( !v67->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v67);
      p_mParagraphFormat = colorStr.pData;
    }
    if ( (p_mParagraphFormat[1].RefCount & 0x200000) != 0 )
    {
      v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                  StringManagerRef->pStringManager,
                  (__m128i *)"marginRight");
      ++v.pNode->RefCount;
      Scaleform::GFx::AS3::Value::Value(&v110, &v);
      v68.VInt = pstyle->mParagraphFormat.RightMargin;
      name.Flags = 3;
      name.Bonus.pWeakProxy = 0;
      name.value.VS._1 = v68;
      v69 = pobj.pV;
      v70 = &pobj.pV->SetProperty;
      Scaleform::GFx::AS3::Multiname::Multiname(&v111, pObject, &v110);
      (*v70)(v69, (Scaleform::GFx::AS3::CheckResult *)&styleName, v71, &name);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v111);
      if ( (name.Flags & 0x1F) > 9 )
      {
        if ( (name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
      }
      if ( (v110.Flags & 0x1F) > 9 )
      {
        if ( (v110.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v110);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v110);
      }
      v72 = v.pNode;
      --v.pNode->RefCount;
      if ( !v72->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v72);
    }
    v73 = (pstyle->mParagraphFormat.PresentMask & 1) == 0;
    colorStr.pData = (Scaleform::String::DataDesc *)&pstyle->mParagraphFormat;
    if ( !v73 )
    {
      if ( ((pstyle->mParagraphFormat.PresentMask >> 9) & 3) != 0 )
      {
        if ( ((pstyle->mParagraphFormat.PresentMask >> 9) & 3) == 3 )
        {
          v74 = (__m128i *)"center";
        }
        else
        {
          v74 = (__m128i *)"right";
          if ( !(unsigned __int8)Scaleform::Render::Text::ParagraphFormat::IsRightAlignment(&pstyle->mParagraphFormat) )
            v74 = (__m128i *)"justify";
        }
      }
      else
      {
        v74 = (__m128i *)"left";
      }
      *(float *)&v107.pNode = COERCE_FLOAT(
                                Scaleform::GFx::ASStringManager::CreateStringNode(
                                  StringManagerRef->pStringManager,
                                  (__m128i *)"textAlign"));
      ++v107.pNode->RefCount;
      Scaleform::GFx::AS3::Value::Value(&v110, &v107);
      v75 = pobj.pV;
      v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, v74);
      ++v.pNode->RefCount;
      v76 = v75->__vftable;
      Scaleform::GFx::AS3::Value::Value(&name, &v);
      v102 = v77;
      Scaleform::GFx::AS3::Multiname::Multiname(&v111, pObject, &v110);
      v76->SetProperty(v75, (Scaleform::GFx::AS3::CheckResult *)&styleName, v78, v102);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v111);
      if ( (name.Flags & 0x1F) > 9 )
      {
        if ( (name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
      }
      v79 = v.pNode;
      --v.pNode->RefCount;
      if ( !v79->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v79);
      if ( (v110.Flags & 0x1F) > 9 )
      {
        if ( (v110.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v110);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v110);
      }
      v80 = v107.pNode;
      --v107.pNode->RefCount;
      if ( !v80->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v80);
    }
    if ( (pstyle->mTextFormat.PresentMask & 0x40) != 0 )
    {
      v81 = (__m128i *)"underline";
      if ( (pstyle->mTextFormat.FormatFlags & 4) == 0 )
        v81 = (__m128i *)"none";
      *(float *)&v107.pNode = COERCE_FLOAT(
                                Scaleform::GFx::ASStringManager::CreateStringNode(
                                  StringManagerRef->pStringManager,
                                  (__m128i *)"textDecoration"));
      ++v107.pNode->RefCount;
      Scaleform::GFx::AS3::Value::Value(&v110, &v107);
      v82 = pobj.pV;
      v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, v81);
      ++v.pNode->RefCount;
      v83 = v82->__vftable;
      Scaleform::GFx::AS3::Value::Value(&name, &v);
      v103 = v84;
      Scaleform::GFx::AS3::Multiname::Multiname(&v111, pObject, &v110);
      v83->SetProperty(v82, (Scaleform::GFx::AS3::CheckResult *)&styleName, v85, v103);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v111);
      if ( (name.Flags & 0x1F) > 9 )
      {
        if ( (name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
      }
      v86 = v.pNode;
      --v.pNode->RefCount;
      if ( !v86->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v86);
      if ( (v110.Flags & 0x1F) > 9 )
      {
        if ( (v110.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v110);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v110);
      }
      v87 = v107.pNode;
      --v107.pNode->RefCount;
      if ( !v87->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v87);
    }
    pData = colorStr.pData;
    if ( (colorStr.pData[1].RefCount & 0x40000) != 0 )
    {
      v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                  StringManagerRef->pStringManager,
                  (__m128i *)"textIndent");
      ++v.pNode->RefCount;
      Scaleform::GFx::AS3::Value::Value(&v110, &v);
      v89.VInt = *(__int16 *)&pData->Data[2];
      name.Flags = 2;
      name.Bonus.pWeakProxy = 0;
      name.value.VS._1 = v89;
      v90 = pobj.pV;
      v91 = &pobj.pV->SetProperty;
      Scaleform::GFx::AS3::Multiname::Multiname(&v111, pObject, &v110);
      (*v91)(v90, (Scaleform::GFx::AS3::CheckResult *)&styleName, v92, &name);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v111);
      if ( (name.Flags & 0x1F) > 9 )
      {
        if ( (name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
      }
      if ( (v110.Flags & 0x1F) > 9 )
      {
        if ( (v110.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v110);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v110);
      }
      v93 = v.pNode;
      --v.pNode->RefCount;
      if ( !v93->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v93);
    }
    v94 = result->pObject;
    v95 = pobj.pV;
    if ( pobj.pV != result->pObject )
    {
      if ( v94 )
      {
        if ( ((unsigned __int8)v94 & 1) != 0 )
        {
          result->pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v94 - 1);
          result->pObject = v95;
          return;
        }
        RefCount = v94->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v94->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v94);
        }
      }
      result->pObject = v95;
    }
  }
  else
  {
    v7 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v7 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v7 - 1);
        result->pObject = 0;
      }
      else
      {
        v8 = v7->RefCount;
        if ( (v8 & 0x3FFFFF) != 0 )
        {
          v7->RefCount = v8 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
        result->pObject = 0;
      }
    }
  }
}
