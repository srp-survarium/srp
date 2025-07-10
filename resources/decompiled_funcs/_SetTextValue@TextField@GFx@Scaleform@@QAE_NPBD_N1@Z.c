char __thiscall Scaleform::GFx::TextField::SetTextValue(
        Scaleform::GFx::TextField *this,
        char *pnewText,
        bool html,
        bool notifyVariable)
{
  Scaleform::StringLH *p_OriginalTextValue; // edi
  unsigned __int8 AvmObjOffset; // al
  int v8; // eax
  const char *v9; // edi
  Scaleform::GFx::TextField::SetTextValue::__l14::TranslateInfo *v10; // ecx
  Scaleform::RefCountVImpl *v11; // ebx
  const char *pData; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
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
  const Scaleform::Render::Text::TextFormat *ptextFmt; // [esp+14h] [ebp-898h] BYREF
  const Scaleform::Render::Text::ParagraphFormat *pparaFmt; // [esp+18h] [ebp-894h] BYREF
  bool translated; // [esp+1Fh] [ebp-88Dh]
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> imageInfoArray; // [esp+20h] [ebp-88Ch] BYREF
  Scaleform::Render::Text::ParagraphFormat paraFmt; // [esp+30h] [ebp-87Ch] BYREF
  Scaleform::Render::Text::TextFormat txtFmt; // [esp+44h] [ebp-868h] BYREF
  Scaleform::GFx::TextField::SetTextValue::__l14::TranslateInfo translateInfo; // [esp+6Ch] [ebp-840h] BYREF

  p_OriginalTextValue = &this->OriginalTextValue;
  pparaFmt = 0;
  if ( !strcmp((const char *)((this->OriginalTextValue.HeapTypeBits & 0xFFFFFFFC) + 8), pnewText)
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
  v9 = (const char *)((p_OriginalTextValue->HeapTypeBits & 0xFFFFFFFC) + 8);
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
    pData = (const char *)&buf;
  }
  else
  {
    pparaFmt = (const Scaleform::Render::Text::ParagraphFormat *)1;
    pData = Scaleform::GFx::DisplayObject::GetName(this, (Scaleform::GFx::ASString *)&ptextFmt)->pNode->pData;
  }
  Scaleform::GFx::TextField::SetTextValue_::_14_::TranslateInfo::TranslateInfo(v10, (int)&translateInfo, pData);
  if ( ((unsigned __int8)pparaFmt & 1) != 0 )
  {
    v13 = (Scaleform::GFx::ASStringNode *)ptextFmt;
    --ptextFmt->Url.HeapTypeBits;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
  if ( !html || (((int (__thiscall *)(Scaleform::RefCountVImpl *))v11->AddRef)(v11) & 1) != 0 )
  {
    Length = Scaleform::UTF8Util::GetLength(v9, -1);
    Scaleform::WStringBuffer::Resize(&translateInfo.KeyBuf, Length + 1);
    Scaleform::UTF8Util::DecodeString(translateInfo.KeyBuf.pText, v9, -1);
    translateInfo.pKey = translateInfo.KeyBuf.pText;
    if ( html )
      translateInfo.Flags |= 4u;
    ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::TextField::SetTextValue::__l14::TranslateInfo *))v11->Release)(
      v11,
      &translateInfo);
  }
  else
  {
    v14 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    Scaleform::Render::Text::TextFormat::TextFormat(&txtFmt, v14);
    Scaleform::Render::Text::ParagraphFormat::ParagraphFormat(&paraFmt);
    Scaleform::GFx::TextField::GetInitialFormats(this, &txtFmt, &paraFmt);
    pObject = this->pDocument.pObject;
    LOBYTE(ptextFmt) = (this->Flags & 0x10) != 0;
    StyleSheet = Scaleform::GFx::TextField::GetStyleSheet(this);
    Scaleform::Render::Text::DocView::ParseHtml(
      pObject,
      v9,
      0xFFFFFFFF,
      (bool)ptextFmt,
      0,
      StyleSheet,
      &txtFmt,
      &paraFmt);
    Scaleform::Render::Text::StyledText::GetText(this->pDocument.pObject->pDocument.pObject, &translateInfo.KeyBuf);
    if ( (((int (__thiscall *)(Scaleform::RefCountVImpl *))v11->AddRef)(v11) & 2) != 0 )
      Scaleform::WStringBuffer::StripTrailingNewLines(&translateInfo.KeyBuf);
    Release = v11->Release;
    translateInfo.pKey = translateInfo.KeyBuf.pText;
    ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::TextField::SetTextValue::__l14::TranslateInfo *))Release)(
      v11,
      &translateInfo);
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&paraFmt);
    Scaleform::Render::Text::TextFormat::~TextFormat(&txtFmt);
  }
  translated = translateInfo.Flags & 1;
  if ( (translateInfo.Flags & 1) != 0 )
  {
    if ( (translateInfo.Flags & 2) != 0 )
    {
      v19 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
      Scaleform::Render::Text::TextFormat::TextFormat(&txtFmt, v19);
      Scaleform::Render::Text::ParagraphFormat::ParagraphFormat(&paraFmt);
      Scaleform::GFx::TextField::GetInitialFormats(this, &txtFmt, &paraFmt);
      v20 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
      v21 = this->Flags >> 4;
      imageInfoArray.Data.pHeap = v20;
      memset(&imageInfoArray, 0, 12);
      LOBYTE(ptextFmt) = v21 & 1;
      pparaFmt = (const Scaleform::Render::Text::ParagraphFormat *)translateInfo.ResultBuf.pText;
      if ( !translateInfo.ResultBuf.pText )
        pparaFmt = (const Scaleform::Render::Text::ParagraphFormat *)&word_96B534;
      v22 = this->pDocument.pObject;
      v23 = Scaleform::GFx::TextField::GetStyleSheet(this);
      Scaleform::Render::Text::DocView::ParseHtml(
        v22,
        (const wchar_t *)pparaFmt,
        0xFFFFFFFF,
        (bool)ptextFmt,
        &imageInfoArray,
        v23,
        &txtFmt,
        &paraFmt);
      if ( imageInfoArray.Data.Size )
        Scaleform::GFx::TextField::ProcessImageTags(this, &imageInfoArray);
      Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy>::~ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy>(&imageInfoArray);
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&paraFmt);
      Scaleform::Render::Text::TextFormat::~TextFormat(&txtFmt);
    }
    else
    {
      Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
        this->pDocument.pObject->pDocument.pObject,
        (Scaleform::Render::Text::TextFormat **)&ptextFmt,
        (Scaleform::Render::Text::ParagraphFormat **)&pparaFmt,
        0);
      Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
        this->pDocument.pObject->pDocument.pObject,
        (Scaleform::Render::Text::TextFormat *)ptextFmt);
      Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
        this->pDocument.pObject->pDocument.pObject,
        (Scaleform::Render::Text::ParagraphFormat *)pparaFmt);
      pText = translateInfo.ResultBuf.pText;
      if ( !translateInfo.ResultBuf.pText )
        pText = (wchar_t *)&word_96B534;
      Scaleform::Render::Text::DocView::SetText(this->pDocument.pObject, pText, 0xFFFFFFFF);
    }
    v39 = 1;
  }
  Scaleform::WStringBuffer::~WStringBuffer(&translateInfo.KeyBuf);
  Scaleform::WStringBuffer::~WStringBuffer(&translateInfo.ResultBuf);
  Scaleform::RefCountImpl::Release(v11);
  if ( !translated )
  {
LABEL_38:
    if ( html )
    {
      v25 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
      Scaleform::Render::Text::TextFormat::TextFormat(&txtFmt, v25);
      paraFmt.RefCount = 1;
      memset(&paraFmt.pTabStops, 0, 16);
      Scaleform::GFx::TextField::GetInitialFormats(this, &txtFmt, &paraFmt);
      imageInfoArray.Data.pHeap = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
      v26 = this->AvmObjOffset;
      memset(&imageInfoArray, 0, 12);
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
        v9,
        0xFFFFFFFF,
        (this->Flags & 0x10) != 0,
        &imageInfoArray,
        v28,
        &txtFmt,
        &paraFmt);
      if ( imageInfoArray.Data.Size )
        Scaleform::GFx::TextField::ProcessImageTags(this, &imageInfoArray);
      Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
        imageInfoArray.Data.Data,
        imageInfoArray.Data.Size);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, imageInfoArray.Data.Data);
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&paraFmt);
      Scaleform::Render::Text::TextFormat::~TextFormat(&txtFmt);
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
