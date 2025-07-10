Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::MovieClip> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl_display::MovieClip::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::MovieClip> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::MovieClip *t)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v2; // eax
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip *v3; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::MovieClip> *v4; // eax

  v2 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::DisplayObject(v2, t);
    v3->pContextMenu.pObject = 0;
    v3->pGraphics.pObject = 0;
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip_vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::MovieClip::`vftable';
    v3->mFrameScript.DescrCnt = 0;
    v4 = result;
    v3->mFrameScript.pData = 0;
    v3->mFrameScript.FrameCnt = 0;
    result->pV = v3;
  }
  else
  {
    v4 = result;
    result->pV = 0;
  }
  return v4;
}
