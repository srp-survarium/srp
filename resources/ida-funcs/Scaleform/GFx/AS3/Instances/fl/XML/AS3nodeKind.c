void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3nodeKind(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *v2; // esi

  v2 = 0;
  switch ( this->GetKind(this) )
  {
    case kElement:
      Scaleform::GFx::ASString::operator=(result, (Scaleform::GFx::ASStringNode *)"element");
      break;
    case kText:
      Scaleform::GFx::ASString::operator=(result, (Scaleform::GFx::ASStringNode *)"text");
      break;
    case kComment:
      Scaleform::GFx::ASString::operator=(result, (Scaleform::GFx::ASStringNode *)"comment");
      break;
    case kInstruction:
      Scaleform::GFx::ASString::operator=(result, (Scaleform::GFx::ASStringNode *)"processing-instruction");
      break;
    case kAttr:
      v2 = (Scaleform::GFx::ASStringNode *)"attribute";
      goto LABEL_7;
    default:
LABEL_7:
      Scaleform::GFx::ASString::operator=(result, v2);
      break;
  }
}
