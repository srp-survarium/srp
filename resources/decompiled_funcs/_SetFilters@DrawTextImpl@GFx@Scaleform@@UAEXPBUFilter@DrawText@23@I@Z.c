void __thiscall Scaleform::GFx::DrawTextImpl::SetFilters(
        Scaleform::GFx::DrawTextImpl *this,
        const Scaleform::GFx::DrawText::Filter *filters,
        unsigned int filtersCnt)
{
  Scaleform::Render::TreeText::SetFilters(this->pTextNode.pObject, filters, filtersCnt);
}
