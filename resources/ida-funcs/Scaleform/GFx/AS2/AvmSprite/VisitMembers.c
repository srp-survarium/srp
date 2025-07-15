void __thiscall Scaleform::GFx::AS2::AvmSprite::VisitMembers(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *pvisitor,
        unsigned int visitFlags,
        const Scaleform::GFx::AS2::ObjectInterface *__formal)
{
  Scaleform::GFx::DisplayList *p_pUserDataHolder; // ecx
  Scaleform::GFx::DisplayList::MemberVisitor pvisitora; // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *v8; // [esp+10h] [ebp-8h]
  unsigned int v9; // [esp+14h] [ebp-4h]

  if ( (visitFlags & 2) != 0 )
  {
    p_pUserDataHolder = (Scaleform::GFx::DisplayList *)&this->pProto.pObject[2].pUserDataHolder;
    pvisitora.__vftable = (Scaleform::GFx::DisplayList::MemberVisitor_vtbl *)&`Scaleform::GFx::AS2::AvmSprite::VisitMembers'::`5'::Visitor::`vftable';
    v8 = pvisitor;
    v9 = visitFlags;
    Scaleform::GFx::DisplayList::VisitMembers(p_pUserDataHolder, &pvisitora);
  }
  Scaleform::GFx::AS2::AvmCharacter::VisitMembers(
    this,
    psc,
    pvisitor,
    visitFlags,
    this != (Scaleform::GFx::AS2::AvmSprite *)4 ? (const Scaleform::GFx::AS2::ObjectInterface *)this : 0);
}
