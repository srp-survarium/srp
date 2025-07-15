void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixSet(
        Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl::Array *value)
{
  Scaleform::Render::Filter *pObject; // ebx
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // edi
  Scaleform::GFx::AS3::Value *v6; // eax
  unsigned int v7; // edx
  Scaleform::GFx::AS3::CheckResult v8; // [esp+13h] [ebp-Dh] BYREF
  float v9; // [esp+14h] [ebp-Ch]
  long double n; // [esp+18h] [ebp-8h] BYREF

  if ( value )
  {
    pObject = this->FilterData.pObject;
    v4 = 0;
    p_SA = &value->SA;
    if ( value->SA.Length )
    {
      do
      {
        v6 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(p_SA, v4);
        if ( !Scaleform::GFx::AS3::Value::Convert2Number(v6, &v8, &n)->Result )
          break;
        if ( v4 < 0x14 )
        {
          v7 = v4 / 5;
          v9 = n;
          if ( v4 % 5 == 4 )
            *((float *)&pObject[5].__vftable + v7) = v9 / 255.0;
          else
            *((float *)&pObject[v7 + 1].__vftable + v4 % 5) = v9;
        }
        ++v4;
      }
      while ( v4 < p_SA->Length );
    }
  }
}
