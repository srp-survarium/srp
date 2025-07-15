char __thiscall Scaleform::GFx::MorphCharacterDef::DefPointTestLocal(
        Scaleform::GFx::MorphCharacterDef *this,
        const Scaleform::Render::Point<float> *pt,
        bool testShape,
        Scaleform::GFx::DisplayObjectBase *pinst)
{
  Scaleform::Render::Scale9GridInfo *v4; // esi
  Scaleform::Render::Scale9GridInfo *v6; // eax
  Scaleform::Render::ShapeMeshProvider *v7; // ecx
  Scaleform::Render::Rect<float> *v8; // eax
  char v9; // al
  Scaleform::GFx::DisplayObjectBase_vtbl *v10; // edx
  float (__thiscall *GetRatio)(Scaleform::GFx::DisplayObjectBase *); // eax
  Scaleform::Render::ShapeMeshProvider *pObject; // ebx
  char v13; // bl
  float morphRatio; // [esp+20h] [ebp-60h]
  float y1; // [esp+44h] [ebp-3Ch]
  float x2; // [esp+48h] [ebp-38h]
  float y2; // [esp+4Ch] [ebp-34h]
  Scaleform::Render::Rect<float> bounds; // [esp+50h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+60h] [ebp-20h] BYREF

  v4 = 0;
  if ( pinst && (pinst->Flags & 1) != 0 )
  {
    Scaleform::GFx::DisplayObjectBase::CreateScale9Grid(pinst);
    v4 = v6;
  }
  result.M[0][0] = 1.0;
  result.M[0][1] = 0.0;
  result.M[0][2] = 0.0;
  result.M[0][3] = 0.0;
  result.M[1][0] = 0.0;
  result.M[1][2] = 0.0;
  if ( testShape )
  {
    v10 = pinst->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    result.M[1][3] = 0.0;
    GetRatio = v10->GetRatio;
    pObject = this->pShapeMeshProvider.pObject;
    result.M[1][1] = 1.0;
    morphRatio = GetRatio(pinst);
    v9 = Scaleform::Render::ShapeMeshProvider::HitTestShape(pObject, &result, pt->x, pt->y, morphRatio, 0, 0, v4);
  }
  else
  {
    v7 = this->pShapeMeshProvider.pObject;
    result.M[1][3] = 0.0;
    result.M[1][1] = 1.0;
    ((void (__stdcall *)(Scaleform::Render::Rect<float> *, Scaleform::Render::Matrix2x4<float> *, _DWORD, _DWORD, _DWORD))v7->GetCorrectBounds)(
      &bounds,
      &result,
      0.0,
      0,
      0);
    if ( v4 )
    {
      v8 = Scaleform::Render::Scale9GridInfo::AdjustBounds(v4, (Scaleform::Render::Rect<float> *)&result, &bounds);
      y1 = v8->y1;
      x2 = v8->x2;
      y2 = v8->y2;
      bounds.x1 = v8->x1;
      bounds.y1 = y1;
      bounds.x2 = x2;
      bounds.y2 = y2;
    }
    v9 = Scaleform::Render::Rect<float>::Contains(&bounds, pt);
  }
  v13 = v9;
  if ( v4 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4);
  return v13;
}
