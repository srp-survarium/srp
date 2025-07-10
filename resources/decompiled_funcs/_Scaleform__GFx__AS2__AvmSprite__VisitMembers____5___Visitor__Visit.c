void __thiscall Scaleform::GFx::AS2::AvmSprite::VisitMembers_::_5_::Visitor::Visit(
        Scaleform::GFx::AS2::AvmSprite::VisitMembers::__l5::Visitor *this,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::InteractiveObject *pch)
{
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::AS2::Value v5; // [esp+Ch] [ebp-10h] BYREF

  v5.T.Type = 7;
  if ( pch )
  {
    pObject = pch->pNameHandle.pObject;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pch);
    v5.NV.Int32Value = (int)pObject;
    if ( pObject )
      ++pObject->RefCount;
  }
  else
  {
    v5.NV.Int32Value = 0;
  }
  this->pVisitor->Visit(this->pVisitor, name, &v5, this->VisitFlags);
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
}
