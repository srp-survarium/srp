void __thiscall Scaleform::Render::PrimitiveBundle::UpdateMesh(
        Scaleform::Render::PrimitiveBundle *this,
        Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::BundleEntry *v2; // edi
  Scaleform::GFx::Resource *v4; // eax

  v2 = entry;
  if ( Scaleform::Render::Bundle::findEntryIndex(this, (unsigned int *)&entry, entry) )
  {
    v4 = (Scaleform::GFx::Resource *)((int (__thiscall *)(Scaleform::Render::TreeCacheNode *))v2->pSourceNode->__vftable[1].HandleChanges)(v2->pSourceNode);
    Scaleform::Render::Primitive::SetMesh(&this->Prim, (unsigned int)entry, v4);
  }
}
