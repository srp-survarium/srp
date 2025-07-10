void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::Render::Filter *pObject; // eax
  char v5; // cl
  Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *v6; // ecx
  Scaleform::Render::Filter *v7; // eax
  const Scaleform::GFx::AS3::Value *v8; // edx
  bool inner; // [esp+39h] [ebp-4Fh]
  bool knock; // [esp+3Ah] [ebp-4Eh]
  Scaleform::GFx::AS3::CheckResult v11; // [esp+3Bh] [ebp-4Dh] BYREF
  unsigned int color; // [esp+3Ch] [ebp-4Ch] BYREF
  int qual; // [esp+40h] [ebp-48h] BYREF
  float v14; // [esp+44h] [ebp-44h]
  long double dist; // [esp+48h] [ebp-40h] BYREF
  long double angl; // [esp+50h] [ebp-38h] BYREF
  long double alpha; // [esp+58h] [ebp-30h] BYREF
  long double blurX; // [esp+60h] [ebp-28h] BYREF
  long double blurY; // [esp+68h] [ebp-20h] BYREF
  double stren; // [esp+70h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value result; // [esp+78h] [ebp-10h] BYREF

  dist = 4.0;
  angl = 45.0;
  alpha = 1.0;
  stren = 1.0;
  v14 = 0.0;
  color = 0;
  blurX = 4.0;
  qual = 1;
  blurY = 4.0;
  inner = 0;
  knock = 0;
  if ( (!argc || Scaleform::GFx::AS3::Value::Convert2Number(argv, &v11, &dist)->Result)
    && (argc < 2 || Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, &v11, &angl)->Result)
    && (argc < 3 || Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 2, &v11, &color)->Result)
    && (argc < 4 || Scaleform::GFx::AS3::Value::Convert2Number(argv + 3, &v11, &alpha)->Result)
    && (argc < 5 || Scaleform::GFx::AS3::Value::Convert2Number(argv + 4, &v11, &blurX)->Result)
    && (argc < 6 || Scaleform::GFx::AS3::Value::Convert2Number(argv + 5, &v11, &blurY)->Result)
    && (argc < 7 || Scaleform::GFx::AS3::Value::Convert2Number(argv + 6, &v11, &stren)->Result)
    && (argc < 8 || Scaleform::GFx::AS3::Value::Convert2Int32(argv + 7, &v11, &qual)->Result) )
  {
    if ( argc >= 7 )
      inner = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 6);
    if ( argc >= 8 )
      knock = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 7);
    result.Flags = 0;
    result.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::distanceSet(this, &result, dist);
    Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::angleSet(this, &result, angl);
    pObject = this->FilterData.pObject;
    v5 = *(&pObject[2].Frozen + 3);
    pObject = (Scaleform::Render::Filter *)((char *)pObject + 44);
    pObject->__vftable = (Scaleform::Render::Filter_vtbl *)color;
    HIBYTE(pObject->__vftable) = v5;
    Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::alphaSet(
      (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)this,
      &result,
      alpha);
    Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::blurXSet(
      (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)this,
      &result,
      blurX);
    Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::blurYSet(v6, &result, blurY);
    v7 = this->FilterData.pObject;
    v14 = stren;
    *(float *)&v7[2].Type = v14;
    Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter::qualitySet(
      (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)this,
      v8,
      qual);
    this->FilterData.pObject[1].__vftable = (Scaleform::Render::Filter_vtbl *)((int)this->FilterData.pObject[1].__vftable
                                                                             | (inner ? 0x20 : 0));
    this->FilterData.pObject[1].__vftable = (Scaleform::Render::Filter_vtbl *)((int)this->FilterData.pObject[1].__vftable
                                                                             | (knock ? 0x10 : 0));
    this->FilterData.pObject[1].__vftable = this->FilterData.pObject[1].__vftable;
    Scaleform::GFx::AS3::Value::~Value(&result);
  }
}
