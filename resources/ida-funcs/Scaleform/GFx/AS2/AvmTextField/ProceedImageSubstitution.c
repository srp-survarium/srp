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
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v12; // ecx
  unsigned int *p_RefCount; // eax
  int SetValue; // ebp
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
  char *pData; // edx
  bool v31; // zf
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::Render::Text::ImageDesc *v33; // eax
  Scaleform::Render::Text::ImageDesc *v34; // eax
  Scaleform::Render::Text::ImageDesc *v35; // esi
  Scaleform::Render::Image *pObject; // ecx
  double v37; // st7
  Scaleform::GFx::ASStringNode *v38; // eax
  Scaleform::Render::Matrix2x4<float> *p_Matrix; // eax
  Scaleform::GFx::AS2::AvmTextField *v40; // edx
  Scaleform::GFx::AS2::Environment *sy; // [esp+10h] [ebp-B8h]
  Scaleform::GFx::ASStringNode *sya; // [esp+10h] [ebp-B8h]
  Scaleform::GFx::ASString sx; // [esp+24h] [ebp-A4h] BYREF
  Scaleform::GFx::ASString v44; // [esp+28h] [ebp-A0h] BYREF
  Scaleform::GFx::ASConstString v45; // [esp+2Ch] [ebp-9Ch] BYREF
  int v46; // [esp+30h] [ebp-98h]
  Scaleform::GFx::AS2::AvmTextField *v47; // [esp+34h] [ebp-94h]
  Scaleform::GFx::ASString result; // [esp+38h] [ebp-90h] BYREF
  Scaleform::GFx::AS2::Value v49; // [esp+3Ch] [ebp-8Ch] BYREF
  Scaleform::GFx::TextField *v50; // [esp+4Ch] [ebp-7Ch]
  float v51; // [esp+50h] [ebp-78h]
  Scaleform::GFx::AS2::Object_vtbl *v52; // [esp+54h] [ebp-74h]
  float v53; // [esp+58h] [ebp-70h]
  Scaleform::GFx::AS2::ObjectInterface *v54; // [esp+5Ch] [ebp-6Ch]
  float v55; // [esp+60h] [ebp-68h]
  Scaleform::Render::Text::DocView::ImageSubstitutor *ImageSubstitutor; // [esp+64h] [ebp-64h]
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element elem; // [esp+68h] [ebp-60h] BYREF
  int v58; // [esp+98h] [ebp-30h] BYREF
  int v59; // [esp+9Ch] [ebp-2Ch]
  int v60; // [esp+A0h] [ebp-28h]
  int v61; // [esp+A4h] [ebp-24h]
  _DWORD v62[8]; // [esp+A8h] [ebp-20h] BYREF

  v47 = this;
  if ( pve && pve->T.Type == 6 )
  {
    pDispObj = (Scaleform::GFx::TextField *)this->pDispObj;
    sy = fn->Env;
    v50 = pDispObj;
    v6 = Scaleform::GFx::AS2::Value::ToObject(pve, sy);
    v49.T.Type = 0;
    ImageSubstitutor = Scaleform::GFx::TextField::CreateImageSubstitutor(pDispObj);
    if ( !ImageSubstitutor )
    {
LABEL_63:
      if ( v49.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v49);
      return;
    }
    Env = fn->Env;
    v8 = &v6->Scaleform::GFx::AS2::ObjectInterface;
    elem.pImageDesc.pObject = 0;
    v54 = v8;
    if ( !Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
            v8,
            (Scaleform::GFx::ASStringNode *)&Env->StringContext,
            "subString",
            &v49) )
    {
      Scaleform::GFx::DisplayObject::GetName(this->pDispObj, &sx);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        &pDispObj->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
        "%s.setImageSubstitutions() failed for #%d element - subString should be specified",
        sx.pNode->pData,
        idx);
      pNode = sx.pNode;
