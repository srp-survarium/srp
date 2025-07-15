void __thiscall Scaleform::GFx::TextField::OnEventLoad(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType pgeomData; // [esp+70h] [ebp-60h] BYREF

  if ( Scaleform::String::GetLength(&this->pDef.pObject->DefaultText) )
    Scaleform::GFx::TextField::SetTextValue(
      this,
      (char *)((this->pDef.pObject->DefaultText.HeapTypeBits & 0xFFFFFFFC) + 8),
      (this->Flags & 2) != 0,
      0);
  else
    Scaleform::GFx::TextField::SetTextValue(this, (char *)&buf, (this->Flags & 2) != 0, 0);
  Scaleform::Render::Text::DocView::Format(this->pDocument.pObject);
  Scaleform::GFx::InteractiveObject::OnEventLoad(this);
  if ( !this->pGeomData )
  {
    pgeomData.OrigMatrix.M[0][0] = 1.0;
    pgeomData.OrigMatrix.M[0][1] = 0.0;
    pgeomData.OrigMatrix.M[0][2] = 0.0;
    pgeomData.Y = 0;
    pgeomData.OrigMatrix.M[0][3] = 0.0;
    pgeomData.X = 0;
    pgeomData.OrigMatrix.M[1][0] = 0.0;
    pgeomData.OrigMatrix.M[1][2] = 0.0;
    pgeomData.OrigMatrix.M[1][3] = 0.0;
    pgeomData.OrigMatrix.M[1][1] = 1.0;
    pgeomData.Rotation = 0.0;
    pgeomData.YScale = 100.0;
    pgeomData.XScale = 100.0;
    pgeomData.ZScale = 100.0;
    pgeomData.YRotation = 0.0;
    pgeomData.XRotation = 0.0;
    pgeomData.Z = 0.0;
    Scaleform::GFx::TextField::UpdateAndGetGeomData(this, &pgeomData, 1);
  }
}
