void __thiscall __noreturn Scaleform::GFx::AS3::XMLParser::XMLParser(
        Scaleform::GFx::AS3::XMLParser *this,
        Scaleform::GFx::AS3::InstanceTraits::fl::XML *itr)
{
  this->NsSep = 58;
  this->NodeKind = kNone;
  this->ITr = itr;
  XML_ParserCreate(0);
}
