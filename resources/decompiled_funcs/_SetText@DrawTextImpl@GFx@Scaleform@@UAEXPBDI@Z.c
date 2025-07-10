void __thiscall Scaleform::GFx::DrawTextImpl::SetText(
        Scaleform::GFx::DrawTextImpl *this,
        const char *putf8Str,
        unsigned int lengthInBytes)
{
  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  Scaleform::Render::TreeText::SetText(this->pTextNode.pObject, putf8Str, lengthInBytes);
}
