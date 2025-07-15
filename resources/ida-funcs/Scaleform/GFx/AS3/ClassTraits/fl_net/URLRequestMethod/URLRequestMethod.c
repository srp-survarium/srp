void __thiscall Scaleform::GFx::AS3::ClassTraits::fl_net::URLRequestMethod::URLRequestMethod(
        Scaleform::GFx::AS3::ClassTraits::fl_net::URLRequestMethod *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // esi
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v4; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v6; // ebx
  Scaleform::GFx::AS3::Class *v7; // eax
  Scaleform::GFx::AS3::Class *v8; // esi
  Scaleform::GFx::AS3::Class *pObject; // ecx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS3::ClassTraits::Traits::Traits(this, vm, &Scaleform::GFx::AS3::fl_net::URLRequestMethodCI);
  this->__vftable = (Scaleform::GFx::AS3::ClassTraits::fl_net::URLRequestMethod_vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_net::URLRequestMethod::`vftable';
  MHeap = vm->MHeap;
  v4 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)MHeap->Alloc(MHeap, 120u, 0);
  if ( v4 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v4, vm, &Scaleform::GFx::AS3::fl_net::URLRequestMethodCI);
    v6.pV = v5;
  }
  else
  {
    v6.pV = 0;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(this, v6);
  v7 = (Scaleform::GFx::AS3::Class *)MHeap->Alloc(MHeap, 64u, 0);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::Class::Class(v7, this);
    v8->__vftable = (Scaleform::GFx::AS3::Class_vtbl *)&Scaleform::GFx::AS3::Classes::fl_net::URLRequestMethod::`vftable';
    v8[1].__vftable = (Scaleform::GFx::AS3::Class_vtbl *)"DELETE";
    v8[1].pRCCRaw = (unsigned int)"GET";
    v8[1].pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)"HEAD";
    v8[1].pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)"OPTIONS";
    v8[1].RefCount = (unsigned int)"POST";
    v8[1].pTraits.pObject = (Scaleform::GFx::AS3::Traits *)"PUT";
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
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    v6.pV->pConstructor.pObject = v8;
  }
}
