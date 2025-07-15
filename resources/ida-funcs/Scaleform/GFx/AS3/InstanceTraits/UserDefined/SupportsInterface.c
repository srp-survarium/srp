char __thiscall Scaleform::GFx::AS3::InstanceTraits::UserDefined::SupportsInterface(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this,
        const Scaleform::GFx::AS3::InstanceTraits::Traits *itraits)
{
  Scaleform::GFx::AS3::Abc::Instance::Interfaces *p_implemented_interfaces; // ebp
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *pObject; // esi
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v6; // esi
  const Scaleform::GFx::AS3::Abc::Multiname *v7; // edi
  Scaleform::GFx::AS3::VM *v8; // ecx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v9; // esi
  Scaleform::GFx::AS3::VM *v10; // ecx
  const Scaleform::GFx::AS3::ClassTraits::Traits *RegisteredClassTraits; // eax
  const Scaleform::GFx::AS3::InstanceTraits::Traits *v12; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v14; // ecx
  unsigned int v16; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v17; // ecx
  unsigned int i; // [esp+8h] [ebp-24h]
  Scaleform::GFx::AS3::VM *vm; // [esp+Ch] [ebp-20h]
  unsigned int size; // [esp+10h] [ebp-1Ch]
  Scaleform::GFx::AS3::Multiname interfaceMN; // [esp+14h] [ebp-18h] BYREF

  p_implemented_interfaces = &this->class_info->inst_info.implemented_interfaces;
  vm = this->pVM;
  size = this->class_info->inst_info.implemented_interfaces.info.Data.Size;
  i = 0;
  if ( !size )
    return 0;
  while ( 1 )
  {
    pObject = this->Script.pObject;
    if ( !pObject->Initialized )
    {
      pObject->Execute(this->Script.pObject);
      pVM = pObject->pTraits.pObject->pVM;
      if ( !pVM->HandleException )
        Scaleform::GFx::AS3::VM::ExecuteCode(pVM, 1u);
    }
    v6 = this->Script.pObject;
    v7 = (const Scaleform::GFx::AS3::Abc::Multiname *)(*(_DWORD *)(*(_DWORD *)(v6->pTraits.pObject[1].FirstOwnSlotNum
                                                                             + 60)
                                                                 + 88)
                                                     + 16 * p_implemented_interfaces->info.Data.Data[i]);
    if ( !v6->Initialized )
    {
      v6->Execute(this->Script.pObject);
      v8 = v6->pTraits.pObject->pVM;
      if ( !v8->HandleException )
        Scaleform::GFx::AS3::VM::ExecuteCode(v8, 1u);
    }
    Scaleform::GFx::AS3::Multiname::Multiname(
      &interfaceMN,
      (Scaleform::GFx::AS3::VMFile *)this->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum,
      v7);
    v9 = this->Script.pObject;
    if ( !v9->Initialized )
    {
      v9->Execute(this->Script.pObject);
      v10 = v9->pTraits.pObject->pVM;
      if ( !v10->HandleException )
        Scaleform::GFx::AS3::VM::ExecuteCode(v10, 1u);
    }
    RegisteredClassTraits = Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(
                              vm,
                              &interfaceMN,
                              *(Scaleform::GFx::AS3::VMAppDomain **)(this->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum
                                                                   + 24));
    if ( !RegisteredClassTraits )
      goto LABEL_14;
    v12 = RegisteredClassTraits->ITraits.pObject;
    if ( v12 == itraits )
      break;
    if ( v12->SupportsInterface((Scaleform::GFx::AS3::InstanceTraits::Traits *)v12, itraits) )
    {
      Scaleform::GFx::AS3::Multiname::~Multiname(&interfaceMN);
      return 1;
    }
LABEL_14:
    if ( (interfaceMN.Name.Flags & 0x1F) > 9 )
    {
      if ( (interfaceMN.Name.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&interfaceMN.Name);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&interfaceMN.Name);
    }
    if ( interfaceMN.Obj.pObject && ((int)interfaceMN.Obj.pObject & 1) == 0 )
    {
      RefCount = interfaceMN.Obj.pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        v14 = interfaceMN.Obj.pObject;
        interfaceMN.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
      }
    }
    if ( ++i >= size )
      return 0;
  }
  if ( (interfaceMN.Name.Flags & 0x1F) > 9 )
  {
    if ( (interfaceMN.Name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&interfaceMN.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&interfaceMN.Name);
  }
  if ( interfaceMN.Obj.pObject )
  {
    if ( ((int)interfaceMN.Obj.pObject & 1) == 0 )
    {
      v16 = interfaceMN.Obj.pObject->RefCount;
      v17 = interfaceMN.Obj.pObject;
      if ( ((unsigned int)&byte_3FFFFF & v16) != 0 )
      {
        interfaceMN.Obj.pObject->RefCount = v16 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
      }
    }
  }
  return 1;
}
