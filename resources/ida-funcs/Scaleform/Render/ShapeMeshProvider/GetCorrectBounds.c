Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::ShapeMeshProvider::GetCorrectBounds(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *m,
        float morphRatio,
        Scaleform::Render::StrokeGenerator *gen,
        const Scaleform::Render::ToleranceParams *tol)
{
  unsigned int v7; // eax
  Scaleform::GFx::Resource *Size; // edx
  Scaleform::GFx::Resource *Capacity; // [esp-4h] [ebp-D0h]
  Scaleform::Render::ShapePosInfo pos2; // [esp+10h] [ebp-BCh] BYREF
  Scaleform::Render::MorphInterpolator shape; // [esp+48h] [ebp-84h] BYREF

  v7 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->FillToStyleTable.Data.Size + 24))(this->FillToStyleTable.Data.Size);
  Size = (Scaleform::GFx::Resource *)this->FillToStyleTable.Data.Size;
  pos2.Sfactor = 1.0;
  pos2.Pos = v7;
  Capacity = (Scaleform::GFx::Resource *)this->FillToStyleTable.Data.Policy.Capacity;
  memset(&pos2.StartX, 0, 44);
  pos2.Initialized = 0;
  Scaleform::Render::MorphInterpolator::MorphInterpolator(&shape, Size, Capacity, morphRatio, &pos2);
  if ( gen )
    Scaleform::Render::ComputeBoundsFillAndStrokes<Scaleform::Render::Matrix2x4<float>>(
      result,
      &shape,
      m,
      gen,
      tol,
      Bound_OuterEdges);
  else
    Scaleform::Render::ComputeBoundsFillAndStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(
      result,
      &shape,
      m,
      Bound_OuterEdges);
  if ( shape.pMorphData.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)shape.pMorphData.pObject);
  if ( shape.pShapeData.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)shape.pShapeData.pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(&shape);
  return result;
}
