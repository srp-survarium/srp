bool __thiscall Scaleform::Render::TreeShape::NodeData::PropagateUp(
        Scaleform::Render::TreeShape::NodeData *this,
        Scaleform::Render::ContextImpl::Entry *entry)
{
  Scaleform::Render::ShapeMeshProvider *pObject; // eax
  float *v4; // eax
  double y2; // st7
  __int16 v6; // ax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax
  float v9; // [esp+54h] [ebp-3Ch]
  float v10; // [esp+54h] [ebp-3Ch]
  float v11; // [esp+58h] [ebp-38h]
  float x2; // [esp+58h] [ebp-38h]
  float v13; // [esp+5Ch] [ebp-34h]
  float y1; // [esp+5Ch] [ebp-34h]
  Scaleform::Render::Rect<float> r; // [esp+60h] [ebp-30h] BYREF
  Scaleform::Render::ContextImpl::EntryData v16; // [esp+70h] [ebp-20h]
  Scaleform::Render::ContextImpl::EntryData v17; // [esp+78h] [ebp-18h]
  Scaleform::Render::Rect<float> pr; // [esp+80h] [ebp-10h] BYREF

  r.x1 = 0.0;
  r.y1 = 0.0;
  r.x2 = 0.0;
  r.y2 = 0.0;
  *(float *)&v16.__vftable = 0.0;
  *(float *)&v16.Type = 0.0;
  *(float *)&v17.__vftable = 0.0;
  *(float *)&v17.Type = 0.0;
  if ( this->AproxLocalBounds.x2 > (double)this->AproxLocalBounds.x1
    && this->AproxLocalBounds.y2 > (double)this->AproxLocalBounds.y1 )
  {
    r.x1 = this->AproxLocalBounds.x1;
    r.y1 = this->AproxLocalBounds.y1;
    r.x2 = this->AproxLocalBounds.x2;
    y2 = this->AproxLocalBounds.y2;
    goto LABEL_6;
  }
  pObject = this->pMeshProvider.pObject;
  if ( pObject )
  {
    v4 = (float *)pObject->GetIdentityBounds(&pObject->Scaleform::Render::MeshProvider, &pr);
    v9 = v4[1];
    v11 = v4[2];
    v13 = v4[3];
    r.x1 = *v4;
    r.y1 = v9;
    r.x2 = v11;
    y2 = v13;
LABEL_6:
    r.y2 = y2;
  }
  if ( r.x2 > (double)r.x1 && r.y2 > (double)r.y1 )
  {
    Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(this, &r, 0);
    if ( (this->Flags & 0x200) != 0 )
      Scaleform::Render::Matrix3x4<float>::EncloseTransform(&this->M34, &pr, &r);
    else
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(
        (Scaleform::Render::Matrix2x4<float> *)&this->M34,
        &pr,
        (__m128 *)&r);
    *(float *)&v16.__vftable = pr.x1;
    *(float *)&v16.Type = pr.y1;
    *(float *)&v17.__vftable = pr.x2;
    *(float *)&v17.Type = pr.y2;
  }
  if ( this->AproxLocalBounds.x1 == r.x1
    && this->AproxLocalBounds.x2 == r.x2
    && this->AproxLocalBounds.y1 == r.y1
    && this->AproxLocalBounds.y2 == r.y2
    && *(float *)&v16.__vftable == r.x1
    && *(float *)&v17.__vftable == r.x2
    && *(float *)&v16.Type == r.y1
    && *(float *)&v17.Type == r.y2 )
  {
    LOBYTE(v6) = 0;
  }
  else
  {
    WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(entry, 8u);
    y1 = r.y1;
    x2 = r.x2;
    v10 = r.y2;
    *(float *)&WritableData[14].__vftable = r.x1;
    *(float *)&WritableData[14].Type = y1;
    *(float *)&WritableData[15].__vftable = x2;
    *(float *)&WritableData[15].Type = v10;
    WritableData[16] = v16;
    WritableData[17] = v17;
    return this->Flags & 1;
  }
  return v6;
}
