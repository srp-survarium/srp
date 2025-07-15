void __thiscall Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object::Vector_object(
        Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object *this,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::ASString *n,
        const Scaleform::GFx::AS3::ClassTraits::Traits *ect)
{
  Scaleform::GFx::AS3::VM *v4; // esi
  const Scaleform::GFx::AS3::ClassTraits::Traits *v6; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *v7; // ebx
  const Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // ebp
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *InternedNamespace; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v10; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v11; // ebx
  Scaleform::GFx::AS3::Class *v12; // eax
  Scaleform::GFx::AS3::Class *v13; // esi
  Scaleform::GFx::AS3::Class *v14; // ecx
  unsigned int RefCount; // eax

  v4 = vm;
  Scaleform::GFx::AS3::ClassTraits::Traits::Traits(
    this,
    vm,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl_vec::Vector_objectCI);
  v6 = ect;
  this->__vftable = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object_vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object::`vftable';
  this->EnclosedClassTraits.pObject = v6;
  if ( v6 )
    v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
  this->TraitsType = Traits_Vector_object;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *)v4->MHeap->Alloc(v4->MHeap, 108u, 0);
  if ( v7 )
  {
    pObject = v4->TraitsObject.pObject->ITraits.pObject;
    InternedNamespace = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
                          v4,
                          (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&vm,
                          NS_Public,
                          (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::NS_Vector);
    Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object::Vector_object(
      v7,
      v4,
      n,
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace>)InternedNamespace->pV,
      pObject,
      1,
      1);
    v11.pV = v10;
  }
  else
  {
    v11.pV = 0;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(this, v11);
  v12 = (Scaleform::GFx::AS3::Class *)v4->MHeap->Alloc(v4->MHeap, 40u, 0);
  v13 = v12;
  if ( v12 )
  {
    Scaleform::GFx::AS3::Class::Class(v12, this);
    v13->__vftable = (Scaleform::GFx::AS3::Class_vtbl *)&Scaleform::GFx::AS3::Classes::fl_vec::Vector_object::`vftable';
  }
  else
  {
    v13 = 0;
  }
  v14 = v11.pV->pConstructor.pObject;
  if ( v13 != v14 )
  {
    if ( v14 )
    {
      if ( ((unsigned __int8)v14 & 1) != 0 )
      {
        v11.pV->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v14 - 1);
        v11.pV->pConstructor.pObject = v13;
        return;
      }
      RefCount = v14->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v14->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
      }
    }
    v11.pV->pConstructor.pObject = v13;
  }
}
