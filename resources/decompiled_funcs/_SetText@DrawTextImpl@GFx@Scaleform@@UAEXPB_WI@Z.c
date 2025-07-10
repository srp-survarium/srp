void __thiscall Scaleform::GFx::DrawTextImpl::SetText(
        Scaleform::GFx::DrawTextImpl *this,
        const wchar_t *pstr,
        unsigned int lengthInChars)
{
  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  Scaleform::Render::TreeText::SetText(this->pTextNode.pObject, pstr, lengthInChars);
}
