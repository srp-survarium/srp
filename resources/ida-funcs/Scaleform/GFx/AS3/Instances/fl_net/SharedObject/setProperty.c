void __thiscall Scaleform::GFx::AS3::Instances::fl_net::SharedObject::setProperty(
        Scaleform::GFx::AS3::Instances::fl_net::SharedObject *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *propertyName,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method instance::SharedObject::setProperty() is not implemented\n");
}
