Scaleform::GFx::AS3::PropRef *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::FindDynamicSlot(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::PropRef *result,
        Scaleform::GFx::AS3::SoundObject *mn)
{
  Scaleform::GFx::AS3::Instances::fl::AttrGetFirst v5; // [esp+8h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Instances::fl::ChildGetFirst cb; // [esp+14h] [ebp-Ch] BYREF

  if ( ((int)mn->Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable
      & 8) != 0 )
  {
    v5.Element = this;
    v5.__vftable = (Scaleform::GFx::AS3::Instances::fl::AttrGetFirst_vtbl *)&Scaleform::GFx::AS3::Instances::fl::AttrGetFirst::`vftable';
    v5.First.pObject = 0;
    if ( Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachAttr(this, mn, &v5) )
    {
      result->pSI = (const Scaleform::GFx::AS3::SlotInfo *)((int)v5.First.pObject | 2);
      Scaleform::GFx::AS3::Value::Value(&result->This, this);
    }
    else
    {
      result->pSI = 0;
      result->SlotIndex = 0;
      result->This.Flags = 0;
      result->This.Bonus.pWeakProxy = 0;
    }
    Scaleform::GFx::AS3::Instances::fl::AttrGetFirst::~AttrGetFirst(&v5);
    return result;
  }
  else
  {
    cb.Element = this;
    cb.__vftable = (Scaleform::GFx::AS3::Instances::fl::ChildGetFirst_vtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::`vftable';
    cb.First.pObject = 0;
    if ( Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(this, mn, &cb) )
    {
      result->pSI = (const Scaleform::GFx::AS3::SlotInfo *)((int)cb.First.pObject | 2);
      Scaleform::GFx::AS3::Value::Value(&result->This, this);
    }
    else
    {
      result->pSI = 0;
      result->SlotIndex = 0;
      result->This.Flags = 0;
      result->This.Bonus.pWeakProxy = 0;
    }
    Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::~ChildGetFirst(&cb);
    return result;
  }
}
