void __thiscall Scaleform::GFx::AS3::AvmTextField::AvmTextField(
        Scaleform::GFx::AS3::AvmTextField *this,
        Scaleform::GFx::TextField *ptf)
{
  Scaleform::GFx::AS3::AvmDisplayObj::AvmDisplayObj(this, ptf);
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmInteractiveObjBase_vtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable';
  this->MouseOverCnt = 0;
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Flags = 0;
  ptf->TabIndex = -1;
  this->Scaleform::GFx::AvmTextFieldBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmTextFieldBase_vtbl *)&Scaleform::GFx::AvmTextFieldBase::`vftable';
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS3::AvmTextField_vtbl *)&Scaleform::GFx::AS3::AvmTextField::`vftable'{for `Scaleform::GFx::AS3::AvmDisplayObj'};
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmInteractiveObjBase_vtbl *)&Scaleform::GFx::AS3::AvmTextField::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  this->Scaleform::GFx::AvmTextFieldBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmTextFieldBase_vtbl *)&Scaleform::GFx::AS3::AvmTextField::`vftable';
  ptf->Flags |= 2u;
  Scaleform::GFx::TextField::SetSelection(ptf, 0, 0);
}
