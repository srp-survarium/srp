void __thiscall Scaleform::GFx::DrawTextImpl::SetText(Scaleform::GFx::DrawTextImpl *this, const Scaleform::String *str)
{
  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  Scaleform::Render::TreeText::SetText(
    this->pTextNode.pObject,
    (char *)((str->HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(str->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
}


void __thiscall Scaleform::GFx::DrawTextImpl::SetText(
        Scaleform::GFx::DrawTextImpl *this,
        char *putf8Str,
        unsigned int lengthInBytes)
{
  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  Scaleform::Render::TreeText::SetText(this->pTextNode.pObject, putf8Str, lengthInBytes);
}


void __thiscall Scaleform::GFx::DrawTextImpl::SetText(
        Scaleform::GFx::DrawTextImpl *this,
        wchar_t *pstr,
        unsigned int lengthInChars)
{
  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  Scaleform::Render::TreeText::SetText(this->pTextNode.pObject, pstr, lengthInChars);
}
