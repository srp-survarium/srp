void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  bool *p_Frozen; // eax
  char v5; // cl
  Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *v6; // ecx
  Scaleform::Render::Filter *pObject; // eax
  const Scaleform::GFx::AS3::Value *v8; // edx
  bool inner; // [esp+49h] [ebp-3Fh]
  bool knock; // [esp+4Ah] [ebp-3Eh]
  Scaleform::GFx::AS3::CheckResult v11; // [esp+4Bh] [ebp-3Dh] BYREF
  unsigned int color; // [esp+4Ch] [ebp-3Ch] BYREF
  int qual; // [esp+50h] [ebp-38h] BYREF
  float v14; // [esp+54h] [ebp-34h]
  long double alpha; // [esp+58h] [ebp-30h] BYREF
  long double blurX; // [esp+60h] [ebp-28h] BYREF
  long double blurY; // [esp+68h] [ebp-20h] BYREF
  double stren; // [esp+70h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value result; // [esp+78h] [ebp-10h] BYREF

  alpha = 1.0;
  blurX = 6.0;
  blurY = 6.0;
  stren = 2.0;
  v14 = 0.0;
  color = (unsigned int)&vostok::memory::s_CRT_arena[5508664];
  qual = 1;
  inner = 0;
  knock = 0;
  if ( (!argc || Scaleform::GFx::AS3::Value::Convert2UInt32(argv, &v11, &color)->Result)
    && (argc < 2 || Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, &v11, &alpha)->Result)
    && (argc < 3 || Scaleform::GFx::AS3::Value::Convert2Number(argv + 2, &v11, &blurX)->Result)
    && (argc < 4 || Scaleform::GFx::AS3::Value::Convert2Number(argv + 3, &v11, &blurY)->Result)
    && (argc < 5 || Scaleform::GFx::AS3::Value::Convert2Number(argv + 4, &v11, &stren)->Result)
    && (argc < 6 || Scaleform::GFx::AS3::Value::Convert2Int32(argv + 5, &v11, &qual)->Result) )
  {
    if ( argc >= 7 )
      inner = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 6);
    if ( argc >= 8 )
      knock = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 7);
    p_Frozen = &this->FilterData.pObject[2].Frozen;
    result.Flags = 0;
    result.Bonus.pWeakProxy = 0;
    v5 = p_Frozen[3];
    *(_DWORD *)p_Frozen = color;
    p_Frozen[3] = v5;
    Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::alphaSet(this, &result, alpha);
    Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::blurXSet(this, &result, blurX);
    Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::blurYSet(v6, &result, blurY);
    pObject = this->FilterData.pObject;
    v14 = stren;
    *(float *)&pObject[2].Type = v14;
    Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter::qualitySet(this, v8, qual);
    this->FilterData.pObject[1].__vftable = (Scaleform::Render::Filter_vtbl *)((int)this->FilterData.pObject[1].__vftable
                                                                             | (inner ? 0x20 : 0));
    this->FilterData.pObject[1].__vftable = (Scaleform::Render::Filter_vtbl *)((int)this->FilterData.pObject[1].__vftable
                                                                             | (knock ? 0x10 : 0));
    Scaleform::GFx::AS3::Value::~Value(&result);
  }
}
