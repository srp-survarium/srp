Scaleform::GFx::AS3::ClassTraits::ClassClass *__thiscall Scaleform::GFx::AS3::VM::GetUserDefinedTraits(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::ASStringNode *ci)
{
  Scaleform::GFx::AS3::Abc::Multiname *v4; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // ebp
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // ecx
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v8; // ebx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // eax
  Scaleform::GFx::ASStringNode *pNode; // ebx
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v11; // esi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::VMFile *filea; // [esp+18h] [ebp+4h]

  v4 = (Scaleform::GFx::AS3::Abc::Multiname *)file->GetMultiname(file, ci->Size);
  Scaleform::GFx::AS3::VMFile::GetInternedString(
    file,
    (Scaleform::GFx::ASString *)&ci,
    (Scaleform::GFx::ASStringNode *)v4->NameIndex);
  InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
                        file,
                        (Scaleform::GFx::AS3::Instances::fl::Namespace *)v4->Ind);
  AppDomain = file->AppDomain;
  ParentDomain = AppDomain->ParentDomain;
  v8 = InternedNamespace;
  if ( !ParentDomain
    || (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(
                       ParentDomain,
                       (const Scaleform::GFx::ASString *)&ci,
                       InternedNamespace)) == 0 )
  {
    filea = (Scaleform::GFx::AS3::VMFile *)Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                                             &AppDomain->ClassTraitsSet,
                                             (const Scaleform::GFx::ASString *)&ci,
                                             v8);
    if ( !filea )
    {
      pNode = v8->Uri.pNode;
      if ( pNode->Size >= 0xD && !strncmp(pNode->pData, "scaleform.gfx", 0xDu) )
      {
        v11 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, file, v4);
        goto LABEL_9;
      }
    }
    ClassTrait = (Scaleform::GFx::AS3::ClassTraits::Traits **)filea;
  }
  v11 = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)*ClassTrait;
LABEL_9:
  v12 = ci;
  --ci->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  return v11;
}
