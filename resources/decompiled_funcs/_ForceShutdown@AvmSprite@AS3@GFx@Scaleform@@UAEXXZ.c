void __thiscall Scaleform::GFx::AS3::AvmSprite::ForceShutdown(Scaleform::GFx::AS3::AvmSprite *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // ecx

  if ( this->pAS3RawPtr )
  {
    pAS3RawPtr = this->pAS3RawPtr;
  }
  else
  {
    if ( !this->pAS3CollectiblePtr.pObject )
      return;
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  }
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::SetLoaderInfo(pAS3RawPtr, 0);
}
