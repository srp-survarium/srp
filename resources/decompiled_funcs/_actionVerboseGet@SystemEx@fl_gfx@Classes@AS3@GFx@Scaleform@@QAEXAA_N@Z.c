void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::actionVerboseGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this,
        bool *result)
{
  *result = (*((_DWORD *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 4061) & 4) != 0;
}
