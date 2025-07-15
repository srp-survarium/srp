void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx::getHitTestDisable(
        Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *o)
{
  Scaleform::GFx::DisplayObject *pObject; // eax

  *result = o
         && (pObject = o->pDispObj.pObject) != 0
         && SLOBYTE(pObject->Scaleform::GFx::DisplayObjectBase::Flags) < 0
         && (pObject[1].Id.Id & 0x800) != 0;
}
