void __thiscall Scaleform::GFx::AS3::Instances::fl_events::Event::clone(
        Scaleform::GFx::AS3::Instances::fl_events::TimerEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *result)
{
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> e; // [esp+4h] [ebp-4h] BYREF

  e.pObject = this;
  this->Clone(this, &e);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)result,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&e);
  if ( e.pObject && ((int)e.pObject & 1) == 0 )
  {
    RefCount = e.pObject->RefCount;
    pObject = e.pObject;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      e.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
}
