// local variable allocation has failed, the output may be wrong!
void __thiscall Scaleform::GFx::AS3::AvmTextField::ProceedImageSubstitution(
        Scaleform::GFx::AS3::AvmTextField *this,
        Scaleform::GFx::AS3::VM *vm,
        int idx,
        const Scaleform::GFx::AS3::Value *ve)
{
  unsigned int v4; // eax
  Scaleform::GFx::TextField *pDispObj; // ebp
  Scaleform::GFx::AS3::Instances::fl::Object *VFunct; // eax
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // eax
  unsigned int Length; // ebx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // ecx
  unsigned int *p_RefCount; // eax
  int v15; // ebp
  Scaleform::GFx::AS3::StringManager *v16; // ecx
  Scaleform::GFx::ASString *ConstString; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::ImageResource *ImageResource; // ebx
  Scaleform::GFx::Resource *v20; // eax
  Scaleform::GFx::Resource *v21; // edi
  Scaleform::Render::ImageBase *pImage; // ebx
  Scaleform::GFx::ResourceReport *(__thiscall *GetResourceReport)(Scaleform::GFx::Resource *); // eax
  Scaleform::GFx::Resource *v24; // edi
  Scaleform::RefCountVImpl *v25; // eax
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::Render::Text::ImageDesc *v27; // ecx
  bool v28; // zf
  Scaleform::GFx::ResourceReport *(__thiscall *v29)(Scaleform::GFx::Resource *); // edx
  Scaleform::RefCountVImpl *v30; // edi
  Scaleform::GFx::ASStringNode *v31; // eax
  Scaleform::GFx::ASString *v32; // eax
  Scaleform::GFx::ASStringNode *v33; // eax
  char *v34; // edi
  Scaleform::GFx::ASString *v35; // eax
  Scaleform::GFx::ASStringNode *v36; // eax
  Scaleform::GFx::ASString *v37; // eax
  Scaleform::GFx::ASStringNode *v38; // eax
  Scaleform::GFx::ASString *v39; // eax
  Scaleform::GFx::ASStringNode *v40; // eax
  double v41; // st7
  Scaleform::GFx::AS3::StringManager *v42; // ecx
  Scaleform::GFx::ASString *v43; // eax
  Scaleform::GFx::ASStringNode *v44; // eax
  Scaleform::GFx::TextField *v45; // edi
  Scaleform::Render::Text::ImageDesc *v46; // eax
  Scaleform::Render::Text::ImageDesc *v47; // eax
  Scaleform::Render::Text::ImageDesc *v48; // esi
  Scaleform::Render::Image *v49; // ecx
  double v50; // st7
  char *v51; // eax
  Scaleform::Render::Matrix2x4<float> *p_Matrix; // eax
  Scaleform::GFx::ASStringNode *v53; // eax
  float sy; // [esp+5Ch] [ebp-17Ch]
  Scaleform::GFx::AS3::CheckResult result[4]; // [esp+70h] [ebp-168h] BYREF
  long double v; // [esp+74h] [ebp-164h] BYREF
  Scaleform::GFx::ASString str; // [esp+7Ch] [ebp-15Ch] BYREF
  Scaleform::GFx::AS3::AvmTextField *v58; // [esp+80h] [ebp-158h]
  long double baseLineX; // [esp+84h] [ebp-154h] OVERLAPPED BYREF
  Scaleform::GFx::ASString origWidth; // [esp+8Ch] [ebp-14Ch] BYREF
  Scaleform::Render::Rect<unsigned long> dimr; // [esp+90h] [ebp-148h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Object *peobj; // [esp+A0h] [ebp-138h] BYREF
  Scaleform::GFx::AS3::Value val; // [esp+A4h] [ebp-134h] BYREF
  float screenHeight; // [esp+B4h] [ebp-124h]
  float screenWidth; // [esp+B8h] [ebp-120h]
  const char *idStr; // [esp+BCh] [ebp-11Ch]
  Scaleform::GFx::TextField *ptextField; // [esp+C0h] [ebp-118h]
  Scaleform::Render::Text::DocView::ImageSubstitutor *pimgSubst; // [esp+C4h] [ebp-114h]
  Scaleform::GFx::AS3::Multiname mn; // [esp+C8h] [ebp-110h] BYREF
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element isElem; // [esp+E0h] [ebp-F8h] BYREF
  Scaleform::GFx::ImageCreateInfo cinfo; // [esp+110h] [ebp-C8h] BYREF
  Scaleform::GFx::AS3::Multiname mn1; // [esp+130h] [ebp-A8h] BYREF
  Scaleform::StringBuffer sb; // [esp+148h] [ebp-90h] BYREF
  Scaleform::GFx::AS3::Multiname mn5; // [esp+160h] [ebp-78h] BYREF
  Scaleform::GFx::AS3::Multiname mn2; // [esp+178h] [ebp-60h] BYREF
  Scaleform::GFx::AS3::Multiname mn6; // [esp+190h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Multiname mn3; // [esp+1A8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Multiname mn4; // [esp+1C0h] [ebp-18h] BYREF

  v4 = (ve->Flags & 0x1F) - 12;
  v58 = this;
  if ( v4 <= 3 )
  {
    pDispObj = (Scaleform::GFx::TextField *)this->pDispObj;
    VFunct = ve->value.VS._1.VFunct;
    ptextField = pDispObj;
    peobj = VFunct;
    val.Flags = 0;
    val.Bonus.pWeakProxy = 0;
    pimgSubst = Scaleform::GFx::TextField::CreateImageSubstitutor(pDispObj);
    if ( !pimgSubst )
    {
LABEL_82:
      Scaleform::GFx::AS3::Value::~Value(&val);
      return;
    }
    StringManagerRef = vm->StringManagerRef;
    isElem.pImageDesc.pObject = 0;
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        StringManagerRef->pStringManager,
                        "subString",
                        9u,
                        0);
    ++ConstStringNode->RefCount;
    LODWORD(baseLineX) = ConstStringNode;
    Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&dimr, (const Scaleform::GFx::ASString *)&baseLineX);
    pObject = vm->PublicNamespace.pObject;
    mn.Kind = MN_QName;
    mn.Obj.pObject = pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    mn.Name.Flags = 0;
    mn.Name.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&mn, (const Scaleform::GFx::AS3::Value *)&dimr);
    Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&dimr);
    v28 = ConstStringNode->RefCount-- == 1;
    if ( v28 )
      Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
    if ( !peobj->GetProperty(peobj, &result[3], &mn, &val)->Result )
    {
      Scaleform::GFx::DisplayObject::GetName(v58->pDispObj, (Scaleform::GFx::ASString *)&baseLineX);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        &pDispObj->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
        "%s.setImageSubstitutions() failed for #%d element - subString should be specified",
        *(const char **)LODWORD(baseLineX),
        idx);
      v53 = (Scaleform::GFx::ASStringNode *)LODWORD(baseLineX);
      --*(_DWORD *)(LODWORD(baseLineX) + 12);
      if ( !v53->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v53);
      goto LABEL_79;
    }
    Scaleform::GFx::AS3::Value::ToStringValue(&val, &result[3], (Scaleform::GFx::ASStringNode *)vm->StringManagerRef);
    str.pNode = (Scaleform::GFx::ASStringNode *)LODWORD(val.value.VNumber);
    ++*(_DWORD *)(val.value.VS._1.VInt + 12);
    Length = Scaleform::GFx::ASConstString::GetLength(&str);
    if ( Length > 0xF )
    {
      Scaleform::GFx::DisplayObject::GetName(v58->pDispObj, &origWidth);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        &pDispObj->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
        "%s.setImageSubstitutions() failed for #%d element - length of subString should not exceed 15 characters",
        origWidth.pNode->pData,
        idx);
      pNode = origWidth.pNode;
      --origWidth.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v12 = str.pNode;
      --str.pNode->RefCount;
      if ( !v12->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
LABEL_79:
      Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
      v27 = isElem.pImageDesc.pObject;
      v28 = isElem.pImageDesc.pObject == 0;
LABEL_80:
      if ( !v28 )
        Scaleform::RefCountNTSImpl::Release(v27);
      goto LABEL_82;
    }
    Scaleform::UTF8Util::DecodeString(isElem.SubString, str.pNode->pData, str.pNode->Size + 1);
    v13 = str.pNode;
    p_RefCount = &str.pNode->RefCount;
    isElem.SubStringLen = Length;
    --str.pNode->RefCount;
    v15 = 0;
    if ( !*p_RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v16 = vm->StringManagerRef;
    screenWidth = 0.0;
    screenHeight = 0.0;
    *(float *)&origWidth.pNode = 0.0;
    *(float *)&str.pNode = 0.0;
    idStr = 0;
    *(float *)&baseLineX = 0.0;
    ConstString = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                    v16,
                    (Scaleform::GFx::ASString *)&v,
                    "image");
    Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&dimr, ConstString);
    Scaleform::GFx::AS3::Multiname::Multiname(
      &mn1,
      vm->PublicNamespace.pObject,
      (const Scaleform::GFx::AS3::Value *)&dimr);
    Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&dimr);
    v18 = (Scaleform::GFx::ASStringNode *)LODWORD(v);
    --*(_DWORD *)(LODWORD(v) + 12);
    if ( !v18->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    if ( !peobj->GetProperty(peobj, &result[3], &mn1, &val)->Result
      || !Scaleform::GFx::AS3::VM::IsOfType(
            vm,
            &val,
            "flash.display.BitmapData",
            (Scaleform::GFx::ASStringNode *)vm->CurrentDomain) )
    {
      goto LABEL_33;
    }
    ImageResource = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::GetImageResource((Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)val.value.VS._1.VInt);
    v20 = v58->pDispObj->GetResourceMovieDef(v58->pDispObj);
    v21 = v20;
    LODWORD(v) = v20;
    if ( v20 )
      Scaleform::RefCountImpl::AddRef(v20);
    if ( ImageResource->pImage->GetImageType(ImageResource->pImage) )
    {
      pImage = ImageResource->pImage;
      if ( pImage )
        pImage->AddRef(pImage);
      v15 = (int)pImage;
    }
    else
    {
      GetResourceReport = v21[1].GetResourceReport;
      v24 = v21 + 1;
      v25 = (Scaleform::RefCountVImpl *)((int (__thiscall *)(Scaleform::GFx::Resource *, int))GetResourceReport)(
                                          v24,
                                          11);
      result[3].Result = v25 == 0;
      if ( v25 )
        Scaleform::RefCountImpl::Release(v25);
      if ( result[3].Result )
      {
        Scaleform::LogDebugMessage((Scaleform::LogMessageId)135168, "ImageCreator is null in ProceedImageSubstitution");
        v21 = (Scaleform::GFx::Resource *)LODWORD(v);
LABEL_30:
        if ( v21 )
          Scaleform::GFx::Resource::Release(v21);
        if ( v15 )
        {
          v32 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                  vm->StringManagerRef,
                  (Scaleform::GFx::ASString *)&v,
                  "width");
          Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&dimr, v32);
          Scaleform::GFx::AS3::Multiname::Multiname(
            &mn2,
            vm->PublicNamespace.pObject,
            (const Scaleform::GFx::AS3::Value *)&dimr);
          Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&dimr);
          v33 = (Scaleform::GFx::ASStringNode *)LODWORD(v);
          --*(_DWORD *)(LODWORD(v) + 12);
          if ( !v33->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v33);
          v34 = (char *)peobj;
          if ( peobj->GetProperty(peobj, &result[3], &mn2, &val)->Result )
          {
            Scaleform::GFx::AS3::Value::Convert2NumberInline(&val, &result[3], &v);
            screenWidth = v * 20.0;
          }
          v35 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                  vm->StringManagerRef,
                  (Scaleform::GFx::ASString *)&v,
                  "height");
          Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&dimr, v35);
          Scaleform::GFx::AS3::Multiname::Multiname(
            &mn3,
            vm->PublicNamespace.pObject,
            (const Scaleform::GFx::AS3::Value *)&dimr);
          Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&dimr);
          v36 = (Scaleform::GFx::ASStringNode *)LODWORD(v);
          --*(_DWORD *)(LODWORD(v) + 12);
          if ( !v36->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v36);
          if ( *(_BYTE *)(*(int (__thiscall **)(char *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(*(_DWORD *)v34 + 16))(
                           v34,
                           &result[3],
                           &mn3,
                           &val) )
          {
            Scaleform::GFx::AS3::Value::Convert2NumberInline(&val, &result[3], &v);
            screenHeight = v * 20.0;
          }
          v37 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                  vm->StringManagerRef,
                  (Scaleform::GFx::ASString *)&v,
                  "baseLineX");
          Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&dimr, v37);
          Scaleform::GFx::AS3::Multiname::Multiname(
            &mn4,
            vm->PublicNamespace.pObject,
            (const Scaleform::GFx::AS3::Value *)&dimr);
          Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&dimr);
          v38 = (Scaleform::GFx::ASStringNode *)LODWORD(v);
          --*(_DWORD *)(LODWORD(v) + 12);
          if ( !v38->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v38);
          if ( *(_BYTE *)(*(int (__thiscall **)(char *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(*(_DWORD *)v34 + 16))(
                           v34,
                           &result[3],
                           &mn4,
                           &val) )
          {
            Scaleform::GFx::AS3::Value::Convert2NumberInline(&val, &result[3], &baseLineX);
            *(float *)&baseLineX = baseLineX * 20.0;
          }
          v39 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                  vm->StringManagerRef,
                  (Scaleform::GFx::ASString *)&v,
                  "baseLineY");
          Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&dimr, v39);
          Scaleform::GFx::AS3::Multiname::Multiname(
            &mn5,
            vm->PublicNamespace.pObject,
            (const Scaleform::GFx::AS3::Value *)&dimr);
          Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&dimr);
          v40 = (Scaleform::GFx::ASStringNode *)LODWORD(v);
          --*(_DWORD *)(LODWORD(v) + 12);
          if ( !v40->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v40);
          if ( *(_BYTE *)(*(int (__thiscall **)(char *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(*(_DWORD *)v34 + 16))(
                           v34,
                           &result[3],
                           &mn5,
                           &val) )
          {
            Scaleform::GFx::AS3::Value::Convert2NumberInline(&val, &result[3], &v);
            v41 = v * 20.0;
          }
          else
          {
            v41 = *(float *)&str.pNode - 20.0;
          }
          v42 = vm->StringManagerRef;
          *(float *)&v = v41;
          v43 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                  v42,
                  (Scaleform::GFx::ASString *)&peobj,
                  "id");
          Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&dimr, v43);
          Scaleform::GFx::AS3::Multiname::Multiname(
            &mn6,
            vm->PublicNamespace.pObject,
            (const Scaleform::GFx::AS3::Value *)&dimr);
          Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&dimr);
          v44 = (Scaleform::GFx::ASStringNode *)peobj;
          --peobj->pPrev;
          if ( !v44->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v44);
          Scaleform::StringBuffer::StringBuffer(&sb, Scaleform::Memory::pGlobalHeap);
          if ( *(_BYTE *)(*(int (__thiscall **)(char *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(*(_DWORD *)v34 + 16))(
                           v34,
                           &result[3],
                           &mn6,
                           &val) )
          {
            Scaleform::GFx::AS3::Value::Convert2String(&val, v34, &result[3], &sb);
            idStr = sb.pData;
            if ( !sb.pData )
              idStr = (const char *)&buf;
          }
          v45 = ptextField;
          v46 = (Scaleform::Render::Text::ImageDesc *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,78>::operator new(
                                                        0x40u,
                                                        (Scaleform::MemAddressStub *)ptextField);
          if ( v46 )
          {
            Scaleform::Render::Text::ImageDesc::ImageDesc(v46);
            v48 = v47;
          }
          else
          {
            v48 = 0;
          }
          if ( isElem.pImageDesc.pObject )
            Scaleform::RefCountNTSImpl::Release(isElem.pImageDesc.pObject);
          isElem.pImageDesc.pObject = v48;
          (*(void (__thiscall **)(int))(*(_DWORD *)v15 + 4))(v15);
          v49 = v48->pImage.pObject;
          if ( v49 )
            v49->Release(v49);
          v50 = *(float *)&baseLineX;
          v48->pImage.pObject = (Scaleform::Render::Image *)v15;
          isElem.pImageDesc.pObject->BaseLineX = v50 * 0.05000000074505806;
          isElem.pImageDesc.pObject->BaseLineY = 0.05000000074505806 * *(float *)&v;
          isElem.pImageDesc.pObject->ScreenWidth = screenWidth;
          v51 = (char *)idStr;
          isElem.pImageDesc.pObject->ScreenHeight = screenHeight;
          if ( v51 )
            Scaleform::GFx::TextField::AddIdImageDescAssoc(v45, v51, isElem.pImageDesc.pObject);
          p_Matrix = &isElem.pImageDesc.pObject->Matrix;
          *(float *)&baseLineX = -isElem.pImageDesc.pObject->BaseLineY;
          isElem.pImageDesc.pObject->Matrix.M[0][3] = isElem.pImageDesc.pObject->Matrix.M[0][3]
                                                    - isElem.pImageDesc.pObject->BaseLineX;
          p_Matrix->M[1][3] = *(float *)&baseLineX + p_Matrix->M[1][3];
          *(float *)&baseLineX = isElem.pImageDesc.pObject->ScreenHeight / *(float *)&str.pNode;
          sy = *(float *)&baseLineX;
          *(float *)&baseLineX = isElem.pImageDesc.pObject->ScreenWidth / *(float *)&origWidth.pNode;
          Scaleform::Render::Matrix2x4<float>::AppendScaling(
            &isElem.pImageDesc.pObject->Matrix,
            *(float *)&baseLineX,
            sy);
          Scaleform::Render::Text::DocView::ImageSubstitutor::AddImageDesc(pimgSubst, &isElem);
          v45->pDocument.pObject->RTFlags |= 2u;
          Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v58->pDispObj);
          Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&sb);
          Scaleform::GFx::AS3::Multiname::~Multiname(&mn6);
          Scaleform::GFx::AS3::Multiname::~Multiname(&mn5);
          Scaleform::GFx::AS3::Multiname::~Multiname(&mn4);
          Scaleform::GFx::AS3::Multiname::~Multiname(&mn3);
          Scaleform::GFx::AS3::Multiname::~Multiname(&mn2);
          goto LABEL_44;
        }
