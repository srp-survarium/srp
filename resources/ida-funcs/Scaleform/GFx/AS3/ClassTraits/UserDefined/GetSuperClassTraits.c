const Scaleform::GFx::AS3::ClassTraits::Traits *__cdecl Scaleform::GFx::AS3::ClassTraits::UserDefined::GetSuperClassTraits(
        Scaleform::GFx::AS3::VMAbcFile *file,
        const Scaleform::GFx::AS3::Abc::ClassInfo *info)
{
  int super_name_ind; // ecx
  const Scaleform::GFx::AS3::ClassTraits::Traits *result; // eax
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v7; // [esp+0h] [ebp-8h] BYREF

  super_name_ind = info->inst_info.super_name_ind;
  result = 0;
  if ( super_name_ind )
  {
    result = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
               file->VMRef,
               file,
               &file->File.pObject->Const_Pool.const_multiname.Data.Data[super_name_ind]);
    if ( !result )
    {
      VMRef = file->VMRef;
      Scaleform::GFx::AS3::VM::Error::Error(&v7, eNotImplementedError, VMRef);
      Scaleform::GFx::AS3::VM::ThrowVerifyError(VMRef, v5);
      pNode = v7.Message.pNode;
      --v7.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return 0;
    }
  }
  return result;
}
