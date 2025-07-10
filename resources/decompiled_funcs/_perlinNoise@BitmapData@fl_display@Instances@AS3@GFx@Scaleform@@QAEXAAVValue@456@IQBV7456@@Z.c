void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::perlinNoise(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v4; // edi
  bool v5; // zf
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // ecx
  Scaleform::GFx::AS3::VM *v10; // esi
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::VMAppDomain *CurrentDomain; // ebx
  Scaleform::GFx::AS3::Value::Extra v14; // edx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *v16; // ecx
  bool v17; // bl
  Scaleform::GFx::AS3::Value::V1U v18; // ebx
  unsigned int v19; // eax
  unsigned int v20; // esi
  Scaleform::GFx::AS3::Impl::SparseArray *v21; // ecx
  const Scaleform::GFx::AS3::Value *v22; // eax
  Scaleform::GFx::AS3::VM *v23; // edi
  Scaleform::GFx::AS3::Value::V1U v24; // ebx
  const Scaleform::GFx::AS3::Value *v25; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // eax
  bool v27; // cl
  float v28; // [esp+4h] [ebp-28Ch]
  Scaleform::GFx::AS3::VMAppDomain *v29; // [esp+24h] [ebp-26Ch]
  Scaleform::GFx::AS3::CheckResult v30; // [esp+37h] [ebp-259h] BYREF
  unsigned int offsetCount; // [esp+38h] [ebp-258h] BYREF
  Scaleform::GFx::AS3::CheckResult v32; // [esp+3Fh] [ebp-251h] BYREF
  float stitch; // [esp+40h] [ebp-250h] BYREF
  Scaleform::GFx::ASStringNode *v34; // [esp+44h] [ebp-24Ch]
  Scaleform::GFx::AS3::CheckResult v35; // [esp+4Ah] [ebp-246h] BYREF
  Scaleform::GFx::AS3::CheckResult v36; // [esp+4Bh] [ebp-245h] BYREF
  unsigned int channels; // [esp+4Ch] [ebp-244h] BYREF
  unsigned int seed; // [esp+50h] [ebp-240h] BYREF
  float *offsets; // [esp+54h] [ebp-23Ch]
  unsigned int octaves; // [esp+58h] [ebp-238h] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v41; // [esp+5Ch] [ebp-234h]
  BOOL grayScale; // [esp+60h] [ebp-230h]
  BOOL fractal; // [esp+64h] [ebp-22Ch]
  Scaleform::GFx::AS3::Value v; // [esp+68h] [ebp-228h] BYREF
  Scaleform::GFx::AS3::Impl::SparseArray *v45; // [esp+7Ch] [ebp-214h]
  double frequencyX; // [esp+80h] [ebp-210h] BYREF
  double frequencyY; // [esp+88h] [ebp-208h] BYREF
  float offsetStorage[128]; // [esp+90h] [ebp-200h] BYREF

  v4 = this;
  stitch = 0.0;
  v5 = this->pImage.pObject == 0;
  v41 = this;
  if ( v5 )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&stitch, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v7);
    v8 = v34;
    --v34->RefCount;
    v9 = v8;
    if ( v8->RefCount )
      return;
    goto LABEL_3;
  }
  if ( argc >= 6 )
  {
    frequencyX = 1.0;
    frequencyY = 1.0;
    octaves = 1;
    seed = 0;
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv, &v30, &frequencyX)->Result )
      return;
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, &v36, &frequencyY)->Result )
      return;
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 2, &v35, &octaves)->Result )
      return;
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 3, &v32, &seed)->Result )
      return;
    LOBYTE(stitch) = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 4);
    LOBYTE(fractal) = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 5);
    channels = 7;
    if ( argc >= 7 && !Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 6, &v32, &channels)->Result )
      return;
    LOBYTE(grayScale) = argc >= 8 && Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 7);
    offsets = 0;
    offsetCount = 0;
    if ( argc >= 9 && argv[8].value.VS._1.VInt )
    {
      memset((int)offsetStorage, 0, sizeof(offsetStorage));
      CurrentDomain = v4->pTraits.pObject->pVM->CurrentDomain;
      v14.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)argv[8].Bonus;
      Flags = argv[8].Flags;
      offsets = offsetStorage;
      v16 = argv + 8;
      v.Bonus = v14;
      v.value.VNumber = argv[8].value.VNumber;
      v.Flags = Flags;
      if ( (Flags & 0x1F) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::AddRefWeakRef(v16);
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(v16);
      }
      v17 = !Scaleform::GFx::AS3::VM::IsOfType(v4->pTraits.pObject->pVM, &v, "Array", CurrentDomain);
      Scaleform::GFx::AS3::Value::~Value(&v);
      if ( v17 )
        return;
      v18 = argv[8].value.VS._1;
      Scaleform::GFx::AS3::Instances::fl_display::FrameLabel::frameGet(
        (Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *)v18.VInt,
        (int *)&offsetCount);
      v19 = offsetCount;
      offsetCount = 128;
      if ( v19 <= 0x80 )
        offsetCount = v19;
      v20 = 0;
      if ( offsetCount )
      {
        v45 = (Scaleform::GFx::AS3::Impl::SparseArray *)(v18.VInt + 32);
        do
        {
          v21 = v45;
          offsetStorage[2 * v20] = 0.0;
          offsetStorage[2 * v20 + 1] = 0.0;
          v22 = Scaleform::GFx::AS3::Impl::SparseArray::At(v21, v20);
          v23 = v4->pTraits.pObject->pVM;
          v24 = v22->value.VS._1;
          v29 = v23->CurrentDomain;
          Scaleform::GFx::AS3::Value::Value(&v, v24.VObj);
          v30.Result = Scaleform::GFx::AS3::VM::IsOfType(v23, v25, "flash.geom.Point", v29);
          Scaleform::GFx::AS3::Value::~Value(&v);
          if ( v30.Result )
          {
            offsetStorage[2 * v20] = *(double *)(v24.VInt + 32);
            offsetStorage[2 * v20 + 1] = *(double *)(v24.VInt + 40);
          }
          v4 = v41;
          ++v20;
        }
        while ( v20 < offsetCount );
      }
    }
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    v4,
                                    v4);
    v27 = LOBYTE(stitch);
    stitch = frequencyY;
    v28 = stitch;
    stitch = frequencyX;
    Scaleform::Render::DrawableImage::PerlinNoise(
      DrawableImageFromBitmapData,
      stitch,
      v28,
      octaves,
      seed,
      v27,
      fractal,
      channels,
      grayScale,
      offsets,
      offsetCount);
    return;
  }
  v10 = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&stitch, eWrongArgumentCountError, v10);
  Scaleform::GFx::AS3::VM::ThrowArgumentError(v10, v11);
  v12 = v34;
  --v34->RefCount;
  v9 = v12;
  if ( !v12->RefCount )
LABEL_3:
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}
