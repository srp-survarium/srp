Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *__thiscall Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *this,
        const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *other)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat *pObject; // ecx
  unsigned int RefCount; // eax

  if ( other != this )
  {
    if ( other->pObject )
      other->pObject->RefCount = (other->pObject->RefCount + 1) & 0x8FBFFFFF;
    pObject = this->pObject;
    if ( this->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->pObject = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)((char *)pObject - 1);
        this->pObject = other->pObject;
        return this;
      }
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    this->pObject = other->pObject;
  }
  return this;
}
