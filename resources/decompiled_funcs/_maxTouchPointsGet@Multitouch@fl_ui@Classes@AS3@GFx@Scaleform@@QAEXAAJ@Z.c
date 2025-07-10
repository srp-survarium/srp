void __thiscall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::maxTouchPointsGet(
        Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this,
        int *result)
{
  *result = Scaleform::GFx::MovieImpl::GetMaxTouchPoints((Scaleform::GFx::MovieImpl *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM);
}
