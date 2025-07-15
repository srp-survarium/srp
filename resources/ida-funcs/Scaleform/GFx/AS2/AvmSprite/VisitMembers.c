void __thiscall Scaleform::GFx::AS2::AvmSprite::VisitMembers(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *pvisitor,
        unsigned int visitFlags,
        const Scaleform::GFx::AS2::ObjectInterface *__formal)
{
  Scaleform::GFx::DisplayList *p_pUserDataHolder; // ecx
  Scaleform::GFx::AS2::AvmSprite::VisitMembers::__l5::Visitor dispListVisitor; // [esp+Ch] [ebp-Ch] BYREF

  if ( (visitFlags & 2) != 0 )
  {
    p_pUserDataHolder = (Scaleform::GFx::DisplayList *)&this->pProto.pObject[2].pUserDataHolder;
    dispListVisitor.__vftable = (Scaleform::GFx::AS2::AvmSprite::VisitMembers::__l5::Visitor_vtbl *)&`Scaleform::GFx::AS2::AvmSprite::VisitMembers'::`5'::Visitor::`vftable';
    dispListVisitor.pVisitor = pvisitor;
    dispListVisitor.VisitFlags = visitFlags;
    Scaleform::GFx::DisplayList::VisitMembers(p_pUserDataHolder, &dispListVisitor);
  }
  Scaleform::GFx::AS2::AvmCharacter::VisitMembers(
    this,
    psc,
    pvisitor,
    visitFlags,
    this != (Scaleform::GFx::AS2::AvmSprite *)4 ? (const Scaleform::GFx::AS2::ObjectInterface *)this : 0);
}
