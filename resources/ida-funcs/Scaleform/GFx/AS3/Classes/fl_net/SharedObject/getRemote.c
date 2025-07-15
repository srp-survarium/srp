void __thiscall Scaleform::GFx::AS3::Classes::fl_net::SharedObject::getRemote(
        Scaleform::GFx::AS3::Classes::fl_net::SharedObject *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject> *result,
        const Scaleform::GFx::ASString *name,
        const Scaleform::GFx::ASString *remotePath,
        const Scaleform::GFx::AS3::Value *persistence,
        bool secure)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method class_::SharedObject::getRemote() is not implemented\n");
}
