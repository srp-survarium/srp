void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult v7; // [esp+2Bh] [ebp-5Dh] BYREF
  Scaleform::GFx::ASString type; // [esp+2Ch] [ebp-5Ch] BYREF
  unsigned int highC; // [esp+30h] [ebp-58h] BYREF
  unsigned int shadowC; // [esp+34h] [ebp-54h] BYREF
  int qual; // [esp+38h] [ebp-50h] BYREF
  BOOL knock; // [esp+3Ch] [ebp-4Ch]
  long double dist; // [esp+40h] [ebp-48h] BYREF
  long double angl; // [esp+48h] [ebp-40h] BYREF
  long double highA; // [esp+50h] [ebp-38h] BYREF
  long double shadowA; // [esp+58h] [ebp-30h] BYREF
  long double blurX; // [esp+60h] [ebp-28h] BYREF
  long double blurY; // [esp+68h] [ebp-20h] BYREF
  long double stren; // [esp+70h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value result; // [esp+78h] [ebp-10h] BYREF

  dist = 4.0;
  angl = 45.0;
  pObject = this->pTraits.pObject;
  highA = 1.0;
  shadowA = 1.0;
  highC = (unsigned int)&vostok::memory::s_CRT_arena[5574199];
  stren = 1.0;
  shadowC = 0;
  qual = 1;
  blurX = 4.0;
  blurY = 4.0;
  pStringManager = pObject->pVM->StringManagerRef->pStringManager;
  knock = 0;
  type.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pStringManager, "inner", 5u, 0);
  ++type.pNode->RefCount;
  LOBYTE(knock) = 0;
  if ( (!argc || Scaleform::GFx::AS3::Value::Convert2Number(argv, &v7, &dist)->Result)
    && (argc < 2 || Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, &v7, &angl)->Result)
    && (argc < 3 || Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 2, &v7, &highC)->Result)
    && (argc < 4 || Scaleform::GFx::AS3::Value::Convert2Number(argv + 3, &v7, &highA)->Result)
    && (argc < 5 || Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 4, &v7, &shadowC)->Result)
    && (argc < 6 || Scaleform::GFx::AS3::Value::Convert2Number(argv + 5, &v7, &shadowA)->Result)
    && (argc < 7 || Scaleform::GFx::AS3::Value::Convert2Number(argv + 6, &v7, &blurX)->Result)
    && (argc < 8 || Scaleform::GFx::AS3::Value::Convert2Number(argv + 7, &v7, &blurY)->Result)
    && (argc < 9 || Scaleform::GFx::AS3::Value::Convert2Number(argv + 8, &v7, &stren)->Result)
    && (argc < 0xA || Scaleform::GFx::AS3::Value::Convert2Int32(argv + 9, &v7, &qual)->Result)
    && (argc < 0xB || Scaleform::GFx::AS3::Value::Convert2String(argv + 10, &v7, &type)->Result) )
  {
    if ( argc >= 0xC )
      LOBYTE(knock) = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 11);
    result.Flags = 0;
    result.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::distanceSet(this, &result, dist);
    Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::angleSet(this, &result, angl);
    Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::highlightColorSet(
      this,
      &result,
      (Scaleform::Render::BevelFilter_vtbl *)highC);
    Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::highlightAlphaSet(this, 0, &result, highA);
    Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::shadowColorSet(
      this,
      &result,
      (Scaleform::Render::BevelFilter_vtbl *)shadowC);
    Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::shadowAlphaSet(this, 0, &result, shadowA);
    Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::blurXSet(this, &result, blurX);
    Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::blurYSet(this, &result, blurY);
    Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::strengthSet(this, &result, stren);
    Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::qualitySet(this, &result, qual);
    Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::typeSet(this, &result, &type);
    Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::knockoutSet(this, &result, knock);
    Scaleform::GFx::AS3::Value::~Value(&result);
  }
  pNode = type.pNode;
  --type.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
