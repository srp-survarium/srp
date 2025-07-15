void __thiscall Scaleform::GFx::DrawingContext::BeginBitmapFill(
        Scaleform::GFx::DrawingContext *this,
        Scaleform::GFx::FillType fillType,
        Scaleform::GFx::ImageResource *pimageRes,
        const Scaleform::Render::Matrix2x4<float> *mtx)
{
  unsigned int v5; // eax
  Scaleform::GFx::DrawingContext::PackedShape *pObject; // ecx
  Scaleform::Render::ComplexFill *v7; // eax
  int v8; // eax
  int v9; // esi
  Scaleform::Render::ImageBase *pImage; // ecx
  Scaleform::Render::ImageBase::ImageType (__thiscall *GetImageType)(Scaleform::Render::ImageBase *); // eax
  int v12; // esi
  Scaleform::Render::ImageBase *v13; // ebx
  Scaleform::MemoryHeap *v14; // eax
  Scaleform::GFx::ImageCreator *v15; // ecx
  Scaleform::RefCountVImpl *v16; // ebx
  Scaleform::Render::FillStyleType *v17; // ebx
  Scaleform::RefCountVImpl *v18; // ecx
  Scaleform::Render::ImageBase *v19; // [esp+4h] [ebp-64h]
  unsigned int v20; // [esp+1Ch] [ebp-4Ch]
  unsigned int v21; // [esp+20h] [ebp-48h] BYREF
  Scaleform::RefCountVImpl *v22; // [esp+24h] [ebp-44h]
  Scaleform::Render::Matrix2x4<float> m; // [esp+28h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v24; // [esp+48h] [ebp-20h] BYREF

  v5 = Scaleform::GFx::DrawingContext::SetNewFill(this);
  v20 = v5;
  if ( v5 )
  {
    pObject = this->Shapes.pObject;
    v22 = 0;
    pObject->GetFillStyle(pObject, v5, (Scaleform::Render::FillStyleType *)&v21);
    v7 = (Scaleform::Render::ComplexFill *)this->pHeap->Alloc(this->pHeap, 64, 0);
    if ( v7 )
    {
      Scaleform::Render::ComplexFill::ComplexFill(v7);
      v9 = v8;
    }
    else
    {
      v9 = 0;
    }
    if ( v22 )
      Scaleform::RefCountImpl::Release(v22);
    m.M[0][0] = mtx->M[0][0];
    m.M[0][1] = mtx->M[0][1];
    v22 = (Scaleform::RefCountVImpl *)v9;
    m.M[0][2] = mtx->M[0][2];
    m.M[0][3] = mtx->M[0][3];
    m.M[1][0] = mtx->M[1][0];
    m.M[1][1] = mtx->M[1][1];
    m.M[1][2] = mtx->M[1][2];
    m.M[1][3] = mtx->M[1][3];
    m.M[0][0] = m.M[0][0] * 20.0;
    m.M[0][1] = m.M[0][1] * 20.0;
    m.M[0][2] = m.M[0][2] * 20.0;
    m.M[0][3] = m.M[0][3] * 20.0;
    m.M[1][0] = m.M[1][0] * 20.0;
    m.M[1][1] = m.M[1][1] * 20.0;
    m.M[1][2] = m.M[1][2] * 20.0;
    m.M[1][3] = 20.0 * m.M[1][3];
    v24.M[0][0] = 1.0;
    v24.M[0][1] = 0.0;
    v24.M[0][2] = 0.0;
    v24.M[0][3] = 0.0;
    v24.M[1][0] = 0.0;
    v24.M[1][2] = 0.0;
    v24.M[1][3] = 0.0;
    v24.M[1][1] = 1.0;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v24, &m);
    pImage = pimageRes->pImage;
    *(float *)(v9 + 16) = v24.M[0][0];
    GetImageType = pImage->GetImageType;
    *(float *)(v9 + 20) = v24.M[0][1];
    *(float *)(v9 + 24) = v24.M[0][2];
    *(float *)(v9 + 28) = v24.M[0][3];
    *(float *)(v9 + 32) = v24.M[1][0];
    *(float *)(v9 + 36) = v24.M[1][1];
    *(float *)(v9 + 40) = v24.M[1][2];
    *(float *)(v9 + 44) = v24.M[1][3];
    v12 = 0;
    if ( GetImageType(pImage) )
    {
      v13 = pimageRes->pImage;
      if ( v13 )
        v13->AddRef(v13);
      v12 = (int)v13;
    }
    else if ( this->ImgCreator.pObject )
    {
      v14 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
      v15 = this->ImgCreator.pObject;
      LODWORD(v24.M[0][1]) = v14;
      *(_QWORD *)&v24.M[0][2] = 0x100000001LL;
      memset(v24.M[1], 0, sizeof(v24.M[1]));
      v19 = pimageRes->pImage;
      LODWORD(v24.M[0][0]) = 3;
      v12 = (int)v15->CreateImage(v15, (const Scaleform::GFx::ImageCreateInfo *)&v24, v19);
    }
    else
    {
      Scaleform::LogDebugMessage(
        (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&loc_20FFD + 3),
        "ImageCreator is null in BeginBitmapFill");
    }
    v16 = v22 + 1;
    if ( v12 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v12 + 4))(v12);
    if ( v16->__vftable )
      (*((void (__thiscall **)(Scaleform::RefCountVImpl_vtbl *))v16->~Scaleform::RefCountVImpl + 2))(v16->__vftable);
    v16->__vftable = (Scaleform::RefCountVImpl_vtbl *)v12;
    switch ( fillType )
    {
      case Fill_TiledSmoothImage:
        LOBYTE(v22[6].__vftable) = 2;
        break;
      case Fill_ClippedSmoothImage:
        LOBYTE(v22[6].__vftable) = 3;
        break;
      case Fill_TiledImage:
        LOBYTE(v22[6].__vftable) = 0;
        break;
      case Fill_ClippedImage:
        LOBYTE(v22[6].__vftable) = 1;
        break;
      default:
        break;
    }
    v17 = &this->Shapes.pObject->FillStyles.Data.Data[v20 - 1];
    v17->Color = v21;
    if ( v22 )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v22);
    v18 = (Scaleform::RefCountVImpl *)v17->pFill.pObject;
    if ( v18 )
      Scaleform::RefCountImpl::Release(v18);
    v17->pFill.pObject = (Scaleform::Render::ComplexFill *)v22;
    if ( (this->States & 0x10) != 0 )
    {
      Scaleform::GFx::DrawingContext::FinishPath(this);
      this->StY = 1.1754944e-38;
      this->StX = 1.1754944e-38;
      this->FillStyle1 = 0;
      this->FillStyle0 = 0;
    }
    this->States |= 0x14u;
    if ( v12 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v12 + 8))(v12);
    if ( v22 )
      Scaleform::RefCountImpl::Release(v22);
  }
}
