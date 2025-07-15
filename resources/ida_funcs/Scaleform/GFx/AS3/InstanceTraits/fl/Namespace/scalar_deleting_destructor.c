Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *__thiscall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::`scalar deleting destructor'(
        Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *this,
        char a2)
{
  Scaleform::GFx::AS3::NamespaceInstanceFactory *pObject; // eax
  Scaleform::RefCountVImpl *v4; // ecx

  pObject = this->pNamespaceFactory.pObject;
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::`vftable';
  pObject->pNamespaceInstanceTraits = 0;
  v4 = (Scaleform::RefCountVImpl *)this->pNamespaceFactory.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  Scaleform::GFx::AS3::InstanceTraits::CTraits::~CTraits(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
