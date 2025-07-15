void __thiscall Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double::Vector_double(
        Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // edi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v4; // eax
  _DWORD *v5; // esi
  Scaleform::GFx::AS3::Class *v6; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v8; // ecx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS3::ClassTraits::Traits::Traits(
    this,
    vm,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl_vec::Vector_doubleCI);
  this->__vftable = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double_vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double::`vftable';
  MHeap = vm->MHeap;
  v4 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->Alloc(MHeap, 120u, 0);
  v5 = &v4->__vftable;
  if ( v4 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
      v4,
      vm,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl_vec::Vector_doubleCI);
    v5[14] |= 1u;
    *v5 = &Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::`vftable';
    v5[13] = 60;
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
    v7->__vftable = (Scaleform::GFx::AS3::RefCountBaseGC<328>_vtbl *)&Scaleform::GFx::AS3::Classes::fl_vec::Vector_double::`vftable';
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
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v8->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
      }
    }
    v5[17] = v7;
  }
}
