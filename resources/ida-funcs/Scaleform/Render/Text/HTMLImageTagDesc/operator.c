BOOL __thiscall Scaleform::Render::Text::HTMLImageTagDesc::operator==(
        Scaleform::Render::Text::HTMLImageTagDesc *this,
        const Scaleform::Render::Text::HTMLImageTagDesc *f)
{
  return !strcmp(
            (const char *)((this->Url.HeapTypeBits & 0xFFFFFFFC) + 8),
            (const char *)((f->Url.HeapTypeBits & 0xFFFFFFFC) + 8))
      && !strcmp(
            (const char *)((this->Id.HeapTypeBits & 0xFFFFFFFC) + 8),
            (const char *)((f->Id.HeapTypeBits & 0xFFFFFFFC) + 8))
      && this->VSpace == f->VSpace
      && this->HSpace == f->HSpace
      && this->ParaId == f->ParaId
      && this->Alignment == f->Alignment;
}
