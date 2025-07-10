void __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLRequest::userAgentSet(
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method URLRequest::userAgentSet() is not implemented\n");
}
