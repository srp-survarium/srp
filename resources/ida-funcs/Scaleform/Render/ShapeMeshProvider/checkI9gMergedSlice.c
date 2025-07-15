bool __thiscall Scaleform::Render::ShapeMeshProvider::checkI9gMergedSlice(Scaleform::Render::ShapeMeshProvider *this)
{
  unsigned int v3; // eax
  Scaleform::RefCountVImpl_vtbl *v4; // edi
  Scaleform::Render::ShapeDataInterface *pObject; // ecx
  unsigned int v6; // esi
  Scaleform::RefCountVImpl_vtbl *v7; // eax
  int v8; // [esp+8h] [ebp-Ch]
  char v9; // [esp+Ch] [ebp-8h] BYREF
  Scaleform::RefCountVImpl *v10; // [esp+10h] [ebp-4h]

  if ( this->pMorphData.pObject )
    return 0;
  v8 = 0;
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
        v10 = 0;
        pObject->GetFillStyle(pObject, v3 + 1, (Scaleform::Render::FillStyleType *)&v9);
        if ( !v10 )
          break;
        v7 = v10[1].__vftable;
        if ( v7 && (!v4 || v4 == v7) )
          ++v8;
        v4 = v10[1].__vftable;
        Scaleform::RefCountImpl::Release(v10);
        v3 = v6;
        if ( v6 >= 9 )
          return v8 == 9;
      }
    }
  }
  return 0;
}
