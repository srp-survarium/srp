void __thiscall Scaleform::GFx::AS3::ClassTraits::Traits::Traits(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::Traits::Traits(&this->Scaleform::GFx::AS3::Traits, vm);
  this->__vftable = (Scaleform::GFx::AS3::ClassTraits::Traits_vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::SecurityDomain::`vftable';
  this->ITraits.pObject = 0;
  this->Flags |= 0x20u;
}


void __thiscall Scaleform::GFx::AS3::ClassTraits::Traits::Traits(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::ASStringNode *ci)
{
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *ParentClassTraits; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **pObject; // ebx
  unsigned __int8 i; // bl
  unsigned __int8 j; // bl

  if ( vm->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    AppDomain = vm->CallStack.Pages[(vm->CallStack.Size - 1) >> 6][(vm->CallStack.Size - 1) & 0x3F].pFile->AppDomain;
  else
    AppDomain = vm->CurrentDomain;
  ParentClassTraits = Scaleform::GFx::AS3::Traits::RetrieveParentClassTraits(vm, ci, AppDomain);
  Scaleform::GFx::AS3::Traits::Traits(&this->Scaleform::GFx::AS3::Traits, vm, ParentClassTraits, 1, 0);
  this->__vftable = (Scaleform::GFx::AS3::ClassTraits::Traits_vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::SecurityDomain::`vftable';
  this->ITraits.pObject = 0;
  pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)vm->TraitsClassClass.pObject->ITraits.pObject;
  if ( !pObject[17] )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **))(*pObject)->V.ValueA.Data.Data)(pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pConstructor,
    pObject[17]);
  this->Flags |= 0x20u;
  if ( !this->pParent.pObject )
    Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(this);
  for ( i = 0; i < BYTE1(ci->pLower); ++i )
    Scaleform::GFx::AS3::Traits::AddSlot(
      &this->Scaleform::GFx::AS3::Traits,
      (Scaleform::GFx::ASStringNode *)(ci->HashFlags + 12 * i));
  for ( j = 0; j < LOBYTE(ci->pLower); ++j )
    Scaleform::GFx::AS3::Traits::Add2VT(
      &this->Scaleform::GFx::AS3::Traits,
      (const Scaleform::GFx::AS3::ClassInfo *)ci,
      (const Scaleform::GFx::AS3::ThunkInfo *)(ci->RefCount + 20 * j));
}


void __thiscall Scaleform::GFx::AS3::ClassTraits::Traits::Traits(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::ClassTraits::Traits *pt)
{
  Scaleform::GFx::AS3::ClassTraits::ClassClass *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **v5; // edi

  Scaleform::GFx::AS3::Traits::Traits(&this->Scaleform::GFx::AS3::Traits, vm, pt, 1, 0);
  this->__vftable = (Scaleform::GFx::AS3::ClassTraits::Traits_vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::SecurityDomain::`vftable';
  this->ITraits.pObject = 0;
  pObject = vm->TraitsClassClass.pObject;
  v5 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)pObject->ITraits.pObject;
  if ( !v5[17] )
    ((void (__thiscall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *))(*v5)->V.ValueA.Data.Data)(pObject->ITraits.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pConstructor,
    v5[17]);
  this->Flags |= 0x20u;
  if ( !this->pParent.pObject )
    Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(this);
}
