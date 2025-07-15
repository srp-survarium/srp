void __thiscall Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::availableGet(
        Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *this,
        bool *result)
{
  *result = *((_DWORD *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 120) != 0;
}
