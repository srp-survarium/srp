void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::clone(
        Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter> *result)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi
  Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *v4; // eax
  Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *v5; // eax
  Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *v6; // esi
  Scaleform::Render::Filter *v7; // eax
  Scaleform::Render::Filter_vtbl *v8; // ecx
  unsigned int v9; // edi
  bool v10; // bl
  double v11; // st6
  Scaleform::Render::Filter *v12; // eax
  char v13; // cl
  int v14; // eax
  Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *v15; // ecx
  unsigned int RefCount; // eax
  unsigned __int8 v17; // [esp+18h] [ebp-38h]
  bool knock; // [esp+1Ah] [ebp-36h]
  bool hide; // [esp+1Bh] [ebp-35h]
  float qual; // [esp+1Ch] [ebp-34h]
  float quala; // [esp+1Ch] [ebp-34h]
  unsigned int qualb; // [esp+1Ch] [ebp-34h]
  float v23; // [esp+20h] [ebp-30h]
  Scaleform::Render::FilterType Type; // [esp+24h] [ebp-2Ch]
  float v25; // [esp+24h] [ebp-2Ch]
  Scaleform::Render::FilterType v26; // [esp+24h] [ebp-2Ch]
  float v27; // [esp+24h] [ebp-2Ch]
  float v28; // [esp+24h] [ebp-2Ch]
  Scaleform::Render::FilterType v29; // [esp+24h] [ebp-2Ch]
  double blurX; // [esp+28h] [ebp-28h]
  double stren; // [esp+38h] [ebp-18h]
  Scaleform::GFx::AS3::Value tempResult; // [esp+40h] [ebp-10h] BYREF

  pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject;
  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)Scaleform::GFx::AS3::Traits::Alloc(pObject);
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::DropShadowFilter(v4, pObject);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v7 = this->FilterData.pObject;
  Type = v7[3].Type;
  v17 = *(&v7[2].Frozen + 3);
  v8 = v7[1].__vftable;
  qual = *(float *)&v7[1].Type * 0.05000000074505806;
  v9 = (unsigned int)&vostok::memory::s_CRT_arena[5574199] & *(_DWORD *)&v7[2].Frozen;
  blurX = qual;
  v10 = ((unsigned __int8)v8 & 0x20) != 0;
  quala = *(float *)&v7[1].Frozen * 0.05000000074505806;
  v11 = quala;
  qualb = v7[1].RefCount;
  stren = *(float *)&v7[2].Type;
  knock = ((unsigned __int8)v8 & 0x10) != 0;
  v23 = 0.05000000074505806 * *(float *)&v7[3].RefCount;
  hide = ((unsigned __int8)v8 & 0x40) != 0;
  tempResult.Flags = 0;
  tempResult.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::distanceSet(v6, &tempResult, v23);
  Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::angleSet(
    v6,
    &tempResult,
    *(float *)&Type * 180.0 / 3.141592653589793);
  v12 = v6->FilterData.pObject;
  v13 = *(&v12[2].Frozen + 3);
  v12 = (Scaleform::Render::Filter *)((char *)v12 + 44);
  v12->__vftable = (Scaleform::Render::Filter_vtbl *)v9;
  HIBYTE(v12->__vftable) = v13;
  *(&v6->FilterData.pObject[2].Frozen + 3) = (int)((double)v17 / 255.0 * 255.0);
  v25 = blurX;
  *(float *)&v26 = v25 * 20.0;
  v6->FilterData.pObject[1].Type = v26;
  v14 = qualb;
  v27 = v11;
  v28 = 20.0 * v27;
  *(float *)&v6->FilterData.pObject[1].Frozen = v28;
  *(float *)&v29 = stren;
  v6->FilterData.pObject[2].Type = v29;
  if ( qualb >= 0xF )
    v14 = 15;
  v6->FilterData.pObject[1].RefCount = v14;
  v6->FilterData.pObject[1].__vftable = (Scaleform::Render::Filter_vtbl *)((int)v6->FilterData.pObject[1].__vftable
                                                                         | (v10 ? 0x20 : 0));
  v6->FilterData.pObject[1].__vftable = (Scaleform::Render::Filter_vtbl *)((int)v6->FilterData.pObject[1].__vftable
                                                                         | (knock ? 0x10 : 0));
  v6->FilterData.pObject[1].__vftable = (Scaleform::Render::Filter_vtbl *)((int)v6->FilterData.pObject[1].__vftable
                                                                         | (hide ? 0x40 : 0));
  v15 = result->pObject;
  if ( v6 != result->pObject )
  {
    if ( v15 )
    {
      if ( ((unsigned __int8)v15 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *)((char *)v15 - 1);
      }
      else
      {
        RefCount = v15->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v15->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v15);
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
