char __thiscall Scaleform::GFx::AS3::AvmBitmap::CreateBitmapShape(Scaleform::GFx::AS3::AvmBitmap *this)
{
  float *v2; // eax
  float *v3; // esi
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // eax
  int v5; // eax
  Scaleform::GFx::ImageResource *v6; // eax
  float v7; // ecx
  int v8; // ebx
  Scaleform::RefCountVImpl *v9; // eax
  Scaleform::RefCountVImpl *v10; // ebx
  void (__thiscall *AddRef)(Scaleform::RefCountVImpl *); // edx
  Scaleform::GFx::ImageResource *v12; // eax
  Scaleform::RefCountVImpl *v13; // eax
  Scaleform::RefCountVImpl_vtbl *v14; // ecx
  Scaleform::RefCountVImpl *v16; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v18; // eax
  Scaleform::Render::ShapeMeshProvider *v19; // eax
  Scaleform::Render::ContextImpl::EntryData_vtbl *v20; // eax
  Scaleform::Render::ContextImpl::EntryData_vtbl *v21; // edi
  int v22; // eax
  Scaleform::Render::ShapeMeshProvider *v23; // eax
  Scaleform::Render::ContextImpl::EntryData_vtbl *v24; // eax
  Scaleform::Render::ContextImpl::EntryData_vtbl *v25; // edi
  float scale; // [esp+240h] [ebp-B4h]
  float x; // [esp+258h] [ebp-9Ch] BYREF
  Scaleform::RefCountVImpl *v28; // [esp+25Ch] [ebp-98h] BYREF
  int v29; // [esp+260h] [ebp-94h] BYREF
  __m128 v30; // [esp+264h] [ebp-90h] BYREF
  Scaleform::Render::TreeShape *pObject; // [esp+280h] [ebp-74h]
  Scaleform::Render::FillStyleType v32; // [esp+284h] [ebp-70h] BYREF
  int v33; // [esp+28Ch] [ebp-68h] BYREF
  Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v34; // [esp+290h] [ebp-64h] BYREF
  float v35[4]; // [esp+294h] [ebp-60h] BYREF
  Scaleform::Render::Matrix2x4<float> v36; // [esp+2A4h] [ebp-50h] BYREF
  __m128 v37; // [esp+2C4h] [ebp-30h] BYREF
  _DWORD v38[8]; // [esp+2D4h] [ebp-20h] BYREF

  pObject = (Scaleform::Render::TreeShape *)this->pRenNode.pObject;
  v33 = 2;
  v2 = (float *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 72, &v33);
  if ( v2 )
  {
    *(_DWORD *)v2 = &Scaleform::RefCountImplCore::`vftable';
    *((_DWORD *)v2 + 1) = 1;
    v2[2] = 0.0;
    v2[3] = 0.0;
    v2[4] = 0.0;
    v2[5] = 0.0;
    v2[6] = 0.0;
    v2[7] = 0.0;
    v2[8] = 0.0;
    v2[11] = 0.0;
    v2[12] = 0.0;
    v2[13] = 0.0;
    *((_DWORD *)v2 + 9) = v2 + 15;
    v2[14] = 0.0;
    v2[10] = 0.0;
    *(_DWORD *)v2 = &Scaleform::Render::ShapeDataFloat::`vftable';
    v2[15] = 0.0;
    v2[16] = 0.0;
    v2[17] = 0.0;
    v3 = v2;
  }
  else
  {
    v3 = 0;
  }
  v28 = (Scaleform::RefCountVImpl *)2;
  AllocAutoHeap = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
  v32.pFill.pObject = 0;
  v32.Color = 0;
  v5 = (int)AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 64u, (const Scaleform::AllocInfo *)&v28);
  if ( v5 )
  {
    *(_DWORD *)v5 = &Scaleform::RefCountImplCore::`vftable';
    *(_DWORD *)(v5 + 4) = 1;
    *(_DWORD *)v5 = &Scaleform::Render::ComplexFill::`vftable';
    *(float *)(v5 + 16) = 1.0;
    *(_DWORD *)(v5 + 8) = 0;
    *(float *)(v5 + 20) = 0.0;
    *(_DWORD *)(v5 + 12) = 0;
    *(float *)(v5 + 24) = 0.0;
    *(float *)(v5 + 28) = 0.0;
    *(float *)(v5 + 32) = 0.0;
    *(float *)(v5 + 40) = 0.0;
    *(float *)(v5 + 44) = 0.0;
    *(float *)(v5 + 36) = 1.0;
    *(_BYTE *)(v5 + 48) = 0;
    *(_DWORD *)(v5 + 52) = -1;
    v28 = (Scaleform::RefCountVImpl *)v5;
  }
  else
  {
    v28 = 0;
  }
  v6 = this->pImage.pObject;
  v32.pFill.pObject = (Scaleform::Render::ComplexFill *)v28;
  if ( v6 )
  {
    if ( v6->pImage->GetImageType(v6->pImage) )
    {
      v7 = *(float *)&this->pImage.pObject->pImage;
      x = v7;
      if ( v7 != 0.0 )
      {
        (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v7) + 4))(COERCE_FLOAT(LODWORD(v7)));
        v7 = x;
      }
      v8 = LODWORD(v7);
    }
    else
    {
      v9 = (Scaleform::RefCountVImpl *)this->pASRoot->pMovieImpl->GetStateAddRef(
                                         &this->pASRoot->pMovieImpl->Scaleform::GFx::StateBag,
                                         11);
      v10 = v9;
      if ( !v9 )
      {
        Scaleform::LogDebugMessage(
          (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&loc_20FFD + 3),
          "Image is not created: can't find ImageCreator.");
        if ( v28 )
          Scaleform::RefCountImpl::Release(v28);
        if ( v3 )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v3);
        return 0;
      }
      Scaleform::RefCountImpl::Release(v9);
      AddRef = v10->__vftable[1].AddRef;
      v38[1] = this->pASRoot->pMovieImpl->pHeap;
      v38[2] = 1;
      v38[3] = 1;
      memset(&v38[4], 0, 16);
      v12 = this->pImage.pObject;
      v38[0] = 3;
      v8 = ((int (__thiscall *)(Scaleform::RefCountVImpl *, _DWORD *, Scaleform::Render::ImageBase *))AddRef)(
             v10,
             v38,
             v12->pImage);
    }
    if ( v8 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(v8);
    v13 = v28;
    v14 = v28[1].__vftable;
    if ( v14 )
    {
      (*((void (__thiscall **)(Scaleform::RefCountVImpl_vtbl *))v14->~Scaleform::RefCountVImpl + 2))(v14);
      v13 = v28;
    }
    v13[1].__vftable = (Scaleform::RefCountVImpl_vtbl *)v8;
    if ( !v8 )
    {
      Scaleform::LogDebugMessage(
        (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&loc_20FFD + 3),
        "Image is not created.");
      if ( v28 )
        Scaleform::RefCountImpl::Release(v28);
      if ( v3 )
      {
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v3);
        return 0;
      }
      return 0;
    }
    *(float *)&v13[2].__vftable = 1.0;
    *(float *)&v13[2].RefCount = 0.0;
    *(float *)&v13[3].__vftable = 0.0;
    *(float *)&v13[3].RefCount = 0.0;
    *(float *)&v13[4].__vftable = 0.0;
    *(float *)&v13[5].__vftable = 0.0;
    *(float *)&v13[5].RefCount = 0.0;
    *(float *)&v13[4].RefCount = 1.0;
    Scaleform::Render::Matrix2x4<float>::AppendScaling((Scaleform::Render::Matrix2x4<float> *)&v13[2], 0.050000001);
    v16 = v28;
    LOBYTE(v28[6].__vftable) = 1;
    pAS3RawPtr = this->pAS3RawPtr;
    if ( !pAS3RawPtr )
      pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
    if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
      pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
    if ( !pAS3RawPtr )
      goto LABEL_33;
    v18 = this->pAS3RawPtr;
    if ( !v18 )
      v18 = this->pAS3CollectiblePtr.pObject;
    if ( ((unsigned __int8)v18 & 1) != 0 )
      v18 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v18 - 1);
    if ( LOBYTE(v18[1].pNext) )
