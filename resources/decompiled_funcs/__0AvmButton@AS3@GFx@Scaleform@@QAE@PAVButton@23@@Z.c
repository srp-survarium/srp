void __thiscall Scaleform::GFx::AS3::AvmButton::AvmButton(
        Scaleform::GFx::AS3::AvmButton *this,
        Scaleform::GFx::Button *pbutton)
{
  Scaleform::GFx::AS3::AvmDisplayObj::AvmDisplayObj(this, pbutton);
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmInteractiveObjBase_vtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable';
  this->MouseOverCnt = 0;
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Flags = 0;
  pbutton->TabIndex = -1;
  this->Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmButtonBase_vtbl *)&Scaleform::GFx::AvmButtonBase::`vftable';
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS3::AvmButton_vtbl *)&Scaleform::GFx::AS3::AvmButton::`vftable'{for `Scaleform::GFx::AS3::AvmDisplayObj'};
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmInteractiveObjBase_vtbl *)&Scaleform::GFx::AS3::AvmButton::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  this->Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmButtonBase_vtbl *)&Scaleform::GFx::AS3::AvmButton::`vftable';
  pbutton->Scaleform::GFx::InteractiveObject::Flags |= 0x60u;
}
