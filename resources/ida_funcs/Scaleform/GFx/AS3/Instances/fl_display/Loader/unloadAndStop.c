void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Loader::unloadAndStop(
        Scaleform::GFx::AS3::Instances::fl_display::Loader *this,
        const Scaleform::GFx::AS3::Value *result,
        bool gc)
{
  Scaleform::GFx::AS3::MovieRoot::UnloadMovie(
    (Scaleform::GFx::AS3::MovieRoot *)this->pTraits.pObject->pVM[1].__vftable,
    this,
    1,
    gc);
}