LABEL_33:
      LOBYTE(v16[6].__vftable) = 3;
    (*(void (__thiscall **)(int, float *))(*(_DWORD *)v8 + 24))(v8, v35);
    v36.M[0][0] = 1.0;
    v36.M[0][1] = 0.0;
    v36.M[0][2] = 0.0;
    v36.M[0][3] = 0.0;
    v36.M[1][0] = 0.0;
    v36.M[1][2] = 0.0;
    v36.M[1][3] = 0.0;
    v36.M[1][1] = 1.0;
    (*(void (__thiscall **)(int, Scaleform::Render::Matrix2x4<float> *))(*(_DWORD *)v8 + 68))(v8, &v36);
    v30.m128_f32[0] = 0.0;
    v30.m128_f32[1] = 0.0;
    v30.m128_f32[2] = 0.0;
    v30.m128_f32[3] = 0.0;
    v37.m128_f32[0] = (float)LODWORD(v35[0]);
    v37.m128_f32[1] = (float)LODWORD(v35[1]);
    v37.m128_f32[2] = (float)LODWORD(v35[2]);
    v37.m128_f32[3] = (float)LODWORD(v35[3]);
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v36, &v30, &v37);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddFillStyle(
      (Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v3,
      &v32);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      (Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v3,
      1u,
      0,
      0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      (Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v3,
      0.0,
      0.0);
    x = v30.m128_f32[2] - v30.m128_f32[0];
    x = x * 20.0;
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      (Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v3,
      x,
      0.0);
    x = v30.m128_f32[3] - v30.m128_f32[1];
    x = x * 20.0;
    scale = x;
    x = v30.m128_f32[2] - v30.m128_f32[0];
    x = 20.0 * x;
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      (Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v3,
      x,
      scale);
    x = v30.m128_f32[3] - v30.m128_f32[1];
    x = x * 20.0;
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      (Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v3,
      0.0,
      x);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ClosePath((Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v3);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath((Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v3);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape((Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v3);
    LODWORD(x) = 2;
    v19 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this,
                                                    96,
                                                    &x);
    if ( v19 )
    {
      Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v19, (Scaleform::GFx::Resource *)v3, 0);
      v21 = v20;
    }
    else
    {
      v21 = 0;
    }
    Scaleform::Render::TreeShape::SetShape(pObject, v21);
    if ( v21 )
      (*((void (__thiscall **)(void (__thiscall **)(Scaleform::Render::ContextImpl::EntryData *, void *)))v21->CopyTo + 2))(&v21->CopyTo);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 8))(v8);
  }
  else
  {
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      (Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v3,
      0,
      0,
      0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      (Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v3,
      0.0,
      0.0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      (Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v3,
      1.0,
      1.0);
    if ( v3[11] != v3[13] || v3[12] != v3[14] )
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
        (Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v3,
        v3[11],
        v3[12]);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath((Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v3);
    v22 = *((_DWORD *)v3 + 2);
    if ( v22 != 6 && v22 )
    {
      if ( v22 != 5 )
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath((Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v3);
      v34.Data = (Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)*((_DWORD *)v3 + 9);
      Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteChar(
        &v34,
        7);
      *((_DWORD *)v3 + 2) = 6;
    }
    v29 = 2;
    v23 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this,
                                                    96,
                                                    &v29);
    if ( v23 )
    {
      Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v23, (Scaleform::GFx::Resource *)v3, 0);
      v25 = v24;
    }
    else
    {
      v25 = 0;
    }
    Scaleform::Render::TreeShape::SetShape(pObject, v25);
    if ( v25 )
      (*((void (__thiscall **)(void (__thiscall **)(Scaleform::Render::ContextImpl::EntryData *, void *)))v25->CopyTo + 2))(&v25->CopyTo);
  }
  if ( v32.pFill.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v32.pFill.pObject);
  if ( v3 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v3);
  return 1;
}
