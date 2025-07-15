const Scaleform::GFx::AS3::ClassTraits::Traits *__cdecl Scaleform::GFx::AS3::ClassTraits::UserDefined::GetSuperClassTraits(
        Scaleform::GFx::AS3::VMAbcFile *file,
        const Scaleform::GFx::AS3::Abc::ClassInfo *info)
{
  int super_name_ind; // ecx
  const Scaleform::GFx::AS3::ClassTraits::Traits *v3; // eax
  Scaleform::GFx::AS3::Abc::Multiname *v4; // edi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr result; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::GFx::AS3::VM::Error v8; // [esp+14h] [ebp-8h] BYREF

  super_name_ind = info->inst_info.super_name_ind;
  v3 = 0;
  if ( super_name_ind )
  {
    v4 = &file->File.pObject->Const_Pool.const_multiname.Data.Data[super_name_ind];
    v3 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(file->VMRef, file, v4);
    if ( !v3 )
    {
      Scaleform::GFx::AS3::Abc::StringView::ToStringDataPtr(
        &file->File.pObject->Const_Pool.ConstStr.Data.Data[v4->NameIndex],
        &result);
      Scaleform::GFx::AS3::VM::Error::Error(&v8, eNotImplementedError, file->VMRef, result);
      Scaleform::GFx::AS3::VM::ThrowVerifyError(file->VMRef, v5);
      pNode = v8.Message.pNode;
      --v8.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return 0;
    }
  }
  return v3;
}
