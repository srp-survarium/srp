void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx::setHitTestDisable(
        Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *o,
        bool f)
{
  Scaleform::GFx::DisplayObject *pObject; // eax

  if ( o )
  {
    pObject = o->pDispObj.pObject;
    if ( pObject )
    {
      if ( SLOBYTE(pObject->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
      {
        if ( f )
          pObject[1].Id.Id |= 0x800u;
        else
          pObject[1].Id.Id &= ~0x800u;
      }
    }
  }
}
