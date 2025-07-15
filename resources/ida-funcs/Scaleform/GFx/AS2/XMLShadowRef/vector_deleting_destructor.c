Scaleform::GFx::AS2::XMLShadowRef *__thiscall Scaleform::GFx::AS2::XMLShadowRef::`vector deleting destructor'(
        Scaleform::GFx::AS2::XMLShadowRef *this,
        char a2)
{
  Scaleform::GFx::AS2::Object *pObject; // ecx
  unsigned int RefCount; // eax

  pObject = this->pAttributes.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->__vftable = (Scaleform::GFx::AS2::XMLShadowRef_vtbl *)&Scaleform::GFx::AS3::Abc::Code::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
