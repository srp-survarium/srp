const Scaleform::GFx::AS3::SlotInfo *__thiscall Scaleform::GFx::AS3::Traits::FindSlotInfo(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        const Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  const Scaleform::GFx::AS3::Abc::Multiname *v3; // ebx
  Scaleform::GFx::AS3::VMAbcFile *v4; // edi
  const Scaleform::GFx::AS3::Abc::NamespaceInfo *p_any_namespace; // eax
  Scaleform::GFx::ASString *InternedString; // eax
  const Scaleform::GFx::AS3::SlotInfo *SlotInfo; // esi
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // [esp-4h] [ebp-10h]

  v3 = mn;
  v4 = file;
  if ( mn->Ind )
    p_any_namespace = &file->File.pObject->Const_Pool.ConstNamespace.Data.Data[mn->Ind];
  else
    p_any_namespace = &file->File.pObject->Const_Pool.any_namespace;
  InternedNamespace = Scaleform::GFx::AS3::VM::GetInternedNamespace(
                        this->pVM,
                        p_any_namespace->Kind,
                        (Scaleform::GFx::ASStringNode *)&p_any_namespace->NameURI);
  InternedString = Scaleform::GFx::AS3::VMFile::GetInternedString(
                     v4,
                     (Scaleform::GFx::ASString *)&file,
                     (Scaleform::GFx::ASStringNode *)v3->NameIndex);
  SlotInfo = Scaleform::GFx::AS3::Slots::FindSlotInfo(
               &this->Scaleform::GFx::AS3::Slots,
               InternedString,
               InternedNamespace);
  v9 = (Scaleform::GFx::ASStringNode *)file;
  --file->pPrev;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  return SlotInfo;
}
