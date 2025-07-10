bool __thiscall Scaleform::GFx::AS3::VMAbcFile::RegisterUserDefinedClassTraits(Scaleform::GFx::AS3::VMAbcFile *this)
{
  Scaleform::GFx::AS3::Abc::File *pObject; // ebp
  Scaleform::GFx::AS3::VM *VMRef; // ecx
  const Scaleform::GFx::AS3::Abc::ClassTable *p_AS3_Classes; // ebp
  const Scaleform::GFx::AS3::Abc::ClassInfo *v5; // ebx
  Scaleform::GFx::AS3::Abc::Multiname *v6; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // edi
  unsigned int Size; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  const Scaleform::GFx::AS3::ClassTraits::Traits *v10; // eax
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v11; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v12; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v13; // ebx
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *p_ClassTraitsSet; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // edx
  unsigned int v17; // eax
  Scaleform::GFx::AS3::VMAbcFile *v18; // ebx
  unsigned int v19; // edx
  unsigned int v20; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *Data; // ecx
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340,Scaleform::ArrayDefaultPolicy> *p_Children; // ebp
  unsigned int v23; // eax
  unsigned int v24; // edi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v25; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v26; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v28; // eax
  int v29; // ebp
  Scaleform::GFx::AS3::Abc::ClassInfo *v30; // ebx
  Scaleform::GFx::AS3::Abc::Multiname *v31; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v32; // edi
  unsigned int v33; // eax
  Scaleform::GFx::ASStringNode *v34; // ecx
  Scaleform::GFx::AS3::VM *v35; // ebx
  Scaleform::GFx::AS3::ClassTraits::UserDefined *UserDefinedTraits; // eax
  Scaleform::GFx::ASStringNode *v37; // ecx
  bool v38; // zf
  Scaleform::GFx::ASStringNode *v40; // ecx
  Scaleform::GFx::ASStringNode *v41; // [esp-8h] [ebp-30h]
  Scaleform::GFx::AS3::CheckResult result; // [esp+Fh] [ebp-19h] BYREF
  const Scaleform::GFx::AS3::Abc::ClassTable *classes; // [esp+10h] [ebp-18h]
  Scaleform::GFx::ASString str_name; // [esp+14h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [esp+18h] [ebp-10h]
  unsigned int numOfClasses; // [esp+1Ch] [ebp-Ch]
  unsigned int i; // [esp+20h] [ebp-8h]
  Scaleform::GFx::AS3::ClassTraits::Traits *val; // [esp+24h] [ebp-4h] BYREF

  pObject = this->File.pObject;
  VMRef = this->VMRef;
  p_AS3_Classes = &pObject->AS3_Classes;
  classes = p_AS3_Classes;
  numOfClasses = 0;
  vm = VMRef;
  i = 0;
  if ( !p_AS3_Classes->Info.Data.Size )
  {
LABEL_38:
    if ( !p_AS3_Classes->Info.Data.Size )
      goto LABEL_39;
    return 0;
  }
  do
  {
    v5 = p_AS3_Classes->Info.Data.Data[i];
    v6 = &this->File.pObject->Const_Pool.const_multiname.Data.Data[v5->inst_info.name_ind];
    Scaleform::GFx::AS3::VMFile::GetInternedString(this, &str_name, (Scaleform::GFx::ASStringNode *)v6->NameIndex);
    InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
                          this,
                          (Scaleform::GFx::AS3::Instances::fl::Namespace *)v6->Ind);
    if ( (_S14 & 1) != 0 )
    {
      Size = scaleform_gfx.Size;
    }
    else
    {
      _S14 |= 1u;
      Size = 13;
      scaleform_gfx.pStr = "scaleform.gfx";
      scaleform_gfx.Size = 13;
    }
    pNode = InternedNamespace->Uri.pNode;
    if ( pNode->Size < Size || strncmp(pNode->pData, scaleform_gfx.pStr, Size) )
    {
      v10 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, &str_name, InternedNamespace, this->AppDomain);
      if ( v10 )
      {
        v18 = v10->GetFilePtr(&v10->Scaleform::GFx::AS3::Traits);
        if ( v18 )
        {
          v19 = this->Children.Data.Size;
          v20 = 0;
          if ( v19 )
          {
            Data = this->Children.Data.Data;
            while ( Data->pObject != v18 )
            {
              ++v20;
              ++Data;
              if ( v20 >= v19 )
                goto LABEL_23;
            }
          }
          else
          {
LABEL_23:
            p_Children = &this->Children;
            v18->RefCount = (v18->RefCount + 1) & 0x8FBFFFFF;
            v23 = this->Children.Data.Size;
            v24 = v23 + 1;
            if ( v23 + 1 >= v23 )
            {
              if ( v24 >= this->Children.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy> *)&this->Children,
                  &this->Children,
                  v24 + (v24 >> 2));
            }
            else
            {
              Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
                &p_Children->Data.Data[v23 + 1],
                0xFFFFFFFF);
              if ( v24 < this->Children.Data.Policy.Capacity >> 1 )
                Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy> *)&this->Children,
                  &this->Children,
                  v24);
            }
            v25 = p_Children->Data.Data;
            this->Children.Data.Size = v24;
            v26 = &v25[v24 - 1];
            if ( v26 )
            {
              v26->pObject = v18;
              v18->RefCount = (v18->RefCount + 1) & 0x8FBFFFFF;
            }
            if ( ((unsigned __int8)v18 & 1) == 0 )
            {
              RefCount = v18->RefCount;
              if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
              {
                v18->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
              }
            }
            p_AS3_Classes = classes;
          }
        }
      }
      else
      {
        v11 = (Scaleform::GFx::AS3::ClassTraits::UserDefined *)vm->MHeap->Alloc(vm->MHeap, 112, 0);
        if ( v11 )
        {
          Scaleform::GFx::AS3::ClassTraits::UserDefined::UserDefined(v11, this, vm, v5);
          v13 = v12;
        }
        else
        {
          v13 = 0;
        }
        p_ClassTraitsSet = &this->AppDomain->ClassTraitsSet;
        val = v13;
        Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
          p_ClassTraitsSet,
          &str_name,
          InternedNamespace,
          &val);
        v15 = this->LoadedClasses.Data.Size;
        ++numOfClasses;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy> *)&this->LoadedClasses,
          &this->LoadedClasses,
          v15 + 1);
        v16 = this->LoadedClasses.Data.Size;
        if ( &this->LoadedClasses.Data.Data[v16] != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)4 )
        {
          this->LoadedClasses.Data.Data[v16 - 1].pObject = v13;
          if ( !v13 )
            goto LABEL_34;
          v13->RefCount = (v13->RefCount + 1) & 0x8FBFFFFF;
        }
        if ( v13 )
        {
          if ( ((unsigned __int8)v13 & 1) == 0 )
          {
            v17 = v13->RefCount;
            if ( ((unsigned int)&byte_3FFFFF & v17) != 0 )
            {
              v13->RefCount = v17 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
            }
          }
        }
      }
    }
