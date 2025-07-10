void __thiscall Scaleform::Render::TreeCacheText::propagate3DFlag(
        Scaleform::Render::TreeCacheText *this,
        __int16 parent3D)
{
  Scaleform::Render::BundleEntry *p_SorterShapeNode; // ebx
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::Render::Bundle *v5; // edi
  Scaleform::RefCountNTSImpl *v6; // ecx
  Scaleform::Render::SortKeyInterface **v7; // eax
  Scaleform::Render::SortKeyInterface **v8; // edi
  void *Data; // eax
  Scaleform::Render::Bundle *v10; // ecx
  Scaleform::Render::SortKey v11; // [esp+Ch] [ebp-8h] BYREF

  p_SorterShapeNode = &this->SorterShapeNode;
  if ( this->SorterShapeNode.pBundle.pObject )
  {
    pObject = this->SorterShapeNode.pBundle.pObject;
    if ( pObject )
      ++pObject->RefCount;
    v5 = this->SorterShapeNode.pBundle.pObject;
    Scaleform::Render::Bundle::RemoveEntry(v5, &this->SorterShapeNode);
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release(v5);
  }
  v6 = p_SorterShapeNode->pBundle.pObject;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  p_SorterShapeNode->pBundle.pObject = 0;
  p_SorterShapeNode->IndexHint = 0;
  Scaleform::Render::SortKey::SortKey(&v11, SortKeyText, (parent3D & 0x200) != 0);
  v8 = v7;
  (*v7)->AddRef(*v7, v7[1]);
  this->SorterShapeNode.Key.pImpl->Release(this->SorterShapeNode.Key.pImpl, this->SorterShapeNode.Key.Data);
  this->SorterShapeNode.Key.pImpl = *v8;
  Data = v11.Data;
  this->SorterShapeNode.Key.Data = v8[1];
  v11.pImpl->Release(v11.pImpl, Data);
  v10 = this->SorterShapeNode.pBundle.pObject;
  if ( v10 )
    v10->UpdateMesh(v10, p_SorterShapeNode);
  Scaleform::Render::TextMeshProvider::Clear(&this->TMProvider);
}
