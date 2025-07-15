Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::ShapeMeshProvider::GetCorrectBounds(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *m,
        float morphRatio,
        Scaleform::Render::StrokeSorter *gen,
        const Scaleform::Render::ToleranceParams *tol)
{
  unsigned int v7; // eax
  Scaleform::GFx::Resource *Size; // edx
  Scaleform::GFx::Resource *Capacity; // [esp-4h] [ebp-D0h]
  Scaleform::Render::ShapePosInfo v11; // [esp+10h] [ebp-BCh] BYREF
  Scaleform::Render::MorphInterpolator shape; // [esp+48h] [ebp-84h] BYREF

  v7 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->FillToStyleTable.Data.Size + 24))(this->FillToStyleTable.Data.Size);
  Size = (Scaleform::GFx::Resource *)this->FillToStyleTable.Data.Size;
  v11.Sfactor = 1.0;
  v11.Pos = v7;
  Capacity = (Scaleform::GFx::Resource *)this->FillToStyleTable.Data.Policy.Capacity;
  memset(&v11.StartX, 0, 44);
  v11.Initialized = 0;
  Scaleform::Render::MorphInterpolator::MorphInterpolator(&shape, Size, Capacity, morphRatio, &v11);
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
