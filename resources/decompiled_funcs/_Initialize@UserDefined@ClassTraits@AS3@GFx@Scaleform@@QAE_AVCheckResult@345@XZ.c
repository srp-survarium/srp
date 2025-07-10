Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::ClassTraits::UserDefined::Initialize(
        Scaleform::GFx::AS3::ClassTraits::UserDefined *this,
        Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *SuperClassTraits; // eax
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v4; // edi
  Scaleform::GFx::AS3::CheckResult *v5; // eax
  const Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // ebx
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v7; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // eax
  Scaleform::GFx::AS3::CheckResult v9; // [esp+Fh] [ebp-1h] BYREF

  SuperClassTraits = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)Scaleform::GFx::AS3::ClassTraits::UserDefined::GetSuperClassTraits(
                                                                                this->File.pObject,
                                                                                this->class_info);
  v4 = (Scaleform::GFx::AS3::ClassTraits::UserDefined *)SuperClassTraits;
  if ( this->pVM->HandleException )
  {
LABEL_2:
    v5 = result;
    result->Result = 0;
    return v5;
  }
  if ( !this->pParent.pObject )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pParent,
      SuperClassTraits);
  if ( this->ITraits.pObject )
  {
    v5 = result;
    result->Result = 1;
    return v5;
  }
  pObject = 0;
  if ( v4 )
  {
    if ( !v4->ITraits.pObject )
    {
      Scaleform::GFx::AS3::ClassTraits::UserDefined::Initialize(v4, &v9);
      if ( this->pVM->HandleException )
      {
        v5 = result;
        result->Result = 0;
        return v5;
      }
    }
    pObject = v4->ITraits.pObject;
  }
  v7 = (Scaleform::GFx::AS3::InstanceTraits::UserDefined *)this->pVM->MHeap->Alloc(this->pVM->MHeap, 116, 0);
  if ( v7 )
    Scaleform::GFx::AS3::InstanceTraits::UserDefined::UserDefined(v7, this->File.pObject, pObject, this->class_info);
  else
    v8.pV = 0;
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(this, v8);
  if ( this->pVM->HandleException )
    goto LABEL_2;
  Scaleform::GFx::AS3::ClassTraits::UserDefined::RegisterSlots(this, result);
  return result;
}
