void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter::clone(
        Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter> *result)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi
  Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *v4; // eax
  Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *v5; // eax
  Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *v6; // esi
  Scaleform::Render::Filter *v7; // eax
  int v8; // edi
  unsigned int RefCount; // ebp
  double v10; // st7
  bool v11; // cl
  bool v12; // dl
  double v13; // st6
  double v14; // st5
  Scaleform::Render::Filter *v15; // eax
  char v16; // bl
  Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *v17; // ecx
  unsigned int v18; // eax
  unsigned __int8 v19; // [esp+12h] [ebp-16h]
  float v20; // [esp+14h] [ebp-14h]
  float v21; // [esp+14h] [ebp-14h]
  float v22; // [esp+14h] [ebp-14h]
  Scaleform::Render::FilterType v23; // [esp+14h] [ebp-14h]
  float v24; // [esp+14h] [ebp-14h]
  float v25; // [esp+14h] [ebp-14h]
  Scaleform::Render::FilterType v26; // [esp+14h] [ebp-14h]
  Scaleform::GFx::AS3::Value tempResult; // [esp+18h] [ebp-10h] BYREF

  pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject;
  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)Scaleform::GFx::AS3::Traits::Alloc(pObject);
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter::GlowFilter(v4, pObject);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v7 = this->FilterData.pObject;
  v8 = *(_DWORD *)&v7[2].Frozen;
  RefCount = v7[1].RefCount;
  v20 = *(float *)&v7[1].Type * 0.05000000074505806;
  v19 = *(&v7[2].Frozen + 3);
  v10 = v20;
  v11 = ((int)v7[1].__vftable & 0x20) != 0;
  v21 = 0.05000000074505806 * *(float *)&v7[1].Frozen;
  v12 = ((int)v7[1].__vftable & 0x10) != 0;
  v13 = v21;
  v14 = *(float *)&v7[2].Type;
  tempResult.Flags = 0;
  tempResult.Bonus.pWeakProxy = 0;
  v15 = v6->FilterData.pObject;
  v16 = *(&v15[2].Frozen + 3);
  v15 = (Scaleform::Render::Filter *)((char *)v15 + 44);
  v15->__vftable = (Scaleform::Render::Filter_vtbl *)(v8 & 0xFFFFFF);
  HIBYTE(v15->__vftable) = v16;
  *(&v6->FilterData.pObject[2].Frozen + 3) = (int)((double)v19 / 255.0 * 255.0);
  v22 = v10;
  *(float *)&v23 = v22 * 20.0;
  v6->FilterData.pObject[1].Type = v23;
  v24 = v13;
  v25 = 20.0 * v24;
  *(float *)&v6->FilterData.pObject[1].Frozen = v25;
  *(float *)&v26 = v14;
  v6->FilterData.pObject[2].Type = v26;
  if ( RefCount >= 0xF )
    RefCount = 15;
  v6->FilterData.pObject[1].RefCount = RefCount;
  v6->FilterData.pObject[1].__vftable = (Scaleform::Render::Filter_vtbl *)((int)v6->FilterData.pObject[1].__vftable
                                                                         | (v11 ? 0x20 : 0));
  v6->FilterData.pObject[1].__vftable = (Scaleform::Render::Filter_vtbl *)((int)v6->FilterData.pObject[1].__vftable
                                                                         | (v12 ? 0x10 : 0));
  v17 = result->pObject;
  if ( v6 != result->pObject )
  {
    if ( v17 )
    {
      if ( ((unsigned __int8)v17 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *)((char *)v17 - 1);
      }
      else
      {
        v18 = v17->RefCount;
        if ( (v18 & 0x3FFFFF) != 0 )
        {
          v17->RefCount = v18 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
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
