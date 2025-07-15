void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::clone(
        Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter> *result)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi
  Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *v4; // eax
  Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *v5; // eax
  Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *v6; // esi
  Scaleform::Render::Filter *v7; // eax
  double v8; // st5
  unsigned int RefCount; // eax
  double v10; // st7
  double v11; // st6
  double v12; // st7
  Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *v13; // ecx
  unsigned int v14; // eax
  float v15; // [esp+8h] [ebp-14h]
  float v16; // [esp+8h] [ebp-14h]
  float v17; // [esp+8h] [ebp-14h]
  Scaleform::Render::FilterType v18; // [esp+8h] [ebp-14h]
  float v19; // [esp+8h] [ebp-14h]
  float v20; // [esp+8h] [ebp-14h]
  Scaleform::GFx::AS3::Value tempResult; // [esp+Ch] [ebp-10h] BYREF

  pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject;
  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *)Scaleform::GFx::AS3::Traits::Alloc(pObject);
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::BlurFilter(v4, pObject);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v7 = this->FilterData.pObject;
  v15 = *(float *)&v7[1].Type * 0.05000000074505806;
  v8 = *(float *)&v7[1].Frozen;
  RefCount = v7[1].RefCount;
  tempResult.Flags = 0;
  v10 = v15;
  tempResult.Bonus.pWeakProxy = 0;
  v16 = 0.05000000074505806 * v8;
  v11 = v10;
  v12 = v16;
  v17 = v11;
  *(float *)&v18 = v17 * 20.0;
  v6->FilterData.pObject[1].Type = v18;
  v19 = v12;
  v20 = 20.0 * v19;
  *(float *)&v6->FilterData.pObject[1].Frozen = v20;
  if ( RefCount >= 0xF )
    RefCount = 15;
  v6->FilterData.pObject[1].RefCount = RefCount;
  v13 = result->pObject;
  if ( v6 != result->pObject )
  {
    if ( v13 )
    {
      if ( ((unsigned __int8)v13 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *)((char *)v13 - 1);
      }
      else
      {
        v14 = v13->RefCount;
        if ( (v14 & 0x3FFFFF) != 0 )
        {
          v13->RefCount = v14 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
        }
      }
    }
    result->pObject = v6;
  }
  if ( (tempResult.Flags & 0x1F) > 9 )
  {
    if ( (tempResult.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&tempResult);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&tempResult);
  }
}
