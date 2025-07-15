Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *__thiscall Scaleform::GFx::AS3::Classes::Function::MakeThunkFunction(
        Scaleform::GFx::AS3::Classes::Function *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *result,
        const Scaleform::GFx::AS3::ThunkInfo *thunk)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pNext; // edi
  Scaleform::GFx::AS3::Instances::FunctionBase *v4; // eax
  Scaleform::GFx::AS3::Instances::ThunkFunction *v5; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *v6; // eax

  pNext = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject[1].pNext;
  v4 = (Scaleform::GFx::AS3::Instances::FunctionBase *)Scaleform::GFx::AS3::Traits::Alloc(pNext);
  v5 = (Scaleform::GFx::AS3::Instances::ThunkFunction *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(v4, pNext);
    v6 = result;
    v5->__vftable = (Scaleform::GFx::AS3::Instances::ThunkFunction_vtbl *)&Scaleform::GFx::AS3::Instances::ThunkFunction::`vftable';
    v5->Thunk = thunk;
    result->pV = v5;
  }
  else
  {
    v6 = result;
    result->pV = 0;
  }
  return v6;
}
