void __thiscall Scaleform::GFx::AMP::FuncTreeItem::Visit<Scaleform::GFx::AMP::FunctionTreeVisitor>(
        Scaleform::GFx::AMP::FuncTreeItem *this,
        Scaleform::GFx::AMP::FunctionTreeVisitor *visitor)
{
  unsigned int i; // esi

  Scaleform::GFx::AMP::FunctionTreeVisitor::operator()(visitor, this);
  for ( i = 0; i < this->Children.Data.Size; ++i )
    Scaleform::GFx::AMP::FuncTreeItem::Visit<Scaleform::GFx::AMP::FunctionTreeVisitor>(
      this->Children.Data.Data[i].pObject,
      visitor);
}


void __thiscall Scaleform::GFx::AMP::FuncTreeItem::Visit<Scaleform::GFx::AMP::FuncStatsVisitor>(
        Scaleform::GFx::AMP::FuncTreeItem *this,
        Scaleform::GFx::AMP::FuncStatsVisitor *visitor)
{
  unsigned int i; // edi

  Scaleform::GFx::AMP::ViewStats::UpdateStats(
    visitor->CallingView,
    this->FunctionId,
    LODWORD(this->EndTime) - LODWORD(this->BeginTime),
    1u,
    visitor->FrameInfo);
  for ( i = 0; i < this->Children.Data.Size; ++i )
    Scaleform::GFx::AMP::FuncTreeItem::Visit<Scaleform::GFx::AMP::FuncStatsVisitor>(
      this->Children.Data.Data[i].pObject,
      visitor);
}


void __thiscall Scaleform::GFx::AMP::FuncTreeItem::Visit<Scaleform::GFx::AMP::MaxIdVisitor>(
        Scaleform::GFx::AMP::FuncTreeItem *this,
        Scaleform::GFx::AMP::MaxIdVisitor *visitor)
{
  unsigned int TreeItemId; // eax
  unsigned int v4; // esi

  TreeItemId = this->TreeItemId;
  if ( TreeItemId < visitor->MaxId )
    TreeItemId = visitor->MaxId;
  v4 = 0;
  for ( visitor->MaxId = TreeItemId; v4 < this->Children.Data.Size; ++v4 )
    Scaleform::GFx::AMP::FuncTreeItem::Visit<Scaleform::GFx::AMP::MaxIdVisitor>(
      this->Children.Data.Data[v4].pObject,
      visitor);
}


void __thiscall Scaleform::GFx::AMP::FuncTreeItem::Visit<Scaleform::GFx::AMP::OffsetIdVisitor>(
        Scaleform::GFx::AMP::FuncTreeItem *this,
        Scaleform::GFx::AMP::OffsetIdVisitor *visitor)
{
  unsigned int i; // edi

  this->TreeItemId += visitor->OffsetId;
  for ( i = 0; i < this->Children.Data.Size; ++i )
    Scaleform::GFx::AMP::FuncTreeItem::Visit<Scaleform::GFx::AMP::OffsetIdVisitor>(
      this->Children.Data.Data[i].pObject,
      visitor);
}
