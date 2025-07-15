void __thiscall Scaleform::Render::ComplexPrimitiveBundle::Draw(
        Scaleform::Render::ComplexPrimitiveBundle *this,
        Scaleform::Render::HAL *hal)
{
  unsigned int v3; // esi
  void (__thiscall *Draw)(Scaleform::Render::HAL *, const Scaleform::Render::RenderQueueItem *); // edx
  Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry *Data; // eax
  Scaleform::Render::ComplexMesh *pObject; // ebp
  Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry *v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  Scaleform::Ptr<Scaleform::Render::ComplexMesh> *p_pMesh; // edx
  unsigned int Size; // [esp+8h] [ebp-Ch]
  _DWORD v12[2]; // [esp+Ch] [ebp-8h] BYREF

  v3 = 0;
  Size = this->Instances.Data.Size;
  if ( Size )
  {
    do
    {
      v12[0] = &this->Scaleform::Render::RenderQueueItem::Interface;
      Draw = hal->Draw;
      v12[1] = v3;
      Draw(hal, (const Scaleform::Render::RenderQueueItem *)v12);
      Data = this->Instances.Data.Data;
      pObject = Data[v3].pMesh.pObject;
      v7 = &Data[v3];
      v8 = this->Instances.Data.Size - 1;
      v9 = v3;
      if ( v3 < v8 )
      {
        p_pMesh = &v7[1].pMesh;
        do
        {
          if ( p_pMesh->pObject != pObject )
            break;
          ++v9;
          p_pMesh += 2;
        }
        while ( v9 < v8 );
      }
      v3 = v9 + 1;
    }
    while ( v9 + 1 < Size );
  }
}
