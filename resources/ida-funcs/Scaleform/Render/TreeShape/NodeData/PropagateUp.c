bool __thiscall Scaleform::Render::TreeShape::NodeData::PropagateUp(
        Scaleform::Render::TreeShape::NodeData *this,
        Scaleform::Render::ContextImpl::Entry *entry)
{
  Scaleform::Render::ShapeMeshProvider *pObject; // eax
  float *v4; // eax
  double y2; // st7
  __int16 v6; // ax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax
  float v9; // [esp+4h] [ebp-3Ch]
  float v10; // [esp+4h] [ebp-3Ch]
  float v11; // [esp+8h] [ebp-38h]
  float x2; // [esp+8h] [ebp-38h]
  float v13; // [esp+Ch] [ebp-34h]
  float y1; // [esp+Ch] [ebp-34h]
  Scaleform::Render::Rect<float> bounds; // [esp+10h] [ebp-30h] BYREF
  Scaleform::Render::ContextImpl::EntryData v16; // [esp+20h] [ebp-20h]
  Scaleform::Render::ContextImpl::EntryData v17; // [esp+28h] [ebp-18h]
  Scaleform::Render::Rect<float> pr; // [esp+30h] [ebp-10h] BYREF

  bounds.x1 = 0.0;
  bounds.y1 = 0.0;
  bounds.x2 = 0.0;
  bounds.y2 = 0.0;
  *(float *)&v16.__vftable = 0.0;
  *(float *)&v16.Type = 0.0;
  *(float *)&v17.__vftable = 0.0;
  *(float *)&v17.Type = 0.0;
  if ( this->AproxLocalBounds.x2 > (double)this->AproxLocalBounds.x1
    && this->AproxLocalBounds.y2 > (double)this->AproxLocalBounds.y1 )
  {
    bounds.x1 = this->AproxLocalBounds.x1;
    bounds.y1 = this->AproxLocalBounds.y1;
    bounds.x2 = this->AproxLocalBounds.x2;
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
    bounds.x1 = *v4;
    bounds.y1 = v9;
    bounds.x2 = v11;
    y2 = v13;
LABEL_6:
    bounds.y2 = y2;
  }
  if ( bounds.x2 > (double)bounds.x1 && bounds.y2 > (double)bounds.y1 )
  {
    Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(this, &bounds, 0);
    if ( (this->Flags & 0x200) != 0 )
      Scaleform::Render::Matrix3x4<float>::EncloseTransform(&this->M34, &pr, &bounds);
    else
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(
        (Scaleform::Render::Matrix2x4<float> *)&this->M34,
        (__m128 *)&pr,
        (__m128 *)&bounds);
    *(float *)&v16.__vftable = pr.x1;
    *(float *)&v16.Type = pr.y1;
    *(float *)&v17.__vftable = pr.x2;
    *(float *)&v17.Type = pr.y2;
  }
  if ( this->AproxLocalBounds.x1 == bounds.x1
    && this->AproxLocalBounds.x2 == bounds.x2
    && this->AproxLocalBounds.y1 == bounds.y1
    && this->AproxLocalBounds.y2 == bounds.y2
    && *(float *)&v16.__vftable == bounds.x1
    && *(float *)&v17.__vftable == bounds.x2
    && *(float *)&v16.Type == bounds.y1
    && *(float *)&v17.Type == bounds.y2 )
  {
    LOBYTE(v6) = 0;
  }
  else
  {
    WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(entry, 8u);
    y1 = bounds.y1;
    x2 = bounds.x2;
    v10 = bounds.y2;
    *(float *)&WritableData[14].__vftable = bounds.x1;
    *(float *)&WritableData[14].Type = y1;
    *(float *)&WritableData[15].__vftable = x2;
    *(float *)&WritableData[15].Type = v10;
    WritableData[16] = v16;
    WritableData[17] = v17;
    return this->Flags & 1;
  }
  return v6;
}
