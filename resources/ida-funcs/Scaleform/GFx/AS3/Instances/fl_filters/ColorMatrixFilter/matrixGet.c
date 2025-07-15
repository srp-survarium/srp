void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixGet(
        Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // ebx
  Scaleform::Render::Filter *pObject; // ebp
  unsigned int i; // esi
  double v6; // st7
  unsigned int v7; // edx
  long double v8; // st7
  unsigned int v9; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v10; // ecx
  unsigned int RefCount; // eax
  unsigned int v12; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> asArray; // [esp+10h] [ebp-18h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v14; // [esp+14h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+18h] [ebp-10h] BYREF

  pV = Scaleform::GFx::AS3::VM::MakeArray(this->pTraits.pObject->pVM, &v14)->pV;
  Scaleform::GFx::AS3::Impl::SparseArray::Resize(&pV->SA, 0x14u);
  pObject = this->FilterData.pObject;
  for ( i = 0; i < 0x14; ++i )
  {
    v6 = 0.0;
    v7 = i / 5;
    v.Bonus.pWeakProxy = 0;
    if ( i % 5 || !i )
    {
      v9 = i % 5 + 4 * v7;
      if ( v9 < 0x14 )
        v6 = *((float *)&pObject[1].__vftable + v9);
      *(float *)&asArray.pObject = v6;
      v8 = *(float *)&asArray.pObject;
    }
    else
    {
      if ( v7 + 16 < 0x14 )
        v6 = *((float *)&pObject[5].__vftable + v7);
      *(float *)&asArray.pObject = v6;
      v8 = *(float *)&asArray.pObject;
    }
    v.value.VNumber = v8;
    v.Flags = 4;
    Scaleform::GFx::AS3::Impl::SparseArray::Set(&pV->SA, i, &v);
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
  if ( &asArray != result )
  {
    if ( pV )
      pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
    v10 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v10 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v10 - 1);
      }
      else
      {
        RefCount = v10->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v10->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
        }
      }
    }
    result->pObject = pV;
  }
  if ( pV && ((unsigned __int8)pV & 1) == 0 )
  {
    v12 = pV->RefCount;
    if ( (v12 & 0x3FFFFF) != 0 )
    {
      pV->RefCount = v12 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
    }
  }
}
