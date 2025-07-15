void __thiscall Scaleform::GFx::AS3::Instances::fl_net::SharedObject::send(
        Scaleform::GFx::AS3::Instances::fl_net::SharedObject *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method instance::SharedObject::send() is not implemented\n");
}
