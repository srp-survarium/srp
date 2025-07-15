const Scaleform::GFx::AS3::SlotInfo *__thiscall Scaleform::GFx::AS3::Traits::FindSlotInfo(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::VMAbcFile *v3; // ebx
  const Scaleform::GFx::AS3::Abc::Multiname *v4; // ebp
  const Scaleform::GFx::AS3::Abc::NamespaceInfo *p_any_namespace; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // edi
  Scaleform::GFx::ASString *InternedString; // eax
  Scaleform::GFx::AS3::Slots *v9; // esi
  const Scaleform::GFx::AS3::SlotInfo *p_Value; // esi
  Scaleform::GFx::ASStringNode *v11; // eax

  v3 = file;
  v4 = mn;
  if ( mn->Ind )
    p_any_namespace = &file->File.pObject->Const_Pool.ConstNamespace.Data.Data[mn->Ind];
  else
    p_any_namespace = &file->File.pObject->Const_Pool.any_namespace;
  InternedNamespace = Scaleform::GFx::AS3::VM::GetInternedNamespace(
                        this->pVM,
                        p_any_namespace->Kind,
                        (Scaleform::GFx::ASStringNode *)&p_any_namespace->NameURI);
  InternedString = Scaleform::GFx::AS3::VMFile::GetInternedString(
                     v3,
                     (Scaleform::GFx::ASString *)&mn,
                     (Scaleform::GFx::ASStringNode *)v4->NameIndex);
  v9 = &this->Scaleform::GFx::AS3::Slots;
  Scaleform::GFx::AS3::Slots::FindSlotInfoIndex(
    v9,
    (Scaleform::GFx::AS3::AbsoluteIndex *)&file,
    InternedString,
    InternedNamespace);
  if ( (int)file < 0 )
  {
    p_Value = 0;
  }
  else if ( (unsigned int)file >= v9->FirstOwnSlotNum )
  {
    p_Value = &v9->VArray.Data.Data[(unsigned int)file - v9->FirstOwnSlotNum].Value;
  }
  else
  {
    p_Value = Scaleform::GFx::AS3::Slots::GetSlotInfo(
                (Scaleform::GFx::AS3::Slots *)v9->Parent,
                (Scaleform::GFx::AS3::AbsoluteIndex)file);
  }
  v11 = (Scaleform::GFx::ASStringNode *)mn;
  --mn->Kind;
  if ( !v11->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  return p_Value;
}
