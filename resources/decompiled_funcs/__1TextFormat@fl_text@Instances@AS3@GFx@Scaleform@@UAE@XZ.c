void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextFormat::~TextFormat(
        Scaleform::GFx::AS3::Instances::fl_text::TextFormat *this)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *p_mUrl; // ecx
  Scaleform::GFx::AS3::Value *p_mUnderline; // ecx
  Scaleform::GFx::AS3::Value *p_mTarget; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value *p_mSize; // ecx
  Scaleform::GFx::AS3::Value *p_mLetterSpacing; // ecx
  Scaleform::GFx::AS3::Value *p_mRightMargin; // ecx
  Scaleform::GFx::AS3::Value *p_mLeftMargin; // ecx
  Scaleform::GFx::AS3::Value *p_mLeading; // ecx
  Scaleform::GFx::AS3::Value *p_mKerning; // ecx
  Scaleform::GFx::AS3::Value *p_mIndent; // ecx
  Scaleform::GFx::AS3::Value *p_mItalic; // ecx
  Scaleform::GFx::AS3::Value *p_mFont; // ecx
  Scaleform::GFx::AS3::Value *p_mColor; // ecx
  Scaleform::GFx::AS3::Value *p_mBold; // ecx
  Scaleform::GFx::AS3::Value *p_mBullet; // ecx
  Scaleform::GFx::AS3::Value *p_mBlockIndent; // ecx
  Scaleform::GFx::AS3::Value *p_mAlign; // ecx

  Flags = this->mUrl.Flags;
  p_mUrl = &this->mUrl;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mUrl);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mUrl);
  }
  p_mUnderline = &this->mUnderline;
  if ( (this->mUnderline.Flags & 0x1F) > 9 )
  {
    if ( (this->mUnderline.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mUnderline);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mUnderline);
  }
  p_mTarget = &this->mTarget;
  if ( (this->mTarget.Flags & 0x1F) > 9 )
  {
    if ( (this->mTarget.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mTarget);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mTarget);
  }
  pObject = this->mTabStops.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->mTabStops.pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  p_mSize = &this->mSize;
  if ( (this->mSize.Flags & 0x1F) > 9 )
  {
    if ( (this->mSize.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mSize);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mSize);
  }
  p_mLetterSpacing = &this->mLetterSpacing;
  if ( (this->mLetterSpacing.Flags & 0x1F) > 9 )
  {
    if ( (this->mLetterSpacing.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mLetterSpacing);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mLetterSpacing);
  }
  p_mRightMargin = &this->mRightMargin;
  if ( (this->mRightMargin.Flags & 0x1F) > 9 )
  {
    if ( (this->mRightMargin.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mRightMargin);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mRightMargin);
  }
  p_mLeftMargin = &this->mLeftMargin;
  if ( (this->mLeftMargin.Flags & 0x1F) > 9 )
  {
    if ( (this->mLeftMargin.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mLeftMargin);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mLeftMargin);
  }
  p_mLeading = &this->mLeading;
  if ( (this->mLeading.Flags & 0x1F) > 9 )
  {
    if ( (this->mLeading.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mLeading);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mLeading);
  }
  p_mKerning = &this->mKerning;
  if ( (this->mKerning.Flags & 0x1F) > 9 )
  {
    if ( (this->mKerning.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mKerning);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mKerning);
  }
  p_mIndent = &this->mIndent;
  if ( (this->mIndent.Flags & 0x1F) > 9 )
  {
    if ( (this->mIndent.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mIndent);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mIndent);
  }
  p_mItalic = &this->mItalic;
  if ( (this->mItalic.Flags & 0x1F) > 9 )
  {
    if ( (this->mItalic.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mItalic);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mItalic);
  }
  p_mFont = &this->mFont;
  if ( (this->mFont.Flags & 0x1F) > 9 )
  {
    if ( (this->mFont.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mFont);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mFont);
  }
  p_mColor = &this->mColor;
  if ( (this->mColor.Flags & 0x1F) > 9 )
  {
    if ( (this->mColor.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mColor);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mColor);
  }
  p_mBold = &this->mBold;
  if ( (this->mBold.Flags & 0x1F) > 9 )
  {
    if ( (this->mBold.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mBold);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mBold);
  }
  p_mBullet = &this->mBullet;
  if ( (this->mBullet.Flags & 0x1F) > 9 )
  {
    if ( (this->mBullet.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mBullet);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mBullet);
  }
  p_mBlockIndent = &this->mBlockIndent;
  if ( (this->mBlockIndent.Flags & 0x1F) > 9 )
  {
    if ( (this->mBlockIndent.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mBlockIndent);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mBlockIndent);
  }
  p_mAlign = &this->mAlign;
  if ( (this->mAlign.Flags & 0x1F) > 9 )
  {
    if ( (this->mAlign.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mAlign);
      Scaleform::GFx::AS3::Instance::~Instance(this);
      return;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(p_mAlign);
  }
  Scaleform::GFx::AS3::Instance::~Instance(this);
}
