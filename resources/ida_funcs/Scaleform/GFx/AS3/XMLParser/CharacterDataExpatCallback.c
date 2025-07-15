void __cdecl Scaleform::GFx::AS3::XMLParser::CharacterDataExpatCallback(
        Scaleform::GFx::AS3::XMLParser *userData,
        char *s,
        Scaleform::GFx::ASStringNode *len)
{
  Scaleform::GFx::AS3::XMLParser::SetNodeKind(userData, kText);
  Scaleform::GFx::ASString::Append(&userData->Text, s, len);
}
