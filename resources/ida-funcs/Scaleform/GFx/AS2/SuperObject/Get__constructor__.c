Scaleform::GFx::AS2::FunctionRef *__thiscall Scaleform::GFx::AS2::SuperObject::Get__constructor__(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::FunctionObject *v3; // eax
  Scaleform::GFx::AS2::Object *pObject; // eax

  result->Flags = 0;
  v3 = *(Scaleform::GFx::AS2::FunctionObject **)&this->ArePropertiesSet;
  result->Function = v3;
  if ( v3 )
    v3->RefCount = (v3->RefCount + 1) & 0x8FFFFFFF;
  result->pLocalFrame = 0;
  pObject = this->SuperProto.pObject;
  if ( pObject )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      result,
      (Scaleform::GFx::AS2::LocalFrame *)pObject,
      (int)this->SavedProto.pObject & 1);
  return result;
}
