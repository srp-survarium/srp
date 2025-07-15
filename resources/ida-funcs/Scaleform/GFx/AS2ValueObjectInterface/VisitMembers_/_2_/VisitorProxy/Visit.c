void __thiscall Scaleform::GFx::AS2ValueObjectInterface::VisitMembers_::_2_::VisitorProxy::Visit(
        Scaleform::GFx::AS2ValueObjectInterface::VisitMembers::__l2::VisitorProxy *this,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        unsigned __int8 flags)
{
  Scaleform::GFx::AS2::Environment *pEnv; // edx
  Scaleform::GFx::Value pdestVal; // [esp+8h] [ebp-18h] BYREF

  pEnv = this->pEnv;
  pdestVal.pObjectInterface = 0;
  pdestVal.Type = VT_Undefined;
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this->pMovieRoot, pEnv, val, &pdestVal);
  this->pVisitor->Visit(this->pVisitor, name->pNode->pData, &pdestVal);
  if ( (pdestVal.Type & 0x40) != 0 )
    pdestVal.pObjectInterface->ObjectRelease(pdestVal.pObjectInterface, &pdestVal, (void *)pdestVal.mValue.IValue);
}
