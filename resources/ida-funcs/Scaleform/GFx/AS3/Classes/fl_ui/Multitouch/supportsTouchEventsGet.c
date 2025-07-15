void __thiscall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::supportsTouchEventsGet(
        Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this,
        bool *result)
{
  *result = Scaleform::GFx::MovieImpl::GetMaxTouchPoints((Scaleform::GFx::MovieImpl *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM) != 0;
}
