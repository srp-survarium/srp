void __thiscall Scaleform::GFx::AS3::Instances::fl_net::SharedObject::connect(
        Scaleform::GFx::AS3::Instances::fl_net::SharedObject *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_net::NetConnection *myConnection,
        const Scaleform::GFx::ASString *params)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method instance::SharedObject::connect() is not implemented\n");
}
