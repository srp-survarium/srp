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
