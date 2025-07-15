void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::clone(
        Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter> *result)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi
  Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *v4; // eax
  Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *v5; // eax
  Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *v6; // esi
  Scaleform::GFx::AS3::Instances::fl::Array *v7; // ebx
  Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *v8; // ecx
  unsigned int RefCount; // eax
  unsigned int v10; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> matrix; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value tempResult; // [esp+10h] [ebp-10h] BYREF

  pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject;
  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *)Scaleform::GFx::AS3::Traits::Alloc(pObject);
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::ColorMatrixFilter(v4, pObject);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  matrix.pObject = 0;
  tempResult.Flags = 0;
  tempResult.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixGet(this, &matrix);
  v7 = matrix.pObject;
  Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixSet(v6, &tempResult, matrix.pObject);
  v8 = result->pObject;
  if ( v6 != result->pObject )
  {
    if ( v8 )
    {
      if ( ((unsigned __int8)v8 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *)((char *)v8 - 1);
      }
      else
      {
        RefCount = v8->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v8->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
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
  if ( v7 && ((unsigned __int8)v7 & 1) == 0 )
  {
    v10 = v7->RefCount;
    if ( (v10 & 0x3FFFFF) != 0 )
    {
      v7->RefCount = v10 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
    }
  }
}
