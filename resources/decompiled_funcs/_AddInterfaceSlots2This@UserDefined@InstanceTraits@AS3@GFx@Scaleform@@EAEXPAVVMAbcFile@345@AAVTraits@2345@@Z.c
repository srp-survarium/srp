void __thiscall Scaleform::GFx::AS3::InstanceTraits::UserDefined::AddInterfaceSlots2This(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this,
        Scaleform::GFx::AS3::VM *file_ptr,
        Scaleform::GFx::AS3::InstanceTraits::Traits *This)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *pObject; // esi
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::AS3::VMAbcFile *FirstOwnSlotNum; // esi
  Scaleform::GFx::AS3::Abc::Instance::Interfaces *p_implemented_interfaces; // edi
  int v8; // ebx
  const Scaleform::GFx::AS3::ClassTraits::Traits *RegisteredClassTraits; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v10; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v12; // ecx
  Scaleform::GFx::AS3::VM *v13; // esi
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int v16; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v17; // ecx
  Scaleform::GFx::AS3::VM::Error v18; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Multiname interfaceMN; // [esp+18h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [esp+34h] [ebp+4h]

  pObject = this->Script.pObject;
  if ( pObject )
  {
    if ( !pObject->Initialized )
    {
      pObject->Execute(this->Script.pObject);
      pVM = pObject->pTraits.pObject->pVM;
      if ( !pVM->HandleException )
        Scaleform::GFx::AS3::VM::ExecuteCode(pVM, 1u);
    }
    FirstOwnSlotNum = (Scaleform::GFx::AS3::VMAbcFile *)this->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum;
  }
  else
  {
    FirstOwnSlotNum = (Scaleform::GFx::AS3::VMAbcFile *)file_ptr;
  }
  p_implemented_interfaces = &this->class_info->inst_info.implemented_interfaces;
  v8 = 0;
  vm = this->pVM;
  if ( this->class_info->inst_info.implemented_interfaces.info.Data.Size )
  {
    while ( 1 )
    {
      Scaleform::GFx::AS3::Multiname::Multiname(
        &interfaceMN,
        FirstOwnSlotNum,
        &FirstOwnSlotNum->File.pObject->Const_Pool.const_multiname.Data.Data[p_implemented_interfaces->info.Data.Data[v8]]);
      RegisteredClassTraits = Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(
                                vm,
                                &interfaceMN,
                                FirstOwnSlotNum->AppDomain);
      if ( !RegisteredClassTraits )
      {
        RegisteredClassTraits = Scaleform::GFx::AS3::FindGOTraits(
                                  this->pVM,
                                  &this->pVM->GlobalObjects,
                                  &interfaceMN,
                                  FirstOwnSlotNum->AppDomain);
        if ( !RegisteredClassTraits )
          break;
      }
      v10 = RegisteredClassTraits->ITraits.pObject;
      if ( !v10 )
        break;
      Scaleform::GFx::AS3::InstanceTraits::Traits::AddInterfaceSlots(This, FirstOwnSlotNum, v10);
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
        v12 = interfaceMN.Obj.pObject;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          interfaceMN.Obj.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
        }
      }
      if ( ++v8 >= p_implemented_interfaces->info.Data.Size )
        return;
    }
    v13 = this->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eClassNotFoundError, v13);
    Scaleform::GFx::AS3::VM::ThrowVerifyError(v13, v14);
    pNode = v18.Message.pNode;
    --v18.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
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
  }
}
