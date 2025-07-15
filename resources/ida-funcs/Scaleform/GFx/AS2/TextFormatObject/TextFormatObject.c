void __thiscall Scaleform::GFx::AS2::TextFormatObject::TextFormatObject(
        Scaleform::GFx::AS2::TextFormatObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::MemoryHeap *pHeap; // ebp

  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::TextFormatObject_vtbl *)&Scaleform::GFx::AS2::TextFormatObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextFormatObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  pHeap = psc->pContext->pHeap;
  this->mTextFormat.RefCount = 1;
  Scaleform::StringDH::StringDH(&this->mTextFormat.FontList, pHeap);
  Scaleform::StringDH::StringDH(&this->mTextFormat.Url, pHeap);
  this->mTextFormat.pImageDesc.pObject = 0;
  this->mTextFormat.pFontHandle.pObject = 0;
  this->mTextFormat.ColorV = -16777216;
  this->mTextFormat.FormatFlags = 0;
  this->mTextFormat.LetterSpacing = 0;
  this->mTextFormat.PresentMask = 0;
  this->mTextFormat.FontSize = 0;
  this->mParagraphFormat.BlockIndent = 0;
  this->mParagraphFormat.LeftMargin = 0;
  this->mParagraphFormat.Leading = 0;
  this->mParagraphFormat.PresentMask = 0;
  this->mParagraphFormat.RefCount = 1;
  this->mParagraphFormat.pTabStops = 0;
  this->mParagraphFormat.Indent = 0;
  this->mParagraphFormat.RightMargin = 0;
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    pprototype);
}


void __thiscall Scaleform::GFx::AS2::TextFormatObject::TextFormatObject(
        Scaleform::GFx::AS2::TextFormatObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // edi
  Scaleform::MemoryHeap *v4; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // edi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::PropFlags v7; // [esp+13h] [ebp-15h] BYREF
  Scaleform::MemoryHeap *pheap; // [esp+14h] [ebp-14h]
  Scaleform::GFx::AS2::Value v9; // [esp+18h] [ebp-10h] BYREF

  v2 = penv;
  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::TextFormatObject_vtbl *)&Scaleform::GFx::AS2::TextFormatObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextFormatObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v4 = v2->StringContext.pContext->pHeap;
  p_StringContext = &v2->StringContext;
  pheap = v4;
  this->mTextFormat.RefCount = 1;
  Scaleform::StringDH::StringDH(&this->mTextFormat.FontList, v4);
  Scaleform::StringDH::StringDH(&this->mTextFormat.Url, pheap);
  this->mTextFormat.pImageDesc.pObject = 0;
  this->mTextFormat.pFontHandle.pObject = 0;
  this->mTextFormat.ColorV = -16777216;
  this->mTextFormat.FormatFlags = 0;
  this->mTextFormat.LetterSpacing = 0;
  this->mTextFormat.PresentMask = 0;
  this->mTextFormat.FontSize = 0;
  this->mParagraphFormat.RefCount = 1;
  this->mParagraphFormat.pTabStops = 0;
  this->mParagraphFormat.BlockIndent = 0;
  this->mParagraphFormat.Indent = 0;
  this->mParagraphFormat.Leading = 0;
  this->mParagraphFormat.LeftMargin = 0;
  this->mParagraphFormat.RightMargin = 0;
  this->mParagraphFormat.PresentMask = 0;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(p_StringContext->pContext, ASBuiltin_TextFormat);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    Prototype);
  v7.Flags = 2;
  v9.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)p_StringContext,
    "align",
    &v9,
    &v7);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  v7.Flags = 2;
  v9.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)p_StringContext,
    "blockIndent",
    &v9,
    &v7);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  v7.Flags = 2;
  v9.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)p_StringContext,
    "bold",
    &v9,
    &v7);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  v7.Flags = 2;
  v9.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)p_StringContext,
    "bullet",
    &v9,
    &v7);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  v7.Flags = 2;
  v9.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)p_StringContext,
    "color",
    &v9,
    &v7);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  v7.Flags = 2;
  v9.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)p_StringContext,
    "font",
    &v9,
    &v7);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  v7.Flags = 2;
  v9.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)p_StringContext,
    "indent",
    &v9,
    &v7);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  v7.Flags = 2;
  v9.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)p_StringContext,
    "italic",
    &v9,
    &v7);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  v7.Flags = 2;
  v9.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)p_StringContext,
    "leading",
    &v9,
    &v7);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  v7.Flags = 2;
  v9.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)p_StringContext,
    "leftMargin",
    &v9,
    &v7);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  v7.Flags = 2;
  v9.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)p_StringContext,
    "rightMargin",
    &v9,
    &v7);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  v7.Flags = 2;
  v9.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)p_StringContext,
    "size",
    &v9,
    &v7);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  v7.Flags = 2;
  v9.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)p_StringContext,
    "tabStops",
    &v9,
    &v7);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  v7.Flags = 2;
  v9.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)p_StringContext,
    "target",
    &v9,
    &v7);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  v7.Flags = 2;
  v9.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)p_StringContext,
    "underline",
    &v9,
    &v7);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  v7.Flags = 2;
  v9.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)p_StringContext,
    "url",
    &v9,
    &v7);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  if ( penv->StringContext.SWFVersion >= 8u )
  {
    LOBYTE(penv) = 2;
    v9.T.Type = 1;
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      (Scaleform::GFx::ASStringNode *)p_StringContext,
      "kerning",
      &v9,
      (const Scaleform::GFx::AS2::PropFlags *)&penv);
    if ( v9.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v9);
    LOBYTE(penv) = 2;
    v9.T.Type = 1;
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      (Scaleform::GFx::ASStringNode *)p_StringContext,
      "letterSpacing",
      &v9,
      (const Scaleform::GFx::AS2::PropFlags *)&penv);
    if ( v9.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v9);
  }
  if ( p_StringContext->pContext->GFxExtensions.Value == 1 )
  {
    LOBYTE(penv) = 2;
    v9.T.Type = 1;
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      (Scaleform::GFx::ASStringNode *)p_StringContext,
      "alpha",
      &v9,
      (const Scaleform::GFx::AS2::PropFlags *)&penv);
    if ( v9.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v9);
  }
}
