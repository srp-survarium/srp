void __thiscall Scaleform::GFx::AMP::FuncTreeItem::ResetTreeIds(
        Scaleform::GFx::AMP::FuncTreeItem *this,
        Scaleform::GFx::AMP::FuncTreeItem *other)
{
  Scaleform::GFx::AMP::FuncTreeItem *v2; // eax
  Scaleform::GFx::AMP::FuncTreeItem **p_pObject; // esi
  unsigned int Size; // edi
  unsigned int v6; // ebx
  Scaleform::GFx::AMP::FuncTreeItem *pObject; // esi
  unsigned int i; // edi
  Scaleform::GFx::AMP::OffsetIdVisitor v9; // [esp+10h] [ebp-4h] BYREF

  v2 = other;
  other = (Scaleform::GFx::AMP::FuncTreeItem *)other->TreeItemId;
  if ( v2->Children.Data.Size )
  {
    p_pObject = &v2->Children.Data.Data->pObject;
    Size = v2->Children.Data.Size;
    do
    {
      Scaleform::GFx::AMP::FuncTreeItem::Visit<Scaleform::GFx::AMP::MaxIdVisitor>(
        *p_pObject++,
        (Scaleform::GFx::AMP::MaxIdVisitor *)&other);
      --Size;
    }
    while ( Size );
  }
  v6 = 0;
  for ( v9.OffsetId = (unsigned int)other; v6 < this->Children.Data.Size; ++v6 )
  {
    pObject = this->Children.Data.Data[v6].pObject;
    pObject->TreeItemId += v9.OffsetId;
    for ( i = 0; i < pObject->Children.Data.Size; ++i )
      Scaleform::GFx::AMP::FuncTreeItem::Visit<Scaleform::GFx::AMP::OffsetIdVisitor>(
        pObject->Children.Data.Data[i].pObject,
        &v9);
  }
}
