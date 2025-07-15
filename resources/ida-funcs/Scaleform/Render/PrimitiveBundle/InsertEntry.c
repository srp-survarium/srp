void __thiscall Scaleform::Render::PrimitiveBundle::InsertEntry(
        Scaleform::Render::PrimitiveBundle *this,
        void (__thiscall *index)(struct Scaleform::Render::Primitive *this),
        Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::TreeCacheNode *pSourceNode; // ecx
  Scaleform::GFx::Resource *v5; // eax
  const Scaleform::Render::MatrixPoolImpl::HMatrix *p_pRenderer2D; // [esp-4h] [ebp-10h]

  Scaleform::Render::Bundle::InsertEntry(this, (unsigned int)index, entry);
  pSourceNode = entry->pSourceNode;
  p_pRenderer2D = (const Scaleform::Render::MatrixPoolImpl::HMatrix *)&pSourceNode[1].pRenderer2D;
  v5 = (Scaleform::GFx::Resource *)((int (__thiscall *)(Scaleform::Render::TreeCacheNode *))pSourceNode->__vftable[1].HandleChanges)(pSourceNode);
  Scaleform::Render::Primitive::Insert(&this->Prim, index, v5, p_pRenderer2D);
}
