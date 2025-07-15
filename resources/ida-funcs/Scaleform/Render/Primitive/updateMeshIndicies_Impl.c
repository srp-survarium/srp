void __thiscall Scaleform::Render::Primitive::updateMeshIndicies_Impl(Scaleform::Render::Primitive *this)
{
  unsigned int Size; // edx
  Scaleform::Render::Primitive *i; // eax

  Size = this->Meshes.Data.Size;
  if ( this->ModifyIndex < Size )
  {
    for ( i = (Scaleform::Render::Primitive *)this->Batches.Root.pPrev;
          i != (Scaleform::Render::Primitive *)&this->Batches;
          i = (Scaleform::Render::Primitive *)i->Scaleform::RefCountBase<Scaleform::Render::Primitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable )
    {
      Size -= i->Meshes.Data.Size;
      i->Meshes.Data.Policy.Capacity = Size;
      if ( Size < this->ModifyIndex )
        break;
    }
    this->ModifyIndex = this->Meshes.Data.Size;
  }
}
