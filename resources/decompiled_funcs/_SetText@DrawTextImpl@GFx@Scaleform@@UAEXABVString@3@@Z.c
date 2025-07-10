void __thiscall Scaleform::GFx::DrawTextImpl::SetText(Scaleform::GFx::DrawTextImpl *this, const Scaleform::String *str)
{
  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  Scaleform::Render::TreeText::SetText(
    this->pTextNode.pObject,
    (const char *)((str->HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(str->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
}
