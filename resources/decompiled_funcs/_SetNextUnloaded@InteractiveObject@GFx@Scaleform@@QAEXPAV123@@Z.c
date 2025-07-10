void __thiscall Scaleform::GFx::InteractiveObject::SetNextUnloaded(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::InteractiveObject *punlObj)
{
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x10u;
  this->pPlayNextOpt = punlObj;
}
