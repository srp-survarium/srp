void __thiscall Scaleform::GFx::AS2ValueObjectInterface::VisitMembers_::_2_::VisitorProxy::Visit(
        Scaleform::GFx::AS2ValueObjectInterface::VisitMembers::__l2::VisitorProxy *this,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        unsigned __int8 flags)
{
  Scaleform::GFx::AS2::Environment *pEnv; // edx
  Scaleform::GFx::Value v; // [esp+8h] [ebp-18h] BYREF

  pEnv = this->pEnv;
  v.pObjectInterface = 0;
  v.Type = VT_Undefined;
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this->pMovieRoot, pEnv, val, &v);
  this->pVisitor->Visit(this->pVisitor, name->pNode->pData, &v);
  if ( (v.Type & 0x40) != 0 )
    v.pObjectInterface->ObjectRelease(v.pObjectInterface, &v, (void *)v.mValue.IValue);
}
