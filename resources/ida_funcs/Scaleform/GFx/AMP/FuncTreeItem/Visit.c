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
