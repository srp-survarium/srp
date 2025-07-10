void __thiscall Scaleform::GFx::AS2::GlobalContext::Init_::_4_::MemberVisitor::Visit(
        Scaleform::GFx::AS2::GlobalContext::Init::__l4::MemberVisitor *this,
        const Scaleform::GFx::ASString *name,
        const Scaleform::GFx::AS2::Value *val,
        unsigned __int8 flags)
{
  this->obj.pObject->SetMemberFlags(
    &this->obj.pObject->Scaleform::GFx::AS2::ObjectInterface,
    this->psc,
    name,
    flags | 1);
}
