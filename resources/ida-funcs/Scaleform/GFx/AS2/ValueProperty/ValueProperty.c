void __thiscall Scaleform::GFx::AS2::ValueProperty::ValueProperty(
        Scaleform::GFx::AS2::ValueProperty *this,
        Scaleform::GFx::AS2::ASRefCountCollector *pCC,
        const Scaleform::GFx::AS2::FunctionRef *getterMethod,
        const Scaleform::GFx::AS2::FunctionRef *setterMethod)
{
  Scaleform::GFx::AS2::FunctionRef *p_GetterMethod; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  Scaleform::GFx::AS2::FunctionObject *v8; // eax
  Scaleform::GFx::AS2::LocalFrame *v9; // eax

  this->pRCC = pCC;
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AS2::ValueProperty_vtbl *)&Scaleform::GFx::AS2::ValueProperty::`vftable';
  p_GetterMethod = &this->GetterMethod;
  p_GetterMethod->Flags = 0;
  Function = getterMethod->Function;
  p_GetterMethod->Function = getterMethod->Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  p_GetterMethod->pLocalFrame = 0;
  pLocalFrame = getterMethod->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(p_GetterMethod, pLocalFrame, getterMethod->Flags & 1);
  this->SetterMethod.Flags = 0;
  v8 = setterMethod->Function;
  this->SetterMethod.Function = setterMethod->Function;
  if ( v8 )
    v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
  this->SetterMethod.pLocalFrame = 0;
  v9 = setterMethod->pLocalFrame;
  if ( v9 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&this->SetterMethod, v9, setterMethod->Flags & 1);
}
