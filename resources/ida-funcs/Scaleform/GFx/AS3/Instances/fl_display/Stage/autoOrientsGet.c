void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::autoOrientsGet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        bool *result)
{
  *result = (*((_DWORD *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 4061) & 0x4000) != 0;
}
