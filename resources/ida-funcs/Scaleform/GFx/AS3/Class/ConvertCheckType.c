Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::Class::ConvertCheckType(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::AS3::Value *v,
        const Scaleform::GFx::AS3::Traits *ot)
{
  const Scaleform::GFx::AS3::ThunkInfo *VThunk; // ebx
  Scaleform::GFx::AS3::Classes::Function **pObject; // esi
  Scaleform::GFx::AS3::Instances::CheckTypeTF *pV; // eax

  VThunk = v->value.VS._1.VThunk;
  pObject = (Scaleform::GFx::AS3::Classes::Function **)this->pTraits.pObject->pVM->TraitsFunction.pObject->ITraits.pObject;
  if ( !pObject[17] )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::Function **))(*pObject)[1].RefCount)(pObject);
  pV = Scaleform::GFx::AS3::Classes::Function::MakeCheckTypeInstance(
         pObject[17],
         (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::CheckTypeTF> *)&v,
         this,
         VThunk,
         ot)->pV;
  result->Flags = 0;
  result->Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Value::PickUnsafe(result, pV);
  return result;
}
