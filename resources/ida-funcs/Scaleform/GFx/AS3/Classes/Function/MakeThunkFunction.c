Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *__thiscall Scaleform::GFx::AS3::Classes::Function::MakeThunkFunction(
        Scaleform::GFx::AS3::Classes::Function *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *result,
        const Scaleform::GFx::AS3::ThunkInfo *thunk,
        const Scaleform::GFx::AS3::Traits *ot)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pNext; // edi
  Scaleform::GFx::AS3::Instances::FunctionBase *v5; // eax
  Scaleform::GFx::AS3::Instances::ThunkFunction *v6; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *v7; // eax

  pNext = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject[1].pNext;
  v5 = (Scaleform::GFx::AS3::Instances::FunctionBase *)Scaleform::GFx::AS3::Traits::Alloc(pNext);
  v6 = (Scaleform::GFx::AS3::Instances::ThunkFunction *)v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(v5, pNext);
    v6->__vftable = (Scaleform::GFx::AS3::Instances::ThunkFunction_vtbl *)&Scaleform::GFx::AS3::Instances::ThunkFunction::`vftable';
    v6->Thunk = thunk;
    v6->OriginationTraits.pObject = ot;
    if ( ot )
      ot->RefCount = (ot->RefCount + 1) & 0x8FBFFFFF;
    v7 = result;
    result->pV = v6;
  }
  else
  {
    v7 = result;
    result->pV = 0;
  }
  return v7;
}
