void __thiscall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::~EventDispatcher(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v4; // ecx
  unsigned int v5; // eax

  pObject = this->MouseEventTraits.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->MouseEventTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)pObject - 1);
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
  }
  v4 = this->EventTraits.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->EventTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)v4 - 1);
      Scaleform::GFx::AS3::Class::~Class(this);
      return;
    }
    v5 = v4->RefCount;
    if ( (v5 & 0x3FFFFF) != 0 )
    {
      v4->RefCount = v5 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
    }
  }
  Scaleform::GFx::AS3::Class::~Class(this);
}
