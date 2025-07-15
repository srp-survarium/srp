void __thiscall Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object::~Vector_object(
        Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object *this)
{
  const Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v4; // ecx
  unsigned int v5; // eax

  pObject = this->EnclosedClassTraits.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->EnclosedClassTraits.pObject = (const Scaleform::GFx::AS3::ClassTraits::Traits *)((char *)pObject - 1);
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
  v4 = this->ITraits.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->ITraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)v4 - 1);
      Scaleform::GFx::AS3::Traits::~Traits(this);
      return;
    }
    v5 = v4->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & v5) != 0 )
    {
      v4->RefCount = v5 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
    }
  }
  Scaleform::GFx::AS3::Traits::~Traits(this);
}
