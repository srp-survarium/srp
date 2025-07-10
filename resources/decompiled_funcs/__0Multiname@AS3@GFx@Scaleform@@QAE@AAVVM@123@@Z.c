void __thiscall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // ebp
  Scaleform::GFx::AS3::Value *p_Name; // ecx
  Scaleform::GFx::ASStringManager *pStringManager; // esi
  Scaleform::GFx::AS3::VM *p_EmptyStringNode; // esi

  v2 = vm;
  this->Kind = MN_QName;
  this->Obj.pObject = 0;
  p_Name = &this->Name;
  p_Name->Flags = 0;
  p_Name->Bonus.pWeakProxy = 0;
  pStringManager = v2->StringManagerRef->pStringManager;
  ++pStringManager->EmptyStringNode.RefCount;
  p_EmptyStringNode = (Scaleform::GFx::AS3::VM *)&pStringManager->EmptyStringNode;
  vm = p_EmptyStringNode;
  Scaleform::GFx::AS3::Value::Assign(p_Name, (const Scaleform::GFx::ASString *)&vm);
  if ( p_EmptyStringNode->StringManagerRef-- == (Scaleform::GFx::AS3::StringManager *)1 )
    Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)p_EmptyStringNode);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Obj,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v2->DefXMLNamespace.pObject);
  if ( !this->Obj.pObject )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Obj,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v2->PublicNamespace.pObject);
}
