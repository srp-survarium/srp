Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData *t)
{
  Scaleform::GFx::AS3::Instances::fl::Object *v2; // eax
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v3; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *v4; // eax

  v2 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v2, t);
    v4 = result;
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData_vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::BitmapData::`vftable';
    v3->pImageResource.pObject = 0;
    v3->pImage.pObject = 0;
    v3->pDefImpl.pObject = 0;
    v3->Width = 0;
    v3->Height = 0;
    v3->Dirty = 0;
    v3->Transparent = 1;
    result->pV = v3;
  }
  else
  {
    v4 = result;
    result->pV = 0;
  }
  return v4;
}
