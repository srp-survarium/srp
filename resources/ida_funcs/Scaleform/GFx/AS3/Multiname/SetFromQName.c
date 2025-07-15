void __thiscall Scaleform::GFx::AS3::Multiname::SetFromQName(
        Scaleform::GFx::AS3::Multiname *this,
        const Scaleform::GFx::AS3::Value *nameVal)
{
  Scaleform::GFx::AS3::Value::V1U v2; // ebp
  Scaleform::GFx::AS3::Value *p_Name; // ebx
  Scaleform::GFx::ASStringNode *v5; // eax
  Scaleform::GFx::AS3::Value::Extra v6; // esi
  Scaleform::GFx::ASStringNode *v7; // esi
  Scaleform::GFx::ASString v; // [esp+Ch] [ebp-4h] BYREF
  const Scaleform::GFx::AS3::Value *nameVala; // [esp+14h] [ebp+4h]

  v2 = nameVal->value.VS._1;
  p_Name = &this->Name;
  Scaleform::GFx::AS3::Value::Assign(&this->Name, (const Scaleform::GFx::ASString *)(v2.VInt + 32));
  if ( (p_Name->Flags & 0x1F) == 0xA )
  {
    nameVala = (const Scaleform::GFx::AS3::Value *)this->Name.value.VS._1.VInt;
    ++nameVala->value.VS._2.VObj;
    v5 = (Scaleform::GFx::ASStringNode *)nameVala;
    if ( nameVala[1].Bonus.pWeakProxy && *(_BYTE *)nameVala->Flags == 42 )
    {
      v6.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)nameVala->Bonus;
      ++v6.pWeakProxy[5].pObject;
      v7 = (Scaleform::GFx::ASStringNode *)&v6.pWeakProxy[4];
      v.pNode = v7;
      Scaleform::GFx::AS3::Value::Assign(p_Name, &v);
      if ( v7->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v7);
      v5 = (Scaleform::GFx::ASStringNode *)nameVala;
    }
    if ( !--v5->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Obj,
    *(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)(v2.VInt + 36));
  this->Kind &= 0xFFFFFFF9;
}