LABEL_34:
    v28 = str_name.pNode;
    --str_name.pNode->RefCount;
    if ( !v28->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v28);
    ++i;
  }
  while ( i < p_AS3_Classes->Info.Data.Size );
  if ( !numOfClasses )
    goto LABEL_38;
LABEL_39:
  v29 = 0;
  if ( classes->Info.Data.Size )
  {
    while ( 1 )
    {
      v30 = classes->Info.Data.Data[v29];
      v31 = &this->File.pObject->Const_Pool.const_multiname.Data.Data[v30->inst_info.name_ind];
      Scaleform::GFx::AS3::VMFile::GetInternedString(this, &str_name, (Scaleform::GFx::ASStringNode *)v31->NameIndex);
      v32 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
              this,
              (Scaleform::GFx::AS3::Instances::fl::Namespace *)v31->Ind);
      if ( (_S14 & 1) != 0 )
      {
        v33 = scaleform_gfx.Size;
      }
      else
      {
        _S14 |= 1u;
        v33 = 13;
        scaleform_gfx.pStr = "scaleform.gfx";
        scaleform_gfx.Size = 13;
      }
      v34 = v32->Uri.pNode;
      if ( v34->Size < v33 || strncmp(v34->pData, scaleform_gfx.pStr, v33) )
      {
        v41 = (Scaleform::GFx::ASStringNode *)v30;
        v35 = vm;
        UserDefinedTraits = (Scaleform::GFx::AS3::ClassTraits::UserDefined *)Scaleform::GFx::AS3::VM::GetUserDefinedTraits(
                                                                               vm,
                                                                               this,
                                                                               v41);
        if ( UserDefinedTraits->File.pObject == this
          && !Scaleform::GFx::AS3::ClassTraits::UserDefined::Initialize(UserDefinedTraits, &result)->Result )
        {
          break;
        }
      }
      v37 = str_name.pNode;
      v38 = str_name.pNode->RefCount-- == 1;
      if ( v38 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v37);
      if ( ++v29 >= classes->Info.Data.Size )
        return !classes->Info.Data.Size || numOfClasses;
    }
    if ( v35->HandleException )
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v35);
    Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Remove(
      &this->AppDomain->ClassTraitsSet,
      &str_name,
      v32);
    v40 = str_name.pNode;
    v38 = str_name.pNode->RefCount-- == 1;
    if ( v38 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v40);
    Scaleform::GFx::AS3::VMAbcFile::UnregisterUserDefinedClassTraits(this);
    return 0;
  }
  return !classes->Info.Data.Size || numOfClasses;
}
