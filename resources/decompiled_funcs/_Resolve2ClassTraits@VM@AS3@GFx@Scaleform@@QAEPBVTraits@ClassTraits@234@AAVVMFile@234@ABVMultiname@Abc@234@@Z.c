Scaleform::GFx::AS3::ClassTraits::ClassClass *__thiscall Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  const Scaleform::GFx::AS3::Abc::Multiname *v3; // ebx
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *pObject; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *v9; // ebp
  unsigned int NextIndex; // ebx
  Scaleform::GFx::AS3::ClassTraits::fl::String *v11; // eax
  const Scaleform::GFx::AS3::Abc::Multiname *v12; // eax
  Scaleform::GFx::AS3::Classes::fl_vec::Vector *Class; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *v15; // [esp-Ch] [ebp-14h]

  v3 = mn;
  if ( mn->Kind == MN_QName && !mn->NameIndex && !mn->Ind )
    return this->TraitsClassClass.pObject;
  Scaleform::GFx::AS3::VMFile::GetInternedString(
    file,
    (Scaleform::GFx::ASString *)&mn,
    (Scaleform::GFx::ASStringNode *)mn->NameIndex);
  v6 = (Scaleform::GFx::ASStringNode *)mn;
  if ( mn == (Scaleform::GFx::AS3::Abc::Multiname *)this->StringManagerRef->Builtins[3].pNode )
  {
    pObject = this->TraitsObject.pObject;
    --mn->Kind;
    if ( !v6->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    return (Scaleform::GFx::AS3::ClassTraits::ClassClass *)pObject;
  }
  else
  {
    InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
                          file,
                          (Scaleform::GFx::AS3::Instances::fl::Namespace *)v3->Ind);
    v9 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
                                                               this,
                                                               (const Scaleform::GFx::ASString *)&mn,
                                                               InternedNamespace,
                                                               file->AppDomain);
    if ( v9 == this->TraitsVector.pObject )
    {
      NextIndex = v3->NextIndex;
      if ( NextIndex )
      {
        v12 = file->GetMultiname(file, NextIndex);
        v11 = (Scaleform::GFx::AS3::ClassTraits::fl::String *)Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
                                                                this,
                                                                file,
                                                                v12);
      }
      else
      {
        v11 = (Scaleform::GFx::AS3::ClassTraits::fl::String *)this->TraitsObject.pObject;
      }
      if ( v11 )
      {
        if ( v11 == (Scaleform::GFx::AS3::ClassTraits::fl::String *)this->TraitsInt.pObject )
        {
          v9 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)this->TraitsVector_int.pObject;
        }
        else if ( v11 == (Scaleform::GFx::AS3::ClassTraits::fl::String *)this->TraitsUint.pObject )
        {
          v9 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)this->TraitsVector_uint.pObject;
        }
        else if ( v11 == (Scaleform::GFx::AS3::ClassTraits::fl::String *)this->TraitsNumber.pObject )
        {
          v9 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)this->TraitsVector_Number.pObject;
        }
        else if ( v11 == this->TraitsString.pObject )
        {
          v9 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)this->TraitsVector_String.pObject;
        }
        else if ( v11->ITraits.pObject )
        {
          v15 = v11;
          Class = (Scaleform::GFx::AS3::Classes::fl_vec::Vector *)Scaleform::GFx::AS3::Traits::GetClass(v9->ITraits.pObject);
          v9 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)Scaleform::GFx::AS3::Classes::fl_vec::Vector::Resolve2Vector(
                                                                     Class,
                                                                     v15);
        }
      }
    }
    v14 = (Scaleform::GFx::ASStringNode *)mn;
    --mn->Kind;
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    return (Scaleform::GFx::AS3::ClassTraits::ClassClass *)v9;
  }
}
