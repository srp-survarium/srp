void __thiscall Scaleform::GFx::AS3::ClassTraits::fl_gfx::IMEEventEx::IMEEventEx(
        Scaleform::GFx::AS3::ClassTraits::fl_gfx::IMEEventEx *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // edi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v4; // eax
  _DWORD *v5; // esi
  Scaleform::GFx::AS3::Classes::fl_gfx::IMEEventEx *v6; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v8; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v9; // ecx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS3::ClassTraits::Traits::Traits(this, vm, &Scaleform::GFx::AS3::fl_gfx::IMEEventExCI);
  this->__vftable = (Scaleform::GFx::AS3::ClassTraits::fl_gfx::IMEEventEx_vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::IMEEventEx::`vftable';
  MHeap = vm->MHeap;
  v4 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->Alloc(MHeap, 120u, 0);
  v5 = &v4->__vftable;
  if ( v4 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v4, vm, &Scaleform::GFx::AS3::fl_gfx::IMEEventExCI);
    *v5 = &Scaleform::GFx::AS3::InstanceTraits::fl_gfx::IMEEventEx::`vftable';
    v5[13] = 56;
  }
  else
  {
    v5 = 0;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    this,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v5);
  v6 = (Scaleform::GFx::AS3::Classes::fl_gfx::IMEEventEx *)MHeap->Alloc(MHeap, 72u, 0);
  if ( v6 )
  {
    Scaleform::GFx::AS3::Classes::fl_gfx::IMEEventEx::IMEEventEx(v6, this);
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
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v9->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
      }
    }
    v5[17] = v8;
  }
}
