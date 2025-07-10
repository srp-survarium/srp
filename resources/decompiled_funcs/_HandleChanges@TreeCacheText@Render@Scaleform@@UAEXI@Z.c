void __thiscall Scaleform::Render::TreeCacheText::HandleChanges(
        Scaleform::Render::TreeCacheText *this,
        __int16 changeBits)
{
  Scaleform::Render::Bundle *pObject; // ecx
  Scaleform::Render::TreeCacheNode *pParent; // ebx
  int v5; // edx
  Scaleform::Render::EdgeAAMode v6; // eax

  if ( (changeBits & 0x400) != 0 )
  {
    pObject = this->SorterShapeNode.pBundle.pObject;
    if ( pObject )
      pObject->UpdateMesh(pObject, &this->SorterShapeNode);
    Scaleform::Render::TextMeshProvider::Clear(&this->TMProvider);
  }
  if ( (changeBits & 0x20) != 0 )
  {
    pParent = this->pParent;
    if ( pParent )
    {
      v5 = pParent->Flags & 0xC;
      if ( v5 == 12 )
      {
        this->propagateEdgeAA(this, EdgeAA_Disable);
        return;
      }
    }
    else
    {
      v5 = 4;
    }
    v6 = *(_WORD *)((*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                               + 4 * ((int)((int)&this->pNode[-1] - ((int)this->pNode & 0xFFFFF000)) / 28)
                               + 20)
                   & 0xFFFFFFFE)
                  + 6)
       & 0xC;
    if ( v6 == EdgeAA_Inherit )
      v6 = v5;
    this->propagateEdgeAA(this, v6);
  }
}
