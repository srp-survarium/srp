void __userpurge Scaleform::GFx::AS3::ClassTraits::ClassClass::ClassClass(
        Scaleform::GFx::AS3::ClassTraits::ClassClass *this@<ecx>,
        int a2@<edi>,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // esi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v5; // eax
  _DWORD *v6; // edi
  Scaleform::GFx::AS3::Class *v7; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v8; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v9; // ecx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS3::ClassTraits::Traits::Traits(this, vm);
  this->__vftable = (Scaleform::GFx::AS3::ClassTraits::ClassClass_vtbl *)&Scaleform::GFx::AS3::ClassTraits::ClassClass::`vftable';
  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int))MHeap->Alloc)(
                                                         MHeap,
                                                         120,
                                                         0,
                                                         a2);
  v6 = &v5->__vftable;
  if ( v5 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v5, vm, &Scaleform::GFx::AS3::ClassClassCI);
    *v6 = &Scaleform::GFx::AS3::InstanceTraits::Prototype::`vftable';
  }
  else
  {
    v6 = 0;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    this,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v6);
  v7 = (Scaleform::GFx::AS3::Class *)((int (__thiscall *)(Scaleform::MemoryHeap *, int))MHeap->Alloc)(MHeap, 40);
  v8 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::Class::Class(v7, this);
    v8->__vftable = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object_vtbl *)&Scaleform::GFx::AS3::Classes::ClassClass::`vftable';
  }
  else
  {
    v8 = 0;
  }
  v9 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v6[17];
  if ( v8 != v9 )
  {
    if ( v9 )
    {
      if ( ((unsigned __int8)v9 & 1) != 0 )
      {
        v6[17] = (char *)v9 - 1;
      }
      else
      {
        RefCount = v9->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v9->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
        }
      }
    }
    v6[17] = v8;
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pConstructor,
    v8);
}
