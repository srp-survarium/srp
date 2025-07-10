char __thiscall Scaleform::GFx::ShapeDataBase::DefPointTestLocal(
        Scaleform::GFx::ShapeDataBase *this,
        Scaleform::Render::ShapeMeshProvider *pshapeMeshProvider,
        const Scaleform::Render::Point<float> *pt,
        bool testShape,
        Scaleform::GFx::DisplayObjectBase *pinst)
{
  Scaleform::Render::Scale9GridInfo *v6; // esi
  Scaleform::Render::Scale9GridInfo *v7; // eax
  Scaleform::Render::Rect<float> *v8; // eax
  Scaleform::Render::TransformerBase *p_trans; // eax
  char v10; // bl
  float y1; // [esp+84h] [ebp-34h]
  float x2; // [esp+88h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> *v14; // [esp+8Ch] [ebp-2Ch]
  Scaleform::Render::TransformerBase trans; // [esp+90h] [ebp-28h] BYREF
  Scaleform::Render::Scale9GridInfo *v16; // [esp+94h] [ebp-24h]
  Scaleform::Render::Rect<float> bounds; // [esp+98h] [ebp-20h] BYREF
  Scaleform::Render::Rect<float> result; // [esp+A8h] [ebp-10h] BYREF

  v6 = 0;
  if ( pinst && (pinst->Flags & 1) != 0 )
  {
    Scaleform::GFx::DisplayObjectBase::CreateScale9Grid(pinst);
    v6 = v7;
  }
  pshapeMeshProvider->GetIdentityBounds(&pshapeMeshProvider->Scaleform::Render::MeshProvider, &bounds);
  if ( v6 )
  {
    v8 = Scaleform::Render::Scale9GridInfo::AdjustBounds(v6, &result, &bounds);
    y1 = v8->y1;
    x2 = v8->x2;
    trans.__vftable = (Scaleform::Render::TransformerBase_vtbl *)LODWORD(v8->y2);
    bounds.x1 = v8->x1;
    bounds.y1 = y1;
    bounds.x2 = x2;
    bounds.y2 = *(float *)&trans.__vftable;
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
    *(float *)&trans.__vftable = COERCE_FLOAT(&Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>::`vftable');
    v16 = 0;
    if ( v6 )
    {
      v16 = v6;
      p_trans = &trans;
    }
    else
    {
      v14 = &Scaleform::Render::Matrix2x4<float>::Identity;
      p_trans = (Scaleform::Render::TransformerBase *)&x2;
    }
    v10 = Scaleform::Render::HitTestFill<Scaleform::Render::TransformerBase>(this, p_trans, pt->x, pt->y);
    *(float *)&trans.__vftable = COERCE_FLOAT(&Scaleform::GFx::AS3::ArrayBase::`vftable');
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
