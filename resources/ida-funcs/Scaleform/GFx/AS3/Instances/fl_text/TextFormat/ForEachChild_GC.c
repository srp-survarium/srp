void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextFormat::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_text::TextFormat *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( (this->mAlign.Flags & 0x1F) > 0xA && (this->mAlign.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mAlign, op, this);
  if ( (this->mBlockIndent.Flags & 0x1F) > 0xA && (this->mBlockIndent.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mBlockIndent, op, this);
  if ( (this->mBullet.Flags & 0x1F) > 0xA && (this->mBullet.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mBullet, op, this);
  if ( (this->mBold.Flags & 0x1F) > 0xA && (this->mBold.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mBold, op, this);
  if ( (this->mColor.Flags & 0x1F) > 0xA && (this->mColor.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mColor, op, this);
  if ( (this->mFont.Flags & 0x1F) > 0xA && (this->mFont.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mFont, op, this);
  if ( (this->mItalic.Flags & 0x1F) > 0xA && (this->mItalic.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mItalic, op, this);
  if ( (this->mIndent.Flags & 0x1F) > 0xA && (this->mIndent.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mIndent, op, this);
  if ( (this->mKerning.Flags & 0x1F) > 0xA && (this->mKerning.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mKerning, op, this);
  if ( (this->mLeading.Flags & 0x1F) > 0xA && (this->mLeading.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mLeading, op, this);
  if ( (this->mLeftMargin.Flags & 0x1F) > 0xA && (this->mLeftMargin.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mLeftMargin, op, this);
  if ( (this->mRightMargin.Flags & 0x1F) > 0xA && (this->mRightMargin.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mRightMargin, op, this);
  if ( (this->mLetterSpacing.Flags & 0x1F) > 0xA && (this->mLetterSpacing.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mLetterSpacing, op, this);
  if ( (this->mSize.Flags & 0x1F) > 0xA && (this->mSize.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mSize, op, this);
  if ( this->mTabStops.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->mTabStops.pObject, this);
  if ( (this->mTarget.Flags & 0x1F) > 0xA && (this->mTarget.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mTarget, op, this);
  if ( (this->mUnderline.Flags & 0x1F) > 0xA && (this->mUnderline.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mUnderline, op, this);
  if ( (this->mUrl.Flags & 0x1F) > 0xA && (this->mUrl.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->mUrl, op, this);
}
