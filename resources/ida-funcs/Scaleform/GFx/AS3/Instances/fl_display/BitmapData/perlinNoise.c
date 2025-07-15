void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::perlinNoise(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v4; // edi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::AS3::VMAppDomain *CurrentDomain; // ebx
  Scaleform::GFx::AS3::Value *v9; // ecx
  Scaleform::GFx::AS3::Value::V2U v10; // edx
  unsigned int Flags; // eax
  bool v12; // bl
  Scaleform::GFx::AS3::Value::V1U v13; // ebx
  unsigned int v14; // eax
  unsigned int v15; // esi
  Scaleform::GFx::AS3::Impl::SparseArray *v16; // ecx
  const Scaleform::GFx::AS3::Value *v17; // eax
  Scaleform::GFx::AS3::VM *pVM; // edi
  Scaleform::GFx::AS3::Value::V1U v19; // ebx
  const Scaleform::GFx::AS3::Value *v20; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // eax
  bool v22; // cl
  float v23; // [esp+4h] [ebp-28Ch]
  Scaleform::StringDataPtr v24; // [esp+20h] [ebp-270h]
  Scaleform::StringDataPtr v25; // [esp+20h] [ebp-270h]
  Scaleform::GFx::AS3::VMAppDomain *v26; // [esp+24h] [ebp-26Ch]
  Scaleform::GFx::AS3::CheckResult v27; // [esp+37h] [ebp-259h] BYREF
  unsigned int offsetCount; // [esp+38h] [ebp-258h] BYREF
  Scaleform::GFx::AS3::CheckResult v29; // [esp+3Fh] [ebp-251h] BYREF
  float stitch; // [esp+40h] [ebp-250h] BYREF
  Scaleform::GFx::ASStringNode *v31; // [esp+44h] [ebp-24Ch]
  Scaleform::GFx::AS3::CheckResult v32; // [esp+4Ah] [ebp-246h] BYREF
  Scaleform::GFx::AS3::CheckResult v33; // [esp+4Bh] [ebp-245h] BYREF
  unsigned int channels; // [esp+4Ch] [ebp-244h] BYREF
  unsigned int seed; // [esp+50h] [ebp-240h] BYREF
  float *offsets; // [esp+54h] [ebp-23Ch]
  unsigned int octaves; // [esp+58h] [ebp-238h] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v38; // [esp+5Ch] [ebp-234h]
  BOOL grayScale; // [esp+60h] [ebp-230h]
  BOOL fractal; // [esp+64h] [ebp-22Ch]
  Scaleform::GFx::AS3::Value v; // [esp+68h] [ebp-228h] BYREF
  Scaleform::GFx::AS3::Impl::SparseArray *v42; // [esp+7Ch] [ebp-214h]
  double frequencyX; // [esp+80h] [ebp-210h] BYREF
  double frequencyY; // [esp+88h] [ebp-208h] BYREF
  float offsetStorage[128]; // [esp+90h] [ebp-200h] BYREF

  v4 = this;
  stitch = 0.0;
  v38 = this;
  if ( !this->pImage.pObject )
  {
    v24.pStr = "Invalid BitmapData";
    v24.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&stitch,
      eArgumentError,
      this->pTraits.pObject->pVM,
      v24);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v4->pTraits.pObject->pVM, v5);
    goto LABEL_3;
  }
  if ( argc < 6 )
  {
    v25.pStr = "BitmapData::perlinNoise";
    v25.Size = 23;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&stitch,
      eWrongArgumentCountError,
      this->pTraits.pObject->pVM,
      v25);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v4->pTraits.pObject->pVM, v7);
LABEL_3:
    v6 = v31;
    --v31->RefCount;
    if ( !v6->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    return;
  }
  seed = 0;
  frequencyX = 1.0;
  frequencyY = 1.0;
  octaves = 1;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(argv, &v27, &frequencyX)->Result
    && Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, &v33, &frequencyY)->Result
    && Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 2, &v32, &octaves)->Result
    && Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 3, &v29, &seed)->Result )
  {
    LOBYTE(stitch) = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 4);
    LOBYTE(fractal) = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 5);
    channels = 7;
    if ( argc < 7 || Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 6, &v29, &channels)->Result )
    {
      LOBYTE(grayScale) = argc >= 8 && Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 7);
      offsets = 0;
      offsetCount = 0;
      if ( argc < 9 || !argv[8].value.VS._1.VInt )
      {
LABEL_30:
        DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                        v4,
                                        v4);
        v22 = LOBYTE(stitch);
        stitch = frequencyY;
        v23 = stitch;
        stitch = frequencyX;
        Scaleform::Render::DrawableImage::PerlinNoise(
          DrawableImageFromBitmapData,
          stitch,
          v23,
          octaves,
          seed,
          v22,
          fractal,
          channels,
          grayScale,
          offsets,
          offsetCount);
        return;
      }
      memset((int)offsetStorage, 0, sizeof(offsetStorage));
      CurrentDomain = v4->pTraits.pObject->pVM->CurrentDomain;
      v9 = argv + 8;
      v.Bonus.pWeakProxy = argv[8].Bonus.pWeakProxy;
      v.value.VS._1.VInt = argv[8].value.VS._1.VInt;
      v10.VObj = (Scaleform::GFx::AS3::Object *)argv[8].value.VS._2;
      offsets = offsetStorage;
      Flags = argv[8].Flags;
      v.value.VS._2 = v10;
      v.Flags = Flags;
      if ( (Flags & 0x1F) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::AddRefWeakRef(v9);
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(v9);
      }
      v12 = !Scaleform::GFx::AS3::VM::IsOfType(v4->pTraits.pObject->pVM, &v, "Array", CurrentDomain);
      Scaleform::GFx::AS3::Value::~Value(&v);
      if ( !v12 )
      {
        v13 = argv[8].value.VS._1;
        Scaleform::GFx::AS3::Instances::fl_display::FrameLabel::frameGet(
          (Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *)v13.VInt,
          (int *)&offsetCount);
        v14 = offsetCount;
        offsetCount = 128;
        if ( v14 <= 0x80 )
          offsetCount = v14;
        v15 = 0;
        if ( offsetCount )
        {
          v42 = (Scaleform::GFx::AS3::Impl::SparseArray *)(v13.VInt + 32);
          do
          {
            v16 = v42;
            offsetStorage[2 * v15] = 0.0;
            offsetStorage[2 * v15 + 1] = 0.0;
            v17 = Scaleform::GFx::AS3::Impl::SparseArray::At(v16, v15);
            pVM = v4->pTraits.pObject->pVM;
            v19 = v17->value.VS._1;
            v26 = pVM->CurrentDomain;
            Scaleform::GFx::AS3::Value::Value(&v, v19.VObj);
            v27.Result = Scaleform::GFx::AS3::VM::IsOfType(pVM, v20, "flash.geom.Point", v26);
            Scaleform::GFx::AS3::Value::~Value(&v);
            if ( v27.Result )
            {
              offsetStorage[2 * v15] = *(double *)(v19.VInt + 32);
              offsetStorage[2 * v15 + 1] = *(double *)(v19.VInt + 40);
            }
            v4 = v38;
            ++v15;
          }
          while ( v15 < offsetCount );
        }
        goto LABEL_30;
      }
    }
  }
}
