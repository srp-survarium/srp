void __thiscall Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> itr)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // ecx
  unsigned int RefCount; // eax

  this->Flags ^= (this->Flags ^ -(((unsigned int)itr.pV->Flags >> 2) & 1)) & 4;
  pObject = this->ITraits.pObject;
  if ( itr.pV != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->ITraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)pObject - 1);
        this->ITraits.pObject = itr.pV;
        return;
      }
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    this->ITraits.pObject = itr.pV;
  }
}
