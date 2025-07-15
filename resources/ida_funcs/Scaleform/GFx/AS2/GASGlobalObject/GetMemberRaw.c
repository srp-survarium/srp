char __thiscall Scaleform::GFx::AS2::GASGlobalObject::GetMemberRaw(
        Scaleform::GFx::AS2::GASGlobalObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  unsigned __int8 Flags; // al
  bool v5; // bl

  if ( name->pNode != (Scaleform::GFx::ASStringNode *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[22].pMovieImpl )
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
  Flags = this->ResolveHandler.pLocalFrame->Callee.V.FunctionValue.Flags;
  if ( Flags )
  {
    v5 = Flags == 1;
    Scaleform::GFx::AS2::Value::DropRefs(val);
    val->V.BooleanValue = v5;
    val->T.Type = 2;
    return 1;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(val);
    val->T.Type = 0;
    return 0;
  }
}
