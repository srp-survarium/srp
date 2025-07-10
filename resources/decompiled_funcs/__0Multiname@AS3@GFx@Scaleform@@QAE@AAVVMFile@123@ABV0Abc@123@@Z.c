void __thiscall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  const Scaleform::GFx::AS3::Abc::Multiname *v3; // esi
  Scaleform::GFx::AS3::Value *p_Name; // ebx
  Scaleform::GFx::ASString *InternedString; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  int v8; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *Ind; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *InternedNamespaceSet; // eax

  v3 = mn;
  this->Kind = mn->Kind;
  this->Obj.pObject = 0;
  p_Name = &this->Name;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0;
  if ( v3->Kind || v3->NameIndex || v3->Ind )
  {
    InternedString = Scaleform::GFx::AS3::VMFile::GetInternedString(
                       file,
                       (Scaleform::GFx::ASString *)&mn,
                       (Scaleform::GFx::ASStringNode *)v3->NameIndex);
    Scaleform::GFx::AS3::Value::Assign(p_Name, InternedString);
    v7 = (Scaleform::GFx::ASStringNode *)mn;
    --mn->Kind;
    if ( !v7->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    Scaleform::GFx::AS3::Multiname::PostProcessName(this, 0);
  }
  v8 = v3->Kind & 3;
  if ( v8 || (v3->Kind & 4) != 0 )
  {
    if ( v8 == 2 )
    {
      InternedNamespaceSet = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)Scaleform::GFx::AS3::VMFile::GetInternedNamespaceSet(
                                                                                        file,
                                                                                        v3->Ind);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Obj,
        InternedNamespaceSet);
    }
  }
  else
  {
    Ind = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v3->Ind;
    if ( Ind )
    {
      InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(file, Ind);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Obj,
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)InternedNamespace);
    }
  }
}
