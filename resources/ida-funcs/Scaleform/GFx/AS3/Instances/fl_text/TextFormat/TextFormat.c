void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextFormat::TextFormat(
        Scaleform::GFx::AS3::Instances::fl_text::TextFormat *this,
        Scaleform::GFx::ASStringNode *t)
{
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::AS3::Value n; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+20h] [ebp-10h] BYREF

  Scaleform::GFx::AS3::Instances::fl::Object::Object(this, (Scaleform::GFx::AS3::InstanceTraits::Traits *)t);
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat_vtbl *)&Scaleform::GFx::AS3::Instances::fl_text::TextFormat::`vftable';
  this->mAlign.Flags = 0;
  this->mAlign.Bonus.pWeakProxy = 0;
  this->mBlockIndent.Flags = 0;
  this->mBlockIndent.Bonus.pWeakProxy = 0;
  this->mBullet.Flags = 0;
  this->mBullet.Bonus.pWeakProxy = 0;
  this->mBold.Flags = 0;
  this->mBold.Bonus.pWeakProxy = 0;
  this->mColor.Flags = 0;
  this->mColor.Bonus.pWeakProxy = 0;
  this->mFont.Flags = 0;
  this->mFont.Bonus.pWeakProxy = 0;
  this->mItalic.Flags = 0;
  this->mItalic.Bonus.pWeakProxy = 0;
  this->mIndent.Flags = 0;
  this->mIndent.Bonus.pWeakProxy = 0;
  this->mKerning.Flags = 0;
  this->mKerning.Bonus.pWeakProxy = 0;
  this->mLeading.Flags = 0;
  this->mLeading.Bonus.pWeakProxy = 0;
  this->mLeftMargin.Flags = 0;
  this->mLeftMargin.Bonus.pWeakProxy = 0;
  this->mRightMargin.Flags = 0;
  this->mRightMargin.Bonus.pWeakProxy = 0;
  this->mLetterSpacing.Flags = 0;
  this->mLetterSpacing.Bonus.pWeakProxy = 0;
  this->mSize.Flags = 0;
  this->mSize.Bonus.pWeakProxy = 0;
  this->mTabStops.pObject = 0;
  this->mTarget.Flags = 0;
  this->mTarget.Bonus.pWeakProxy = 0;
  this->mUnderline.Flags = 0;
  this->mUnderline.Bonus.pWeakProxy = 0;
  this->mUrl.Flags = 0;
  this->mUrl.Bonus.pWeakProxy = 0;
  pStringManager = this->pTraits.pObject->pVM->StringManagerRef->pStringManager;
  t = &pStringManager->NullStringNode;
  ++pStringManager->NullStringNode.RefCount;
  memset(&n.Bonus, 0, 12);
  r.Flags = 0;
  r.Bonus.pWeakProxy = 0;
  n.Flags = 12;
  Scaleform::GFx::AS3::Value::Assign(&this->mAlign, (const Scaleform::GFx::ASString *)&t);
  Scaleform::GFx::AS3::Value::Assign(&this->mBlockIndent, &n);
  Scaleform::GFx::AS3::Value::Assign(&this->mBold, &n);
  Scaleform::GFx::AS3::Value::Assign(&this->mBullet, &n);
  Scaleform::GFx::AS3::Value::Assign(&this->mColor, &n);
  Scaleform::GFx::AS3::Value::Assign(&this->mFont, (const Scaleform::GFx::ASString *)&t);
  Scaleform::GFx::AS3::Value::Assign(&this->mIndent, &n);
  Scaleform::GFx::AS3::Value::Assign(&this->mItalic, &n);
  Scaleform::GFx::AS3::Value::Assign(&this->mKerning, &n);
  Scaleform::GFx::AS3::Value::Assign(&this->mLeading, &n);
  Scaleform::GFx::AS3::Value::Assign(&this->mLeftMargin, &n);
  Scaleform::GFx::AS3::Value::Assign(&this->mLetterSpacing, &n);
  Scaleform::GFx::AS3::Value::Assign(&this->mRightMargin, &n);
  Scaleform::GFx::AS3::Value::Assign(&this->mSize, &n);
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
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    this->mTabStops.pObject = 0;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mTarget, (const Scaleform::GFx::ASString *)&t);
  Scaleform::GFx::AS3::Value::Assign(&this->mUnderline, &n);
  Scaleform::GFx::AS3::Value::Assign(&this->mUrl, (const Scaleform::GFx::ASString *)&t);
  if ( (n.Flags & 0x1F) > 9 )
  {
    if ( (n.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&n);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&n);
  }
  if ( (r.Flags & 0x1F) > 9 )
  {
    if ( (r.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
  }
  v6 = t;
  --t->RefCount;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
}
