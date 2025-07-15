void __thiscall Scaleform::GFx::ImageShapeCharacterDef::ImageShapeCharacterDef(
        Scaleform::GFx::ImageShapeCharacterDef *this,
        Scaleform::GFx::ImageResource *pimage,
        Scaleform::GFx::ImageCreator *imgCreator,
        bool bilinear)
{
  float *v5; // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v6; // edi
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx
  int v8; // eax
  Scaleform::Render::ImageBase *v9; // ecx
  Scaleform::Render::ImageBase::ImageType (__thiscall *GetImageType)(Scaleform::Render::ImageBase *); // eax
  Scaleform::Render::ImageBase *v11; // eax
  Scaleform::Render::Image *(__thiscall *CreateImage)(Scaleform::GFx::ImageCreator *, const Scaleform::GFx::ImageCreateInfo *, Scaleform::Render::ImageSource *); // edx
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // ecx
  unsigned int Capacity; // edx
  Scaleform::RefCountVImpl *v15; // ecx
  Scaleform::Render::Matrix2x4<float> *p_Size; // ecx
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v17; // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::DataStatus Status; // eax
  Scaleform::Render::ShapeMeshProvider *v19; // eax
  float v20; // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::ShapeMeshProvider *v22; // eax
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v23; // eax
  Scaleform::Render::ShapeMeshProvider *v24; // eax
  float v25; // eax
  Scaleform::Render::ImageBase *scale; // [esp+30h] [ebp-A4h]
  float scalea; // [esp+30h] [ebp-A4h]
  float x; // [esp+44h] [ebp-90h] BYREF
  Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v29; // [esp+48h] [ebp-8Ch] BYREF
  Scaleform::Render::ImageBase *v30; // [esp+4Ch] [ebp-88h]
  int v31; // [esp+50h] [ebp-84h] BYREF
  __m128 v32; // [esp+54h] [ebp-80h] BYREF
  Scaleform::Render::FillStyleType fill; // [esp+64h] [ebp-70h] BYREF
  int v34; // [esp+6Ch] [ebp-68h] BYREF
  int v35; // [esp+70h] [ebp-64h] BYREF
  float v36[4]; // [esp+74h] [ebp-60h] BYREF
  Scaleform::Render::Matrix2x4<float> v37; // [esp+84h] [ebp-50h] BYREF
  __m128 v38; // [esp+A4h] [ebp-30h] BYREF
  _DWORD v39[8]; // [esp+B4h] [ebp-20h] BYREF

  this->__vftable = (Scaleform::GFx::ImageShapeCharacterDef_vtbl *)&Scaleform::GFx::Resource::`vftable';
  this->pLib = 0;
  this->RefCount.Value = 1;
  this->Id.Id = 0x40000;
  this->pShapeMeshProvider.pObject = 0;
  this->__vftable = (Scaleform::GFx::ImageShapeCharacterDef_vtbl *)&Scaleform::GFx::ImageShapeCharacterDef::`vftable';
  this->pShape.pObject = 0;
  v34 = 2;
  v5 = (float *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 72, &v34);
  if ( v5 )
  {
    *(_DWORD *)v5 = &Scaleform::RefCountImplCore::`vftable';
    *((_DWORD *)v5 + 1) = 1;
    v5[2] = 0.0;
    v5[3] = 0.0;
    v5[4] = 0.0;
    v5[5] = 0.0;
    v5[6] = 0.0;
    v5[7] = 0.0;
    v5[8] = 0.0;
    v5[11] = 0.0;
    v5[12] = 0.0;
    v5[13] = 0.0;
    *((_DWORD *)v5 + 9) = v5 + 15;
    v5[14] = 0.0;
    v5[10] = 0.0;
    *(_DWORD *)v5 = &Scaleform::Render::ShapeDataFloat::`vftable';
    v5[15] = 0.0;
    v5[16] = 0.0;
    v5[17] = 0.0;
    v6 = (Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v5;
  }
  else
  {
    v6 = 0;
  }
  LODWORD(x) = 2;
  AllocAutoHeap = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
  fill.pFill.pObject = 0;
  v8 = (int)AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 64u, (const Scaleform::AllocInfo *)&x);
  if ( v8 )
  {
    *(_DWORD *)v8 = &Scaleform::RefCountImplCore::`vftable';
    *(_DWORD *)(v8 + 4) = 1;
    *(_DWORD *)v8 = &Scaleform::Render::ComplexFill::`vftable';
    *(float *)(v8 + 16) = 1.0;
    *(_DWORD *)(v8 + 8) = 0;
    *(float *)(v8 + 20) = 0.0;
    *(_DWORD *)(v8 + 12) = 0;
    *(float *)(v8 + 24) = 0.0;
    v29.Data = (Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)v8;
    *(float *)(v8 + 28) = 0.0;
    *(float *)(v8 + 32) = 0.0;
    *(float *)(v8 + 40) = 0.0;
    *(float *)(v8 + 44) = 0.0;
    *(float *)(v8 + 36) = 1.0;
    *(_BYTE *)(v8 + 48) = 0;
    *(_DWORD *)(v8 + 52) = -1;
  }
  else
  {
    v29.Data = 0;
  }
  fill.pFill.pObject = (Scaleform::Render::ComplexFill *)v29.Data;
  if ( !pimage )
  {
    Scaleform::LogDebugMessage(
      (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&loc_20FFD + 3),
      "Image is null in ImageShapeCharacterDef ctor.");
    goto LABEL_45;
  }
  v9 = pimage->pImage;
  GetImageType = v9->GetImageType;
  v30 = 0;
  if ( GetImageType(v9) )
  {
    v11 = pimage->pImage;
    x = *(float *)&v11;
    if ( *(float *)&v11 != 0.0 )
    {
      v11->AddRef(v11);
      *(float *)&v11 = x;
    }
    goto LABEL_14;
  }
  if ( imgCreator )
  {
    v39[1] = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    v39[2] = 1;
    v39[3] = 1;
    CreateImage = imgCreator->CreateImage;
    scale = pimage->pImage;
    v39[0] = 3;
    memset(&v39[4], 0, 16);
    *(float *)&v11 = COERCE_FLOAT((int)CreateImage(
                                         imgCreator,
                                         (const Scaleform::GFx::ImageCreateInfo *)v39,
                                         (Scaleform::Render::ImageSource *)scale));
LABEL_14:
    v30 = v11;
    goto LABEL_15;
  }
  Scaleform::LogDebugMessage(
    (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&loc_20FFD + 3),
    "ImageCreator is null in ImageShapeCharacterDef ctor");
  *(float *)&v11 = 0.0;
LABEL_15:
  if ( *(float *)&v11 != 0.0 )
  {
    v11->AddRef(v11);
    v11 = v30;
  }
  Data = v29.Data;
  Capacity = v29.Data->Data.Policy.Capacity;
  if ( Capacity )
  {
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)Capacity + 8))(v29.Data->Data.Policy.Capacity);
    v11 = v30;
    Data = v29.Data;
  }
  Data->Data.Policy.Capacity = (unsigned int)v11;
  if ( *(float *)&v11 == 0.0 )
  {
    Scaleform::LogDebugMessage(
      (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&loc_20FFD + 3),
      "Image is not created.");
    v15 = (Scaleform::RefCountVImpl *)v29.Data;
    goto LABEL_46;
  }
  p_Size = (Scaleform::Render::Matrix2x4<float> *)&Data[1].Data.Size;
  p_Size->M[0][0] = 1.0;
  p_Size->M[0][1] = 0.0;
  p_Size->M[0][2] = 0.0;
  p_Size->M[0][3] = 0.0;
  p_Size->M[1][0] = 0.0;
  p_Size->M[1][2] = 0.0;
  p_Size->M[1][3] = 0.0;
  p_Size->M[1][1] = 1.0;
  Scaleform::Render::Matrix2x4<float>::AppendScaling(p_Size, 0.050000001);
  v17 = v29.Data;
  LOBYTE(v29.Data[4].Data.Data) = 1;
  if ( bilinear )
    LOBYTE(v17[4].Data.Data) |= 2u;
  v30->GetRect(v30, (Scaleform::Render::Rect<unsigned long> *)v36);
  v37.M[0][0] = 1.0;
  v37.M[0][1] = 0.0;
  v37.M[0][2] = 0.0;
  v37.M[0][3] = 0.0;
  v37.M[1][0] = 0.0;
  v37.M[1][2] = 0.0;
  v37.M[1][3] = 0.0;
  v37.M[1][1] = 1.0;
  ((void (__thiscall *)(Scaleform::Render::ImageBase *, Scaleform::Render::Matrix2x4<float> *))v30->__vftable[1].GetImageType)(
    v30,
    &v37);
  v32.m128_f32[0] = 0.0;
  v32.m128_f32[1] = 0.0;
  v32.m128_f32[2] = 0.0;
  v32.m128_f32[3] = 0.0;
  v38.m128_f32[0] = (float)LODWORD(v36[0]);
  v38.m128_f32[1] = (float)LODWORD(v36[1]);
  v38.m128_f32[2] = (float)LODWORD(v36[2]);
  v38.m128_f32[3] = (float)LODWORD(v36[3]);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v37, &v32, &v38);
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddFillStyle(
    v6,
    &fill);
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
    v6,
    1u,
    0,
    0);
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
    v6,
    0.0,
    0.0);
  x = v32.m128_f32[2] - v32.m128_f32[0];
  x = x * 20.0;
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
    v6,
    x,
    0.0);
  x = v32.m128_f32[3] - v32.m128_f32[1];
  x = x * 20.0;
  scalea = x;
  x = v32.m128_f32[2] - v32.m128_f32[0];
  x = 20.0 * x;
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
    v6,
    x,
    scalea);
  x = v32.m128_f32[3] - v32.m128_f32[1];
  x = x * 20.0;
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
    v6,
    0.0,
    x);
  if ( v6->StartX != v6->LastX || v6->StartY != v6->LastY )
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      v6,
      v6->StartX,
      v6->StartY);
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v6);
  Status = v6->Status;
  if ( Status != Status_EndShape && Status )
  {
    if ( Status != Status_EndPath )
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v6);
    v29.Data = v6->Data;
    Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteChar(
      &v29,
      7);
    v6->Status = Status_EndShape;
  }
  v35 = 2;
  v19 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  this,
                                                  96,
                                                  &v35);
  if ( v19 )
  {
    Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v19, (Scaleform::GFx::Resource *)v6, 0);
    x = v20;
  }
  else
  {
    x = 0.0;
  }
  Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
  pObject = (Scaleform::RefCountVImpl *)this->pShape.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pShape.pObject = v6;
  v31 = 2;
  v22 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  this,
                                                  96,
                                                  &v31);
  if ( v22 )
  {
    Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v22, (Scaleform::GFx::Resource *)this->pShape.pObject, 0);
    v29.Data = v23;
  }
  else
  {
    v29.Data = 0;
  }
  v24 = this->pShapeMeshProvider.pObject;
  if ( v24 )
    v24->Release(&v24->Scaleform::Render::MeshProvider);
  v25 = x;
  this->pShapeMeshProvider.pObject = (Scaleform::Render::ShapeMeshProvider *)v29.Data;
  if ( v25 != 0.0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)(LODWORD(v25) + 8) + 8))(LODWORD(v25) + 8);
  v30->Release(v30);
LABEL_45:
  v15 = (Scaleform::RefCountVImpl *)fill.pFill.pObject;
LABEL_46:
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  if ( v6 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
}
