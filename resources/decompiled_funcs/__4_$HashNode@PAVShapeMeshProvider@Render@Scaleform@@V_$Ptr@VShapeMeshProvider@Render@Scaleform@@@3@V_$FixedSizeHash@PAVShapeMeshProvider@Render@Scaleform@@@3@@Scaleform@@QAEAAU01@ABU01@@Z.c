Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> > *__thiscall Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::operator=(
        Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> > *this,
        const Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> > *__that)
{
  Scaleform::Render::ShapeMeshProvider *pObject; // eax
  Scaleform::Render::ShapeMeshProvider *v4; // eax

  this->First = __that->First;
  pObject = __that->Second.pObject;
  if ( pObject )
    pObject->AddRef(&pObject->Scaleform::Render::MeshProvider);
  v4 = this->Second.pObject;
  if ( v4 )
    v4->Release(&v4->Scaleform::Render::MeshProvider);
  this->Second.pObject = __that->Second.pObject;
  return this;
}