LABEL_33:
        Scaleform::GFx::DisplayObject::GetName(v58->pDispObj, (Scaleform::GFx::ASString *)&v);
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
          &ptextField->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
          "%s.setImageSubstitutions() failed for #%d element - 'image' is not specified or not a BitmapData",
          *(const char **)LODWORD(v),
          idx);
        v26 = (Scaleform::GFx::ASStringNode *)LODWORD(v);
        --*(_DWORD *)(LODWORD(v) + 12);
        if ( !v26->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v26);
        Scaleform::GFx::AS3::Multiname::~Multiname(&mn1);
        Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
        v27 = isElem.pImageDesc.pObject;
        v28 = isElem.pImageDesc.pObject == 0;
        goto LABEL_80;
      }
      cinfo.pHeap = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v58);
      cinfo.Use = 1;
      cinfo.RUse = Use_Bitmap;
      memset(&cinfo.pLog, 0, 16);
      v29 = v24->GetResourceReport;
      cinfo.Type = Create_SourceImage;
      v30 = (Scaleform::RefCountVImpl *)((int (__thiscall *)(Scaleform::GFx::Resource *, int))v29)(v24, 11);
      v15 = ((int (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::ImageCreateInfo *, Scaleform::Render::ImageBase *))v30->__vftable[1].AddRef)(
              v30,
              &cinfo,
              ImageResource->pImage);
      Scaleform::RefCountImpl::Release(v30);
      v21 = (Scaleform::GFx::Resource *)LODWORD(v);
    }
    if ( v15 )
    {
      (*(void (__thiscall **)(int, Scaleform::Render::Rect<unsigned long> *))(*(_DWORD *)v15 + 24))(v15, &dimr);
      *(float *)&origWidth.pNode = (float)(dimr.x2 - dimr.x1);
      LODWORD(v) = dimr.y2 - dimr.y1;
      *(float *)&str.pNode = (float)(dimr.y2 - dimr.y1);
      screenWidth = *(float *)&origWidth.pNode * 20.0;
      screenHeight = 20.0 * *(float *)&str.pNode;
      if ( 0.0 == *(float *)&origWidth.pNode || *(float *)&str.pNode == 0.0 )
      {
        Scaleform::GFx::DisplayObject::GetName(v58->pDispObj, (Scaleform::GFx::ASString *)&v);
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
          &ptextField->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
          "%s.setImageSubstitutions() failed for #%d element - image has one zero dimension",
          *(const char **)LODWORD(v),
          idx);
        v31 = (Scaleform::GFx::ASStringNode *)LODWORD(v);
        --*(_DWORD *)(LODWORD(v) + 12);
        if ( !v31->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v31);
        if ( v21 )
          Scaleform::GFx::Resource::Release(v21);
LABEL_44:
        Scaleform::GFx::AS3::Multiname::~Multiname(&mn1);
        (*(void (__thiscall **)(int))(*(_DWORD *)v15 + 8))(v15);
        Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
        v27 = isElem.pImageDesc.pObject;
        v28 = isElem.pImageDesc.pObject == 0;
        goto LABEL_80;
      }
    }
    goto LABEL_30;
  }
}
