void __thiscall Scaleform::GFx::AS3::ClassTraits::fl_display::MorphShape::MorphShape(
        Scaleform::GFx::AS3::ClassTraits::fl_display::MorphShape *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // ebx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v4; // eax
  _DWORD *v5; // esi
  Scaleform::GFx::AS3::Class *v6; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v8; // ebx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v9; // ecx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS3::ClassTraits::Traits::Traits(this, vm, &Scaleform::GFx::AS3::fl_display::MorphShapeCI);
  this->__vftable = (Scaleform::GFx::AS3::ClassTraits::fl_display::MorphShape_vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::SecurityDomain::`vftable';
  this->TraitsType = Traits_MorphShape;
  MHeap = vm->MHeap;
  v4 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->Alloc(MHeap, 120u, 0);
  v5 = &v4->__vftable;
  if ( v4 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v4, vm, &Scaleform::GFx::AS3::fl_display::MorphShapeCI);
    *v5 = &Scaleform::GFx::AS3::InstanceTraits::fl_display::MorphShape::`vftable';
    v5[15] = 20;
    v5[13] = 56;
  }
  else
  {
    v5 = 0;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    this,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v5);
  v6 = (Scaleform::GFx::AS3::Class *)MHeap->Alloc(MHeap, 40u, 0);
  if ( v6 )
  {
    Scaleform::GFx::AS3::Class::Class(v6, this);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  v9 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v5[17];
  if ( v8 != v9 )
  {
    if ( v9 )
    {
      if ( ((unsigned __int8)v9 & 1) != 0 )
      {
        v5[17] = (char *)v9 - 1;
        v5[17] = v8;
        return;
      }
      RefCount = v9->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        v9->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
      }
    }
    v5[17] = v8;
  }
}
