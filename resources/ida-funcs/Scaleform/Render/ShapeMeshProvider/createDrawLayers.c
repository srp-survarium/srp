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
  unsigned int v12; // edx
  int v13; // ebx
  unsigned int v14; // ebp
  Scaleform::ArrayLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2,Scaleform::ArrayDefaultPolicy> *p_DrawLayers; // edi
  unsigned int v16; // esi
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *v17; // ecx
  unsigned int *p_StartPos; // eax
  Scaleform::AmpServer *Instance; // eax
  unsigned int Pos; // [esp+Ch] [ebp-2Ch]
  int v22; // [esp+10h] [ebp-28h]
  Scaleform::Render::BitSet v23; // [esp+14h] [ebp-24h] BYREF
  Scaleform::Render::ShapeMeshProvider::DrawLayerType val; // [esp+24h] [ebp-14h] BYREF
  unsigned int i1a; // [esp+40h] [ebp+8h]
  unsigned int i1b; // [esp+40h] [ebp+8h]
  unsigned int i2a; // [esp+44h] [ebp+Ch]
  unsigned int i2b; // [esp+44h] [ebp+Ch]

  if ( i2 > i1 )
  {
    v6 = paths;
    Data = paths->Data;
    p_Local = (Scaleform::Render::BitSet *)&v23.Local;
    v9 = 24 * i1;
    v23.Size = 32;
    v23.Local = 0;
    v23.pData = &v23.Local;
    v23.pHeap = Scaleform::Memory::pGlobalHeap;
    Pos = Data[i1].Pos;
    i2a = i1;
    i1a = i2 - i1;
    do
    {
      if ( v6->Data[i2a].Styles[0] != v6->Data[i2a].Styles[1] && (!v23.Size || (p_Local->Size & 1) == 0) )
      {
        Scaleform::Render::ShapeMeshProvider::countComplexFills(this, v6, i1, i2, &val);
        val.StartPos = Pos;
        val.StrokeStyle = 0;
        val.Image9GridType = I9gNone;
        Scaleform::ArrayData<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &this->DrawLayers.Data,
          &val);
        if ( !v23.Size )
          Scaleform::Render::BitSet::resize(&v23, 1u);
        *v23.pData |= 1u;
      }
      v10 = paths->Data[i2a].Styles[2];
      if ( v10 )
      {
        if ( v10 >= v23.Size )
          Scaleform::Render::BitSet::resize(&v23, v10 + 1);
        v23.pData[v10 >> 5] |= 1 << (v10 & 0x1F);
      }
      ++i2a;
      v11 = i1a-- == 1;
      p_Local = (Scaleform::Render::BitSet *)v23.pData;
      v6 = paths;
    }
    while ( !v11 );
    if ( i1 < i2 )
    {
      i1b = 24 * i1;
      v22 = i2 - i1;
      while ( 1 )
      {
        v12 = *(unsigned int *)((char *)&v6->Data->Styles[2] + v9);
        i2b = v12;
        if ( !v12 )
          goto LABEL_29;
        if ( v12 >= v23.Size )
          goto LABEL_29;
        v13 = 1 << (v12 & 0x1F);
        v14 = v12 >> 5;
        if ( (v13 & *(unsigned int *)((_BYTE *)&p_Local->Size + v14 * 4)) == 0 )
          goto LABEL_29;
        p_DrawLayers = &this->DrawLayers;
        v16 = this->DrawLayers.Data.Size + 1;
        if ( v16 >= this->DrawLayers.Data.Size )
        {
          if ( v16 >= this->DrawLayers.Data.Policy.Capacity )
          {
            Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &p_DrawLayers->Data,
              p_DrawLayers,
              v16 + (v16 >> 2));
            goto LABEL_25;
          }
        }
        else if ( v16 < this->DrawLayers.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &p_DrawLayers->Data,
            p_DrawLayers,
            this->DrawLayers.Data.Size + 1);
LABEL_25:
          v12 = i2b;
        }
        v17 = p_DrawLayers->Data.Data;
        this->DrawLayers.Data.Size = v16;
        p_StartPos = &v17[v16 - 1].StartPos;
        *p_StartPos = Pos;
        p_StartPos[1] = 0;
        p_StartPos[2] = 1;
        p_StartPos[3] = v12;
        p_StartPos[4] = 0;
        if ( v12 >= v23.Size )
          Scaleform::Render::BitSet::resize(&v23, v12 + 1);
        v23.pData[v14] &= ~v13;
        this->Strokes = 1;
        Instance = Scaleform::AmpServer::GetInstance();
        Instance->AddStrokes(Instance, 1u);
        p_Local = (Scaleform::Render::BitSet *)v23.pData;
LABEL_29:
        v9 = i1b + 24;
        v11 = v22-- == 1;
        i1b += 24;
        if ( v11 )
          break;
        v6 = paths;
      }
    }
    if ( p_Local != (Scaleform::Render::BitSet *)&v23.Local )
      v23.pHeap->Free(v23.pHeap, p_Local);
  }
}
