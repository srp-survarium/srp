void __thiscall Scaleform::GFx::AS2::GAS_GlobalASSetPropFlags_::_27_::MemberVisitor::Visit(
        Scaleform::GFx::AS2::GAS_GlobalASSetPropFlags::__l27::MemberVisitor *this,
        const Scaleform::GFx::ASString *name,
        const Scaleform::GFx::AS2::Value *__formal,
        unsigned __int8 flags)
{
  this->obj->SetMemberFlags(this->obj, this->pSC, name, this->SetTrue | flags & ~this->SetFalse);
}
