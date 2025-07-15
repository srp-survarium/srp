bool __thiscall Scaleform::GFx::ShapeDataBase::DefPointTestLocal(
        Scaleform::GFx::ShapeDataBase *this,
        Scaleform::Render::ShapeMeshProvider *pshapeMeshProvider,
        const Scaleform::Render::Point<float> *pt,
        bool testShape,
        Scaleform::GFx::DisplayObjectBase *pinst)
{
  Scaleform::Render::Scale9GridInfo *v6; // esi
  Scaleform::Render::Scale9GridInfo *v7; // eax
  Scaleform::Render::Rect<float> *v8; // eax
  float *p_y2; // eax
  bool v10; // bl
  float y1; // [esp+18h] [ebp-34h]
  float x2; // [esp+1Ch] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> *v14; // [esp+20h] [ebp-2Ch]
  float y2; // [esp+24h] [ebp-28h] BYREF
  Scaleform::Render::Scale9GridInfo *v16; // [esp+28h] [ebp-24h]
  Scaleform::Render::Rect<float> bounds; // [esp+2Ch] [ebp-20h] BYREF
  Scaleform::Render::Rect<float> result; // [esp+3Ch] [ebp-10h] BYREF

  v6 = 0;
  if ( pinst && (pinst->Flags & 1) != 0 )
  {
    Scaleform::GFx::DisplayObjectBase::CreateScale9Grid(pinst);
    v6 = v7;
  }
  pshapeMeshProvider->GetIdentityBounds(&pshapeMeshProvider->Scaleform::Render::MeshProvider, &bounds);
  if ( v6 )
  {
    v8 = Scaleform::Render::Scale9GridInfo::AdjustBounds(v6, &result, COERCE_FLOAT(&bounds));
    y1 = v8->y1;
    x2 = v8->x2;
    y2 = v8->y2;
    bounds.x1 = v8->x1;
    bounds.y1 = y1;
    bounds.x2 = x2;
    bounds.y2 = y2;
  }
  if ( bounds.x2 < (double)pt->x || bounds.x1 > (double)pt->x || bounds.y2 < (double)pt->y || bounds.y1 > (double)pt->y )
  {
    if ( v6 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
    return 0;
  }
  else if ( testShape )
  {
    x2 = COERCE_FLOAT(&Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::`vftable');
    v14 = 0;
    y2 = COERCE_FLOAT(&Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>::`vftable');
    v16 = 0;
    if ( v6 )
    {
      v16 = v6;
      p_y2 = &y2;
    }
    else
    {
      v14 = &Scaleform::Render::Matrix2x4<float>::Identity;
      p_y2 = &x2;
    }
    v10 = Scaleform::Render::HitTestFill<Scaleform::Render::TransformerBase>(
            this,
            (Scaleform::Render::TransformerBase *)p_y2,
            pt->x,
            pt->y);
    y2 = COERCE_FLOAT(&Scaleform::GFx::AS3::ArrayBase::`vftable');
    x2 = COERCE_FLOAT(&Scaleform::GFx::AS3::ArrayBase::`vftable');
    if ( v6 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
    return v10;
  }
  else
  {
    if ( v6 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
    return 1;
  }
}
