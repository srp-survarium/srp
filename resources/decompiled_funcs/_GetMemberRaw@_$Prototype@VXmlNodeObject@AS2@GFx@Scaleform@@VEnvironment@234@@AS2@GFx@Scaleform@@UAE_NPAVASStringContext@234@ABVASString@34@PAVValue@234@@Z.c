char __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>::GetMemberRaw(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  bool v4; // bl
  Scaleform::GFx::ASStringNodeHolder *v6; // esi
  bool v7; // zf
  bool v8; // bl
  Scaleform::GFx::ASStringNodeHolder *v9; // esi
  bool v10; // zf
  bool namea; // [esp+1Ch] [ebp+8h]

  v4 = psc->SWFVersion > 6u;
  v6 = &Scaleform::GFx::AS2::GlobalContext::GetStringManager(psc->pContext)->Builtins[80];
  if ( v4 )
  {
    v7 = v6->pNode == name->pNode;
  }
  else
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v7 = v6->pNode->pLower == name->pNode->pLower;
  }
  namea = v7;
  if ( v7 )
    return Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor(
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->pWatchpoints,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  v8 = psc->SWFVersion > 6u;
  v9 = &Scaleform::GFx::AS2::GlobalContext::GetStringManager(psc->pContext)->Builtins[79];
  if ( v8 )
  {
    v10 = v9->pNode == name->pNode;
  }
  else
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v10 = v9->pNode->pLower == name->pNode->pLower;
  }
  if ( v10 )
    return Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor(
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->pWatchpoints,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  else
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
}
