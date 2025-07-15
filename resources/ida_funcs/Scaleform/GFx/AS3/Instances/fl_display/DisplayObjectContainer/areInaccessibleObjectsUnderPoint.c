void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::areInaccessibleObjectsUnderPoint(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *point)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(
    UI,
    Output_Warning,
    "The method DisplayObjectContainer::areInaccessibleObjectsUnderPoint() is not implemented\n");
}
