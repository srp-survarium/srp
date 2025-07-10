Scaleform::Pickable<Scaleform::GFx::AS3::Instances::CheckTypeTF> *__thiscall Scaleform::GFx::AS3::Classes::Function::MakeCheckTypeInstance(
        Scaleform::GFx::AS3::Classes::Function *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::CheckTypeTF> *result,
        const Scaleform::GFx::AS3::Class *data_type,
        const Scaleform::GFx::AS3::ThunkInfo *thunk)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pNext; // edi
  Scaleform::GFx::AS3::Instances::FunctionBase *v6; // eax
  Scaleform::GFx::AS3::Instances::CheckTypeTF *v7; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::CheckTypeTF> *v8; // eax

  pObject = this->pTraits.pObject;
  pNext = (Scaleform::GFx::AS3::InstanceTraits::Traits *)pObject[1].pNext;
  v6 = (Scaleform::GFx::AS3::Instances::FunctionBase *)pObject->pVM->MHeap->Alloc(pObject->pVM->MHeap, 44u, 0);
  v7 = (Scaleform::GFx::AS3::Instances::CheckTypeTF *)v6;
  if ( v6 )
  {
    Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(v6, pNext);
    v8 = result;
    v7->Thunk = thunk;
    v7->__vftable = (Scaleform::GFx::AS3::Instances::CheckTypeTF_vtbl *)&Scaleform::GFx::AS3::Instances::CheckTypeTF::`vftable';
    v7->DataTypeClass = data_type;
    result->pV = v7;
  }
  else
  {
    v8 = result;
    result->pV = 0;
  }
  return v8;
}