LABEL_59:
      if ( !--pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_61:
      if ( elem.pImageDesc.pObject )
        Scaleform::RefCountNTSImpl::Release(elem.pImageDesc.pObject);
      goto LABEL_63;
    }
    Scaleform::GFx::AS2::Value::ToStringImpl(&v49, (Scaleform::GFx::ASString *)&v45, fn->Env, -1, 0);
    Length = Scaleform::GFx::ASConstString::GetLength(&v45);
    if ( Length > 0xF )
    {
      Scaleform::GFx::DisplayObject::GetName(v47->pDispObj, &result);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        &pDispObj->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
        "%s.setImageSubstitutions() failed for #%d element - length of subString should not exceed 15 characters",
        result.pNode->pData,
        idx);
      v10 = result.pNode;
      --result.pNode->RefCount;
      if ( !v10->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      pNode = v45.pNode;
      goto LABEL_59;
    }
    Scaleform::UTF8Util::DecodeString(elem.SubString, (char *)v45.pNode->pData, v45.pNode->Size + 1);
    v12 = v45.pNode;
    p_RefCount = &v45.pNode->RefCount;
    elem.SubStringLen = Length;
    --v45.pNode->RefCount;
    SetValue = 0;
    if ( !*p_RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    v15 = fn->Env;
    v51 = 0.0;
    v53 = 0.0;
    *(float *)&result.pNode = 0.0;
    *(float *)&v45.pNode = 0.0;
    v55 = 0.0;
    *(float *)&sx.pNode = 0.0;
    if ( !Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
            v8,
            (Scaleform::GFx::ASStringNode *)&v15->StringContext,
            "image",
            &v49)
      || (v16 = Scaleform::GFx::AS2::Value::ToObject(&v49, fn->Env), (v17 = v16) == 0)
      || v16->GetObjectType(&v16->Scaleform::GFx::AS2::ObjectInterface) != Object_BitmapData )
    {
LABEL_26:
      Scaleform::GFx::DisplayObject::GetName(v47->pDispObj, &v44);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        &v50->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
        "%s.setImageSubstitutions() failed for #%d element - 'image' is not specified or not a BitmapData",
        v44.pNode->pData,
        idx);
      pNode = v44.pNode;
      goto LABEL_59;
    }
    v18 = (int *)v47->pDispObj;
    v19 = *v18;
    v52 = v17[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
    v20 = (Scaleform::GFx::Resource *)(*(int (__thiscall **)(int *))(v19 + 256))(v18);
    v21 = v20;
    v44.pNode = (Scaleform::GFx::ASStringNode *)v20;
    if ( v20 )
      Scaleform::RefCountImpl::AddRef(v20);
    if ( (*(int (__thiscall **)(void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::AS2::Value *)))(*(_DWORD *)v52->SetValue + 12))(v52->SetValue) )
    {
      SetValue = (int)v52->SetValue;
      if ( SetValue )
      {
        (*(void (__thiscall **)(void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::AS2::Value *)))(*(_DWORD *)SetValue + 4))(v52->SetValue);
LABEL_28:
        if ( SetValue )
        {
          (*(void (__thiscall **)(int, int *))(*(_DWORD *)SetValue + 24))(SetValue, &v58);
          *(float *)&result.pNode = (float)(unsigned int)(v60 - v58);
          v44.pNode = (Scaleform::GFx::ASStringNode *)(v61 - v59);
          *(float *)&v45.pNode = (float)(unsigned int)(v61 - v59);
          v51 = *(float *)&result.pNode * 20.0;
          v53 = 20.0 * *(float *)&v45.pNode;
          if ( 0.0 == *(float *)&result.pNode || *(float *)&v45.pNode == 0.0 )
          {
            Scaleform::GFx::DisplayObject::GetName(v47->pDispObj, &v44);
            Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
              &v50->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
              "%s.setImageSubstitutions() failed for #%d element - image has one zero dimension",
              v44.pNode->pData,
              idx);
            v26 = v44.pNode;
            --v44.pNode->RefCount;
            if ( !v26->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v26);
            if ( v21 )
              Scaleform::GFx::Resource::Release(v21);
            (*(void (__thiscall **)(int))(*(_DWORD *)SetValue + 8))(SetValue);
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
        v62[1] = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v47);
        v62[2] = 1;
        v62[3] = 1;
        GetResourceReport = v22->GetResourceReport;
        v62[0] = 3;
        memset(&v62[4], 0, 16);
        v25 = (Scaleform::RefCountVImpl *)((int (__thiscall *)(Scaleform::GFx::Resource *, int))GetResourceReport)(
                                            v22,
                                            11);
        SetValue = ((int (__thiscall *)(Scaleform::RefCountVImpl *, _DWORD *, _DWORD))v25->__vftable[1].AddRef)(
                     v25,
                     v62,
                     v52->SetValue);
        Scaleform::RefCountImpl::Release(v25);
        v8 = v54;
        v21 = (Scaleform::GFx::Resource *)v44.pNode;
        goto LABEL_28;
      }
      Scaleform::LogDebugMessage(
        (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&loc_20FFD + 3),
        "ImageCreator is null in ProceedImageSubstitution");
      v8 = v54;
      v21 = (Scaleform::GFx::Resource *)v44.pNode;
    }
    if ( v21 )
      Scaleform::GFx::Resource::Release(v21);
    if ( SetValue )
    {
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
             v8,
             (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext,
             "width",
             &v49) )
      {
        v51 = Scaleform::GFx::AS2::Value::ToNumber(&v49, fn->Env) * 20.0;
      }
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
             v8,
             (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext,
             "height",
             &v49) )
      {
        v53 = Scaleform::GFx::AS2::Value::ToNumber(&v49, fn->Env) * 20.0;
      }
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
             v8,
             (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext,
             "baseLineX",
             &v49) )
      {
        v55 = Scaleform::GFx::AS2::Value::ToNumber(&v49, fn->Env) * 20.0;
      }
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
             v8,
             (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext,
             "baseLineY",
             &v49) )
      {
        v27 = Scaleform::GFx::AS2::Value::ToNumber(&v49, fn->Env) * 20.0;
      }
      else
      {
        v27 = *(float *)&v45.pNode - 20.0;
      }
      v28 = fn->Env;
      *(float *)&v44.pNode = v27;
      if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
             v8,
             (Scaleform::GFx::ASStringNode *)&v28->StringContext,
             "id",
             &v49) )
      {
        Scaleform::GFx::AS2::Value::ToStringImpl(&v49, &sx, fn->Env, -1, 0);
        v29 = sx.pNode;
        pData = (char *)sx.pNode->pData;
        v31 = sx.pNode->RefCount-- == 1;
        sx.pNode = (Scaleform::GFx::ASStringNode *)pData;
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
      if ( elem.pImageDesc.pObject )
        Scaleform::RefCountNTSImpl::Release(elem.pImageDesc.pObject);
      elem.pImageDesc.pObject = v35;
      (*(void (__thiscall **)(int))(*(_DWORD *)SetValue + 4))(SetValue);
      pObject = v35->pImage.pObject;
      if ( pObject )
        pObject->Release(pObject);
      v37 = v55;
      v35->pImage.pObject = (Scaleform::Render::Image *)SetValue;
      elem.pImageDesc.pObject->BaseLineX = v37 * 0.05000000074505806;
      elem.pImageDesc.pObject->BaseLineY = 0.05000000074505806 * *(float *)&v44.pNode;
      elem.pImageDesc.pObject->ScreenWidth = v51;
      v38 = sx.pNode;
      elem.pImageDesc.pObject->ScreenHeight = v53;
      if ( v38 )
        Scaleform::GFx::TextField::AddIdImageDescAssoc(v50, (const __m128i *)v38, elem.pImageDesc.pObject);
      p_Matrix = &elem.pImageDesc.pObject->Matrix;
      *(float *)&sx.pNode = -elem.pImageDesc.pObject->BaseLineY;
      elem.pImageDesc.pObject->Matrix.M[0][3] = elem.pImageDesc.pObject->Matrix.M[0][3]
                                              - elem.pImageDesc.pObject->BaseLineX;
      p_Matrix->M[1][3] = p_Matrix->M[1][3] + *(float *)&sx.pNode;
      *(float *)&sx.pNode = elem.pImageDesc.pObject->ScreenHeight / *(float *)&v45.pNode;
      sya = sx.pNode;
      *(float *)&sx.pNode = elem.pImageDesc.pObject->ScreenWidth / *(float *)&result.pNode;
      Scaleform::Render::Matrix2x4<float>::AppendScaling(
        &elem.pImageDesc.pObject->Matrix,
        *(float *)&sx.pNode,
        *(float *)&sya);
      Scaleform::Render::Text::DocView::ImageSubstitutor::AddImageDesc(ImageSubstitutor, &elem);
      v40 = v47;
      v50->pDocument.pObject->RTFlags |= 2u;
      Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v40->pDispObj);
      (*(void (__thiscall **)(int))(*(_DWORD *)SetValue + 8))(SetValue);
      goto LABEL_61;
    }
    goto LABEL_26;
  }
}
