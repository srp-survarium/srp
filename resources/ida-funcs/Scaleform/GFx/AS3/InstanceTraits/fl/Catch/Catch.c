void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl::Catch::Catch(
        Scaleform::GFx::AS3::InstanceTraits::fl::Catch *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *e)
{
  const Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v5; // ebx
  unsigned int var_name_ind; // eax
  unsigned int exc_type_ind; // ecx
  Scaleform::GFx::AS3::SlotInfo::BindingType BindingType; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ecx
  Scaleform::GFx::ASStringNode *v10; // eax

  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, vm, &Scaleform::GFx::AS3::fl::CatchCI);
  v5 = e;
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::fl::Catch_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
  this->TraitsType = Traits_Catch;
  var_name_ind = v5->var_name_ind;
  if ( var_name_ind )
    var_name_ind = file->File.pObject->Const_Pool.ConstStr.Data.Size - var_name_ind;
  Scaleform::GFx::AS3::VMFile::GetInternedString(file, (Scaleform::GFx::ASString *)&vm, var_name_ind);
  exc_type_ind = v5->exc_type_ind;
  BindingType = BT_Value;
  if ( exc_type_ind )
    BindingType = Scaleform::GFx::AS3::Traits::GetBindingType(
                    this,
                    file,
                    &file->File.pObject->Const_Pool.const_multiname.Data.Data[exc_type_ind]);
  pObject = this->pVM->PublicNamespace.pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::Traits::AddSlot(
    this,
    (const Scaleform::GFx::ASString *)&vm,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const >)pObject,
    BindingType,
    0,
    0);
  Scaleform::GFx::AS3::Traits::CalculateMemSize(this, 0x20u);
  v10 = (Scaleform::GFx::ASStringNode *)vm;
  --vm->StringManagerRef;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
}
