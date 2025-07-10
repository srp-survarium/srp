void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::clone(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter> *result)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edi
  Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *v4; // eax
  Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *v5; // eax
  Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *v6; // ebx
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::Render::BevelFilter *v8; // eax
  Scaleform::Render::BevelFilter *(__thiscall *GetBevelFilterData)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *); // edx
  int v10; // eax
  Scaleform::Render::BevelFilter *(__thiscall *v11)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *); // edx
  unsigned int v12; // edi
  Scaleform::Render::BevelFilter *(__thiscall *v13)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *); // eax
  int v14; // eax
  Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter_vtbl *v15; // edx
  Scaleform::Render::BevelFilter *(__thiscall *v16)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *); // eax
  double v17; // st7
  Scaleform::Render::BevelFilter *(__thiscall *v18)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *); // eax
  double v19; // st7
  Scaleform::Render::BevelFilter *(__thiscall *v20)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *); // eax
  double Strength; // st7
  Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter_vtbl *v22; // edx
  int Passes; // ecx
  Scaleform::Render::BevelFilter *(__thiscall *v24)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *); // eax
  int v25; // eax
  char v26; // cl
  double v27; // st7
  Scaleform::Render::BevelFilter *(__thiscall *v28)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *); // edx
  int v29; // eax
  char v30; // cl
  double v31; // st7
  Scaleform::Render::BevelFilter *(__thiscall *v32)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *); // edx
  Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter_vtbl *v33; // eax
  int v34; // eax
  Scaleform::Render::BevelFilter *(__thiscall *v35)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *); // edx
  int v36; // eax
  Scaleform::Render::BevelFilter *(__thiscall *v37)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *); // edx
  int v38; // eax
  int v39; // edi
  int v40; // eax
  Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *v41; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  float v44; // [esp+2Ch] [ebp-5Ch]
  int Alpha; // [esp+2Ch] [ebp-5Ch]
  int v46; // [esp+2Ch] [ebp-5Ch]
  float v47; // [esp+2Ch] [ebp-5Ch]
  float v48; // [esp+2Ch] [ebp-5Ch]
  bool knock; // [esp+33h] [ebp-55h]
  Scaleform::GFx::ASString type; // [esp+34h] [ebp-54h] BYREF
  long double dist; // [esp+38h] [ebp-50h]
  unsigned int shadowC; // [esp+40h] [ebp-48h]
  int qual; // [esp+44h] [ebp-44h]
  long double angl; // [esp+48h] [ebp-40h]
  double highA; // [esp+50h] [ebp-38h]
  double shadowA; // [esp+58h] [ebp-30h]
  double blurX; // [esp+60h] [ebp-28h]
  double blurY; // [esp+68h] [ebp-20h]
  double stren; // [esp+70h] [ebp-18h]
  Scaleform::GFx::AS3::Value tempResult; // [esp+78h] [ebp-10h] BYREF

  pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject;
  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)Scaleform::GFx::AS3::Traits::Alloc(pObject);
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::BevelFilter(v4, pObject);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  pStringManager = this->pTraits.pObject->pVM->StringManagerRef->pStringManager;
  type.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  v8 = this->GetBevelFilterData(this);
  GetBevelFilterData = this->GetBevelFilterData;
  v44 = v8->Distance * 0.05000000074505806;
  dist = v44;
  v10 = (int)GetBevelFilterData(this);
  v11 = this->GetBevelFilterData;
  angl = *(float *)(v10 + 56) * 180.0 / 3.141592653589793;
  v12 = (unsigned int)&vostok::memory::s_CRT_arena[5574199] & v11(this)->Params.Colors[1].Raw;
  Alpha = this->GetBevelFilterData(this)->Params.Colors[1].Channels.Alpha;
  v13 = this->GetBevelFilterData;
  highA = (double)Alpha / 255.0;
  v14 = (int)v13(this);
  v15 = this->__vftable;
  shadowC = (unsigned int)&vostok::memory::s_CRT_arena[5574199] & *(_DWORD *)(v14 + 44);
  v46 = v15->GetBevelFilterData(this)->Params.Colors[0].Channels.Alpha;
  v16 = this->GetBevelFilterData;
  shadowA = (double)v46 / 255.0;
  v17 = v16(this)->Params.BlurX * 0.05000000074505806;
  v18 = this->GetBevelFilterData;
  v47 = v17;
  blurX = v47;
  v19 = v18(this)->Params.BlurY * 0.05000000074505806;
  v20 = this->GetBevelFilterData;
  v48 = v19;
  blurY = v48;
  Strength = v20(this)->Params.Strength;
  v22 = this->__vftable;
  stren = Strength;
  Passes = v22->GetBevelFilterData(this)->Params.Passes;
  v24 = this->GetBevelFilterData;
  qual = Passes;
  if ( (v24(this)->Params.Mode & 0x20) != 0 )
    Scaleform::GFx::ASString::operator=(&type, "inner");
  else
    Scaleform::GFx::ASString::operator=(&type, "outer");
  knock = (this->GetBevelFilterData(this)->Params.Mode & 0x10) != 0;
  tempResult.Flags = 0;
  tempResult.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::distanceSet(v6, &tempResult, dist);
  Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::angleSet(v6, &tempResult, angl);
  v25 = (int)v6->GetBevelFilterData(v6);
  v26 = *(_BYTE *)(v25 + 51);
  v27 = highA * 255.0;
  v25 += 48;
  *(_DWORD *)v25 = v12;
  *(_BYTE *)(v25 + 3) = v26;
  v28 = v6->GetBevelFilterData;
  LODWORD(dist) = (int)v27;
  v28(v6)->Params.Colors[1].Channels.Alpha = (int)v27;
  v29 = (int)v6->GetBevelFilterData(v6);
  v30 = *(_BYTE *)(v29 + 47);
  v31 = shadowA * 255.0;
  v29 += 44;
  *(float *)v29 = *(float *)&shadowC;
  *(_BYTE *)(v29 + 3) = v30;
  v32 = v6->GetBevelFilterData;
  shadowC = (int)v31;
  v32(v6)->Params.Colors[0].Channels.Alpha = (int)v31;
  *(float *)&shadowC = blurX;
  v33 = v6->__vftable;
  *(float *)&shadowC = *(float *)&shadowC * 20.0;
  v34 = (int)v33->GetBevelFilterData(v6);
  *(float *)(v34 + 24) = *(float *)&shadowC;
  v35 = v6->GetBevelFilterData;
  *(float *)&shadowC = blurY;
  *(float *)&shadowC = *(float *)&shadowC * 20.0;
  v36 = (int)v35(v6);
  *(float *)(v36 + 28) = *(float *)&shadowC;
  v37 = v6->GetBevelFilterData;
  *(float *)&shadowC = stren;
  v38 = (int)v37(v6);
  *(float *)(v38 + 40) = *(float *)&shadowC;
  v39 = qual;
  if ( (unsigned int)qual >= 0xF )
    v39 = 15;
  v6->GetBevelFilterData(v6)->Params.Passes = v39;
  Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::typeSet(v6, &tempResult, &type);
  v40 = (int)v6->GetBevelFilterData(v6);
  *(_DWORD *)(v40 + 16) |= knock ? 0x10 : 0;
  v41 = result->pObject;
  if ( v6 != result->pObject )
  {
    if ( v41 )
    {
      if ( ((unsigned __int8)v41 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *)((char *)v41 - 1);
      }
      else
      {
        RefCount = v41->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v41->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v41);
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
  pNode = type.pNode;
  --type.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
