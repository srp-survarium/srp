Scaleform::String *__thiscall Scaleform::GFx::TextField::TextDocumentListener::GetCharacterPath(
        Scaleform::GFx::TextField::TextDocumentListener *this,
        Scaleform::String *result)
{
  Scaleform::String::String(result);
  Scaleform::GFx::DisplayObject::GetAbsolutePath((Scaleform::GFx::DisplayObject *)&this[-15].HandlersMask, result);
  return result;
}
