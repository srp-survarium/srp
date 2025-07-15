void __thiscall Scaleform::Render::ShapeMeshProvider::createDrawLayers(
        Scaleform::Render::ShapeMeshProvider *this,
        const Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2> *paths,
        unsigned int i1,
        unsigned int i2)
{
  const Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2> *v6; // ecx
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *Data; // edx
  Scaleform::Render::BitSet *p_Local; // esi
  unsigned int v9; // ebp
  unsigned int v10; // esi
  bool v11; // zf
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *v12; // eax
  unsigned int v13; // ebx
  int v14; // edx
  unsigned int v15; // ebp
  Scaleform::ArrayLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2,Scaleform::ArrayDefaultPolicy> *p_DrawLayers; // edi
  unsigned int v17; // esi
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *v18; // ecx
  unsigned int *p_StartPos; // eax
  unsigned int startPos; // [esp+Ch] [ebp-2Ch]
  int v22; // [esp+10h] [ebp-28h]
  Scaleform::Render::BitSet styles; // [esp+14h] [ebp-24h] BYREF
  Scaleform::Render::ShapeMeshProvider::DrawLayerType val; // [esp+24h] [ebp-14h] BYREF
  unsigned int i1a; // [esp+40h] [ebp+8h]
  unsigned int i1b; // [esp+40h] [ebp+8h]
  unsigned int i2a; // [esp+44h] [ebp+Ch]
  unsigned int i2b; // [esp+44h] [ebp+Ch]

  if ( i2 > i1 )
  {
    v6 = paths;
    Data = paths->Data;
    p_Local = (Scaleform::Render::BitSet *)&styles.Local;
    v9 = 24 * i1;
    styles.Size = 32;
    styles.Local = 0;
    styles.pData = &styles.Local;
    styles.pHeap = Scaleform::Memory::pGlobalHeap;
    startPos = Data[i1].Pos;
    i2a = i1;
    i1a = i2 - i1;
    do
    {
      if ( v6->Data[i2a].Styles[0] != v6->Data[i2a].Styles[1] && (!styles.Size || (p_Local->Size & 1) == 0) )
      {
        Scaleform::Render::ShapeMeshProvider::countComplexFills(this, v6, i1, i2, &val);
        val.StartPos = startPos;
        val.StrokeStyle = 0;
        val.Image9GridType = I9gNone;
        Scaleform::ArrayData<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &this->DrawLayers.Data,
          &val);
        if ( !styles.Size )
          Scaleform::Render::BitSet::resize(&styles, 1u);
        *styles.pData |= 1u;
      }
      v6 = paths;
      v10 = paths->Data[i2a].Styles[2];
      if ( v10 )
      {
        if ( v10 >= styles.Size )
          Scaleform::Render::BitSet::resize(&styles, v10 + 1);
        v6 = paths;
        styles.pData[v10 >> 5] |= 1 << (v10 & 0x1F);
      }
      ++i2a;
      v11 = i1a-- == 1;
      p_Local = (Scaleform::Render::BitSet *)styles.pData;
    }
    while ( !v11 );
    if ( i1 < i2 )
    {
      i1b = 24 * i1;
      v22 = i2 - i1;
      while ( 1 )
      {
        v12 = v6->Data;
        v13 = *(unsigned int *)((char *)&v12->Styles[2] + v9);
        if ( !v13 )
          goto LABEL_29;
        if ( v13 >= styles.Size )
          goto LABEL_29;
        v14 = 1 << (*((_BYTE *)&v12->Styles[2] + v9) & 0x1F);
        v15 = v13 >> 5;
        i2b = v14;
        if ( (v14 & *(unsigned int *)((_BYTE *)&p_Local->Size + v15 * 4)) == 0 )
          goto LABEL_29;
        p_DrawLayers = &this->DrawLayers;
        v17 = this->DrawLayers.Data.Size + 1;
        if ( v17 >= this->DrawLayers.Data.Size )
        {
          if ( v17 >= this->DrawLayers.Data.Policy.Capacity )
          {
            Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &p_DrawLayers->Data,
              p_DrawLayers,
              v17 + (v17 >> 2));
            goto LABEL_25;
          }
        }
        else if ( v17 < this->DrawLayers.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &p_DrawLayers->Data,
            p_DrawLayers,
            this->DrawLayers.Data.Size + 1);
LABEL_25:
          v14 = i2b;
        }
        v18 = p_DrawLayers->Data.Data;
        this->DrawLayers.Data.Size = v17;
        p_StartPos = &v18[v17 - 1].StartPos;
        *p_StartPos = startPos;
        p_StartPos[1] = 0;
        p_StartPos[2] = 1;
        p_StartPos[3] = v13;
        p_StartPos[4] = 0;
        if ( v13 >= styles.Size )
        {
          Scaleform::Render::BitSet::resize(&styles, v13 + 1);
          v14 = i2b;
        }
        styles.pData[v15] &= ~v14;
        p_Local = (Scaleform::Render::BitSet *)styles.pData;
        this->Strokes = 1;
LABEL_29:
        v9 = i1b + 24;
        v11 = v22-- == 1;
        i1b += 24;
        if ( v11 )
          break;
        v6 = paths;
      }
    }
    if ( p_Local != (Scaleform::Render::BitSet *)&styles.Local )
      styles.pHeap->Free(styles.pHeap, p_Local);
  }
}
