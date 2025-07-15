void __thiscall Scaleform::Render::ShapeMeshProvider::GetFillData(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::FillData *pdata,
        unsigned int drawLayer,
        unsigned int fillIndex,
        char meshGenFlags)
{
  int v6; // eax
  Scaleform::Render::ComplexFill *ComplexFill; // eax
  int v8; // eax
  Scaleform::Render::Image *v9; // eax
  int v10; // eax
  Scaleform::Render::ImageFillMode v11; // [esp-4h] [ebp-24h]
  Scaleform::Render::FillData v12; // [esp+Ch] [ebp-14h] BYREF

  if ( (meshGenFlags & 2) != 0 )
  {
    Scaleform::Render::FillData::FillData(&v12, Fill_Mask);
    pdata->Type = *(_DWORD *)v6;
    pdata->Color = *(_DWORD *)(v6 + 4);
    pdata->Color = *(_DWORD *)(v6 + 4);
    pdata->Color = *(_DWORD *)(v6 + 4);
    pdata->PrimFill = *(_DWORD *)(v6 + 8);
    pdata->FillMode.Fill = *(_BYTE *)(v6 + 12);
    pdata->pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
    return;
  }
  ComplexFill = Scaleform::Render::ShapeMeshProvider::getComplexFill(
                  (Scaleform::Render::ShapeMeshProvider *)((char *)this - 8),
                  drawLayer,
                  fillIndex,
                  0);
  if ( !ComplexFill )
  {
    Scaleform::Render::FillData::FillData(&v12, Fill_VColor);
    goto LABEL_10;
  }
  if ( ComplexFill->pGradient.pObject )
  {
    Scaleform::Render::FillData::FillData(&v12, ComplexFill->pGradient.pObject);
LABEL_10:
    pdata->Type = *(_DWORD *)v8;
    pdata->Color = *(_DWORD *)(v8 + 4);
    pdata->Color = *(_DWORD *)(v8 + 4);
    pdata->Color = *(_DWORD *)(v8 + 4);
    pdata->PrimFill = *(_DWORD *)(v8 + 8);
    pdata->FillMode.Fill = *(_BYTE *)(v8 + 12);
    pdata->pVFormat = *(const Scaleform::Render::VertexFormat **)(v8 + 16);
    return;
  }
  v11.Fill = ComplexFill->FillMode.Fill;
  v9 = ComplexFill->pImage.pObject->GetAsImage(ComplexFill->pImage.pObject);
  Scaleform::Render::FillData::FillData(&v12, v9, v11);
  pdata->Type = *(_DWORD *)v10;
  pdata->Color = *(_DWORD *)(v10 + 4);
  pdata->Color = *(_DWORD *)(v10 + 4);
  pdata->Color = *(_DWORD *)(v10 + 4);
  pdata->PrimFill = *(_DWORD *)(v10 + 8);
  pdata->FillMode.Fill = *(_BYTE *)(v10 + 12);
  pdata->pVFormat = *(const Scaleform::Render::VertexFormat **)(v10 + 16);
  if ( *(&this->hKeySet.pManager.Value->KeySetLock.cs.RecursionCount + 5 * drawLayer) )
  {
    if ( (meshGenFlags & 8) != 0 )
    {
      pdata->PrimFill = PrimFill_UVTexture;
      pdata->pVFormat = &Scaleform::Render::Image9GridVertex::Format;
    }
  }
}
