void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::stopTouchDrag(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this,
        const Scaleform::GFx::AS3::Value *result,
        int touchPointID)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method Sprite::stopTouchDrag() - multitouch support is OFF is not implemented\n");
}
