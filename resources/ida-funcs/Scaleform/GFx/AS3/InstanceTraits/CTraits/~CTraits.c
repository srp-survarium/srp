void __thiscall Scaleform::GFx::AS3::InstanceTraits::CTraits::~CTraits(
        Scaleform::GFx::AS3::InstanceTraits::CTraits *this)
{
  unsigned int Size; // eax
  Scaleform::GFx::AS3::Multiname *v3; // edi
  unsigned int v4; // ebx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ecx
  unsigned int RefCount; // eax

  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::CTraits_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::CTraits::`vftable';
  Size = this->ImplementsInterfaces.Data.Size;
  v3 = &this->ImplementsInterfaces.Data.Data[Size - 1];
  if ( Size )
  {
    v4 = this->ImplementsInterfaces.Data.Size;
    do
    {
      Scaleform::GFx::AS3::Multiname::~Multiname(v3--);
      --v4;
    }
    while ( v4 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->ImplementsInterfaces.Data.Data);
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::CTraits_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Traits::`vftable';
  pObject = this->Ns.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pObject - 1);
      Scaleform::GFx::AS3::Traits::~Traits(this);
      return;
    }
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
  Scaleform::GFx::AS3::Traits::~Traits(this);
}
