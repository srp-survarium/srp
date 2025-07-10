void __thiscall Scaleform::GFx::AS2::MovieClipObject::Set__proto___::_5_::MemberVisitor::Visit(
        Scaleform::GFx::AS2::MovieClipObject::Set__proto__::__l5::MemberVisitor *this,
        const Scaleform::GFx::ASString *name,
        const Scaleform::GFx::AS2::Value *val,
        unsigned __int8 flags)
{
  if ( (unsigned __int16)Scaleform::GFx::AS2::MovieClipObject::GetButtonEventNameMask(this->pStringContext, name) )
    this->obj.pObject->HasButtonHandlers = 1;
}
