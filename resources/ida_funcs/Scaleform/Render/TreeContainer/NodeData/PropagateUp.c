bool __thiscall Scaleform::Render::TreeContainer::NodeData::PropagateUp(
        Scaleform::Render::TreeContainer::NodeData *this,
        Scaleform::Render::ContextImpl::Entry *entry)
{
  Scaleform::Render::TreeContainer::NodeData *v2; // esi
  unsigned int v3; // ecx
  unsigned int *p_Children; // eax
  unsigned int v5; // edi
  unsigned int v6; // ecx
  unsigned int *v7; // ebx
  int v8; // eax
  const Scaleform::Render::Rect<float> *v9; // ecx
  unsigned int State; // eax
  int v11; // edi
  unsigned int i; // esi
  Scaleform::Render::ContextImpl::EntryData *v13; // eax
  __int16 v14; // ax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax
  char v17; // [esp+F5h] [ebp-45h]
  unsigned int v18; // [esp+F6h] [ebp-44h]
  Scaleform::Render::TreeContainer::NodeData *v19; // [esp+FAh] [ebp-40h]
  float v20; // [esp+FEh] [ebp-3Ch]
  float y2; // [esp+FEh] [ebp-3Ch]
  float v22; // [esp+102h] [ebp-38h]
  float x2; // [esp+102h] [ebp-38h]
  float v24; // [esp+106h] [ebp-34h]
  float y1; // [esp+106h] [ebp-34h]
  Scaleform::Render::Rect<float> pdest; // [esp+10Ah] [ebp-30h] BYREF
  Scaleform::Render::ContextImpl::EntryData v27; // [esp+11Ah] [ebp-20h]
  Scaleform::Render::ContextImpl::EntryData v28; // [esp+122h] [ebp-18h]
  Scaleform::Render::Rect<float> pr; // [esp+12Ah] [ebp-10h] BYREF

  v2 = this;
  v3 = this->Children.pData[0];
  p_Children = (unsigned int *)&v2->Children;
  v5 = 0;
  v19 = v2;
  if ( v3 )
  {
    if ( (v3 & 1) != 0 )
      v18 = *(_DWORD *)((v3 & 0xFFFFFFFE) + 4);
    else
      v18 = (v2->Children.pData[1] != 0) + 1;
  }
  else
  {
    v18 = 0;
  }
  v6 = *p_Children;
  if ( *p_Children )
  {
    if ( (v6 & 1) != 0 )
      p_Children = (unsigned int *)((v6 & 0xFFFFFFFE) + 8);
    v7 = p_Children;
  }
  else
  {
    v7 = 0;
  }
  v17 = 1;
  pdest.x1 = 0.0;
  pdest.y1 = 0.0;
  pdest.x2 = 0.0;
  pdest.y2 = 0.0;
  *(float *)&v27.__vftable = 0.0;
  *(float *)&v27.Type = 0.0;
  *(float *)&v28.__vftable = 0.0;
  *(float *)&v28.Type = 0.0;
  if ( v18 )
  {
    do
    {
      v8 = *(_DWORD *)(*(_DWORD *)((v7[v5] & 0xFFFFF000) + 0x10)
                     + 4 * ((int)(v7[v5] - (v7[v5] & 0xFFFFF000) - 28) / 28)
                     + 20);
      if ( (*(_BYTE *)(v8 + 6) & 1) != 0 )
      {
        v9 = (const Scaleform::Render::Rect<float> *)(v8 + 128);
        if ( *(float *)(v8 + 136) > (double)*(float *)(v8 + 128) && *(float *)(v8 + 140) > (double)*(float *)(v8 + 132) )
        {
          if ( v17 )
          {
            v17 = 0;
            v20 = *(float *)(v8 + 132);
            v22 = *(float *)(v8 + 136);
            v24 = *(float *)(v8 + 140);
            pdest.x1 = v9->x1;
            pdest.y1 = v20;
            pdest.x2 = v22;
            pdest.y2 = v24;
          }
          else
          {
            Scaleform::Render::Rect<float>::UnionRect(&pdest, &pdest, v9);
          }
        }
      }
      ++v5;
    }
    while ( v5 < v18 );
    if ( !v17 )
    {
      State = Scaleform::Render::StateBag::GetState(&v2->States, State_ActionControl);
      if ( State )
      {
        v11 = *(_DWORD *)(State + 4);
        if ( v11 )
        {
          for ( i = 0; i < *(_DWORD *)(v11 + 12); ++i )
            Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(
              *(const Scaleform::Render::Filter **)(*(_DWORD *)(v11 + 8) + 4 * i),
              &pdest);
        }
      }
      if ( (v19->Flags & 0x200) != 0 )
        Scaleform::Render::Matrix3x4<float>::EncloseTransform(&v19->M34, &pr, &pdest);
      else
        Scaleform::Render::Matrix2x4<float>::EncloseTransform(
          (Scaleform::Render::Matrix2x4<float> *)&v19->M34,
          &pr,
          (__m128 *)&pdest);
      v2 = v19;
      *(float *)&v27.__vftable = pr.x1;
      *(float *)&v27.Type = pr.y1;
      *(float *)&v28.__vftable = pr.x2;
      *(float *)&v28.Type = pr.y2;
    }
  }
  if ( v2->AproxLocalBounds.x1 == pdest.x1
    && v2->AproxLocalBounds.x2 == pdest.x2
    && v2->AproxLocalBounds.y1 == pdest.y1
    && v2->AproxLocalBounds.y2 == pdest.y2
    && v2->AproxParentBounds.x1 == *(float *)&v27.__vftable
    && v2->AproxParentBounds.x2 == *(float *)&v28.__vftable
    && v2->AproxParentBounds.y1 == *(float *)&v27.Type
    && v2->AproxParentBounds.y2 == *(float *)&v28.Type )
  {
    if ( entry->pPrev )
    {
      v13 = Scaleform::Render::ContextImpl::Entry::getWritableData(entry, 0) + 18;
      if ( ((int)v13->__vftable & 1) != 0 )
        *(_DWORD *)&v13->Type = 0;
    }
    LOBYTE(v14) = 0;
  }
  else
  {
    WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(entry, 9u);
    y1 = pdest.y1;
    x2 = pdest.x2;
    y2 = pdest.y2;
    *(float *)&WritableData[14].__vftable = pdest.x1;
    *(float *)&WritableData[14].Type = y1;
    *(float *)&WritableData[15].__vftable = x2;
    *(float *)&WritableData[15].Type = y2;
    WritableData[16] = v27;
    WritableData[17] = v28;
    if ( entry->pPrev && ((int)WritableData[18].__vftable & 1) != 0 )
      *(_DWORD *)&WritableData[18].Type = 0;
    return v2->Flags & 1;
  }
  return v14;
}
