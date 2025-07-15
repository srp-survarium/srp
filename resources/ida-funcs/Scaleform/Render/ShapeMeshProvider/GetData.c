char __thiscall Scaleform::Render::ShapeMeshProvider::GetData(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::MeshBase *mesh,
        Scaleform::Render::VertexOutput *verOut,
        unsigned int meshGenFlags)
{
  unsigned int Layer; // eax
  Scaleform::Render::Scale9GridInfo *v5; // esi
  Scaleform::Render::ShapeMeshProvider *v7; // edi
  Scaleform::Render::Scale9GridInfo *v8; // eax
  Scaleform::Render::Scale9GridData *pObject; // ecx
  Scaleform::Render::Scale9GridInfo *v10; // eax
  char Image9Grid; // al
  Scaleform::Render::Scale9GridInfo *v12; // eax
  Scaleform::Render::Scale9GridInfo *v13; // eax
  unsigned int v14; // ecx
  char v15; // bl
  unsigned int v17; // [esp+18h] [ebp-28h]
  int v18; // [esp+1Ch] [ebp-24h] BYREF
  Scaleform::Render::Matrix2x4<float> viewMtx; // [esp+20h] [ebp-20h] BYREF

  Layer = mesh->Layer;
  v5 = 0;
  v17 = Layer;
  if ( mesh->pScale9Grid.pObject )
  {
    if ( *(&this->hKeySet.pManager.Value->KeySetLock.cs.RecursionCount + 5 * Layer) )
    {
      v18 = 2;
      v7 = (Scaleform::Render::ShapeMeshProvider *)((char *)this - 8);
      v8 = (Scaleform::Render::Scale9GridInfo *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  &this[-1].Strokes + 7,
                                                  448,
                                                  &v18);
      if ( v8 )
      {
        pObject = mesh->pScale9Grid.pObject;
        viewMtx.M[0][0] = 1.0;
        viewMtx.M[0][1] = 0.0;
        viewMtx.M[0][2] = 0.0;
        viewMtx.M[0][3] = 0.0;
        viewMtx.M[1][0] = 0.0;
        viewMtx.M[1][2] = 0.0;
        viewMtx.M[1][3] = 0.0;
        viewMtx.M[1][1] = 1.0;
        Scaleform::Render::Scale9GridInfo::Scale9GridInfo(v8, pObject, &viewMtx);
        v5 = v10;
      }
      else
      {
        v5 = 0;
      }
      Image9Grid = Scaleform::Render::ShapeMeshProvider::generateImage9Grid(v7, v5, mesh, verOut, v17);
      goto LABEL_15;
    }
    if ( mesh->pScale9Grid.pObject )
    {
      v18 = 2;
      v12 = (Scaleform::Render::Scale9GridInfo *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   &this[-1].Strokes + 7,
                                                   448,
                                                   &v18);
      if ( v12 )
        Scaleform::Render::Scale9GridInfo::Scale9GridInfo(
          v12,
          mesh->pScale9Grid.pObject,
          &mesh->pScale9Grid.pObject->ViewMtx);
      else
        v13 = 0;
      v5 = v13;
      Layer = v17;
    }
  }
  v14 = *(&this->hKeySet.pManager.Value->KeySetLock.cs.LockCount + 5 * Layer);
  if ( v14 )
    Image9Grid = Scaleform::Render::ShapeMeshProvider::tessellateStroke(
                   (Scaleform::Render::ShapeMeshProvider *)((char *)this - 8),
                   v5,
                   v14,
                   Layer,
                   mesh,
                   verOut,
                   meshGenFlags);
  else
    Image9Grid = Scaleform::Render::ShapeMeshProvider::tessellateFill(
                   (Scaleform::Render::ShapeMeshProvider *)((char *)this - 8),
                   (const Scaleform::Render::ToleranceParams *)this,
                   v5,
                   Layer,
                   mesh,
                   verOut,
                   meshGenFlags);
LABEL_15:
  v15 = Image9Grid;
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  return v15;
}
