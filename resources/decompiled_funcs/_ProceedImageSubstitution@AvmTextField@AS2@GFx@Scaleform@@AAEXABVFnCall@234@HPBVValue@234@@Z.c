void __thiscall Scaleform::GFx::AS2::AvmTextField::ProceedImageSubstitution(
        Scaleform::GFx::AS2::AvmTextField *this,
        const Scaleform::GFx::AS2::FnCall *fn,
        int idx,
        Scaleform::GFx::AS2::Value *pve)
{
  Scaleform::GFx::TextField *pDispObj; // ebp
  Scaleform::GFx::AS2::Object *v6; // esi
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::ObjectInterface *v8; // esi
  unsigned int Length; // ebx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // ecx
  unsigned int *p_RefCount; // eax
  Scaleform::Render::ImageBase *pImage; // ebp
  Scaleform::GFx::AS2::Environment *v15; // eax
  Scaleform::GFx::AS2::Object *v16; // eax
  Scaleform::GFx::AS2::Object *v17; // ebx
  int *v18; // ecx
  int v19; // edx
  Scaleform::GFx::Resource *v20; // eax
  Scaleform::GFx::Resource *v21; // ebx
  Scaleform::GFx::Resource *v22; // esi
  Scaleform::RefCountVImpl *v23; // eax
  Scaleform::GFx::ResourceReport *(__thiscall *GetResourceReport)(Scaleform::GFx::Resource *); // edx
  Scaleform::RefCountVImpl *v25; // esi
  Scaleform::GFx::ASStringNode *v26; // eax
  double v27; // st7
  Scaleform::GFx::AS2::Environment *v28; // eax
  Scaleform::GFx::ASStringNode *v29; // ecx
  const char *v30; // edx
  bool v31; // zf
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::Render::Text::ImageDesc *v33; // eax
  Scaleform::Render::Text::ImageDesc *v34; // eax
  Scaleform::Render::Text::ImageDesc *v35; // esi
  Scaleform::Render::Image *pObject; // ecx
  double v37; // st7
  char *v38; // eax
  Scaleform::Render::Matrix2x4<float> *p_Matrix; // eax
  Scaleform::GFx::AS2::AvmTextField *v40; // edx
  Scaleform::GFx::AS2::Environment *sy; // [esp+10h] [ebp-B8h]
  const char *sya; // [esp+10h] [ebp-B8h]
  const char *idStr; // [esp+24h] [ebp-A4h] BYREF
  Scaleform::GFx::ASString baseLineY; // [esp+28h] [ebp-A0h] BYREF
  Scaleform::GFx::ASString str; // [esp+2Ch] [ebp-9Ch] BYREF
  int v46; // [esp+30h] [ebp-98h]
  Scaleform::GFx::AS2::AvmTextField *v47; // [esp+34h] [ebp-94h]
  Scaleform::GFx::ASString origWidth; // [esp+38h] [ebp-90h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+3Ch] [ebp-8Ch] BYREF
  Scaleform::GFx::TextField *ptextField; // [esp+4Ch] [ebp-7Ch]
  float screenWidth; // [esp+50h] [ebp-78h]
  Scaleform::GFx::ImageResource *pimgRes; // [esp+54h] [ebp-74h]
  float screenHeight; // [esp+58h] [ebp-70h]
  Scaleform::GFx::AS2::ObjectInterface *v54; // [esp+5Ch] [ebp-6Ch]
  float baseLineX; // [esp+60h] [ebp-68h]
  Scaleform::Render::Text::DocView::ImageSubstitutor *pimgSubst; // [esp+64h] [ebp-64h]
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element isElem; // [esp+68h] [ebp-60h] BYREF
  Scaleform::Render::Rect<unsigned long> dimr; // [esp+98h] [ebp-30h] BYREF
  Scaleform::GFx::ImageCreateInfo cinfo; // [esp+A8h] [ebp-20h] BYREF

  v47 = this;
  if ( pve && pve->T.Type == 6 )
  {
    pDispObj = (Scaleform::GFx::TextField *)this->pDispObj;
    sy = fn->Env;
    ptextField = pDispObj;
    v6 = Scaleform::GFx::AS2::Value::ToObject(pve, sy);
    val.T.Type = 0;
    pimgSubst = Scaleform::GFx::TextField::CreateImageSubstitutor(pDispObj);
    if ( !pimgSubst )
    {
LABEL_63:
      if ( val.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&val);
      return;
    }
    Env = fn->Env;
    v8 = &v6->Scaleform::GFx::AS2::ObjectInterface;
    isElem.pImageDesc.pObject = 0;
    v54 = v8;
    if ( !Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v8, &Env->StringContext, "subString", &val) )
    {
      Scaleform::GFx::DisplayObject::GetName(this->pDispObj, (Scaleform::GFx::ASString *)&idStr);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        &pDispObj->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
        "%s.setImageSubstitutions() failed for #%d element - subString should be specified",
        *(const char **)idStr,
        idx);
      v11 = (Scaleform::GFx::ASStringNode *)idStr;
LABEL_59:
      if ( !--v11->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
LABEL_61:
      if ( isElem.pImageDesc.pObject )
        Scaleform::RefCountNTSImpl::Release(isElem.pImageDesc.pObject);
      goto LABEL_63;
    }
    Scaleform::GFx::AS2::Value::ToStringImpl(&val, &str, fn->Env, -1, 0);
    Length = Scaleform::GFx::ASConstString::GetLength(&str);
    if ( Length > 0xF )
    {
      Scaleform::GFx::DisplayObject::GetName(v47->pDispObj, &origWidth);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        &pDispObj->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
        "%s.setImageSubstitutions() failed for #%d element - length of subString should not exceed 15 characters",
        origWidth.pNode->pData,
        idx);
      pNode = origWidth.pNode;
      --origWidth.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v11 = str.pNode;
      goto LABEL_59;
    }
    Scaleform::UTF8Util::DecodeString(isElem.SubString, str.pNode->pData, str.pNode->Size + 1);
    v12 = str.pNode;
    p_RefCount = &str.pNode->RefCount;
    isElem.SubStringLen = Length;
    --str.pNode->RefCount;
    pImage = 0;
    if ( !*p_RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    v15 = fn->Env;
    screenWidth = 0.0;
    screenHeight = 0.0;
    *(float *)&origWidth.pNode = 0.0;
    *(float *)&str.pNode = 0.0;
    baseLineX = 0.0;
    *(float *)&idStr = 0.0;
    if ( !Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v8, &v15->StringContext, "image", &val)
      || (v16 = Scaleform::GFx::AS2::Value::ToObject(&val, fn->Env), (v17 = v16) == 0)
      || v16->GetObjectType(&v16->Scaleform::GFx::AS2::ObjectInterface) != Object_BitmapData )
    {
LABEL_26:
      Scaleform::GFx::DisplayObject::GetName(v47->pDispObj, &baseLineY);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        &ptextField->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
        "%s.setImageSubstitutions() failed for #%d element - 'image' is not specified or not a BitmapData",
        baseLineY.pNode->pData,
        idx);
      v11 = baseLineY.pNode;
      goto LABEL_59;
    }
    v18 = (int *)v47->pDispObj;
    v19 = *v18;
    pimgRes = (Scaleform::GFx::ImageResource *)v17[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
    v20 = (Scaleform::GFx::Resource *)(*(int (__thiscall **)(int *))(v19 + 256))(v18);
    v21 = v20;
    baseLineY.pNode = (Scaleform::GFx::ASStringNode *)v20;
    if ( v20 )
      Scaleform::RefCountImpl::AddRef(v20);
    if ( pimgRes->pImage->GetImageType(pimgRes->pImage) )
    {
      pImage = pimgRes->pImage;
      if ( pImage )
      {
        pImage->AddRef(pimgRes->pImage);
LABEL_28:
        if ( pImage )
        {
          pImage->GetRect(pImage, &dimr);
          *(float *)&origWidth.pNode = (float)(dimr.x2 - dimr.x1);
          baseLineY.pNode = (Scaleform::GFx::ASStringNode *)(dimr.y2 - dimr.y1);
          *(float *)&str.pNode = (float)(dimr.y2 - dimr.y1);
          screenWidth = *(float *)&origWidth.pNode * 20.0;
          screenHeight = 20.0 * *(float *)&str.pNode;
          if ( 0.0 == *(float *)&origWidth.pNode || *(float *)&str.pNode == 0.0 )
          {
            Scaleform::GFx::DisplayObject::GetName(v47->pDispObj, &baseLineY);
            Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
              &ptextField->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
              "%s.setImageSubstitutions() failed for #%d element - image has one zero dimension",
              baseLineY.pNode->pData,
              idx);
            v26 = baseLineY.pNode;
            --baseLineY.pNode->RefCount;
            if ( !v26->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v26);
            if ( v21 )
              Scaleform::GFx::Resource::Release(v21);
            pImage->Release(pImage);
            goto LABEL_61;
          }
        }
      }
    }
    else
    {
      v22 = v21 + 1;
      v23 = (Scaleform::RefCountVImpl *)((int (__thiscall *)(Scaleform::GFx::Resource *, int))v21[1].GetResourceReport)(
                                          &v21[1],
                                          11);
      HIBYTE(v46) = v23 == 0;
      if ( v23 )
        Scaleform::RefCountImpl::Release(v23);
      if ( !HIBYTE(v46) )
      {
        cinfo.pHeap = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v47);
        cinfo.Use = 1;
        cinfo.RUse = Use_Bitmap;
        GetResourceReport = v22->GetResourceReport;
        cinfo.Type = Create_SourceImage;
        memset(&cinfo.pLog, 0, 16);
        v25 = (Scaleform::RefCountVImpl *)((int (__thiscall *)(Scaleform::GFx::Resource *, int))GetResourceReport)(
                                            v22,
                                            11);
        pImage = (Scaleform::Render::ImageBase *)((int (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::ImageCreateInfo *, Scaleform::Render::ImageBase *))v25->__vftable[1].AddRef)(
                                                   v25,
                                                   &cinfo,
                                                   pimgRes->pImage);
        Scaleform::RefCountImpl::Release(v25);
        v8 = v54;
        v21 = (Scaleform::GFx::Resource *)baseLineY.pNode;
        goto LABEL_28;
      }
      Scaleform::LogDebugMessage((Scaleform::LogMessageId)135168, "ImageCreator is null in ProceedImageSubstitution");
      v8 = v54;
      v21 = (Scaleform::GFx::Resource *)baseLineY.pNode;
    }
    if ( v21 )
      Scaleform::GFx::Resource::Release(v21);
    if ( pImage )
    {
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v8, &fn->Env->StringContext, "width", &val) )
        screenWidth = Scaleform::GFx::AS2::Value::ToNumber(&val, fn->Env) * 20.0;
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v8, &fn->Env->StringContext, "height", &val) )
        screenHeight = Scaleform::GFx::AS2::Value::ToNumber(&val, fn->Env) * 20.0;
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v8, &fn->Env->StringContext, "baseLineX", &val) )
        baseLineX = Scaleform::GFx::AS2::Value::ToNumber(&val, fn->Env) * 20.0;
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v8, &fn->Env->StringContext, "baseLineY", &val) )
        v27 = Scaleform::GFx::AS2::Value::ToNumber(&val, fn->Env) * 20.0;
      else
        v27 = *(float *)&str.pNode - 20.0;
      v28 = fn->Env;
      *(float *)&baseLineY.pNode = v27;
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v8, &v28->StringContext, "id", &val) )
      {
        Scaleform::GFx::AS2::Value::ToStringImpl(&val, (Scaleform::GFx::ASString *)&idStr, fn->Env, -1, 0);
        v29 = (Scaleform::GFx::ASStringNode *)idStr;
        v30 = *(const char **)idStr;
        v31 = (*((_DWORD *)idStr + 3))-- == 1;
        idStr = v30;
        if ( v31 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      }
      pHeap = fn->Env->StringContext.pContext->pHeap;
      v33 = (Scaleform::Render::Text::ImageDesc *)pHeap->Alloc(pHeap, 64u, 0);
      if ( v33 )
      {
        Scaleform::Render::Text::ImageDesc::ImageDesc(v33);
        v35 = v34;
      }
      else
      {
        v35 = 0;
      }
      if ( isElem.pImageDesc.pObject )
        Scaleform::RefCountNTSImpl::Release(isElem.pImageDesc.pObject);
      isElem.pImageDesc.pObject = v35;
      pImage->AddRef(pImage);
      pObject = v35->pImage.pObject;
      if ( pObject )
        pObject->Release(pObject);
      v37 = baseLineX;
      v35->pImage.pObject = (Scaleform::Render::Image *)pImage;
      isElem.pImageDesc.pObject->BaseLineX = v37 * 0.05000000074505806;
      isElem.pImageDesc.pObject->BaseLineY = 0.05000000074505806 * *(float *)&baseLineY.pNode;
      isElem.pImageDesc.pObject->ScreenWidth = screenWidth;
      v38 = (char *)idStr;
      isElem.pImageDesc.pObject->ScreenHeight = screenHeight;
      if ( v38 )
        Scaleform::GFx::TextField::AddIdImageDescAssoc(ptextField, v38, isElem.pImageDesc.pObject);
      p_Matrix = &isElem.pImageDesc.pObject->Matrix;
      *(float *)&idStr = -isElem.pImageDesc.pObject->BaseLineY;
      isElem.pImageDesc.pObject->Matrix.M[0][3] = isElem.pImageDesc.pObject->Matrix.M[0][3]
                                                - isElem.pImageDesc.pObject->BaseLineX;
      p_Matrix->M[1][3] = p_Matrix->M[1][3] + *(float *)&idStr;
      *(float *)&idStr = isElem.pImageDesc.pObject->ScreenHeight / *(float *)&str.pNode;
      sya = idStr;
      *(float *)&idStr = isElem.pImageDesc.pObject->ScreenWidth / *(float *)&origWidth.pNode;
      Scaleform::Render::Matrix2x4<float>::AppendScaling(
        &isElem.pImageDesc.pObject->Matrix,
        *(float *)&idStr,
        *(float *)&sya);
      Scaleform::Render::Text::DocView::ImageSubstitutor::AddImageDesc(pimgSubst, &isElem);
      v40 = v47;
      ptextField->pDocument.pObject->RTFlags |= 2u;
      Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v40->pDispObj);
      pImage->Release(pImage);
      goto LABEL_61;
    }
    goto LABEL_26;
  }
}
