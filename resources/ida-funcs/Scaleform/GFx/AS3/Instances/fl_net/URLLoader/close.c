void __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::close(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method URLLoader::close() is not implemented\n");
}
