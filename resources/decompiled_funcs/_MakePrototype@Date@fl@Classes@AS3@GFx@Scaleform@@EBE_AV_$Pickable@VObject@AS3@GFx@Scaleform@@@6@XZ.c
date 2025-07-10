Scaleform::Pickable<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Classes::fl::Date::MakePrototype(
        Scaleform::GFx::AS3::Classes::fl::Date *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::MemoryHeap *MHeap; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Prototype *v4; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v6; // ebx
  Scaleform::GFx::AS3::Instance *v7; // eax
  Scaleform::GFx::AS3::Instance *v8; // esi
  unsigned int RefCount; // eax

  MHeap = this->pTraits.pObject->pVM->MHeap;
  v4 = (Scaleform::GFx::AS3::InstanceTraits::Prototype *)MHeap->Alloc(MHeap, 120u, 0);
  if ( v4 )
  {
    Scaleform::GFx::AS3::InstanceTraits::Prototype::Prototype(
      v4,
      this->pTraits.pObject->pVM,
      &Scaleform::GFx::AS3::fl::DateCI,
      this);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v7 = (Scaleform::GFx::AS3::Instance *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)this->pTraits.pObject[1].__vftable);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v7, v6);
    *(double *)&v8[1].pNext = 0.0;
    v8->__vftable = (Scaleform::GFx::AS3::Instance_vtbl *)&Scaleform::GFx::AS3::Instances::fl::Date::`vftable';
    v8[1].__vftable = 0;
    LOBYTE(v8[1]._pRCC) = 0;
  }
  else
  {
    v8 = 0;
  }
  result->pV = v8;
  if ( v6 )
  {
    if ( ((unsigned __int8)v6 & 1) == 0 )
    {
      RefCount = v6->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        v6->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
      }
    }
  }
  return result;
}
