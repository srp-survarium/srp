void __thiscall Scaleform::Render::PrimitiveBundle::PrimitiveBundle(
        Scaleform::Render::PrimitiveBundle *this,
        Scaleform::Render::TreeCacheRoot *proot,
        const Scaleform::Render::SortKey *key,
        Scaleform::Render::Renderer2DImpl *pr2d)
{
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::PrimitiveBundle_vtbl *)&Scaleform::Render::Bundle::`vftable';
  this->Entries.Data.Data = 0;
  this->Entries.Data.Size = 0;
  this->Entries.Data.Policy.Capacity = 0;
  this->NeedUpdate = 1;
  this->FrameId = 0;
  Scaleform::Render::Bundle::UpdateChain(this, 0);
  this->pRoot = proot;
  this->NeedUpdate = 1;
  this->pRenderer2D = pr2d;
  this->__vftable = (Scaleform::Render::PrimitiveBundle_vtbl *)&Scaleform::Render::PrimitiveBundle::`vftable';
  Scaleform::Render::Primitive::Primitive(
    &this->Prim,
    pr2d->pHal.pObject,
    (Scaleform::Render::PrimitiveFill *)key->Data);
}
