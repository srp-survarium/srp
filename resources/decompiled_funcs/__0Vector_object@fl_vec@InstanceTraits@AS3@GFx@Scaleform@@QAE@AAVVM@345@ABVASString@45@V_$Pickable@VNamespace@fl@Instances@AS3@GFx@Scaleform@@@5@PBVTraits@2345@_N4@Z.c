void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object::Vector_object(
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *this,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::ASString *n,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> ns,
        const Scaleform::GFx::AS3::InstanceTraits::Traits *pt,
        bool isDynamic,
        bool isFinal)
{
  int v8; // edi
  int v9; // ebx

  Scaleform::GFx::AS3::InstanceTraits::RTraits::RTraits(this, vm, n, ns, pt, isDynamic, isFinal);
  this->Flags |= 1u;
  v8 = 0;
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object::`vftable';
  this->TraitsType = Traits_Vector_object;
  v9 = 23;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(
      this,
      &Scaleform::GFx::AS3::fl_vec::Vector_objectCI,
      &Scaleform::GFx::AS3::fl_vec::Vector_objectCI.InstanceMethod[v8++]);
    --v9;
  }
  while ( v9 );
  this->MemSize = 60;
}
