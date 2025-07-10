bool __thiscall Scaleform::Render::ShapeMeshProvider::checkI9gMergedSlice(Scaleform::Render::ShapeMeshProvider *this)
{
  unsigned int v3; // eax
  Scaleform::Render::Image *v4; // edi
  Scaleform::Render::ShapeDataInterface *pObject; // ecx
  unsigned int v6; // esi
  Scaleform::Render::Image *v7; // eax
  unsigned int imgStyleCount; // [esp+8h] [ebp-Ch]
  Scaleform::Render::FillStyleType f; // [esp+Ch] [ebp-8h] BYREF

  if ( this->pMorphData.pObject )
    return 0;
  imgStyleCount = 0;
  if ( this->DrawLayers.Data.Size == 9 && this->pShapeData.pObject->GetFillStyleCount(this->pShapeData.pObject) == 9 )
  {
    v3 = this->pShapeData.pObject->GetStrokeStyleCount(this->pShapeData.pObject);
    if ( !v3 )
    {
      v4 = 0;
      while ( 1 )
      {
        pObject = this->pShapeData.pObject;
        v6 = v3 + 1;
        f.pFill.pObject = 0;
        pObject->GetFillStyle(pObject, v3 + 1, &f);
        if ( !f.pFill.pObject )
          break;
        v7 = f.pFill.pObject->pImage.pObject;
        if ( v7 && (!v4 || v4 == v7) )
          ++imgStyleCount;
        v4 = f.pFill.pObject->pImage.pObject;
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)f.pFill.pObject);
        v3 = v6;
        if ( v6 >= 9 )
          return imgStyleCount == 9;
      }
    }
  }
  return 0;
}
