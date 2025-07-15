int __thiscall Scaleform::Render::TextMeshProvider::GetMeshUseStatus(Scaleform::Render::TextMeshProvider *this)
{
  Scaleform::Render::MeshUseStatus v2; // ebp
  unsigned int v4; // ebx
  int v5; // edi
  Scaleform::Render::TextMeshLayer *Data; // eax
  int Type; // ecx
  Scaleform::Render::TextMeshLayer *v8; // eax
  Scaleform::Render::Mesh *pObject; // eax
  Scaleform::Render::MeshUseStatus UseStatus; // eax

  v2 = MUS_Uncached;
  if ( this->PinCount )
    return 5;
  v4 = 0;
  if ( this->GetLayerCount(this) )
  {
    v5 = 0;
    do
    {
      Data = this->Layers.Data.Data;
      Type = Data[v5].Type;
      v8 = &Data[v5];
      if ( Type > 4 )
        break;
      if ( Type >= 2 )
      {
        pObject = v8->pMesh.pObject;
        if ( pObject )
        {
          UseStatus = Scaleform::Render::Mesh::GetUseStatus(pObject);
          if ( UseStatus > v2 )
            v2 = UseStatus;
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->GetLayerCount(this) );
  }
  return v2;
}
