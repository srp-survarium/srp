void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::~Sprite(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::Graphics *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // ecx
  unsigned int v5; // eax

  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_display::Sprite_vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::Sprite::`vftable';
  pObject = this->pGraphics.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pGraphics.pObject = (Scaleform::GFx::AS3::Instances::fl_display::Graphics *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_display::Sprite_vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::`vftable';
  v4 = this->pContextMenu.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->pContextMenu.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v4 - 1);
      Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::~DisplayObject(this);
      return;
    }
    v5 = v4->RefCount;
    if ( (v5 & 0x3FFFFF) != 0 )
    {
      v4->RefCount = v5 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
    }
  }
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::~DisplayObject(this);
}
