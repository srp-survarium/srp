void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3nodeKind(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::ASString *result)
{
  char *v2; // esi

  v2 = 0;
  switch ( this->GetKind(this) )
  {
    case kElement:
      Scaleform::GFx::ASString::operator=(result, "element");
      break;
    case kText:
      Scaleform::GFx::ASString::operator=(result, "text");
      break;
    case kComment:
      Scaleform::GFx::ASString::operator=(result, "comment");
      break;
    case kInstruction:
      Scaleform::GFx::ASString::operator=(result, "processing-instruction");
      break;
    case kAttr:
      v2 = "attribute";
      goto LABEL_7;
    default:
LABEL_7:
      Scaleform::GFx::ASString::operator=(result, v2);
      break;
  }
}
