void __thiscall Scaleform::GFx::AS3::ClassTraits::fl::XML::XML(
        Scaleform::GFx::AS3::ClassTraits::fl::XML *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // ebx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v4; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v6; // ebp
  Scaleform::GFx::AS3::Class *v7; // eax
  Scaleform::GFx::AS3::Class *v8; // esi
  Scaleform::GFx::AS3::Class *pObject; // ecx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS3::ClassTraits::Traits::Traits(this, vm, &Scaleform::GFx::AS3::fl::XMLCI);
  this->__vftable = (Scaleform::GFx::AS3::ClassTraits::fl::XML_vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::SecurityDomain::`vftable';
  this->TraitsType = Traits_XML;
  MHeap = vm->MHeap;
  v4 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->Alloc(MHeap, 120u, 0);
  v5 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v4, vm, &Scaleform::GFx::AS3::fl::XMLCI);
    v5->__vftable = (Scaleform::GFx::AS3::InstanceTraits::Traits_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::XML::`vftable';
    v5->TraitsType = Traits_XML;
    v5->MemSize = 40;
    v6.pV = v5;
  }
  else
  {
    v6.pV = 0;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(this, v6);
  v7 = (Scaleform::GFx::AS3::Class *)MHeap->Alloc(MHeap, 48u, 0);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::Class::Class(v7, this);
    v8->__vftable = (Scaleform::GFx::AS3::Class_vtbl *)&Scaleform::GFx::AS3::Classes::fl::XML::`vftable';
    LOBYTE(v8[1].__vftable) = 1;
    BYTE1(v8[1].__vftable) = 1;
    BYTE2(v8[1].__vftable) = 1;
    HIBYTE(v8[1].__vftable) = 1;
    v8[1].pRCCRaw = 2;
  }
  else
  {
    v8 = 0;
  }
  pObject = v6.pV->pConstructor.pObject;
  if ( v8 != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        v6.pV->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)pObject - 1);
        v6.pV->pConstructor.pObject = v8;
        return;
      }
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    v6.pV->pConstructor.pObject = v8;
  }
}
