void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx::getTopmostLevel(
        Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *o)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  unsigned __int16 Flags; // ax

  *result = o
         && (pObject = o->pDispObj.pObject) != 0
         && (Flags = pObject->Scaleform::GFx::DisplayObjectBase::Flags, (Flags & 0x80u) != 0)
         && (Flags & 2) != 0;
}
