char __thiscall Scaleform::GFx::TextField::SetTextValue(
        Scaleform::GFx::TextField *this,
        const __m128i *pnewText,
        char html,
        bool notifyVariable)
{
  Scaleform::StringLH *p_OriginalTextValue; // edi
  unsigned __int8 AvmObjOffset; // al
  int v8; // eax
  char *v9; // edi
  Scaleform::GFx::TextField::SetTextValue::__l14::TranslateInfo *v10; // ecx
  Scaleform::RefCountVImpl *v11; // ebx
  const char *pData; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::MemoryHeap *v14; // eax
  Scaleform::Render::Text::DocView *pObject; // ebp
  const Scaleform::GFx::Text::StyleManager *StyleSheet; // eax
  void (__thiscall *Release)(Scaleform::RefCountVImpl *); // edx
  int Length; // eax
  Scaleform::MemoryHeap *v19; // eax
  const Scaleform::MemoryHeap *v20; // eax
  unsigned int v21; // ecx
  Scaleform::Render::Text::DocView *v22; // ebp
  const Scaleform::GFx::Text::StyleManager *v23; // eax
  wchar_t *pText; // eax
  Scaleform::MemoryHeap *v25; // eax
  unsigned __int8 v26; // al
  int v27; // eax
  const Scaleform::Render::Text::StyleManagerBase *v28; // eax
  Scaleform::Render::Text::EditorKitBase *v29; // ecx
  unsigned int v30; // edi
  unsigned __int8 v31; // al
  int v32; // eax
  unsigned __int8 v33; // al
  int v34; // eax
  unsigned __int8 v35; // al
  int v36; // eax
  Scaleform::Render::TreeText *RenderNode; // eax
  Scaleform::Render::TreeText *v38; // eax
  char v39; // [esp+13h] [ebp-899h]
  Scaleform::GFx::ASString result; // [esp+14h] [ebp-898h] BYREF
  wchar_t *pwStr; // [esp+18h] [ebp-894h] BYREF
  int v42; // [esp+1Ch] [ebp-890h]
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> pimgInfoArr; // [esp+20h] [ebp-88Ch] BYREF
  Scaleform::Render::Text::ParagraphFormat pparaFmt; // [esp+30h] [ebp-87Ch] BYREF
  Scaleform::Render::Text::TextFormat ptextFmt; // [esp+44h] [ebp-868h] BYREF
  _DWORD v46[3]; // [esp+6Ch] [ebp-840h] BYREF
  char v47; // [esp+78h] [ebp-834h]
  Scaleform::WStringBuffer pstring; // [esp+88Ch] [ebp-20h] BYREF
  Scaleform::WStringBuffer pBuffer; // [esp+89Ch] [ebp-10h] BYREF

  p_OriginalTextValue = &this->OriginalTextValue;
  pwStr = 0;
  if ( !strcmp((const char *)((this->OriginalTextValue.HeapTypeBits & 0xFFFFFFFC) + 8), pnewText->m128i_i8)
    && (this->Flags & 0x10000) == 0 )
  {
    return 0;
  }
  AvmObjOffset = this->AvmObjOffset;
  this->Flags &= ~0x10000u;
  if ( AvmObjOffset )
  {
    v8 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + AvmObjOffset)
                                       + 16))(
           (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + 4 * AvmObjOffset);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 96))(v8) )
    {
      this->Flags |= 2u;
      html = 1;
    }
  }
  Scaleform::String::operator=(p_OriginalTextValue, pnewText);
  if ( html )
    this->Flags |= 0x1000u;
  else
    this->Flags &= ~0x1000u;
  v9 = (char *)((p_OriginalTextValue->HeapTypeBits & 0xFFFFFFFC) + 8);
  v39 = 0;
  if ( (this->Flags & 8) != 0 )
    goto LABEL_38;
  v11 = (Scaleform::RefCountVImpl *)this->pASRoot->pMovieImpl->GetStateAddRef(
                                      &this->pASRoot->pMovieImpl->Scaleform::GFx::StateBag,
                                      1);
  if ( !v11 )
    goto LABEL_38;
  if ( (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Flags & 2) != 0 )
  {
    pData = uri;
  }
  else
  {
    pwStr = (wchar_t *)1;
    pData = Scaleform::GFx::DisplayObject::GetName(this, &result)->pNode->pData;
  }
  Scaleform::GFx::TextField::SetTextValue_::_14_::TranslateInfo::TranslateInfo(v10, (int)v46, pData);
  if ( ((unsigned __int8)pwStr & 1) != 0 )
  {
    pNode = result.pNode;
    --result.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( !html || (((int (__thiscall *)(Scaleform::RefCountVImpl *))v11->AddRef)(v11) & 1) != 0 )
  {
    Length = Scaleform::UTF8Util::GetLength(v9, -1);
    Scaleform::WStringBuffer::Resize(&pBuffer, Length + 1);
    Scaleform::UTF8Util::DecodeString(pBuffer.pText, v9, -1);
    v46[0] = pBuffer.pText;
    if ( html )
      v47 |= 4u;
    ((void (__thiscall *)(Scaleform::RefCountVImpl *, _DWORD *))v11->Release)(v11, v46);
  }
  else
  {
    v14 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    Scaleform::Render::Text::TextFormat::TextFormat(&ptextFmt, v14);
    Scaleform::Render::Text::ParagraphFormat::ParagraphFormat(&pparaFmt);
    Scaleform::GFx::TextField::GetInitialFormats(this, &ptextFmt, &pparaFmt);
    pObject = this->pDocument.pObject;
    LOBYTE(result.pNode) = (this->Flags & 0x10) != 0;
    StyleSheet = Scaleform::GFx::TextField::GetStyleSheet(this);
    Scaleform::Render::Text::DocView::ParseHtml(
      pObject,
      (int)pObject,
      v9,
      0xFFFFFFFF,
      (bool)result.pNode,
      0,
      StyleSheet,
      &ptextFmt,
      &pparaFmt);
    Scaleform::Render::Text::StyledText::GetText(this->pDocument.pObject->pDocument.pObject, &pBuffer);
    if ( (((int (__thiscall *)(Scaleform::RefCountVImpl *))v11->AddRef)(v11) & 2) != 0 )
      Scaleform::WStringBuffer::StripTrailingNewLines(&pBuffer);
    Release = v11->Release;
    v46[0] = pBuffer.pText;
    ((void (__thiscall *)(Scaleform::RefCountVImpl *, _DWORD *))Release)(v11, v46);
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&pparaFmt);
    Scaleform::Render::Text::TextFormat::~TextFormat(&ptextFmt);
  }
  HIBYTE(v42) = v47 & 1;
  if ( (v47 & 1) != 0 )
  {
    if ( (v47 & 2) != 0 )
    {
      v19 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
      Scaleform::Render::Text::TextFormat::TextFormat(&ptextFmt, v19);
      Scaleform::Render::Text::ParagraphFormat::ParagraphFormat(&pparaFmt);
      Scaleform::GFx::TextField::GetInitialFormats(this, &ptextFmt, &pparaFmt);
      v20 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
      v21 = this->Flags >> 4;
      pimgInfoArr.Data.pHeap = v20;
      memset(&pimgInfoArr, 0, 12);
      LOBYTE(result.pNode) = v21 & 1;
      pwStr = pstring.pText;
      if ( !pstring.pText )
        pwStr = (wchar_t *)&unk_6E53BC;
      v22 = this->pDocument.pObject;
      v23 = Scaleform::GFx::TextField::GetStyleSheet(this);
      Scaleform::Render::Text::DocView::ParseHtml(
        v22,
        (int)v22,
        pwStr,
        0xFFFFFFFF,
        (bool)result.pNode,
        &pimgInfoArr,
        v23,
        &ptextFmt,
        &pparaFmt);
      if ( pimgInfoArr.Data.Size )
        Scaleform::GFx::TextField::ProcessImageTags(this, &pimgInfoArr);
      Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy>::~ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy>(&pimgInfoArr);
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&pparaFmt);
      Scaleform::Render::Text::TextFormat::~TextFormat(&ptextFmt);
    }
    else
    {
      Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
        this->pDocument.pObject->pDocument.pObject,
        (Scaleform::Render::Text::TextFormat **)&result,
        (Scaleform::Render::Text::ParagraphFormat **)&pwStr,
        0);
      Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
        this->pDocument.pObject->pDocument.pObject,
        (Scaleform::Render::Text::TextFormat *)result.pNode);
      Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
        this->pDocument.pObject->pDocument.pObject,
        (Scaleform::Render::Text::ParagraphFormat *)pwStr);
      pText = pstring.pText;
      if ( !pstring.pText )
        pText = (wchar_t *)&unk_6E53BC;
      Scaleform::Render::Text::DocView::SetText(this->pDocument.pObject, pText, 0xFFFFFFFF);
    }
    v39 = 1;
  }
  Scaleform::WStringBuffer::~WStringBuffer(&pBuffer);
  Scaleform::WStringBuffer::~WStringBuffer(&pstring);
  Scaleform::RefCountImpl::Release(v11);
  if ( !HIBYTE(v42) )
  {
LABEL_38:
    if ( html )
    {
      v25 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
      Scaleform::Render::Text::TextFormat::TextFormat(&ptextFmt, v25);
      pparaFmt.RefCount = 1;
      memset(&pparaFmt.pTabStops, 0, 16);
      Scaleform::GFx::TextField::GetInitialFormats(this, &ptextFmt, &pparaFmt);
      pimgInfoArr.Data.pHeap = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
      v26 = this->AvmObjOffset;
      memset(&pimgInfoArr, 0, 12);
      if ( v26 )
      {
        v27 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                              + v26)
                                            + 16))(
                (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
              + 4 * v26);
        v28 = (const Scaleform::Render::Text::StyleManagerBase *)(*(int (__thiscall **)(int))(*(_DWORD *)v27 + 92))(v27);
      }
      else
      {
        v28 = 0;
      }
      Scaleform::Render::Text::DocView::ParseHtml(
        this->pDocument.pObject,
        0,
        v9,
        0xFFFFFFFF,
        (this->Flags & 0x10) != 0,
        &pimgInfoArr,
        v28,
        &ptextFmt,
        &pparaFmt);
      if ( pimgInfoArr.Data.Size )
        Scaleform::GFx::TextField::ProcessImageTags(this, &pimgInfoArr);
      Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
        pimgInfoArr.Data.Data,
        pimgInfoArr.Data.Size);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pimgInfoArr.Data.Data);
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&pparaFmt);
      Scaleform::Render::Text::TextFormat::~TextFormat(&ptextFmt);
    }
    else
    {
      Scaleform::Render::Text::DocView::SetText(this->pDocument.pObject, v9, 0xFFFFFFFF);
    }
  }
  v29 = this->pDocument.pObject->pEditorKit.pObject;
  if ( v29 )
  {
    if ( !v29->IsReadOnly(v29) )
    {
      v30 = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject->pDocument.pObject);
      if ( (unsigned int)Scaleform::GFx::Text::EditorKit::GetCursorPos((Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)this->pDocument.pObject->pEditorKit.pObject) > v30 )
        Scaleform::GFx::Text::EditorKit::SetCursorPos(
          (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject,
          v30,
          0);
    }
  }
  v31 = this->AvmObjOffset;
  if ( v31 )
  {
    v32 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + v31)
                                        + 16))(
            (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
          + 4 * v31);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v32 + 96))(v32) )
    {
      if ( (this->pDocument.pObject->pDocument.pObject->RTFlags & 1) != 0 )
        Scaleform::GFx::TextField::CollectUrlZones(this);
    }
  }
  if ( notifyVariable )
  {
    v33 = this->AvmObjOffset;
    if ( v33 )
    {
      v34 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                            + v33)
                                          + 16))(
              (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
            + 4 * v33);
      (*(void (__thiscall **)(int))(*(_DWORD *)v34 + 124))(v34);
    }
  }
  if ( v39 )
  {
    v35 = this->AvmObjOffset;
    if ( v35 )
    {
      v36 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                            + v35)
                                          + 16))(
              (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
            + 4 * v35);
      (*(void (__thiscall **)(int))(*(_DWORD *)v36 + 100))(v36);
    }
    RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  }
  this->Flags |= 0x2000u;
  v38 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v38);
  return 1;
}
