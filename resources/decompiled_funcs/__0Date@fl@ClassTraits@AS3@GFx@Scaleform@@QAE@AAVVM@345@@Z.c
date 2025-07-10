void __thiscall Scaleform::GFx::AS3::ClassTraits::fl::Date::Date(
        Scaleform::GFx::AS3::ClassTraits::fl::Date *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // ebx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v4; // eax
  _DWORD *v5; // esi
  Scaleform::GFx::AS3::Class *v6; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // ebx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v8; // ecx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS3::ClassTraits::Traits::Traits(this, vm, &Scaleform::GFx::AS3::fl::DateCI);
  this->__vftable = (Scaleform::GFx::AS3::ClassTraits::fl::Date_vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::SecurityDomain::`vftable';
  this->TraitsType = Traits_Date;
  MHeap = vm->MHeap;
  v4 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->Alloc(MHeap, 120u, 0);
  v5 = &v4->__vftable;
  if ( v4 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v4, vm, &Scaleform::GFx::AS3::fl::DateCI);
    *v5 = &Scaleform::GFx::AS3::InstanceTraits::fl::Date::`vftable';
    v5[15] = 8;
    v5[13] = 48;
  }
  else
  {
    v5 = 0;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    this,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v5);
  v6 = (Scaleform::GFx::AS3::Class *)MHeap->Alloc(MHeap, 40u, 0);
  v7 = v6;
  if ( v6 )
  {
    Scaleform::GFx::AS3::Class::Class(v6, this);
    v7->__vftable = (Scaleform::GFx::AS3::RefCountBaseGC<328>_vtbl *)&Scaleform::GFx::AS3::Classes::fl::Date::`vftable';
  }
  else
  {
    v7 = 0;
  }
  v8 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v5[17];
  if ( v7 != v8 )
  {
    if ( v8 )
    {
      if ( ((unsigned __int8)v8 & 1) != 0 )
      {
        v5[17] = (char *)v8 - 1;
        v5[17] = v7;
        return;
      }
      RefCount = v8->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        v8->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
      }
    }
    v5[17] = v7;
  }
}
