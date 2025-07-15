Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *__thiscall Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *this,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *p)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *pObject; // ecx
  unsigned int RefCount; // eax

  if ( p != this->pObject )
  {
    if ( p )
      p->RefCount = (p->RefCount + 1) & 0x8FBFFFFF;
    pObject = this->pObject;
    if ( this->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)pObject - 1);
        this->pObject = p;
        return this;
      }
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    this->pObject = p;
  }
  return this;
}
