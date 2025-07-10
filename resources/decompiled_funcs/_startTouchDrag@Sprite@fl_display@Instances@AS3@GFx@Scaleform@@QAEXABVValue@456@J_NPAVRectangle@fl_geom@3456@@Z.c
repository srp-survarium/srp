void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::startTouchDrag(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this,
        const Scaleform::GFx::AS3::Value *result,
        int touchPointID,
        bool lockCenter,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *bounds)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method Sprite::startTouchDrag() - multitouch support is OFF is not implemented\n");
}
