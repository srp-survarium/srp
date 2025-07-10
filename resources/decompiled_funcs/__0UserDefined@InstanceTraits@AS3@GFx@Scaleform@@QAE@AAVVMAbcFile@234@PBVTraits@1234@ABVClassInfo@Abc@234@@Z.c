void __thiscall Scaleform::GFx::AS3::InstanceTraits::UserDefined::UserDefined(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        const Scaleform::GFx::AS3::InstanceTraits::Traits *pt,
        const Scaleform::GFx::AS3::Abc::ClassInfo *info)
{
  const Scaleform::GFx::AS3::Abc::ClassInfo *v4; // ebp
  unsigned __int8 flags; // cl
  Scaleform::GFx::AS3::VMAbcFile *v7; // edi
  Scaleform::GFx::AS3::Abc::File *pObject; // edx
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  Scaleform::GFx::AS3::VM *VMRef; // ebx
  const Scaleform::GFx::ASString *InternedString; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  int v13; // eax
  int v14; // ecx
  const Scaleform::GFx::AS3::InstanceTraits::Traits *v15; // eax
  unsigned int MemSize; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v17; // [esp-14h] [ebp-24h]
  const Scaleform::GFx::AS3::InstanceTraits::Traits *v18; // [esp-10h] [ebp-20h]
  bool v19; // [esp-Ch] [ebp-1Ch]
  bool isFinal; // [esp+Ch] [ebp-4h]

  v4 = info;
  flags = info->inst_info.flags;
  v7 = file;
  pObject = file->File.pObject;
  LOBYTE(info) = flags & 1;
  isFinal = (flags & 2) != 0;
  InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
                        file,
                        pObject->Const_Pool.const_multiname.Data.Data[v4->inst_info.name_ind].Ind);
  if ( InternedNamespace )
    InternedNamespace->RefCount = (InternedNamespace->RefCount + 1) & 0x8FBFFFFF;
  VMRef = v7->VMRef;
  v19 = (_BYTE)info == 0;
  v18 = pt;
  v17.pV = InternedNamespace;
  InternedString = Scaleform::GFx::AS3::VMFile::GetInternedString(
                     v7,
                     (Scaleform::GFx::ASString *)&file,
                     v7->File.pObject->Const_Pool.const_multiname.Data.Data[v4->inst_info.name_ind].NameIndex);
  Scaleform::GFx::AS3::InstanceTraits::RTraits::RTraits(this, VMRef, InternedString, v17, v18, v19, isFinal);
  v12 = (Scaleform::GFx::ASStringNode *)file;
  --file->pPrev;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::UserDefined_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::UserDefined::`vftable';
  this->Script.pObject = 0;
  this->Flags |= 0x10u;
  v13 = this->Flags;
  this->class_info = v4;
  v14 = v13 ^ ((unsigned __int8)v13 ^ (unsigned __int8)-((v4->inst_info.flags >> 2) & 1)) & 4;
  v15 = pt;
  this->Flags = v14;
  if ( v15 )
    MemSize = v15->MemSize;
  else
    MemSize = Scaleform::GFx::AS3::InstanceTraits::RTraits::GetFixedMemSize(this);
  if ( Scaleform::GFx::AS3::Traits::AddSlots(this, (Scaleform::GFx::AS3::CheckResult *)&pt, &v4->inst_info, v7, MemSize)->Result )
    Scaleform::GFx::AS3::InstanceTraits::UserDefined::AddInterfaceSlots2This(this, (Scaleform::GFx::AS3::VM *)v7, this);
}
