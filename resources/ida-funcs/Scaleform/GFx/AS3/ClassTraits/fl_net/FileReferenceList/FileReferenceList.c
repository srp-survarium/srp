void __thiscall Scaleform::GFx::AS3::ClassTraits::fl_net::FileReferenceList::FileReferenceList(
        Scaleform::GFx::AS3::ClassTraits::fl_net::FileReferenceList *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // esi
  Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *v4; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v6; // ebx
  Scaleform::GFx::AS3::Class *v7; // eax
  Scaleform::GFx::AS3::Class *v8; // eax
  Scaleform::GFx::AS3::Class *v9; // esi
  Scaleform::GFx::AS3::Class *pObject; // ecx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS3::ClassTraits::Traits::Traits(this, vm, &Scaleform::GFx::AS3::fl_net::FileReferenceListCI);
  this->__vftable = (Scaleform::GFx::AS3::ClassTraits::fl_net::FileReferenceList_vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::SecurityDomain::`vftable';
  MHeap = vm->MHeap;
  v4 = (Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *)MHeap->Alloc(MHeap, 120u, 0);
  if ( v4 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::EventDispatcher(
      v4,
      vm,
      &Scaleform::GFx::AS3::fl_net::FileReferenceListCI);
    v6.pV = v5;
  }
  else
  {
    v6.pV = 0;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(this, v6);
  v7 = (Scaleform::GFx::AS3::Class *)MHeap->Alloc(MHeap, 40u, 0);
  if ( v7 )
  {
    Scaleform::GFx::AS3::Class::Class(v7, this);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  pObject = v6.pV->pConstructor.pObject;
  if ( v9 != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        v6.pV->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)pObject - 1);
        v6.pV->pConstructor.pObject = v9;
        return;
      }
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    v6.pV->pConstructor.pObject = v9;
  }
}
