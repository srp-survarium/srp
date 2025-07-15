void __thiscall Scaleform::GFx::AMP::MessageAppControl::MessageAppControl(
        Scaleform::GFx::AMP::MessageAppControl *this,
        unsigned int flags)
{
  this->__vftable = (Scaleform::GFx::AMP::MessageAppControl_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Version = 33;
  this->GFxVersion = 4;
  this->__vftable = (Scaleform::GFx::AMP::MessageAppControl_vtbl *)&Scaleform::GFx::AMP::MessageAppControl::`vftable';
  this->OptionBits = flags;
  Scaleform::StringLH::StringLH(&this->LoadMovieFile);
  this->ProfileLevel = -1;
}
