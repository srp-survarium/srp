void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Loader::close(
        Scaleform::GFx::AS3::Instances::fl_display::Loader *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::MovieRoot::UnloadMovie(
    (Scaleform::GFx::AS3::MovieRoot *)this->pTraits.pObject->pVM[1].__vftable,
    this,
    0,
    0);
}
