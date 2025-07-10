void __thiscall Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::operator=(
        Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> > *this,
        const Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >::NodeRef *src)
{
  const Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *pSecond; // edi
  Scaleform::Render::ShapeMeshProvider *pObject; // eax

  this->First = *src->pFirst;
  pSecond = src->pSecond;
  if ( pSecond->pObject )
    pSecond->pObject->AddRef(&pSecond->pObject->Scaleform::Render::MeshProvider);
  pObject = this->Second.pObject;
  if ( pObject )
    pObject->Release(&pObject->Scaleform::Render::MeshProvider);
  this->Second = (Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>)pSecond->pObject;
}
